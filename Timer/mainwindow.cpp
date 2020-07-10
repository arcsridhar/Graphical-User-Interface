#include "mainwindow.h"

#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    myButton = new QPushButton("Start Timer");
    myLabel = new QLabel("100");

    QVBoxLayout *myLayout = new QVBoxLayout;
    myLayout->addWidget(myButton);
    myLayout->addWidget(myLabel);

    setLayout(myLayout);

    myTimer = new QTimer(this);
    myTimer->setInterval(10);
    timerCount = 0;

    connect(myButton, SIGNAL(clicked()), this, SLOT(changeText()));
    connect(myTimer, SIGNAL(timeout()), this, SLOT(timerTimeout()));

}

MainWindow::~MainWindow()
{

}

void MainWindow::changeText()
{
    myButton->setEnabled(false);
    timerCount = 100;
    if(!myTimer->isActive())
        myTimer->start();

}
void MainWindow::timerTimeout()
{
    myLabel->setText(QString::number(timerCount));
    --timerCount;
    if (timerCount <= 0)
    {
        myTimer->stop();
        myButton->setEnabled(true);
        myLabel->setText(QString::number(100));
    }

}
