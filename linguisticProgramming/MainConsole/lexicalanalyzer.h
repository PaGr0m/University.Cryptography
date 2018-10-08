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

    bool isConst(QString word);
    bool isIdent(QString word);
    bool isOther(QString word);
    bool isSigns(QString word);
    bool isUnary(QString word);

    void readFileToString();

    void setFile(QString path);
    void setPath(QString path);


    QVector<Lexem> run();

private:
    const QVector<QString> serviceWords = {"Var"};
    const QVector<QString> unaryOperations = {"+", "-", "*", "/"};
//    const QVector<QString> commas = {",", ";", ""};
//    const QVector<QString> signs = {".", "=", ":"};
    const QVector<QString> signs = {",", ";", ":", "(", ")"};
//    const QVector<QString> otherSymbols = {":=", ")", "("};
    const QVector<QString> stringSymbols = {" ", "\n", "\r"};

private:
    bool printFlag = true;
    int index = 0;

    QFile file;
    QString text;
    QString path = "";

    QVector<Lexem> lexemBox;
};

#endif // LEXICALANALYZER_H
