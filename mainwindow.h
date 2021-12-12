#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <time.h>
#include <QPixmap>
#include <QString>
#include <QMessageBox>
#include <QLayout>
#include <iostream>
#include <QThread>
#include <QKeyEvent>
#include <unistd.h>
#include <QElapsedTimer>
#include <QTime>
#include <sys/time.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
