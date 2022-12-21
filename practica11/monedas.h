/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Computabilidad y Algoritmia
 *
 * @author Héctor Rodríguez Alonso (alu0101365107)
 * @date 21. dec. 2022
 * @brief Práctica 11: Algoritmos Voraces
 * 
 * Creacion de la clase Moneda
*/

#pragma once

#include <iostream>

class Moneda {
  public:
		/**
		 * Constructor
		*/
		Moneda(int, std::string);
		
		/**
		 * Destructor
		*/
		~Moneda();

		/**
		 * Getters
		*/
		int getValue();
		std::string getRepresentacion();
  private:
		int valor_ = 0;
		std::string representacion_;
};
