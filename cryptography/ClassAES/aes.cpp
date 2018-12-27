#include "aes.h"

AES::AES()
{

}

QVector<QByteArray> AES::keyExpansion(QString key, int numberKey)
{
    int numberByte = NUMBER_BYTE;
    int numberRound = numberKey + NUMBER_ROUND;

    QVector<QByteArray> keyFinal;
    QByteArray keyAll;

    QString bufferString;
    for (int i = 0; i < numberKey * 4; i++)
    {
        for (int j = 0; j < 8; j++)
            bufferString[j] = key[i*8 + j];

        keyFinal.append(QByteArray::number(bufferString.toInt(nullptr, BIT), HEX));
    }

    for (int i = numberKey; i < numberByte*(numberRound+1); i++)
    {
        QVector<QByteArray> buffer;

        for (int j = 0; j < 4; j++)
            buffer.append(keyFinal[i*4-4+j]);

        if (i%numberKey == 0)
        {
            std::rotate(buffer.begin(),
                        buffer.begin() + 1,
                        buffer.end());

            for (int k = 0; k < 4; k++)
            {
                buffer[k] = QByteArray::number((Sbox[buffer[k].toInt(nullptr, HEX)]), HEX);
                buffer[k] = QByteArray::number((buffer[k].toInt(nullptr, HEX) ^
                                                keyFinal[i*4-16+k].toInt(nullptr, HEX) ^
                                                Rcon[i-4+k]), HEX);
            }
        }
        else
        {
            for (int k = 0; k < 4; k++)
                buffer[k] = QByteArray::number((buffer[k].toInt(nullptr, HEX) ^
                                                keyFinal[i*4-16+k].toInt(nullptr, HEX)), HEX);
        }

        for (int k = 0; k < 4; k++)
            keyFinal.append(buffer[k]);
    }

    return keyFinal;
}
