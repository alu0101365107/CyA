#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

class Fichero {
  public:
    Fichero(std::string nombre_fichero, bool opcode = false);
    ~Fichero();
    std::vector<std::string> getVectorString();
    void escribirFichero(std::vector<std::string> escritura);
  private:
    std::vector<std::string> lectura;
    std::ifstream ficheroLectura;
    std::ofstream ficheroEscritura;
};

