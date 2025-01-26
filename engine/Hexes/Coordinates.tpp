namespace Hexes {
 template <class T>
 SqrCoordinate<T>::SqrCoordinate(T X, T Y) {
  this->x = X;
  this->y = Y;
 }

 template <class T>
 SqrCoordinate<T> SqrCoordinate<T>::operator+(const SqrCoordinate<T>& obj) {
  return SqrCoordinate(this->x + obj.x, this->y + obj.y);
 }

 template <class T>
 SqrCoordinate<T> SqrCoordinate<T>::operator-(const SqrCoordinate<T>& obj) {
  return SqrCoordinate(this->x - obj.x, this->y - obj.y);
 }

 template <class T>
 SqrCoordinate<T> SqrCoordinate<T>::operator*(const T& obj) {
  return SqrCoordinate(this->x * obj, this->y * obj);
 }

 template <class T>
 SqrCoordinate<T> SqrCoordinate<T>::operator/(const T& obj) {
  return SqrCoordinate(this->x / obj, this->y / obj);
 }

 template <class T>
 HexCoordinate<T> SqrToHex(SqrCoordinate<T> sqr) {
  int q = sqr.x - (sqr.y - (sqr.y & 1)) / 2;
  int r = sqr.y;
  return HexCoordinate(q, r);
 }

 template <class T>
 HexCoordinate<T>::HexCoordinate(T Q, T R) {
  this->q = Q;
  this->r = R;
  this->s = -q-r;
 }

 template <class T>
 HexCoordinate<T> HexCoordinate<T>::operator+(const HexCoordinate<T>& obj) {
  return HexCoordinate(this->q + obj.q, this->r + obj.r);
 }

 template <class T>
 HexCoordinate<T> HexCoordinate<T>::operator-(const HexCoordinate<T>& obj) {
  return HexCoordinate(this->q - obj.q, this->r - obj.r);
 }
  
 template <class T>
 HexCoordinate<T> HexCoordinate<T>::operator*(const T& obj) {
  return HexCoordinate(this->q * obj, this->r * obj);
 }

 template <class T>
 HexCoordinate<T> HexCoordinate<T>::operator/(const T& obj) {
  return HexCoordinate(this->q / obj, this->r / obj);
 }

 template <class T>
 SqrCoordinate<T> HexToSqr(HexCoordinate<T> hex) {
  int x = hex.q + (hex.r - (hex.r & 1)) / 2;
  int y = hex.r;
  return SqrCoordinate(x, y);
 }
}
