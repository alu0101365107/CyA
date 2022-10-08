// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 05/10/2022
// Archivo simbolo.cc: Encargado de la creación de los métodos de la clase Simbolo.

#include "simbolo.h"

// Constructor de la clase Simbolo, el cual unicamente añade a simbolos, aquellos los
// cuales tengan espacios, asi obviando las posibles cadenas.
Simbolo::Simbolo(std::vector<std::string> lectura) {
  std::string tmp_entrada;
  const char kEspacio = ' ';
  bool lectura_status = false;
  std::vector<int> vector_contador_espacios = ContarEspacios(lectura);
  int tmp_contador = 0;
  int letra = 0;
  for(int cadena = 0; cadena < lectura.size(); cadena++) {
    while(tmp_contador < vector_contador_espacios[cadena]) {
      while (lectura[cadena][letra] != kEspacio) {
        tmp_entrada = tmp_entrada + lectura[cadena][letra];
        letra += 1;
      }
      letra += 1;
      tmp_contador += 1;
      tmp_entrada = tmp_entrada + " ";
    }
    if (tmp_contador == 0) {
      simbolos.push_back(GenerarSimbolos(lectura[cadena]));
    } else { 
      simbolos.push_back(tmp_entrada);
    }
    tmp_entrada = "";
    letra = 0;
    tmp_contador = 0;;
  }
};

// Destructor de la clase Simbolo
Simbolo::~Simbolo() {};

// Getter del vector de string de simbolos
std::vector<std::string> Simbolo::GetSimbolos() {
  return simbolos;
};


// Metodo para mostrar por pantalla los simbolos
void Simbolo::DisplaySimbolos() {
  for(int i= 0; i < simbolos.size(); i++ ) {
    std::cout << simbolos[i] << "\n";
  };
  std::cout << std::endl;
};

// Metodo el cual nos indica el numero de espacio que posee un vector de string,
// este devuelve en la misma posicion de la string, el numero de espacio que posee.
std::vector<int> Simbolo::ContarEspacios(std::vector<std::string> entrada) {
  const char kEspacio = ' ';
  std::vector<int> vectorContador = {};
  int tmp_contador = 0;
  for(int i = 0; i < entrada.size(); i++) {
    for(int j = 0; j < entrada[i].size(); j++) {
      if (entrada[i][j] == kEspacio) {
        tmp_contador+=1;
      }
    }
    vectorContador.push_back(tmp_contador);
    tmp_contador = 0;
  }
  return vectorContador;
}

// Metodo para la generacion de simbolos mediante una string
std::string Simbolo::GenerarSimbolos(std::string entrada) {
  std::string tmp_cadena = "";
  for(int letra = 0; letra < entrada.size(); letra++) {
    tmp_cadena = tmp_cadena + entrada[letra] + " ";
  }
  return tmp_cadena;
}

// Metodo el cual devuelve el size del vector de simbolos
int Simbolo::Size() {
  return simbolos.size();
}

// Sobrecarga del operador []
std::string Simbolo::operator[](int& other) {
  return simbolos[other];
}

// Metodo para la eliminacion de una posicion del vector de simbolos
void Simbolo::erase(int& posicion) {
  simbolos.erase(simbolos.begin()+posicion);
}

// Setter el cual cambia una string de la posicion de simbolos
void Simbolo::SetSimbolos(std::string entrada, int posicion) {
  simbolos[posicion] = entrada;
}
