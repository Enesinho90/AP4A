#include "Sensor.h"
#ifndef PROJET_AP4A_TemperatureSENSOR_H
#define PROJET_AP4A_TemperatureSENSOR_H


class TemperatureSensor :public Sensor {
public:
    TemperatureSensor(Server& s);
    ~TemperatureSensor(); //Destructeur
    virtual void execute();
    virtual std::string getData() const;
private :
    float data;
};


#endif //PROJET_AP4A_TemperatureSENSOR_H
