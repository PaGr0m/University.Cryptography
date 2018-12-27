#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEditKey->setPlainText("1 0 0 1 0 0 1 0 0 0 1 1 1 0 0 0 "
                                  "1 0 0 1 0 0 1 0 1 0 1 1 1 0 0 1 "
                                  "1 0 0 1 0 0 1 0 0 0 1 1 1 0 0 0 "
                                  "1 0 0 1 0 0 1 0 1 0 1 1 1 0 0 1 "
                                  "1 0 0 1 0 0 1 0 0 0 1 1 1 0 0 0 "
                                  "1 0 0 1 0 0 1 0 1 0 1 1 1 0 0 1 "
                                  "1 1 0 0 1 0 0 1 1 0 1 1 1 0 0 1 "
                                  "0 0 1 1 0 1 1 0 0 1 1 0 0 0 1 1 "); // 16 * 8 = 128 bit

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setKey(QString text, int keySize)
{
    QString keyToString;
    QVector<QByteArray> key = aes.keyExpansion(text, keySize);

    for (QVector<QByteArray>::iterator it = key.begin(); it != key.end(); ++it)
        keyToString += QString::fromStdString(it->toStdString()) + " ";

    ui->textEditExpandKey->setPlainText(keyToString);
}

void MainWindow::on_pushButtonKey_clicked()
{
    int keySize;
    QString text = ui->textEditKey->toPlainText();
//    QString text = ui->textEditKey->toPlainText().split(QRegExp("\\s+"), QString::SkipEmptyParts);

    QString newText;
    for (auto it = text.begin(); it != text.end(); ++it)
    {
        if (*it != " " && *it != "\n")
        {
            newText.append(*it);
        }
    }
    qDebug() << text;
    qDebug() << newText;

    if (ui->radioButton128bit->isChecked())
        keySize = aes.BIT_128;
    if (ui->radioButton192bit->isChecked())
        keySize = aes.BIT_192;
    if (ui->radioButton256bit->isChecked())
        keySize = aes.BIT_256;

    setKey(newText, keySize);
}
