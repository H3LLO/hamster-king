#include "Hexes/Hexes.h"
#include <iostream>

void PopulateHexGrid(Hexes::HexGrid hg);
void PrintHexGrid(Hexes::HexGrid hg);

int rows = 10;
int cols = 10;

int main() {
 Hexes::HexGrid* hg = new Hexes::HexGrid(rows, cols);
 PopulateHexGrid(*hg);
 PrintHexGrid(*hg);
 return 0;
}

void PopulateHexGrid(Hexes::HexGrid hg) {
 char* types = new char[3] {'a','b','c'};
 for (int i = 0; i < rows; i++) 
  for (int j = 0; j < cols; j++) {
   Hexes::HexCell hc;
   hc.type = types[(i + (j % 2 * 2)) % 3];
   //if (!((i % 10) && (j % 10))) std::cout << i << '-' << j << '-' << (i + (j % 2 * 2)) % 3 << ':' << hc.type << std::endl;
   hg.ArrMutate(hc, j, i);
  }
}

void PrintHexGrid(Hexes::HexGrid hg) {
 for (int j = 0; j < cols; j++) {
  if(j%2) std::cout << " ";
  for (int i = 0; i < rows; i++) {
   std::cout << hg.ArrAccess(j, i).type << " ";
  }
  std::cout << std::endl;
 }
}
