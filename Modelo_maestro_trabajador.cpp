#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

using namespace std;

void trabajador(int id, int inicio, int fin) {
    int suma = 0;

    cout << "Trabajador " << id << " procesando numeros del "
         << inicio << " al " << fin << endl;

    for (int i = inicio; i <= fin; i++) {
        suma += i;
        this_thread::sleep_for(chrono::milliseconds(300));
    }

    cout << "Trabajador " << id << " termino. Resultado parcial: "
         << suma << endl;
}

int main() {
    cout << "---- Modelo Maestro-Trabajador ----" << endl;

    vector<thread> trabajadores;

    // El maestro reparte el trabajo
    trabajadores.push_back(thread(trabajador, 1, 1, 5));
    trabajadores.push_back(thread(trabajador, 2, 6, 10));
    trabajadores.push_back(thread(trabajador, 3, 11, 15));
    trabajadores.push_back(thread(trabajador, 4, 16, 20));

    // El maestro espera a que todos terminen
    for (auto &hilo : trabajadores) {
        hilo.join();
    }

    cout << "Todas las tareas fueron completadas por los trabajadores." << endl;

    return 0;
}
