#include "alfabeto.h"

Alfabeto::Alfabeto(Simbolo& simbolos, Cadena& cadenas) {
  for(int i = 0; i < simbolos.Size(); i++) {
    BorrarDuplicadosSimbolos(simbolos[i], simbolos, i);
    kAlfabetos.push_back(simbolos[i]);
  }
};

Alfabeto::~Alfabeto() {};

void Alfabeto::DisplayAlfabetos() {
  for(int i=0; i < kAlfabetos.size(); i++) {
    for(int j=0; j < kAlfabetos[i].size(); j++) {
      std::cout << kAlfabetos[i][j];
    }
    std::cout << std::endl;
  }
}


void Alfabeto::BorrarDuplicadosSimbolos(std::string kEntrada, Simbolo& kSimbolos, int kPosicion) {
  std::string tmp_entrada = "";
  bool duplicado = false;
  for(int i = 0; i < kEntrada.size(); i++) {
    for(int j = 0; j < tmp_entrada.size(); j++) {
      if(kEntrada[i] == tmp_entrada[j] && kEntrada[i] != ' ') {
        duplicado = true;
      }
    }
    if (duplicado == false) {
      tmp_entrada = tmp_entrada + kEntrada[i];
    } else {
      duplicado = false;
    }
  }
  if(kEntrada.compare(tmp_entrada) != 0) {
    kSimbolos.SetSimbolos(tmp_entrada, kPosicion);
  }
}