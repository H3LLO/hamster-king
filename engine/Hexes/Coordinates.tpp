#include <cmath>

namespace Hexes {
 template <typename T>
 SqrCoordinate<T>::SqrCoordinate(T X, T Y) {
  this->x = X;
  this->y = Y;
 }

 template <typename T> template <typename U>
 SqrCoordinate<T>::SqrCoordinate(const SqrCoordinate<U> &source) {
  this->x = source.x;
  this->y = source.y;
 }

 template <typename T>
 SqrCoordinate<T> SqrCoordinate<T>::operator+(const SqrCoordinate<T> &obj) {
  return SqrCoordinate(this->x + obj.x, this->y + obj.y);
 }

 template <typename T>
 SqrCoordinate<T> SqrCoordinate<T>::operator-(const SqrCoordinate<T> &obj) {
  return SqrCoordinate(this->x - obj.x, this->y - obj.y);
 }

 template <typename T>
 SqrCoordinate<T> SqrCoordinate<T>::operator*(const T &obj) {
  return SqrCoordinate(this->x * obj, this->y * obj);
 }

 template <typename T>
 SqrCoordinate<T> SqrCoordinate<T>::operator/(const T &obj) {
  return SqrCoordinate(this->x / obj, this->y / obj);
 }

 template <typename U>
 bool operator<(const SqrCoordinate<U> &left, const SqrCoordinate<U> &right) {
  return std::sqrt(left.x * left.x + left.y * left.y) < std::sqrt(right.x * right.x + right.y * right.y);
 }

 template <typename T>
 HexCoordinate<T> SqrToHex(SqrCoordinate<T> sqr) {
  int q = sqr.x - (sqr.y - (sqr.y & 1)) / 2;
  int r = sqr.y;
  return HexCoordinate(q, r);
 }

 template <typename T>
 HexCoordinate<T>::HexCoordinate(T Q, T R) {
  this->q = Q;
  this->r = R;
  this->s = -Q - R;
 }

 template <typename T> template <typename U>
 HexCoordinate<T>::HexCoordinate(const HexCoordinate<U> &source) {
  this->q = static_cast<T>(source.q);
  this->r = static_cast<T>(source.r);
  this->s = -this->q - this->r;
 }

 template <typename T>
 HexCoordinate<T> HexCoordinate<T>::operator+(const HexCoordinate<T> &obj) {
  return HexCoordinate(this->q + obj.q, this->r + obj.r);
 }

 template <typename T>
 HexCoordinate<T> HexCoordinate<T>::operator-(const HexCoordinate<T> &obj) {
  return HexCoordinate(this->q - obj.q, this->r - obj.r);
 }
  
 template <typename T>
 HexCoordinate<T> HexCoordinate<T>::operator*(const T &obj) {
  return HexCoordinate(this->q * obj, this->r * obj);
 }

 template <typename T>
 HexCoordinate<T> HexCoordinate<T>::operator/(const T &obj) {
  return HexCoordinate(this->q / obj, this->r / obj);
 }

 template <typename U>
 bool operator<(const HexCoordinate<U> &left, const HexCoordinate<U> &right) {
  return std::max(std::max(std::abs(left.q), std::abs(left.r)), std::abs(left.s))
   < std::max(std::max(std::abs(right.q), std::abs(right.r)), std::abs(right.s));
 }

 template <typename T>
 SqrCoordinate<T> HexToSqr(HexCoordinate<T> hex) {
  int x = hex.q + (hex.r - (hex.r & 1)) / 2;
  int y = hex.r;
  return SqrCoordinate(x, y);
 }
}
