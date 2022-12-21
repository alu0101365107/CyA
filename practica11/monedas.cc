/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Computabilidad y Algoritmia
 *
 * @author Héctor Rodríguez Alonso (alu0101365107)
 * @date 21. dec. 2022
 * @brief Práctica 11: Algoritmos Voraces
 * 
 * Creacion de los metodos la clase Moneda
*/

#include "monedas.h"


/** Constructor
 * @param valor Valor de la moneda en centimos
 * @param representacion Representacion de la moneda con su simbolo
 */ 
Moneda::Moneda(int valor, std::string representacion) {
    valor_ = valor;
    representacion_ = representacion;
}
/**
 * Destructor
*/
Moneda::~Moneda() {};

/**
 * Getter para obtener el valor de una moneda
*/
int Moneda::getValue() {
    return valor_;
};

/**
 * Getter para obtener la representacion de una moneda
*/
std::string Moneda::getRepresentacion() {
    return representacion_;
}