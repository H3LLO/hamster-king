#ifndef HexCell_H
#define HexCell_H

namespace Hexes {
 template <class T>
 struct HexCell {
  bool traversable = true;
  T type;
 };
}

#endif // HexCell_H
