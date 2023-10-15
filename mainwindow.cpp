#include "mainwindow.h"
#include <QWidget>
#include <QByteArray>
#include <string>
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    QWidget *mainWidget = new QWidget();
    mainLayout = new QGridLayout();
    setCentralWidget(mainWidget);
    port.defPort();
    defPlots();
    defLabels();
    defLayouts();
    engineLayout->addWidget(plotES);
    dataLabels->addWidget(engineRealLabel);
    dataLabels->addWidget(engineAvLabel);
    dataLabels->addWidget(engineEnteredLabel);
    engineLayout->addItem(dataLabels);
    engineValues->addWidget(engineRealVal);
    engineValues->addWidget(engineAvVal);
    engineValues->addWidget(engineEnteredVal);
    engineLayout->addItem(engineValues);
    mainLayout->addWidget(engineLabel,0,0);
    shaftLayout->addWidget(plotShS);
    shaftLayout->addWidget(shaftLabel);
    shaftLayout->addWidget(shaftValue);
    mainLayout->addLayout(engineLayout,1,0);
    mainLayout->addWidget(shaftSpeedLabel,2,0);
    mainLayout->addLayout(shaftLayout,3,0);
    screwLabels->addWidget(screwRealLabel);
    screwLabels->addWidget(screwAvLabel);
    screwLabels->addWidget(screwEnteredLabel);
    tailScrewLayout->addWidget(plotScS);
    tailScrewLayout->addLayout(screwLabels);
    screwValues->addWidget(screwRealVal);
    screwValues->addWidget(screwAvVal);
    screwValues->addWidget(screwEnteredVal);
    tailScrewLayout->addLayout(screwValues);
    temp->addWidget(tempLabel);
    temp->addWidget(tempVal);
    press->addWidget(pressLabel);
    press->addWidget(pressVal);
    density->addWidget(densLabel);
    density->addWidget(densVal);
    envLayout->addLayout(temp);
    envLayout->addLayout(press);
    envLayout->addLayout(density);
    indLayout->addWidget(indWrite);
    indLayout->addWidget(indCal);
    indLayout->addWidget(indConP);
    indLayout->addWidget(indConB);
    volamLayout->addWidget(voltsLabel);
    volamLayout->addWidget(voltsVal);
    volamLayout->addWidget(ampersLabel);
    volamLayout->addWidget(ampersVal);
    plotLay->addWidget(fPlot);
    plotLay->addWidget(plotP);
    powLayout->addLayout(plotLay);
    powLayout->addLayout(volamLayout);
    anTorqLayout->addWidget(angleLabel);
    anTorqLayout->addWidget(angleVal);
    anTorqLayout->addWidget(torqueLable);
    anTorqLayout->addWidget(torqueVal);
    thrustLayout->addWidget(plotT);
    thrustLayout->addLayout(anTorqLayout);
    vecTLayout->addWidget(vecTLab);
    vecTLayout->addWidget(vecTvalX);
    vecTLayout->addWidget(vecTvalY);
    pwmLayout->addWidget(pwmLab);
    pwmLayout->addWidget(pwmVal1);
    pwmLayout->addWidget(pwmVal2);
    pwmLayout->addWidget(pwmVal3);
    vecDLayout->addWidget(vecDLab);
    vecDLayout->addWidget(vecDval);
    lastLayout->addWidget(plotVT);
    lastLayout->addLayout(vecTLayout);
    lastLayout->addLayout(pwmLayout);
    lastLayout->addLayout(vecDLayout);
    mainLayout->addWidget(screwSpeedLabel,4,0);
    mainLayout->addLayout(tailScrewLayout,5,0);
    mainLayout->addWidget(envLabel,6,0);
    mainLayout->addLayout(envLayout,7,0);
    mainLayout->addLayout(indLayout,0,1);
    mainLayout->addLayout(powLayout,1,1);
    mainLayout->addWidget(plotThrustLabel,2,1);
    mainLayout->addLayout(thrustLayout,3,1);
    mainLayout->addLayout(lastLayout,5,1);
    mainWidget->setLayout(mainLayout);
    connect(port.getPort(),SIGNAL(readyRead()),this,SLOT(serialRecieve()));
}


void MainWindow::defLabels(){
    engineLabel = new QLabel("График оборотов двигателя");
    engineRealLabel= new QLabel("Реал.");
    engineAvLabel= new QLabel("Сред.");
    engineEnteredLabel= new QLabel("Задан.");
    engineRealVal= new QLabel("2201");
    engineAvVal= new QLabel("2152");
    engineEnteredVal= new QLabel("2000");
    shaftLabel = new QLabel("Реал.");
    shaftValue = new QLabel("2000");
    shaftSpeedLabel = new QLabel("График оборотов несущего вала");
    screwRealLabel= new QLabel("Реал.");
    screwAvLabel= new QLabel("Сред.");
    screwEnteredLabel= new QLabel("Задан.");
    screwRealVal= new QLabel("2000");
    screwAvVal= new QLabel("2122");
    screwEnteredVal= new QLabel("2331");
    screwSpeedLabel = new QLabel("График оборотов хвостового винта");
    tempLabel = new QLabel("Температура");
    pressLabel = new QLabel("Давление");
    densLabel = new QLabel("Плотность");
    tempLabel->setFixedHeight(20);
    pressLabel->setFixedHeight(20);
    densLabel->setFixedHeight(20);
    tempVal = new QLabel("30");
    pressVal = new QLabel("50");
    densVal = new QLabel("100");
    tempVal->setFixedHeight(20);
    pressVal->setFixedHeight(20);
    densVal->setFixedHeight(20);
    envLabel = new QLabel("Блок условий окр. среды");
    indCal = new QLabel("Калибровка");
    indCal->setStyleSheet( "border-radius: 10px; background-color: red;" );
    indCal->setAlignment(Qt::AlignCenter);
    indWrite = new QLabel("Запись");
    indWrite->setStyleSheet( "border-radius: 10px; background-color: red;" );
    indWrite->setAlignment(Qt::AlignCenter);
    indConP = new QLabel("Связь пульт");
    indConP->setStyleSheet( "border-radius: 10px; background-color: red;" );
    indConP->setAlignment(Qt::AlignCenter);
    indConB = new QLabel("Связь БУ");
    indConB->setStyleSheet( "border-radius: 10px; background-color: red;" );
    indConB->setAlignment(Qt::AlignCenter);
    fPlot = new QLabel("График ...");
    powBlock = new QLabel("Блок мощности");
    ampersLabel= new QLabel("Амеры");
    voltsLabel = new QLabel("Вольты");
    ampersVal = new QLabel("20 А");
    voltsVal = new QLabel("45 В");
    angleVal = new QLabel("4.5");
    angleLabel = new QLabel("Угол атаки");
    torqueLable = new QLabel("Крутящий момент");
    torqueVal = new QLabel("6 Н.м");
    plotThrustLabel = new QLabel("График тяга НВ");
    vecTLab = new QLabel("Вектор тяги");
    vecTvalX = new QLabel("1");
    vecTvalY = new QLabel("2");
    pwmLab = new QLabel("PWM серво");
    pwmVal1 = new QLabel("1");
    pwmVal2 = new QLabel("2");
    pwmVal3 = new QLabel("3");
    vecDLab = new QLabel("Вектор тарелки");
    vecDval = new QLabel("1");
    vecDval->setAlignment(Qt::AlignTop);
    plotThrustLabel->setAlignment(Qt::AlignCenter);
    fPlot->setAlignment(Qt::AlignCenter);
    powBlock->setAlignment(Qt::AlignCenter);
    fPlot->setFixedHeight(20);
    powBlock->setFixedHeight(20);
    envLabel->setAlignment(Qt::AlignCenter);
    envLabel->setFixedHeight(20);
    screwSpeedLabel->setAlignment(Qt::AlignCenter);
    screwSpeedLabel->setFixedHeight(20);
    shaftSpeedLabel->setAlignment(Qt::AlignCenter);
    shaftSpeedLabel->setFixedHeight(20);
    engineRealLabel->setFixedWidth(40);
    engineAvLabel->setFixedWidth(40);
    engineEnteredLabel->setFixedWidth(40);
    engineLabel->setAlignment(Qt::AlignCenter);
    engineLabel->setFixedHeight(20);
    shaftLabel->setFixedWidth(40);
    screwRealLabel->setFixedWidth(40);
    screwAvLabel->setFixedWidth(40);
    screwEnteredLabel->setFixedWidth(40);
    modelVal.pushLabel(new QLabel("1"));
    modelVal.pushLabel(engineRealVal);
    modelVal.pushLabel(engineAvVal);
    modelVal.pushLabel(engineEnteredVal);
    modelVal.pushLabel(new QLabel("1"));
    modelVal.pushLabel(screwRealVal);
    modelVal.pushLabel(screwAvVal);
    modelVal.pushLabel(screwEnteredVal);
    modelVal.pushLabel(new QLabel("1"));
    modelVal.pushLabel(pwmVal1);
    modelVal.pushLabel(pwmVal2);
    modelVal.pushLabel(pwmVal3);
    modelVal.pushLabel(angleVal);
    modelVal.pushLabel(pressVal);
    modelVal.pushLabel(tempVal);
    modelVal.pushLabel(densVal);
    modelVal.pushLabel(voltsVal);
    modelVal.pushLabel(ampersVal);
    modelVal.pushLabel(new QLabel("1"));
    modelVal.pushLabel(torqueVal);
    modelVal.pushLabel(new QLabel("1"));
    modelVal.pushLabel(vecTvalX);
    modelVal.pushLabel(vecTvalY);
    modelVal.pushLabel(new QLabel("1"));
    modelVal.pushLabel(new QLabel("1"));
    modelVal.pushLabel(new QLabel("1"));
    modelVal.pushLabelValue("0");
    modelVal.pushLabelValue("0");
    modelVal.pushLabelValue("0");
    modelVal.pushLabelValue("0");
    modelVal.pushLabelValue("0");
    modelVal.pushLabelValue("0");
    modelVal.pushLabelValue("0");
    modelVal.pushLabelValue("0");
    modelVal.pushLabelValue("0");
    modelVal.pushLabelValue("0");
    modelVal.pushLabelValue("0");
    modelVal.pushLabelValue("0");
    modelVal.pushLabelValue("0");
    modelVal.pushLabelValue("0");
    modelVal.pushLabelValue("0");
    modelVal.pushLabelValue("0");
    modelVal.pushLabelValue("0");
    modelVal.pushLabelValue("0");
    modelVal.pushLabelValue("0");
    modelVal.pushLabelValue("0");
    modelVal.pushLabelValue("0");
    modelVal.pushLabelValue("0");
    modelVal.pushLabelValue("0");
    modelVal.pushLabelValue("0");
    modelVal.pushLabelValue("0");

}

void MainWindow::defLayouts(){
    engineLayout = new QHBoxLayout();
    dataLabels = new QVBoxLayout();
    engineValues = new QVBoxLayout();
    screwValues = new QVBoxLayout();
    shaftLayout = new QHBoxLayout();
    tailScrewLayout = new QHBoxLayout();
    screwLabels = new QVBoxLayout();
    envLayout = new QHBoxLayout();
    temp = new QVBoxLayout();
    press = new QVBoxLayout();
    density = new QVBoxLayout();
    indLayout = new QHBoxLayout();
    volamLayout = new QVBoxLayout();
    powLayout = new QHBoxLayout();
    plotLay = new QVBoxLayout();
    plotTLay = new QVBoxLayout();
    thrustLayout = new QHBoxLayout();
    anTorqLayout = new QVBoxLayout();
    lastLayout = new QHBoxLayout();
    vecTLayout = new QVBoxLayout();
    pwmLayout = new QVBoxLayout();
    vecDLayout = new QVBoxLayout();
    powLayout->setContentsMargins(0,0,20,0);
    engineLayout->setContentsMargins(0,0,20,0);
    tailScrewLayout->setContentsMargins(0,0,20,0);
    shaftLayout->setContentsMargins(0,0,20,0);
    lastLayout->setContentsMargins(0,0,20,0);
    mainLayout->setContentsMargins(0,0,20,0);
}


void MainWindow::serialRecieve(){
    QByteArray ba;
    ba = this->port.getPort()->readAll();
    for(int i=0;i< ba.size();i++){
        if(char(ba[i] == '\n')){
            modelVal.getValsFromPort();
            fillApp();
            putPlotVals();
            fillPlots();
            modelVal.clearVecValues();
        }
        modelVal.pushValue((char)ba[i]);
    }
}



void MainWindow::fillApp(){
    for(int i = 0; i<modelVal.getSizeVal();i++){
        modelVal.setLabelValue(i);
    }
}
void MainWindow::putPlotVals(){
    string s;
    if(modelVal.getLabelValue(3)!="0")
    {
        s = modelVal.getLabelValue(3).trimmed().toStdString();
        s.resize(s.find(' '));
        rEngine.push_back(stod(s));
    }

    if(modelVal.getLabelValue(7)!="0")
    {
        s = modelVal.getLabelValue(7).trimmed().toStdString();
        s.resize(s.find(' '));
        rScrew.push_back(stod(s));
    }
    if(modelVal.getLabelValue(18)!="0")
    {
        s = modelVal.getLabelValue(18).trimmed().toStdString();
        s.resize(s.find(' '));
        power.push_back(stod(s));
    }
    if(modelVal.getLabelValue(19)!="0")
    {
        s = modelVal.getLabelValue(19).trimmed().toStdString();
        s.resize(s.find(' '));
        tShaft.push_back(stod(s));
    }

}
void MainWindow::fillPlots(){
    xrange +=h;
    plotES->xAxis->setRange(0,xrange);
    plotScS->xAxis->setRange(0,xrange);
    plotP->xAxis->setRange(0,xrange);
    plotT->xAxis->setRange(0,xrange);
    t.push_back(xrange+h);
    plotES->graph(0)->addData(t,rEngine);
    plotScS->graph(0)->addData(t,rScrew);
    plotP->graph(0)->addData(t,power);
    plotT->graph(0)->addData(t,tShaft);
    plotES->replot();
    plotScS->replot();
    plotP->replot();
    plotT->replot();
}
void MainWindow::defPlots(){
    plotES = new QCustomPlot();
    plotES->resize(400,200);
    plotShS->xAxis->setRange(0,xrange);
    plotES->yAxis->setRange(0,2);
    plotES->addGraph();
    plotES->graph(0)->addData(t,rEngine);
    plotES->replot();
    plotShS = new QCustomPlot();
    plotShS->resize(400,200);
    plotShS->xAxis->setRange(0,xrange);
    plotShS->yAxis->setRange(0,1);
    plotShS->addGraph();
    plotShS->graph(0)->addData(t,rShaft);
    plotShS->replot();
    plotScS = new QCustomPlot();
    plotScS->resize(400,200);
    plotScS->xAxis->setRange(0,xrange);
    plotScS->yAxis->setRange(0,1);
    plotScS->addGraph();
    plotScS->graph(0)->addData(t,rScrew);
    plotScS->replot();
    plotP = new QCustomPlot();
    plotP->resize(400,200);
    plotP->xAxis->setRange(0,xrange);
    plotP->yAxis->setRange(0,1);
    plotP->addGraph();
    plotP->graph(0)->addData(t,power);
    plotP->replot();
    plotT = new QCustomPlot();
    plotT->resize(400,200);
    plotT->xAxis->setRange(0,xrange);
    plotT->yAxis->setRange(0,1);
    for(X=xBeg;X<=xEnd;X+=h){
        tShaft.push_back(X);
    }
    plotT->addGraph();
    plotT->graph(0)->addData(t,tShaft);
    plotT->replot();
    plotVT = new QCustomPlot();
    plotVT->resize(400,200);
    plotVT->xAxis->setRange(0,xrange);
    plotVT->yAxis->setRange(0,1);
    plotVT->addGraph();
    plotVT->replot();
}
