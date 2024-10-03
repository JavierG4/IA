#pragma once

#include <iostream>
#include <vector>

#pragma once

#include <iostream>
#include <vector>

/**
 * @class Nodo
 * @brief Representa un nodo en un grafo.
 */
class Nodo {
 public:
   /**
    * @brief Constructor que inicializa un nodo con un número.
    * @param numero Número del nodo.
    */
   Nodo(int numero);

   /**
    * @brief Obtiene el número del nodo.
    * @return Número del nodo.
    */
   int Get_numero() { return numero_; }

   /**
    * @brief Obtiene los hijos del nodo.
    * @return Vector de punteros a los nodos hijos.
    */
   std::vector<Nodo*> Get_hijo() { return hijo_; }

   /**
    * @brief Obtiene el padre del nodo.
    * @return Puntero al nodo padre.
    */
   Nodo* Get_padre() { return padre_; }

   /**
    * @brief Establece un hijo para el nodo.
    * @param hijo Puntero al nodo hijo.
    */
   void Set_hijo(Nodo* hijo);

   /**
    * @brief Establece el padre del nodo.
    * @param padre Puntero al nodo padre.
    */
   void Set_padre(Nodo* padre);

   /**
    * @brief Verifica si un nodo ha sido visitado.
    * @param encontrar Número del nodo a verificar.
    * @return true si el nodo ha sido visitado, false en caso contrario.
    */
   bool Visitado(int encontrar);

 private:
   int numero_; ///< Número del nodo.
   std::vector<Nodo*> hijo_; ///< Vector de punteros a los nodos hijos.
   Nodo* padre_; ///< Puntero al nodo padre.
   // profundidad ?
   // Coste acumulado ?
};