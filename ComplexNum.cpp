#include <cmath>
#include <ostream>
#include <istream>
#include <memory>
#include <cmath>
#include "ComplexNum.h"
using namespace std;

//реализовать abs, arg
//декартовы координаты, полярные
//бинарные операторы
//unit-tests
//покрытие тестами lcov
//header, cpp ,main - тесты

using namespace std;

  ComplexNum::ComplexNum() {};

  ComplexNum::ComplexNum (double r) {
    re = r;
    im = 0;
  }

  ComplexNum::ComplexNum (double r, double i) {
    re = r;
    im = i;
  }

  ComplexNum::ComplexNum (const ComplexNum& num) {
    re = num.re;
    im = num.im;
  }

  ComplexNum::~ComplexNum() = default;

  double ComplexNum::abs () const {  // module
    return sqrt((re * re + im * im));
  }

  ComplexNum& ComplexNum::operator = (const ComplexNum& num) {
    re = num.re;
    im = num.im;
    return *this;
  }

  const ComplexNum& ComplexNum::operator += (const ComplexNum& num) {
    re += num.re;
    im += num.im;
    return *this;
  }

  const ComplexNum& ComplexNum::operator -= (const ComplexNum& num){
    re -= num.re;
    im -= num.im;
    return *this;
  }

  ComplexNum ComplexNum::operator + (const ComplexNum& num) {
    return ComplexNum(re + num.re, im + num.im);
  }

  ComplexNum ComplexNum::operator - (const ComplexNum& num) {
    return ComplexNum(re - num.re, im - num.im);
  }

  ComplexNum ComplexNum::operator * (const ComplexNum& num) {
    return ComplexNum(re * num.re, im * num.im);
  }

  ComplexNum ComplexNum::operator / (const ComplexNum& num) {
    double r = num.re * num.re + num.im * num.im;
    double re = (this->re * num.re + im * num.im) / r;
    double im = (this->im * num.re - this->re * num.im) / r;
    return ComplexNum(re,im);
  }

  ostream& operator << (ostream& out, const ComplexNum& c) {
    out << "( " << c.re << ", " << c.im << ")";
    return out;
  }

  istream& operator >> (istream& in, ComplexNum& c) {
    in >> c.re >> c.im;
    return in;
  }

  bool ComplexNum::operator==(const ComplexNum& right_op) const{
    return (std::abs(this->re - right_op.re) < 0.00001 &&
            std::abs(this->im - right_op.im) < 0.00001);
  }

  void ComplexNum::set_im(double i) {
      this->im = i;
  }

  void ComplexNum::set_re(double r){
      this->re = r;
  }

  double ComplexNum::get_im() const {
    return this->im;
  }

  double ComplexNum::get_re() const{
    return this->re;
  }

  const double ComplexNum::arg() const {
      return atan2(this->im, this->re);
  }

  ComplexNum polarToCart(const PolarComplex &num) {
    double x = num.get_ro() * cos(num.get_phi());
    double y = num.get_ro() * sin(num.get_phi());
    return ComplexNum(x, y);
  }

  PolarComplex cartToPolar(const ComplexNum &num) {
    return PolarComplex(num.abs(), num.arg());
  }

  //Polar Complex

  PolarComplex::PolarComplex() {}

  PolarComplex::PolarComplex(double r) {
    phi = 0;
    ro = std::abs(r);
  }

  PolarComplex::PolarComplex(double ro, double phi) {
    this->ro = std::abs(ro);
    this->phi = phi;
  }

  PolarComplex::PolarComplex(const PolarComplex &num) {
    phi = std::abs(num.phi);
    ro = num.ro;
  }

  const PolarComplex& PolarComplex::operator+=(const PolarComplex &num) {
    ComplexNum buff = polarToCart(*this) + polarToCart(num);
    this->ro = cartToPolar(buff).ro;
    this->phi = cartToPolar(buff).phi;
    return *this;
  }

  const PolarComplex& PolarComplex::operator-=(const PolarComplex &num) {
    ComplexNum buff = polarToCart(*this) - polarToCart(num);
    this->ro = cartToPolar(buff).ro;
    this->phi = cartToPolar(buff).phi;
    return *this;
  }

  const PolarComplex& PolarComplex::operator=(const PolarComplex &num) {
    this->ro = std::abs(num.ro);
    this->phi = num.phi;
    return *this;
  }

  PolarComplex PolarComplex::operator*(const PolarComplex &num) {
    return PolarComplex(std::abs(this->ro * num.ro), this->phi + num.phi);
  }

  PolarComplex PolarComplex::operator+(const PolarComplex &num) {
    ComplexNum buff = polarToCart(*this) + polarToCart(num);
    return cartToPolar(buff);
  }

  PolarComplex PolarComplex::operator-(const PolarComplex &num) {
    ComplexNum buff = polarToCart(*this) - polarToCart(num);
    return cartToPolar(buff);
  }

  PolarComplex PolarComplex::operator/(const PolarComplex &num) {
    return PolarComplex(std::abs(this->ro / num.ro), this->phi - num.phi);
  }

  ostream& operator<<(ostream &st, const PolarComplex &num) {
    st << "(ro=" << num.ro << ",phi=" << num.phi <<")";
    return st;
  }

  istream& operator>>(istream &st, PolarComplex &num) {
    st >> num.ro >> num.phi;
    return st;
  }

  double PolarComplex::abs(){
    return sqrt(this->ro * this->ro + this->phi * this->phi);
  }

  bool PolarComplex::operator==(const PolarComplex &num) const {
    return (polarToCart(*this) == polarToCart(num));
  }

  double PolarComplex::arg() {
    return atan2(this->phi, this->ro) * 180 / M_PI;
  }

  double PolarComplex::get_ro() const {
    return std::abs(ro);
  }

  double PolarComplex::get_phi() const {
    return this->phi;
  }

  void PolarComplex::set_phi(double p) {
    this->phi = p;
  }

  void PolarComplex::set_ro(double r) {
    this->ro = std::abs(r);
  }