#include "../library/nodo.h"

Nodo::Nodo(int numero) {
  numero_ = numero;
  padre_ = nullptr;
}

void Nodo::Set_hijo(Nodo* hijo) {
  hijo_.push_back(hijo);
}

bool Nodo::Visitado(int econtrar) {
  Nodo* Este = this;
  Nodo* nodo = Este;
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