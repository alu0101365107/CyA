// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 05/10/2022
// Archivo alfabeto.cc: Encargado de la creación de los métodos de la clase Alfabeto.

#include "alfabeto.h"

// Constructor de la clase Alfabeto, el cual recibe Simbolo y Cadena, para su posterior procesamiento.
Alfabeto::Alfabeto(Simbolo& simbolos, Cadena& cadenas) {
  for(int i = 0; i < simbolos.Size(); i++) {
    BorrarDuplicadosSimbolos(simbolos[i], simbolos, i);
    ComprobarCadenaRespectoSimbolo(simbolos[i], cadenas, simbolos, i);
    kAlfabetos.push_back(simbolos[i]);
  }
};

// Destructor de la clase Alfabeto.
Alfabeto::~Alfabeto() {};

// Metodo encargado de borrar simbolos repetidos, ya que el alfabeto es un conjunto de simbolos.
void Alfabeto::BorrarDuplicadosSimbolos(std::string entrada, Simbolo& simbolos, int posicion) {
  std::string tmp_entrada = "";
  bool duplicado = false;
  for(int i = 0; i < entrada.size(); i++) {
    for(int j = 0; j < tmp_entrada.size(); j++) {
      if(entrada[i] == tmp_entrada[j] && entrada[i] != ' ') {
        duplicado = true;
      }
    }
    if (duplicado == false) {
      tmp_entrada = tmp_entrada + entrada[i];
    } else {
      duplicado = false;
    }
  }
  if(entrada.compare(tmp_entrada) != 0) {
    simbolos.SetSimbolos(tmp_entrada, posicion);
  }
}

// Metodo para comprobar si una cadena pertenece a un alfabeto.
void Alfabeto::ComprobarCadenaRespectoSimbolo(std::string entrada, Cadena& cadenas, Simbolo& simbolos, int posicion) {
  bool encontrada = false;
  for(int i = 0; i < cadenas[posicion].size(); i++) {
    for(int j = 0; j < entrada.size(); j++) {
      if (cadenas[posicion][i] == entrada[j]) {
        encontrada = true;
      }
    }
    if (encontrada == false) {
      i = cadenas[posicion].size();
      cadenas.erase(posicion);
      simbolos.erase(posicion);
    }
  }
}