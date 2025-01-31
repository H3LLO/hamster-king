#include <cmath>

namespace Hexes {
 template <typename T>
 SqrCoordinate<T>::SqrCoordinate() : x(0), y(0) {}
 template <typename T>
 SqrCoordinate<T>::SqrCoordinate(T X, T Y) : x(X), y(Y) {}

 template <typename T> template <typename U>
 SqrCoordinate<T>::SqrCoordinate(const SqrCoordinate<U> &source) {
  this->x = static_cast<T>(source.x);
  this->y = static_cast<T>(source.y);
 }

 template <typename T>
 double SqrCoordinate<T>::Magnitude() const {
  return std::sqrt(this->x * this->x + this->y * this->y);
 }

 template <typename T>
 SqrCoordinate<T> SqrCoordinate<T>::operator+(const SqrCoordinate<T> &obj) const {
  return SqrCoordinate(this->x + obj.x, this->y + obj.y);
 }

 template <typename T>
 SqrCoordinate<T> SqrCoordinate<T>::operator-(const SqrCoordinate<T> &obj) const {
  return SqrCoordinate(this->x - obj.x, this->y - obj.y);
 }

 template <typename T>
 SqrCoordinate<T> SqrCoordinate<T>::operator*(const T &obj) const {
  return SqrCoordinate(this->x * obj, this->y * obj);
 }

 template <typename T>
 SqrCoordinate<T> SqrCoordinate<T>::operator/(const T &obj) const {
  return SqrCoordinate(this->x / obj, this->y / obj);
 }

 template <typename U>
 bool operator<(const SqrCoordinate<U> &left, const SqrCoordinate<U> &right) {
  double l = left.Magnitude(), r = right.Magnitude();
  return (l != r ? l < r : l + left.x < r + right.x);
 }

 template <typename U>
 bool operator==(const SqrCoordinate<U> &left, const SqrCoordinate<U> &right) {
  return left.x == right.x && left.y == right.y;
 }

 template <typename T>
 HexCoordinate<T> SqrToHex(SqrCoordinate<T> sqr) {
  int q = sqr.x - (sqr.y - (sqr.y & 1)) / 2;
  int r = sqr.y;
  return HexCoordinate(q, r);
 }

 template <typename T>
 HexCoordinate<T>::HexCoordinate() : q(0), r(0), s(0) {}

 template <typename T>
 HexCoordinate<T>::HexCoordinate(T Q, T R) : q(Q), r(R), s(-Q - R) {}

 template <typename T> template <typename U>
 HexCoordinate<T>::HexCoordinate(const HexCoordinate<U> &source) {
  this->q = static_cast<T>(source.q);
  this->r = static_cast<T>(source.r);
  this->s = -this->q - this->r;
 }

 template <typename T>
 double HexCoordinate<T>::Magnitude() const {
  return std::max(std::max(std::abs(this->q), std::abs(this->r)), std::abs(this->s));
 }

 template <typename T>
 HexCoordinate<T> HexCoordinate<T>::operator+(const HexCoordinate<T> &obj) const {
  return HexCoordinate(this->q + obj.q, this->r + obj.r);
 }

 template <typename T>
 HexCoordinate<T> HexCoordinate<T>::operator-(const HexCoordinate<T> &obj) const {
  return HexCoordinate(this->q - obj.q, this->r - obj.r);
 }
  
 template <typename T>
 HexCoordinate<T> HexCoordinate<T>::operator*(const T &obj) const {
  return HexCoordinate(this->q * obj, this->r * obj);
 }

 template <typename T>
 HexCoordinate<T> HexCoordinate<T>::operator/(const T &obj) const {
  return HexCoordinate(this->q / obj, this->r / obj);
 }

 template <typename U>
 bool operator<(const HexCoordinate<U> &left, const HexCoordinate<U> &right) {
  double l = left.Magnitude(), r = right.Magnitude();
  return (l != r ? l < r : l + left.q < r + right.q);
 }

 template <typename U>
 bool operator==(const HexCoordinate<U> &left, const HexCoordinate<U> &right) {
  return left.q == right.q && left.r == right.r;
 }

 template <typename T>
 SqrCoordinate<T> HexToSqr(HexCoordinate<T> hex) {
  int x = hex.q + (hex.r - (hex.r & 1)) / 2;
  int y = hex.r;
  return SqrCoordinate(x, y);
 }
}
