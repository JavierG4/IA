#include "../library/nodo.h"

Nodo::Nodo(int inicialx, int inicialy) {
  posx_ = inicialx;
  posy_ = inicialy;
  padre_ = nullptr;
}

void Nodo::Set_hijo(Nodo* hijo) {
  hijo_.push_back(hijo);
}

bool Nodo::Visitado(int econtrar) {
  //std::cout << "Visitando" << numero_ << std::endl;
  Nodo* nodo = this;
  while (nodo->Get_padre() != nullptr) {
    if (nodo->Get_padre()->Get_numero() == econtrar ) {
      return true;
    }
    nodo = nodo->Get_padre();
  }
  return false;
}

void Nodo::Set_padre(Nodo* padre) {
  padre_ = padre;
}

void Nodo::Set_pos(int x, int y) {
  posx_ = x;
  posy_ = y;
}