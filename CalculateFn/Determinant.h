#pragma once

#include <vector>
#include "Equation.h"
#include <iostream>
#include <cassert>

namespace Jeri {
  class Determinant {
  public:
    Determinant() {
    }

    void Add(const Equation& rhs) {
      funcs.push_back(rhs);
    }

    void Print() {
      for (auto& item : funcs) {
        Print(item);
      }
    }

    void PrintAnswer() {
      int n = N();
      int m = M();
      assert(n == m);
      std::cout << "f(x) = ";
      for (int col = 0; col < n; ++col) {
        if (col != 0) std::cout << " + ";
        std::cout << (funcs[col].Value() / funcs[col][col]).ToString();
        std::cout << "(X^" << n - col - 1 << ")";
      }
      std::cout << std::endl;
    }

    void Solve() {
      int n = N();
      int m = M();
      assert(n == m);
      for (int col = 0; col < n; ++col) {
        if (funcs[col][col] == 0) {
          for (int nextRaw = col + 1; nextRaw < n; ++nextRaw) {
            if (funcs[nextRaw][col] == 0) continue;
            std::swap(funcs[col], funcs[nextRaw]);
          }
        }
        if (funcs[col][col] == 0) continue;

        for (int nextRaw = col + 1; nextRaw < n; ++nextRaw) {
          if (funcs[nextRaw][col] == 0) continue;
          auto beilv = funcs[nextRaw][col] / funcs[col][col];
          funcs[nextRaw] = funcs[nextRaw] - funcs[col] * beilv;
        }
      }

      for (int col = n - 1; col > 0; col--) {
        if (funcs[col][col] != 0) {
          for (int lastRaw = col - 1; lastRaw >= 0; --lastRaw) {
            if (funcs[lastRaw][col] == 0) continue;
            auto beilv = funcs[lastRaw][col] / funcs[col][col];
            funcs[lastRaw] = funcs[lastRaw] - funcs[col] * beilv;
          }
        } else {

        }
      }
    }

  private:
    void Print(Equation& equation) {
      int length = equation.Length();
      for (int index = 0; index < length; ++index) {
        std::cout << equation[index].ToString() << " ";
      }
      std::cout << " = " << equation.Value().ToString() << std::endl;
    }

    int M() {
      return funcs.front().Length();
    }

    int N() {
      return funcs.size();
    }
  private:
    std::vector<Equation> funcs;
  };

}