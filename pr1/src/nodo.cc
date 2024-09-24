#include "../library/nodo.h"

Nodo::Nodo(int numero) {
  padre_ = nullptr;
  numero_ = numero;
}

void Nodo::Set_hijo(Nodo* hijo) {
  hijo_.push_back(hijo);
}