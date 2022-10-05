// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 05/10/2022
// Archivo cadena.h: Encargado de la definición de la clase Cadena y sus correspondientes
//                   métodos y atributos.

#include "fichero.h"

// Constructor de la clase Fichero, este posee un booleano el cual
// en caso de ser true, se abrira el fichero en modo lectura, para cualquier
// otro caso, se abrira en escritura.
Fichero::Fichero(std::string kNombreFichero, bool kOpcode) {
  if (kOpcode == true) { 
    fichero_lectura.open(kNombreFichero);
    std::string tmp_cadena_entrada = "";
    if(fichero_lectura.is_open()) {
      while(std::getline(fichero_lectura, tmp_cadena_entrada)) {
        lectura.push_back(tmp_cadena_entrada);
      }
      fichero_lectura.close();
    } else {
      std::cout << "El fichero de lectura no se pudo abrir" << std::endl;
    }
  } else {
    fichero_escritura.open(kNombreFichero);
  };
}

// Destructor de la clase Fichero, el cual en caso de estar los ficheros
// abiertos, se cerraran.
Fichero::~Fichero() {
  if(fichero_lectura.is_open()) {
    fichero_lectura.close();
  } else if (fichero_escritura.is_open()) {
    fichero_escritura.close();
  }
};

// Getter para obtener el vector de la lectura de datos del fichero
std::vector<std::string> Fichero::GetVectorString() {
  return lectura;
}

// Metodo para escribir cualquier vector de string en el fichero
void Fichero::EscribirFichero(std::vector<std::string> escritura) {
  for (int i = 0; i< escritura.size(); i++) {
    fichero_escritura << escritura[i] << "\n";
  }
}