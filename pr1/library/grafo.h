#pragma once

#include<iostream>
#include<fstream>
#include<vector>
#include "nodo.h"
#include "arista.h"
#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <algorithm> 
#include <stack>


#pragma once

#include "arista.h"
#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>

/**
 * @class Grafo
 * @brief Representa un grafo con nodos y aristas.
 */
class Grafo {
 public:
   /**
    * @brief Constructor que inicializa el grafo a partir de un archivo.
    * @param archivo Nombre del archivo que contiene la definición del grafo.
    */
   Grafo(std::string archivo);

   /**
    * @brief Realiza un recorrido en profundidad (DFS) en el grafo.
    * @param destino Nodo destino del recorrido.
    * @param inicio Nodo inicial del recorrido.
    */
   void RecorridoProfundidad(int destino, int inicio);

   /**
    * @brief Realiza un recorrido en amplitud (BFS) en el grafo.
    * @param destino Nodo destino del recorrido.
    * @param inicio Nodo inicial del recorrido.
    */
   void RecorridoAmplitud(int destino, int inicio);

   /**
    * @brief Destructor que libera la memoria utilizada por el grafo.
    */
   ~Grafo();

   /**
    * @brief Visualiza el grafo.
    */
   void Visualizar();

 private:
   std::vector<Nodo*> vertices_; ///< Vector de punteros a los nodos del grafo.
   std::vector<std::vector<Arista*>> aristas_; ///< Matriz de punteros a las aristas del grafo.
   
   /**
    * @brief Calcula el coste del camino entre dos nodos.
    * @param inicio Nodo inicial.
    * @param final Nodo final.
    * @return Coste del camino entre los nodos.
    */
   int Camino(int inicio, int final);

   /**
    * @brief Verifica si un nodo ha sido visitado.
    * @param nodo Puntero al nodo a verificar.
    * @return true si el nodo ha sido visitado, false en caso contrario.
    */
   bool Visitado(Nodo* nodo);

   int n_aristas_; ///< Número de aristas en el grafo.
};