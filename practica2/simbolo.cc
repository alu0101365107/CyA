// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 12/10/2022
// Archivo simbolo.cc: Encargado de la creación de los métodos de la clase Simbolo.

#include "simbolo.h"

//Constructor de la clase simbolo el cual recibe una string
Simbolo::Simbolo(std::string entrada) {
  for (int iterador = 0; iterador < entrada.size(); iterador++) {
    simbolo = simbolo + entrada[iterador];
  }
};

//Getter para la obtencion del simbolo
std::string Simbolo::GetSimbolo() {
  return simbolo;
}


//Metodo para mostrar por pantalla un simbolo
void Simbolo::DisplaySimbolos(){
  for (int iterador = 0; iterador < simbolo.size(); iterador++) {
    std::cout << simbolo[iterador];
  }
  std::cout << "\n";
}

//Sobrecarga del operador <<
std::ostream & operator<<(std::ostream& os, Simbolo& p_simbolo) {
  os << p_simbolo.GetSimbolo();
  return os;
}

//Sobrecarga del operador <
bool Simbolo::operator<(const Simbolo& entrada) const {
  return simbolo < entrada.simbolo;
}