namespace Hexes {
 SqrCoordinate::SqrCoordinate(int X, int Y) {
  this->x = X;
  this->y = Y;
 }

 HexCoordinate SqrToHex(SqrCoordinate sqr) {
  int q = sqr.x - (sqr.y - (sqr.y & 1)) / 2;
  int r = sqr.y;
  return HexCoordinate(q, r);
 }

 HexCoordinate::HexCoordinate(int Q, int R) {
  this->q = Q;
  this->r = R;
  this->s = -q-r;
 }

 SqrCoordinate HexToSqr(HexCoordinate hex) {
  int x = hex.q + (hex.r - (hex.r & 1)) / 2;
  int y = hex.r;
  return SqrCoordinate(x, y);
 }
}
