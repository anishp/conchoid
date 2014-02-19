#include "dialog.h"
#include "ui_dialog.h"

#define PI 3.1415
#define B_VAL 50

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->ui->horizontalSlider->setRange(0, B_VAL*2);
    connect(this->ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(updateConchoid()));
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
    qreal r,a,b;
    QPointF point, prev;

    QPainter myPainter(this);
    myPainter.fillRect(0,0,640,480, QColor(255, 255, 255));
    myPainter.setClipRect(0, 10, 640, 420);

    for(theta = (0.0); theta < (2* PI); theta += (PI/100))
    {
        a = this->ui->horizontalSlider->value();
        b = B_VAL;

        r = b + a/qCos(theta);
        point = QPointF((r * qCos(theta))+origin.x(), (r * qSin(theta))+origin.y());

        if(theta==0) { prev = QPoint(point.x(), point.y());}

        myPainter.drawLine(prev, point);
        prev = QPoint(point.x(), point.y());
    }

}

void Dialog::updateConchoid()
{
    float a = (float) (this->ui->horizontalSlider->value())/B_VAL;
    QString text = QString("a/b = %1").arg(a);
    this->ui->label->setText(text);
    update();
}
