#ifndef VEGENERACODE_H
#define VEGENERACODE_H

#include <QString>
#include <QChar>
#include <QVector>

class VegeneraCode
{
public:
    VegeneraCode();
    VegeneraCode(QString text_, QString key_);

    // SETTERS
    void setOriginalText(QString text);
    void setKey(QString key_);
    void restartCrypto();

    // GETTERS
    QString getEncryptedText();
    QString getDecryptedText();
    QString getOriginalText();
    QString getKey();

    // METHODS
    QVector<char> printLowerEnglishASCII();
    QVector<char> printUpperEnglishASCII();

    void encode();
    void decode();

private:
    void prepareKey();

private:
    const int ALPHABET_POWER = 26;
    const int OFFSET = 65;

    QString originalText = "";
    QString key = "";

    QString newKey = "";
    QString encryptedText = "";
    QString decryptedText = "";
};

#endif // VEGENERACODE_H
