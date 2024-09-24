#include "../library/arista.h"


Arista::Arista(double coste, Nodo* origen, Nodo* destino) {
  coste_ = coste;
  origen_ = origen;
  destino_ = destino;
}

void Arista::Ver_arista() {
  if (origen_ && destino_) {
    std::cout << "Coste " << coste_ << std::endl;
    std::cout << "d( " << origen_->Get_numero() << " ," << destino_->Get_numero() << " )" << std::endl;
  } else {
    std::cerr << "Error: Origen o destino es nullptr" << std::endl;
  }
}