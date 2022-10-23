// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 12/10/2022
// Archivo funciones.cc: Encargado de la creación de los métodos para lectura y escritura de ficheros

#include "funciones.h"

//Metodo para obter un vector de simbolos el cual representa a un alfabeto
std::vector<Simbolo> LeerAlfabetoFichero(std::string entrada) {
  std::vector<Simbolo> simbolos = {};
  std::string tmp_concat = "";
  for (int iterador = 0; iterador < entrada.size(); iterador++) {
    if (entrada[iterador] == '}') {
      break;
    } else if (entrada[iterador] != ' ' && entrada[iterador] != '{') {
      tmp_concat = tmp_concat + entrada[iterador];
    } else {
      Simbolo tmp_simbolo(tmp_concat);
      simbolos.push_back(tmp_simbolo);
      tmp_concat = "";
    }
  }
  return simbolos;
}

//Metodo para obtener un vector de cadenas el cual representa un lenguaje
std::vector<Cadena> LeerLenguajeFichero(std::string entrada) {
  std::vector<Cadena> cadenas = {};
  std::string tmp_concat = "";
  std::string tmp_entrada (std::find(entrada.begin()+1, entrada.end(), '{'), entrada.end()-1);
  tmp_entrada.erase(0, 2);
  for (int iterador = 0; iterador < tmp_entrada.size(); iterador++) {
    if (tmp_entrada[iterador] != ' ') {
      tmp_concat = tmp_concat + tmp_entrada[iterador];
    } else {
      Cadena tmp_cadena(tmp_concat);
      cadenas.push_back(tmp_cadena);
      tmp_concat = "";
    }
  }
  return cadenas;
}

//Metodo para escribir una string en un fichero dado
void EscribirFichero(std::ofstream& fichero_escritura, std::string entrada) {
  fichero_escritura << entrada << "\n";
}