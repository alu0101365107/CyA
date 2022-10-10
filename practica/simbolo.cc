#include "simbolo.h"

Simbolo::Simbolo(std::string entrada) {
  for(int i = 0; i < entrada.size(); i++) {
    simbolo = simbolo + entrada[i];
  }
};

std::string Simbolo::getSimbolo() {
  return simbolo;
}

void Simbolo::DisplaySimbolos(){
  for(int iterador = 0; iterador < simbolo.size(); iterador++) {
    std::cout << simbolo[iterador];
  }
  std::cout << "\n";
}

std::ostream & operator<<(std::ostream& os, Simbolo& p_simbolo) {
  os << p_simbolo.getSimbolo();
  return os;
}