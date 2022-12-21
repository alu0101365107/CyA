/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Computabilidad y Algoritmia
 *
 * @author Héctor Rodríguez Alonso (alu0101365107)
 * @date 09. dec. 2022
 * @brief Práctica 6: Simulacion Automatas
*/

#include "automata.h"
#include <iostream>
#include <regex>
#include <fstream>
#include <sstream>
#include "alfabeto.h"
#include "simbolo.h"
#include "cadena.h"
#include "assert.h"

/** Main del programa al cual le pasamos 2 argumentos, nombre del fichero el cual describe
 * a un automata y el nombre del fichero el cual tiene las cadenas a analizar.
 * Creamos un objeto Automata, al cual le pasamos la descripción del fichero .fa, una vez hecho
 * llamamos al metodo RunAutomata, el cual analiza las cadenas del segundo fichero.
 * En caso de que el usuario no llame correctamente al programa, se le indicara la 
 * forma correcta ademas de poseer un --help.
*/

int main(int argc, char* argv[]) {
  if(argc == 1) {
    std::cout << "Modo de uso: ./cliente input.fa input.txt\n";
    std::cout << "Para más información --help\n";
  } else if(strcmp(argv[1], "--help") == 0) {
    std::cout << "Uso correcto del programa:\n- Nombre del fichero del fa con extensión .fa\n";
    std::cout << "- Nombre del fichero con las cadenas\n";
    std::cout << "Modo de uso: ./cliente input.fa input.fa\n";
  }else if (argc == 3) {
    if (std::regex_search(argv[1], std::regex("(.+)(\\.fa)$"))) {
      if (std::regex_search(argv[2], std::regex("(.+)(\\.txt)$"))) {
        std::string kFicheroFA = argv[1];
        std::string kLecturaFichero = argv[2];
        std::ifstream fichero_fa;
        std::ifstream fichero_lectura;
        std::string tmp_entrada = "";
        std::string tmp_concat = "";
        std::string tmp_entrada_no_space = "";
        std::vector<Simbolo> tmp_simbolos = {};
        Alfabeto alfabeto;
        int contador_linea = 0;
        char kEspacio = ' ';
        int contador_linea_estado = 0;
        fichero_fa.open(kFicheroFA);
        fichero_lectura.open(kLecturaFichero);
        if (fichero_fa.is_open()) {
          Automata automata;
          while(std::getline(fichero_fa, tmp_entrada)) {
            contador_linea += 1;
            std::stringstream tmp_entrada_ss(tmp_entrada);
            switch (contador_linea) {
              case (1):
                while(std::getline(tmp_entrada_ss, tmp_entrada_no_space, ' ')) {
                  tmp_simbolos.push_back(Simbolo (tmp_entrada_no_space));
                }
                alfabeto.SetAlfabeto(tmp_simbolos);
                automata.SetAlfabeto(alfabeto);
                break;
              case (2):
                automata.SetNumerosEstado(stoi(tmp_entrada));
                break;
              case (3):
                automata.SetEstadoArranque(stoi(tmp_entrada));
                break;
              default:
                estructura_transicion transicion ;
                nodo estado;
                while(std::getline(tmp_entrada_ss, tmp_entrada_no_space, ' ')) {
                  contador_linea_estado += 1;
                  if (contador_linea_estado == 1) {
                    estado.nombre_estado = stoi(tmp_entrada_no_space);
                  } else if (contador_linea_estado == 2) {
                    if (stoi(tmp_entrada_no_space) == 0) {
                      estado.aceptacion = false;
                    } else {
                      estado.aceptacion = true;
                    }
                  } else if (contador_linea_estado == 3) {
                  } else if (contador_linea_estado % 2 == 0) {
                    transicion.simbolo =  tmp_entrada_no_space;
                  } else if (contador_linea_estado % 2 != 0){
                    transicion.estado = stoi(tmp_entrada_no_space);
                    estado.transiciones.push_back(transicion);
                  }
                }
              automata.AddEstados(estado);
              contador_linea_estado = 0;
              break;
            }
          }
          assert(automata.GetNumeroEstados() == automata.GetNumeroEstadosMax());
          fichero_fa.close();
          if (fichero_lectura.is_open()) {
            while(std::getline(fichero_lectura, tmp_entrada)) {
              Cadena tmp_cadena(tmp_entrada);
              if (automata.RunAutomata(alfabeto.GetCadenaDeAlfabeto(tmp_cadena)) == true) {
                std::cout << tmp_entrada + " ---Accepted\n";
              } else {
                std::cout << tmp_entrada + " ---Rejected\n";
              }
            };
          }
        }
      } else {
        std::cout << "Parece que el segundo parametro introducido no es un .txt\n";
      }
    } else {
      std::cout << "Parece que el primer parametro introducido no es un .fa\n";
    }
  } else {
    std::cout << "Para más información --help\n";
  }
  return 0;
}