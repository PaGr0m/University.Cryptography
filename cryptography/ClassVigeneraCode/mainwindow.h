#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "vegeneracode.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void prepareData();
    void decodeText();
    void encodeText();

private slots:
    void on_pushButtonEncode_clicked();

    void on_pushButtonDecode_clicked();

private:
    Ui::MainWindow *ui;
    VegeneraCode *vegeraCode;
};

#endif // MAINWINDOW_H
