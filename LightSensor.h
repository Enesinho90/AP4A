#include "Sensor.h"
#ifndef PROJET_AP4A_LIGHTSENSOR_H
#define PROJET_AP4A_LIGHTSENSOR_H


class LightSensor : public Sensor {
public:
    LightSensor(Server& s);
    ~LightSensor();
    virtual void execute();
    virtual std::string getData() const;

private :
    bool data;
};


#endif //PROJET_AP4A_LIGHTSENSOR_H
