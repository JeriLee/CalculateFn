#pragma once

#include <stdint.h>

namespace Jeri {
  template<typename T>
  class Fraction {
  private:
    T numberator_;
    T denominator_;

  public:
    explicit Fraction(T x = 0) :numberator_(x), denominator_(1) {
    }

    Fraction(T x, T y) :numberator_(x), denominator_(y) {
      if (y == 0) throw 0xfe;
      if (x == 0) numberator_ = 0, denominator_ = 1;
      else {
        T g = Gcd(numberator_, denominator_);
        numberator_ /= g;
        denominator_ /= g;
      }
    }

    T GetDenominator() {
      return denominator_;
    }

    T GetNumberator() {
      return numberator_;
    }

    operator double() {
      return numberator_ / (double)denominator_;
    }

    Fraction operator + (const Fraction& rhs) const {
      T lcm = Lcm(denominator_, rhs.denominator_);
      return Fraction(lcm / denominator_ * numberator_ + lcm / rhs.denominator_ * rhs.numberator_, lcm);
    }

    Fraction operator - (const Fraction& rhs) {
      T lcm = Lcm(denominator_, rhs.denominator_);
      return Fraction(lcm / denominator_ * numberator_ - lcm / rhs.denominator_ * rhs.numberator_, lcm);
    }

    Fraction operator * (const Fraction& rhs) {
      T gcd1 = Gcd(numberator_, rhs.denominator_);
      T gcd2 = Gcd(denominator_, rhs.numberator_);
      return Fraction((numberator_ / gcd1) * (rhs.numberator_ / gcd2), (rhs.denominator_ / gcd1) * (denominator_ / gcd2));
    }

    Fraction operator / (const Fraction& rhs) {
      return (*this) * Fraction(rhs.denominator_, rhs.numberator_);
    }

    bool operator == (int val) {
      return denominator_ == 1 && numberator_ == val;
    }

    bool operator == (const Fraction& rhs) {
      return denominator_ == rhs.denominator_ && numberator_ == rhs.numberator_;
    }

    ~Fraction() {
    }

  private:
    static T Gcd(T a, T b) {
      return b == 0 ? a : Gcd(b, a % b);
    }

    static T Lcm(T a, T b) {
      return a / Gcd(a, b) * b;
    }
  };

  class FractionInt : public Fraction<int32_t> {
  public:
    FractionInt(int32_t x, int32_t y) : Fraction(x, y) {
    }
    FractionInt(const Fraction<int32_t>& source) : Fraction(source) {
    }
  };

  class FractionLong : public Fraction<int64_t> {
  };
}

