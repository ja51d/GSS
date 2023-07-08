#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QFile>

void MainWindow::readData()
{

    while (socket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(socket->pendingDatagramSize());
        socket->readDatagram(datagram.data(), datagram.size());




        QDataStream stream(datagram);
        stream.setByteOrder(QDataStream::LittleEndian);
        stream >>datas.packetnumber>>datas.cansatstatus>>datas.errorcode>>datas.sendtime>>datas.basinc1>>datas.basinc2
            >>datas.height1>>datas.height2>>datas.irtifafarki>>datas.landingspeed>>datas.temperature>>datas.voltage
            >>datas.gps1latitude>>datas.gps1longitude >> datas.gps1altitude >>datas.pitch>>datas.roll>>datas.yaw>>datas.teamno;



    }

}
void MainWindow::writeData(){



}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    QPixmap pix("/Users/Javid/desktop/itutayf.png");
    ui->label_2->setPixmap(pix);





QCPScatterStyle myScatter;
        myScatter.setShape(QCPScatterStyle::ssDisc);
        myScatter.setPen(QPen(Qt::black));
        myScatter.setSize(2);

        QFont plotFont= font();
        plotFont.setPointSize(6);



ui->bas1->addGraph();

        ui->bas1->graph(0)->setScatterStyle(myScatter);
        ui->bas1->graph(0)->setLineStyle(QCPGraph::lsLine);
        ui->bas1->graph(0)->setPen(QPen(QColor(15,65,74)));
        ui->bas1->setBackground(QColor(150,200,120));

        ui->bas1->xAxis->setLabel("Packet Number");
        ui->bas1->xAxis->setLabelFont(plotFont);
        ui->bas1->xAxis->setTickLabelFont(plotFont);
        ui->bas1->yAxis->setLabel("Basınc");
        ui->bas1->yAxis->setLabelFont(plotFont);
        ui->bas1->yAxis->setTickLabelFont(plotFont);

ui->bas2->addGraph();

        ui->bas2->graph(0)->setScatterStyle(myScatter);
        ui->bas2->graph(0)->setLineStyle(QCPGraph::lsLine);
        ui->bas2->graph(0)->setPen(QPen(QColor(15,65,74)));
        ui->bas2->setBackground(QColor(150,200,120));


        ui->bas2->xAxis->setLabel("Packet Number");
        ui->bas2->yAxis->setLabel("Basınc");
        ui->bas2->xAxis->setLabelFont(plotFont);
        ui->bas2->xAxis->setTickLabelFont(plotFont);
        ui->bas2->yAxis->setLabelFont(plotFont);
        ui->bas2->yAxis->setTickLabelFont(plotFont);

ui->height1->addGraph();

        ui->height1->graph(0)->setScatterStyle(myScatter);
        ui->height1->graph(0)->setLineStyle(QCPGraph::lsLine);
        ui->height1->graph(0)->setPen(QPen(QColor(5,25,88)));
        ui->height1->setBackground(QColor(120,120,200));


        ui->height1->xAxis->setLabel("Packet Number");
        ui->height1->yAxis->setLabel("Height");
        ui->height1->xAxis->setLabelFont(plotFont);
        ui->height1->xAxis->setTickLabelFont(plotFont);
        ui->height1->yAxis->setLabelFont(plotFont);
        ui->height1->yAxis->setTickLabelFont(plotFont);

ui->height2->addGraph();

        ui->height2->graph(0)->setScatterStyle(myScatter);
        ui->height2->graph(0)->setLineStyle(QCPGraph::lsLine);
        ui->height2->graph(0)->setPen(QPen(QColor(5,25,88)));
        ui->height2->setBackground(QColor(120,120,200));


        ui->height2->xAxis->setLabel("Packet Number");
        ui->height2->yAxis->setLabel("Height");
        ui->height2->xAxis->setLabelFont(plotFont);
        ui->height2->xAxis->setTickLabelFont(plotFont);
        ui->height2->yAxis->setLabelFont(plotFont);
        ui->height2->yAxis->setTickLabelFont(plotFont);


ui->temp->addGraph();

        ui->temp->graph(0)->setScatterStyle(myScatter);
        ui->temp->graph(0)->setLineStyle(QCPGraph::lsLine);
        ui->temp->graph(0)->setPen(QPen(QColor(20,75,15)));
        ui->temp->setBackground(QColor(140,180,170));


        ui->temp->xAxis->setLabel("Packet Number");
        ui->temp->yAxis->setLabel("Temperature");
        ui->temp->xAxis->setLabelFont(plotFont);
        ui->temp->xAxis->setTickLabelFont(plotFont);
        ui->temp->yAxis->setLabelFont(plotFont);
        ui->temp->yAxis->setTickLabelFont(plotFont);


ui->lspeed->addGraph();

        ui->lspeed->graph(0)->setScatterStyle(myScatter);
        ui->lspeed->graph(0)->setLineStyle(QCPGraph::lsLine);
        ui->lspeed->graph(0)->setPen(QPen(QColor(30,20,30)));
        ui->lspeed->setBackground(QColor(40,200,130));

        ui->lspeed->xAxis->setLabel("Packet Number");
        ui->lspeed->yAxis->setLabel("Landing Speed");
        ui->lspeed->xAxis->setLabelFont(plotFont);
        ui->lspeed->xAxis->setTickLabelFont(plotFont);
        ui->lspeed->yAxis->setLabelFont(plotFont);
        ui->lspeed->yAxis->setTickLabelFont(plotFont);




    timer = new QTimer(this);
    connect(timer, SIGNAL (timeout()),this,SLOT(timerFunc()));

    socket = new QUdpSocket(this);

    socket->bind(QHostAddress::LocalHost, 5005);


    socket2 = new QUdpSocket(this);

    socket2->bind(QHostAddress::LocalHost, 5005);



}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_toggled(bool checked)
{


        if(checked==true){

            ui->pushButton->setText("Stop");

            timer->start(1000);




        }

        else{


            ui->pushButton->setText("Start");

            timer->stop();

        }
    }

void MainWindow::timerFunc(){








        readData();
QString datab= QString::number(datas.packetnumber)+","+ QString::number(datas.cansatstatus)
+","+ QString::number(datas.errorcode) + ","+ QString::number(datas.sendtime) +","+
 QString::number(datas.basinc1) + ","+ QString::number(datas.basinc2) + ","+ QString::number(datas.height1) +
","+QString::number(datas.height2)+","+QString::number(datas.irtifafarki) +","+  QString::number(datas.landingspeed) +
","+QString::number(datas.temperature) +","+  QString::number(datas.voltage) +","+
QString::number(datas.gps1latitude)  +","+QString::number(datas.gps1longitude)+ ","+QString::number(datas.gps1altitude)+
","+QString::number(datas.pitch) + ","+QString::number(datas.roll)+","+ QString::number(datas.yaw)+ ","+QString::number(datas.teamno);





ui->listWidget->addItem(datab);



ui->listWidget_2->clear();



ui->listWidget_2->addItem(QString::number(datas.irtifafarki));






int  x=datas.packetnumber;
double  y1=datas.basinc1;
double  y2=datas.basinc2;
double  y3=datas.height1;
double  y4=datas.height2;
double  y5=datas.temperature;
double  y6=datas.landingspeed;





ui->bas1->addGraph();
ui->bas1->graph(0)->addData(x, y1);



ui->bas1->rescaleAxes();
ui->bas1->replot();
ui->bas1->update();

ui->bas2->addGraph();
ui->bas2->graph(0)->addData(x, y2);



ui->bas2->rescaleAxes();
ui->bas2->replot();
ui->bas2->update();


ui->height1->addGraph();
ui->height1->graph(0)->addData(x, y3);



ui->height1->rescaleAxes();
ui->height1->replot();
ui->height1->update();


ui->height2->addGraph();
ui->height2->graph(0)->addData(x, y4);



ui->height2->rescaleAxes();
ui->height2->replot();
ui->height2->update();


ui->temp->addGraph();
ui->temp->graph(0)->addData(x, y5);

ui->temp->rescaleAxes();
ui->temp->replot();
ui->temp->update();


ui->lspeed->addGraph();
ui->lspeed->graph(0)->addData(x, y6);



ui->lspeed->rescaleAxes();
ui->lspeed->replot();
ui->lspeed->update();





QFile File("/Users/javid/Desktop/cansat.csv");
File.open(QIODevice::Append |QIODevice::WriteOnly);

QTextStream stream(&File);
stream<< datas.packetnumber<<datas.cansatstatus<<datas.errorcode<<datas.sendtime<<datas.basinc1<<datas.basinc2
       <<datas.height1<<datas.height2<<datas.irtifafarki<<datas.landingspeed<<datas.temperature<<datas.voltage
       <<datas.gps1latitude<<datas.gps1longitude << datas.gps1altitude <<datas.pitch<<datas.roll<<datas.yaw<<datas.teamno;




File.close();


}
