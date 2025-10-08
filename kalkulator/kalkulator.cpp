#include "kalkulator.h"

void kalkulator::oneButtonPressed()
{
    this->calcString += "1";
    ui.resultPanel->setText(this->calcString);
    this->isSecondOperation = false;
}

void kalkulator::twoButtonPressed()
{
    this->calcString += "2";
    ui.resultPanel->setText(this->calcString);
    this->isSecondOperation = false;
}

void kalkulator::threeButtonPressed()
{
    this->calcString += "3";
    ui.resultPanel->setText(this->calcString);
    this->isSecondOperation = false;
}

void kalkulator::fourButtonPressed()
{
    this->calcString += "4";
    ui.resultPanel->setText(this->calcString);
    this->isSecondOperation = false;
}

void kalkulator::fiveButtonPressed()
{
    this->calcString += "5";
    ui.resultPanel->setText(this->calcString);
    this->isSecondOperation = false;
}

void kalkulator::sixButtonPressed()
{
    this->calcString += "6";
    ui.resultPanel->setText(this->calcString);
    this->isSecondOperation = false;
}

void kalkulator::sevenButtonPressed()
{
    this->calcString += "7";
    ui.resultPanel->setText(this->calcString);
    this->isSecondOperation = false;
}

void kalkulator::eightButtonPressed()
{
    this->calcString += "8";
    ui.resultPanel->setText(this->calcString);
    this->isSecondOperation = false;
}

void kalkulator::nineButtonPressed()
{
    this->calcString += "9";
    ui.resultPanel->setText(this->calcString);
    this->isSecondOperation = false;
}

void kalkulator::zeroButtonPressed()
{
    this->calcString += "0";
    ui.resultPanel->setText(this->calcString);
    this->isSecondOperation = false;
}

void kalkulator::addButtonPressed()
{

}

void kalkulator::substractButtonPressed()
{

}

void kalkulator::divideButtonPressed()
{

}

void kalkulator::multiplyButtonPressed()
{

}

//Clearing potential calculation errors (for example dividing by 0)
void kalkulator::clearErrors()
{

}

void kalkulator::powerButtonPressed()
{

}

void kalkulator::sqRootButtonPressed()
{

}

void kalkulator::clearButtonPressed()
{

}

void kalkulator::decimalButtonPressed()
{

}

//Deleting last inputed number
void kalkulator::backButtonPressed()
{

}

//Constructor
kalkulator::kalkulator(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setFixedSize(420,630); //Setting fixed size because uhhhhh... who needs a bigger calculator I guess?


    QObject::connect(
        ui.oneButton, &QPushButton::clicked, this, &kalkulator::oneButtonPressed
    );

    QObject::connect(
        ui.twoButton, &QPushButton::clicked, this, &kalkulator::twoButtonPressed
    );

    QObject::connect(
        ui.threeButton, &QPushButton::clicked, this, &kalkulator::threeButtonPressed
    );

    QObject::connect(
        ui.fourButton, &QPushButton::clicked, this, &kalkulator::fourButtonPressed
    );

    QObject::connect(
        ui.fiveButton, &QPushButton::clicked, this, &kalkulator::fiveButtonPressed
    ); 
    
    QObject::connect(
        ui.sixButton, &QPushButton::clicked, this, &kalkulator::sixButtonPressed
    ); 
    
    QObject::connect(
        ui.sevenButton, &QPushButton::clicked, this, &kalkulator::sevenButtonPressed
    ); 
    
    QObject::connect(
        ui.eightButton, &QPushButton::clicked, this, &kalkulator::eightButtonPressed
    );
    
    QObject::connect(
        ui.nineButton, &QPushButton::clicked, this, &kalkulator::nineButtonPressed
    );

    QObject::connect(
        ui.zeroButton, &QPushButton::clicked, this, &kalkulator::zeroButtonPressed
    );

}

//Destructor
kalkulator::~kalkulator()
{}
