/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Computabilidad y Algoritmia
 *
 * @author Héctor Rodríguez Alonso (alu0101365107)
 * @date 26. nov. 2022
 * @brief Práctica 4: Expresiones Regulares
*/

#include "fichero.h"

// Constructor del fichero entrada, el cual lee cada linea de este y lo analiza
Fichero::Fichero(std::ifstream& entrada_fichero, std::string entrada_nombre_programa) {
  std::string tmp_entrada = "";
  nombre_programa = entrada_nombre_programa;
  while(std::getline(entrada_fichero, tmp_entrada)) {
	linea += 1;
    LeerBloqueComentario(entrada_fichero, tmp_entrada);
	  if (IsBucle(tmp_entrada) == false) {
		if (IsComentario(tmp_entrada) == false) {
          IsVariable(tmp_entrada);
		}
	  }
	  if (main == false) {
		IsMain(tmp_entrada);
	  }
	}
  entrada_fichero.close();
}

// Desctructor de la clase fichero
Fichero::~Fichero() {};

/** Metodo el cual en caso de encontrar en una linea del fichero la expresion regular,
 * este ira concatenando linea a linea hasta encontrar la siguiente expresion regular.
 * Una vez se encuentre esta, el bloque del comentario habra finalizado.
*/
bool Fichero::LeerBloqueComentario(std::ifstream& fichero, std::string entrada) {
  std::string kEspacio = "\n";
  if(std::regex_search(entrada, std::regex("(\\/\\*+)"))) {
	bloque_comentario.lineaC = linea;
	bloque_comentario.comentario += "DESCRIPTION : \n" + entrada + kEspacio;
	std::getline(fichero, entrada);
	linea += 1;
	while(!std::regex_search(entrada, std::regex("\\*\\/"))) {
      bloque_comentario.comentario += entrada + kEspacio;
	  std::getline(fichero, entrada);
	  linea += 1;
	}
	  bloque_comentario.comentario += entrada + kEspacio;
	  bloque_comentario.lineaF = linea;
	  comentario tmp_comentario;
	  tmp_comentario.comentario = "DESCRIPTION";
	  tmp_comentario.lineaC = bloque_comentario.lineaC;
	  tmp_comentario.lineaF = bloque_comentario.lineaF;
	  comentarios.push_back(tmp_comentario);
	  return true;
	}
  return false;
}

// Metodo el cual busca en una string la siguiente expresion regular, la cual refleja el main de un programa
void Fichero::IsMain(std::string entrada) {
  if(std::regex_search(entrada, std::regex("[a-z]*\\s(main)\\s(\\([a-z]*\\))\\s(\\{)"))) {
    main = true;
  }
}

// Metodo el cual busca los bucles for y while en una string dada
bool Fichero::IsBucle(std::string entrada) {
  for(std::string tmp_tipo: tipo_bucle) {
	if(std::regex_search(entrada, std::regex("("+tmp_tipo+")\\s(\\(.+\\{)"))) {
      bucle tmp_bucle;
	  tmp_bucle.tipo = tmp_tipo;
	  tmp_bucle.linea = linea;
	  bucles.push_back(tmp_bucle);
	  return true;
	}
  }
  return false;
}

// Metodo el cual busca la sucesion de dos "\\"
bool Fichero::IsComentario(std::string entrada) {
  if (std::regex_search(entrada, std::regex("(\\/\\/)\\s(.)"))) {
    comentario tmp_comentario;
	tmp_comentario.comentario = entrada;
	tmp_comentario.lineaC = linea;
	comentarios.push_back(tmp_comentario);
	return true;
  }
  return false;
}

// Meotod el cual busca variables de tipo "double" e "int" en una string dada
bool Fichero::IsVariable(std::string entrada) {
  for(std::string tmp_tipo: tipo_variable) {
	if(std::regex_search(entrada, std::regex("("+tmp_tipo+")\\s(\\w+)\\s(\\;|\\=\\s\\w+)"))) {
      std::transform(tmp_tipo.begin(), tmp_tipo.end(), tmp_tipo.begin(), ::toupper);
	    variable tmp_variable;
	    tmp_variable.tipo = tmp_tipo;
	    entrada = std::regex_replace(entrada, std::regex("\\s+"), " ");
	    entrada.erase(0, tmp_variable.tipo.size()+2);
	    tmp_variable.nombre = entrada;
	    tmp_variable.linea = linea;
	    variables.push_back(tmp_variable);
	    return true;
	}
  }
  return false;
}

// Metodo el cual devuelve una string formateada con todo el analisis
std::string Fichero::GetAnalisis() {
  std::string salida = "";
  std::string kEspacio = "\n";
  std::string kDobleEspacio = "\n\n";
  salida = "PROGRAM: " + nombre_programa + kEspacio;
  if (bloque_comentario.comentario != "") {
    salida += bloque_comentario.comentario + kEspacio;
  }
  if (main == false) {
    salida += "MAIN: " + kEspacio + "False"+ kDobleEspacio;
  } else {
    salida += "MAIN: " + kEspacio + "True"+ kDobleEspacio;
  }
  if (variables.size() > 0) {
    salida += "VARIABLES: \n";
    for (variable tmp_variable: variables) {
	  salida += "[Line " + std::to_string(tmp_variable.linea) + "]" + tmp_variable.tipo + ": " + tmp_variable.nombre + kEspacio;
	}
  }
  if (bucles.size() > 0) {
	salida += kEspacio + "STATEMENTS:" + kEspacio;
	for(bucle tmp_bucle: bucles) {
		salida += "[Line " + std::to_string(tmp_bucle.linea) + "] LOOP: " + tmp_bucle.tipo + kEspacio;
	}
  }
  if (comentarios.size() > 0) {
	salida += kEspacio + "COMMENTS: " + kEspacio;
	for (comentario tmp_comentario: comentarios) {
	  if (tmp_comentario.lineaF == 0) {
		salida += "[Line " + std::to_string(tmp_comentario.lineaC) + "] " + tmp_comentario.comentario + kEspacio;
	  } else {
		salida += "[Line " + std::to_string(tmp_comentario.lineaC) + "-" + std::to_string(tmp_comentario.lineaF) +" ] " + tmp_comentario.comentario + kEspacio;
	  }
	}
  }
  return salida;
}