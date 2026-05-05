
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void prepararSalsa() {
    cout << "Preparando salsa..." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Salsa lista." << endl;
}

void prepararPasta() {
    cout << "Preparando pasta..." << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "Pasta lista." << endl;
}

void prepararEnsalada() {
    cout << "Preparando ensalada..." << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Ensalada lista." << endl;
}

int main() {
    cout << "---- Modelo Concurrente ----" << endl;

    thread hilo1(prepararSalsa);
    thread hilo2(prepararPasta);
    thread hilo3(prepararEnsalada);

    hilo1.join();
    hilo2.join();
    hilo3.join();

    cout << "Comida completa lista." << endl;

    return 0;
}
