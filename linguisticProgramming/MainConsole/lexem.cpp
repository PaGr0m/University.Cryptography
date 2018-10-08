#include "lexem.h"

Lexem::Lexem()
{
    this->name = "";
    this->type = Lexem::NONE;
}

Lexem::Lexem(QString name, Lexem::Types type)
{
    this->name = name;
    this->type = type;
}

QString Lexem::getName() const
{
    return this->name;
}

Lexem::Types Lexem::getType() const
{
    return this->type;
}

void Lexem::convertDebug()
{
    // if ()
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
    debug.nospace() << "(" << lexem.getName() << ", " << lexem.getType() << ")";

    return debug;
}
