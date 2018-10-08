#ifndef SYNTACTICALANALYZER_H
#define SYNTACTICALANALYZER_H

#include <QFile>
#include <QVector>

#include "lexicalanalyzer.h"

class SyntacticalAnalyzer
{
public:
    SyntacticalAnalyzer();

public:
    void readFileToString();

    bool declarationOfVariables(QVectorIterator <Lexem> iterator);
    bool variableList(QVectorIterator <Lexem> iterator);

    bool statementsList(QVector<Lexem>::iterator iterator);

//    bool statement()
    bool expression(QVectorIterator <Lexem> iterator);
    bool subExpression(QVectorIterator <Lexem> iterator);




    void setLexemBox(QVector<Lexem> lexemBox);
    bool isCorrect(QString text);

private:
    const QVector<QString> serviceWords = {"Var"};
    const QVector<QString> unaryOperations = {"+", "-", "*", "/"};
    const QVector<QString> signs = {";", ".", "=", ":", ","};
    const QVector<QString> otherSymbols = {":=", "."};
    const QVector<QString> stringSymbols = {" ", "\n", "\r"};

private:
    QFile file;
    QString text;

    QVector<Lexem> lexemBox;

};

#endif // SYNTACTICALANALYZER_H
