#include "../library/nodo.h"
#include "../library/tablero.h"

int main(int argc, char* argv[]) {
  std::string archivo = argv[1];
  Tablero tablero(archivo);
  tablero.ImprimirEnFichero("salida1.txt");
  std::cout << tablero.Get_inicialx() << " " << tablero.Get_inicialy() << std::endl;
  tablero.BusquedaA();

  return 0;
}