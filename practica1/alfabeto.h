#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include "cadena.h"
#include "simbolo.h"


class Alfabeto {
  public:
    Alfabeto(Simbolo simbolos, Cadena cadenas);
    ~Alfabeto();
    std::vector<std::string> getAlfabeto();
    void displayAlfabeto();
  private:
    std::vector<std::string> alfabetos;
};

