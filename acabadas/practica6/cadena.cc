// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 19/10/2022
// Archivo cadena.cc: Encargado de la creación de los métodos de la clase Cadena.

#include "cadena.h"

//Constructor de la clase el cual recibe una string
Cadena::Cadena(std::string entrada_cadena) {
  std::string tmp_entrada = "";
  for (int letra = 0; letra < entrada_cadena.size(); letra++) {
    tmp_entrada += entrada_cadena[letra];
  }
  for (int letra = 0; letra < tmp_entrada.size(); letra++) {
    cadena.push_back(Simbolo(std::string(1, tmp_entrada[letra])));
  }
};

//Constructor por defecto
Cadena::Cadena() {};

//Metodo para printear por pantalla una cadena
void Cadena::DisplayCadenas() {
  for (int iterador = 0; iterador < cadena.size(); iterador++) {
    std::cout << cadena[iterador].GetSimbolo();
  }
  std::cout << "\n";
}

//Destructor de la clase
Cadena::~Cadena() {};

//Getter para obtener la cadena
std::vector<Simbolo> Cadena::GetCadena() {
  return cadena;
}
