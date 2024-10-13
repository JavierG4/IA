#include "../library/nodo.h"
#include "../library/tablero.h"

int main(int argc, char* argv[]) {
  std::string archivo = argv[1];
  std::string salida = argv[2];
  Tablero tablero(archivo);
  bool salir = false;
  while (!salir) {
    //Menu
    std::cout << "1. Imprimir tablero en fichero" << std::endl;
    std::cout << "2. Busqueda A*" << std::endl;
    std::cout << "3. Elegir inicio" << std::endl;
    std::cout << "4. Elegir final" << std::endl;
    std::cout << "5. Salir" << std::endl;
    int opcion;
    std::cin >> opcion;
    switch (opcion) {
      case 1:
        tablero.ImprimirEnFichero(salida);
        break;
      case 2:
        tablero.BusquedaA(salida);
        break;
      case 3:
        int x,y;
        std::cout << "Introduce la posición x del inicio" << std::endl;
        std::cin >> x;
        std::cout << "Introduce la posición y del inicio" << std::endl;
        std::cin >> y;
        tablero.Set_inicial(x,y);
        break;
      case 4:
        int x1,y1;
        std::cout << "Introduce la posición x del final" << std::endl;
        std::cin >> x1;
        std::cout << "Introduce la posición y del final" << std::endl;
        std::cin >> y1;
        tablero.Set_final(x1,y1);
        break;
      case 5:
        return 0;
        break;
      default:
        std::cout << "Opción no válida" << std::endl;
        break;
    }
  }
  return 0;
}