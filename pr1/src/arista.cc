#include "../library/arista.h"


Arista::Arista(int coste,int origen,int destino) {
  coste_ = coste;
  origen_ = origen;
  destino_ = destino;
}

void Arista::Ver_arista() {
  if (origen_ && destino_ != 0) {
    std::cout << "Coste " << coste_ << std::endl;
    std::cout << "d( " << origen_ << " ," << destino_ << " )" << std::endl;
  } else {
    std::cerr << "Error: Origen o destino es nullptr" << std::endl;
  }
}
