#include "valuemodel.h"
using namespace std;
ValueModel::ValueModel()
{

}
void ValueModel::pushLabel(QLabel* label){
    this->vecLab.push_back(label);
}
void ValueModel::pushLabelValue(QString value){
    this->vecValLab.push_back(value);
}
void ValueModel::pushValue(char value){
    vecVal.push_back(value);
}
void ValueModel::setValue(QString value, int ind){
    this->vecValLab[ind] = value;
}

unsigned long long ValueModel::getSizeVal(){
    return vecValLab.size();
}
void ValueModel::setLabelValue(int ind ){
    vecLab[ind]->setText(vecValLab[ind].trimmed());
}
QString ValueModel::getLabelValue(int ind){
    return this->vecValLab[ind];
}
void ValueModel::getValsFromPort(){
    int k = 0;
    QString s;
    for(int i = 0; static_cast<unsigned long long>(i)< vecVal.size();i++){
        if(vecVal[i]!=',')
        {
            s.push_back(vecVal[i]);
        }
        else{
            this->setValue(s,k);
            s.clear();
            k++;
        }
    }
}
void ValueModel::clearVecValues(){
    vecVal.clear();
}
ValueModel::~ValueModel(){
    for(int i = 0; static_cast<unsigned long long>(i)<vecLab.size();i++){
        delete vecLab[i];
    }
}
