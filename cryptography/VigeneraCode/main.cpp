#include <QCoreApplication>
#include <QDebug>
#include <QString>

#include <iomanip>
#include <iostream>

using namespace std;

const int alphabetPower = 26;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const QString originalText = "ATTACKATDAWN";
    const QString key = "LEMON";

    QString newKey = "";
    QString encryptedText = "";

    // A=65, Z=90
    for (char symbol = 65; symbol <= 90; symbol++) cout << int(symbol) << ") " << symbol << endl;

    // a=97, z=122
    for (char symbol = 97; symbol <= 122; symbol++) cout << int(symbol) << ") " << symbol << endl;

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
    else
    {
        newKey = key;
    }

    int offset = 65;
    // ENCODE
    for (int i = 0; i < originalText.length(); i++)
        encryptedText.append(QChar(char((int(originalText.at(i).toLatin1()) - offset + int(newKey.at(i).toLatin1()) - offset) % alphabetPower + offset)));

    // DECODE
    for (int i = 0; i < originalText.length(); i++)
        encryptedText.append(QChar((int(originalText.at(i).toLatin1()) - offset - (int(newKey.at(i).toLatin1()) - offset) + alphabetPower) % alphabetPower + offset));

    qDebug() << originalText;
    qDebug() << newKey;
    qDebug() << encryptedText;

    return a.exec();
}
