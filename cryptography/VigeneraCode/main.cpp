#include <QCoreApplication>
#include <QDebug>
#include <QString>

#include <iomanip>
#include <iostream>

using namespace std;

const unsigned int alphabetPower = 25;

//QString decode(QString word)
//{

//}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const QString originalText = "ATTACKATDAWN";
    const QString key = "LEMON";

//    const QString originalText = "LEMON";
//    const QString key = "ATTACKATDAWN";

    QString newKey = "";
    QString encryptedText = "";

    // A=65, Z=90
    for (char symbol = 65; symbol <= 90; symbol++) cout << int(symbol) << ") " << symbol << endl;

    // a=97, z=122
//    for (char symbol = 97; symbol <= 122; symbol++) cout << symbol << endl;

    if (originalText.length() > key.length())
    {
        for (int i = 0; i < originalText.length()/key.length(); i++)
            newKey.append(key);

        for (int i = 0; i < originalText.length()%key.length(); i++)
            newKey.append(key.at(i));
    }
    else if (originalText.length() < key.length())
    {
        newKey.append(key);
        newKey.remove(originalText.length(), key.length() - originalText.length());
    }

    qDebug() << originalText;
    qDebug() << newKey;


   // ENCODE
    for (int i = 0; i < originalText.length(); i++)
    {
//        encryptedText.at(i) = (originalText.at(i).toLatin1() + newKey.at(i).toLatin1());
    }

    int offset = 65;
    qDebug() << int(originalText.at(0).toLatin1()) - offset << int(newKey.at(0).toLatin1()) - offset;
    qDebug() <<

//    qDebug() << (originalText.at(0).toLatin1() + newKey.at(0).toLatin1() - 65) % 26;
//    qDebug() << char((originalText.at(0).toLatin1() + newKey.at(0).toLatin1()) % 90);

    return a.exec();
}
