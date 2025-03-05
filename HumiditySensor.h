#include <chrono>
#include "Sensor.h"
#ifndef PROJET_AP4A_HUMIDITYSENSOR_H
#define PROJET_AP4A_HUMIDITYSENSOR_H


class HumiditySensor :public Sensor {
public:
    HumiditySensor(Server& s);
    ~HumiditySensor();
    virtual void execute();
    virtual std::string getData() const;
private :
    float data;
};


#endif //PROJET_AP4A_HUMIDITYSENSOR_H
