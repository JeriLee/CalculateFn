#pragma once

#include <vector>
#include "Fraction.h"
typedef long long Int;

namespace Jeri {
  class Equation {
  public:

    Equation(std::vector<Fraction<Int>>& sources, Int val) : a(sources), result(val) {
    }

    Equation(size_t length) : a(length, Fraction<Int>(0)), result(0) {
    }

    void Add(const Equation& rhs, const Fraction<Int>& mulpti) {
      int length = Length();
      for (int index = 0; index < length; ++index) {
        //a[index] += rhs
      }
    }

    //static Equation operator *(const Equation& first, const Equation& second) {
    //  return Equation(1);
    //}

    Equation operator * (const Fraction<Int>& mulpti) {
      int length = Length();
      Equation result(length);
      for (int index = 0; index < length; ++index) {
        result[index] = a[index] * mulpti;
      }
      return result;
    }

    Equation operator +(const Equation& rhsConst) const {
      Equation& rhs = const_cast<Equation&>(rhsConst);
      int length = Length();
      Equation result(length);
      for (int index = 0; index < length; ++index) {
        result[index] = a[index] + rhs[index];
      }
      return result;
    }

    size_t Length() const {
      return a.size();
    }

    Fraction<Int>& operator [] (int index) {
      return a[index];
    }

  private:
    std::vector<Fraction<Int>> a;
    int result;
  };
}
