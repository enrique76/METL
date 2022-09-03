#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <QWidget>

namespace Ui {
class Archivo;
}

class Archivo : public QWidget
{
    Q_OBJECT

public:
    explicit Archivo(QWidget *parent = nullptr);
    ~Archivo();

private:
    Ui::Archivo *ui;
};

#endif // ARCHIVO_H
