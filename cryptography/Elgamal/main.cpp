#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QtMath>
#include <QRandomGenerator>


int main(int argc, char *argv[])
{
    QCoreApplication application(argc, argv);

    QTextStream qtin(stdin);

    QString word;
    qint32 P;
    qint32 G;
    qint32 X;
    qint32 Y;
    qint32 K;
    qint32 A;
    QVector<qint32> B;

//    qDebug() << "Enter the P:";
//    P = qtin.readLine().toInt();
//    qDebug() << "Enter the G:";
//    G = qtin.readLine();
//    qDebug() << "Enter the X:";
//    X = qtin.readLine();

    // SETTINGS
    int OFFSET = 65;
    word = "Pavel";
    P = 23;
    G = 3;
    X = 5;

    // LOGIC
    K = rand() % (P-1);

    Y = int(qPow(G, X)) % P;
    A = int(qPow(G, K)) % P;
//       int firstLetter = originalText.at(i).toLatin1() - this->OFFSET;

    foreach (QString letter, word)
    {
//        int tmp = letter;
        qDebug() << letter.toLatin1() - 65;
//        B.append(int(qPow(Y, K) * (letter.toLatin1() - OFFSET) % P);

    }
    qDebug() << B;

    qDebug() << K;
    return application.exec();
}
