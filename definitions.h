#ifndef GEO_DFNS
#define GEO_DFNS
#include <iostream>
using namespace std;
#endif

class mathObject {};
class point : public mathObject {
public:
  double x, y;
  void initPoint(double x_value, double y_value) {
    x = x_value;
    y = y_value;
  };
  friend ostream &operator<<(ostream &os, const point &a) {
    os << "(" << a.x << "," << a.y << ")";
    return os;
  }

private:
};

class formula : public mathObject {
public:
  double c1, c2, ac, power, ic; // c1- c1,c2- c2,ac-ac,ic-ic

  void initFormula(double c2_, double c1_, double ac_) {
    power = 2;
    c1 = c1_;
    c2 = c2_;
    ac = ac_;
  }
  void initFormula(double c1_, double ac_) {
    power = 1;
    c1 = c1_;
    ac = ac_;
  }
  void initFormula(double cinverse) {
    power = -1;
    ic = cinverse;
  }
  formula() {
    c1 = c2 = ic = ac = 0;
    power = 2;
  }
  friend ostream &operator<<(ostream &os, const formula &a) {
    if (a.power == -1)
      os << "(" << a.ic << ")x^-1";
    else if (a.power == 1) {
      os << "(" << a.c1 << ")x+(" << a.ac << ")";
    } else if (a.power == 2) {
      os << "(" << a.c2 << ")"
         << "x^2+(" << a.c1 << ")x"
         << "+(" << a.ac << ")";
    }
    return os;
  }
  bool operator==(const formula &f) const {
    if (c2 == f.c2 && c1 == f.c1 && ac == f.ac && ic == f.ic) {
      return true;
    } else
      return false;
  }
  formula &operator=(formula const &f) {
    c1 = f.c1;
    c2 = f.c2;
    ac = f.ac;
    ic = f.ic;
    power = f.power;
    return *this;
  }

private:
};

class line : public formula {
public:
  formula analysis;
  line() { k = b = 0; }
  double k, b;
  void initLine(point A, point B) {
    double x1 = A.x, x2 = B.x, y1 = A.y, y2 = B.y;
    k = (y2 - y1) / (x2 - x1);
    b = y1 - k * x1;
    analysis.initFormula(k, b);
  };
  bool operator==(const line &l) const {
    if (analysis == l.analysis) {
      return true;
    } else
      return false;
  }
  friend ostream &operator<<(ostream &os, const line &a) {
    os << a.analysis;
    return os;
  }
};

class linearPair : public line {
public:
  line first, second;
  void initLP(line a, line b) {
    first.analysis = a.analysis;
    second.analysis = b.analysis;
  }

  friend ostream &operator<<(ostream &os, const linearPair &a) {
    os << "<" << a.first << "," << a.second << ">";
    return os;
  }
};
