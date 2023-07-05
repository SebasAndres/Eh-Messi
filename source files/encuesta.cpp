#pragma once
#include <../header files/encuesta.h>

void tipsEncuesta::tips() {
        
    /* Dado el porcentaje minimo de una encuesta, 
       muestra por consola la cantidad minima de participantes para llegar a ese porcentaje.
    */

    int minPercent = 100;
    std::cout << "# Ingresa el menor porcentaje obtenido en la encuesta : ";
    std::cin >> minPercent;
    std::cout << std::endl;

    int participantes = participantesMinimos(minPercent);
    int votos = participantes * (minPercent / 100);

    std::cout << "* El menor numero de participantes que habilita " << minPercent << "% es ";
    std::cout << participantes;
    std::cout << ", con " << votos << " votos positivos";
    std::cout << " y " << participantes - votos << " negativos." << std::endl;
    std::cout << std::endl;

    std::cout << "* Estos son todos los numeros que tambien lo habilitan: ";
    
    std::vector<int> possibilities = todasLasPosibilidades(minPercent, 100);
    for (int n : possibilities) {
        std::cout << n << ' ';
    }

    if (possibilities[possibilities.size() - 1] == 99) std::cout << "...";
    std::cout << std::endl;
}

std::vector<std::pair<int, int>> tipsEncuesta::porcentajesPosibles(int n_participantes) {
    /*
    * Dada una cantidad de participantes (n), 
      devuelve una lista de pares de enteros con los posibles porcentajes que 
      se pueden obtener.
        (1, 100 * 1/n), (2, 100 * 2/n), ..., (n, 100 * n/n)
    */
    std::vector<std::pair<int, int>> porcentajes_posibles = {};
    for (int k = 1; k < n_participantes + 1; k++) {
        porcentajes_posibles.push_back(std::make_pair(k, 100 * k / n_participantes));
    }
    return porcentajes_posibles;
}

int tipsEncuesta::participantesMinimos(int minPercent) {  
    /* Dada una cantidad maxima participantes (n) y un porcentaje (stat),
       devuelve la cantidad minima de votantes necesarios para llegar a ese porcentaje.
    */
    int n = 1;
    while (true) {
        std::vector<std::pair<int, int>> lista_i = porcentajesPosibles(n);
        for (auto pair_prob : lista_i) {
            if (pair_prob.second == minPercent) { return n; }
        }
        n++;
    }
}

std::vector<int> tipsEncuesta::todasLasPosibilidades (int minPercent, int max) {
    /* Dada una cantidad maxima participantes (n) y un porcentaje (stat),
       devuelve todas las cantidades de votantes que admiten ese resultado.
    */
    std::vector<int> possibilities = {};
    for (int i = 1; i < max; i++) {
        std::vector<std::pair<int, int>> lista_i = porcentajesPosibles(i);
        for (auto pair_prob : lista_i) {
            if (pair_prob.second == minPercent) 
                possibilities.push_back(i); 
        }
    }
    return possibilities;
}
