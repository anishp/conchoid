#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <qmath.h>
#include <QPointF>
#include <QPainter>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

public slots:
    void updateConchoid();

private:
    Ui::Dialog *ui;

protected:
    void paintEvent(QPaintEvent *);
    void drawConchoid();
};

#endif // DIALOG_H
