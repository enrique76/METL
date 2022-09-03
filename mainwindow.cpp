#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QDir>
#include"nuevo.h"
#include"unidades.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    ui->bl->setVisible(false);
    ui->base->setVisible(false);
    ui->base->setCurrentIndex(0);
    ui->area_Trabajo->setVisible(false);
    ui->area_Trabajo->setCurrentIndex(0);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InicioProyecto(){
    this->Proyecto = new QTreeWidgetItem();
    this->Proyecto->setText(0,this->nombre);
    this->Proyecto->setIcon(0,QIcon(":/new/prefix1/iconos/proyecto.png"));

    // agregar al proyecto

        // area de Trabajo

    this->AreaTrabajo = new QTreeWidgetItem();
    this->AreaTrabajo->setText(0,"Area de Trabajo");
    this->AreaTrabajo->setIcon(0,QIcon(":/new/prefix1/iconos/home.png"));

    this->Proyecto->addChild(this->AreaTrabajo);

        //fluidos
    this->Fluidos = new QTreeWidgetItem();
    this->Fluidos->setText(0,"Fluidos");
    this->Fluidos->setIcon(0,QIcon(":/new/prefix1/iconos/fluido.png"));

    this->Proyecto->addChild(this->Fluidos);

       // Unidades
    this->Unidades = new QTreeWidgetItem();
    this->Unidades->setText(0,"Unidades");
    this->Unidades->setIcon(0,QIcon(":/new/prefix1/iconos/si.jpg"));

    this->Proyecto->addChild(this->Unidades);

        // Tablas
    this->Tablas = new QTreeWidgetItem();
    this->Tablas->setText(0,"Tablas");
    this->Tablas->setIcon(0,QIcon(":/new/prefix1/iconos/tabla.png"));

    this->Proyecto->addChild(this->Tablas);

        // historial

    this->Historial = new QTreeWidgetItem();
    this->Historial->setText(0,"Historial");
    this->Historial->setIcon(0,QIcon(":/new/prefix1/iconos/historial.png"));

    this->Proyecto->addChild(this->Historial);

    ui->arbol->addTopLevelItem(this->Proyecto);

    ui->bl->setVisible(true);
    ui->base->setVisible(true);
    ui->base->setCurrentIndex(0);
    ui->area_Trabajo->setVisible(true);
}

void MainWindow::on_actionAbrir_triggered(){
    this->ruta =  QFileDialog::getExistingDirectory(this,"Abrir Proyecto",QDir::homePath());
}

void MainWindow::on_actionNuevo_triggered(){
    nuevo *n = new nuevo();

    n->setTitle("Nuevo Pryecto");
    n->setIcon(":/new/prefix1/iconos/nuevo-mensaje.png");

    n->exec();

    if(n->getV()){

        this->nombre = n->getNombre();
        this->ruta = n->getRuta();

        InicioProyecto();
    }
}

void MainWindow::on_actionSistema_Internacional_triggered(){
    unidades *u = new unidades();

    u->setBase(0);

    u->exec();
}

void MainWindow::on_actionSistema_ingles_triggered(){
    unidades *u = new unidades();

    u->setBase(1);

    u->exec();
}


void MainWindow::on_actionSistema_de_Unidades_triggered(){
    unidades *u = new unidades();

    u->setBase(0);

    u->exec();
}


void MainWindow::on_arbol_itemDoubleClicked(QTreeWidgetItem *item, int column){
    if(item == this->AreaTrabajo){
        ui->area_Trabajo->setCurrentIndex(0);
         ui->area_Trabajo->tabBar()->setTabVisible(0,true);
    }
    else if(item == this->Fluidos){
        ui->area_Trabajo->setCurrentIndex(1);
         ui->area_Trabajo->tabBar()->setTabVisible(1,true);
    }
    else if(item == this->Unidades){
        ui->area_Trabajo->setCurrentIndex(2);
         ui->area_Trabajo->tabBar()->setTabVisible(2,true);
    }
    else if(item == this->Tablas){
        ui->area_Trabajo->setCurrentIndex(3);
         ui->area_Trabajo->tabBar()->setTabVisible(3,true);
    }
    else if(item == this->Historial){
        ui->area_Trabajo->setCurrentIndex(4);
         ui->area_Trabajo->tabBar()->setTabVisible(4,true);
    }
}


void MainWindow::on_area_Trabajo_tabCloseRequested(int index){
    if(index != 0){
        ui->area_Trabajo->tabBar()->setTabVisible(index,false);
    }
}

