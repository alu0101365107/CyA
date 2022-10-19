// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 19/10/2022
// Archivo funciones.cc: Encargado de la creación de los métodos para lectura y escritura de ficheros

#include "funciones.h"


//Metodo para obter un vector de simbolos el cual representa a un alfabeto
std::vector<Simbolo> LeerAlfabetoFichero(std::string entrada) {
  std::vector<Simbolo> simbolos = {};
  std::string tmp_concat = "";
  int inicio = entrada.find("{") + 1;
  for (int iterador = inicio; iterador < entrada.size(); iterador++) {
    if (entrada[iterador] != ',' && entrada[iterador] != ' ' && entrada[iterador] != '}') {
      if(tmp_concat.find(entrada[iterador]) == std::string::npos) {
        simbolos.push_back(Simbolo(std::string(1, entrada[iterador])));
        tmp_concat += entrada[iterador];
      }
    }
  }
  return simbolos;
}

//Metodo para obtener un vector de cadenas el cual representa un lenguaje
std::vector<Cadena> LeerLenguajeFichero(std::string entrada) {
  std::vector<Cadena> cadenas = {};
  std::string tmp_concat = "";
  int inicio = entrada.find("{") + 1;
  for (int iterador = inicio; iterador < entrada.size(); iterador++) {
    if(entrada[iterador] == ',' || iterador == entrada.size()-1) {
      iterador++;
      cadenas.push_back(Cadena(tmp_concat));
      tmp_concat = "";
    } else {
      tmp_concat += entrada[iterador];
    }
  }
  return cadenas;
}

//Metodo para leer el nombre de un lenguaje
std::string LeerNombreLenguaje(std::string entrada) {
  std::string salida = "";
  for (int iterador = 0; iterador < entrada.size(); iterador++) {
    if (entrada[iterador] == ' ') {
      break;
    } else {
      salida += entrada[iterador];
    }
  }
  return salida;
}

//Metodo el cual saca de la pila un lenguaje
Lenguaje GetElementoPila(std::stack<Lenguaje>& pila) {
  Lenguaje lenguaje = pila.top();
  pila.pop();
  return lenguaje;
}