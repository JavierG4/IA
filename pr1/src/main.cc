#include<iostream>
#include<fstream>
#include "../library/grafo.h"
#include "../library/arista.h"
#include "../library/nodo.h"

int main(int argc, char* argv[]) {
  std::string nombre_archivo = argv[1];
  Grafo Arbol(nombre_archivo);
  Arbol.Visualizar();
  int inicial, final;
  bool decision;
  std::cout << "Que recorrido quieres hacer, pulse 0 amplitud, 1 profundidad" << std::endl;
  std::cin >> decision;
  // Se debería comporbar si es un nodo posible
  std::cout << "Cual va a ser tu nodo inicial" << std::endl;
  std::cin >> inicial;
  std::cout << "Cual va a ser tu nodo Final" << std::endl;
  std::cin >> final;
  
  if (decision == 0) {
    Arbol.RecorridoAmplitud(final,inicial);
  } else {
    Arbol.RecorridoProfundidad(final,inicial);
  }
  return 0;
}