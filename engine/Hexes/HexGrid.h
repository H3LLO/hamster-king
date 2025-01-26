#pragma once
#include "Coordinates.h"
#ifndef HexGrid_H
#define HexGrid_H

namespace Hexes {
 template<class T>
 class HexGrid {
  private:
   T* _hexArr;

  public:
   int Rows;
   int Cols;
   
   HexGrid(int rows, int cols);

   // Accessors
   // Row major
   T ArrAccess(int j, int i);
   T AxialAccess(int q, int r);
   T ArrAccess(SqrCoordinate sqr);
   T AxialAccess(HexCoordinate hex);

   // Mutators
   void ArrMutate(T cell, int j, int i);
   void AxialMutate(T cell, int q, int r);
   void ArrMutate(T cell, SqrCoordinate sqr);
   void AxialMutate(T cell, HexCoordinate hex);

   void Dispose();
 };
}

#include "HexGrid.tpp"
#endif // HexGrid_H
