#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "port.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include "qcustomplot.h"
#include <QWidget>
#include <vector>
#include "valuemodel.h"

using namespace std;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
   // ~MainWindow();
private:
   QGridLayout *mainLayout;
   QHBoxLayout *engineLayout;
   QHBoxLayout *tailScrewLayout;
   QHBoxLayout *shaftLayout;
   QHBoxLayout *envLayout;
   QHBoxLayout *powLayout;
   QHBoxLayout *lastLayout;
   QVBoxLayout *vecTLayout;
   QVBoxLayout *pwmLayout;
   QVBoxLayout *vecDLayout;
   QVBoxLayout *volamLayout;
   QVBoxLayout *dataLabels;
   QVBoxLayout *engineValues;
   QVBoxLayout *tailScrewValues;
   QVBoxLayout *screwValues;
   QVBoxLayout *screwLabels;
   QVBoxLayout *temp;
   QVBoxLayout *press;
   QVBoxLayout *density;
   QVBoxLayout *plotLay;
   QVBoxLayout *plotTLay;
   QHBoxLayout *indLayout;
   QVBoxLayout * anTorqLayout;
   QHBoxLayout *thrustLayout;
   QLabel *indWrite;
   QLabel *indCal;
   QLabel *indConP;
   QLabel *indConB;
   QPushButton *but;
   QLabel *plotThrustLabel;
   QLabel *powBlock;
   QLabel *fPlot;
   QLabel *engineRealLabel;
   QLabel *engineAvLabel;
   QLabel *engineEnteredLabel;
   QLabel *screwRealLabel;
   QLabel *screwAvLabel;
   QLabel *screwEnteredLabel;
   QLabel *engineRealVal;
   QLabel *engineAvVal;
   QLabel *engineEnteredVal;
   QLabel *screwRealVal;
   QLabel *screwAvVal;
   QLabel *screwEnteredVal;
   QLabel *shaftLabel;
   QLabel *shaftValue;
   QLabel *engineLabel;
   QLabel *shaftSpeedLabel;
   QLabel *screwSpeedLabel;
   QLabel *envLabel;
   QLabel *tempLabel;
   QLabel *pressLabel;
   QLabel *densLabel;
   QLabel *tempVal;
   QLabel *pressVal;
   QLabel *voltsVal;
   QLabel *ampersVal;
   QLabel *voltsLabel;
   QLabel *ampersLabel;
   QLabel *densVal;
   QLabel *angleLabel;
   QLabel *torqueLable;
   QLabel *angleVal;
   QLabel *torqueVal;
   QLabel *vecTLab;
   QLabel *vecTvalX;
   QLabel *vecTvalY;
   QLabel *pwmLab;
   QLabel *pwmVal1;
   QLabel *pwmVal2;
   QLabel *pwmVal3;
   QLabel *vecDLab;
   QLabel *vecDval;
   QCustomPlot *plotES;
   QCustomPlot *plotShS;
   QCustomPlot *plotScS;
   QCustomPlot *plotP;
   QCustomPlot *plotT;
   QCustomPlot *plotVT;

   double xBeg,xEnd,X,xrange,h=0.1;
   int n;
   QVector <double> t,rEngine,rShaft,rScrew,power,tShaft,pwm;
   void defLayouts();
   void defPlots();
   void defLabels();
   void defPort();
   void getVals(vector<char> vecVal);
   void putPlotVals();
   void fillApp();
   void fillPlots();

private slots:
    void serialRecieve();

private:
    Port port;
    ValueModel modelVal;
};
#endif // MAINWINDOW_H

