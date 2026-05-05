#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <chrono>

using namespace std;

queue<int> cola;
mutex mtx;

void productor() {
    for (int i = 1; i <= 5; i++) {
        this_thread::sleep_for(chrono::seconds(1));

        mtx.lock();
        cola.push(i);
        cout << "Productor agrego dato: " << i << endl;
        mtx.unlock();
    }
}

void consumidor() {
    for (int i = 1; i <= 5; i++) {
        this_thread::sleep_for(chrono::seconds(2));

        mtx.lock();
        if (!cola.empty()) {
            cout << "Consumidor proceso dato: " << cola.front() << endl;
            cola.pop();
        }
        mtx.unlock();
    }
}

int main() {
    cout << "---- Modelo Productor-Consumidor ----" << endl;

    thread h1(productor);
    thread h2(consumidor);

    h1.join();
    h2.join();

    cout << "Proceso terminado." << endl;

    return 0;
}

