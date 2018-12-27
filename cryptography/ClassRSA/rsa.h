#ifndef RSA_H
#define RSA_H

#include <QtMath>
#include <QString>
#include <QDebug>


class RSA
{
public:
    RSA();
    RSA(long long p, long long q, long long e);

    bool isPrime(long long value);
    long long gcd(long long first, long long second);
    void prepareValues(long long p, long long q, long long e);

    QString encrypt(QString text);
    QString decrypt(QString text);

private:
    long long p;
    long long q;
    long long e;
    long long n;
    long long d;
    long long ecl;
    long long buffer;

    QString outputText;
};

#endif // RSA_H
