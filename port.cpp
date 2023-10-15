#include "port.h"
Port::Port() : serial(new QSerialPort())
{
}
QSerialPort  *  Port::getPort() {
    return this->serial;

}
void Port::defPort(){
    serial->setPortName(QString("com3"));
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->setStopBits(QSerialPort::OneStop);
    serial->open(QIODevice::ReadOnly);
}
Port::~Port(){
    this->serial->disconnect();
    this->serial->close();
    delete serial;
}
