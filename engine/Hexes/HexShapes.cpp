#include "Coordinates.h"
#include "CoordinateMath.h"
#include "HexCell.h"
#include "HexGrid.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>

namespace Hexes {
 // Hex shapes
 int HexLine(HexCoordinate<int>* &results, const HexCoordinate<int> a, const HexCoordinate<int> b) {
  HexCoordinate<double> nudgeb = HexCoordinate<double>(b) + *epsilon;
  const int N = HexDistance(a, b);
  std::cout << "Distance of " << N << " found" << std::endl;
  results = new HexCoordinate<int>[N];
  for (int i = 0; i < N; i++) {
   results[i] = HexRound(Lerq(HexCoordinate<double>(a), nudgeb, (double) (i+1) / (double) N));
  }
  return N;
 }

 int HexFill(HexCoordinate<int>* &results, const HexCoordinate<int> center, const int range) {
  const int N = ((range + 1) * range) * 3; //\Sigma_0^range * 6
  results = new HexCoordinate<int>[N];
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

 int HexPerimeter(HexCoordinate<int>* &results, const HexCoordinate<int> center, const int range) {
  const int N = 6 * range;
  results = new HexCoordinate<int>[N];
  int i = 0; 
  results[i++] = center + (AxialDirectionVectors[4] * range);
  for (int dir = direction::E; dir < 6; dir++)
   for (int s = 0; s < range; s++)
    results[i] = AxialNeighbor(results[-1 + i++], (direction)dir);
  return N;
 }

 int HexTriangleFill(HexCoordinate<int>* &results, const HexCoordinate<int> lcorner, const int sideLength, const bool up) {
  const int N = ((sideLength + 1) * sideLength) / 2 - 1;
  results = new HexCoordinate<int>[N];
  int dir = up ? 1 : 5;
  HexCoordinate<int>* spine = new HexCoordinate<int>[sideLength - 1];
  int nn = HexLine(spine, lcorner, lcorner + (AxialDirectionVectors[0] * (sideLength - 1)));
  HexCoordinate<int>* line = nullptr;
  int n, i = 0;
  for (int j = 1; j < sideLength; j ++) {
   results[i++] = spine[j - 1];
   n = HexLine(line, spine[j - 1], lcorner + AxialDirectionVectors[dir] * j);
   for (int k = 0; k < n; k++) {
    results[i++] = line[k];
   }
   delete[] line;
   line = nullptr;
  }
  delete[] spine;
  spine = nullptr;
  return N;
 }

 int HexTrianglePerimeter(HexCoordinate<int>* &results, const HexCoordinate<int> lcorner, const int sideLength, const bool up) {
  const int N = (sideLength - 1) * 3 - 1;
  results = new HexCoordinate<int>[N];
  int dir = up ? 1 : 5;
  int n, i = 0;
  HexCoordinate<int>* line = nullptr;
  for (int j = 0; (std::cout << "On j loop " << j << std::endl, j < 3); j++) {
   HexCoordinate<int> start = (j ? results[i - 1] : lcorner);
   HexCoordinate<int> offset = (AxialDirectionVectors[j ? dir : 0] * (j == 2 ? 1 : sideLength - 1));
   HexCoordinate<int> end = lcorner + offset;
   std::cout << "Starting at (" << start.q << "," << start.r << ") [" << j << "]";
   std::cout << " with an offset of (" << offset.q << "," << offset.r << ")";
   std::cout << " and going to (" << end.q << "," << end.r << ") [" << (j ? dir : 0) << " x " << (j == 2 ? 1 : sideLength - 1) << "]" << std::endl;
   n = HexLine(line, start, end);
   for (int k = 0; (std::cout << "On k loop " << k << std::endl, k < n); k++) {
    std::cout << i << "th point at (" << line[k].q << "," << line[k].r << ")" << std::endl;
    results[i++] = line[k];
   }
   delete[] line;
   line = nullptr;
  }
  return N;
 }

 int HexNonsense(HexCoordinate<int>* &results, const HexCoordinate<int> center, const int range) {
  results = new HexCoordinate<int>[6];
  for(int i = 0; i < 6; i++) {
   results[i] = center + AxialDirectionVectors[i] * range;
  }
  return 6;
 }
}
