#ifndef DRAWER_H
#define DRAWER_H

#include <QPaintEvent>
#include <QWidget>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
//#include "tempo.h"

class drawer : public QWidget
{
    Q_OBJECT

public:
    explicit drawer(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    int getScore();
    int getTempo();

    int score = getScore();
    int tempo = getTempo();

signals:

};

#endif // DRAWER_H
