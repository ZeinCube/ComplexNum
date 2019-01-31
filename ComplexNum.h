#include <cmath>
#include <ostream>
#include <istream>
#include <memory>

//реализовать abs, arg
//декартовы координаты, полярные
//бинарные операторы
//unit-tests
//покрытие тестами lcov
//header, cpp ,main - тесты

using namespace std;

class ComplexNum {
 public:

  ComplexNum();

  explicit ComplexNum(double r);

  ComplexNum(double r, double i);

  ComplexNum(const ComplexNum &num);

  ~ComplexNum();

  double abs() const;

  ComplexNum& operator=(const ComplexNum &num);

  const ComplexNum& operator+=(const ComplexNum &num);

  const ComplexNum& operator-=(const ComplexNum &num);

  ComplexNum operator+(const ComplexNum &num);

  ComplexNum operator-(const ComplexNum &num);

  ComplexNum operator*(const ComplexNum &num);

  ComplexNum operator/(const ComplexNum &num);

  friend ostream& operator<<(ostream &out, const ComplexNum &c);

  friend istream& operator>>(istream &in, ComplexNum &c);

  bool operator==(const ComplexNum &num);

  const double arg() const;

 private:
  double re;
  double im;
};

class PolarComplex {

 public:
  PolarComplex();

  explicit PolarComplex(double ro);

  PolarComplex(double phi, double ro);

  PolarComplex(const PolarComplex &num);

  double get_ro() const;

  double get_phi() const;

  void set_ro(double r);

  void set_phi(double p);

  double abs(const double re, const double im);

  double arg(double re, double im);

  const PolarComplex& operator+=(const PolarComplex &num);

  const PolarComplex& operator-=(const PolarComplex &num);

  const PolarComplex& operator=(const PolarComplex &num);

  PolarComplex operator*(const PolarComplex &num);

  PolarComplex operator+(const PolarComplex &num);

  PolarComplex operator-(const PolarComplex &num);

  PolarComplex operator/(const PolarComplex &num);

  bool operator==(const PolarComplex &num);

  friend ostream& operator<<(ostream &st, const PolarComplex &num);

  friend istream& operator>>(istream &st, PolarComplex &num);

 private:
  double ro;
  double phi;
};

ComplexNum polarToCart(const PolarComplex &num);

PolarComplex cartToPolar(const ComplexNum &num);