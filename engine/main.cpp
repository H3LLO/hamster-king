#include "Hexes/Hexes.h"
#include <iostream>

void PopulateHexGrid(Hexes::HexGrid<char> hg);
void PrintHexGrid(Hexes::HexGrid<char> hg);

int rows = 10;
int cols = 10;

int main() {
 Hexes::HexGrid<char>* hg = new Hexes::HexGrid<char>(rows, cols);
 PopulateHexGrid(*hg);
 PrintHexGrid(*hg);
 return 0;
}

void PopulateHexGrid(Hexes::HexGrid<char> hg) {
 char* types = new char[3] {'a','b','c'};
 for (int i = 0; i < rows; i++) 
  for (int j = 0; j < cols; j++) {
   char type = types[(i + (j % 2 * 2)) % 3];
   //if (!((i % 10) && (j % 10))) std::cout << i << '-' << j << '-' << (i + (j % 2 * 2)) % 3 << ':' << hc.type << std::endl;
   hg.ArrMutate(type, j, i);
  }
}

void PrintHexGrid(Hexes::HexGrid<char> hg) {
 for (int j = 0; j < cols; j++) {
  if(j%2) std::cout << " ";
  for (int i = 0; i < rows; i++) {
   std::cout << hg.ArrAccess(j, i) << " ";
  }
  std::cout << std::endl;
 }
}
