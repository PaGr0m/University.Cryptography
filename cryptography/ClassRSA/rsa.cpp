#include "rsa.h"

RSA::RSA()
{

}

RSA::RSA(long long p, long long q, long long e):
    p(p), q(q), e(e)
{
    this->n = this->p * this->q;
    this->ecl = (this->p - 1) * (this->q - 1);
    this->buffer = gcd(this->ecl, this->e);

    if (buffer != 1)
        qDebug() << "Одно из чисел не подходит по условию задачи";

    for (int i = 2; i < this->ecl; i++)
    {
        if ((i * this->e) % this->ecl == 1)
        {
            this->d = i;
            break;
        }
    }
}

bool RSA::isPrime(long long value)
{
    if (value%2 == 0)
        return false;

    for (int i = 3; i <= qSqrt(value); i+=2)
        if (value%i == 0)
            return false;
    return true;
}

long long RSA::gcd(long long first, long long second)
{
    return second ? gcd (second, first % second) : first;
}

QString RSA::encrypt(QString text)
{
    for(int i = 0; i < text.length(); i++)
    {
        int numLet = text.at(i).unicode();
        qDebug() << i << numLet;

        for (int j = 2; j <= this->e; j++)
        {
            numLet *= text.at(i).unicode();
            numLet %= this->n;
        }

        numLet %= this->n;
        outputText.append(QString::number(numLet));
        outputText.append(' ');
    }
    return outputText;
}

QString RSA::decrypt(QString text)
{
    outputText.clear();
    long long numLet = 0;
    QString oneLet;

    for (int i = 0; i < text.length(); i++)
    {
        if((text.at(i) != ' ') && (i != text.length() - 1))
        {
            oneLet.append(text.at(i));
        }
        else
        {
            numLet = oneLet.toInt();
            qDebug() << numLet;

            for (int j = 2; j <= this->d; j++)
            {
                numLet *= oneLet.toInt();
                numLet %= this->n;
            }

            numLet %= this->n;
            qDebug() << numLet;

            oneLet = "";
            int textSymbol = numLet;

            outputText.append(QChar(textSymbol));
        }
    }

    return outputText;
}
