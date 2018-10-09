#include "syntacticalanalyzer.h"

SyntacticalAnalyzer::SyntacticalAnalyzer()
{

}


void SyntacticalAnalyzer::readFileToString()
{
    QString string;

    if (file.open(QIODevice::ReadOnly))
        string.append(file.readAll());

    this->text = string;
}

bool SyntacticalAnalyzer::declarationOfVariables()
{
    // первый блок - объявление переменных
    if (*iterator == Lexem::SERVICE_WORD)
    {
        iterator++;
        variableList();
        iterator++;

        // второй блок - описание вычислений
        while (iterator != lexemBox.end())
        {
            if (*iterator == Lexem::IDENT)
            {
                iterator++;
                if (*iterator == Lexem::ASSIGMENT)
                {
                    iterator++;
                    expression();
                }
            }
            iterator++;
        }
        return true;
    }
    else
        return false;
}

bool SyntacticalAnalyzer::variableList()
{

    if (*iterator == Lexem::IDENT)
    {
        this->iterator++;

        if(*iterator == Lexem::COMMA) // ,
        {
            this->iterator++;
            return variableList();
        }
        else if (*iterator == Lexem::SEMICOLON) // ;
            return true;
        else
            return false;
    }
    else
        return false;
}

void SyntacticalAnalyzer::expression()
{
    if (*iterator == Lexem::UNARY)
        iterator++;

    subExpression();
}

bool SyntacticalAnalyzer::subExpression()
{
    if (*iterator == Lexem::BRACKET_OPENING) // (
    {
        // вызываю выражение
        iterator++;
        expression();

        iterator++;
        if (*iterator != Lexem::BRACKET_CLOSING) // )
        {
            return false;
        }
    }
    else if (*iterator == Lexem::IDENT ||
             *iterator == Lexem::CONST)
    {
        iterator++;
//        qDebug() << "subExp 2 --> " << *iterator;
        if (*iterator == Lexem::SEMICOLON)
        {
            return true;
        }
        else if (*iterator == Lexem::BINARY)
        {
            iterator++;
            return subExpression();
        }
    }

    if(*iterator == Lexem::SEMICOLON)
    {
        return true;
    }
    else
        return false;
}

void SyntacticalAnalyzer::setLexemBox(QVector<Lexem> lexemBox)
{
    this->lexemBox = lexemBox;
}

void SyntacticalAnalyzer::setIterator(QVector<Lexem>::iterator iterator)
{
    this->iterator = iterator;
}


