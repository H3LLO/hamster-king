#pragma once
#ifndef Coordinates_H
#define Coordinates_H

namespace Hexes {
 struct SqrCoordinate {
  int x, y;

  SqrCoordinate(int X, int Y);
 };

 struct HexCoordinate {
  int q, r, s;

  HexCoordinate(int Q, int R);
 };

  HexCoordinate SqrToHex(SqrCoordinate sqr);
  SqrCoordinate HexToSqr(HexCoordinate hex);
}

#endif // Coordinates_H
