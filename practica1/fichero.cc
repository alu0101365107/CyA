#include "fichero.h"

Fichero::Fichero(std::string nombre_fichero, bool opcode) {
  if (opcode == true) { 
    ficheroLectura.open(nombre_fichero);
    std::string tmp_cadena_entrada;
    if(ficheroLectura.is_open()) {
      while(std::getline(ficheroLectura, tmp_cadena_entrada)) {
        lectura.push_back(tmp_cadena_entrada);
      }
    }
    ficheroLectura.close();
  } else {
    ficheroEscritura.open(nombre_fichero);
  };
}

Fichero::~Fichero() {
  if(ficheroLectura.is_open()) {
    ficheroLectura.close();
  } else if (ficheroEscritura.is_open()) {
    ficheroEscritura.close();
  }
};

std::vector<std::string> Fichero::getVectorString() {
  return lectura;
}

void Fichero::escribirFichero(std::vector<std::string> escritura) {
  for (int i=0; i< escritura.size(); i++) {
    ficheroEscritura << escritura[i] << "\n";
  }
}