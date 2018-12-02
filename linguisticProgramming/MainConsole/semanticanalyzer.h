#ifndef SEMANTICANALYZER_H
#define SEMANTICANALYZER_H

#include "lexicalanalyzer.h"


class SemanticAnalyzer
{
public:
    SemanticAnalyzer();
    SemanticAnalyzer(QVector<Lexem> lexemBox);
    SemanticAnalyzer(LexicalAnalyzer lexicalAnalyzer);

    void toForm();

private:
    QVector<Lexem> lexemBox;
    QVector<Lexem>::iterator iterator;
};

#endif // SEMANTICANALYZER_H
