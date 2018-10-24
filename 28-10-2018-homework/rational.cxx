#include<iostream>
#include<exception>

using namespace std;

class quit_signal {};  // Throwable for easy quit

class Rational {
	long den_, num_;

	void standardize() {  // Makes den_ positive
		if (den_ < 0) {
			den_ *= -1;
			num_ *= -1;
		}
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
	Rational(const long num=1, const long den=1) {
		if (!den)  // Check for invalid den_
			throw runtime_error("Provide non-zero den...");

		num_ = num;
		den_ = den;
	}

	void reduce() {
		standardize();
		long tmp = num_ < 0 ? -num_ : num_;
		long r = gcd(tmp, den_);
		num_ /= r;
		den_ /= r;
	}

	friend istream& operator>>(istream& is, Rational& r) {
		long num, den;
		char c;

        is >> c;

        if (c == 'q')
            throw quit_signal();

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
	}

	void operator-=(const Rational r) {
		num_ = num_ * r.den_ - r.num_ * den_;
		den_ = den_ * r.den_;
	}

	void operator*=(const Rational r) {
		num_ *= r.num_;
        den_ *= r.den_;
	}

	void operator/=(const Rational r) {
		num_ *= r.den_;
		den_ *= r.num_;
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

        if (operation == '=') {
            result.reduce();
            return result;
        }

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
