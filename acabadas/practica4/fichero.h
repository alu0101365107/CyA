/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Computabilidad y Algoritmia
 *
 * @author Héctor Rodríguez Alonso (alu0101365107)
 * @date 26. nov. 2022
 * @brief Práctica 4: Expresiones Regulares
*/

#pragma once

#include <iostream>
#include <regex>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>

// Esctructura la cual define un comentario
typedef struct {
  std::string comentario = "";
  int lineaC = 0;
  int lineaF = 0;
} comentario;

// Esctructura la cual define un bucle
typedef struct {
  std::string tipo = "";
  int linea = 0;
} bucle;

// Esctructura la cual define una variable
typedef struct {
  std::string tipo = "";
  std::string nombre = "";
  int linea = 0;
} variable;

// Clase la cual gestiona el contenido de un fichero y lo analiza en busqueda
// de bloques de comentarios, bucles, comentarios simples, variables y si posee main
class Fichero {
  public:
    Fichero(std::ifstream& fichero_entrada, std::string entrada_nombre_programa);
    ~Fichero();
    std::string GetAnalisis();
  private:
    bool LeerBloqueComentario(std::ifstream& fichero, std::string entrada);
    void IsMain(std::string entrada);
    bool IsBucle(std::string entrada);
    bool IsComentario(std::string entrada);
    bool IsVariable(std::string entrada);
    bool IsAsignacion(std::string entrada);
    std::vector<std::string> contenido_fichero = {""};
    comentario bloque_comentario;
    std::vector<comentario> comentarios = {};
    std::vector<bucle> bucles = {};
    std::vector<variable> variables = {};
    std::string nombre_programa = "";
    bool main = false;
    int linea = 0;
    std::vector<std::string> tipo_bucle = {"for", "while"};
    std::vector<std::string> tipo_variable = {"int", "double"};
    std::vector<std::string> tipo_asignacion = {"\\=", "\\+\\=", "\\-\\=", "\\*\\="};
};