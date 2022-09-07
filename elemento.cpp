#include "elemento.h"
#include "ui_elemento.h"

elemento::elemento(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::elemento)
{
    ui->setupUi(this);
}

elemento::~elemento()
{
    delete ui;
}
