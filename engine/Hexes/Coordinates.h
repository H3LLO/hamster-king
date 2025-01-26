#pragma once
#ifndef Coordinates_H
#define Coordinates_H

namespace Hexes {
 template <class T>
 struct SqrCoordinate {
  T x, y;

  SqrCoordinate(T X, T Y);

  SqrCoordinate<T> operator+(const SqrCoordinate<T>& obj);
  SqrCoordinate<T> operator-(const SqrCoordinate<T>& obj);
  SqrCoordinate<T> operator*(const T& obj);
  SqrCoordinate<T> operator/(const T& obj);
 };

 template <class T>
 struct HexCoordinate {
  T q, r, s;

  HexCoordinate(T Q, T R);

  HexCoordinate<T> operator+(const HexCoordinate<T>& obj);
  HexCoordinate<T> operator-(const HexCoordinate<T>& obj);
  HexCoordinate<T> operator*(const T& obj);
  HexCoordinate<T> operator/(const T& obj);
 };

 template <class T>
 HexCoordinate<T> SqrToHex(SqrCoordinate<T> sqr);
 template <class T>
 SqrCoordinate<T> HexToSqr(HexCoordinate<T> hex);
}

#include "Coordinates.tpp"
#endif // Coordinates_H
