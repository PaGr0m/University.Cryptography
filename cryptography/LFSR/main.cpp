#include <QCoreApplication>
#include <QString>
#include <QTextStream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream qtin(stdin);

    QByteArray IV;
    QByteArray word;
    QByteArray C;
    QByteArray Z;
    QByteArray Y;
    QByteArray X;

    qDebug() << "Enter the word: ";
    word = qtin.readLine().toLatin1();

    qDebug() << "\nEnter the IV:";
    IV = qtin.readLine().toLatin1();

    qDebug() << "\nEnter the C:";
    C = qtin.readLine().toLatin1();

    // Вектор ключей
    Z = IV;
    for (int i = IV.length(); i < word.length(); i++)
    {

        short tmp = C.at(0) & Z.at(i-C.length());
        for (int j = 1; j < C.length(); j++)
        {
            tmp ^= C.at(j) & Z.at(i+j-C.length());
        }
        Z.append(QString::number(tmp));
        qDebug() << "Z[" << i << "] " << QString::number(tmp);
    }

    // Y (emcode)
    for (int i = 0; i < Z.length(); i++)
    {
        short tmp;
        tmp = word.at(i) ^ Z.at(i);
        Y.append(QString::number(tmp));
    }
    qDebug() << "ENCODE --> " << Y;

    // X (decode)
    for (int i = 0; i < Z.length(); i++)
    {
        short tmp;
        tmp = Y.at(i) ^ Z.at(i);
        X.append(QString::number(tmp));
    }
    qDebug() << "DECODE --> " << X;

    return a.exec();
}
