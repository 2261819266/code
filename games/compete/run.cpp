#include <iostream>
#include <process.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace {

#define autotransform vector<string> args = transform(argc, argv);

	vector<string> split(const string &s) {
		vector<string> ret;
		using string_size = string::size_type ;
		string_size i = 0;

		while (i != s.size()) {
			while (i != s.size() && isspace(s[i]))
				++i;

			string_size j = i;

			while (j != s.size() && !isspace(s[j]))
				++j;

			if (i != j) {
				ret.push_back(s.substr(i, j - i));
				i = j;
			}
		}

		return ret;
	}

	vector<string> transform(int _argc, const char *_argv[]) {
		vector<string> result;
		for (int i = 1; i < _argc; ++i)
			result.push_back(_argv[i]);
		return result;
	}

	int run(string address) {
		string command = "g++ "+ address + " -o " + address.substr(0, address.size() - 3) + "exe";
		system(command.c_str());
		system((address.substr(0, address.size() - 3) + "exe").c_str());
		return 0;
	}

	int complite

}

int main(int argc, const char *argv[]) {
	autotransform;
	// run(args[0]);
	system("ls > out.out");
	return 0;
}