#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void reproducirMusica() {
    for (int i = 1; i <= 3; i++) {
        cout << "Reproduciendo musica... segundo " << i << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void descargarArchivo() {
    for (int i = 1; i <= 3; i++) {
        cout << "Descargando archivo... " << i * 30 << "%" << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void mostrarNotificaciones() {
    for (int i = 1; i <= 3; i++) {
        cout << "Mostrando notificacion " << i << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int main() {
    cout << "---- Modelo de Hilos Independientes ----" << endl;

    thread h1(reproducirMusica);
    thread h2(descargarArchivo);
    thread h3(mostrarNotificaciones);

    h1.join();
    h2.join();
    h3.join();

    cout << "Todas las tareas independientes finalizaron." << endl;

    return 0;
}
