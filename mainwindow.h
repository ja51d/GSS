#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QWidget>
#include <QUdpSocket>
#include <QUrl>

struct CanSatdata {

    int packetnumber;
    double cansatstatus;
    double errorcode;
    double sendtime;
    double basinc1;
    double basinc2;
    double height1;
    double height2;
    double irtifafarki;
    double landingspeed;
    double temperature;
    double voltage;
    double gps1latitude;
    double gps1longitude;
    double gps1altitude;
    double pitch;
    double roll;
    double yaw;
    int teamno;

};


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

 void timerFunc();
    void readData();
    void writeData();
    void on_pushButton_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QUdpSocket *socket;
    QUdpSocket *socket2;
    CanSatdata datas;
    };
#endif // MAINWINDOW_H
