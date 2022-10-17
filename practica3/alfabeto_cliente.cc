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
#include <regex>
#include <cctype>
#include <stack>

int main(int argc, char* argv[]) {
  if(argc == 1) {
    std::cout << "Modo de uso: ./alfabeto_cliente input_file1.txt input_file2.txt output_file.txt opcode\n";
    std::cout << "Para más información --help\n";
  }else if (argc == 2) {
    std::string kLecturaFichero = argv[1];
    std::ifstream fichero_lectura;
    std::string tmp_entrada;
    std::vector<Lenguaje> lenguajes = {};
    std::vector<Alfabeto> alfabetos = {};
    std::regex alfabeto("[A-Za-z]");
    std::string resultado = "";
    std::stack <Lenguaje> pila;
    Lenguaje lenguaje_operacion;
    Lenguaje lenguaje_operacion_2;
    fichero_lectura.open(kLecturaFichero);
    if(fichero_lectura.is_open()) {
      while(std::getline(fichero_lectura, tmp_entrada)) {
        if (tmp_entrada.find("=") != std::string::npos) {
          Alfabeto tmp_alfabeto(LeerAlfabetoFichero(tmp_entrada));
          Lenguaje tmp_lenguaje(LeerLenguajeFichero(tmp_entrada), tmp_alfabeto);
          lenguajes.push_back(tmp_lenguaje);
        } else {
          resultado = std::regex_replace(tmp_entrada, alfabeto, "");
          for(int iterador = 0; iterador < resultado.size(); iterador++) {
            if(resultado[iterador] != ' ') {
              if (isdigit(resultado[iterador])) {
                int i = resultado[iterador] - '0';
                pila.push(lenguajes[i-1]);
              } else {
                lenguaje_operacion_2 = pila.top();
                pila.pop();
                lenguaje_operacion= pila.top();
                pila.pop();
                switch (resultado[iterador]) {
                  case ('+'):
                    pila.push(lenguaje_operacion.Concatenacion(lenguaje_operacion_2));
                    break;
                  case ('|'):
                    pila.push(lenguaje_operacion.Union(lenguaje_operacion_2));
                    break;
                  case ('^'):
                    pila.push(lenguaje_operacion.Interseccion(lenguaje_operacion_2));
                    break;
                  case ('-'):
                    pila.push(lenguaje_operacion.Diferencia(lenguaje_operacion_2));
                    break;
                  case ('!'):
                    pila.push(lenguaje_operacion.Inversa());
                    break;             
                  default:
                    break;
                }
              }
            }
          }
          lenguaje_operacion = pila.top();
          pila.pop();
          lenguaje_operacion.Display();
        }
      }
    }
  } else if(strcmp(argv[1], "--help") == 0) {
    std::cout << "Uso correcto del programa\n- Nombre del fichero de lectura_1\n";
    std::cout << "- Nombre del fichero de lectura_2\n";
    std::cout << "- Nombre del fichero de escritura\n- Opcode:\n";
    std::cout << "\t1- Concatenacion\n\t2- Union\n";
    std::cout << "\t3- Interseccion\n\t4- Diferencia\n";
    std::cout << "\t5- Inversa\n\t6- Potencia\n";
    std::cout << "Modo de uso: ./alfabeto_cliente input_file1.txt input_file2.txt output_file.txt opcode\n";
  } else {
    std::cout << "Para más información --help\n";
    std::cout << argv[1];
  }
  return 0;
};
