#include "syntacticalanalyzer.h"

SyntacticalAnalyzer::SyntacticalAnalyzer()
{

}

SyntacticalAnalyzer::SyntacticalAnalyzer(QVector<Lexem> lexemBox):
    lexemBox(lexemBox)
{

}

SyntacticalAnalyzer::SyntacticalAnalyzer(LexicalAnalyzer lexicalAnalyzer):
    lexemBox(lexicalAnalyzer.getLexemBox())
{

}

bool SyntacticalAnalyzer::declarationOfVariables()
{
    this->iterator = lexemBox.begin();

    // первый блок - объявление переменных
    if (*iterator == Lexem::SERVICE_WORD)
    {
        this->iterator++;
        variableList();
        this->iterator++;

        // второй блок - описание вычислений
        while (iterator != lexemBox.end())
        {
            if (*iterator == Lexem::IDENT)
            {
                this->iterator++;
                if (*iterator == Lexem::ASSIGMENT)
                {
                    this->iterator++;
                    expression();
                }
            }
            this->iterator++;
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
        this->iterator++;

    subExpression();
}

bool SyntacticalAnalyzer::subExpression()
{
    if (*iterator == Lexem::BRACKET_OPENING) // (
    {
        // вызываю выражение
        this->iterator++;
        expression();

        this->iterator++;
        if (*iterator != Lexem::BRACKET_CLOSING) // )
        {
            return false;
        }
    }
    else if (*iterator == Lexem::IDENT || *iterator == Lexem::CONST)
    {
        this->iterator++;
        if (*iterator == Lexem::SEMICOLON)
        {
            return true;
        }
        else if (*iterator == Lexem::BINARY)
        {
            this->iterator++;
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


