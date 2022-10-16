#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include "simbolo.h"

class Cadena {
  public:
    Cadena(std::string entrada_cadena);
    ~Cadena();
    void DisplayCadenas();
    std::vector<Simbolo>  getCadena();
  private:
    std::vector<Simbolo> cadena;
};