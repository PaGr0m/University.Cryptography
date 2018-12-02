#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include <QFile>
#include <QString>
#include <QVector>
#include <QDebug>

#include "lexem.h"


class LexicalAnalyzer
{
public:
    LexicalAnalyzer();
    LexicalAnalyzer(QString path);

    void readFileToString();
    void setPath(QString path);

    QVector<Lexem> run();    
    QVector<Lexem> getLexemBox();

private:
    bool isConst(QString word);
    bool isIdent(QString word);
    bool isSigns(QString word);
    bool isUnary(QString word);

    const QVector<QString> serviceWords = {"Var"};
    const QVector<QString> unaryOperations = {"+", "-", "*", "/"};
    const QVector<QString> signs = {",", ";", ":", "(", ")"};
    const QVector<QString> stringSymbols = {" ", "\n", "\r"};

    bool printFlag = true;
    int index = 0;

    QString text;
    QString path = "";

    QVector<Lexem> lexemBox;
};

#endif // LEXICALANALYZER_H
