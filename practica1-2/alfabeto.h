#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include "simbolo.h"
#include "cadena.h"

class Alfabeto {
  public:
    Alfabeto(std::vector<Simbolo> simbolos, Cadena cadena);
    void DisplayAlfabeto();
  private:
    std::vector<Simbolo> alfabeto;
};