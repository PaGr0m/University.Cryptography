#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Vigenera Code");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::prepareData()
{
    vegeraCode = new VegeneraCode(ui->lineEditOriginalText->text().toUpper(),
                                  ui->lineEditKey->text().toUpper());
}

void MainWindow::encodeText()
{
    prepareData();
    vegeraCode->encode();
    ui->lineEditCiphertext->setText(vegeraCode->getEncryptedText());
}

void MainWindow::decodeText()
{
    prepareData();
    vegeraCode->decode();
    ui->lineEditDecipheredText->setText(vegeraCode->getDecryptedText());
}

void MainWindow::on_pushButtonEncode_clicked()
{
    this->encodeText();
}

void MainWindow::on_pushButtonDecode_clicked()
{
    this->decodeText();
}
