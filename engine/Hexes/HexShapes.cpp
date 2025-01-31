namespace Hexes {
 // Validation
 template <typename T>
 int ValidHexes(HexCoordinate<int>* &results, const int size, const HexGrid<T>* &grid) {
  int rows = grid->Rows, cols = grid->Cols, n = 0;
  HexCoordinate<int>* valid = new HexCoordinate<int>[size];
  for (int i = 0; i < size; i++) {
   SqrCoordinate<int> sqr = HexToSqr(results[i]);
   if (sqr.x < cols && sqr.y < rows) valid[n++] = results[i];
  }
  delete[] results;
  results = valid;
  return n;
 }

 template <typename T>
 void ValidHexes(std::set<HexCoordinate<int>> &results, const HexGrid<T>* grid) {
  int rows = grid->Rows, cols = grid->Cols;
  std::set<HexCoordinate<int>> valid{ };
  for (HexCoordinate<int> hex : results) {
   SqrCoordinate<int> sqr = HexToSqr(hex);
   if (sqr.x < cols && sqr.y < rows) {
    valid.insert(hex);
   }
  }
  results.swap(valid);
  valid.clear();
 }

 // Hex shapes
 int HexShape(HexCoordinate<int>* &results, const Shape &shape) {
  int N = 0;
  switch(shape.type){
   case Line:
    N = HexLine(results, shape.point, shape.point2);
    break;
   case HexagonFill:
    N = HexFill(results, shape.point, shape.length);
    break;
   case HexagonPerimeter:
    N = HexPerimeter(results, shape.point, shape.length);
    break;
   case TriangleFill:
    N = HexTriangleFill(results, shape.point, shape.length, shape.pointsUp);
    break;
   case TrianglePerimeter:
    N = HexTrianglePerimeter(results, shape.point, shape.length, shape.pointsUp);
    break;
   case CenteredTriangleFill:
    N = HexCenterTriangleFill(results, shape.point, shape.length, shape.pointsUp);
    break;
   case CenteredTrianglePerimeter:
    N = HexCenterTrianglePerimeter(results, shape.point, shape.length, shape.pointsUp);
    break;
   default:
    N = HexNonsense(results, shape.point, shape.length);
    break;
  }
  return N;
 }

 void HexShape(std::set<HexCoordinate<int>> &cells, const Shape &shape) {
  int N = 0;
  HexCoordinate<int>* results = nullptr;
  N = HexShape(results, shape);
  if(results == NULL || results == nullptr) {
   throw stop_struct(100);
  }
  for (int i = 0; i < N; i++) cells.insert(results[i]);
  delete[] results;
  results = nullptr;
 }

 int HexLine(HexCoordinate<int>* &results, const HexCoordinate<int> a, const HexCoordinate<int> b) {
  HexCoordinate<double> nudgeb = HexCoordinate<double>(b) + *epsilon;
  const int N = HexDistance(a, b);
  results = new HexCoordinate<int>[N];
  for (int i = 0; i < N; i++) {
   results[i] = HexRound(Lerq(HexCoordinate<double>(a), nudgeb, (double) (i+1) / (double) N));
  }
  return N;
 }

 int HexFill(HexCoordinate<int>* &results, const HexCoordinate<int> center, const int range) {
  const int N = ((range + 1) * range) * 3; //\Sigma_0^range * 6
  results = new HexCoordinate<int>[N];
  int i = 0;
  HexCoordinate<int>* search = new HexCoordinate(0, 0);
  for (search->q = -range; search->q <= range; search->q++)
   for (search->r = std::max(-range, -search->q - range);
     search->r <= std::min(range, range - search->q); search->r++)
    if (0 != search->q || 0 != search->r) {
     results[i++] = center + *search;
    }
  delete[] search;
  search = nullptr;
  return N;
 }

 int HexPerimeter(HexCoordinate<int>* &results, const HexCoordinate<int> center, const int range) {
  const int N = 6 * range;
  results = new HexCoordinate<int>[N];
  int i = 0; 
  results[i++] = center + (AxialDirectionVectors[4] * range);
  for (int dir = direction::E; dir < 6; dir++)
   for (int s = 0; s < range; s++)
    results[i] = AxialNeighbor(results[-1 + i++], (direction)dir);
  return N;
 }

 int HexTriangleFill(HexCoordinate<int>* &results, const HexCoordinate<int> lcorner, const int sideLength, const bool up) {
  const int N = ((sideLength + 1) * sideLength) / 2 - 1;
  results = new HexCoordinate<int>[N];
  int dir = up ? 1 : 5;
  HexCoordinate<int>* spine = new HexCoordinate<int>[sideLength - 1];
  int nn = HexLine(spine, lcorner, lcorner + (AxialDirectionVectors[0] * (sideLength - 1)));
  HexCoordinate<int>* line = nullptr;
  int n, i = 0;
  for (int j = 1; j < sideLength; j ++) {
   results[i++] = spine[j - 1];
   n = HexLine(line, spine[j - 1], lcorner + AxialDirectionVectors[dir] * j);
   for (int k = 0; k < n; k++) {
    results[i++] = line[k];
   }
   delete[] line;
   line = nullptr;
  }
  delete[] spine;
  spine = nullptr;
  return N;
 }

 int HexTrianglePerimeter(HexCoordinate<int>* &results, const HexCoordinate<int> lcorner, const int sideLength, const bool up) {
  const int N = (sideLength - 1) * 3 - 1;
  results = new HexCoordinate<int>[N];
  int dir = up ? 1 : 5;
  int n, i = 0;
  HexCoordinate<int>* line = nullptr;
  for (int j = 0; j < 3; j++) {
   n = HexLine(line, (j ? results[i - 1] : lcorner), lcorner + (AxialDirectionVectors[j ? dir : 0] * (j == 2 ? 1 : sideLength - 1)));
   for (int k = 0; k < n; k++) {
    results[i++] = line[k];
   }
   delete[] line;
   line = nullptr;
  }
  return N;
 }

 int HexCenterTriangleFill(HexCoordinate<int>* &results, const HexCoordinate<int> center, const int sideLength, const bool up) {
  int dirI = (up ? 4 : 2), diagI = (up ? 3 : 2 ); 
  HexCoordinate<int> lcorner = center + (AxialDirectionVectors[dirI] * (!(sideLength % 3) ? 1 : 0)) + AxialDiagonalVectors[diagI] * ((sideLength - 1) / 3);
  int N = HexTriangleFill(results, lcorner, sideLength, up);
  for (int i = 0;  i < N; i++) {
   if(results[i] == center) {
    results[i] = lcorner;
    break;
   }
  }
  return N;
 }

 int HexCenterTrianglePerimeter(HexCoordinate<int>* &results, const HexCoordinate<int> center, const int sideLength, const bool up) {
  int dirI = (up ? 4 : 2), diagI = (up ? 3 : 2 ); 
  HexCoordinate<int> lcorner = center + (AxialDirectionVectors[dirI] * (!(sideLength % 3) ? 1 : 0)) + AxialDiagonalVectors[diagI] * ((sideLength - 1) / 3);
  HexCoordinate<int>* cells = nullptr;
  int N = HexTrianglePerimeter(cells, lcorner, sideLength, up);
  results = new HexCoordinate<int>[N + 1];
  for(int i = 0; i < N; i++) results[i] = cells[i];
  results[N] = lcorner;
  delete[] cells;
  cells = nullptr;
  return N + 1;
 }

 int HexNonsense(HexCoordinate<int>* &results, const HexCoordinate<int> center, const int range) {
  results = new HexCoordinate<int>[6];
  for(int i = 0; i < 6; i++) {
   results[i] = center + AxialDirectionVectors[i] * range;
  }
  return 6;
 }
}
