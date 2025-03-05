#include "LightSensor.h"
#include "Server.h"
#include <cstdlib>
LightSensor::LightSensor(Server& s) : Sensor("Light_Sensor",5,s), data(false) { //Instanciation à l'aide de la classe mère, intervalle de 5 secondes  pour les capteurs de luminosité

}

LightSensor::~LightSensor(){
    delete server;
}
void LightSensor::execute() {
    this->data=(rand() % 100)%2 ;// Génère un booleen aléatoire
    server->consoleWrite(*this);  // Affiche le nombre aléatoire
    server->fileWrite(*this);
    server->measureData(*this);

}

std::string LightSensor::getData() const{
    return std::to_string(this->data);
}
