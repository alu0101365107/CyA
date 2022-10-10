#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <fstream>
#include "simbolo.h"

std::string LeerSimbolosFichero(std::string entrada);
std::vector<Simbolo> LeerCadenaFichero(std::string entrada);
int ContadorEspacios(std::string entrada);