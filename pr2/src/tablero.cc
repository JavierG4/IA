#include "../library/tablero.h"
// "█" = 1

#include <iostream>
#include <vector>
#include <fstream>

/**
 * @brief Imprime el laberinto en la consola y en un archivo.
 * @param laberinto Vector de vectores que representa el laberinto.
 * @param nombre_fichero Nombre del archivo donde se imprimirá el laberinto.
 */
void ImprimirLaberinto(const std::vector<std::vector<int>>& laberinto, const std::string& nombre_fichero) {
  std::ofstream archivo(nombre_fichero);
  if (!archivo) {
    std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
    return;
  }

  int filas = laberinto.size();
  int columnas = laberinto[0].size();

  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      if (laberinto[i][j] == 1) {
        std::cout << "█";  // Para representar el cuadro negro
        archivo << "█";
      } else if (laberinto[i][j] == 0) {
        std::cout << " ";  // Para representar el cuadro blanco
        archivo << " ";
      } else if(laberinto[i][j] == 2) {
          std::cout << "*";  // Para representar el cuadro blanco
          archivo << "*";
      } else if (laberinto[i][j] == 3) {
        std::cout << "E";  // Para representar la salida "E"
        archivo << "E";
      } else if (laberinto[i][j] == 4) {
        std::cout << "S";  // Para representar el inicio "S"
        archivo << "S";
      }
    }
    std::cout << std::endl;  // Salto de línea al final de cada fila
    archivo << std::endl;
  }

  archivo.close();
}

void ImprimirIteracion(int contador, const std::set<Nodo*>& abierto, const std::set<Nodo*>& cerrados) {
  // Abre un archivo para escribir los datos en modo de sobrescritura
  std::ofstream archivo("salida.txt", std::ios::app);

  // Imprimir en la consola
  std::cout << "Iteración " << contador << std::endl;
  std::cout << "Abiertos: " << std::endl;
  for (auto c : abierto) {
    std::cout << "Nodo: (" << c->Get_posx() << "," << c->Get_posy() << ") f: " << c->Get_f() << " g: " << c->Get_g() << " h: " << c->Get_h() << std::endl;
  }
  std::cout << "Cerrados: " << std::endl;
  for (auto c : cerrados) {
    std::cout << "Nodo: (" << c->Get_posx() << "," << c->Get_posy() << ") f: " << c->Get_f() << " g: " << c->Get_g() << " h: " << c->Get_h() << std::endl;
  }

  // Imprimir en el archivo
  archivo << "Iteración " << contador << std::endl;
  archivo << "Abiertos: " << std::endl;
  for (auto c : abierto) {
    archivo << "Nodo: (" << c->Get_posx() << "," << c->Get_posy() << ") f: " << c->Get_f() << " g: " << c->Get_g() << " h: " << c->Get_h() << std::endl;
  }
  archivo << "Cerrados: " << std::endl;
  for (auto c : cerrados) {
    archivo << "Nodo: (" << c->Get_posx() << "," << c->Get_posy() << ") f: " << c->Get_f() << " g: " << c->Get_g() << " h: " << c->Get_h() << std::endl;
  }

  // Cierra el archivo
  archivo.close();
}
Tablero::Tablero(std::string nombre_archivo) {
  std::ifstream archivo(nombre_archivo);
  if (!archivo) {
    throw std::logic_error("No se pudo abrir el archivo: " + nombre_archivo);
  }

  int filas, columnas;
  archivo >> filas >> columnas;
  tablero_.resize(filas, std::vector<int>(columnas));

  for (int i = 0; i < filas; ++i) {
    for (int j = 0; j < columnas; ++j) {
      int casilla;
      archivo >> casilla;
      tablero_[i][j] = casilla;
      if (casilla == 3 ) {
        //std::cout << "Encontrado el inicio" << std::endl;
        //std::cout << "Posición: " << i << " " << j << std::endl;
        inicialx_ = i;
        inicialy_ = j;
      } else if ( casilla == 4) {
        finalx_ = i;
        finaly_ = j;
      }
    }
  }

  archivo.close();
}

void Tablero::ImprimirEnFichero(std::string nombre_fichero) {
  std::ofstream archivo(nombre_fichero);
  if (!archivo) {
    std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
    return;
  }
  archivo << tablero_.size() << std::endl;
  archivo << tablero_[0].size() << std::endl;

  for (const auto& fila : tablero_) {
    for (const auto& elemento : fila) {
      archivo << elemento << " ";
    }
    archivo << "\n";
  }

  archivo.close();
}

void Tablero::BusquedaA() {
  std::set<Nodo*> cerrados;
  std::set<Nodo*> abierto;
  // Creo nodo inicial
  Nodo* inicial = new Nodo(inicialx_,inicialy_);
  //Añadimos el nodo inicial al vector y sus funciones
  abierto.insert(inicial);
  int h = Calcular_h(inicialx_,inicialy_);
  int f = Calcular_f(0,inicialx_,inicialy_);
  inicial->Set_f(f);
  inicial->Set_h(h);
  inicial->Set_g(0);
  int contador = 1;
  while (!abierto.empty()) {
    // Imprimir cada iteración
    ImprimirIteracion(contador, abierto, cerrados);
    //std::cout << "tamaño abierto: " << abierto.size() << std::endl; 
  // Encontramos el menor f en abiertos (2.a)
    int menor_f = 99999999;
    Nodo* nodo = nullptr;
    for ( auto c : abierto ) {
      int f = c->Get_f();
      if ( menor_f > f ) {
        nodo = c;
        menor_f = f;
      }
    }
    // Verificamos si el nodo final está en abiertos con un menor f
    for (auto c : cerrados) {
      if (c->Get_posx() == finalx_ && c->Get_posy() == finaly_ && c->Get_f() <= menor_f) {
        nodo = c;
        menor_f = c->Get_f();
        break;
      }
    }


  //Comprobamos si es el final con el menor f(N)
    if (nodo->Get_posx() == finalx_ && nodo->Get_posy() == finaly_) {
      std::cout << "Hemos llegado al final" << std::endl;
      std::vector<std::vector<int>> tablero = tablero_;
      Nodo* aux = nodo;
      while (aux->Get_padre() != nullptr) {
        tablero[aux->Get_posx()][aux->Get_posy()] = 2;
        aux = aux->Get_padre();
      }
      tablero[finalx_][finaly_] = 4;
      //std::cout << "Copito " << std::endl;
      ImprimirLaberinto(tablero, "salida.txt");
      //Destructor
      for (auto c : cerrados) {
        delete c;
      }
      for ( auto c : abierto ) {
        delete c;
      }
      return;
    }
  // sacamos el nodo de abiertos y lo metemos en cerrados
    abierto.erase(nodo);
    cerrados.insert(nodo);
  // Calculamos los hijos y los añadimos a la lista de abiertos si no estan en cerrados
  // Si encontramos un nodo que ya esta en el vector de abiertos, comprobamos si el nuevo camino es mejor
  // (2.b)
    int posx = nodo->Get_posx();
    int posy = nodo->Get_posy();

    // Direcciones posibles (8 direcciones)
    int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
    int costos[8] = {5, 5, 5, 5, 7, 7, 7, 7}; // Costos correspondientes a cada dirección
    // Recorremos las 8 direcciones
    for (int i = 0; i < 8; ++i) {
      int new_x = posx + dx[i];
      int new_y = posy + dy[i];

      // Verificamos si la nueva posición está dentro de los límites y no es un obstáculo
      if (new_x >= 0 && new_x < tablero_.size() && new_y >= 0 && new_y < tablero_[0].size() && (tablero_[new_x][new_y] != 1 )) {
        Nodo* hijo = new Nodo(new_x, new_y);
        hijo->Set_padre(nodo);
        int g = nodo->Get_g() + costos[i]; // Movimiento de coste 5 o 7
        int h = Calcular_h(new_x, new_y);
        int f = Calcular_f(g, new_x, new_y);
        hijo->Set_g(g);
        hijo->Set_h(h);
        hijo->Set_f(f);
        bool encontrado = false;
        bool peor = false; // El que ya está en abiertos es peor
        // Compruebo si esta en cerrados y si es mejor
        for ( auto c : cerrados ) {
          if ( c->Get_posx() == new_x && c->Get_posy() == new_y ) {
            encontrado = true;
            break;
          }
        }
        if (!encontrado ) { 
          for (auto c : abierto) {
            if (c->Get_posx() == new_x && c->Get_posy() == new_y) {
              if (c->Get_f() > f) {
                c->Set_f(f);
                c->Set_g(g);
                c->Set_h(h);
                c->Set_padre(nodo);
                peor = false;
              }
              encontrado = true;
              peor = true;
              break;
            }
          }
        }
        // Si no esta en ningun vector lo añado
        if ( !encontrado ) {
          if (hijo->Visitado()) { // Preveo bucles viendo
            delete hijo;
          } else {
            abierto.insert(hijo);
          }
        // Si ya estaba y el que estaba es peor
        } else if ( encontrado && !peor ) {
          delete hijo;
        }
      }
    }
    contador++;
  }
  std::cout << "No se ha encontrado solución" << std::endl;
  //Destructor
  for (auto c : cerrados) {
    delete c;
  }
  for ( auto c : abierto ) {
    delete c;
  }
}

int Tablero::Calcular_h(int xE, int yE) {
  const int W = 3;
  int distancia_manhattan = std::abs(xE - finalx_) + std::abs(yE - finaly_);
  return distancia_manhattan * W;
}

int Tablero::Calcular_f(int costeg, int posx, int posy) {
  int coste_h = Calcular_h(posx,posy);
  return costeg + coste_h;
}