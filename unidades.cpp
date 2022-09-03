#include "unidades.h"
#include "ui_unidades.h"

unidades::unidades(QWidget *parent) :QDialog(parent),ui(new Ui::unidades){
    ui->setupUi(this);

}

unidades::~unidades()
{
    delete ui;
}

void unidades::setTitle(QString t){
    setWindowTitle(t);
}

void unidades::setBase(int i){
    ui->base->setCurrentIndex(i);
}

void unidades::on_buttonBox_accepted(){
    close();
}

