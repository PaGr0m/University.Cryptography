#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegExp>
#include "aes.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setKey(QString text,
                int keySize);

private slots:
    void on_pushButtonKey_clicked();

private:
    Ui::MainWindow *ui;

    AES aes;
};

#endif // MAINWINDOW_H
