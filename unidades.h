#ifndef UNIDADES_H
#define UNIDADES_H

#include <QDialog>

namespace Ui {
class unidades;
}

class unidades : public QDialog
{
    Q_OBJECT

public:
    explicit unidades(QWidget *parent = nullptr);
    ~unidades();
    void setTitle(QString);
    void setBase(int);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::unidades *ui;
};

#endif // UNIDADES_H
