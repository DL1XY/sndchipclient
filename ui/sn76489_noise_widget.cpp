#include "sn76489_noise_widget.h"
#include <QButtonGroup>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include "qwt_knob.h"

SN76489NoiseWidget::SN76489NoiseWidget(QWidget *parent) : QWidget(parent)
{
    QFont fontChannel( "Arial", 16, QFont::Bold);
    QFont fontDesc( "Arial", 6, QFont::Bold);


    QwtKnob *knobAttenuation = new QwtKnob(this);
    knobAttenuation->setTotalSteps(4);
    knobAttenuation->setSingleSteps(1);
    knobAttenuation->setScaleStepSize(4);
    knobAttenuation->setScale(0,3);
    knobAttenuation->setKnobWidth(80);
    knobAttenuation->setMarkerSize(QwtKnob::Tick);
    knobAttenuation->setKnobStyle(QwtKnob::Sunken);
    knobAttenuation->show();

    QButtonGroup *btnGroupNoise = new QButtonGroup;
    QPushButton *btnNoise00 = new QPushButton ("N/512");
    QPushButton *btnNoise01 = new QPushButton ("N/1024");
    QPushButton *btnNoise10 = new QPushButton ("N/2048");
    QPushButton *btnNoise11 = new QPushButton ("TONE 3 OUT");
    btnNoise00->setCheckable(true);
    btnNoise01->setCheckable(true);
    btnNoise10->setCheckable(true);
    btnNoise11->setCheckable(true);
    btnNoise00->setMinimumWidth(100);
    btnNoise01->setMinimumWidth(100);
    btnNoise10->setMinimumWidth(100);
    btnNoise11->setMinimumWidth(100);
    btnGroupNoise->addButton(btnNoise00);
    btnGroupNoise->addButton(btnNoise01);
    btnGroupNoise->addButton(btnNoise10);
    btnGroupNoise->addButton(btnNoise11);

    QButtonGroup *btnGroupNoiseType = new QButtonGroup;
    QPushButton *btnNoiseTypePeriodic = new QPushButton ("PERIODIC");
    QPushButton *btnNoiseTypeWhite = new QPushButton ("WHITE NOISE");
    btnNoiseTypePeriodic->setCheckable(true);
    btnNoiseTypeWhite->setCheckable(true);
    btnNoiseTypePeriodic->setMinimumWidth(100);
    btnNoiseTypeWhite->setMinimumWidth(100);
    btnGroupNoiseType->addButton(btnNoiseTypePeriodic);
    btnGroupNoiseType->addButton(btnNoiseTypeWhite);

    QGridLayout *layout = new QGridLayout;
    QLabel *lblNoise = new QLabel("NOISE GENERATOR");
    lblNoise->setFont(fontChannel);
    layout->addWidget(lblNoise, 0, 0, Qt::AlignHCenter);

    QLabel *lblNoiseAttenuation = new QLabel("ATTENUATION");
    layout->addWidget(lblNoiseAttenuation, 1, 0, Qt::AlignHCenter);
    layout->addWidget(knobAttenuation, 2, 0, Qt::AlignHCenter);

    QLabel *lblNoiseFreq = new QLabel("FREQUENCY");
    layout->addWidget(lblNoiseFreq, 3, 0, Qt::AlignHCenter);
    layout->addWidget(btnNoise00, 4, 0, Qt::AlignHCenter);
    layout->addWidget(btnNoise01, 5, 0, Qt::AlignHCenter);
    layout->addWidget(btnNoise10, 6, 0, Qt::AlignHCenter);
    layout->addWidget(btnNoise11, 7, 0, Qt::AlignHCenter);

    QLabel *lblNoiseType = new QLabel("TYPE");
   layout->addWidget(lblNoiseType, 8, 0, Qt::AlignHCenter);
    layout->addWidget(btnNoiseTypePeriodic, 9, 0, Qt::AlignHCenter);
    layout->addWidget(btnNoiseTypeWhite, 10, 0,Qt::AlignCenter);

    this->setLayout(layout);
}
