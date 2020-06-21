#include <iostream>
#include <algorithm>

class IntRange {
private:
    int low, high;

public:
  IntRange(const int _low, const int _high) :
    low(_low), high(_high) {}

  int Get_Low() const { return low; }

  virtual int Get_High() const { return high; }
  void Set_High(const int _high) { high = _high; }

  bool Includes(const int arg) const
  {
    return Get_Low() <= arg && arg <= Get_High();
  }

  void Grow(const int factor)
  {
    Set_High( Get_High() * factor);
  }
};

class CappedRange : public IntRange {
private:
  int cap;
public:

  CappedRange(const int _low, const int _high, const int _cap) :
    IntRange(_low, _high), cap(_cap) {};

  int Get_Cap() const { return cap; }
  int Get_High() const 
  { 
    
    return std::min(this->IntRange::Get_High() , Get_Cap() ); 
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
  cout << cr.Get_High() << endl;
  return 0;
}
