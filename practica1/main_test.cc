#include "fichero.h"
#include "simbolo.h"
#include "cadena.h"
#include "alfabeto.h"

int main(int argc, char* argv[]) {
  std::string lectura_fichero = argv[1];
  std::string escritura_fichero = argv[2];
  std::vector<std::string> lectura = Fichero(lectura_fichero, true).getVectorString();
  Fichero fichero_escritua(escritura_fichero);
  Cadena cadenas(lectura);
  Simbolo simbolos(lectura);
  Alfabeto alfabetos(simbolos, cadenas);
  std::string opcode = argv[3];
  if (opcode == "1") {
    fichero_escritua.escribirFichero(cadenas.getLongitud());
  } else if (opcode == "2") {
    fichero_escritua.escribirFichero(cadenas.inversa());
  } else if (opcode == "3") {
    fichero_escritua.escribirFichero(cadenas.getPrefijos());
  } else if (opcode == "4") {
    cadenas.inversa();
    fichero_escritua.escribirFichero(cadenas.getPrefijos());
  } else if (opcode == "5") {
    cadenas.getSubcadenas();
  }
  return 0;
};
