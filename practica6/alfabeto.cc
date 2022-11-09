// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 19/10/2022
// Archivo alfabeto.cc: Encargado de la creación de los métodos de la clase Alfabeto.

#include "alfabeto.h"

//Constructor de la clase el cual recibe un vector de simbolos
Alfabeto::Alfabeto(std::vector<Simbolo> simbolos) {
  if (simbolos.size() == 0) {
    vacio = true;
  }
  alfabeto = std::set<Simbolo>(simbolos.begin(), simbolos.end());
}

//Constructor por defecto
Alfabeto::Alfabeto() {};

//Destructor
Alfabeto::~Alfabeto() {};

//Metodo para printear por pantalla un Alfabeto
void Alfabeto::DisplayAlfabeto(){
  std::cout << "{ ";
  for (Simbolo simbolo: alfabeto) {
     std::cout << simbolo.GetSimbolo() << " ";
  }
  std::cout << "}";
}

//Metodo para obtener un lenguaje en string
std::string Alfabeto::GetString() {
  std::string salida = "{ ";
    for (Simbolo simbolo: alfabeto) {
      for (int iterador = 0; iterador < simbolo.GetSimbolo().size(); iterador++) {
        salida = salida +  simbolo.GetSimbolo() + " "; 
      }
    }
  salida = salida + "}";
  return salida;
}

//Getter para saber si un lenguaje es vacio
bool Alfabeto::GetVacio() {
  return vacio;
}

int Alfabeto::GetSize() {
  return alfabeto.size();
}

void Alfabeto::SetAlfabeto(std::vector<Simbolo> simbolos) {
  if (simbolos.size() == 0) {
    vacio = true;
  }
  alfabeto = std::set<Simbolo>(simbolos.begin(), simbolos.end());
}

std::vector<Simbolo> Alfabeto::GetCadenaDeAlfabeto(Cadena& cadena) {
  std::string tmp_concat = "";
  std::vector<Simbolo> tmp_simbolos = {};
  for(int simbolo = 0; simbolo < cadena.GetCadena().size(); simbolo++) {
    tmp_concat += cadena.GetCadena()[simbolo].GetSimbolo();
    for (Simbolo simbolo_alfabeto: alfabeto) {
      if (simbolo_alfabeto.GetSimbolo() == tmp_concat || tmp_concat == "&") {
        tmp_simbolos.push_back(tmp_concat);
        tmp_concat = "";
      }
    }
  }
  return tmp_simbolos;
}