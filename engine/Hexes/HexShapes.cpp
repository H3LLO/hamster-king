#include "Coordinates.h"
#include "CoordinateMath.h"
#include "HexCell.h"
#include "HexGrid.h"
#include <stdlib.h>
#include <algorithm>
#include <iostream>

namespace Hexes {
 // Hex shapes
 int HexLine(HexCoordinate<int>* &results, HexCoordinate<int> a, HexCoordinate<int> b) {
  HexCoordinate<double> nudgeb = HexCoordinate<double>(b) + *epsilon;
  int N = HexDistance(a, b);
  results = (HexCoordinate<int>*)malloc(N * sizeof(HexCoordinate<int>));
  for (int i = 0; i < N; i++) {
   results[i] = HexRound(Lerq(HexCoordinate<double>(a), nudgeb, (double) (i+1) / (double) N));
  }
  return N;
 }

 int HexFill(HexCoordinate<int>* &results, HexCoordinate<int> center, int range) {
  int N = 0;
  for (int n = range; n > 0; n--) N += n;
  N *= 6;
  results = (HexCoordinate<int>*)malloc(N * sizeof(HexCoordinate<int>));
  int i = 0;
  HexCoordinate<int>* search = new HexCoordinate(0, 0);
  for (search->q = -range; search->q <= range; search->q++)
   for (search->r = std::max(-range, -search->q - range);
     search->r <= std::min(range, range - search->q); search->r++)
    if (0 != search->q || 0 != search->r) {
     results[i++] = center + *search;
    }
  delete[] search;
  search = nullptr;
  return N;
 }

 int HexPerimeter(HexCoordinate<int>* &results, HexCoordinate<int> center, int range) {
  int N = 6 * range;
  results = (HexCoordinate<int>*)malloc(N * sizeof(HexCoordinate<int>));
  int i = 0; 
  results[i++] = center + (AxialDirectionVectors[4] * range);
  for (int dir = direction::E; dir < 6; dir++)
   for (int s = 0; s < range; s++)
    results[i] = AxialNeighbor(results[-1 + i++], (direction)dir);
  return N;
 }

 int HexNonsense(HexCoordinate<int>* &results, HexCoordinate<int> center, int range) {
  results = (HexCoordinate<int>*)malloc(N * sizeof(HexCoordinate<int>));
  for(int i = 0; i < 6; i++) {
   results[i] = center + AxialDirectionVectors[i] * range;
  }
  return 6;
 }
}
