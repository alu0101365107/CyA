// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 09/11/2022
// Archivo automata.h: Encargado de la definicion de la clase Automata, además de las estructura de una
//                     transición y nodo


#pragma once
#include <set>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
#include "alfabeto.h"
#include "simbolo.h"
#include <assert.h>


typedef struct {
  std::string simbolo = "";
  int estado;
  bool check = false;
} estructura_transicion;


typedef struct {
  bool aceptacion;
  int nombre_estado;
  std::vector<estructura_transicion> transiciones = {};
} nodo;


class Automata {
  public:
    Automata(Alfabeto alfabeto);
    ~Automata();
    Automata();
    void AddEstados(nodo estado);
    void SetNumerosEstado(int numero_estados);
    void SetEstadoArranque(int estado_aceptacion);
    void SetAlfabeto(Alfabeto alfabeto);
    bool RunAutomata(std::vector<Simbolo> cadena);
    void Print();
    int GetNumeroEstadosMax();
    int GetNumeroEstados();
  private:
    Alfabeto alfabeto;
    bool dfa;
    int numero_estados;
    int estado_arranque;
    std::vector<nodo> estados;
    int Find(nodo estado);
    bool AnalizarAutomata();
    void RunNFA(int estado_next, int contador_veces);
    std::vector<estructura_transicion> GetTransiciones(nodo estado_entrada);
    std::vector<std::vector<std::string>> posibles_soluciones = {};
};
