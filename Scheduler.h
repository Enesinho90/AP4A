#ifndef PROJET_AP4A_SCHEDULER_H
#define PROJET_AP4A_SCHEDULER_H

#include "Sensor.h"
#include <vector>

#include <vector>
#include "Sensor.h"

class Scheduler {
public:
    // FORME CANONIQUE DE COPLIEN
    Scheduler();
    Scheduler(std::vector<Sensor *> listSensor);
    ~Scheduler();
    Scheduler(const Scheduler& copie);

    Scheduler& operator=(const Scheduler& s); // Opérateur d'affection
    void simulation(long long time); // Simulation pendant un temps donné
    void simulation(); // Simulation pendant 30 secondes
    void addSensor(Sensor& sensor);

private:
    std::vector<Sensor*> sensors; // Tableau de pointeurs vers des objets Sensor

};


#endif //PROJET_AP4A_SCHEDULER_H
