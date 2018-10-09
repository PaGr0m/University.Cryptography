#include <QCoreApplication>
#include <QFile>
#include <QDebug>

#include "lexicalanalyzer.h"
#include "syntacticalanalyzer.h"

const QString PATH_TO_FILE = ":/input/resourses/test_1.txt";

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // INIT LEXICAL ANALYZER
    LexicalAnalyzer lexicalAnalyzer;
    lexicalAnalyzer.setPath(PATH_TO_FILE);

    QVector<Lexem> lexemBox = lexicalAnalyzer.run();

    // INIT SYNTACTICAL ANALYZER
    SyntacticalAnalyzer syntacticalAnalyzer;
    syntacticalAnalyzer.setLexemBox(lexemBox);
    syntacticalAnalyzer.setIterator(lexemBox.begin());

    // DEBUG
    qDebug() << lexemBox;
    qDebug() << syntacticalAnalyzer.declarationOfVariables();

    return a.exec();
}

/*
    TODO: 1) переименовать функции
          2) проверить код. Указать на setters
          3) можно ли переименовать проект? Стоит ли сделать класс,
             который будет агригировать анализаторы, и запускать все классы внутри
          4) переопределить readFileToString с void на bool (проверка на открытие файла)
          5) переписать логику в конструкторы
*/
