#ifndef Coordinates_H
#define Coordinates_H
#include <iostream>

namespace Hexes {
 template <typename T>
 struct SqrCoordinate {
  T x, y;

  SqrCoordinate(T X, T Y);
  template<typename U>
  SqrCoordinate(const SqrCoordinate<U>& source);

  SqrCoordinate<T> operator+(const SqrCoordinate<T> &obj);
  SqrCoordinate<T> operator-(const SqrCoordinate<T> &obj);
  SqrCoordinate<T> operator*(const T& obj);
  SqrCoordinate<T> operator/(const T& obj);
  template<typename U>
  friend bool operator<(const SqrCoordinate<U> &left, const SqrCoordinate<U> &right);
 };

 template <typename T>
 inline bool operator>(const SqrCoordinate<T> &left, const SqrCoordinate<T> &right) { return right < left; } 
 template <typename T>
 inline bool operator<=(const SqrCoordinate<T> &left, const SqrCoordinate<T> &right) { return !(left > right); } 
 template <typename T>
 inline bool operator>=(const SqrCoordinate<T> &left, const SqrCoordinate<T> &right) { return !(left < right); } 

 template <typename T>
 struct HexCoordinate {
  T q, r, s;

  HexCoordinate(T Q, T R);
  template <typename U>
  HexCoordinate(const HexCoordinate<U>& source);

  HexCoordinate<T> operator+(const HexCoordinate<T> &obj);
  HexCoordinate<T> operator-(const HexCoordinate<T> &obj);
  HexCoordinate<T> operator*(const T& obj);
  HexCoordinate<T> operator/(const T& obj);
  template<typename U>
  friend bool operator<(const HexCoordinate<U> &left, const HexCoordinate<U> &right);
 };

 template <typename T>
 inline bool operator>(const HexCoordinate<T> &left, const HexCoordinate<T> &right) { return right < left; } 
 template <typename T>
 inline bool operator<=(const HexCoordinate<T> &left, const HexCoordinate<T> &right) { return !(left > right); } 
 template <typename T>
 inline bool operator>=(const HexCoordinate<T> &left, const HexCoordinate<T> &right) { return !(left < right); } 

 template <typename T>
 HexCoordinate<T> SqrToHex(SqrCoordinate<T> sqr);
 template <typename T>
 SqrCoordinate<T> HexToSqr(HexCoordinate<T> hex);
}

#include "Coordinates.tpp"
#endif // Coordinates_H
