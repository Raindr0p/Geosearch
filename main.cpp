#define VNAME(name) (#name)
#include "basic_headers.h"
#include "geo_definitions.h"

int main(){
      formula a;
      a.initFormula("y=-3x^2-2x-3");
      a.printFormula();
}