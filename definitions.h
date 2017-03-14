#ifndef DFNS
#define DFNS
#include <cmath>
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
    os << " "
       << "(" << a.x << "," << a.y << ")"
       << " ";
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
      os << " "
         << "(" << a.ic << ")x^-1"
         << " ";
    else if (a.power == 1) {
      os << " "
         << "(" << a.c1 << ")x+(" << a.ac << ")"
         << " ";
    } else if (a.power == 2) {
      os << " "
         << "(" << a.c2 << ")"
         << "x^2+(" << a.c1 << ")x"
         << "+(" << a.ac << ")"
         << " ";
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
    os << " " << a.analysis << " ";
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
    os << " "
       << "<" << a.first << "," << a.second << ">"
       << " ";
    return os;
  }
};

class frac {
  int getCommon(int ia, int ib) {
    int temp;
    int a = ia;
    int b = ib;
    if (a < b) {
      temp = a;
      a = b;
      b = temp;
    }
    while (b != 0) {
      temp = a % b;
      a = b;
      b = temp;
    }
    return a;
  }
  int nu, de; // The numerator and denominator

public:
  frac(double a, double b) {
    int ia, ib;
    ia = a * 10000000;
    ib = b * 10000000;
    if (b != 0) {
      int gcd = getCommon(ia, ib);
      ia /= gcd;
      ib /= gcd;
      nu = ia;
      de = ib;
    } else {
      cerr << "Wrong Fraction!" << endl;
      nu = 1;
    }
  }
  double getValue() {
    double res;
    res = (double)nu / (double)de;
    return res;
  }
  friend ostream &operator<<(ostream &os, const frac &a) {
    int nu = a.nu;
    int de = a.de;
    if ((nu > 0 && de < 0) || (nu < 0 && de > 0))
      os << " -" << abs(nu) << "/" << abs(de) << " ";
    else if ((nu < 0 && de < 0) || (nu > 0 && de > 0))
      os << " " << abs(nu) << "/" << abs(de) << " ";
    else if (nu == 0)
      os << " 0 ";
    return os;
  }
};

class csqrt : public mathObject {
public:
  double a;
  csqrt(double num) { a = num; }
  friend ostream &operator<<(ostream &os, const csqrt &a) {
    cout << " √(" << a.a << ") ";
    return os;
  }
  double getValue() { return sqrt(a); }
};
