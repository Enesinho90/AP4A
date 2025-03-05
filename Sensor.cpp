#include "Sensor.h"
#include <iostream>  // Pour cout
#include <cstdlib>   // Pour rand(), srand()
#include <ctime>
#include <thread>
#include <chrono>
Sensor::Sensor(){
    id=0;
    type="sensor";
    server=nullptr;
    interval=0;
}
Sensor::Sensor(Server& s){
    id=0;
    type="sensor";
    server=&s;
    interval=0;
}
Sensor::Sensor(const std::string type_,int interval_, Server& serv): id(nextId++),type(type_),interval(interval_),server(&serv){}Sensor::~Sensor(){
}
Sensor::Sensor(const Sensor& copie){
    this->id=copie.id;
    this->type=copie.type;
    this->server=copie.server;
    this->interval=copie.interval;
    this->lastUpdate=copie.lastUpdate;

}
Sensor& Sensor::operator=(const Sensor& s){
    this->id=s.id;
    this->type=s.type;
    this->server=s.server;
    this->interval=s.interval;
    this->lastUpdate=s.lastUpdate;
    return *this;
}

std::string Sensor::getType() const{
    return type;
}
int Sensor::getId()const {
    return id;
}

void Sensor::update(){
    auto now = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - lastUpdate);
    if (elapsed.count() >= interval) {
        lastUpdate = now;
        execute();
    }
}

int Sensor::nextId=1;

