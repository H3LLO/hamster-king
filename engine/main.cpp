#include "Debug/Debug.h" //gives malloc to be used straight
#include "Hexes/Hexes.h"
#include <iostream>
#include <set>

void PopulateHexGrid(Hexes::HexGrid<char>* &hg);
void DrawStuff(Hexes::HexGrid<char>* &hg, int q, int r, int toEdge, bool flipped);
void PrintHexGrid(Hexes::HexGrid<char>* &hg);

int rows = 10;
int cols = 40;

int main(int argc, char* argv[]) {
 try {
 Hexes::HexGrid<char>* hg = new Hexes::HexGrid<char>(rows, cols);
 PopulateHexGrid(hg);
 hg->debug = true;
 DrawStuff(hg, cols/2, rows/2, 2, true);
 hg->debug = false;
 PrintHexGrid(hg);
 hg->Dispose();
 }
 catch (exception& stop) {
  return stop.error_code;
 }
 return 0;
}

void PopulateHexGrid(Hexes::HexGrid<char>* &hg) {
 char* types = new char[3] {'a','b','c'};
 for (int j = 0; j < rows; j++) 
  for (int i = 0; i < cols; i++) {
   Hexes::HexCell<char> hc;
   hc.type = types[(i + (j % 2 * 2)) % 3];
   hg->ArrMutate(hc, j, i);
  }
}

void DrawStuff(Hexes::HexGrid<char>* &hg, int x, int y, int toEdge, bool flipped) {
 Hexes::HexCoordinate<int> center = Hexes::SqrToHex(*(new Hexes::SqrCoordinate(x, y)));
 Hexes::HexCell<char> cell;
 cell.type = '%';
 hg->AxialMutate(cell, center);

 Hexes::HexCoordinate<int> offset = Hexes::HexCoordinate<int>(Hexes::HexCoordinate<double>(center) * 1.5);
 std::cout << "Initializing set with center" << std::endl;
 std::set<Hexes::HexCoordinate<int>> uniqCells{ };
 std::cout << "Initializing cells to nullptr" << std::endl;
 Hexes::HexCoordinate<int>* cells = nullptr; 
 int N = 0, n;
 std::cout << "Finding HexFill" << std::endl;
 N += n = Hexes::HexFill(cells, center, toEdge);
 if(cells == NULL || cells == nullptr) {
  std::cout << "cells not set" << std::endl;
  throw exception(100);
 }
 std::cout << "Inserting cells found from HexFill" << std::endl;
 for (int i = 0; i < n; i++) uniqCells.insert(cells[i]);
 std::cout << "Finding HexLine" << std::endl;
 N += n = Hexes::HexLine(cells, center, offset);
 if(cells == NULL || cells == nullptr) {
  std::cout << "cells not set" << std::endl;
  throw exception(100);
 }
 std::cout << "Inserting cells found from HexLine" << std::endl;
 for (int i = 0; i < n; i++) uniqCells.insert(cells[i]);
 std::cout << "Finding HexNonsense" << std::endl;
 N += n = Hexes::HexNonsense(cells, center, toEdge);
 if(cells == NULL || cells == nullptr) {
  std::cout << "cells not set" << std::endl;
  throw exception(100);
 }
 for (int i = 0; i < n; i++) uniqCells.insert(cells[i]);
 cell.type = '^';
 for (Hexes::HexCoordinate<int> uniqCell : uniqCells) {
  hg->AxialMutate(cell, uniqCell);
 }
}

void PrintHexGrid(Hexes::HexGrid<char>* &hg) {
 for (int j = 0; j < rows; j++) {
  if(j%2) std::cout << " ";
  for (int i = 0; i < cols; i++) {
   std::cout << hg->ArrAccess(j, i).type << " ";
  }
  std::cout << std::endl;
 }
}
