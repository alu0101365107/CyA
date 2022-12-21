/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Computabilidad y Algoritmia
 *
 * @author Héctor Rodríguez Alonso (alu0101365107)
 * @date 21. dec. 2022
 * @brief Práctica 11: Algoritmos Voraces
 * 
 * Creacion de la clase MonedaCollection
*/

#pragma once

#include <iostream>
#include <vector>

#include "monedas.h"

class MonedaCollection {
  public:
		/**
		 * Constructor
		*/
    MonedaCollection(std::vector<Moneda>);

		/**
		 * Destructor
		*/
    ~MonedaCollection();

		/**
		 * Getters
		*/
    int getSize();
    std::vector<Moneda> getMonedas();

		/**
		 * Metodo para printear una collection
		*/
    void Print();
  private:
    std::vector<Moneda> monedas_;
};