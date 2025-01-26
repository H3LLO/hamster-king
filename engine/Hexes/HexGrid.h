#pragma once
#include "Coordinates.h"
#include "HexCell.h"
#ifndef HexGrid_H
#define HexGrid_H

namespace Hexes {
 template<class T>
 class HexGrid {
  private:
   HexCell<T>* _hexArr;

  public:
   int Rows;
   int Cols;
   
   HexGrid(int rows, int cols);

   // Accessors
   // Row major
   HexCell<T> ArrAccess(int j, int i);
   HexCell<T> AxialAccess(int q, int r);
   HexCell<T> ArrAccess(SqrCoordinate sqr);
   HexCell<T> AxialAccess(HexCoordinate hex);

   // Mutators
   void ArrMutate(HexCell<T> cell, int j, int i);
   void AxialMutate(HexCell<T> cell, int q, int r);
   void ArrMutate(HexCell<T> cell, SqrCoordinate sqr);
   void AxialMutate(HexCell<T> cell, HexCoordinate hex);

   void Dispose();
 };
}

#include "HexGrid.tpp"
#endif // HexGrid_H
