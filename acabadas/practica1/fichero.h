// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 05/10/2022
// Archivo fichero.cc: Encargado de la creación de los métodos de la clase Fichero.

#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

class Fichero {
  public:
    Fichero(std::string nombre_fichero, bool opcode = false);
    ~Fichero();
    std::vector<std::string> GetVectorString();
    void EscribirFichero(std::vector<std::string> escritura);
  private:
    std::vector<std::string> lectura;
    std::ifstream fichero_lectura;
    std::ofstream fichero_escritura;
};

