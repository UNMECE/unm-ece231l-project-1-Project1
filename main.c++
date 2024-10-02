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

int main(int argc, char *argv[]) {
    const float C = 100e-12;
    const float R = 1000;
    const float V0 = 10;
    const float I0 = 1e-2;
    const float FinalTime = 5e-6;
    const float dt = 1e-10;
    const float timestep = FinalTime / dt;

    Capacitor C1 = createCapacitor(timestep, C);



    return 0;
};
