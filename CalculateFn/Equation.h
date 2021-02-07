#pragma once

#include <vector>
#include "Fraction.h"

// a[0]A + a[1]B + a[2]C + a[3]D = b

namespace Jeri {
  class Equation {
  public:
    using Int = typename long long;
    Equation(std::vector<Fraction<Int>>& sources, Fraction<Int> val) : key(sources), value(val) {
    }

    Equation(size_t length) : key(length, Fraction<Int>(0)), value(0) {
    }

    Equation(size_t length, const Fraction<Int>& rest) : key(length, Fraction<Int>(0)), value(rest) {
    }

    Equation operator * (const Fraction<Int>& mulpti) {
      int length = Length();
      Equation result(length, value * mulpti);
      for (int index = 0; index < length; ++index) {
        result[index] = key[index] * mulpti;
      }
      return result;
    }

    Equation operator +(const Equation& rhsConst) const {
      Equation& rhs = const_cast<Equation&>(rhsConst);
      int length = Length();
      Equation result(length, ConstValue() + rhs.Value());
      for (int index = 0; index < length; ++index) {
        result[index] = key[index] + rhs[index];
      }
      return result;
    }

    Equation operator -(const Equation& rhsConst)const {
      Equation& rhs = const_cast<Equation&>(rhsConst);
      int length = Length();
      Equation result(length, ConstValue() - rhs.Value());
      for (int index = 0; index < length; ++index) {
        result[index] = key[index] - rhs[index];
      }
      return result;
    }

    size_t Length() const {
      return key.size();
    }

    Fraction<Int>& operator [] (int index) {
      return key[index];
    }

    Fraction<Int>& Value() {
      return value;
    }

    const Fraction<Int>& ConstValue() const {
      return value;
    }

  private:
    std::vector<Fraction<Int>> key;
    Fraction<Int> value;
  };
}
