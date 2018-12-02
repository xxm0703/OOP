#include<iostream>

using namespace std;

class Rational {
	long den_, num_;
	friend Rational add(Rational, Rational);
	friend Rational sub(Rational, Rational);
	friend Rational mul(Rational, Rational);
	friend Rational div(Rational, Rational);

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

	void dump() {
		reduce();
		cout << '(' << num_ << '/' << den_ << ')' << endl;
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

	void add(Rational r) {
		num_ = num_ * r.den_ + r.num_ * den_;
		den_ = den_ * r.den_;
	}

	void sub(Rational r) {
		num_ = num_ * r.den_ - r.num_ * den_;
		den_ = den_ * r.den_;
	}

	void mul(Rational r) {
		num_ *= r.num_;
		den_ *= r.den_;
	}

	void div(Rational r) {
		num_ *= r.den_;
		den_ *= r.num_;
	}
};

Rational add(Rational a, Rational b) {
	long num = a.num_ * b.den_ + b.num_ * a.den_;
	long den = a.den_ * b.den_;
	Rational r(num, den);
	return r;
}

Rational sub(Rational a, Rational b) {
	long num = a.num_ * b.den_ - b.num_ * a.den_;
	long den = a.den_ * b.den_;
	Rational r(num, den);
	return r;
}

Rational mul(Rational a, Rational b) {
	long num = a.num_ * b.num_;
	long den = a.den_ * b.den_;
	Rational r(num, den);
	return r;
}

Rational div(Rational a, Rational b) {
	long num = a.num_ * b.den_;
	long den = a.den_ * b.num_;
	Rational r(num, den);
	return r;
}

int main() {
	Rational r1(1, 2);
	Rational r2(2, 4);
	Rational r3(3, -6);

	r1.dump();
	r2.dump();
	r3.dump();

	add(r1, r2).dump();

	r1 += r2;
	r1.dump();

	r1.mul(r3);
	r1.dump();

	return 0;
}
