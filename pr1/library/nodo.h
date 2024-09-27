#pragma once

#include <iostream>
#include <vector>

class Nodo {
 public:
   Nodo(int);
   int Get_numero() { return numero_;}
   std::vector<Nodo*> Get_hijo() { return hijo_;}
   Nodo* Get_padre() { return padre_;}
   void Set_hijo (Nodo* hijo);
   void Set_padre(Nodo*);
   bool Visitado(int)
   
 private:
   int numero_;
   std::vector<Nodo*> hijo_;
   Nodo* padre_;
   // profundiad ?
   // Coste acumulado ?
};