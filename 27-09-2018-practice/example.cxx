#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>

#define STRICT 1
#define INTEGERS 2

using namespace std;

class ReadExeption {
	string msg_;
public:
	ReadExeption(string msg) {
		msg_ = msg;
	}

	string get() {
		return msg_;
	}
};

class Reader {
	vector<float> v_;
	short flags_;
	string file_name_;
public:
	Reader(string file_name, short flags) {
		file_name_ = file_name;
		flags_ = flags;
	}

	void read() {
		ifstream file(file_name_);
		if(!file.is_open()) {
			throw ReadExeption("Cannot open file");
		}

		float a;

		while (true) {
			file >> a;

			if (file.eof())
				break;

			if (flags_ & INTEGERS && (int) a != a) {
				throw ReadExeption("ERR: PROVIDE ONLY INTEGERS");
			}

			if (!file) {
				if (flags_ & STRICT) {
					throw ReadExeption("ERR: PROVIDE ONLY NUMBERS");
				}
				file.clear();
				file.ignore(numeric_limits<streamsize>::max(), ' ');	// Some black magic
			} else {		// If it gets to str a sets to 0 for one cicle
				v_.push_back(a);
			}
		}
		file.close();
		sort(v_.begin(), v_.end());
	}

	void write() {
		cout << v_[0] << ' ';
		cout << v_[v_.size()-1] << ' ';
		float sum = 0;
		for (int i = 0; i < v_.size(); ++i) {
			sum += v_[i];
		}
		cout << sum / v_.size() << endl;
	}
};

int main(int argc, char *argv[]) {

	short flags = 0;

	if (argc == 4) {
		flags |= STRICT;
		flags |= INTEGERS;
	} else if (argc == 3) {
		if (argv[2][2] == 's')
			flags |= STRICT;
		else
			flags |= INTEGERS;
	}

	Reader r(argv[1], flags);
	try {
		r.read();
		r.write();
	} catch(ReadExeption e) {
		cout << e.get() << endl;
	}

	return 0;
}
