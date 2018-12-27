#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEditP->setText("331");
    ui->lineEditQ->setText("607");

    timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()),
            this, SLOT(updateTime()));
    timer->start();
}

MainWindow::~MainWindow()
{
    delete timer;
    delete ui;
}

void MainWindow::updateTime()
{
    QVector<QString> results;
    results = bbs.solve(ui->lineEditP->text().toInt(),
                        ui->lineEditQ->text().toInt());

    ui->lineEditTime->setText(results.at(0));
    ui->lineEditBinary->setText(results.at(1));
    ui->lineEditRandom->setText(results.at(2));

    this->setWindowTitle(QTime::currentTime().toString());
}
