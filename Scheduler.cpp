#include <chrono>
#include <thread>
#include "Scheduler.h"
#include "Sensor.h"
#include "vector"
// Constructeur par défaut
Scheduler::Scheduler() {
}

// Constructeur avec paramètres
Scheduler::Scheduler(std::vector<Sensor *> listSensor) {
   sensors=listSensor;
}

// Destructeur
Scheduler::~Scheduler() {
    for (auto sensor : sensors) {
        delete sensor; // Libère la mémoire allouée pour chaque sensor
    }
}

// Constructeur par copie
Scheduler::Scheduler(const Scheduler& copie) {
    for (const auto& sensor : copie.sensors) {
        sensors.push_back(sensor); // Copie chaque pointeur dans le tableau
    }
}

// Opérateur d'affection
Scheduler& Scheduler::operator=(const Scheduler& s) {
    if (this != &s) {
        // Libérer l'ancien tableau
        for (auto sensor : sensors) {
            delete sensor;
        }
        sensors.clear();

        // Copier les nouveaux pointeurs
        for (const auto& sensor : s.sensors) {
            sensors.push_back(sensor);
        }
    }
    return *this;
}
void Scheduler::simulation(long long t){
    auto start = std::chrono::steady_clock::now();

    // Durée de 30 secondes
    const std::chrono::seconds duration(t);
    while(1){
        auto now = std::chrono::steady_clock::now();
        if (now - start >= duration) {
            break; // Sortir de la boucle après x secondes
        }else {
            for(Sensor* sensor : sensors){
                sensor->update();
            }
        }
    }
    std::cout<< "Fin de la simulation"<< std::endl;
}
void Scheduler::simulation(){
    auto start = std::chrono::steady_clock::now();

    // Durée de 30 secondes
    const std::chrono::seconds duration(30);
    auto now = std::chrono::steady_clock::now();
    while(now - start <= duration){
        for(Sensor* sensor : sensors){
            sensor->update();
            }
        now = std::chrono::steady_clock::now();
    }
    std::cout << "Fin de la simulation"<< std::endl;


}

void Scheduler::addSensor(Sensor& sensor) {
    sensors.push_back(&sensor);
}
