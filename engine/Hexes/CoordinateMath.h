#pragma once
#ifndef CoordinateMath_H
#define CoordinateMath_H

namespace Hexes {
 // References
 enum direction {E, NE, N, NW, W, SW, S, SE,};
 SqrCoordinate<int>* SquareDirectionVectors = new SqrCoordinate<int>[8] {
  SqrCoordinate(+1,0), //E
  SqrCoordinate(+1,+1), //NE
  SqrCoordinate(0,+1), //N
  SqrCoordinate(-1,+1), //NW
  SqrCoordinate(-1,0), //W
  SqrCoordinate(-1,-1), //SW
  SqrCoordinate(0,-1), //S
  SqrCoordinate(+1,-1), //SE
 };
 HexCoordinate<int>* AxialDirectionVectors = new HexCoordinate<int>[6] {
  HexCoordinate(+1,0), //E
  HexCoordinate(+1,-1), //NE
  HexCoordinate(0,-1), //NW
  HexCoordinate(-1,0), //W
  HexCoordinate(-1,+1), //SW
  HexCoordinate(0,+1), //SE
 };
 HexCoordinate<int>* AxialDiagonalVectors = new HexCoordinate<int>[6] {
  HexCoordinate(+2,+1), //NE
  HexCoordinate(+1,-2), //N
  HexCoordinate(-1,-1), //NW
  HexCoordinate(-2,+1), //SW
  HexCoordinate(-1,+2), //S
  HexCoordinate(+1,+1), //SE
 };

 // Square maths
 template <class T>
 SqrCoordinate<T> SquareNeighbor(SqrCoordinate<T> sqr, direction dir);
 template <class T>
 T SquareDistance(SqrCoordinate<T> a, SqrCoordinate<T> b);
 template <class T>
 SqrCoordinate<int> SqrRound(SqrCoordinate<T> frac);

 // Hex maths
 template <class T>
 HexCoordinate<T> AxialNeighbor(HexCoordinate<T> hex, direction dir);
 template <class T>
 HexCoordinate<T> AxialDiagonal(HexCoordinate<T> hex, direction dir);
 template <class T>
 T HexDistance(HexCoordinate<T> a, HexCoordinate<T> b);
 template <class T>
 HexCoordinate<int> HexRound(HexCoordinate<T> frac);

 // Agnostic maths
 template <class T>
 T Lerq(T a, T b, double t);
}

#include "CoordinateMath.tpp"
#endif // CoordinateMath_H
