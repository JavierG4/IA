#include "../library/tools.h"

std::string eliminarSimbolos(const std::string& entrada) {
  std::string simbolosAEliminar = "/*d(),=";
  std::string resultado;
  for (char c : entrada) {
    if (c == '-') {
      return "X";
    }
    if (simbolosAEliminar.find(c) == std::string::npos) {
      resultado += c;
    }
  }
  return resultado;
}