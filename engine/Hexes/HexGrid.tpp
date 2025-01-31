namespace Hexes {
 template <class T>
 HexGrid<T>::HexGrid(int rows, int cols) {
  this->Rows = rows;
  this->Cols = cols;
  const int size = rows * cols;
  _hexArr = new HexCell<T>[size];
 }

 // Accessors
 // Row major
 template <class T>
 HexCell<T> HexGrid<T>::ArrAccess(int j, int i) {
  AccessInfo(i,j);
  assert(j < this->Rows);
  assert(i < this->Cols);
  return _hexArr[j * this->Cols + i];
 }

 template <class T>
 HexCell<T> HexGrid<T>::AxialAccess(int q, int r) {
  int i = q + (r - (r & 1)) / 2;
  int j = r;
  return ArrAccess(j, i);
 }

 template <class T>
 HexCell<T> HexGrid<T>::ArrAccess(SqrCoordinate<int> &sqr) {
  return ArrAccess(sqr.y, sqr.x);
 }

 template <class T>
 HexCell<T> HexGrid<T>::AxialAccess(HexCoordinate<int> &hex) {
  return AxialAccess(hex.q, hex.r);
 }

 // Mutators
 template <class T>
 void HexGrid<T>::ArrMutate(HexCell<T> cell, int j, int i) {
  AccessInfo(i,j);
  assert(j < this->Rows);
  assert(i < this->Cols);
  _hexArr[j * this->Cols + i] = cell;
 }

 template <class T>
 void HexGrid<T>::AxialMutate(HexCell<T> cell, int q, int r) {
  int i = q + (r - (r & 1)) / 2;
  int j = r;
  ArrMutate(cell, j, i);
 }

 template <class T>
 void HexGrid<T>::ArrMutate(HexCell<T> cell, SqrCoordinate<int> &sqr) {
  ArrMutate(cell, sqr.y, sqr.x);
 }

 template <class T>
 void HexGrid<T>::AxialMutate(HexCell<T> cell, HexCoordinate<int> &hex) {
  AxialMutate(cell, hex.q, hex.r);
 }

 template <class T>
 void HexGrid<T>::Dispose() {
  delete[] _hexArr;
 }

 // Debug balogna
 template <class T>
 void HexGrid<T>::AccessInfo(int i, int j) {
  if (!debug) return;
  SqrCoordinate<int>* sqr = new SqrCoordinate(i,j);
  HexCoordinate hex = SqrToHex(*sqr);
  std::cout << "Accessing position (" << i << "," << j << ")/" << j * this->Cols + i;
  std::cout << " => hex: (" << hex.q << "," << hex.r << ") ";
  std::cout << "in an array of (" << this->Cols << "," << this->Rows << ")/" << this->Cols*this->Rows << std::endl;
 }
}
