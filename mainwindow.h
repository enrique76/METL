#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void InicioProyecto();

private slots:
    void on_actionAbrir_triggered();

    void on_actionNuevo_triggered();

    void on_actionSistema_Internacional_triggered();

    void on_actionSistema_ingles_triggered();

    void on_actionSistema_de_Unidades_triggered();

    void on_arbol_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_area_Trabajo_tabCloseRequested(int index);

private:
    Ui::MainWindow *ui;
    QString ruta;
    QString nombre;
    QString Sistema_Unidades;
    QTreeWidgetItem *Proyecto;
    QTreeWidgetItem *AreaTrabajo;
    QTreeWidgetItem *Fluidos;
    QTreeWidgetItem *Unidades;
    QTreeWidgetItem *Historial;
    QTreeWidgetItem *Tablas;

};
#endif // MAINWINDOW_H
