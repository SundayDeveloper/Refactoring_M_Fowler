#include <iostream>
#include <algorithm>

class IntRange {
protected:
    int low, high;

public:
  IntRange(const int _low, const int _high) :
    low(_low), high(_high) {}

  bool Includes(const int arg) const
  {
    return low <= arg && arg <= high;
  }

  void Grow(const int factor)
  {
    high *= factor;
  }
};

class CappedRange : public IntRange {
private:
  int cap;  
public:

  CappedRange(const int _low, const int _high, const int _cap) :
    IntRange(_low, _high), cap(_cap) {};

  bool Includes(const int arg)
  {
    return low <= arg && arg <= std::min(high, cap);
  }
 
};

int main()
{
  using std::cout;
  using std::endl;
  IntRange ir(0,5);
  cout << ir.Includes(4) << endl
       << ir.Includes(-3) << endl
       << ir.Includes(6)  << endl;
  ir.Grow(2);
  cout << ir.Includes(7) << endl;

  CappedRange cr(0,5, 3);
  cout << cr.Includes(3) << endl
       << cr.Includes(5) << endl;

  return 0;
}
