#include "../library/grafo.h"

Grafo::Grafo(std::string fichero) {
  std::ifstream archivo{fichero};
  int num_vertices;
  archivo >> num_vertices;

  aristas_.resize(num_vertices);
  for (int i = 0; i < num_vertices; ++i) {
    for (int j = i + 1; j < num_vertices; ++j) {
      int coste;
      archivo >> coste;

      // Crear aristas
      if (coste != -1) {
        //std::cout << "Coste: " << coste << "\n";
        //std::cout << "Posiciones: " << i + 1 << ", " << j + 1 << std::endl;
        Arista* arista = new Arista(coste, i + 1, j + 1);
        aristas_[i].push_back(arista);
        Arista* arista2 = new Arista(coste, j + 1, i + 1);
        aristas_[j].push_back(arista2);
      }
    }
  }
  archivo.close();
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

void Grafo::RecorridoAmplitud(int destino, int inicio) {
  std::vector<int> generados; // Tienes que poner todos los generados 
  std::vector<int> inspeccionados; // Se escriben lo sucesores de un nodo cuando lo inspeccionas, no cuando lo generas
  std::queue<Nodo*> proximos;

  Nodo* Inicial = new Nodo(inicio);
  vertices_.push_back(Inicial);
  proximos.push(Inicial);
  generados.push_back(inicio);
  int contador = 1;

  while (!proximos.empty()) {
    std::cout << "Iteración " << contador << std::endl;
    std::cout << "Nodos generados: ";
    for ( int i = 0; i < generados.size(); i++) {
      std::cout << generados[i] << ", ";
    }
    std::cout << std::endl;
    std::cout << "Nodos Inspeccionados: ";
    if (inspeccionados.size() == 0) {
      std::cout << "-";
    } else {
      for ( int i = 0; i < inspeccionados.size(); i++) {
        std::cout << inspeccionados[i] << ", ";
      }
    }
    std::cout << std::endl;
    
    // Sacamos de la cola el front y metemos en inspeccionados
    Nodo* top = proximos.front();
    proximos.pop();
    inspeccionados.push_back(top->Get_numero());
    if (top->Get_numero() == destino) {
      int resultado = 0;
      std::vector<int> camino;
      camino.push_back(top->Get_numero());
      Nodo* padre = top->Get_padre();
      while(padre != nullptr) {
        camino.push_back(padre->Get_numero());
        resultado =+ Camino(top->Get_numero(),padre->Get_numero());
        padre = padre->Get_padre();
      }
      //Imprimir resultado final... y break
    }
    // Recorremos las aristas del front
    for (int i = 0; i < aristas_[top->Get_numero() -1].size(); i++) {
      int hijo = aristas_[top->Get_numero() -1][i]->Get_destino();

      if (top->Visitado(hijo)) { // Duda ¿ Añadimos el sucesor solo si no estaba ya antes en la rama para evitar bucles infinitos? Se para cuando se inspecciona el final y sucesores
        // Creamos este nuevo nodo
        Nodo* nuevo_nodo = new Nodo (hijo);
        //Destructor...
        vertices_.push_back(nuevo_nodo);
        //Hacemos un set del Padre a este nuevo nodo creado
        nuevo_nodo->Set_padre(top);
        //Metemos en la cola este nuevo nodo que no ha sidp visitado
        proximos.push(nuevo_nodo);
        //Añadimos numero del nodo generado
        generados.push_back(hijo);
        // Añadimos sucesor al nodo inspeccionado
        top->Set_hijo(nuevo_nodo);

      }
    }

  }
}

void Grafo::RecorridoProfundidad(int final,int inicio) {
  // Para liberar memoria, tenemos que comprobar si un nodo ya hemos
  // inspeccionado sus sucesores si es así liberamos esos nodos
}


int Grafo::Camino(int inicio,int final) {
  for ( int i = 0; i < aristas_[inicio -1].size(); i++) {
    if (aristas_[inicio-1][i]->Get_destino() == final) {
      return aristas_[inicio-1][i]->Get_coste();
    }
  }
  return 0;
}