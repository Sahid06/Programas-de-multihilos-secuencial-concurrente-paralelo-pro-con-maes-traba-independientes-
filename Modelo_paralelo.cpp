#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

using namespace std;

void sumarParte(vector<int> numeros, int inicio, int fin, int &resultado) {
    resultado = 0;

    cout << "Hilo procesando desde la posicion " << inicio 
         << " hasta la posicion " << fin - 1 << endl;

    for (int i = inicio; i < fin; i++) {
        resultado += numeros[i];
        this_thread::sleep_for(chrono::milliseconds(200));
    }

    cout << "Resultado parcial: " << resultado << endl;
}

int main() {
    cout << "---- Modelo Paralelo ----" << endl;

    vector<int> numeros = {5, 10, 15, 20, 25, 30, 35, 40};

    int resultado1 = 0;
    int resultado2 = 0;

    thread hilo1(sumarParte, numeros, 0, 4, ref(resultado1));
    thread hilo2(sumarParte, numeros, 4, 8, ref(resultado2));

    hilo1.join();
    hilo2.join();

    int resultadoFinal = resultado1 + resultado2;

    cout << "Suma del primer bloque: " << resultado1 << endl;
    cout << "Suma del segundo bloque: " << resultado2 << endl;
    cout << "Resultado final: " << resultadoFinal << endl;

    return 0;
}
