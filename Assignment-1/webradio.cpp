#include<QApplication>
#include<QSlider>
#include<QSpinBox>
#include<QVBoxLayout>
#include<QLCDNumber>
#include<QHBoxLayout>
#include<QLabel>
#include<QDial>
#include<QPalette>
#include<QRadioButton>
#include<QPushButton>
int main(int argc, char *argv[])
{
        QApplication *app = new QApplication(argc, argv);
        QPalette pal = app->palette();
        pal.setColor(QPalette::Window,Qt::gray);
        app->setPalette(pal);

        QWidget *window = new QWidget;
        window->setWindowTitle("Web Radio");

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
        close->setText("Exit");

        //Connecting LCDVolume (Display) with dial
        QObject::connect(lcdVolume,SIGNAL(display(int)), dialVolume,SLOT(setValue(int)));
        QObject::connect(dialVolume,SIGNAL(valueChanged(int)), lcdVolume,SLOT(display(int)));
        QObject::connect(spinBoxBass,SIGNAL(valueChanged(int)), sliderBass,SLOT(setValue(int)));
        QObject::connect(sliderBass,SIGNAL(valueChanged(int)), spinBoxBass,SLOT(setValue(int)));
        QObject::connect(spinBoxTreble,SIGNAL(setValue(int)), sliderTreble,SLOT(setValue(int)));
        QObject::connect(sliderTreble,SIGNAL(valueChanged(int)), spinBoxTreble,SLOT(setValue(int)));
        QObject::connect(lcdStation,SIGNAL(display(int)), dial,SLOT(setValue(int)));
        QObject::connect(dial,SIGNAL(valueChanged(int)), lcdStation,SLOT(display(int)));
        QObject::connect(close,SIGNAL(clicked()),window ,SLOT(close()));

        QHBoxLayout *topLeftLayout = new QHBoxLayout;

        topLeftLayout->addWidget(labelModulation);
        //Arranging AM,FM

        QGridLayout *modulationLayout = new QGridLayout;
        modulationLayout->addWidget(labelFM,1,0);
        modulationLayout->addWidget(buttonFM,1,1);

        modulationLayout->addWidget(labelAM,2,0);
        modulationLayout->addWidget(buttonAM,2,1);

        modulationLayout->setMargin(5);

        QGridLayout *leftLayout = new QGridLayout;

        leftLayout->addLayout(topLeftLayout,0,0);
        leftLayout->addLayout(modulationLayout,1,0);

        leftLayout->addWidget(labelStation,3,0);
        leftLayout->addWidget(labelFrequency,4,0);
        leftLayout->addWidget(lcdStation,3,1);


        //Arranging Dial for Tuner
        leftLayout->addWidget(dial,4,2);

        //Arranging Volume
        leftLayout->addWidget(labelVolume,0,6);
        leftLayout->addWidget(lcdVolume,0,7);
        leftLayout->addWidget(dialVolume,1,7);

        QGridLayout *soundLayout = new QGridLayout;

        soundLayout->addWidget(labelSound,5,0);


        //Arranging Bass
        soundLayout->addWidget(labelBass,7,0);
        soundLayout->addWidget(sliderBass,7,1);
        soundLayout->addWidget(spinBoxBass,7,2);

        //Arranging Treble
        soundLayout->addWidget(labelTreble,8,0);
        soundLayout->addWidget(sliderTreble,8,1);
        soundLayout->addWidget(spinBoxTreble,8,2);

        QVBoxLayout *mainLayout = new QVBoxLayout();
        mainLayout->addLayout(leftLayout);
        mainLayout->addLayout(soundLayout);
        mainLayout->addWidget(close);

        window->setLayout(mainLayout);
        window-> show();
        return app->exec();
}
