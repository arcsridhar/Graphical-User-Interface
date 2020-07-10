#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtGui>

#include <QMainWindow>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QPushButton *myButton;
    QLabel *myLabel;
    QTimer *myTimer;
    int timerCount;

private slots:
    void changeText();
    void timerTimeout();

    };

#endif // MAINWINDOW_H

