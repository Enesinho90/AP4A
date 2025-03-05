#ifndef PROJET_AP4A_SOUNDSENSOR_H
#define PROJET_AP4A_SOUNDSENSOR_H
#include "Sensor.h"


class SoundSensor : public Sensor {
public:
    SoundSensor(Server& s);
    ~SoundSensor(); //Destructeur
    virtual void execute();
    virtual std::string getData() const;

private :
    int data;
};



#endif //PROJET_AP4A_SOUNDSENSOR_H
