#include "cadena.h"

Cadena::Cadena(std::vector<std::string> entrada) {
  std::string tmp_entrada;
  char espacio = ' ';
  for(int cadena = 0; cadena < entrada.size(); cadena++) {
    for(int letra = 0; letra < entrada[cadena].size(); letra++) {
      if(entrada[cadena][letra] != espacio) {
        tmp_entrada = tmp_entrada + entrada[cadena][letra];
      } else {
        tmp_entrada = "";
      }
    }
    cadenas.push_back(tmp_entrada);
    tmp_entrada = "";
  }
};

Cadena::~Cadena() {};


std::vector<std::string> Cadena::getCadenas() {
  return cadenas;
};

std::vector<std::string> Cadena::getLongitud() {
  std::vector<std::string> longitud;
  for (int i=0; i < cadenas.size(); i++) {
    longitud.push_back(std::to_string(cadenas[i].size()));
  }
  return longitud;
};

std::vector<std::string> Cadena::inversa() {
  for (int i=0; i < cadenas.size(); i++) {
    reverse(cadenas[i].begin(), cadenas[i].end());
  }
  return cadenas;
};

std::vector<std::string> Cadena::getPrefijos() {
  std::vector<std::string> prefijos;
  std::string tmp_prefijos;
  int contador = 0;
  std::cout << cadenas[0];
  for (int i=0; i < cadenas.size(); i++) {
    tmp_prefijos = "& ";
    for (int j = 0; j < cadenas[i].size(); j++) {
      while (contador <= j) {
        tmp_prefijos = tmp_prefijos + cadenas[i][contador];
        contador += 1;
      }
      contador = 0;
      tmp_prefijos = tmp_prefijos + " ";
    }
    prefijos.push_back(tmp_prefijos);
  }
  return prefijos;
};

std::vector<std::string> Cadena::getSubcadenas() {
  std::vector<std::string> subcadenas;
  std::string tmp_subcadenas;
  int contador = 0;
  int veces = 0;
  int size = 0;
  int save_posicion = 0;
  int  posicion = save_posicion;
  for(int i=0; i < cadenas.size(); i++) {
    veces = 1;
    for(int j=0; j < cadenas[i].size(); j++) {
      for(int k = j; k < cadenas[i].size(); k++) {
        posicion = save_posicion;
        while(contador < veces) {
          tmp_subcadenas = tmp_subcadenas + cadenas[i][posicion];
          contador += 1;
          posicion +=1;
        }
        std::cout << tmp_subcadenas << " ";
        tmp_subcadenas = "";
        contador = 0;
        save_posicion += 1;
      }
      posicion = 0;
      save_posicion = 0;
      veces +=1;
    }
    std::cout << "\n";
  }
  return subcadenas;
};

void Cadena::displayCadenas() {
  for(int i= 0; i < cadenas.size(); i++ ) {
    std::cout << cadenas[i] << "\n";
  };
  std::cout << std::endl;
};