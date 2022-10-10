// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 05/10/2022
// Archivo alfabeto_cliente.cc: Fichero principal el cual posee el main, este es el encargado de crear los
//         objetos, en este caso Cadena, Simbolo y Alfabeto, ademas de proporcionar las posibles opciones,
//         como puede ser Longitud, Inversa, Prefijos y Sufijos de una cadena, ademas de la generacion 
//         de subcadenas.

#include "simbolo.h"
#include "cadena.h"
#include "funciones.h"
#include "alfabeto.h"

int main(int argc, char* argv[]) {
  if(argc == 1) {
    std::cout << "Modo de uso: ./alfabeto_cliente input_file.txt output_file.txt opcode\n";
    std::cout << "Para más información --help\n";
  }else if (argc == 4) {
    std::string kLecturaFichero = argv[1];
    std::string kEscrituraFichero = argv[2];
    int kOpcode = std::stoi(argv[3]);
    std::ifstream fichero_lectura;
    std::ofstream fichero_escritura;
    std::string tmp_entrada;
    std::vector<Cadena> cadenas;
    std::vector<Simbolo> simbolos;
    std::vector<Alfabeto> alfabetos;
    std::string simbolos_string;
    const char kEspacio = ' ';
    std::string tmp_simbolo_string;
    fichero_lectura.open(kLecturaFichero);
    if(fichero_lectura.is_open()) {
      while(std::getline(fichero_lectura, tmp_entrada)) {
        simbolos_string = LeerSimbolosFichero(tmp_entrada);
        for(int i = 0; i < simbolos_string.size(); i++) {
          if(simbolos_string[i] != kEspacio) {
            tmp_simbolo_string = tmp_simbolo_string + simbolos_string[i];
          } else {
            Simbolo tmp_simbolo(tmp_simbolo_string);
            simbolos.push_back(tmp_simbolo);
            tmp_simbolo_string = "";
          }
        }
        Cadena tmp_cadena(tmp_entrada);
        cadenas.push_back(tmp_cadena);
        Alfabeto tmp_alfabeto(simbolos, tmp_cadena);
        alfabetos.push_back(tmp_alfabeto);
        simbolos = {};
        cadenas = {};
      }
      for(int i = 0; i < alfabetos.size(); i++) {
        //simbolos[i].DisplaySimbolos();
        //cadenas[i].DisplayCadenas();
        //alfabetos[i].DisplayAlfabeto();
        //std::cout << "\n";
      }
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
