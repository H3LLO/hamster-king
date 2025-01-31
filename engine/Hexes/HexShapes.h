#ifndef HexShapes_H
#define HexShapes_H

namespace Hexes {
 HexCoordinate<double>* epsilon = new HexCoordinate(1e-6, 2e-6);

 // Validation
 template <typename T>
 int ValidHexes(HexCoordinate<int>* &results, const int size, const HexGrid<T>* &grid);
 template <typename T>
 void ValidHexes(std::set<HexCoordinate<int>> &results, const HexGrid<T>* grid);

 // Hex shapes
 enum ShapeType {
  Line,
  HexagonFill,
  HexagonPerimeter,
  TriangleFill,
  TrianglePerimeter,
  CenteredTriangleFill,
  CenteredTrianglePerimeter,
 };

 struct Shape {
  int type;
  HexCoordinate<int> point;
  HexCoordinate<int> point2;
  int length;
  bool pointsUp;

  Shape(int t, HexCoordinate<int> pt, HexCoordinate<int> pt2) : type(t), point(pt), point2(pt2) {}
  Shape(int t, HexCoordinate<int> pt, int l, bool up) : type(t), point(pt), length(l), pointsUp(up) {}
 };

 int HexShape(HexCoordinate<int>* &results, const Shape &shape);
 void HexShape(std::set<HexCoordinate<int>> &cells, const Shape &shape);
 int HexLine(HexCoordinate<int>* &results, const HexCoordinate<int> a, const HexCoordinate<int> b);
 int HexFill(HexCoordinate<int>* &results, const HexCoordinate<int> center, const int range);
 int HexPerimeter(HexCoordinate<int>* &results, const HexCoordinate<int> center, const int range);
 int HexTriangleFill(HexCoordinate<int>* &results, const HexCoordinate<int> lcorner, const int sideLength, const bool up = false);
 int HexTrianglePerimeter(HexCoordinate<int>* &results, const HexCoordinate<int> lcorner, const int sideLength, const bool up = false);
 int HexCenterTriangleFill(HexCoordinate<int>* &results, const HexCoordinate<int> center, const int sideLength, const bool up = false);
 int HexCenterTrianglePerimeter(HexCoordinate<int>* &results, const HexCoordinate<int> center, const int sideLength, const bool up = false);
 int HexNonsense(HexCoordinate<int>* &results, const HexCoordinate<int> center, const int range);
}

#include "HexShapes.cpp"
#endif // HexShapes_H
