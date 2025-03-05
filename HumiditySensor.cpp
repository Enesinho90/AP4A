#include "HumiditySensor.h"
#include "Server.h"
#include <cstdlib>

HumiditySensor::HumiditySensor(Server& s) : Sensor("Humidity_Sensor",2,s), data(0.0f){} // Instanciation à l'aide de la classe mère, intervalle de 2 secondes  pour les capteurs d'humidité

HumiditySensor::~HumiditySensor(){
    delete server;
}
void HumiditySensor::execute() {
    this->data=static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100)); ;// Génère un nombre aléatoire
    server->consoleWrite(*this);  // Affiche le nombre aléatoire
    server->fileWrite(*this);
    server->measureData(*this);

}

std::string HumiditySensor::getData() const{
    return std::to_string(this->data);
}



