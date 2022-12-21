/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Computabilidad y Algoritmia
 *
 * @author Héctor Rodríguez Alonso (alu0101365107)
 * @date 21. dec. 2022
 * @brief Práctica 11: Algoritmos Voraces
 * 
 * Creacion de los metodos para el cambio de monedas y adicion del contenido de un vector de monedas a otro sin duplicados
*/

#pragma once

#include <vector>
#include "monedas.h"
#include "monedaCollection.h"

// Metodo el cual devuelve el cambio en funcion de una collection de monedas
std::vector<Moneda> devolverCambio(MonedaCollection, int);

// Metodo el cual devuelve el cambio en funcion de una collection de monedas de forma optima
std::vector<Moneda> devolverCambioOptimo(MonedaCollection, int);

// Metodo el cual permite añadir a un vector de monedas, el contenido de otro sin duplicados
std::vector<Moneda> addMonedas(std::vector<Moneda>, std::vector<Moneda>);