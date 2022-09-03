#include "nuevo.h"
#include "ui_nuevo.h"
#include<QFileDialog>
#include<QDir>

nuevo::nuevo(QDialog *parent) : QDialog(parent),ui(new Ui::nuevo){
    ui->setupUi(this);

}

nuevo::~nuevo()
{
    delete ui;
}

QString nuevo::getNombre(){
return ui->nombre->text();
}

QString nuevo::getRuta(){
    return ui->ruta->text();
}

bool nuevo::getV(){
    return this->V;
}

void nuevo::setIcon(QString i){
    setWindowIcon(QIcon(i));
}

void nuevo::setTitle(QString t){
    setWindowTitle(t);
}

void nuevo::on_buscar_ruta_clicked(){
    ui->ruta->setText(QFileDialog::getExistingDirectory(this,"Ruta",QDir::homePath()));
}

void nuevo::on_buttonBox_accepted(){
    if(!ui->ruta->text().isEmpty() || !ui->nombre->text().isEmpty()){
        this->V = true;
    }

    close();
}

