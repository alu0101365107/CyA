// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 19/10/2022
// Archivo funciones.h: Encargado de la creación de los métodos para lectura de ficheros y gestion de la pila


#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include "simbolo.h"
#include "cadena.h"
#include "lenguaje.h"
#include <stack>

std::vector<Simbolo> LeerAlfabetoFichero(std::string entrada);
std::vector<Cadena> LeerLenguajeFichero(std::string entrada);
std::string LeerNombreLenguaje(std::string entrada);
Lenguaje GetElementoPila(std::stack<Lenguaje>& pila);