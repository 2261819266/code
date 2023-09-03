#include <cstddef>
#include <cstdio>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

struct ACAutomaton {
	using size_t = std::size_t;
	struct Node {
		using value_type = Node*;
		using list_type = std::vector<value_type>;
		list_type c;
		size_t cnt;
		void clear() {
			c.clear();
			cnt = 0;
		}

		void assign(size_t n, value_type val) {
			clear();
			c.assign(n, val);
		}

		Node(size_t n, value_type val) {
			this->assign(n, val);
			list_type x(10);
		}

		Node() {
			this->assign(26, 0);
		}

		value_type &operator[](int x) {
			return c[x];
		}
	};
	using value_type = Node;
	using list_type = std::vector<value_type>;
	using string_type = std::string;
	using string_list_type = std::vector<string_type>;
	// using turn_type = size_t(*)(size_t);
	list_type a;
	value_type empty;
	value_type root;
	// turn_type turn_on, turn_off;
	// turn_type turn_none = [](size_t x) { return x; };

	void clear() {
		a.clear();
	}

	void build_root() {
		clear();
		a.push_back(empty);
		// turn_on = turn_off = turn_none;
	}

	

	// void set_config(turn_type t1, turn_type t2) {
	// 	turn_on = t1, turn_off = t2;
	// }

	ACAutomaton(
		// turn_type t1 = nullptr, turn_type t2 = nullptr
	) {
		build_root();
		// if (t1) turn_on = t1;
		// if (t2) turn_off = t2;
	}
} a;

int main() {
	// a.turn_off(1);
}