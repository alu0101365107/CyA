// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 05/10/2022
// Archivo cadena.h: Encargado de la definición de la clase Cadena y sus correspondientes
//                   métodos y atributos.

#include "fichero.h"

Fichero::Fichero(std::string kNombreFichero, bool kOpcode) {
  if (kOpcode == true) { 
    kFicheroLectura.open(kNombreFichero);
    std::string tmp_cadena_entrada;
    if(kFicheroLectura.is_open()) {
      while(std::getline(kFicheroLectura, tmp_cadena_entrada)) {
        kLectura.push_back(tmp_cadena_entrada);
      }
      kFicheroLectura.close();
    } else {
      std::cout << "El fichero de lectura no se pudo abrir" << std::endl;
    }
  } else {
    kFicheroEscritura.open(kNombreFichero);
  };
}

Fichero::~Fichero() {
  if(kFicheroLectura.is_open()) {
    kFicheroLectura.close();
  } else if (kFicheroEscritura.is_open()) {
    kFicheroEscritura.close();
  }
};

std::vector<std::string> Fichero::GetVectorString() {
  return kLectura;
}

void Fichero::EscribirFichero(std::vector<std::string> kEscritura) {
  for (int i=0; i< kEscritura.size(); i++) {
    kFicheroEscritura << kEscritura[i] << "\n";
  }
}