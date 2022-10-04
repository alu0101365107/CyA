#include "simbolo.h"

Simbolo::Simbolo(std::vector<std::string> kLectura) {
  std::string tmp_entrada;
  const char kEspacio = ' ';
  bool lectura_status = false;
  std::vector<int> vector_contador_espacios = ContarEspacios(kLectura);
  int tmp_contador = 0;
  int letra = 0;
  for(int cadena = 0; cadena < kLectura.size(); cadena++) {
    while(tmp_contador < vector_contador_espacios[cadena]) {
      while (kLectura[cadena][letra] != kEspacio) {
        tmp_entrada = tmp_entrada + kLectura[cadena][letra];
        letra += 1;
      }
      letra += 1;
      tmp_contador += 1;
      tmp_entrada = tmp_entrada + " ";
    }
    if (tmp_contador == 0) {
      simbolos.push_back(GenerarSimbolos(kLectura[cadena]));
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

std::vector<int> Simbolo::ContarEspacios(std::vector<std::string> kEntrada) {
  char espacio = ' ';
  std::vector<int> vectorContador;
  int tmp_contador = 0;
  for(int i = 0; i < kEntrada.size(); i++) {
    for(int j = 0; j < kEntrada[i].size(); j++) {
      if (kEntrada[i][j] == espacio) {
        tmp_contador+=1;
      }
    }
    vectorContador.push_back(tmp_contador);
    tmp_contador = 0;
  }
  return vectorContador;
}

std::string Simbolo::GenerarSimbolos(std::string kEntrada) {
  std::string tmp_cadena;
  for(int letra = 0; letra < kEntrada.size(); letra++) {
    tmp_cadena = tmp_cadena + kEntrada[letra] + " ";
  }
  return tmp_cadena;
}