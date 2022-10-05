// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 05/10/2022
// Archivo simbolo.h: Encargado de la definición de la clase Simbolo y sus correspondientes
//                   métodos y atributos.

#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

class Simbolo {
  public:
    Simbolo(std::vector<std::string> kLectura);
    ~Simbolo();
    std::vector<std::string> GetSimbolos();
    void DisplaySimbolos();
    int Size();
    std::string operator[] (int& other);
    void SetSimbolos(std::string kEntrada, int kPosicion);
  private:
    std::vector<std::string> kSimbolos;
    std::vector<int> ContarEspacios(std::vector<std::string> kEntrada);
    std::string GenerarSimbolos(std::string kEntrada);
};
