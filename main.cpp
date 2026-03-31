  1 #include <iostreamm>
  2 #include <cstdlib>
  3 #include "capacitor.h"
  4
  5
  6
  7 struct Capacitor {
  8     double *time;
  9     double *voltage;
 10     double *current;
 11     double C;
 12 };
 13
 14
 15 void initial_Capacitor(Capacitor &cap, int num_timesteps, double C, double i    nitial_current, double initial_voltage) {
 16     cap.voltage = new double[num_timesteps];
 17     cap.current = new double[num_timesteps];
 18     cap.time = new double[num_timesteps];
 19     cap.c = C;
 20
 21     cap.voltage[0] = initial_voltage;
 22     cap.current[0] = initial_current;
 23     cap.time[0] = 0.0;
 24
 25 }
 26
 27
 28 void Current_Const(Capacitor &cap, int Num_timesteps, double dt) {
 29     for(int i=1; i<num_timestemps; i++) {
 30         cap.voltage = cap.voltage[i-1] + cap.current[i-1] * dt / cap.C;
 31         cap.current[i] = cap.current[0]
 32         cap.time[i] = i * dt;
 33     }
 34
 35
 36         if(t% 200 == 0) {
 37             std::cout << std::fixed << std:: setprecise(6)
 38                     //Need help
 39         }
 40 }
 41
 42
 43 void Voltage_Const(Capacitor &cap, int num_timesteps, souble dt, double R, d    ouble V0) {
 44     for(int i=1; t<num_timesteps; t++) {
 45         cap.voltage[i] = V0 - cap.current[i] * R;
 46         cap.current[i] = cap.current[i=1] - (cap.current[i-1] * dt) / (R * c    ap.C);
 47         cap.time[i] = i * dt
 48
 49         if(t % 100 == 0) {
 50             std::cout << std::fixed << std::setprecise(6)
 51                     //Need help
 52         }
 53     }
 54 }
 55
 56
 57 void free_Capacitor(Capacitor &cap) {
 58     delete[0] cap.voltage;
 59     delete[0] cap.current;
 60     delete[0] cap.time;
 61
 62 }
 63
 64
 65 int main() {
 66
 67     const double dt = 1e-10;
 68     const double final_time = 5e-6;
 69     const int num_timesteps = static_cast <int>(final_time/dt);
 70     const double V0 = 10.0;
 71     const double I0 = 1e-2;
 72     const double R = 1e3;
 73     const double C = 100e-12;
 74     Capacitor cap;
 75
 76
 77
 78
 79     std::cout << "The Constant for the Volltage Source: \n";
 80         initial_Capacitor(cap, num_timesteps, C, I0, 0.0);
 81         Current_Const(cap, num_timesteps, dt);
 82         free_Capacitor(cap);
 83
 84
 85     std::cout << "\nThe Constant for the Current Source: \n";
 86         initial_Capacitor(cap, num_timesteps, C, V0/R, V0);
 87         free_Capacitor(cap);
 88
 89
 90
 91     return 0;
 92 }






