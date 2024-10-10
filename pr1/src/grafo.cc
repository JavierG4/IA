#include "../library/grafo.h"

Grafo::Grafo(std::string fichero) {
  std::ifstream archivo{fichero};
  int num_vertices;
  archivo >> num_vertices;
  n_aristas_ = 0;

  aristas_.resize(num_vertices);
  for (int i = 0; i < num_vertices; ++i) {
    for (int j = i + 1; j < num_vertices; ++j) {
      std::string coste_str;
      int coste;
      archivo >> coste_str;
      coste_str.erase(std::remove(coste_str.begin(), coste_str.end(), '.'), coste_str.end());
      coste_str.erase(std::remove(coste_str.begin(), coste_str.end(), ','), coste_str.end());
      //std::cout << coste;
      coste = std::stod(coste_str);
      // Crear aristas
      if (coste > 0) {
        //std::cout << "Coste: " << coste << "\n";
        //std::cout << "Posiciones: " << i + 1 << ", " << j + 1 << std::endl;
        Arista* arista = new Arista(coste, i + 1, j + 1);
        aristas_[i].push_back(arista);
        Arista* arista2 = new Arista(coste, j + 1, i + 1);
        aristas_[j].push_back(arista2);
        n_aristas_++;
      }
    }
  }
  archivo.close();
}


void Grafo::Visualizar() {
  std::cout << aristas_.size() << std::endl;
  for (int i = 0; i < aristas_.size(); i++) {
    for (int j = 0; j < aristas_[i].size(); j++) {
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
  std::ofstream archivo("salida.txt", std::ios::out);

  std::cout << "--------------------------------------------------------------------------------------" << std::endl;
  archivo << "--------------------------------------------------------------------------------------" << std::endl;

  std::cout << "Número de nodos del Grafo: " << aristas_.size() << std::endl;
  archivo << "Número de nodos del Grafo: " << aristas_.size() << std::endl;

  std::cout << "Numero de aristas: " << n_aristas_ << std::endl;
  archivo << "Numero de aristas: " << n_aristas_ << std::endl;

  std::cout << "Nodo Inicial: " << inicio << std::endl;
  archivo << "Nodo Inicial: " << inicio << std::endl;

  std::cout << "Nodo Final: " << destino << std::endl;
  archivo << "Nodo Final: " << destino << std::endl;

  std::cout << "--------------------------------------------------------------------------------------" << std::endl;
  archivo << "--------------------------------------------------------------------------------------" << std::endl;

  while (!proximos.empty()) {
    // Imprimo datos de cada iteracion
    std::cout << "Iteración " << contador << std::endl;
    archivo << "Iteración " << contador << std::endl;

    std::cout << "Nodos generados: ";
    archivo << "Nodos generados: ";
    for (int i = 0; i < generados.size(); i++) {
      if( i == generados.size() - 1) {
        std::cout << generados[i];
        archivo << generados[i];
      } else {
        std::cout << generados[i] << ", ";
        archivo << generados[i] << ", ";
      }
    }
    std::cout << std::endl;
    archivo << std::endl;

    std::cout << "Nodos Inspeccionados: ";
    archivo << "Nodos Inspeccionados: ";
    if (inspeccionados.size() == 0) {
      std::cout << "-";
      archivo << "-";
    } else {
      for (int i = 0; i < inspeccionados.size(); i++) {
        if( i == inspeccionados.size() - 1) {
          std::cout << inspeccionados[i];
          archivo << inspeccionados[i];
        } else {
        std::cout << inspeccionados[i] << ", ";
        archivo << inspeccionados[i] << ", ";
        }
      }
    }
    std::cout << std::endl;
    archivo << std::endl;
    std::cout << "--------------------------------------------------------------------------------------" << std::endl;
    archivo << "--------------------------------------------------------------------------------------" << std::endl;
    
    //std::cout << "pepe" << std::endl;
    // Sacamos de la cola el front y metemos en inspeccionados
    Nodo* top = proximos.front();
    proximos.pop();
    inspeccionados.push_back(top->Get_numero());
    if (top->Get_numero() == destino) {
      int resultado = 0;
      std::vector<int> camino;
      camino.push_back(top->Get_numero());
      Nodo* padre = top->Get_padre();
      Nodo* temporal = top;
      while(padre != nullptr) {
        camino.push_back(padre->Get_numero());
        resultado = resultado + Camino(temporal->Get_numero(),padre->Get_numero());
        temporal = padre;
        padre = padre->Get_padre();
      }
      std::cout << "Recorrido ";
      for (int i = camino.size() - 1; i >= 0; i--) {
        archivo << camino[i] << " - ";
        std::cout << camino[i] << " - ";
      }
      std::cout << std::endl;
      archivo << std::endl;
      std::cout << "--------------------------------------------------------------------------------------" << std::endl;
      archivo << "--------------------------------------------------------------------------------------" << std::endl;
      std::cout << "Coste " << resultado << std::endl;
      std::cout << "--------------------------------------------------------------------------------------" << std::endl;
      archivo << "--------------------------------------------------------------------------------------" << std::endl;
      std::cout << std::endl;
      return;
    }
    //std::cout << "pepe2" << std::endl;
    // Recorremos las aristas del front
    for (int i = 0; i < aristas_[top->Get_numero() -1].size(); i++) {
      //std::cout << i;
      int hijo = aristas_[top->Get_numero() -1][i]->Get_destino();

      if (!top->Visitado(hijo)) { // Duda ¿ Añadimos el sucesor solo si no estaba ya antes en la rama para evitar bucles infinitos? Se para cuando se inspecciona el final y sucesores
        // Creamos este nuevo nodo
        //std::cout << "Entrando" << std::endl;
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
    contador++;
  }
  std::cout << "No se ha encontrado camino" << std::endl;
  archivo << "No se ha encontrado camino" << std::endl;
}

void Grafo::RecorridoProfundidad(int destino,int inicio) {
  // Para liberar memoria, tenemos que comprobar si un nodo ya hemos
  // inspeccionado sus sucesores si es así liberamos esos nodos
  std::vector<int> generados; // Tienes que poner todos los generados 
  std::vector<int> inspeccionados; // Se escriben lo sucesores de un nodo cuando lo inspeccionas, no cuando lo generas
  std::stack<Nodo*> proximos;

  Nodo* Inicial = new Nodo(inicio);
  vertices_.push_back(Inicial);
  proximos.push(Inicial);
  generados.push_back(inicio);
  int contador = 1;

  std::ofstream archivo("salida.txt", std::ios::out);

  std::cout << "--------------------------------------------------------------------------------------" << std::endl;
  archivo << "--------------------------------------------------------------------------------------" << std::endl;

  std::cout << "Número de nodos del Grafo: " << aristas_.size() << std::endl;
  archivo << "Número de nodos del Grafo: " << aristas_.size() << std::endl;

  std::cout << "Numero de aristas: " << n_aristas_ << std::endl;
  archivo << "Numero de aristas: " << n_aristas_ << std::endl;

  std::cout << "Nodo Inicial: " << inicio << std::endl;
  archivo << "Nodo Inicial: " << inicio << std::endl;

  std::cout << "Nodo Final: " << destino << std::endl;
  archivo << "Nodo Final: " << destino << std::endl;

  std::cout << "--------------------------------------------------------------------------------------" << std::endl;
  archivo << "--------------------------------------------------------------------------------------" << std::endl;

  while (!proximos.empty()) {

    // Imprimo datos de cada iteracion
    std::cout << "Iteración " << contador << std::endl;
    archivo << "Iteración " << contador << std::endl;

    std::cout << "Nodos generados: ";
    archivo << "Nodos generados: ";
    for (int i = 0; i < generados.size(); i++) {
      if (i == generados.size() - 1) {
        std::cout << generados[i];
        archivo << generados[i];
      } else {
      std::cout << generados[i] << ", ";
      archivo << generados[i] << ", ";
      }
    }
    std::cout << std::endl;
    archivo << std::endl;

    std::cout << "Nodos Inspeccionados: ";
    archivo << "Nodos Inspeccionados: ";
    if (inspeccionados.size() == 0) {
      std::cout << "-";
      archivo << "-";
    } else {
      for (int i = 0; i < inspeccionados.size(); i++) {
        if (i == inspeccionados.size() - 1) {
          std::cout << inspeccionados[i];
          archivo << inspeccionados[i];
        } else {
        std::cout << inspeccionados[i] << ", ";
        archivo << inspeccionados[i] << ", ";
        }
      }
    }
    std::cout << std::endl;
    archivo << std::endl;
    std::cout << "--------------------------------------------------------------------------------------" << std::endl;
    archivo << "--------------------------------------------------------------------------------------" << std::endl;
    
    //std::cout << "pepe" << std::endl;
    // Sacamos de la cola el front y metemos en inspeccionados
    Nodo* top = proximos.top();
    proximos.pop();
    inspeccionados.push_back(top->Get_numero());

    // Comprobamos si es el final
    if (top->Get_numero() == destino) {
      int resultado = 0;
      std::vector<int> camino;
      camino.push_back(top->Get_numero());
      Nodo* padre = top->Get_padre();
      Nodo* temporal = top;
      while(padre != nullptr) {
        camino.push_back(padre->Get_numero());
        resultado = resultado + Camino(temporal->Get_numero(),padre->Get_numero());
        temporal = padre;
        padre = padre->Get_padre();
      }
      std::cout << "Recorrido ";
      archivo << "Recorrido ";
      for (int i = camino.size() - 1; i >= 0;i--){
        archivo << camino[i] << " - ";
        std::cout << camino[i] << " - ";
      }
      std::cout << std::endl;
      archivo << std::endl;
      std::cout << "--------------------------------------------------------------------------------------" << std::endl;
      archivo << "--------------------------------------------------------------------------------------" << std::endl;
      std::cout << "Coste " << resultado << std::endl;
      archivo << "Coste " << resultado << std::endl;
      archivo << std::endl;
      std::cout << std::endl;
      std::cout << "--------------------------------------------------------------------------------------" << std::endl;
      archivo << "--------------------------------------------------------------------------------------" << std::endl;
      return;
    }
    // Recorremos las aristas del front
    for (int i = aristas_[top->Get_numero() - 1].size() - 1; i >= 0; i--) {
      int hijo = aristas_[top->Get_numero() -1][i]->Get_destino();

      if (!top->Visitado(hijo)) { // Duda ¿ Añadimos el sucesor solo si no estaba ya antes en la rama para evitar bucles infinitos? Se para cuando se inspecciona el final y sucesores
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
    contador++;
  }
  std::cout << "No se ha encontrado camino" << std::endl;
  archivo << "No se ha encontrado camino" << std::endl;
}


int Grafo::Camino(int inicio,int final) {
  //std::cout << "camnino " << inicio << "-" << final << std::endl;
  for ( int i = 0; i < aristas_[inicio -1].size(); i++) {
    if (aristas_[inicio-1][i]->Get_destino() == final) {
      //std::cout << aristas_[inicio-1][i]->Get_coste() << std::endl;
      return aristas_[inicio-1][i]->Get_coste();
    }
  }
  return 0;
}