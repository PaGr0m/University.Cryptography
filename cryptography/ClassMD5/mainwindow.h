#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "md5.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_textEditOriginal_textChanged();

private:
    Ui::MainWindow *ui;

    MD5 md5;
};

#endif // MAINWINDOW_H
