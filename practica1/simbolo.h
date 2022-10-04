#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

class Simbolo {
  public:
    Simbolo(std::vector<std::string> lectura);
    ~Simbolo();
    std::vector<std::string> getSimbolos();
    void displaySimbolos();
  private:
    std::vector<std::string> simbolos;
    std::vector<int> contarEspacios(std::vector<std::string> entrada);
    std::string generateSimbolos(std::string entrada);
};
