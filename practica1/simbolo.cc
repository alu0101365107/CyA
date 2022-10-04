#include "simbolo.h"

Simbolo::Simbolo(std::vector<std::string> lectura) {
  std::string tmp_entrada;
  char espacio = ' ';
  bool lecturaStatus = false;
  std::vector<int> contador = contarEspacios(lectura);
  int tmp_contador = 0;
  int letra = 0;
  for(int cadena = 0; cadena < lectura.size(); cadena++) {
    while(tmp_contador < contador[cadena]) {
      while (lectura[cadena][letra] != espacio) {
        tmp_entrada = tmp_entrada + lectura[cadena][letra];
        letra += 1;
      }
      letra += 1;
      tmp_contador += 1;
      tmp_entrada = tmp_entrada + " ";
    }
    if (tmp_contador == 0) {
      simbolos.push_back(generateSimbolos(lectura[cadena]));
    } else { 
      simbolos.push_back(tmp_entrada);
    }
    tmp_entrada = "";
    letra = 0;
    tmp_contador = 0;;
  }
};

Simbolo::~Simbolo() {};

std::vector<std::string> Simbolo::getSimbolos() {
  return simbolos;
};

void Simbolo::displaySimbolos() {
  for(int i= 0; i < simbolos.size(); i++ ) {
    std::cout << simbolos[i] << "\n";
  };
  std::cout << std::endl;
};

std::vector<int> Simbolo::contarEspacios(std::vector<std::string> entrada) {
  char espacio = ' ';
  std::vector<int> vectorContador;
  int tmp_contador = 0;
  for(int i = 0; i < entrada.size(); i++) {
    for(int j = 0; j < entrada[i].size(); j++) {
      if (entrada[i][j] == espacio) {
        tmp_contador+=1;
      }
    }
    vectorContador.push_back(tmp_contador);
    tmp_contador = 0;
  }
  return vectorContador;
}

std::string Simbolo::generateSimbolos(std::string entrada) {
  std::string tmp_cadena;
  for(int letra = 0; letra < entrada.size(); letra++) {
    tmp_cadena = tmp_cadena + entrada[letra] + " ";
  }
  return tmp_cadena;
}