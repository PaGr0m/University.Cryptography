#include "md5.h"

MD5::MD5()
{

}

unsigned int MD5::F(unsigned int X, unsigned int Y, unsigned int Z)
{
    return ((X & Y) | ((~X) & Z));
}

unsigned int MD5::G(unsigned int X, unsigned int Y, unsigned int Z)
{
    return ((X & Z) | (Y & (~Z)));
}

unsigned int MD5::H(unsigned int X, unsigned int Y, unsigned int Z)
{
    return (X ^ Y ^ Z);
}

unsigned int MD5::I(unsigned int X, unsigned int Y, unsigned int Z)
{
    return (Y ^ (X | (~Z)));
}

unsigned int MD5::rotateToLeft(unsigned int value, unsigned int shift)
{
    return (value << shift | value >> (32 - shift));
}

QString MD5::solve(QString text)
{
    // first part --- initial vector
    QString binaryText;
    for (int i = 0; i < text.length(); i++)
    {
        std::bitset<8> bitset(text.at(i).unicode());

        for (int j = 7; j >= 0; j--)
        {
            if (bitset[j] == 0)
                binaryText.append('0');
            else
                binaryText.append('1');
        }
    }
    binaryText.append('1'); // add '1'

    // second part
    unsigned int zeroCounter = binaryText.length() % 512;
    if (zeroCounter <= 448)
        zeroCounter = 448 - zeroCounter;
    else
        zeroCounter = 512 - zeroCounter + 448;
    for (unsigned int i = 0; i < zeroCounter; i++)
        binaryText.append('0');

    // third part  --- add length
    std::bitset<64> bitset(binaryText.length());
    for (int j = 63; j >= 0; j--)
    {
        if (bitset[j] == 0)
            binaryText.append('0');
        else
            binaryText.append('1');
    }

    // fourth part --- init buffer
    unsigned int counter;
    counter = (binaryText.length()+511)/512;

    unsigned int A = 1732584193; // 01 23 45 67 // 67452301h
    unsigned int B = 4023233417; // 89 AB CD EF // EFCDAB89h
    unsigned int C = 2562383102; // FE DC BA 98 // 98BADCFEh
    unsigned int D = 271733878;  // 76 54 32 10 // 10325476h

    unsigned int AA;
    unsigned int BB;
    unsigned int CC;
    unsigned int DD;

    unsigned int T[64];
    for (int i = 1; i < 65; i++)
        T[i-1] = uint(pow(2, 32) * fabs(sin(i)));

    // CYCLE
    for (unsigned int count = 0; count < counter; count++)
    {
        unsigned int X[16] = {};
        for (int k = 0; k < 512; k++)
        {
            X[k/32] *= 2;
            if (binaryText[k+count*512] == '1')
                ++X[k/32];
        }

        // INIT
        A = AA + A;
        B = BB + B;
        C = CC + C;
        D = DD + D;

        // FIRST PART
        A = B + rotateToLeft((A + F(B,C,D) + X[0] + T[0]), 7);
        D = A + rotateToLeft((D + F(A,B,C) + X[1] + T[1]), 12);
        C = D + rotateToLeft((C + F(D,A,B) + X[2] + T[2]), 17);
        B = C + rotateToLeft((B + F(C,D,A) + X[3] + T[3]), 22);

        A = B + rotateToLeft((A + F(B,C,D) + X[4] + T[4]), 7);
        D = A + rotateToLeft((D + F(A,B,C) + X[5] + T[5]), 12);
        C = D + rotateToLeft((C + F(D,A,B) + X[6] + T[6]), 17);
        B = C + rotateToLeft((B + F(C,D,A) + X[7] + T[7]), 22);

        A = B + rotateToLeft((A + F(B,C,D) + X[8] + T[8]), 7);
        D = A + rotateToLeft((D + F(A,B,C) + X[9] + T[9]), 12);
        C = D + rotateToLeft((C + F(D,A,B) + X[10] + T[10]), 17);
        B = C + rotateToLeft((B + F(C,D,A) + X[11] + T[11]), 22);

        A = B + rotateToLeft((A + F(B,C,D) + X[12] + T[12]), 7);
        D = A + rotateToLeft((D + F(A,B,C) + X[13] + T[13]), 12);
        C = D + rotateToLeft((C + F(D,A,B) + X[14] + T[14]), 17);
        B = C + rotateToLeft((B + F(C,D,A) + X[15] + T[15]), 22);

        // SECOND PART
        A = B + rotateToLeft((A + G(B,C,D) + X[1] + T[16]), 5);
        D = A + rotateToLeft((D + G(A,B,C) + X[6] + T[17]), 9);
        C = D + rotateToLeft((C + G(D,A,B) + X[11] + T[18]), 14);
        B = C + rotateToLeft((B + G(C,D,A) + X[0] + T[19]), 20);

        A = B + rotateToLeft((A + G(B,C,D) + X[5] + T[20]), 5);
        D = A + rotateToLeft((D + G(A,B,C) + X[10] + T[21]), 9);
        C = D + rotateToLeft((C + G(D,A,B) + X[15] + T[22]), 14);
        B = C + rotateToLeft((B + G(C,D,A) + X[4] + T[23]), 20);

        A = B + rotateToLeft((A + G(B,C,D) + X[9] + T[24]), 5);
        D = A + rotateToLeft((D + G(A,B,C) + X[14] + T[25]), 9);
        C = D + rotateToLeft((C + G(D,A,B) + X[3] + T[26]), 14);
        B = C + rotateToLeft((B + G(C,D,A) + X[8] + T[27]), 20);

        A = B + rotateToLeft((A + G(B,C,D) + X[13] + T[28]), 5);
        D = A + rotateToLeft((D + G(A,B,C) + X[2] + T[29]), 9);
        C = D + rotateToLeft((C + G(D,A,B) + X[7] + T[30]), 14);
        B = C + rotateToLeft((B + G(C,D,A) + X[12] + T[31]), 20);

        // THIRD PART
        A = B + rotateToLeft((A + H(B,C,D) + X[5] + T[32]), 4);
        D = A + rotateToLeft((D + H(A,B,C) + X[8] + T[33]), 11);
        C = D + rotateToLeft((C + H(D,A,B) + X[11] + T[34]), 16);
        B = C + rotateToLeft((B + H(C,D,A) + X[14] + T[35]), 23);

        A = B + rotateToLeft((A + H(B,C,D) + X[1] + T[36]), 4);
        D = A + rotateToLeft((D + H(A,B,C) + X[4] + T[37]), 11);
        C = D + rotateToLeft((C + H(D,A,B) + X[7] + T[38]), 16);
        B = C + rotateToLeft((B + H(C,D,A) + X[10] + T[39]), 23);

        A = B + rotateToLeft((A + H(B,C,D) + X[13] + T[40]), 4);
        D = A + rotateToLeft((D + H(A,B,C) + X[0] + T[41]), 11);
        C = D + rotateToLeft((C + H(D,A,B) + X[3] + T[42]), 16);
        B = C + rotateToLeft((B + H(C,D,A) + X[6] + T[43]), 23);

        A = B + rotateToLeft((A + H(B,C,D) + X[9] + T[44]), 4);
        D = A + rotateToLeft((D + H(A,B,C) + X[12] + T[45]), 11);
        C = D + rotateToLeft((C + H(D,A,B) + X[15] + T[46]), 16);
        B = C + rotateToLeft((B + H(C,D,A) + X[2] + T[47]), 23);

        // FOURTH PART
        A = B + rotateToLeft((A + I(B,C,D) + X[0] + T[48]), 6);
        D = A + rotateToLeft((D + I(A,B,C) + X[7] + T[49]), 10);
        C = D + rotateToLeft((C + I(D,A,B) + X[14] + T[50]), 15);
        B = C + rotateToLeft((B + I(C,D,A) + X[5] + T[51]), 21);

        A = B + rotateToLeft((A + I(B,C,D) + X[12] + T[52]), 6);
        D = A + rotateToLeft((D + I(A,B,C) + X[3] + T[53]), 10);
        C = D + rotateToLeft((C + I(D,A,B) + X[10] + T[54]), 15);
        B = C + rotateToLeft((B + I(C,D,A) + X[1] + T[55]), 21);

        A = B + rotateToLeft((A + I(B,C,D) + X[8] + T[56]), 6);
        D = A + rotateToLeft((D + I(A,B,C) + X[15] + T[57]), 10);
        C = D + rotateToLeft((C + I(D,A,B) + X[6] + T[58]), 15);
        B = C + rotateToLeft((B + I(C,D,A) + X[13] + T[59]), 21);

        A = B + rotateToLeft((A + I(B,C,D) + X[4] + T[60]), 6);
        D = A + rotateToLeft((D + I(A,B,C) + X[11] + T[61]), 10);
        C = D + rotateToLeft((C + I(D,A,B) + X[2] + T[62]), 15);
        B = C + rotateToLeft((B + I(C,D,A) + X[9] + T[63]), 21);

        // SUM
        A = AA + A;
        B = BB + B;
        C = CC + C;
        D = DD + D;
    }

    QString result = QString::number(A, 16) +
                     QString::number(B, 16) +
                     QString::number(C, 16) +
                     QString::number(D, 16);
    qDebug() << result;
    return result;
}
