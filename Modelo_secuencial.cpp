#include <iostream>
#include <thread>
#include <chrono>
#include <string>

using namespace std;

void descargarArchivo(string nombre) {
    cout << "Iniciando descarga de: " << nombre << endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "Descarga completada de: " << nombre << endl << endl;
}

int main() {
    cout << "---- Modelo Secuencial: Descarga de Archivos ----" << endl;

    descargarArchivo("Archivo1.zip");
    descargarArchivo("Archivo2.mp4");
    descargarArchivo("Archivo3.pdf");

    cout << "Todas las descargas han finalizado." << endl;

    return 0;
}