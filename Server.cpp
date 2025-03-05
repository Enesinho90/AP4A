#include "Server.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

Server::Server(){
    this->Name="";
}
Server::Server(std::string name){
    this->Name=name;
}
Server::~Server()= default;
Server::Server(const Server& copie){
    this->Name=copie.Name;
}
Server& Server::operator=(const Server& s){
    this->Name=s.Name;
    return *this;
}
std::string Server::getName()const{
    return Name;
}
void Server::setName(const std::string& name){
    this->Name=name;
}

void Server::consoleWrite(const Sensor& s)const{
    std::cout <<"Server : " << Name << " || Sensor ID : " << s.getId() << " || Type : " << s.getType() << " || Data : " << s.getData() << std::endl;
}

void Server::fileWrite(const Sensor& sensor) const {
    std::string fileName = this->getName() + "_"+sensor.getType() +"_log.csv";
    std::ofstream file(fileName, std::ios::app);

    if (!file) {
        std::cerr << "Erreur dans l'ouverture du fichier " << fileName << std::endl;
        return;
    }
    file.seekp(0, std::ios::end);
    if (file.tellp() == 0) {
        file << sensor.getType() << std::endl;
        file << "DATE,ID,DATA" << std::endl;
    }
    // Obtenir l'heure actuelle comme temps du système
    auto now = std::chrono::system_clock::now();
    // Convertir en un type de temps utilisable (std::time_t)
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    file << std::put_time(std::localtime(&currentTime), "%Y-%m-%d %H:%M:%S") <<","<< std::to_string(sensor.getId()) <<","<< sensor.getData()<< std::endl;
    file.close();
    std::cout << "Donnees ecrites dans le fichier : " << fileName << std::endl <<std::endl;
}

void Server::measureData(const Sensor& sensor) {
    if (sensor.getType()=="Humidity_Sensor"){
        sumHum = sumHum + std::stof(sensor.getData());
        measureNumberHum++;
    }
    if (sensor.getType()=="Sound_Sensor"){
        sumSou = sumSou + std::stoi(sensor.getData());
        measureNumberSou++;
    }
    if (sensor.getType()=="Temperature_Sensor"){
        sumTemp = sumTemp + std::stof(sensor.getData());
        measureNumberTemp++;
    }

}

void Server::analyzeData() const {
    std::cout << "Moyenne de temperature durant la simulation : " << sumTemp/measureNumberTemp << "C"<< std::endl;
    std::cout << "Moyenne sonore durant la simulation : " << sumSou/measureNumberSou << "db" << std::endl;
    std::cout << "Moyenne de l'humidite durant la simulation : " << sumHum/measureNumberHum <<"%" << std::endl;


}
