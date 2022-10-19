// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 19/10/2022
// Archivo lenguaje.h: Encargado de la creación de los métodos de la clase Lenguaje.

#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>
#include "simbolo.h"
#include "cadena.h"
#include "alfabeto.h"

class Lenguaje {
  public:
    Lenguaje(std::vector<Cadena> entrada_cadena, Alfabeto entrada_alfabeto);
    Lenguaje();
    void Display();
    Lenguaje Concatenacion(Lenguaje& entrada);
    Lenguaje Union(Lenguaje& entrada);
    Lenguaje Interseccion(Lenguaje& entrada);
    Lenguaje Diferencia(Lenguaje& entrada);
    Lenguaje Inversa();
    Lenguaje Potencia(int valor_n);
    std::string GetString();
  private:
    std::set<Cadena> cadenas;
    Alfabeto alfabeto;
};