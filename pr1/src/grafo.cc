#include "../library/grafo.h"

Grafo::Grafo(std::string fichero) {
  std::ifstream archivo{fichero};
  std::string linea;
  getline(archivo,linea);
  std::cout << linea << std::endl;
  int vertices = std::stoi(linea.substr(0, 1));
  // Inicializar los nodos
  for ( int i = 0 ; i < vertices; i++) {
    Nodo* nodo = new Nodo(i + 1);
    vertices_.push_back(nodo);
  }

  std::cout << vertices_.size() << std::endl;
  aristas_.resize(vertices);
  while (getline(archivo,linea)) {
    std::cout << linea << std::endl;
    std::string resultado = eliminarSimbolos(linea);
    std::istringstream iss(resultado);
    int pos1;
    int pos2;
    double coste;
    iss >> coste >> pos1 >> pos2;

    //Crear aristas
    if ( coste != 0 ) {
      std::cout << "Coste: " << coste << "\n";
      std::cout << "Posiciones: " << pos1 << ", " << pos2 << std::endl;
      Arista* arista = new Arista(coste, Get_nodo(pos1), Get_nodo(pos2));
      aristas_[pos1 - 1].push_back(arista);
      Arista* arista2 = new Arista(coste, Get_nodo(pos2), Get_nodo(pos1));
      aristas_[pos2 - 1].push_back(arista2);
    }
  }
}

Nodo* Grafo::Get_nodo(int x) {
  return vertices_[x - 1];
}

void Grafo::Visualizar(){
  for (int i = 0; i < vertices_.size(); i++) {
    std::cout << "Nodo " << i << " " << vertices_[i] -> Get_hijo().size() << std::endl;
    std::cout << vertices_[i] -> Get_numero() << std::endl;
  }
  for ( int i = 0 ; i < aristas_.size(); i++) {
    for ( int j = 0 ; j < aristas_[i].size(); j++) {
      aristas_[i][j]->Ver_arista();
    }
  }
}

Grafo::~Grafo () {
  for (Nodo* nodo : vertices_) {
    delete nodo;
  }
  for (auto& listaAristas : aristas_) {
    for (Arista* arista : listaAristas) {
      delete arista;
    }
  }
}