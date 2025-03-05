#include "TemperatureSensor.h"
#include "Server.h"
#include <cstdlib>

TemperatureSensor::TemperatureSensor(Server& s) : Sensor("Temperature_Sensor",1,s), data(0.0f) {

}

TemperatureSensor::~TemperatureSensor(){
    delete server;
}

void TemperatureSensor::execute() {
    this->data=static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100));// Génère un nombre aléatoire
    server->consoleWrite(*this);  // Affiche le nombre aléatoire
    server->fileWrite(*this);
    server->measureData(*this);

}

std::string TemperatureSensor::getData() const{
    return std::to_string(this->data);
}
