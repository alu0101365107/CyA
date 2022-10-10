#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

class Simbolo {
  public:
    Simbolo(std::string entrada);
    std::string getSimbolo();
    void DisplaySimbolos();
  private:
    std::string simbolo;
};

std::ostream & operator<<(std::ostream& os, Simbolo& p_simbolo);