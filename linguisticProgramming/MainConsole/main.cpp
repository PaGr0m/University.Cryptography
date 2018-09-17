#include <QCoreApplication>
#include <QFile>
#include <QDebug>

const QString PATH_TO_FILE = ":/input/resourses/programTest.txt";

const QStringList serviceWords = (QStringList() << "Var");
const QStringList unaryOperations = (QStringList() << "+" << "-" << "*" << "/");
const QStringList signs = (QStringList() << ";" << "." << "=");
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
    int count = 0;

    foreach (QChar symbol, word)
        if (symbol.isLetter())
            count++;

    if (count == word.length())
        return true;
    else
        return false;
}

bool isConst(QString word)
{
    int count = 0;

    foreach (QChar symbol, word)
        if (symbol.isDigit())
            count++;

    if (count == word.length())
        return true;
    else
        return false;
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

    QStringList str = readOnList(PATH_TO_FILE);

//    QStringList str;
//    QString qwe = readFromFile(PATH_TO_FILE);
//    foreach (QString line, qwe.split("\n"))
//    {
//        str.append(line);
//    }


//    foreach( const QString& str, strings )
    foreach (QString line, str)
    {
        foreach (QString word, line.split(" "))
        {
            qDebug() << word;

            if (serviceWords.contains(word))
            {
                qDebug() << word + " -> serviceWords";
            }
            else if (unaryOperations.contains(word))
            {
                qDebug() << word + " -> unaryOperations";
            }
            else if (signs.contains(word))
            {
                qDebug() << word + " -> signs";
            }
            else if (isConst(word))
            {
                qDebug() << word + " -> const";
            }
            else if (isIdent(word))
            {
                qDebug() << word + " -> ident";
            }
            else if (otherSymbols.contains(word))
            {
                qDebug() << word + " -> other";
            }
            else
            {
                qDebug() << "!!! MAIN ERROR !!!";
                return 1;
            }
//            qDebug() << "";
        }

//        qDebug() << line;
    }

    return a.exec();
}
