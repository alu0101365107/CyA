/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Computabilidad y Algoritmia
 *
 * @author Héctor Rodríguez Alonso (alu0101365107)
 * @date 26. nov. 2022
 * @brief Práctica 4: Expresiones Regulares
*/

#include "fichero.h"
#include <iostream>
#include <regex>
#include <fstream>
#include <vector>

/** Main del programa al cual le pasamos 2 argumentos, nombre del fichero de lectura y
 * nombre del fichero de salida, este crea un objeto Fichero, el cual es analizado, escribiendo
 * los resultados en el fichero de salida. En caso de que el usuario no llame correctamente
 * al programa, se le indicara la forma correcta ademas de poseer un --help
*/
int main(int argc, char* argv[]) {
  if(argc == 1) {
    std::cout << "Modo de uso: ./cliente input_file.cc output_file.txt\n";
    std::cout << "Para más información --help\n";
  } else if(strcmp(argv[1], "--help") == 0) {
    std::cout << "Uso correcto del programa:\n- Nombre del fichero de lectura\n";
    std::cout << "- Nombre del fichero de salida\n";
    std::cout << "Modo de uso: ./cliente input_file.txt output_file\n";
  }else if (argc == 3) {
    std::string kLecturaFichero = argv[1];
    std::string kEscrituraFichero = argv[2];
    std::ifstream fichero_lectura;
    std::ofstream fichero_escritura;
    fichero_lectura.open(kLecturaFichero);
    fichero_escritura.open(kEscrituraFichero);
    if (fichero_lectura.is_open() && fichero_escritura.is_open()) {
      Fichero codigo(fichero_lectura, kLecturaFichero);
      fichero_escritura << codigo.GetAnalisis();
    }
  } else {
    std::cout << "Para más información --help\n";
  }
  return 0;
}