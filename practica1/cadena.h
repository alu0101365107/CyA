#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cmath>

class Cadena {
  public:
    Cadena(std::vector<std::string> entrada);
    ~Cadena();
    std::vector<std::string> getCadenas();
    std::vector<std::string> getLongitud();
    std::vector<std::string> inversa();
    std::vector<std::string> getPrefijos();
    std::vector<std::string> getSubcadenas();
    void displayCadenas();
  private:
    std::vector<std::string> cadenas;
};
