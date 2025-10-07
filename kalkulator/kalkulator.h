#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_kalkulator.h"


/*Colour pallete:
Background: 1C1C1C
functional buttons: FF9500
numerical buttons: 505050
Clear, Percent and change sign buttons: D4D4D2
*/


class kalkulator : public QMainWindow
{
    Q_OBJECT

public:
    kalkulator(QWidget *parent = nullptr);
    ~kalkulator();

private:
    Ui::kalkulatorClass ui;

    //Functions will go here
};

