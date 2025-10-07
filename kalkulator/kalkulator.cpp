#include "kalkulator.h"


//Functions will go here I guess xd


kalkulator::kalkulator(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setFixedSize(420,630); //Setting fixed size because uhhhhh... who needs a bigger calculator I guess?
}

kalkulator::~kalkulator()
{}

