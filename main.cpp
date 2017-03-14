#define VNAME(name) (#name)
#include "basic_headers.h"
#include "definitions.h"

int main() {
  point A, B, C;
  A.initPoint(1, 2);
  B.initPoint(0, 0);
  C.initPoint(1, 3);

  line a, b;
  a.initLine(A, B);
  b.initLine(C, B);

  linearPair alp;
  alp.initLP(a, b);

  frac f(1.2, 1);
  cout << f << endl;
}
