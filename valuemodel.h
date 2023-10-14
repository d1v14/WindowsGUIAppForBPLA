#ifndef VALUEMODEL_H
#define VALUEMODEL_H

#include "port.h"
#include <QLabel>
#include <vector>
using namespace std;
class ValueModel
{
public:
    ValueModel();
    void pushLabel(QLabel* label);
    void pushLabelValue(QString value);
    void pushValue(char value);
    void setValue(QString value, int ind);
    unsigned long long getSizeVal();
    QString getLabelValue(int ind);
    void setLabelValue(int ind);
    void getValsFromPort();
    void clearVecValues();
    ~ValueModel();
private:
    vector<QLabel*> vecLab;
    vector<QString> vecValLab;
    vector<char> vecVal;
};

#endif // VALUEMODEL_H
