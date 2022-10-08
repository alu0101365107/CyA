// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 05/10/2022
// Archivo alfabeto_cliente.cc: Fichero principal el cual posee el main, este es el encargado de crear los
//         objetos, en este caso Cadena, Simbolo y Alfabeto, ademas de proporcionar las posibles opciones,
//         como puede ser Longitud, Inversa, Prefijos y Sufijos de una cadena, ademas de la generacion 
//         de subcadenas.

#include "fichero.h"
#include "simbolo.h"
#include "cadena.h"
#include "alfabeto.h"

int main(int argc, char* argv[]) {
  if(argc == 1) {
    std::cout << "Modo de uso: ./alfabeto_cliente input_file.txt output_file.txt opcode\n";
    std::cout << "Para más información --help\n";
  }else if (argc == 4) {
    std::string kLecturaFichero = argv[1];
    std::string kEscrituraFichero = argv[2];
    std::vector<std::string> kVectorSave = {};
    int kOpcode = std::stoi(argv[3]);
    std::vector<std::string> kLectura = Fichero(kLecturaFichero, true).GetVectorString();
    Fichero kFicheroEscitura(kEscrituraFichero);
    Cadena kCadenas(kLectura);
    Simbolo kSimbolos(kLectura);
    Alfabeto kAlfabetos(kSimbolos, kCadenas);
    switch (kOpcode) {
      case(1):
        kFicheroEscitura.EscribirFicheroMod(kAlfabetos.GetVectorString(), kCadenas.GetCadenas(), kCadenas.GetLongitud());
        break;
      case(2):
        kVectorSave = kCadenas.GetCadenas();
        kFicheroEscitura.EscribirFicheroMod(kAlfabetos.GetVectorString(), kVectorSave, kCadenas.Inversa());
        break;
      case(3):
        kFicheroEscitura.EscribirFicheroMod(kAlfabetos.GetVectorString(), kCadenas.GetCadenas(), kCadenas.GetPrefijos());
        break;
      case(4):
        kVectorSave = kCadenas.GetCadenas();
        kCadenas.Inversa();
        kFicheroEscitura.EscribirFicheroMod(kAlfabetos.GetVectorString(), kVectorSave, kCadenas.GetPrefijos());
        break;
      case(5):
        kFicheroEscitura.EscribirFicheroMod(kAlfabetos.GetVectorString(), kCadenas.GetCadenas(), kCadenas.GetSubcadenas());
        break;
      default:
        std::cout << "Para más información --help\n";
        break;
    }
  } else if(strcmp(argv[1], "--help") == 0) {
    std::cout << "Uso correcto del programa\n- Nombre del fichero de lectura\n";
    std::cout << "- Nombre del fichero de escritura\n- Opcode:\n";
    std::cout << "\t1- Longitud de la cadena\n\t2- Inversa de la cadena\n";
    std::cout << "\t3- Prefijos de la cadena\n\t4- Sufijos de la cadena\n";
    std::cout << "\t5- Subcadenas de la cadena\n";
    std::cout << "Modo de uso: ./alfabeto_cliente input_file.txt output_file.txt opcode\n";
  } else {
    std::cout << "Para más información --help\n";
    std::cout << argv[1];
  }
  return 0;
};
