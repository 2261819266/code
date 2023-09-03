#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 300;
vector<int> stack[SIZE], cards;
vector<pair<pair<int, int>, int>> tot_steps;
int stack_num, card_num, pattern_num;

bool search(int steps) {
	if (steps > 2 * card_num)
		return false;
	bool flag = cards.empty();
	for (int i = 0; i < stack_num; i++) {
		if (!stack[i].empty() || !flag) {
			flag = false;
			break;
		}
	}
	if (flag && card_num <= steps) {
		cout << steps << endl;
		for (int i = 0; i < steps; i++)
			if (tot_steps[i].first.first == 1)
				cout << "1 " << tot_steps[i].first.second << endl;
			else
				cout << "2 " << tot_steps[i].first.second << ' ' << tot_steps[i].second << endl;
		return true;
	}
	for (int i = 0; i < stack_num; i++)
	{
		bool is_same = false;
		int last = cards[card_num - 1];
		if (stack[i].size() >= 1)
			is_same = last == stack[i][stack[i].size() - 1];
		if (is_same)
			stack[i].pop_back();
		else
			stack[i].push_back(last);
		cards.pop_back();
		tot_steps.push_back({{1, i + 1}, 0});
		bool result = search(steps + 1);
		if (is_same)
			stack[i].push_back(last);
		else
			stack[i].pop_back();
		cards.push_back(last);
		tot_steps.pop_back();
		if (result)
			return true;
	}
	for (int i = 0; i < stack_num; i++)
	{
		if (stack[i].empty())
			continue;
		for (int j = i + 1; j < stack_num; j++) {
			if (stack[j].empty() || stack[i][0] != stack[j][0])
				continue;
			int last = stack[i][0];
			tot_steps.push_back({{2, i + 1}, j + 1});
			stack[i].erase(stack[i].begin());
			stack[j].erase(stack[j].begin());
			bool result = search(steps + 1);
			tot_steps.pop_back();
			stack[i].insert(stack[i].begin(), last);
			stack[j].insert(stack[j].begin(), last);
			if (result)
				return true;
		}
	}
	return false;
}

int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	
	int t;
	cin >> t;
	while (t--) {
		cin >> stack_num >> card_num >> pattern_num;
		for (int i = 0; i < card_num; i++)
		{
			int card;
			cin >> card;
			cards.push_back(card);
		}
		search(1);
	}
}
