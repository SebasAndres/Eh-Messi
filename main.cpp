#include <iostream>
#include <stdio.h>  

#include <string.h>
#include <vector>

#include <math.h>
#include <unistd.h>
#include <algorithm>

#include <../scripts/opendir.h>
#include <../scripts/encuesta.h>

using namespace std;

#define forn(max) for (int i=0; i<max; i++)

void Execute(char* argv[]);
string GetCurrentWorkingDir(); 
string replaceChar(string input, int idChar, int nChar); 

int main(int argc, char* argv[]) // argc: num argumentos y argv: argumentos
{   
    cout << endl;
    Execute(argv);
    return 0;
}

string GetCurrentWorkingDir()
{
    string cwd("\0", FILENAME_MAX + 1);
    return getcwd(&cwd[0], cwd.capacity());
}

string replaceChar(string input, int idChar, int nChar) {
    string out;
    forn(input.length()) {
        if ((int)input[i] == idChar) 
            out += char(nChar);
        else
            out += input[i];
    }
    return out;
}

void Execute(char* argv[]) {

    string command = argv[1];

    if (strcmp(command, "help") == 0) {
        cout << "help: muestra la lista de comandos disponibles" << endl;
        cout << "opendir: abre el directorio actual" << endl;
        cout << "encuesta: cantidad de participantes minimas dado un resultado" << endl;
        cout << "unicode: cambia el orden de / en un texto para que sea unicode" << endl;
        cout << "cuad: resuelve una cuadratica" << endl;
    }
    else if (strcmp(command, "opendir") == 0) {
        string currDir = GetCurrentWorkingDir();
        openDir(currDir);
    }
    else if (strcmp(command, "encuesta") == 0) {
        tipsEncuesta.tipsEncuesta();
    }
    else {
        cout << "* El comando " << command << " no esta registrado. Prueba help para ver la lista de comandos. " << endl;
    }
}