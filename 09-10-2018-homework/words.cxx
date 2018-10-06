#include<iostream>
#include<vector>
#include<cstring>
#include<exception>
#include<iterator>
#include<cmath>

using namespace std;

template<class T> class Basic {
protected:
	vector<T> data_;
public:
	bool empty() {
		return !data_.size();
	}

	void push(T value) {
		data_.push_back(value);
	}

};

class Parentheses : public Basic<char> {
public:
		char pop() {
			if(empty())
				throw runtime_error("ERR: PROVIDE MATCHING PARENTHESES");
			char tmp = data_.back();
			data_.pop_back();
			return tmp;
		}
};

class Sentance : public Basic<string> {
	Parentheses parants_;
	int flags_;
public:
	Sentance(int flags) {
		flags_ = flags;
	}

	int get_cc() {
		int count = 0;
		for(vector<string>::iterator it = data_.begin(); it != data_.end(); it++) {
			count += (*it).size();
		}
		return count;
	}

	int get_wc() {
		return data_.size();
	}

	void check() {
		if (!parants_.empty()) {
			throw runtime_error("ERR: PROVIDE MATCHING PARENTHESES");
		}
	}

	void clean_up() {
		for(vector<string>::iterator it = data_.begin(); it != data_.end(); it++) {
			switch ((*it).back()) {
				case ',':
				case ';':
				case '.':
					(*it).pop_back();
					break;
				case ')':
					parants_.pop();
					break;
				case '(':
					parants_.push('(');
			}
		}
	}

	void reset() {
		data_.erase(data_.begin(), data_.end());
	}

};

class Text : public Basic<Sentance> {
public:
	int average_wc() {
		float wc = 0;
		for(vector<Sentance>::iterator it = data_.begin(); it != data_.end(); it++) {
			wc += (*it).get_wc();
		}
		return round(wc / data_.size());
	}
};

int main() {
	string word;
	Text text;
	Sentance sentance(0);
	while(true) {

		cin >> word;

		if (!word.compare("END")) {
			break;
		}
		if (word.compare("-")) {
			sentance.push(word);

			if (word.back() == '.') {
				try {
					sentance.clean_up();
					sentance.check();
				}
				catch(exception e) {
					cout << e.what();
				}
				text.push(sentance);
				sentance.reset();
			}
		}
	}
	cout << text.average_wc() << endl;
	return 0;
}
