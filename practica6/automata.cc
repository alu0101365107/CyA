// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 09/11/2022
// Archivo automata.cc: Encargado de la creación de los métodos de la clase Automata.

#include "automata.h"

//Constructor de la clase automata al cual le pasamos un alfabeto
Automata::Automata(Alfabeto alfabeto_entrada) {
  alfabeto = alfabeto_entrada;
};

//Constructor por defecto de la clase Automata
Automata::Automata() {};

//Destructor de la clase automata
Automata::~Automata() {};

//Setter al acual le pasamos un alfabeto
void Automata::SetAlfabeto(Alfabeto alfabeto_entrada) {
	alfabeto = alfabeto_entrada;
}

//Setter al cual le pasamos el numero de estados que tiene el automata
void Automata::SetNumerosEstado(int numero_estados_entrada) {
	numero_estados = numero_estados_entrada;
};

//Metodo el cual añade los nodos del automata
void Automata::AddEstados(nodo estado) {
  estados.push_back(estado);
};

//Setter el cual recibe el estado de arranque
void Automata::SetEstadoArranque(int estado_arranque_entrada) {
	estado_arranque = estado_arranque_entrada;
}

//Metodo el cual arranca el automata para un las posibles cadenas, 
// este comienza en el estado inicial revisa los posibles simbolos 
// que tiene ese estado para transicionar y cuando encuentra uno 
// coincidente, transita.
bool Automata::RunAutomata(std::vector<Simbolo> cadena) {
  int estado_next = estado_arranque;
	bool aceptacion  = false;
	if (dfa != true && dfa != false) {
		dfa = AnalizarAutomata();
	}
    for (Simbolo simbolo: cadena) {
		  if (simbolo.GetSimbolo() != "&") {
		    for(int transicion = 0; transicion < estados[estado_next].transiciones.size(); transicion++) {
	  	  	if (simbolo.GetSimbolo() == estados[estado_next].transiciones[transicion].simbolo) {
            estado_next = Find(estados[estados[estado_next].transiciones[transicion].estado]);
            aceptacion = estados[estado_next].aceptacion;
	  	  	}
	  	  }
		  } else {
        aceptacion = estados[estado_next].aceptacion;
      }
	}
  return aceptacion;
};

int Automata::GetNumeroEstadosMax() {
	return numero_estados;
}

int Automata::GetNumeroEstados() {
	return estados.size();
}

void Automata::RunNFA(int estado_next, int contador_veces) {
  if (contador_veces == 0) {
    
  } else {
    
  }
}

//Metodo para obtener el iterador del nodo a buscar en el vector estados
int Automata::Find(nodo estado_a_buscar) {
	for(int estado = 0; estado < estados.size(); estado++) {
		if (estados[estado].nombre_estado == estado_a_buscar.nombre_estado) {
			return estado;
		}
	}
  return -1;
}


//Metodo para comprobrar si un automata es un NFA o DFA
bool Automata::AnalizarAutomata() {
	std::vector <int> tmp_transiciones = {};
	int tmp_contador = 0;
	for(int estado = 0; estado < estados.size(); estado++) {
    if (estados[estado].transiciones.size() > alfabeto.GetSize()) {
			dfa = false;
			return dfa;
		}
	}
	dfa = true;
	return dfa;
}

//Metodo el cual printea por consola un automata
void Automata::Print() {
	std::string tmp_aceptacion = "";
	alfabeto.DisplayAlfabeto(); 
	std::cout << "Numero Total de Estados -> " + std::to_string(numero_estados) + "\n";
	std::cout << "Nombre del estado de arranque -> " + std::to_string(estado_arranque) + "\n";
  for (int estado = 0; estado < estados.size(); estado++) {
		std::cout << "Nombre del estado -> " + std::to_string(estados[estado].nombre_estado) << "\n";
    if (estados[estado].aceptacion == false) {
      tmp_aceptacion = "false";
		} else {
			tmp_aceptacion = "true";
		}
		std::cout << "Aceptacion -> " + tmp_aceptacion << "\n";
		for(int transicion = 0; transicion < estados[estado].transiciones.size(); transicion++) {
			std::cout << "\tTransicion al estado -> " + std::to_string(estados[estado].transiciones[transicion].estado);
			std::cout << " Con simbolo -> " + estados[estado].transiciones[transicion].simbolo << "\n";
		}
	}
}