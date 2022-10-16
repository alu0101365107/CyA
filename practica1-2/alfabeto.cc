#include "alfabeto.h"

Alfabeto::Alfabeto(std::vector<Simbolo> simbolos, Cadena cadena) {
  bool pertenece = false;
  for(int i = 0; i < simbolos.size(); i++) {
    std::cout << simbolos[i] << " ";
  }
  std::cout << "\t";
  for(int i = 0; i < cadena.getCadena().size(); i++) {
    std::cout << cadena.getCadena()[i].getSimbolo() << " ";
  }
  std::cout << "\t";
  // int contador = 0;
  // int pos = 0;
  // std::string tmp_concat = "";
  // for(int len = 1; len <= cadena.getCadena().size(); len++) {   
  //   for(int i = 0; i <= cadena.getCadena().size() - len; i++) {
  //     int j = i + len - 1;           
  //     for (int k = i; k <= j; k++)
  //       std::cout << cadena.getCadena()[k];
  //       std::cout << std::endl;
  //       }
  //   }
  // int contador = 0;
  // int tmp_size = 0;
  // std::string tmp_cadena = "";
  // bool lock = false;
  // for(int i = 0; i < cadena.getCadena().size(); i++) {
  //   contador = i;
  //   for(int j = 0; j < simbolos.size(); j++) {
  //     while(tmp_size < simbolos[j].getSimbolo().size() && lock == false) {
  //       tmp_cadena = tmp_cadena + cadena.getCadena()[contador].getSimbolo();
  //       contador += 1;
  //       tmp_size += 1;
  //     }
  //     lock = true;
  //     std::cout << "\nTamaño Simbolo-> " << tmp_size << "\tCadena-> " << tmp_cadena << "\tSimbolo-> " << simbolos[j].getSimbolo() ;
  //     if(tmp_cadena == simbolos[j].getSimbolo()) {
  //       pertenece = true;
  //       std::cout << simbolos[j].getSimbolo().size();
  //       contador = simbolos[j].getSimbolo().size();
  //       j = simbolos.size();
  //       tmp_size = 0;
  //       tmp_cadena = "";
  //       lock = false;
  //     } else {
  //       pertenece = false;
  //     }
  //   }
  // }
  if (pertenece == true) {
    std:: cout << "La cadena pertenece al alfabeto\n";
  } else {
    std::cout << "La cadena no pertenece al alfabeto\n";
  }
  alfabeto = simbolos ;
}

void Alfabeto::DisplayAlfabeto(){
  for(int iterador = 0; iterador < alfabeto.size(); iterador++) {
    std::cout << alfabeto[iterador].getSimbolo();
  }
  std::cout << "\n";
}