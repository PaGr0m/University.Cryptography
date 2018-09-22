#include <QCoreApplication>
#include <QFile>
#include <QDebug>

#include "lexicalanalyzer.h"

const QString PATH_TO_FILE = ":/input/resourses/test_4.txt";

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    LexicalAnalyzer lexicalAnalyzer;
    lexicalAnalyzer.setPath(PATH_TO_FILE);
    lexicalAnalyzer.run();

    return a.exec();
}
