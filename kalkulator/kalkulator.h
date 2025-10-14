#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_kalkulator.h"
#include <vector>
#include <QRegularExpression>


/*
Colour pallete:
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
    void equalsButtonPressed();

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

