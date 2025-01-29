#ifndef HexGrid_H
#define HexGrid_H
#include "Coordinates.h"
#include "HexCell.h"

namespace Hexes {
 template<class T>
 class HexGrid {
  private:
   HexCell<T>* _hexArr;

   void AccessInfo(int i, int j);

  public:
   int Rows;
   int Cols;
   bool debug = false;
   
   HexGrid(int rows, int cols);

   // Accessors
   // Row major
   HexCell<T> ArrAccess(int j, int i);
   HexCell<T> AxialAccess(int q, int r);
   HexCell<T> ArrAccess(SqrCoordinate<int> &sqr);
   HexCell<T> AxialAccess(HexCoordinate<int> &hex);

   // Mutators
   void ArrMutate(HexCell<T> cell, int j, int i);
   void AxialMutate(HexCell<T> cell, int q, int r);
   void ArrMutate(HexCell<T> cell, SqrCoordinate<int> &sqr);
   void AxialMutate(HexCell<T> cell, HexCoordinate<int> &hex);

   void Dispose();
 };
}

#include "HexGrid.tpp"
#endif // HexGrid_H
