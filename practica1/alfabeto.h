// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 05/10/2022
// Archivo alfabeto.h: Encargado de la definición de la clase Alfabeto y sus correspondientes
//                   métodos y atributos.


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
  private:
    std::vector<std::string> kAlfabetos;
    void BorrarDuplicadosSimbolos(std::string entrada, Simbolo& simbolos, int posicion);
    void ComprobarCadenaRespectoSimbolo(std::string entrada, Cadena& cadena, Simbolo& simbolos, int posicion);
};

