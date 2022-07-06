// C++ Version
#include <cstdio>
#include <iostream>
#include <string>
using std::string;

const int M = 1e9 + 7;
const int B = 233;

typedef long long ll;

ll get_hash(const string &s) {
	int res = 0;
	for (int i = 0; i < s.size(); ++i) {
		res = (ll)(res * B + s[i]) % M;
	}
	return res;
}

bool cmp(const string &s, const string &t) { return get_hash(s) == get_hash(t); }
// from OI wiki (https://oiwiki.org/string/hash/)

#define KK

int main(int argc, char const *argv[]) {
	string s, t;
#ifdef KK
	while (true) std::cin >> s, std::cout << get_hash(s) << std::endl;
#else
	while (true) std::cin >> s >> t, std::cout << cmp(s, t) << std::endl;
#endif
	printf("size : %d\n", sizeof(s));
}
