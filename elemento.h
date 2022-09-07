#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <QDialog>

namespace Ui {
class elemento;
}

class elemento : public QDialog
{
    Q_OBJECT

public:
    explicit elemento(QWidget *parent = nullptr);
    ~elemento();

private:
    Ui::elemento *ui;
};

#endif // ELEMENTO_H
