// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 05/10/2022
// Archivo cadena.cc: Encargado de la creación de los métodos de la clase Cadena.


#include "cadena.h"

Cadena::Cadena(std::vector<std::string> kEntrada) {
  std::string tmp_entrada;
  char espacio = ' ';
  for(int cadena = 0; cadena < kEntrada.size(); cadena++) {
    for(int letra = 0; letra < kEntrada[cadena].size(); letra++) {
      if(kEntrada[cadena][letra] != espacio) {
        tmp_entrada = tmp_entrada + kEntrada[cadena][letra];
      } else {
        tmp_entrada = "";
      }
    }
    kCadenas.push_back(tmp_entrada);
    tmp_entrada = "";
  }
};

Cadena::~Cadena() {};


std::vector<std::string> Cadena::GetCadenas() {
  return kCadenas;
};

std::vector<std::string> Cadena::GetLongitud() {
  std::vector<std::string> longitud;
  for (int i=0; i < kCadenas.size(); i++) {
    longitud.push_back(std::to_string(kCadenas[i].size()));
  }
  return longitud;
};

std::vector<std::string> Cadena::Inversa() {
  for (int i=0; i < kCadenas.size(); i++) {
    std::reverse(kCadenas[i].begin(), kCadenas[i].end());
  }
  return kCadenas;
};

std::vector<std::string> Cadena::GetPrefijos() {
  std::vector<std::string> prefijos;
  std::string tmp_prefijos;
  int contador = 0;
  std::cout << kCadenas[0];
  for (int i=0; i < kCadenas.size(); i++) {
    tmp_prefijos = "& ";
    for (int j = 0; j < kCadenas[i].size(); j++) {
      while (contador <= j) {
        tmp_prefijos = tmp_prefijos + kCadenas[i][contador];
        contador += 1;
      }
      contador = 0;
      tmp_prefijos = tmp_prefijos + " ";
    }
    prefijos.push_back(tmp_prefijos);
  }
  return prefijos;
};

std::vector<std::string> Cadena::GetSubcadenas() {
  std::vector<std::string> subcadenas;
  std::string tmp_subcadenas;
  int contador = 0;
  int veces = 0;
  int size = 0;
  int save_posicion = 0;
  int  posicion = save_posicion;
  for(int i=0; i < kCadenas.size(); i++) {
    veces = 1;
    for(int j=0; j < kCadenas[i].size(); j++) {
      for(int k = j; k < kCadenas[i].size(); k++) {
        posicion = save_posicion;
        while(contador < veces) {
          tmp_subcadenas = tmp_subcadenas + kCadenas[i][posicion];
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

void Cadena::DisplayCadenas() {
  for(int i= 0; i < kCadenas.size(); i++ ) {
    std::cout << kCadenas[i] << "\n";
  };
  std::cout << std::endl;
};