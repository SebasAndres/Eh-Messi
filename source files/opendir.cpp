#pragma once
#include "../Header Files/opendir.h"

void opendir::openDir(std::string dir) {
    std::string cc = "explorer ";
    const char* cmd = (cc.append(dir)).c_str(); 
    std::cout << "* Abriendo el directorio " << dir << std::endl;
    system(cmd);
}