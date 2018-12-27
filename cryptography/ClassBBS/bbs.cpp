#include "bbs.h"

BBS::BBS()
{

}

QVector<QString> BBS::solve(int p, int q)
{
    // 1 - time, 2 - bin, 3 - number
    QVector<QString> results;

    time_t resultTime = time(NULL);
    qDebug() << resultTime;
    int rnd = resultTime;

    int n = p*q;
    int z[31];

    long long s = 1;
    long long result = 0;

    rnd = rnd*rnd % n;

    QString resultBinary;
    for (int i = 0; i < 32; i++)
    {
        rnd = rnd*rnd % n;

        if (rnd % 2 == 0)
            z[i] = 0;
        else
            z[i] = 1;

        resultBinary.append(QString::number(z[i]));
    }

    qDebug() << resultBinary;

    for (int i = 31; i >= 0; i--)
    {
        if (z[i] == 1)
            result += s;

        s*=2;
    }
    qDebug() << result;

    results.append(QString::number(resultTime));
    results.append(resultBinary);
    results.append(QString::number(result));

    return results;
}
