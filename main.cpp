#define VNAME(name) (#name)
#include "basic_headers.h"
#include "geo_definitions.h"

int main(){
      formula a,b,c;
      a.initFormula("y=-3x^2-2x-3");
      b.initFormula(-3,2,1);
      c.initFormula(3);
        a.printFormula(); 
      b.printFormula();
      c.printFormula();
}