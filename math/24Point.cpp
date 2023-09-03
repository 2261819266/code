#include <algorithm>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <cmath>

bool St;

struct RegularExpression {
	using value_type = double;

	using operator_type = value_type(*)(const value_type &x, const value_type &y);
	
	operator_type addition = [](const value_type &x, const value_type &y) -> value_type { return x + y; };
	operator_type substraction = [](const value_type &x, const value_type &y) -> value_type { return x - y; };
	operator_type multiplication = [](const value_type &x, const value_type &y) -> value_type { return x * y; };
	operator_type division = [](const value_type &x, const value_type &y) -> value_type { return x / y; };

	struct ValOrOpt {
		int p;
		value_type x;
		operator_type f;
		
		ValOrOpt() {
			p = 0;
			x = 0;
			f = 0;
		}

		template<typename t> ValOrOpt(const t &__val) {
			*this = __val;
		}

		void operator=(const value_type &value) {
			x = value;
			p = 1;
			f = 0;
		}
		void operator=(const operator_type &opt) {
			f = opt;
			p = 2;
		}

		bool isValue() const {
			return p == 1;
		}

		bool isOperator() const {
			return p == 2;
		}

		operator value_type() { return x; }
		operator operator_type() { return f; }
	};

	std::vector<ValOrOpt> a;

	template<typename t> void push(const t &x) {
		a.push_back((ValOrOpt)(x));
	}

	void pop() { a.pop_back(); }

	value_type calculation() {
		std::stack<value_type> s;
 
		// if (a.front().isOperator()) return 0;

		for (ValOrOpt i : a) {
			if (i.isValue()) s.push(i);
			else if (i.isOperator()) {
				if (s.size() < 2) return 0;
				value_type first, second;
				second = s.top();
				s.pop();
				first = s.top();
				s.pop();
				operator_type f = i;
				s.push(f(first, second));
			} else return 0;
		}
		return s.size() != 1 ? 0 : s.top();
	}

	// void dfs(int i) {

	// }

	void print() {
		for (auto i : a) {
			if (i.isValue()) std::cout << i.x;
			else {
				if (i == addition) putchar('+');
				if (i == substraction) putchar('-');
				if (i == multiplication) putchar('*');
				if (i == division) putchar('/');
			}
			putchar(' ');
		}
		putchar(10);
	}
};

using value_type = RegularExpression::value_type;
using operator_type = RegularExpression::operator_type;
const RegularExpression __;
const operator_type addition = __.addition;
const operator_type substraction = __.substraction;
const operator_type multiplication = __.multiplication;
const operator_type division = __.division;
const std::vector<operator_type> opt = {addition, substraction, multiplication, division};
std::vector<value_type> val = {1, 6, 6, 8};
const double goal = 24, mis = 0.001;

void solve(std::vector<bool> valhad, int optnum = 1, RegularExpression now = {}) {
	if (optnum == val.size()) {
		double x = now.calculation();
		if (std::fabs(now.calculation() - goal) < mis) {
			now.print();
		}
		return;
	}
	
	for (int i = 0; i < val.size(); i++) {
		if (!valhad[i]) {
			valhad[i] = true;
			now.push(val[i]);
			solve(valhad, optnum, now);
			now.pop();
			valhad[i] = false;
		}
	}

	for (int i = 0; i < opt.size(); i++) {
		now.push(opt[i]);
		solve(valhad, optnum + 1, now);
		now.pop();
	}
}

bool solve_for_one_answer(std::vector<bool> valhad, int optnum = 1, RegularExpression now = {}) {
	if (optnum == val.size()) {
		double x = now.calculation();
		if (std::fabs(now.calculation() - goal) < mis) {
			now.print();
			return true;
		}
		return false;
	}

	bool k = false;
	
	for (int i = 0; i < val.size(); i++) {
		if (!valhad[i]) {
			valhad[i] = true;
			now.push(val[i]);
			k = solve_for_one_answer(valhad, optnum, now);
			now.pop();
			valhad[i] = false;
			if (k) return true;
		}
	}

	for (int i = 0; i < opt.size(); i++) {
		now.push(opt[i]);
		k = solve_for_one_answer(valhad, optnum + 1, now);
		now.pop();
		if (k) return true;
	}
	return false;
}

void search_for_answer_of_all_input() {
	int minx = 1, maxx = 4;
	scanf("%d%d", &minx, &maxx);
	int times = 0, all_times = 0, times_2 = 0;
	std::vector<bool> sv(4, false);
	for (int i = minx; i <= maxx; i++) {
		val[0] = i;
		for (int j = i; j <= maxx; j++) {
			val[1] = j;
			for (int k = j; k <= maxx; k++) {
				val[2] = k;
				for (int l = k; l <= maxx; l++) {
					sv.assign(4, false);
					val[3] = l;
					int x = solve_for_one_answer(sv);
					times += x;
					all_times++;
					std::vector<int> ti(maxx + 1, 0);
					{
						ti[i]++,ti[j]++,ti[k]++,ti[l]++;
						std::sort(ti.begin(), ti.end(), [](int _x, int _y) { return _x > _y; });
						if (ti[0] == 3) x *= 4;
						if (ti[1] == 2) x *= 6;
						if (ti[0] == 2 && ti[1] == 1) x *= 12;
						if (ti[0] == 1) x *= 24;
						times_2 += x;
					}
				}
			}
		}
	}
	printf("%.3lf%% %.3lf%%\n", times * 100.0 / all_times, times_2 * 100.0 / pow(maxx - minx + 1, 4));
}

void solve_math() {
	for (int i = 0; i < 4; i++) {
		scanf("%lf", &val[i]);
	}
	std::vector<bool> sv(4, false);
	// solve(sv);
	solve_for_one_answer(sv);
}

bool Ed;

int main() {
	std::cerr << (double)std::abs(&Ed - &St) / 1024.0 / 1024.0 << "Mb\n";
	// solve_math();
	search_for_answer_of_all_input();
	std::cerr << "\n" << double(clock()) / CLOCKS_PER_SEC << "s\n";
	return 0;
}

// int main() {
// 	RegularExpression a;
// 	a.a = {6, 1, 6, 8, a.division, a.substraction, a.division};
// 	printf("%lf", a.calculation());
// }