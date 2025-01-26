#include "Coordinates.h"
#include <stdlib.h>
#include <cassert>
#include <iostream>

#define assertm(exp, msg) assert((void(msg), exp))

namespace Hexes {
 template <class T>
 HexGrid<T>::HexGrid(int rows, int cols) {
  this->Rows = rows;
  this->Cols = cols;
  _hexArr = (T *)std::malloc(rows * cols * sizeof(T));
 }

 // Accessors
 // Row major
 template <class T>
 T HexGrid<T>::ArrAccess(int j, int i) {
  assert(j < this->Rows && i < this->Cols);
  return _hexArr[j * this->Cols + i];
 }

 template <class T>
 T HexGrid<T>::AxialAccess(int q, int r) {
  int i = q + (r - (r & 1)) / 2;
  int j = r;
  return ArrAccess(j, i);
 }

 template <class T>
 T HexGrid<T>::ArrAccess(SqrCoordinate sqr) {
  return ArrAccess(sqr.y, sqr.x);
 }

 template <class T>
 T HexGrid<T>::AxialAccess(HexCoordinate hex) {
  return AxialAccess(hex.q, hex.r);
 }

 // Mutators
 template <class T>
 void HexGrid<T>::ArrMutate(T cell, int j, int i) {
  _hexArr[j * this->Cols + i] = cell;
 }

 template <class T>
 void HexGrid<T>::AxialMutate(T cell, int q, int r) {
  int i = q + (r - (r & 1)) / 2;
  int j = r;
  ArrMutate(cell, j, i);
 }

 template <class T>
 void HexGrid<T>::ArrMutate(T cell, SqrCoordinate sqr) {
  ArrMutate(cell, sqr.y, sqr.x);
 }

 template <class T>
 void HexGrid<T>::AxialMutate(T cell, HexCoordinate hex) {
  AxialMutate(cell, hex.q, hex.r);
 }

 template <class T>
 void HexGrid<T>::Dispose() {
  std::free(_hexArr);
 }
}
