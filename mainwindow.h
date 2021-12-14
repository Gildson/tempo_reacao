#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <QString>
#include <QPixmap>
#include <QWidget>
#include <QTime>
#include <QMessageBox>
#include <QDebug>
#include <QLabel>
#include <QMoveEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void reset();

private slots:
    void on_pushButtoniniciar_clicked();

private:
    Ui::MainWindow *ui;
    int bola, x, y;
    int cont = 0, score = 0;
    float tempo_medio = 0;
    void sleep(int t);
    void mostrarBolas();
    struct timeval time_inicio, time_final;
    void keyPressEvent(QKeyEvent *event);
    bool _start;
    void mostrarResultados();
    time_t tempo_real1, tempo_real2;
};
#endif // MAINWINDOW_H
