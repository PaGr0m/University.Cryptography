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
    void expression();

    bool declarationOfVariables();
    bool variableList();
    bool subExpression();

    void setLexemBox(QVector<Lexem> lexemBox);
    void setIterator(QVector<Lexem>::iterator iterator);

private:
    QFile file;
    QString text;

    QVector<Lexem> lexemBox;
    QVector<Lexem>::iterator iterator;
};

#endif // SYNTACTICALANALYZER_H
