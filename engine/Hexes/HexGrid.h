#pragma once
#include "Coordinates.h"
#include "HexCell.h"
#ifndef HexGrid_H
#define HexGrid_H

namespace Hexes {
 class HexGrid {
  private:
   HexCell* _hexArr;

  public:
   int Rows;
   int Cols;
   
   HexGrid(int rows, int cols);

   // Accessors
   // Row major
   HexCell ArrAccess(int j, int i);
   HexCell AxialAccess(int q, int r);
   HexCell ArrAccess(SqrCoordinate sqr);
   HexCell AxialAccess(HexCoordinate hex);

   // Mutators
   void ArrMutate(HexCell cell, int j, int i);
   void AxialMutate(HexCell cell, int q, int r);
   void ArrMutate(HexCell cell, SqrCoordinate sqr);
   void AxialMutate(HexCell cell, HexCoordinate hex);

   void Dispose();
 };
}
#endif // HexGrid_H
