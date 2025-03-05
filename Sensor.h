#ifndef PROJET_AP4A_SENSOR_H
#define PROJET_AP4A_SENSOR_H
#include <string>
#include <vector>
#include <iostream> // Pour std::cout
#include <fstream>
#include <chrono>
#include "Server.h"

class Server;

class Sensor {
public :
// FORME CANONIQUE DE COPLIEN
    Sensor(); //Constructeur par défaut
    Sensor(Server& s);
    Sensor(const std::string,int interval_, Server& s);
    virtual ~Sensor(); //Destructeur
    Sensor(const Sensor& copie); //Constructeur par copie
    Sensor& operator=(const Sensor& s); //Opérateur d'affection

    // METHODES
    void update();
    virtual void execute()=0;
    std::string getType() const ;
    virtual std::string getData() const=0;
    int getId() const;


private:
    static int nextId; // permet l'ID unique
    int id;
    std::string type;
    int interval;
    std::chrono::time_point<std::chrono::high_resolution_clock> lastUpdate;

protected:
    Server *server;
};


#endif //PROJET_AP4A_SENSOR_H
