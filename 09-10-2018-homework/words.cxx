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

	void clear() {
		data_.erase(data_.begin(), data_.end());
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

class Sentence : public Basic<string> {
	Parentheses parants_;
	int flags_;
public:
	Sentence() {
		flags_ = 0;
	}

	void set_flags() {
		string tmp;
		cin >> tmp;
		if (!tmp.compare("strict")) {
			flags_ |= 0x100;
			set_flags();
		}
		else if (tmp.find("sentence-up-to:") != string::npos) {
			tmp.erase(tmp.begin(), tmp.begin()+15);
			flags_ |= stoi(tmp);
			set_flags();
		}
		else {
			push(tmp);
		}
	}

	int get_flags() {
		return flags_;
	}

	int get_wc() {
		return data_.size();
	}

	int get_cc() {
		int count = 0;
		for(vector<string>::iterator it = data_.begin(); it != data_.end(); it++) {
			count += (*it).size();
		}
		return count;
	}

	void check() {
		if (!parants_.empty()) {
			throw logic_error("ERR: PROVIDE MATCHING PARENTHESES");
		}
	}

	void clean_up() {
		int max_words = flags_ & 0xFF;
		if (max_words && data_.size() > max_words) {
			data_.resize(max_words);
		}

		for(vector<string>::iterator it = data_.begin(); it != data_.end(); it++) {
			switch ((*it).front()) {
				case ')':
					parants_.pop();
					break;
				case '(':
					parants_.push('(');
			}
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
		clear();
		parants_.clear();
	}

};

class Text : public Basic<Sentence> {
public:
	int average_wc() {
		float wc = 0;
		for(vector<Sentence>::iterator it = data_.begin(); it != data_.end(); it++) {
			wc += (*it).get_wc();
		}
		return round(wc / data_.size());
	}
};

int main() {
	string word;
	Text text;
	Sentence sentence;
	sentence.set_flags();
	while(true) {

		cin >> word;

		if (!word.compare("END")) {
			break;
		}
		if (word.compare("-")) {
			sentence.push(word);

			if (word.back() == '.') {
				try {
					sentence.clean_up();
					sentence.check();
				}
				catch(logic_error e) {
					if (sentence.get_flags() >> 8) {
						cout << e.what() << endl;
						return 1;
					}
				}
				text.push(sentence);
				sentence.reset();
			}
		}
	}
	cout << text.average_wc() << endl;
	return 0;
}
