// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 19/10/2022
// Archivo lenguaje.cc: Encargado de la creación de los métodos de la clase Lenguaje.

#include "lenguaje.h"

//Constructor de la clase Lenguaje el cual recibe un vector de Cadena y un Alfabeto
Lenguaje::Lenguaje(std::vector<Cadena> entrada_cadena, Alfabeto entrada_alfabeto) {
  cadenas = std::set<Cadena>(entrada_cadena.begin(), entrada_cadena.end());
  alfabeto = entrada_alfabeto;
}

//Constructor por defecto
Lenguaje::Lenguaje() {};

//Metodo para mostrar por pantalla un Lenguaje
void Lenguaje::Display(){
  alfabeto.DisplayAlfabeto();
  std::cout << "{ ";
  for (Cadena cadena : cadenas) {
    for (int iterador = 0; iterador < cadena.GetCadena().size(); iterador++){
      std::cout << cadena.GetCadena()[iterador].GetSimbolo();
    }
    std::cout << " ";
  }
  std::cout << "}\n";
}

//Metodo para obtener un lenguaje como string
std::string Lenguaje::GetString(){
  std::string salida = alfabeto.GetString() + "{ ";
  for (Cadena cadena : cadenas) {
    for (int iterador = 0; iterador < cadena.GetCadena().size(); iterador++){
      salida = salida + cadena.GetCadena()[iterador].GetSimbolo();
    }
   salida = salida + " ";
  }
  salida = salida + "}";
  return salida;
}

//Metodo para concatenar un lenguaje con otro
Lenguaje Lenguaje::Concatenacion(Lenguaje& entrada) {
  if (alfabeto.GetVacio() == true || entrada.alfabeto.GetVacio() == true) {
    return Lenguaje();
  }
  std::vector<Cadena> vector_cadena = {};
    for (Cadena cadena : cadenas) {
      for (Cadena cadena_entrada : entrada.cadenas) {
        vector_cadena.push_back(cadena.Concatenacion(cadena_entrada));
      }
    }
    return Lenguaje(vector_cadena, alfabeto.AddAlfabeto(entrada.alfabeto));
}

//Metodo para realizar la union con otro lenguaje
Lenguaje Lenguaje::Union(Lenguaje& entrada) {
  if (alfabeto.GetVacio() == true || entrada.alfabeto.GetVacio() == true) {
    return Lenguaje();
  }
  std::string tmp_concat = "";
  std::vector<Cadena> vector_cadena = {};
  std::string concat = "";
  for (Cadena cadena : cadenas) {
    for (int iterador = 0; iterador < cadena.GetCadena().size(); iterador++) {
     tmp_concat = tmp_concat + cadena.GetCadena()[iterador].GetSimbolo();
    }
    vector_cadena.push_back(Cadena(tmp_concat));
    tmp_concat = "";
  }
  for (Cadena cadena : entrada.cadenas) {
    for (int iterador = 0; iterador < cadena.GetCadena().size(); iterador++) {
      tmp_concat = tmp_concat + cadena.GetCadena()[iterador].GetSimbolo();
    }
    vector_cadena.push_back(Cadena(tmp_concat));
    tmp_concat = "";
  }
  return Lenguaje(vector_cadena, alfabeto.AddAlfabeto(entrada.alfabeto));
}

//Metodo para realizar la interseccion con otro lenguaje
Lenguaje Lenguaje::Interseccion(Lenguaje& entrada) {
  if (alfabeto.GetVacio() == true || entrada.alfabeto.GetVacio() == true) {
    return Lenguaje();
  }
  std::string tmp_concat = "";
  std::string tmp_concat2 = "";
  std::vector<Cadena> vector_cadena = {};
  for (Cadena cadena: cadenas) {
    for (int iterador = 0; iterador < cadena.GetCadena().size(); iterador++) {
      tmp_concat = tmp_concat + cadena.GetCadena()[iterador].GetSimbolo();
    }
    for (Cadena cadena_entrada : entrada.cadenas) {
      for (int iterador_entrada = 0; iterador_entrada < cadena_entrada.GetCadena().size(); iterador_entrada++) {
        tmp_concat2 = tmp_concat2 + cadena_entrada.GetCadena()[iterador_entrada].GetSimbolo();
      }
      if (tmp_concat.compare(tmp_concat2) == 0) {
        vector_cadena.push_back(Cadena(tmp_concat));
      }
      tmp_concat2 = "";
    }
    tmp_concat = "";
  }
  return Lenguaje(vector_cadena, alfabeto.AddAlfabeto(entrada.alfabeto));
}

//Metodo para realizar la diferencia con otro lenguaje
Lenguaje Lenguaje::Diferencia(Lenguaje& entrada) {
  if (alfabeto.GetVacio() == true || entrada.alfabeto.GetVacio() == true) {
    return Lenguaje();
  }
  std::string tmp_concat = "";
  std::string tmp_concat2 = "";
  std::vector<Cadena> vector_cadena = {};
  bool status = false;
  for (Cadena cadena: cadenas) {
    for (int iterador = 0; iterador < cadena.GetCadena().size(); iterador++) {
      tmp_concat = tmp_concat + cadena.GetCadena()[iterador].GetSimbolo();
    }
    for (Cadena cadena_entrada : entrada.cadenas) {
      for (int iterador_entrada = 0; iterador_entrada < cadena_entrada.GetCadena().size(); iterador_entrada++) {
        tmp_concat2 = tmp_concat2 + cadena_entrada.GetCadena()[iterador_entrada].GetSimbolo();
      }
      if (tmp_concat.compare(tmp_concat2) == 0) {
        status = true;
      }
      tmp_concat2 = "";
    }
    if (status == false) {
     vector_cadena.push_back(Cadena(tmp_concat));
    } 
    status = false;
    tmp_concat = "";
  }
  return Lenguaje(vector_cadena, alfabeto.AddAlfabeto(entrada.alfabeto));
}

//Metodo para obtener un lenguaje nuevo el cual representa la inversa
Lenguaje Lenguaje::Inversa() {
  std::string tmp_concat = "";
  std::vector<Cadena> vector_cadena = {};
  for (Cadena cadena: cadenas) {
    for (int iterador_entrada = 0; iterador_entrada < cadena.GetCadena().size(); iterador_entrada++) {
      tmp_concat = tmp_concat + cadena.GetCadena()[iterador_entrada].GetSimbolo();
    }
    vector_cadena.push_back(Cadena(tmp_concat).Inversa());
    tmp_concat = "";
  }
 return Lenguaje(vector_cadena, alfabeto);
}

//Metodo para realizar la potencia de un lenguaje
Lenguaje Lenguaje::Potencia(int valor_n) {
  std::string tmp_concat = "";
  std::vector<Cadena> vector_cadena = {};
  Lenguaje tmp_lenguaje_concat;
  Lenguaje lenguaje_concat;
  if (valor_n != 0) {
    for(Cadena cadena: cadenas) {
      for(int iterador = 0; iterador < cadena.GetCadena().size(); iterador++) {
        tmp_concat = tmp_concat + cadena.GetCadena()[iterador].GetSimbolo();
      }
        vector_cadena.push_back(tmp_concat);
        tmp_concat = "";
    }
    tmp_lenguaje_concat = Lenguaje(vector_cadena, alfabeto);
    lenguaje_concat = tmp_lenguaje_concat;
    for(int iterador_valor_n = 0; iterador_valor_n < valor_n - 1; iterador_valor_n++) {
      lenguaje_concat = lenguaje_concat.Concatenacion(tmp_lenguaje_concat);
    }
  } else {
      Cadena cadena_vacia ("&");
      std::vector<Cadena> vector_cadena_vacio = {cadena_vacia};
      return Lenguaje (vector_cadena_vacio, alfabeto);
  }
  return lenguaje_concat;
}