#include "archivo.h"
#include "ui_archivo.h"

Archivo::Archivo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Archivo)
{
    ui->setupUi(this);
}

Archivo::~Archivo()
{
    delete ui;
}
