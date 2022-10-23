// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 19/10/2022
// Archivo cadena.cc: Encargado de la creación de los métodos de la clase Cadena.

#include "cadena.h"

//Constructor de la clase el cual recibe una string
Cadena::Cadena(std::string entrada_cadena) {
  std::string tmp_entrada = "";
  char Espacio = ' ';
  for (int letra = 0; letra < entrada_cadena.size(); letra++) {
    if (entrada_cadena[letra] != Espacio) {
      tmp_entrada = tmp_entrada + entrada_cadena[letra];
    } else {
      tmp_entrada = "";
    }
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

//Metodo para realizar la inversa de una cadena usando el metodo reverse de string
Cadena Cadena::Inversa() {
  std::string tmp_inversa = "";
  for (int i = 0; i < cadena.size(); i++) {
    tmp_inversa = tmp_inversa + cadena[i].GetSimbolo();
  }
  reverse(tmp_inversa.begin(), tmp_inversa.end());
  return Cadena(tmp_inversa);
}

//Destructor de la clase
Cadena::~Cadena() {};

//Getter para obtener la cadena
std::vector<Simbolo> Cadena::GetCadena() {
  return cadena;
}

//Sobrecarga del operador <
bool Cadena::operator<(const Cadena& entrada) const {
  return cadena < entrada.cadena;
}

//Metodo para la concatenacion de 2 cadenas, obteniendo los simbolos de cada una
//para concatenar a nivel de string
Cadena Cadena::Concatenacion(Cadena& entrada) {
  std::string concat = "";
  int iterador = 0;
  for (int i = 0; i < cadena.size(); i++) {
    concat += cadena[i].GetSimbolo();
  }
  for (int i = 0; i < entrada.cadena.size(); i++) {
    concat += entrada.cadena[i].GetSimbolo();
  }
  for (int i = 0; i < concat.size(); i++) {
    if(concat[i] == '&') {
      iterador++;
    }
    if (iterador > 0 && concat[i] == '&') {
      concat.erase(i, 1);
    }
  }
  return Cadena(concat);
}
