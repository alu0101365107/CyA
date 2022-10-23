// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 12/10/2022
// Archivo alfabeto_cliente.cc: Fichero principal el cual posee el main, este es el encargado de crear los
//         objetos, en este caso Cadena, Simbolo, Alfabeto y Lenguaje, ademas de proporcionar las posibles opciones,
//         como puede ser Concatenacion, Union, Interseccion, Diferencia, Inversa y Potencia, operaciones sobre lenguajes

#include "simbolo.h"
#include "cadena.h"
#include "funciones.h"
#include "alfabeto.h"
#include "lenguaje.h"

int main(int argc, char* argv[]) {
  if(argc == 1) {
    std::cout << "Modo de uso: ./alfabeto_cliente input_file1.txt input_file2.txt output_file.txt opcode\n";
    std::cout << "Para más información --help\n";
  }else if (argc == 5) {
    std::string kLecturaFichero1 = argv[1];
    std::string kLecturaFichero2 = argv[2];
    std::string kEscrituraFichero = argv[3];
    int kOpcode = std::stoi(argv[4]);
    std::ifstream fichero_lectura1;
    std::ifstream fichero_lectura2;
    std::ofstream fichero_escritura;
    std::string tmp_entrada;
    std::vector<Alfabeto> alfabetos_1 = {};
    std::vector<Lenguaje> lenguajes_1 = {};
    std::vector<Alfabeto> alfabetos_2 = {};
    std::vector<Lenguaje> lenguajes_2 = {};
    fichero_lectura1.open(kLecturaFichero1);
    fichero_lectura2.open(kLecturaFichero2);
    fichero_escritura.open(kEscrituraFichero);
    std::vector<Lenguaje> tmp_concatenacion = {};
    if(fichero_lectura1.is_open() && fichero_lectura2.is_open() && fichero_escritura.is_open()) {
      while(std::getline(fichero_lectura1, tmp_entrada)) {
        Alfabeto tmp_alfabeto(LeerAlfabetoFichero(tmp_entrada));
        Lenguaje tmp_lenguaje(LeerLenguajeFichero(tmp_entrada, tmp_alfabeto), tmp_alfabeto);
        lenguajes_1.push_back(tmp_lenguaje);
        alfabetos_1.push_back(tmp_alfabeto);
      }
      while(std::getline(fichero_lectura2, tmp_entrada)) {
        Alfabeto tmp_alfabeto(LeerAlfabetoFichero(tmp_entrada));
        Lenguaje tmp_lenguaje(LeerLenguajeFichero(tmp_entrada, tmp_alfabeto),tmp_alfabeto);
        lenguajes_2.push_back(tmp_lenguaje);
        alfabetos_2.push_back(tmp_alfabeto);
      }
      if(lenguajes_1.size() == lenguajes_2.size()) {
        switch (kOpcode) {
          case(1):
            for(int i = 0; i < lenguajes_1.size(); i++) {
              EscribirFichero(fichero_escritura, lenguajes_1[i].Concatenacion(lenguajes_2[i]).GetString());
            }
            break;
          case(2):
            for(int i = 0; i < lenguajes_1.size(); i++) {
              EscribirFichero(fichero_escritura, lenguajes_1[i].Union(lenguajes_2[i]).GetString());
            }
            break;
          case(3):
            for(int i = 0; i < lenguajes_1.size(); i++) {
              EscribirFichero(fichero_escritura, lenguajes_1[i].Interseccion(lenguajes_2[i]).GetString());
            }
            break;
          case(4):
            for(int i = 0; i < lenguajes_1.size(); i++) {
              EscribirFichero(fichero_escritura, lenguajes_1[i].Diferencia(lenguajes_2[i]).GetString());
            }
            break;
          case(5):
            for(int i = 0; i < lenguajes_1.size(); i++) {
              EscribirFichero(fichero_escritura, lenguajes_1[i].Inversa().GetString());
            }
            break;
          case(6):
            std::cout << "Introduce el valor de N -> ";
            std::cin >> kOpcode;
            if(kOpcode >= 0) {
              for(int i = 0; i < lenguajes_1.size(); i++) {
                EscribirFichero(fichero_escritura, lenguajes_1[i].Potencia(kOpcode).GetString());
              }
            } else {
              std::cout << "El valor de N debe de ser positivo\n";
            }
            break;
          default:
            std::cout << "Para más información --help\n";
            break;
        }
      } else {
        std::cout << "Los ficheros de lectura no poseen la misma cantidad de líneas\n";
      }
    }
  } else if(strcmp(argv[1], "--help") == 0) {
    std::cout << "Uso correcto del programa\n- Nombre del fichero de lectura\n";
    std::cout << "- Nombre del fichero de escritura\n- Opcode:\n";
    std::cout << "\t1- Longitud de la cadena\n\t2- Inversa de la cadena\n";
    std::cout << "\t3- Prefijos de la cadena\n\t4- Sufijos de la cadena\n";
    std::cout << "\t5- Subcadenas de la cadena\n";
    std::cout << "Modo de uso: ./alfabeto_cliente input_file1.txt input_file2.txt output_file.txt opcode\n";
  } else {
    std::cout << "Para más información --help\n";
    std::cout << argv[1];
  }
  return 0;
};
