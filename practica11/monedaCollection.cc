/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Computabilidad y Algoritmia
 *
 * @author Héctor Rodríguez Alonso (alu0101365107)
 * @date 21. dec. 2022
 * @brief Práctica 11: Algoritmos Voraces
 * 
 * Creacion de los metodos la clase MonedaCollection
*/

#include "monedaCollection.h"

/** Constructor
 * @param monedasEntrante Vector todas las monedas de la collection
*/ 
MonedaCollection::MonedaCollection(std::vector<Moneda> monedasEntrante) {
    monedas_ = monedasEntrante;
}

/**
 * Destructor
*/
MonedaCollection::~MonedaCollection() {};

/**
 * Metodo para printear una collection formateada
*/
void MonedaCollection::Print() {
  int contador = 0;
  int contadorTotal = 0;
  bool billete = false;
  Moneda ultimaMoneda = monedas_[0];
  std::string stringResultado = "";
  for(uint indiceMonedaActual = 0; indiceMonedaActual < monedas_.size(); indiceMonedaActual++) {  //Recorremos todas las monedas de la collection
    if (monedas_[indiceMonedaActual].getValue() >= 500) {  //Si el valor de la moneda es mas de 500¢, estaremos ante un billete
        billete = true;
    }
    if (ultimaMoneda.getValue() == monedas_[indiceMonedaActual].getValue()) {  //En caso de la ultima moneda sea igual a la actual, seguiremos sumando
        contador++;
    } else {  // Si tenemos una moneda diferente, sumaremos el contador al total, resetearemos el contador 
              // y cambiaremos la ultimaMoneda, ademas de retrasar el indiceMonedaActual
        if (contador == 1) {  // Si unicamente tenemos una moneda de ese valor, añadiremos este formato a la cadena final
            stringResultado += monedas_[indiceMonedaActual-1].getRepresentacion() + ", ";
        } else {  // En caso contrario, indicaremos la cantidad de esta
            stringResultado += std::to_string(contador) + "x" + monedas_[indiceMonedaActual-1].getRepresentacion() + ", ";
        }
        contadorTotal += contador;
        contador = 0;
        ultimaMoneda = monedas_[indiceMonedaActual];
        indiceMonedaActual--;
    }
    if (indiceMonedaActual == monedas_.size()-1) {  // Cuando el indice sea igual al size del vector de monedas menos 1, 
                                                    // estaremos ante la ultima moneda, por lo que la añadiremos
        stringResultado += std::to_string(contador) + "x" + monedas_[indiceMonedaActual].getRepresentacion() + " ";
        contadorTotal += contador;
    }
  }
  if (billete == true) {  // Si estamos ante un billete, sacaremos por pantalla el siguiente texto formateado
    std::cout << stringResultado << "\nTotal billetes o monedas: " << contadorTotal << "\n";
  } else {  // En caso contrario este
    std::cout << stringResultado << "\nTotal monedas: " << contadorTotal << "\n";
  }

}

/**
 * Getter para obtener el size de la collection
*/
int MonedaCollection::getSize() {
    return monedas_.size();
}

/**
 * Getter para obtener el vector de la collection
*/
std::vector<Moneda> MonedaCollection::getMonedas() {
    return monedas_;
}