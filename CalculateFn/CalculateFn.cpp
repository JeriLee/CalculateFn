#include <iostream>
#include "Fraction.h"

using namespace Jeri;
using namespace std;

int main()
{
  Fraction<int> frac(4, 6);
  Fraction<int> frac2(9, 6);
  cout << frac.GetNumberator() << " " << frac.GetDenominator() << endl;
  Fraction<int> re = frac + frac2;
  cout << re.GetNumberator() << " " << re.GetDenominator() << endl;
  FractionInt re2 = re;
  cout << re2.GetNumberator() << " " << re2.GetDenominator() << endl;

}
