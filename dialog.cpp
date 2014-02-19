#include "dialog.h"
#include "ui_dialog.h"

#define PI 3.1415

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *)
{
    drawConchoid();
}

void Dialog::drawConchoid()
{

    qreal theta = 0;
    QPointF origin = QPointF(320, 240);

    QPainter myPainter(this);

    qreal r = 100;
    qreal a,b;

    QPointF point, prev;

    for(theta = (0); theta < (2* PI); theta += (PI/50))
    {
        // parabola
        r = (-1) * 20 / (1 + qCos(theta));
        //a = 50; b = 50;
        //r = b + a/qCos(theta);
        point = QPointF((r * qCos(theta))+origin.x(), (r * qSin(theta))+origin.y());

        if(theta==0)
        {
            prev = QPoint(point.x(), point.y());
        }

        myPainter.drawLine(prev, point);
        prev = QPoint(point.x(), point.y());
    }

}
