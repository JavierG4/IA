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
   Nodo(int, int);

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
   bool Visitado();
   void Set_pos(int,int);
   int Get_posx() const{return posx_;}
   int Get_posy() const {return posy_;}
   int Get_g() const {return g_;}
   void Set_g(int g) {g_ = g;}
   int Get_f() const {return f_;}
   void Set_f(int f) {f_ = f;}
   int Get_h() const {return h_;}
   void Set_h(int h) {h_ = h;} 

 private:
   std::vector<Nodo*> hijo_; ///< Vector de punteros a los nodos hijos.
   Nodo* padre_; ///< Puntero al nodo padre.
   int g_; // Coste acumulado hasta el nodo
   int f_; // g + h
   int h_; // Funcion eurística
   int posx_;
   int posy_;
};