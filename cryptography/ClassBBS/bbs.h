#ifndef BBS_H
#define BBS_H

#include <QString>
#include <math.h>
#include <QDebug>

class BBS
{
public:
    BBS();

    QVector<QString> solve(int p, int q);
};

#endif // BBS_H
