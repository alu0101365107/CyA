// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 12/10/2022
// Archivo alfabeto.h: Encargado de la definición de la clase Alfabeto y sus correspondientes
//                   métodos y atributos.


#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include "simbolo.h"
#include "cadena.h"
#include <set>

class Alfabeto {
  public:
    Alfabeto(std::vector<Simbolo> simbolos);
    Alfabeto();
    ~Alfabeto();
    Alfabeto AddAlfabeto(Alfabeto& entrada);
    void DisplayAlfabeto();
    std::string GetString();
    std::set<Simbolo> GetSimbolos();
  private:
    std::set<Simbolo> alfabeto;
};