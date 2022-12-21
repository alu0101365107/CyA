// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 19/10/2022
// Archivo cadena.h: Encargado de la creación de los métodos de la clase Cadena.

#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <algorithm> 
#include "simbolo.h"

class Cadena {
  public:
    Cadena(std::string entrada_cadena);
    ~Cadena();
    Cadena();
    void DisplayCadenas();
    std::vector<Simbolo> GetCadena();
  private:
    std::vector<Simbolo> cadena;
};
