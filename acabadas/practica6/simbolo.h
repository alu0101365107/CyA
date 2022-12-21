// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 19/10/2022
// Archivo simbolo.h: Encargado de la creación de los métodos de la clase Simbolo.

#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

class Simbolo {
  public:
    Simbolo(std::string entrada);
    std::string GetSimbolo();
    void DisplaySimbolos();
    bool operator<(const Simbolo& entrada) const;
  private:
    std::string simbolo;
};

std::ostream & operator<<(std::ostream& os, Simbolo& p_simbolo);