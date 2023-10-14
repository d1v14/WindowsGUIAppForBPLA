#ifndef PORT_H
#define PORT_H
#include <QtSerialPort/QSerialPort>

class Port
{
public:
    Port();
    ~Port();
    void defPort();
    QSerialPort  *  getPort() ;
private:
    QSerialPort *  serial;

};

#endif // PORT_H
