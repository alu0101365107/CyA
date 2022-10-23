// Autor: Héctor Rodríguez Alonso
// Correo: alu0101365107@ull.es
// Fecha: 12/10/2022
// Archivo funciones.h: Encargado de la creación de los métodos para lectura y escritura de ficheros


#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include "simbolo.h"
#include "cadena.h"
#include "alfabeto.h"
#include "assert.h"

std::vector<Simbolo> LeerAlfabetoFichero(std::string entrada);
std::vector<Cadena> LeerLenguajeFichero(std::string entrada, Alfabeto alfabeto);
void EscribirFichero(std::ofstream& fichero_escritura, std::string entrada);