#include "funciones.h"
std::string LeerSimbolosFichero(std::string entrada) {
  std::string tmp_entrada = "";
  const char kEspacio = ' ';
  int tmp_contador_espacios = 0;
  int tmp_letra = 0;
  int contador_espacios = ContadorEspacios(entrada);
  bool duplicado = false;
  if (contador_espacios != 0) {
    while(contador_espacios > tmp_contador_espacios) {
      if(entrada[tmp_letra] == kEspacio) {
        tmp_contador_espacios += 1;
      }
      tmp_entrada = tmp_entrada + entrada[tmp_letra];
      tmp_letra += 1;
    }
  } else {
    for(int letra = 0; letra < entrada.size(); letra++) {
      for(int elemento = 0; elemento < tmp_entrada.size(); elemento++) {
        if(tmp_entrada[elemento] == entrada[letra]) {
          duplicado = true;
        }
      }
      if(duplicado == false) {
        tmp_entrada = tmp_entrada + entrada[letra] + kEspacio;
      } else {
        duplicado = false;
      }
    }
  }
  return tmp_entrada;
}

std::vector<Simbolo> LeerCadenaFichero(std::string entrada) {
  std::vector<Simbolo> simbolos_cadena = {};
  std::string Clear = "";
  std::string tmp_entrada = Clear;
  char Espacio = ' ';
  for(int letra = 0; letra < entrada.size(); letra++) {
    if(entrada[letra] != Espacio) {
      tmp_entrada = tmp_entrada + entrada[letra];
    } else {
      tmp_entrada = Clear;
    }
  }
  std::cout << tmp_entrada << "\n\n";
  return simbolos_cadena;
}

int ContadorEspacios(std::string entrada) {
  int espacios = 0;
  const char kEspacio = ' ';
  for(int letra = 0; letra < entrada.size(); letra++) {
    if(entrada[letra] == kEspacio) {
      espacios += 1;
    }
  }
  return espacios;
}