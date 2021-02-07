#include <iostream>
#include <vector>

#include "Fraction.h"
#include "Equation.h"
#include "Determinant.h"

using namespace Jeri;
using namespace std;
using Int = typename long long;

std::vector<int> ReadInput() {
  int n, x;
  std::vector<int> ret;
  cout << "请输入数列长度" << endl;
  cin >> n;
  cout << "请输入数列" << endl;
  while (n-- > 0) {
    cin >> x;
    ret.push_back(x);
  }
  return ret;
}

Int Exp(Int a, Int p) {
  return p == 0 ? 1 : Exp(a, p - 1) * a;
}

std::vector<Fraction<Int>> EquationKey(Int key, Int length) {
  std::vector<Fraction<Int>> keys;
  for (int index = length - 1; index >= 0; --index) {
    keys.push_back(Fraction<Int>(Exp(key, index)));
  }
  return keys;
}

int main()
{
  auto input = ReadInput();
  input.push_back(114514);
  int length = input.size();
  int funcCount = length;

  Determinant determinant;
  for (int index = 1; index <= funcCount; ++index) {
    std::vector<Fraction<Int>> equationKey = EquationKey(index, length);
    Equation equation(equationKey, Fraction<Int>(input[index - 1]));
    determinant.Add(equation);
  }
  //cout << "构造行列式" << endl;
  //determinant.Print();

  determinant.Solve();
  /*
  cout << endl;
  cout << endl;
  cout << "行列式结果： " << endl;
  determinant.Print();
  cout << endl;
  cout << endl;
  */
  
  cout << "第" << (length) << "个数是 114514" << endl;
  cout << "方程的解： " << endl;
  determinant.PrintAnswer();
  cout << endl;
  cout << "输入回车结束" << endl;
  cin.get();
  cin.get();
  return 0;
}
