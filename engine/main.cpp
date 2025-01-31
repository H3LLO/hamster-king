#include "Debug.h" //gives malloc to be used straight
#include "Hexes.h"
#include "Drawing.h"
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
  //hg->debug = true;
  DrawStuff(hg, cols/2, rows/2, 4, false);
  //hg->debug = false;
  PrintHexGrid(hg);
  hg->Dispose();
 }
 catch (stop_struct &stop) {
  return stop.stop_code;
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

void DrawStuff(Hexes::HexGrid<char>* &hg, int x, int y, int distance, bool flipped) {
 Hexes::HexCoordinate<int> center = Hexes::SqrToHex(*(new Hexes::SqrCoordinate(x, y)));
 Hexes::HexCell<char> cell;
 cell.type = '%';
 hg->AxialMutate(cell, center);

 Hexes::HexCoordinate<int> offset = Hexes::HexCoordinate<int>(Hexes::HexCoordinate<double>(center) * 0.5);
 std::set<Hexes::HexCoordinate<int>> cells{ };
 //Hexes::HexShape(cells, Hexes::Shape(Hexes::ShapeType::Line, center, offset));
 //Hexes::HexShape(cells, Hexes::Shape(Hexes::ShapeType::HexagonFill, center, distance, false));
 Hexes::HexShape(cells, Hexes::Shape(Hexes::ShapeType::CenteredTriangleFill, center, distance, false));
 Hexes::HexShape(cells, Hexes::Shape(Hexes::ShapeType::CenteredTrianglePerimeter, offset, distance, true));
 Hexes::ValidHexes(cells, hg);

 cell.type = '^';
 for (Hexes::HexCoordinate<int> uniqCell : cells) {
  hg->AxialMutate(cell, uniqCell);
 }
}

void PrintHexGrid(Hexes::HexGrid<char>* &hg) {
 for (int j = 0; j < rows; j++) {
  if(j % 2) std::cout << " ";
  for (int i = 0; i < cols; i++) {
   std::cout << hg->ArrAccess(j, i).type << " ";
  }
  std::cout << std::endl;
 }
}
