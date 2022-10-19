// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 19/10/2022
// Archivo alfabeto_cliente.cc: Fichero principal el cual posee el main, este es el encargado de crear los
//         objetos, en este caso Lenguaje. Este lee un fichero de entrada, resuelve las operaciones linea a linea
//         y devuelve el resultado por pantalla

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
    std::cout << "Modo de uso: ./alfabeto_cliente input_file1.txt\n";
    std::cout << "Para más información --help\n";
  }else if (argc == 2) {
    std::string kLecturaFichero = argv[1];
    std::ifstream fichero_lectura;
    std::string tmp_entrada;
    std::vector<Lenguaje> lenguajes = {};
    std::vector<Alfabeto> alfabetos = {};
    std::vector<std::string> nombre_lenguajes = {};
    std::string nombre = "";
    int max_size_string = 0;
    int iterador_nombre = 0;
    int n = 0;
    std::stack <Lenguaje> pila;
    Lenguaje lenguaje_operacion;
    Lenguaje lenguaje_operacion_2;
    fichero_lectura.open(kLecturaFichero);
    if(fichero_lectura.is_open()) {
      while(std::getline(fichero_lectura, tmp_entrada)) {
        if (tmp_entrada.find("=") != std::string::npos) {
          Alfabeto tmp_alfabeto(LeerAlfabetoFichero(tmp_entrada));
          Lenguaje tmp_lenguaje(LeerLenguajeFichero(tmp_entrada), tmp_alfabeto);
          std::cout << LeerNombreLenguaje(tmp_entrada) << "\n";
          nombre_lenguajes.push_back(LeerNombreLenguaje(tmp_entrada));
          lenguajes.push_back(tmp_lenguaje);
        } else {
          for (int iterador = 0; iterador < tmp_entrada.size(); iterador++) {
            if (tmp_entrada[iterador] != ' ') {
              switch (tmp_entrada[iterador]) {
                case ('+'):
                  lenguaje_operacion = GetElementoPila(pila);
                  lenguaje_operacion_2 = GetElementoPila(pila);
                  pila.push(lenguaje_operacion.Concatenacion(lenguaje_operacion_2));
                  break;
                case ('|'):
                  lenguaje_operacion = GetElementoPila(pila);
                  lenguaje_operacion_2 = GetElementoPila(pila);
                  pila.push(lenguaje_operacion.Union(lenguaje_operacion_2));
                  break;
                case ('^'):
                  lenguaje_operacion = GetElementoPila(pila);
                  lenguaje_operacion_2 = GetElementoPila(pila);
                  pila.push(lenguaje_operacion.Interseccion(lenguaje_operacion_2));
                  break;
                case ('-'):
                  lenguaje_operacion = GetElementoPila(pila);
                  lenguaje_operacion_2 = GetElementoPila(pila);
                  pila.push(lenguaje_operacion.Diferencia(lenguaje_operacion_2));
                  break;
                case ('!'):
                  lenguaje_operacion = GetElementoPila(pila);
                  pila.push(lenguaje_operacion.Inversa());
                  break;             
                default:
                  nombre += tmp_entrada[iterador];
                  break;
              }              
              for (std::string tmp_nombre: nombre_lenguajes) {
                if(tmp_nombre.size() > max_size_string) {
                  max_size_string = tmp_nombre.size();
                }
                if (nombre.size() > max_size_string) {
                  std::cout << "El nombre del lenguaje[" << nombre << "]de la expresion no esta definido\n";
                  return 1;
                } else if (tmp_nombre == nombre) {
                  nombre = "";
                  pila.push(lenguajes[iterador_nombre]);
                  if(pila.size() > 2) {
                    std::cout << "Hay mas de un elemento en la pila [Expresion erronea]\n";
                    return 1;
                  }
                } else if (tmp_entrada[iterador+2] == '*') {
                  lenguaje_operacion = GetElementoPila(pila);
                  n = nombre[0] - '0';
                  pila.push(lenguaje_operacion.Potencia(n));
                  iterador+=2;
                  nombre = "";
                  break;
                }
                iterador_nombre++;
              }
            }
            iterador_nombre = 0;
          }
          nombre = "";
          lenguaje_operacion = pila.top();
          pila.pop();
          lenguaje_operacion.Display();
        }
      }
    }
  } else if(strcmp(argv[1], "--help") == 0) {
    std::cout << "Uso correcto del programa\n- Nombre del fichero de lectura_1\n";
    std::cout << "Modo de uso: ./alfabeto_cliente input_file1.txt\n";
  } else {
    std::cout << "Para más información --help\n";
    std::cout << argv[1];
  }
  return 0;
};
