#include "kalkulator.h"

// ! NUMBERS !

void kalkulator::oneButtonPressed()
{
    this->calcString += "1";
    ui.resultPanel->setText(this->calcString);
    //this->isSecondOperation = false;
}

void kalkulator::twoButtonPressed()
{
    this->calcString += "2";
    ui.resultPanel->setText(this->calcString);
    //this->isSecondOperation = false;
}

void kalkulator::threeButtonPressed()
{
    this->calcString += "3";
    ui.resultPanel->setText(this->calcString);
    //this->isSecondOperation = false;
}

void kalkulator::fourButtonPressed()
{
    this->calcString += "4";
    ui.resultPanel->setText(this->calcString);
    //this->isSecondOperation = false;
}

void kalkulator::fiveButtonPressed()
{
    this->calcString += "5";
    ui.resultPanel->setText(this->calcString);
    //this->isSecondOperation = false;
}

void kalkulator::sixButtonPressed()
{
    this->calcString += "6";
    ui.resultPanel->setText(this->calcString);
    //this->isSecondOperation = false;
}

void kalkulator::sevenButtonPressed()
{
    this->calcString += "7";
    ui.resultPanel->setText(this->calcString);
    //this->isSecondOperation = false;
}

void kalkulator::eightButtonPressed()
{
    this->calcString += "8";
    ui.resultPanel->setText(this->calcString);
    //this->isSecondOperation = false;
}

void kalkulator::nineButtonPressed()
{
    this->calcString += "9";
    ui.resultPanel->setText(this->calcString);
    //this->isSecondOperation = false;
}

void kalkulator::zeroButtonPressed()
{
    this->calcString += "0";
    ui.resultPanel->setText(this->calcString);
    //this->isSecondOperation = false;
}


// ! BASIC OPERATIONS !

void kalkulator::addButtonPressed()
{
    if (!calcString.isEmpty())
    {
        if (!isSecondOperation)
        {
            this->calcString += " + ";
            ui.resultPanel->setText(this->calcString);
            this->isSecondOperation = true;
        }    
    }
}

void kalkulator::substractButtonPressed()
{
    if (!isSecondOperation)
    {
        if (calcString.isEmpty())
        {
            this->calcString += "-";
            ui.resultPanel->setText(this->calcString);
            return;
        } else {
            this->calcString += " - ";
            ui.resultPanel->setText(this->calcString);
            isSecondOperation = true;
        }
    }
}

void kalkulator::divideButtonPressed()
{
    if (!calcString.isEmpty())
    {
        if (!isSecondOperation)
        {
            this->calcString += " : ";
            ui.resultPanel->setText(this->calcString);
            this->isSecondOperation = true;
        }
    }
}

void kalkulator::multiplyButtonPressed()
{
    if (!calcString.isEmpty())
    {
        if (!isSecondOperation)
        {
            this->calcString += " X ";
            ui.resultPanel->setText(this->calcString);
            this->isSecondOperation = true;
        }
    }
}

// ! OTHER OPERATIONS !

void kalkulator::powerButtonPressed()
{
    if (!calcString.isEmpty())
    {
        if (!isSecondOperation)
        {
            this->calcString += "^";
            ui.resultPanel->setText(this->calcString);
            this->isSecondOperation = true;
        }
    }
}

void kalkulator::sqRootButtonPressed()
{
    //JUST THROEING OUT THE SQUARE ROOT OF A NUMBER
}

void kalkulator::clearButtonPressed()
{
    this->calcString.clear();
    this->isSecondOperation = false;
    ui.resultPanel->setText(this->calcString);
}

void kalkulator::decimalButtonPressed()
{

}

// ! OTHER FUNCTIONS !

//Deleting last inputed number
void kalkulator::backButtonPressed()
{
    if (!calcString.isEmpty())
    {

        if (isOperator(calcString.back()) || calcString.back() == " ") 
        {
            while (isOperator(calcString.back()) || calcString.back() == " ") 
            {
                calcString.removeLast();
                this->isSecondOperation = false;
				ui.resultPanel->setText(this->calcString);
            }
        } else {
		    this->calcString.chop(1); 
		    ui.resultPanel->setText(this->calcString);
        }

    }
}

//Checking wether the character is an operator
bool kalkulator::isOperator(QChar ch)
{

    if (ch == '+' || ch == '-' || ch == 'X' || ch == ':' || ch =='^')
    {
        return true;
    }

    return false;
}

//Clearing potential calculation errors (for example dividing by 0)
void kalkulator::clearErrors()
{
    
}

//Constructor
kalkulator::kalkulator(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    

    this->isSecondOperation = false;
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

    QObject::connect(
        ui.addButton, &QPushButton::clicked, this, &kalkulator::addButtonPressed
    );

    QObject::connect(
        ui.substractButton, &QPushButton::clicked, this, &kalkulator::substractButtonPressed
    );

    QObject::connect(
        ui.multiplyButton, &QPushButton::clicked, this, &kalkulator::multiplyButtonPressed
    );

    QObject::connect(
        ui.divideButton, &QPushButton::clicked, this, &kalkulator::divideButtonPressed
    );

    QObject::connect(
        ui.dotButton, &QPushButton::clicked, this, &kalkulator::decimalButtonPressed
    );

    QObject::connect(
		ui.clearButton, &QPushButton::clicked, this, &kalkulator::clearButtonPressed
    );

    QObject::connect(
        ui.backButton, &QPushButton::clicked, this, &kalkulator::backButtonPressed
    );
}

//Destructor
kalkulator::~kalkulator()
{}
