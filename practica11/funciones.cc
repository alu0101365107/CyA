/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Computabilidad y Algoritmia
 *
 * @author Héctor Rodríguez Alonso (alu0101365107)
 * @date 21. dec. 2022
 * @brief Práctica 11: Algoritmos Voraces
 * 
 * Desarrollo de los metodos para el cambio de monedas y adicion del contenido de un vector de monedas a otro sin duplicados
*/

#include "funciones.h"

/** Devolucion del cambio
 * @param monedasEntrante Vector todas las monedas de la collection
 * @param cambio Cambio el debemos de obtener
*/ 
std::vector<Moneda> devolverCambio(MonedaCollection monedasEntrante, int cambio) {
  std::vector<Moneda> monedasEmpleadas;
  int indiceMonedaActual = 0;
  while (cambio > 0) {
    if (cambio >= monedasEntrante.getMonedas()[indiceMonedaActual].getValue()) {  //Si el cambio es mas grande que el valor de la moneda actual
      monedasEmpleadas.push_back(Moneda(monedasEntrante.getMonedas()[indiceMonedaActual].getValue(),
                                        monedasEntrante.getMonedas()[indiceMonedaActual].getRepresentacion()));  // Añadimos la moneda al vector final de monedas
      cambio -= monedasEntrante.getMonedas()[indiceMonedaActual].getValue();  // Restamos el valor añadido al cambio
    } else {  // En caso contario, cambiaremos de moneda
      indiceMonedaActual++;
    }
  }
  return monedasEmpleadas;
}

/** Adicion del contenido de un vector de monedas a otro sin duplicados
 * @param vector1 Vector al añadiremos el contenido del segundo vector
 * @param vector2 Vector el cual queremos unir al primer vector
*/ 
std::vector<Moneda> addMonedas(std::vector<Moneda> vector1, std::vector<Moneda> vector2) {
    bool encontrado = false;
    for (uint indiceMonedaActual = 0; indiceMonedaActual < vector2.size(); indiceMonedaActual++) {
        for (uint indiceMonedaActual2 = 0 ; indiceMonedaActual2 < vector1.size(); indiceMonedaActual2++) {
            if (vector1[indiceMonedaActual2].getValue() == vector2[indiceMonedaActual].getValue()) {
                encontrado = true;
            }
        }
        if (encontrado == false) {
            vector1.push_back(vector2[indiceMonedaActual]);
        }
        encontrado = false;
    }

    return vector1;
}

/** Devolucion del cambio optimo
 * @param monedasEntrante Vector todas las monedas de la collection
 * @param cambio Cambio el debemos de obtener
*/ 
std::vector<Moneda> devolverCambioOptimo(MonedaCollection monedasEntrante, int cambio) {
  std::vector<Moneda> monedasEmpleadas;
  int sumaTotal  = 0;
  int numeroMonedasNecesarias  = 0;
  for (uint indiceMonedaActual = 0; indiceMonedaActual < monedasEntrante.getSize(); indiceMonedaActual++) {
    numeroMonedasNecesarias  = (cambio - sumaTotal ) / monedasEntrante.getMonedas()[indiceMonedaActual].getValue(); // Calculamos el numero necesario de esta moneda
    if ( numeroMonedasNecesarias  != 0)  { 
        for (uint indiceMonedaActual2 = 0; indiceMonedaActual2 < numeroMonedasNecesarias ; indiceMonedaActual2++ ) {  //Añadimos al vector de monedas esa moneda tantas veces sea necesaria
          monedasEmpleadas.push_back(monedasEntrante.getMonedas()[indiceMonedaActual]);
        }
        sumaTotal  += numeroMonedasNecesarias * monedasEntrante.getMonedas()[indiceMonedaActual].getValue();  // Sumamos el contenido añadiro en bruto a la sumaTotal
    }
  }
  return monedasEmpleadas;
}