#include "lexicalanalyzer.h"

LexicalAnalyzer::LexicalAnalyzer()
{

}

LexicalAnalyzer::LexicalAnalyzer(QString path)
{
    file.setFileName(path);
    readFileToString();
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
        if (!symbol.isLetter())
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

bool LexicalAnalyzer::isOther(QString word)
{
    return otherSymbols.contains(word);
}

void LexicalAnalyzer::readFileToString()
{
    QString string;

    if (file.open(QIODevice::ReadOnly))
        string.append(file.readAll());

    this->text = string;
}

void LexicalAnalyzer::setFile(QString path)
{
    file.setFileName(path);
}

void LexicalAnalyzer::setPath(QString path)
{
    this->path = path;
}

void LexicalAnalyzer::printInfo(QString value, QString type)
{
    if (printFlag)
        qDebug() << value + " --> " + type;
}

void LexicalAnalyzer::run()
{
    setFile(this->path);
    readFileToString();

    while (index < text.length())
    {
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

            if (serviceWords.contains(word))
                printInfo(word, "SERVICE_WORDS");
            else
                printInfo(word, "IDENT");
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
            printInfo(word, "CONST");
        }

        // UNART OPERATIONS
        else if (unaryOperations.contains(symbol))
            printInfo(symbol, "UNARY");
        // SIGNS
        else if (signs.contains(symbol))
            printInfo(symbol, "SIGNS");

        // OTHER
        else if (otherSymbols.contains(symbol))
            printInfo(symbol, "OTHER");

        // ERROR
//        else
//        {
//            // TODO: create error function, check "\n", "\r", " "
//            // Alphabet is A-Za-z
//            qDebug() << "Error";
//            break;
//        }

        // NEXT ITERATOR
        index++;
    }
}


