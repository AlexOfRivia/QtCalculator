#include "kalkulator.h"


// ! NUMBERS !

void kalkulator::oneButtonPressed()
{
	kalkulator::clearErrors();
    this->calcString += "1";
    ui.resultPanel->setText(this->calcString);
}

void kalkulator::twoButtonPressed()
{
    kalkulator::clearErrors();

    this->calcString += "2";
    ui.resultPanel->setText(this->calcString);
}

void kalkulator::threeButtonPressed()
{
    kalkulator::clearErrors();
    this->calcString += "3";
    ui.resultPanel->setText(this->calcString);
}

void kalkulator::fourButtonPressed()
{
    kalkulator::clearErrors();
    this->calcString += "4";
    ui.resultPanel->setText(this->calcString);
}

void kalkulator::fiveButtonPressed()
{
    kalkulator::clearErrors();
    this->calcString += "5";
    ui.resultPanel->setText(this->calcString);
}

void kalkulator::sixButtonPressed()
{
    kalkulator::clearErrors();
    this->calcString += "6";
    ui.resultPanel->setText(this->calcString);
}

void kalkulator::sevenButtonPressed()
{
    kalkulator::clearErrors();
    this->calcString += "7";
    ui.resultPanel->setText(this->calcString);
}

void kalkulator::eightButtonPressed()
{
    kalkulator::clearErrors();
    this->calcString += "8";
    ui.resultPanel->setText(this->calcString);
}

void kalkulator::nineButtonPressed()
{
    kalkulator::clearErrors();
    this->calcString += "9";
    ui.resultPanel->setText(this->calcString);
}

void kalkulator::zeroButtonPressed()
{
    kalkulator::clearErrors();
    this->calcString += "0";
    ui.resultPanel->setText(this->calcString);
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

void kalkulator::equalsButtonPressed()
{
    char operation;
    double a, b;
    QStringList list;

    list = this->calcString.split(" ");

    a = list[0].toDouble();
    b = list[2].toDouble();

	operation = list[1].at(0).toLatin1();


    if (!calcString.isEmpty())
    {
        switch (operation)
        {
            case '+':
				this->calcString = QString::number(a + b);
                this->isSecondOperation = false;
				ui.resultPanel->setText(this->calcString);
                break;
            case '-':
                this->calcString = QString::number(a - b);
                this->isSecondOperation = false;
                ui.resultPanel->setText(this->calcString);
                break;
            case 'X':
                this->calcString = QString::number(a * b);
                this->isSecondOperation = false;
                ui.resultPanel->setText(this->calcString);
                break;
            case ':':
                this->calcString = QString::number(a / b);
                this->isSecondOperation = false;
                ui.resultPanel->setText(this->calcString);
                break;
            case '^':
                this->calcString = QString::number(pow(a,b));
                this->isSecondOperation = false;
                ui.resultPanel->setText(this->calcString);
                break;
            default:
                return;
        }
    } else {
        return;
    }
}

// ! OTHER OPERATIONS !

void kalkulator::powerButtonPressed()
{
    if (!calcString.isEmpty())
    {
        if (!isSecondOperation)
        {
            this->calcString += " ^ ";
            ui.resultPanel->setText(this->calcString);
            this->isSecondOperation = true;
        }
    }
}

void kalkulator::sqRootButtonPressed()
{
    if (!calcString.isEmpty())
    {
        double a = this->calcString.toDouble();
        a = sqrt(a);
		this->calcString = QString::number(a);
        ui.resultPanel->setText(this->calcString);
    }
}

void kalkulator::clearButtonPressed()
{
    this->calcString.clear();
    this->isSecondOperation = false;
    ui.resultPanel->setText(this->calcString);
}

void kalkulator::decimalButtonPressed()
{
    QRegularExpression re("[+\\-*/^ ]");
    int lastOperatorIndex = calcString.lastIndexOf(re);

    QString currentNumber = calcString.mid(lastOperatorIndex + 1);

    if (currentNumber.contains(".")) 
    {
        return;
    }
    if (currentNumber.isEmpty()) {
        calcString += "0.";
    } else {
        calcString += ".";
    }
    ui.resultPanel->setText(calcString);

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
    if (this->calcString == "0")
    {
        this->calcString.clear();
		ui.resultPanel->setText(this->calcString);
    }

    if (ui.resultPanel->toPlainText() == "inf")
    {
        this->calcString.clear();
        ui.resultPanel->setText(this->calcString);
    }
}

//Constructor
kalkulator::kalkulator(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    ui.resultPanel->setTextColor(QColor::fromRgb(255, 255, 255));
    

    this->isSecondOperation = false;
    setFixedSize(420,630); //Setting fixed size because uhhhhh... who needs a bigger calculator I guess?


	// ! NUMBERS !

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



	// ! BASIC OPERATIONS !

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
        ui.equalsButton, &QPushButton::clicked, this, &kalkulator::equalsButtonPressed
    );



	// ! OTHER OPERATIONS !
    
    QObject::connect(
		ui.clearButton, &QPushButton::clicked, this, &kalkulator::clearButtonPressed
    );

    QObject::connect(
        ui.dotButton, &QPushButton::clicked, this, &kalkulator::decimalButtonPressed
    );

    QObject::connect(
        ui.squareRoot, &QPushButton::clicked, this, &kalkulator::sqRootButtonPressed
    );

    QObject::connect(
        ui.powerButton, &QPushButton::clicked, this, &kalkulator::powerButtonPressed
    );

	// ! OTHER FUNCTIONS !

    QObject::connect(
        ui.backButton, &QPushButton::clicked, this, &kalkulator::backButtonPressed
    );

}

//Destructor
kalkulator::~kalkulator()
{}
