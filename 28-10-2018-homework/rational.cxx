#include<iostream>

using namespace std;

class Rational {
	long den_, num_;

	void standardize() {
		if (den_ < 0) {
			den_ *= -1;
			num_ *= -1;
		}
	}

	void reduce() {
		standardize();
		long tmp = num_ < 0 ? -num_ : num_;
		long r = gcd(tmp, den_);
		num_ /= r;
		den_ /= r;
	}

	long gcd(long a, long b) {
		long r = a % b;
		while(r) {
			a = b;
			b = r;
			r = a % b;
		}
		return b;
	}

public:
	Rational(long num, long den) {
		if (!den)
			throw runtime_error("Provide non-zero den...");

		num_ = num;
		den_ = den;
	}

	friend istream& operator>>(istream& is, Rational& r) {
		long num, den;
		char c;
		is >> c;
		if (c != '(') {
			is.clear(ios_base::badbit);
			return is;
		}
		is >> num >> c;
		if (c != '/') {
			is.clear(ios_base::badbit);
			return is;
		}
		is >> den >> c;
		if (c != ')') {
			is.clear(ios_base::badbit);
		}
		return is;
	}

	friend ostream& operator<<(ostream& os, Rational& r) {
		r.reduce();
		os << '(' << r.num_ << '/' << r.den_ << ')' << endl;
		return os;
	}

	void operator+=(Rational r) {
		num_ = num_ * r.den_ + r.num_ * den_;
		den_ = den_ * r.den_;
	}

	void operator-=(Rational r) {
		num_ = num_ * r.den_ - r.num_ * den_;
		den_ = den_ * r.den_;
	}

	void operator*=(Rational r) {
		num_ *= r.num_;
		den_ *= r.den_;
	}

	void operator/=(Rational r) {
		num_ *= r.den_;
		den_ *= r.num_;
	}

};


int main() {
	Rational r1(1, 2);
	Rational r2(2, 4);
	Rational r3(3, -6);

	cout << r1;
	cout << r2;
	cout << r3;


	r1 += r2;
	cout << r1;

	return 0;
}
