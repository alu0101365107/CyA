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
    int kOpcode = std::stoi(argv[3]);
    std::vector<std::string> kLectura = Fichero(kLecturaFichero, true).GetVectorString();
    Fichero kFicheroEscitura(kEscrituraFichero);
    Cadena kCadenas(kLectura);
    Simbolo kSimbolos(kLectura);
    Alfabeto kAlfabetos(kSimbolos, kCadenas);
    kAlfabetos.DisplayAlfabetos();
    switch (kOpcode) {
      case(1):
        kFicheroEscitura.EscribirFichero(kCadenas.GetLongitud());
        break;
      case(2):
        kFicheroEscitura.EscribirFichero(kCadenas.Inversa());
        break;
      case(3):
        kFicheroEscitura.EscribirFichero(kCadenas.GetPrefijos());
        break;
      case(4):
        kCadenas.Inversa();
        kFicheroEscitura.EscribirFichero(kCadenas.GetPrefijos());
      case(5):
        kCadenas.GetSubcadenas();
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
