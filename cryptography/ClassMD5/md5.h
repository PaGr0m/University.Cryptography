#ifndef MD5_H
#define MD5_H

#include "bitset"
#include <QString>
#include <math.h>
#include <QDebug>

class MD5
{
public:
    MD5();

    unsigned int F(unsigned int X, unsigned int Y, unsigned int Z);
    unsigned int G(unsigned int X, unsigned int Y, unsigned int Z);
    unsigned int H(unsigned int X, unsigned int Y, unsigned int Z);
    unsigned int I(unsigned int X, unsigned int Y, unsigned int Z);

    unsigned int rotateToLeft(unsigned int value, unsigned int shift);

    QString solve(QString text);
};

#endif // MD5_H
