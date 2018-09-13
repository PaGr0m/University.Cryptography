#include "vegeneracode.h"

VegeneraCode::VegeneraCode()
{
    this->originalText = "";
    this->key = "";
    this->newKey = "";
    this->encryptedText = "";
    this->decryptedText = "";
}

VegeneraCode::VegeneraCode(QString text_, QString key_)
{
    this->originalText = text_;
    this->key = key_;
    this->newKey = "";
    this->encryptedText = "";
    this->decryptedText = "";
}

void VegeneraCode::setOriginalText(QString text)
{
    this->originalText = text;
}

void VegeneraCode::setKey(QString key_)
{
    this->key = key_;
}

void VegeneraCode::restartCrypto()
{
    this->newKey = "";
    this->encryptedText = "";
    this->decryptedText = "";
}

QString VegeneraCode::getEncryptedText()
{
    return this->encryptedText;
}

QString VegeneraCode::getDecryptedText()
{
    return this->decryptedText;
}

QString VegeneraCode::getOriginalText()
{
    return this->originalText;
}

QString VegeneraCode::getKey()
{
    return this->key;
}

QVector<char> VegeneraCode::printLowerEnglishASCII()
{
    QVector<char> tmpVector;

    for (char symbol = 97; symbol <= 122; symbol++)
        tmpVector.append(symbol);

    return tmpVector;
}

QVector<char> VegeneraCode::printUpperEnglishASCII()
{
    QVector<char> tmpVector;

    for (char symbol = 65; symbol <= 90; symbol++)
        tmpVector.append(symbol);

    return tmpVector;
}

void VegeneraCode::encode()
{
    prepareKey();
    this->encryptedText = "";

    for (int i = 0; i < originalText.length(); i++)
    {
        int firstLetter = originalText.at(i).toLatin1() - this->OFFSET;
        int secondLetter = newKey.at(i).toLatin1() - this->OFFSET;
        QChar encryptedLetter = (firstLetter + secondLetter) % this->ALPHABET_POWER + this->OFFSET;

        this->encryptedText.append(encryptedLetter);
    }
}

void VegeneraCode::decode()
{
    prepareKey();
    this->decryptedText = "";

    for (int i = 0; i < originalText.length(); i++)
    {
        int firstLetter = originalText.at(i).toLatin1() - this->OFFSET;
        int secondLetter = newKey.at(i).toLatin1() - this->OFFSET;
        QChar decryptedLetter = (firstLetter - secondLetter + this->ALPHABET_POWER) % this->ALPHABET_POWER + this->OFFSET;

        this->decryptedText.append(decryptedLetter);
    }
}

void VegeneraCode::prepareKey()
{
    this->newKey = "";
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
}
