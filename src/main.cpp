#include "programa.hpp"

int main() {
	Programa supermercado;

	do {
        supermercado.menu();
	}
	while (supermercado.inicio);

	return 0;
}