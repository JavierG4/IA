#include "../library/nodo.h"
#include "../library/tablero.h"

int main(int argc, char* argv[]) {
  std::string archivo = argv[1];
  Tablero tablero(archivo);
  tablero.ImprimirEnFichero("salida.txt");

  return 0;
}