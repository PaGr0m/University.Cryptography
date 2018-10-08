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

bool SyntacticalAnalyzer::declarationOfVariables(QVectorIterator <Lexem> iterator)
//        QVector<Lexem>::iterator iterator)
{
    if (iterator.peekNext().getType() == Lexem::SERVICE_WORD)
    {
        qDebug() << "1 --> " << iterator.peekNext();
        iterator.next();

        variableList(iterator);
    }

    qDebug() << "1 --> " << iterator.peekNext();
    // второй блок - описание вычислений
    if (iterator.peekNext().getType() == Lexem::IDENT)
    {
        iterator.next();
//        qDebug() << " check " << *iterator;
        if (iterator.peekNext().getType() == Lexem::OTHER)
        {
            iterator.next();
            expression(iterator);
        }
    }

//// ---------------------------------------
    // первый блок - объявление переменных
//    if (*iterator == Lexem::SERVICE_WORD)
//    {
//        qDebug() << "1 --> " << *iterator;
//        iterator++;

//        variableList(iterator);
//    }

//    qDebug() << " check " << *iterator;
////    iterator++;
//    // второй блок - описание вычислений
//    if (*iterator == Lexem::IDENT)
//    {
//        iterator++;
//        qDebug() << " check " << *iterator;
//        if (*iterator == Lexem::OTHER)
//        {
//            iterator++;
//            expression(iterator);
//        }
//    }
}

bool SyntacticalAnalyzer::variableList(QVectorIterator<Lexem> iterator)
{
    qDebug() << "func2 --> " << iterator.peekNext();
    if (iterator.peekNext().getType() == Lexem::IDENT)
    {
//        qDebug() << *iterator;
        iterator.next();

        if(iterator.peekNext().getType() == Lexem::COMMA) // ,
        {
            iterator.next();
            return variableList(iterator);
        }
        else if (iterator.peekNext().getType() == Lexem::COMMA2) // ;
            return true;
        else
            return false;
    }
    else
        return false;

//    qDebug() << "func2 --> " << *iterator;
//    if (*iterator == Lexem::IDENT)
//    {
//        qDebug() << *iterator;
//        iterator++;

//        if(*iterator == Lexem::COMMA) // ,
//        {
//            iterator++;
//            return variableList(iterator);
//        }
//        else if (*iterator == Lexem::COMMA2) // ;
//            return true;
//        else
//            return false;
//    }
//    else
//        return false;
}

bool SyntacticalAnalyzer::statementsList(QVector<Lexem>::iterator iterator)
{
//    if (*iterator == Lexem::IDENT)
//    {
//        iterator++;

//        // 1
//        if (*iterator == Lexem::OTHER) // ":="
//        {

//        }

//        // 2
//        if (*iterator == Lexem::IDENT) //
//        {

//        }
//        else if (*iterator == Lexem::BINARY)
//        {

//        }
//        else if (*iterator == Lexem::CONST)
//        {

//        }
//        else if (*iterator == Lexem::OTHER)
//        {

//        }

//        // 3
//        if (*iterator == Lexem::COMMA)
//        {
//            iterator++;
//            return variableList(iterator);
//        }
//        else if (*iterator == Lexem::COMMA2)
//        {
//            return true;
//        }
//    }
//    else
//        return false;
}

bool SyntacticalAnalyzer::expression(QVectorIterator<Lexem> iterator)
{
//    qDebug() << "exp --> " << *iterator;
    if (iterator.peekNext().getType() == Lexem::UNARY)
        iterator.next();

    subExpression(iterator);
//    qDebug() << "exp --> " << *iterator;
//    if (*iterator == Lexem::UNARY)
//        iterator++;

//    subExpression(iterator);
}

bool SyntacticalAnalyzer::subExpression(QVectorIterator<Lexem> iterator)
{
//    qDebug() << "subExp --> " << *iterator;
    if (iterator.peekNext().getType() == Lexem::OTHER) // (
    {
        // вызываю выражение
        iterator.next();
        expression(iterator);

        iterator.next();
        if (iterator.peekNext().getType() != Lexem::OTHER) // )
        {
            return false;
        }
    }
    else if (iterator.peekNext().getType() == Lexem::IDENT ||
             iterator.peekNext().getType() == Lexem::CONST)
    {
        iterator.next();
        if (iterator.peekNext().getType() == Lexem::COMMA2)
        {
            return true;
        }
        else if (iterator.peekNext().getType() == Lexem::BINARY)
        {
            iterator.next();
            return subExpression(iterator);
        }
    }

    if(iterator.peekNext().getType() == Lexem::COMMA2)
    {
        return true;
    }

//    qDebug() << "subExp --> " << *iterator;
//    if (*iterator == Lexem::OTHER) // (
//    {
//        // вызываю выражение
//        iterator++;
//        expression(iterator);

//        iterator++;
//        if (*iterator != Lexem::OTHER) // )
//        {
//            return false;
//        }
//    }
//    else if (*iterator == Lexem::IDENT ||
//             *iterator == Lexem::CONST)
//    {
//        iterator++;
//        if (*iterator == Lexem::COMMA2)
//        {
//            return true;
//        }
//        else if (*iterator == Lexem::BINARY)
//        {
//            iterator++;
//            return subExpression(iterator);
//        }
//    }

//    if(*iterator == Lexem::COMMA2)
//    {
//        return true;
//    }
}

void SyntacticalAnalyzer::setLexemBox(QVector<Lexem> lexemBox)
{
    this->lexemBox = lexemBox;
}

bool SyntacticalAnalyzer::isCorrect(QString text)
{

//    if (lexemBox.first() == Lexem::SERVICE_WORD)
//        return false;


//    foreach (Lexem lexem, lexemBox) {
//        if (lexem[] == "Var")

//        if (lexem == Lexem::OTHER)
//            return false;
//    }
//    if (!text.isEmpty())
//        return false;

    return true;
}


