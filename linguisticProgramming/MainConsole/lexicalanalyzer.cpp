#include "lexicalanalyzer.h"


LexicalAnalyzer::LexicalAnalyzer()
{
    this->path = "";
}

LexicalAnalyzer::LexicalAnalyzer(QString path)
{
    this->path = path;
}

bool LexicalAnalyzer::isConst(QString word)
{
    foreach (QChar symbol, word)
        if (!symbol.isDigit())
            return false;
    return true;
}

bool LexicalAnalyzer::isIdent(QString word)
{
    foreach (QChar symbol, word)
        if ((symbol < QChar('A') || symbol > QChar('Z')) &&
                (symbol < QChar('a') || symbol > QChar('z')))
            return false;
    return true;
}

bool LexicalAnalyzer::isUnary(QString word)
{
    return unaryOperations.contains(word);
}

bool LexicalAnalyzer::isSigns(QString word)
{
    return signs.contains(word);
}

void LexicalAnalyzer::readFileToString()
{
    QString string;
    QFile file(path);

    if (file.open(QIODevice::ReadOnly))
        string.append(file.readAll());

    this->text = string;
}

QVector<Lexem> LexicalAnalyzer::getLexemBox()
{
    return this->lexemBox;
}

void LexicalAnalyzer::setPath(QString path)
{
    this->path = path;
}

QVector<Lexem> LexicalAnalyzer::run()
{
    readFileToString();

    while (index < text.length())
    {
        Lexem::Types type;
        QString word;
        QString symbol = text.at(index);

        // IDENT
        if (isIdent(symbol))
        {
            while (true)
            {
                if (isIdent(text.at(index)))
                {
                    word.append(text.at(index));
                    index++;
                }
                else
                {
                    index--;
                    break;
                }
            }

            symbol = word;

            if (serviceWords.contains(symbol))
                type = Lexem::SERVICE_WORD;
            else
                type = Lexem::IDENT;
        }

        // CONST
        else if (isConst(symbol))
        {
            while (true)
            {
                if (isConst(text.at(index)))
                {
                    word.append(text.at(index));
                    index++;
                }
                else
                {
                    index--;
                    break;
                }
            }
            symbol = word;
            type = Lexem::CONST;
        }

        // UNARY and BINARY OPERATIONS
        else if (unaryOperations.contains(symbol))
        {
            if ((lexemBox.last().getName() == ":=") || (lexemBox.last().getName() == "("))
                type = Lexem::BINARY;
            else
                type = Lexem::UNARY;
        }

        // SIGNS
        else if (signs.contains(symbol))
        {
            if (text.at(index+1) == "=")
            {
                symbol.append(text.at(index+1));
                index++;
            }

            if (symbol == ",")
                type = Lexem::COMMA;
            else if (symbol == ";")
                type = Lexem::SEMICOLON;
            else if (symbol == "(")
                type = Lexem::BRACKET_OPENING;
            else if (symbol == ")")
                type = Lexem::BRACKET_CLOSING;
        }

        // CHECK (" ", "\n", "\r")
        else if (stringSymbols.contains(symbol))
        {
            // empty
        }

        // ERROR
        else
        {
            qDebug() << "Error";
            lexemBox.clear();
            break;
        }

        // Add LEXEM to box
        if (symbol != ' ' && symbol != '\n' && symbol != '\r')
            lexemBox.append(Lexem(symbol, type));

        // NEXT ITERATOR
        index++;
    }

    return lexemBox;
}


