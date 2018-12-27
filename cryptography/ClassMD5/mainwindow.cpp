#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("MD5");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_textEditOriginal_textChanged()
{
    ui->textEditMD5->setPlainText(
                md5.solve(
                    ui->textEditOriginal->toPlainText()));
}
