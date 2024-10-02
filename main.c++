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

    return 0;
};
