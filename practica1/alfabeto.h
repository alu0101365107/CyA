#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include "cadena.h"
#include "simbolo.h"


class Alfabeto {
  public:
    Alfabeto(Simbolo& simbolos, Cadena& cadenas);
    ~Alfabeto();
    std::vector<std::string> getAlfabeto();
    void DisplayAlfabetos();
  private:
    std::vector<std::string> kAlfabetos;
    void BorrarDuplicadosSimbolos(std::string kEntrada, Simbolo& kSimbolos, int kPosicion);
};

