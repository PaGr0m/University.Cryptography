#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include <QFile>
#include <QString>
#include <QVector>
#include <QDebug>

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

    void printInfo(QString value, QString type);
    void run();

private:
    const QVector<QString> serviceWords = {"Var"};
    const QVector<QString> unaryOperations = {"+", "-", "*", "/"};
    const QVector<QString> signs = {";", ".", "=", ":"};
    const QVector<QString> otherSymbols = {":=", ".", " "};

private:
    bool printFlag = true;
    int index = 0;

    QFile file;
    QString text;
    QString path = "";

    QVector<QString> lexemBox;
};

#endif // LEXICALANALYZER_H
