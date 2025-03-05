#ifndef PROJET_AP4A_SERVER_H
#define PROJET_AP4A_SERVER_H
#include <string>
#include <vector>
#include <iostream> // Pour std::cout
#include <fstream>
#include "Sensor.h"

class Sensor;
class Server {
public:
        // FORME CANONIQUE DE COPLIEN
        Server(); //Constructeur par défaut
        Server(std::string name); // Constructeur avec nom
        ~Server(); //Destructeur
        Server(const Server& copie); //Constructeur par copie
        Server& operator=(const Server& s); // Opérateur d'affection


        // METHODES
        std::string getName() const;
        void setName(const std::string& name);
        void consoleWrite(const Sensor& sensor) const; // Affichage des données sur la console
        void fileWrite(const Sensor& sensor) const;// Ecriture des données dans un fichier
        void measureData(const Sensor&); // Mesure des données
        void analyzeData() const; // Analyse des données



private:
    std::string Name;
    float sumTemp=0.0,sumHum=0.0;
    int sumSou=0;
    int measureNumberTemp=0,measureNumberHum=0,measureNumberSou=0;
};


#endif //PROJET_AP4A_SERVER_H
