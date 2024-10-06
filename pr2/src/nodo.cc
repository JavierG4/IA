#include "../library/nodo.h"

Nodo::Nodo(int inicialx, int inicialy) {
  posx_ = inicialx;
  posy_ = inicialy;
  padre_ = nullptr;
}

void Nodo::Set_hijo(Nodo* hijo) {
  hijo_.push_back(hijo);
}


void Nodo::Set_padre(Nodo* padre) {
  padre_ = padre;
}

void Nodo::Set_pos(int x, int y) {
  posx_ = x;
  posy_ = y;
}

bool Nodo::Visitado() {
  Nodo* padre = padre_;
  while (padre != nullptr) {
    if (posx_ == padre->Get_posx() && posy_ == padre->Get_posy()) {
      return true;
    }
    padre = padre->Get_padre();
  }
  return false;
}