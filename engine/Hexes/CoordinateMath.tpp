namespace Hexes {
 // Square maths
 template <class T>
 SqrCoordinate<T> SquareNeighbor(SqrCoordinate<T> sqr, direction dir) {
   return sqr + SquareDirectionVectors[dir];
 }

 template <class T>
 T SquareDistance(SqrCoordinate<T> a, SqrCoordinate<T> b) {
  SqrCoordinate offsets = a - b;
  return std::abs(offsets.x) + std::abs(offsets.y);
 }

 template <class T>
 SqrCoordinate<int> SqrRound(SqrCoordinate<T> frac) {
  return SqrCoordinate(lround(frac.x), lround(frac.y));
 }

 // Hex maths
 template <class T>
 HexCoordinate<T> AxialNeighbor(HexCoordinate<T> hex, direction dir) {
  assert(dir != direction::N && dir != direction::S);
  return hex + AxialDirectionVectors[dir - (dir + 1) / 4]; //Collapses the N and S cases
 }

 template <class T>
 HexCoordinate<T> AxialDiagonal(HexCoordinate<T> hex, direction dir) {
  assert(dir != direction::E && dir != direction::W);
  return hex + AxialDirectionVectors[dir - 1 - dir / 5]; //Collapses the E and W cases
 }

 template <class T>
 T HexDistance(HexCoordinate<T> a, HexCoordinate<T> b) {
  HexCoordinate offset = a - b;
  return std::max(std::max(std::abs(offset.q), std::abs(offset.r)), std::abs(offset.s));
 }

 template <class T>
 HexCoordinate<int> HexRound(HexCoordinate<T> frac) {
  return HexCoordinate(lround(frac.q), lround(frac.r));
 }
 
 // Agnostic maths
 template <class T>
 T Lerq(T a, T b, double t) {
  return a + (b - a) * t;
 }
}
