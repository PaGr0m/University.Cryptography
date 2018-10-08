#ifndef SYNTACTICALANALYZER_H
#define SYNTACTICALANALYZER_H

#include <QFile>
#include <QVector>

#include "lexicalanalyzer.h"

class SyntacticalAnalyzer
{
public:
    SyntacticalAnalyzer();
    SyntacticalAnalyzer(QVector<Lexem> lexemBox);

public:
    void readFileToString();

    bool declarationOfVariables();
    bool variableList();

//    bool statement()
    bool expression();
    bool subExpression();

    void setLexemBox(QVector<Lexem> lexemBox);
    void setIterator(QVector<Lexem>::iterator iterator);
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
    QVector<Lexem>::iterator iterator;
};

#endif // SYNTACTICALANALYZER_H
