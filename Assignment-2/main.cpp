#include<QApplication>
#include<QSlider>
#include<QSpinBox>
#include<QVBoxLayout>
#include<QLCDNumber>
#include<QHBoxLayout>
#include<QLabel>
#include<QDial>
#include<QWidget>
#include<QPalette>
#include<QRadioButton>
#include<QDockWidget>
#include<QBoxLayout>
#include<QPushButton>
#include "globj.h"

int main(int argc, char *argv[])
{
    QApplication *app = new QApplication(argc, argv);


    QWidget *window = new QWidget;
    window->setWindowTitle("Web Radio and Shapes");

    GLobj *globj = new GLobj;

    QDockWidget *dock = new QDockWidget();
    dock->setWidget(globj);

    QSlider *sliderBass = new QSlider(Qt::Horizontal);
    QSlider *sliderTreble = new QSlider(Qt::Horizontal);

    QLCDNumber *lcdVolume = new QLCDNumber;
    QLCDNumber *lcdStation = new QLCDNumber;

    QSpinBox *spinBoxTreble = new QSpinBox;
    QSpinBox *spinBoxBass = new QSpinBox;

    QRadioButton *buttonAM = new QRadioButton;
    QRadioButton *buttonFM = new QRadioButton;

    QLabel *labelModulation = new QLabel;
    labelModulation->setText("MODULATION:");

    QLabel *labelAM = new QLabel;
    labelAM->setText("AM");
    buttonFM->setCheckable(true);

    QLabel *labelFM = new QLabel;
    labelFM->setText("FM");
    buttonAM->setCheckable(true);

    QLabel *labelStation = new QLabel;
    labelStation->setText("STATION:");

    QLabel *labelFrequency = new QLabel;
    labelFrequency->setText("Frequency");

    QDial *dial = new QDial;
    dial->setRange(0,100);

    QLabel *labelSound = new QLabel;
    labelSound->setText("SOUND:");

    QLabel *labelVolume = new QLabel;
    labelVolume->setText("VOLUME:");

    QDial *dialVolume = new QDial;
    dialVolume->setRange(0,100);

    QLabel *labelBass = new QLabel;
    labelBass->setText("Bass");

    QLabel *labelTreble = new QLabel;
    labelTreble->setText("Treble");

    sliderBass->setRange(0,100);
    sliderTreble->setRange(0,100);
    spinBoxTreble->setRange(0,100);
    spinBoxBass->setRange(0,100);

    QPushButton *close=new QPushButton();
    close->setText("Close");

    //Connecting LCDVolume (Display) with the dial
    QObject::connect(lcdVolume,SIGNAL(display(int)), dialVolume,SLOT(setValue(int)));
    QObject::connect(dialVolume,SIGNAL(valueChanged(int)), lcdVolume,SLOT(display(int)));
    QObject::connect(spinBoxBass,SIGNAL(valueChanged(int)), sliderBass,SLOT(setValue(int)));
    QObject::connect(sliderBass,SIGNAL(valueChanged(int)), spinBoxBass,SLOT(setValue(int)));
    QObject::connect(spinBoxTreble,SIGNAL(setValue(int)), sliderTreble,SLOT(setValue(int)));
    QObject::connect(sliderTreble,SIGNAL(valueChanged(int)), spinBoxTreble,SLOT(setValue(int)));
    QObject::connect(lcdStation,SIGNAL(display(int)), dial,SLOT(setValue(int)));
    QObject::connect(dial,SIGNAL(valueChanged(int)), lcdStation,SLOT(display(int)));
    QObject::connect(close,SIGNAL(clicked()),window ,SLOT(close()));


    //Arranging AM,FM

    QGridLayout *appLayout = new QGridLayout;
    appLayout->addWidget(labelModulation,0,0);
    appLayout->addWidget(labelFM,1,0);
    appLayout->addWidget(buttonFM,1,1);

    appLayout->addWidget(labelAM,2,0);
    appLayout->addWidget(buttonAM,2,1);


    appLayout->addWidget(labelStation,3,0);
    appLayout->addWidget(labelFrequency,4,0);
    appLayout->addWidget(lcdStation,3,1);


    //Arranging Dial for Tuner
    appLayout->addWidget(dial,4,2);

    //Arranging Volume
    appLayout->addWidget(labelVolume,0,6);
    appLayout->addWidget(lcdVolume,0,7);
    appLayout->addWidget(dialVolume,1,7);
    //leftLayout->addWidget(dock,0,9);

    //QGridLayout *soundLayout = new QGridLayout;

    appLayout->addWidget(labelSound,5,0);


    //Arranging Bass
    appLayout->addWidget(labelBass,7,0);
    appLayout->addWidget(sliderBass,7,1);
    appLayout->addWidget(spinBoxBass,7,2);

    //Arranging Treble
    appLayout->addWidget(labelTreble,8,0);
    appLayout->addWidget(sliderTreble,8,1);
    appLayout->addWidget(spinBoxTreble,8,2);

    QGridLayout *layout = new QGridLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout();
    // Arranging the gridlayout of shapes to the Radio layout
    mainLayout->addWidget(globj);
    mainLayout->addLayout(layout);
    mainLayout->addLayout(appLayout);
    mainLayout->addWidget(close);

    window->resize(600,800);
    window->setLayout(mainLayout);
    window->show();
    return app->exec();


}
