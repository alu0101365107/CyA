#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

class Simbolo {
  public:
    Simbolo(std::vector<std::string> kLectura);
    ~Simbolo();
    std::vector<std::string> getSimbolos();
    void displaySimbolos();
  private:
    std::vector<std::string> simbolos;
    std::vector<int> ContarEspacios(std::vector<std::string> kEntrada);
    std::string GenerarSimbolos(std::string kEntrada);
};
