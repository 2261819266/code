#include <iostream>
using namespace std;

const int SIZE = 250000;
int team1[SIZE], team2[SIZE];

int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	
	int t, person, match;
	cin >> t >> person;
	for (int i = 0; i < person; i++)
		cin >> team1[i];
	for (int i = 0; i < person; i++)
		cin >> team2[i];
	cin >> match;
	while (match--) {
		int l, r;
		cin >> l >> r;
		unsigned long long counter = 0;
		for (int p = l; p <= r; p++) {
			for (int q = p; q <= r; q++) {
				int max1 = 0, max2 = 0;
				for (int i = p; i <= q; i++) {
					max1 = max(max1, team1[i - 1]);
					max2 = max(max2, team2[i - 1]);
				}	
				counter += (unsigned long long)max1 * max2;
			}
		}
		cout << counter << endl;
	}
}
