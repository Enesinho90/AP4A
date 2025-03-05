#include <iostream>
#include "Server.h"
#include "Sensor.h"
#include "Scheduler.h"
#include <cstdlib>
#include "SoundSensor.h"
#include "HumiditySensor.h"
#include "LightSensor.h"
#include "TemperatureSensor.h"


int main(){
    srand(time(0));

    // Créer un serveur nommé S1
    Server S1("S1");

    //Creation des diffents capteurs
    SoundSensor sensSou(S1);
    HumiditySensor sensHum(S1);
    LightSensor sensLig(S1);
    TemperatureSensor sensTem(S1);
    SoundSensor sens2Sou(S1);

    // Création d'une liste de capteurs
    std::vector<Sensor*> sensorList = {&sensSou,&sensHum,&sensLig,&sensTem};
    // Créer un scheduler avec la liste de capteurs
    Scheduler scheduler(sensorList);
    // Ajout d'un capteur a la liste de capteurs dans le scheduler
    scheduler.addSensor(sens2Sou);

    //Lancer la simulation
    scheduler.simulation(20);
    //Analyser les données
    S1.analyzeData();

    return 0;
}


