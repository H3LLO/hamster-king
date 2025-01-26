#include "HexCell.h"
#include "HexGrid.h"
#include "Coordinates.h"
#include <stdlib.h>
#include <cassert>
#include <iostream>

#define assertm(exp, msg) assert((void(msg), exp))

namespace Hexes {
 HexGrid::HexGrid(int rows, int cols) {
  this->Rows = rows;
  this->Cols = cols;
  _hexArr = (HexCell *)std::malloc(rows * cols * sizeof(HexCell));
 }

 // Accessors
 // Row major
 HexCell HexGrid::ArrAccess(int j, int i) {
  assert(j < this->Rows && i < this->Cols);
  return _hexArr[j * this->Cols + i];
 }

 HexCell HexGrid::AxialAccess(int q, int r) {
  int i = q + (r - (r & 1)) / 2;
  int j = r;
  return ArrAccess(j, i);
 }

 HexCell HexGrid::ArrAccess(SqrCoordinate sqr) {
  return ArrAccess(sqr.y, sqr.x);
 }

 HexCell HexGrid::AxialAccess(HexCoordinate hex) {
  return AxialAccess(hex.q, hex.r);
 }

 // Mutators
 void HexGrid::ArrMutate(HexCell cell, int j, int i) {
  _hexArr[j * this->Cols + i] = cell;
 }

 void HexGrid::AxialMutate(HexCell cell, int q, int r) {
  int i = q + (r - (r & 1)) / 2;
  int j = r;
  ArrMutate(cell, j, i);
 }

 void HexGrid::ArrMutate(HexCell cell, SqrCoordinate sqr) {
  ArrMutate(cell, sqr.y, sqr.x);
 }

 void HexGrid::AxialMutate(HexCell cell, HexCoordinate hex) {
  AxialMutate(cell, hex.q, hex.r);
 }

 void HexGrid::Dispose() {
  std::free(_hexArr);
 }
}
