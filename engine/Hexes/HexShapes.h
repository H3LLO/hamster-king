#ifndef HexShapes_H
#define HexShapes_H

namespace Hexes {
 HexCoordinate<double>* epsilon = new HexCoordinate(1e-6, 2e-6);

 // Hex shapes
 int HexLine(HexCoordinate<int>* &results, const HexCoordinate<int> a, const HexCoordinate<int> b);
 int HexFill(HexCoordinate<int>* &results, const HexCoordinate<int> center, const int range);
 int HexPerimeter(HexCoordinate<int>* &results, const HexCoordinate<int> center, const int range);
 int HexTriangleFill(HexCoordinate<int>* &results, const HexCoordinate<int> lcorner, const int sideLength, const bool up = false);
 int HexTrianglePerimeter(HexCoordinate<int>* &results, const HexCoordinate<int> lcorner, const int sideLength, const bool up = false);
 int HexNonsense(HexCoordinate<int>* &results, const HexCoordinate<int> center, const int range);
}

#include "HexShapes.cpp"
#endif // HexShapes_H
