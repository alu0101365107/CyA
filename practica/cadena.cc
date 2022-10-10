#include "cadena.h"

Cadena::Cadena(std::string entrada_cadena) {
  std::string tmp_entrada = "";
  char Espacio = ' ';
  for(int letra = 0; letra < entrada_cadena.size(); letra++) {
    if(entrada_cadena[letra] != Espacio) {
      tmp_entrada = tmp_entrada + entrada_cadena[letra];
    } else {
      tmp_entrada = "";
    }
  }
  for(int letra = 0; letra < tmp_entrada.size(); letra++) {
    cadena.push_back(Simbolo(std::string(1, tmp_entrada[letra])));
  }
};

void Cadena::DisplayCadenas() {
  for(int iterador = 0; iterador < cadena.size(); iterador++) {
    std::cout << cadena[iterador].getSimbolo();
  }
  std::cout << "\n";
}

Cadena::~Cadena() {};

std::vector<Simbolo> Cadena::getCadena() {
  return cadena;
}