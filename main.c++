#include <string>
#include <iostream>
using namespace std;

struct _capacitor
{
    double *time;       // time array
    double *voltage;    // voltage array
    double *current;    // current array
    double C;           // capacitance value
};
typedef struct _capacitor Capacitor;

Capacitor createCapacitor(size_t size, double capacitance) {
    Capacitor cap;

    // Allocation de mémoire pour les tableaux
    cap.time = (double *)malloc(size * sizeof(double));
    cap.voltage = (double *)malloc(size * sizeof(double));
    cap.current = (double *)malloc(size * sizeof(double));

    // Vérification de l'allocation
    if (cap.time == NULL || cap.voltage == NULL || cap.current == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    cap.C = capacitance;
}

void computeVoltage(Capacitor* capacitor,float V0, float I0, int time,float dt) {
    capacitor->voltage[0] = V0;
    capacitor->current[1] = I0;

    for(int i = 1; i < time; i++){
        capacitor->voltage[i] = capacitor->voltage[i-1] + capacitor->current[i-1]*dt*1/capacitor->C;
    }
}

void computeCurrent(Capacitor* capacitor,float V0, float I0, int time,float dt, float R) {
    capacitor->voltage[0] = V0;
    capacitor->current[1] = I0;
    for(int i = 1; i < time; i++) {
        capacitor->current[i] = capacitor->current[i-1] - (capacitor->current[i-1]/(R*capacitor->C))*dt;
    }

}


int main(int argc, char *argv[]) {
    const double C = 100e-12;
    const float R = 1000;
    const float V0 = 10;
    const float I0 = 1e-2;
    const float FinalTime = 5e-6;
    const float dt = 1e-10;
    const int timestep = FinalTime / dt;

    Capacitor C1 = createCapacitor(timestep, C);



    return 0;
};
