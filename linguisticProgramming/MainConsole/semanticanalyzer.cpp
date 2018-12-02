#include "semanticanalyzer.h"

SemanticAnalyzer::SemanticAnalyzer()
{

}

SemanticAnalyzer::SemanticAnalyzer(QVector<Lexem> lexemBox):
    lexemBox(lexemBox)
{

}

SemanticAnalyzer::SemanticAnalyzer(LexicalAnalyzer lexicalAnalyzer):
    lexemBox(lexicalAnalyzer.getLexemBox())
{

}

void SemanticAnalyzer::toForm()
{
    QString text;
    bool flag = false;
    int counter = -1;

    foreach (Lexem lexem, lexemBox)
    {
        if (lexem.getName() == ":=")
            text.append("= ");
        else if (lexem.getName() != ";")
            text.append(lexem.getName()).append(" ");
        else
        {
            text.append(";\n");
            counter++;

            if (counter == 0)
                text.append("[\n");
        }
    }
    text.append("]");

    QFile file("/home/pagrom/university/linguisticProgramming/MainConsole/resourses/out_1.txt");

    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << file.isOpen();
        QTextStream writeStream(&file);
        writeStream << text;
        file.close();
    }

    qDebug() << text;
}
