
#include <iostream>
#include <vector>

class tipsEncuesta {
    public:
        void tips();
        int participantesMinimos(int minPercent);
        std::vector<int> todasLasPosibilidades (int minPercent, int max);
        std::vector <std::pair<int, int>> porcentajesPosibles(int nParticipantes);
};