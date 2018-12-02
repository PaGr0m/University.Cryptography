#include "lexem.h"

Lexem::Lexem():
    name(), type(Lexem::NONE)
{

}

Lexem::Lexem(QString name, Lexem::Types type):
    name(name), type(type)
{

}

QString Lexem::getName() const
{
    return this->name;
}

Lexem::Types Lexem::getType() const
{
    return this->type;
}

QString Lexem::getTypesName() const
{
    switch (type)
    {
        case SERVICE_WORD:
            return "SERVICE_WORD";
        case IDENT:
            return "IDENT";
        case CONST:
            return "CONST";
        case BINARY:
            return "BINARY";
        case UNARY:
            return "UNARY";
        case COMMA:
            return "COMMA";
        case SEMICOLON:
            return "SEMICOLON";
        case ASSIGMENT:
            return "ASSIGMENT";
        case BRACKET_OPENING:
            return "BRACKET_OPENING";
        case BRACKET_CLOSING:
            return "BRACKET_CLOSING";

        default:
            return "NONE";
    }
}

bool Lexem::operator ==(Lexem::Types type)
{
    return this->type == type;
}

bool Lexem::operator ==(const Lexem lexem)
{
    return this->type == lexem.type;
}

bool Lexem::operator !=(Lexem::Types type)
{
    return this->type != type;
}

bool Lexem::operator !=(const Lexem lexem)
{
    return this->type != lexem.type;
}

QDebug operator <<(QDebug debug, const Lexem lexem)
{
    QDebugStateSaver saver(debug);
    debug.nospace() << "(" << lexem.getName() << ", " << lexem.getTypesName() << ")" << "\n";

    return debug;
}
