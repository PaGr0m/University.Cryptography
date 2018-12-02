#include <QCoreApplication>
#include <QFile>
#include <QDebug>

#include "lexicalanalyzer.h"
#include "syntacticalanalyzer.h"
#include "semanticanalyzer.h"


const QString PATH_TO_FILE = ":/input/resourses/test_1.txt";

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // INIT LEXICAL ANALYZER
    LexicalAnalyzer lexicalAnalyzer(PATH_TO_FILE);

    // INIT SYNTACTICAL ANALYZER
    SyntacticalAnalyzer syntacticalAnalyzer(lexicalAnalyzer.run());

    // INIT SEMANTIC ANALYZER
    SemanticAnalyzer semanticAnalyzer(lexicalAnalyzer.run());

    // DEBUG
    qDebug() << "Lexical Analyzer = " << lexicalAnalyzer.getLexemBox();
    qDebug() << "Syntactical Analyzer = " << syntacticalAnalyzer.declarationOfVariables();
    qDebug() << "Semantic Analyzer: ";
    semanticAnalyzer.toForm();

    return app.exec();
}
