#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_kalkulator.h"
#include <vector>


/*Colour pallete:
Background: 1C1C1C
functional buttons: FF9500
numerical buttons: 505050
Clear, Percent and change sign buttons: D4D4D2
*/

/*

TODO:
- Add a color upon button press and fix button positions to look sleeker
- Change style of the result panel: change the color to the background & text color to white


The numbers should at first be used as strings and then converted into double numbers I think
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

    
    //Variables
    QString calcString;
    std::vector<char> operators;
    bool isSecondOperation; //For checking if any of the operation button has been pressed

    //Number functions
    void oneButtonPressed();
    void twoButtonPressed();
    void threeButtonPressed();
    void fourButtonPressed();
    void fiveButtonPressed();
    void sixButtonPressed();
    void sevenButtonPressed();
    void eightButtonPressed();
    void nineButtonPressed();
    void zeroButtonPressed();

    //Basic operations 
    void addButtonPressed();
    void substractButtonPressed();
    void divideButtonPressed();
    void multiplyButtonPressed();

    //Other operations
    void powerButtonPressed();
    void sqRootButtonPressed();
    void clearButtonPressed();
    void decimalButtonPressed();
    void backButtonPressed();

    //Other functions I guess
    bool isOperator(QChar ch); //Checking if a character is an operator or not
    void clearErrors();

};

