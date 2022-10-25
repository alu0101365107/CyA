/** Autor: Héctor Rodríguez Alonso
* Correo: alu0101365107@ull.es
* Fecha: 05/10/2022
* Archivo cadena.cc: Encargado de la creación de los métodos de la clase Cadena.
*/
#include "cadena.h"

// Constructor de la clase Cadena el cual recibe un vector de string.
// Este concatena los caracteres y en caso de no encontrar ningun
// espacio, lo mete en el atributo privado kEntrada.

Cadena::Cadena(const std::vector<std::string> kEntrada) {
  std::string Clear = "";
  std::string tmp_entrada = Clear;
  char Espacio = ' ';
  for(int cadena = 0; cadena < kEntrada.size(); cadena++) {
    for(int letra = 0; letra < kEntrada[cadena].size(); letra++) {
      if(kEntrada[cadena][letra] != Espacio) {
        tmp_entrada = tmp_entrada + kEntrada[cadena][letra];
      } else {
        tmp_entrada = Clear;
      }
    }
    cadenas.push_back(tmp_entrada);
    tmp_entrada = Clear;
  }
};

// Destructor de la clase Cadena.
Cadena::~Cadena() {};

// Getter para la obtencion del vector de cadenas.
std::vector<std::string> Cadena::GetCadenas() {
  return cadenas;
};

// Getter para obtener el size de cada cadena.
std::vector<std::string> Cadena::GetLongitud() {
  std::vector<std::string> longitud;
  for (int i = 0; i < cadenas.size(); i++) {
    longitud.push_back(std::to_string(cadenas[i].size()));
  }
  return longitud;
};

// Metodo para crear la inversa de cada cadena mediante el metodo
// reverse perteneciente a la libreria algorithm.
std::vector<std::string> Cadena::Inversa() {
  for (int i = 0; i < cadenas.size(); i++) {
    std::reverse(cadenas[i].begin(), cadenas[i].end());
  }
  return cadenas;
};

// Metodo para la creacion de los prefijos que genera cada cadena.
// Este se basa en la concatenacion, hasta llegar al size maximo de la cadena
// concatenamos siempre desde la primera posicion una vez mas, incrementando
// en cada iteracion un caracter mas.
std::vector<std::string> Cadena::GetPrefijos() {
  std::vector<std::string> prefijos;
  std::string tmp_prefijos;
  int contador = 0;
  for (int i = 0; i < cadenas.size(); i++) {
    tmp_prefijos = "& ";
    for (int j = 0; j < cadenas[i].size(); j++) {
      while (contador <= j) {
        tmp_prefijos = tmp_prefijos + cadenas[i][contador];
        contador += 1;
      }
      contador = 0;
      tmp_prefijos = tmp_prefijos + " ";
    }
    prefijos.push_back(tmp_prefijos);
  }
  return prefijos;
};

// Metodo para la creacion de las subcadenas.
// Este se basa en el recorrido de cada una de las cadenas,
// una vez estamos en una cadena, usamos la misma idea de GetPrefijos,
// hasta encontrar el size de la cadena, iteramos primeramente cogiendo un
// caracter hasta llegar al size, en la siguiente iteracion cogemos dos
// caracteres moviendonos 1 posicion en cada uno, de esta forma vamos incrementando
// tanto los caracteres cogidos como la posicion, generando las subcadenas.
std::vector<std::string> Cadena::GetSubcadenas() {
  const std::string kClear = "";
  const std::string kEpsilon = "ε";
  const std::string kEspacio = " ";
  std::vector<std::string> subcadenas = {};
  std::string tmp_subcadenas_formacion = kClear;
  std::string tmp_subcadenas = kClear;
  int contador = 0;
  int veces = 0;
  int size = 0;
  int save_posicion = 0;
  int  posicion = save_posicion;
  for(int i = 0; i < cadenas.size(); i++) {
    veces = 1;
    tmp_subcadenas_formacion = kEpsilon + kEspacio;
    for(int j = 0; j < cadenas[i].size(); j++) {
      for(int k = j; k < cadenas[i].size(); k++) {
        posicion = save_posicion;
        while(contador < veces) {
          tmp_subcadenas_formacion = tmp_subcadenas_formacion + cadenas[i][posicion];
          contador += 1;
          posicion += 1;
        }
        tmp_subcadenas = tmp_subcadenas + tmp_subcadenas_formacion + kEspacio;
        tmp_subcadenas_formacion = kClear;
        contador = 0;
        save_posicion += 1;
      }
      posicion = 0;
      save_posicion = 0;
      veces += 1;
    }
    subcadenas.push_back(tmp_subcadenas);
    tmp_subcadenas = kClear;
  }
  return subcadenas;
};

// Metodo para mostrar por terminal las cadenas
void Cadena::DisplayCadenas() {
  for(int i = 0; i < cadenas.size(); i++ ) {
    std::cout << cadenas[i] << "\n";
  };
  std::cout << std::endl;
};

// Sobrecarga del operador []
std::string Cadena::operator[](int& other) {
  return cadenas[other];
}

// Metodo para la eliminacion de una posicion del vector de cadenas
void Cadena::erase(int& posicion) {
  cadenas.erase(cadenas.begin()+posicion);
}