#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    RSA rsa(ui->lineEdit->text().toInt(),
            ui->lineEdit_2->text().toInt(),
            ui->lineEdit_3->text().toInt());

    ui->textEdit_2->setText(rsa.decrypt(ui->textEdit->toPlainText()));
}
