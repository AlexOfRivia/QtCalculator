#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_kalkulator.h"


/*Colour pallete:
Background: 1C1C1C
functional buttons: FF9500
numerical buttons: 505050
Clear, Percent and change sign buttons: D4D4D2
*/

/*The numbers should at first be used as strings and then converted into float numbers I think

you can press coma only once per number
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

