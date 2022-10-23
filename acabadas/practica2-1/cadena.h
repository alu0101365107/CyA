// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 12/10/2022
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
    Cadena Inversa();;
    std::vector<Simbolo> GetCadena();
    bool operator<(const Cadena& entrada) const;
    Cadena Concatenacion(Cadena& entrada);
  private:
    std::vector<Simbolo> cadena;
};
