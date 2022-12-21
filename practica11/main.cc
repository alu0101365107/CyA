/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Computabilidad y Algoritmia
 *
 * @author Héctor Rodríguez Alonso (alu0101365107)
 * @date 21. dec. 2022
 * @brief Práctica 11: Algoritmos Voraces
 * 
 * Main del programa el cual genera el cambio en billetes o monedas
*/

#include "monedas.h"
#include "monedaCollection.h"
#include "funciones.h"
#include <iostream>
#include <cstring>

// Creacion de un vector de monedas el cual representada estas desde "2€" a "1¢" en centimos
const std::vector<Moneda> kVectorMoneda = {
    Moneda(200, "2€"),
    Moneda(100, "1€"),
    Moneda(50, "50¢"),
    Moneda(20, "20¢"),
    Moneda(10, "10¢"),
    Moneda(5, "5¢"),
    Moneda(2, "2¢"),
    Moneda(1, "1¢")
};

// Creacion de un vector de monedas el cual representado los billetes desde "500€" a "5€" en centimos
const std::vector<Moneda> kVectorBilletes = {
    Moneda(50000, "500€"),
    Moneda(20000, "200€"),
    Moneda(10000, "100€"),
    Moneda(5000, "50€"),
    Moneda(2000, "20€"),
    Moneda(1000, "10€"),
    Moneda(500, "5€"),
};

// Comprobacion para saber si la entrada es un numero o no
bool esNumero(char number[]) {
  for (uint i = 0; number[i] != 0; i++) {
    if (!isdigit(number[i]) && number[i] != '.')
      return false;
  }
  return true;
}

// Main principal del programa
int main(int argc, char* argv[]) {  
  if (argc > 3  || argc <= 1) {   // En caso de que se pasen mas argumentos de los esperados o menos, indicaremos el uso correcto
    std::cout << "Modo de uso: ./main [opcion] [cantidad]\n";
    std::cout << "Para más información --help\n";
  } else if(strcmp(argv[1], "--help") == 0) {    // Cuando el usuario emplee el flag --help, mostraremos por pantalla las instrucciones de uso mas detalladas
    std::cout << "Uso correcto del programa:\n- [opcion]\t\n -b -> Billetes \t\n -o -> Optima\n";
    std::cout << "-[cantidad] Cantidad a devolver\n";
    std::cout << "Modo de uso: ./main [opcion] [cantidad]\n";
  } else if (strcmp(argv[1], "-b") == 0) {     // Cuando el usuario emplee el flag -b, lanzaremos el cambio empleando billetes
    if (argc == 3) {
      if (esNumero(argv[2]) == true) {
        std::cout << "Opcion Billetes: " + std::string(argv[2]) + "€\n";
        const int kCantidad = atof(argv[2]) * 100.0;    //Pasaremos el char* de la entrada a float para multiplicarlo por 100.0
        MonedaCollection (devolverCambio(addMonedas(kVectorBilletes, kVectorMoneda), kCantidad)).Print();  /** Añadiremos al vector el cual pasaremos a devolverCambio
                                                                                                        * el vector de billetes y monedas, ademas de la cantidad a 
                                                                                                        * devolver. Este nos devolvera una collection de monedas
                                                                                                        * la cual imprimiremos por pantalla
                                                                                                        */ 
      } else {
        std::cout << "Ingresaste un valor no válido\nPara más información --help\n";
      }
    } else {
      std::cout << "No ingresaste una cantidad\nPara más información --help\n";
    }  
  } else if (strcmp(argv[1], "-o") == 0) {    // Cuando el usuario emplee el flag -o, lanzaremos el cambio empleando monedas ademas de usar el algoritmo opmito
    if (argc == 3){
      if (esNumero(argv[2]) == true) {
        std::cout << "Opcion Optima: " + std::string(argv[2]) + "€\n";
        const int kCantidad = atof(argv[2]) * 100.0;    //Pasaremos el char* de la entrada a float para multiplicarlo por 100.0
        MonedaCollection (devolverCambioOptimo(kVectorMoneda, kCantidad)).Print();  /** Pasaremos a devolverCambioOptimo el vector de monedas 
                                                                                    * ademas de la cantidad a devolver. Este nos devolvera 
                                                                                    * una collection de monedas la cual imprimiremos por pantalla
                                                                                    */ 
      } else {
        std::cout << "Ingresaste un valor no válido\nPara más información --help\n";
      } 
    } else {
      std::cout << "No ingresaste una cantidad\nPara más información --help\n";
    }   
  } else {
    if (esNumero(argv[1]) == true) {
      std::cout << "Opcion Normal: " + std::string(argv[1]) + "€\n";
      const int kCantidad = atof(argv[1]) * 100.0;    //Pasaremos el char* de la entrada a float para multiplicarlo por 100.0
      MonedaCollection (devolverCambio(kVectorMoneda, kCantidad)).Print();    /** Pasaremos a devolverCambio el vector de monedas 
                                                                              * ademas de la cantidad a devolver. Este nos devolvera 
                                                                              * una collection de monedas la cual imprimiremos por pantalla
                                                                              */ 
    } else {
      std::cout << "Ingresaste un valor no válido\nPara más información --help\n";
    }
  }
  return 0;
}