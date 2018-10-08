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
		void check() {
			if (!empty())
				throw logic_error("ERR: PROVIDE MATCHING PARENTHESES");
		}

        char pop() {
            if(empty())
                throw logic_error("ERR: PROVIDE MATCHING PARENTHESES");
            char tmp = data_.back();
            data_.pop_back();
            return tmp;
        }
};

class Sentence : public Basic<string> {
    Parentheses parantheses_;
    int flags_;
public:
    Sentence() {
        flags_ = 0;
    }

    string set_flags() {  // Returns the first word after flags
        string tmp;
        cin >> tmp;
        if (!tmp.compare("strict")) {
            flags_ |= 0x100;
            return set_flags();
        }
        else if (tmp.find("sentences-up-to:") != string::npos) {
            tmp.erase(tmp.begin(), tmp.begin()+16);
            flags_ |= stoi(tmp);
            return set_flags();
        }
        else if (!tmp.compare("END")) {
            throw runtime_error("ERR: PROVIDE AT LEAST ONE SENTENCE OR WORD");
        }
		return tmp;
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

    void check_parantheses() {
        parantheses_.check();
    }

	bool check_length() {
        int max_words = flags_ & 0xFF;
        if (max_words && data_.size() > max_words) {
            return false;
        }
		return true;
	}

    void clean_up() {

        for(vector<string>::iterator it = data_.begin(); it != data_.end(); it++) {
            while(true) {
                switch ((*it).back()) {
                    case ',':
                    case ';':
                    case '.':
                        (*it).pop_back();
                        continue;
                }

                if ((*it).front() == '(') {
                    parantheses_.push('(');
                    (*it).erase((*it).begin());  // pop_front()
                    continue;
                }
                if ((*it).back() == ')') {
                    parantheses_.pop();
                    (*it).pop_back();
                    continue;
                }
                break;
            }
        }
    }

    void reset() {
        clear();
        parantheses_.clear();
    }

};

class Text : public Basic<Sentence> {
    float wc_, cc_;  // So that we can round it
public:
    Text() {
        wc_ = 0;
        cc_ = 0;
    }

    void calculate() {
        for(vector<Sentence>::iterator it = data_.begin(); it != data_.end(); it++) {
            wc_ += (*it).get_wc();
            cc_ += (*it).get_cc();
        }
    }

    int average_wc() {
        return round((float)wc_ / data_.size());
    }

    int average_cc() {
        return round((float)cc_ / wc_);
    }
};

int main() {
    string word;
	Sentence sentence;
    Text text;
    try {
        word = sentence.set_flags();
    }
    catch(runtime_error e) {
        cout << e.what() << endl;
        return 1;
    }
    while(true) {

        if (!word.compare("END")) {
            break;
        }
        if (word.compare("-")) {
            sentence.push(word);

            if (word.back() == '.') {
                try {
                    if (sentence.check_length()) {
						sentence.clean_up();
						sentence.check_parantheses();
						text.push(sentence);
					}
					sentence.reset();
                }
                catch(logic_error e) {
                    if (sentence.get_flags() >> 8) {
                        cout << e.what() << endl;
                        return 1;
                    }
                }
            }
        }

		cin >> word;
    }

    text.calculate();
    cout << text.average_wc() << ' ' << text.average_cc() << endl;
    return 0;
}
