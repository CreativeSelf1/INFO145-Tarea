#include "spentResources.h"

using namespace std;

struct rusage resource_usage;

resources::resources() {
    totalTime = 0.0;
    initialRAM = 0.0;
    totalRAM = 0.0;
}

//Almacena el tiempo actual
std::chrono::high_resolution_clock::time_point resources::getTime(){
    auto ini_time = chrono::high_resolution_clock::now();
    return ini_time;
}
//Recibe el valor de getTime, obtiene el tiempo actual (final) y calcula e imprime la diferencia.
void resources::getTotalTime(std::chrono::high_resolution_clock::time_point ini_time){
    auto end_time = chrono::high_resolution_clock::now();  //Se guarda el tiempo después de buscar en la estructura
    auto elapsed_time = chrono::duration_cast<chrono::nanoseconds>(end_time - ini_time); //Se calcula el tiempo que llevó la busqueda de un elemento: marca final - marca inicial.
    //printf("Tiempo requerido: %0.f nanosegundos.\n", (double)elapsed_time.count()); fflush(stdout); //Se imprime el tiempo que llevó
}
//Almacena el valor actual de memoria
float resources::getRam(){
    getrusage(RUSAGE_SELF, &resource_usage);
    float start_ram = resource_usage.ru_maxrss;
    return start_ram;
}
//Recibe el valor de getRam, genera un valor de memoria final y calcula e imprime la diferencia.
void resources::getTotalRam(float start_ram){
    getrusage(RUSAGE_SELF, &resource_usage);
    float end_ram = resource_usage.ru_maxrss;
    double elapsed_ram = end_ram - start_ram;
    printf("\nMemoria utilizada por la ED: %0.3fMB.\n", elapsed_ram/1e3);
}
