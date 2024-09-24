#include "../library/grafo.h"

Grafo::Grafo(std::string fichero) {
  std::ifstream archivo{fichero};
  std::string linea;
  getline(archivo,linea);
  int vertices = linea[0];
  while (getline(archivo,linea)) {
    std::istringstream iss(eliminarSimbolos(linea));
    int pos1;
    int pos2;
    double coste;
    iss >> coste >> pos1 >> pos2;
    std::cout << "Coste: " << coste << "\n";
    std::cout << "Posiciones: " << pos1 << ", " << pos2 << std::endl;
  }
}
