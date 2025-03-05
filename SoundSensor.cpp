#include "SoundSensor.h"
#include "Server.h"
#include <cstdlib>

SoundSensor::SoundSensor(Server& s) : Sensor("Sound_Sensor",3,s), data(0) {
}

SoundSensor::~SoundSensor(){
    delete server;
}

void SoundSensor::execute() {
    this->data=rand() % 100 ;// Génère un nombre aléatoire
    server->consoleWrite(*this);  // Affiche le nombre aléatoire
    server->fileWrite(*this);
    server->measureData(*this);

}

std::string SoundSensor::getData() const{
    return std::to_string(this->data);
}