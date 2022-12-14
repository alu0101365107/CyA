// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 05/10/2022
// Archivo cadena.h: Encargado de la definición de la clase Cadena y sus correspondientes
//                   métodos y atributos.

#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cmath>

class Cadena {
  public:
    Cadena(const std::vector<std::string> kEntrada);
    ~Cadena();
    std::vector<std::string> GetCadenas();
    std::vector<std::string> GetLongitud();
    std::vector<std::string> Inversa();
    std::vector<std::string> GetPrefijos();
    std::vector<std::string> GetSubcadenas();
    std::string operator[] (int& other);
    void erase(int& posicion);
    void DisplayCadenas();
  private:
    std::vector<std::string> cadenas;
};
