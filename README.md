# WindowsGUIAppForBPLA
Данное приложение реализует функционал USB-драйвера, принимающего непрерывный поток байт с платы-иммитатора, посылающего набор данных о состоянии БПЛА.
# Класс MainWindow
В данной работе используется библиотека QCustomPlot для реализации графического отображения непрерывноизменяющихся данных
Поля класса:
 1:набор объектов QLabel, QLayout для реализации графического интерфейса
 2:объект класс для реализизации подключения к COM-порту(Port)
 3:объект класса для хранения неграфической модели данных графического приложения(ValueModel)
Слот serialRecieve для подключения функции приема и обработки данных к сигналу readyRead()
Методы класса:
void defLayouts();  инициализация лейаутов
void defPlots();    инициализация графиков
void defLabels();   инициализация лейблов
void putPlotVals(); заполнение массивов графиков принятыми и обработанными значениями с USB
void fillApp();     заполнение полей графического интерфейса принятыми и обработанными значениями с USB
void fillPlots();   заполнение графиков
#Класс Port
Поле класса:
1: Объект класса QSerialPort для работы с COM-портом
Методы класса:
void defPort();    инициализация порта
QSerialPort  *  getPort()   функция, возвращающая указатель на объект открытого для приема QSerialPort
#Класс ValueModel
Поля класса:
1:vector<QLabel*> vecLab        вектор ссылок на лейблы графического интерфейса, необходимый для быстрой адресации к ним, с целью обновления данных, принятых с USB
2:vector<QString> vecValLab     вектор текущих значений типа QString для каждого лейбла из vecLab, необходимый для быстрого соотнесения значения с необходимым лейблом по индексу size(vecLab) = size(vecValLab)
3:vector<char> vecVal           промежуточный вектор значений необходимый, для сохранения данных, пока не встретится символ конца одного пакета данных. После того, как будет достигнут символ конца пакета, данный массив будет парсирован, значения из него переместятся в vecValLab, а позже, очищен.
Методы класса:
void pushLabel(QLabel* label);  метод для добавления лейблов графического интерфейса в конец вектора
void pushLabelValue(QString value); метод для добавления значения лейбла в конец вектора
void pushValue(char value);         метод для добавления значения в конец промежуточного вектора vecLab
void setValue(QString value, int ind);  метод для смены значений в векторе vecVal
unsigned long long getSizeVal();        метод возвращающий длину вектора vecVal
QString getLabelValue(int ind);         метод возвращающий значение из вектора vecValLab по индексу
void setLabelValue(int ind);            метод устанавливающий значение в вектор setLabelValue 
void getValsFromPort();                 метод парсящий промежуточный вектор значений и заполняющий вектор текущих значений лейблов
void clearVecValues();                  метод очищающий промежуточный вектор
=
