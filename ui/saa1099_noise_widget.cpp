#include "saa1099_noise_widget.h"
#include <QButtonGroup>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

SAA1099NoiseWidget::SAA1099NoiseWidget(QWidget *parent) : QWidget(parent)
{
    QFont fontChannel( "Arial", 8, QFont::Bold);
    QFont fontDesc( "Arial", 6, QFont::Bold);


    QButtonGroup *btnGroupNoise = new QButtonGroup;
    QPushButton *btnNoise00 = new QPushButton ("31.3 KHZ");
    QPushButton *btnNoise01 = new QPushButton ("15.6 KHZ");
    QPushButton *btnNoise10 = new QPushButton ("7.6 KHZ");
    QPushButton *btnNoise11 = new QPushButton ("61 HZ TO 15.6 KHZ");
    btnNoise00->setCheckable(true);
    btnNoise01->setCheckable(true);
    btnNoise10->setCheckable(true);
    btnNoise11->setCheckable(true);
    btnNoise00->setFont(fontDesc);
    btnNoise01->setFont(fontDesc);
    btnNoise10->setFont(fontDesc);
    btnNoise11->setFont(fontDesc);
    btnGroupNoise->addButton(btnNoise00);
    btnGroupNoise->addButton(btnNoise01);
    btnGroupNoise->addButton(btnNoise10);
    btnGroupNoise->addButton(btnNoise11);


    QGridLayout *layout = new QGridLayout;
    QLabel *lblNoise = new QLabel("NOISE GENERATOR");
    lblNoise->setFont(fontChannel);
    layout->addWidget(lblNoise, 0, 0, 1, 2, Qt::AlignHCenter);
    layout->addWidget(btnNoise00,1,0);
    layout->addWidget(btnNoise01,1,1);
    layout->addWidget(btnNoise10,2,0);
    layout->addWidget(btnNoise11,2,1);
    this->setLayout(layout);

}
