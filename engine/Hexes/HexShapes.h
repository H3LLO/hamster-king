#ifndef HexShapes_H
#define HexShapes_H

namespace Hexes {
 HexCoordinate<double>* epsilon = new HexCoordinate(1e-6, 2e-6);

 // Hex shapes
 int HexLine(HexCoordinate<int>* &results, HexCoordinate<int> a, HexCoordinate<int> b);
 int HexFill(HexCoordinate<int>* &results, HexCoordinate<int> center, int range);
 int HexPerimeter(HexCoordinate<int>* &results, HexCoordinate<int> center, int range);
 int HexNonsense(HexCoordinate<int>* &results, HexCoordinate<int> center, int range);
}

#include "HexShapes.cpp"
#endif // HexShapes_H
