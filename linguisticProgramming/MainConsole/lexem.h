#ifndef LEXEM_H
#define LEXEM_H

#include <QString>
#include <QDebugStateSaver>

class Lexem
{
public:
    enum Types
    {
        SERVICE_WORD,
        IDENT,
        CONST,
        BINARY,
        UNARY,

        // SIGNS
        COMMA,
        SEMICOLON,
        ASSIGMENT,

        BRACKET_OPENING,
        BRACKET_CLOSING,

        NONE
    };

public:
    Lexem();
    Lexem(QString name,
          Types type);

    QString getName() const;
    Types getType() const;

    void convertDebug();

    bool operator == (enum Types type);
    bool operator == (const Lexem lexem);
    bool operator != (enum Types type);
    bool operator != (const Lexem lexem);

    friend QDebug operator <<(QDebug debug, const Lexem lexem);

private:
    QString name;
//    QString type;
    Types type;
};

QDebug operator <<(QDebug debug, const Lexem lexem);

#endif // LEXEM_H
