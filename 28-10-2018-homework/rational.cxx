#include<iostream>
#include<exception>

using namespace std;

class quit_signal {};

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
	Rational(long num=1, long den=1) {
		if (!den)
			throw runtime_error("Provide non-zero den...");

		num_ = num;
		den_ = den;
	}

	friend istream& operator>>(istream& is, Rational& r) {
		long num, den;
		char c;

        is >> c;

        if (c == 'q') {
            throw quit_signal();
        }

		is >> num >> c;
        is >> den >> c;

        r = Rational(num, den);
		return is;
	}

	friend ostream& operator<<(ostream& os, const Rational& r) {
		os << '(' << r.num_ << '/' << r.den_ << ')' << endl;
		return os;
	}

	void operator+=(const Rational r) {
		num_ = num_ * r.den_ + r.num_ * den_;
		den_ = den_ * r.den_;
        reduce();
	}

	void operator-=(const Rational r) {
		num_ = num_ * r.den_ - r.num_ * den_;
		den_ = den_ * r.den_;
        reduce();
	}

	void operator*=(const Rational r) {
		num_ *= r.num_;
        den_ *= r.den_;
        reduce();
	}

	void operator/=(const Rational r) {
		num_ *= r.den_;
		den_ *= r.num_;
        reduce();
	}

};

Rational evaluate_eq();

int main() {
    while(1) {
        try {
            cout << evaluate_eq();
        }catch(quit_signal s) {
            break;
        }
    }
    return 0;
}

Rational evaluate_eq() {
	Rational operand, result;
    char operation;

    cout << "> ";
    cin >> result;

    while(true) {
        cin >> operation;

        if (operation == '=')
            return result;

        cin >> operand;

        switch(operation) {
        case '+':
            result += operand;
            break;
        case '-':
            result -= operand;
            break;
        case '*':
            result *= operand;
            break;
        case '/':
            result /= operand;
            break;
        }
    }
}
