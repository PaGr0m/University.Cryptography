#include <QCoreApplication>
#include <QFile>
#include <QDebug>

const QString PATH_TO_FILE = ":/input/resourses/programTest.txt";

const QStringList serviceWords = (QStringList() << "Var");
const QStringList unaryOperations = (QStringList() << "+" << "-" << "*" << "/");
const QStringList signs = (QStringList() << ";" << "." << "=" << ":");
const QStringList otherSymbols = (QStringList() << ":=" << ",");

const QRegExp regLetters("[A-Za-z]");
const QRegExp regDigits("[0-9]");

QString readFromFile(QString pathToFile)
{
    QFile file(pathToFile);
    QByteArray data;

    if (file.open(QIODevice::ReadOnly))
        data = file.readAll();

//    qDebug() << QString(data);

    return data;
}

bool isIdent(QString word)
{
    foreach (QChar symbol, word)
        if (!symbol.isLetter())
            return false;
    return true;
}

bool isConst(QString word)
{
    foreach (QChar symbol, word)
        if (!symbol.isDigit())
            return false;
    return true;
}

QStringList readOnList(QString pathToFile)
{
    QFile file(pathToFile);
    QStringList stringList;

    if (file.open(QIODevice::ReadOnly))
        while(!file.atEnd())
            stringList.append(file.readLine());

    return stringList;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile file(PATH_TO_FILE);
    if (file.open(QIODevice::ReadOnly))
    {
        while (!file.atEnd())
        {
            QByteArray tmp;
            QByteArray symbol = file.read(1);

            // IDENT
            if (isIdent(symbol))
            {
                while (true)
                {
                    tmp = file.read(1);
                    if(isIdent(tmp))
                        symbol.append(tmp);
                    else
                        break;
                }

                if (serviceWords.contains(symbol))
                    qDebug() << symbol + " --> serviceWords";
                else
                    qDebug() << symbol + " --> IDENT";

                if (unaryOperations.contains(tmp))
                    qDebug() << tmp + " --> UNARY";
                else if (signs.contains(tmp))
                    qDebug() << tmp + " --> SIGNS";
                else if (otherSymbols.contains(tmp))
                    qDebug() << tmp + " --> OTHER";

            }

            // CONST
            else if (isConst(symbol))
            {
                while (true)
                {
                    tmp = file.read(1);
                    if (isConst(tmp))
                        symbol.append(tmp);
                    else
                        break;
                }
                qDebug() << symbol + " --> CONST";

                if (unaryOperations.contains(tmp))
                    qDebug() << tmp + " --> UNARY";
                else if (signs.contains(tmp))
                    qDebug() << tmp + " --> SIGNS";
                else if (otherSymbols.contains(tmp))
                    qDebug() << tmp + " --> OTHER";
            }

            // UNART OPERATIONS
            else if (unaryOperations.contains(symbol))
                qDebug() << symbol + " --> UNARY";

            // SIGNS
            else if (signs.contains(symbol))
                qDebug() << symbol + " --> SIGNS";

            // OTHER
            else if (otherSymbols.contains(symbol))
                qDebug() << symbol + " --> OTHER";
        }
    }

    return a.exec();
}

void test()
{
//        foreach (QString line, str)
//        {
//            foreach (QString word, line.split(" "))
//            {
//                qDebug() << word;

//                if (serviceWords.contains(word))
//                {
//                    qDebug() << word + " -> serviceWords";
//                }
//                else if (word.isEmpty())
//                {

//                }
//                else if (unaryOperations.contains(word))
//                {
//                    qDebug() << word + " -> unaryOperations";
//                }
//                else if (signs.contains(word))
//                {
//                    qDebug() << word + " -> signs";
//                }
//                else if (isConst(word))
//                {
//                    qDebug() << word + " -> const";
//                }
//                else if (isIdent(word))
//                {
//                    qDebug() << word + " -> ident";
//                }
//                else if (otherSymbols.contains(word))
//                {
//                    qDebug() << word + " -> other";
//                }
//                else
//                {
//                    qDebug() << "!!! MAIN ERROR !!!";
////                    return 1;
//                }
////                qDebug() << "";
//            }
////            qDebug() << line;
//        }
}
