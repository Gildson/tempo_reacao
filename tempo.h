#ifndef TEMPO_H
#define TEMPO_H

#include <QMainWindow>
#include "drawer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class tempo; }
QT_END_NAMESPACE

class tempo : public QMainWindow
{
    Q_OBJECT

public:
    tempo(QWidget *parent = nullptr);
    ~tempo();
    bool start = false;

public slots:
    void iniciar();
    void zerar();

private:
    Ui::tempo *ui;
};
#endif // TEMPO_H
