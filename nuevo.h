#ifndef NUEVO_H
#define NUEVO_H

#include <QDialog>

namespace Ui {
class nuevo;
}

class nuevo : public QDialog
{
    Q_OBJECT

public:
    explicit nuevo(QDialog *parent = nullptr);
    ~nuevo();
    QString getNombre();
    QString getRuta();
    bool getV();
    void setIcon(QString);
    void setTitle(QString);

private slots:
    void on_buscar_ruta_clicked();

    void on_buttonBox_accepted();

private:
    Ui::nuevo *ui;
    bool V = false;
};

#endif // NUEVO_H
