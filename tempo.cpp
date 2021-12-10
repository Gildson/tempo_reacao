#include "tempo.h"
#include "ui_tempo.h"
#include "drawer.h"
#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <QString>
#include <QTextEdit>

using namespace std;

tempo::tempo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::tempo){
    ui->setupUi(this);

    connect(ui->pushButtoniniciar,
            SIGNAL(clicked(bool)),
            this,
            SLOT(iniciar()));

    connect(ui->pushButtonzerar,
            SIGNAL(clicked(bool)),
            this,
            SLOT(zerar()));
}

tempo::~tempo(){
    delete ui;
}

void tempo::iniciar(){
    //ui->widget->
    start = true;
    int score = drawer().score;
    int tempo = drawer().tempo;
    ui->textBrowserscore->setText(QString::number(score));
    ui->textBrowsertempo->setText(QString::number(tempo));
}

void tempo::zerar(){
    start = false;
    ui->textBrowsertempo->setText(" ");
    ui->textBrowserscore->setText(" ");
}

