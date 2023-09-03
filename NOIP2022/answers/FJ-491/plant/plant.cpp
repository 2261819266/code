#include <iostream>
#include <string>
using namespace std;

const int SIZE = 1000, mod = 998244353;
bool map[SIZE][SIZE];

int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);

	int groups, id, length, width;
	long long c, f;
	string line;
	cin >> groups >> id;
	while (groups--) {
		cin >> length >> width >> c >> f;
		for (int i = 0; i < length; i++) {
			cin >> line;
			for (int j = 0; j < width; j++)
				map[i][j] = line[j] - '0';
		}
		
		// C-
		int counter_c = 0;
		for (int col = 0; col < width; col++) {
			for (int start = 0; start < length - 2; start++) {
				if (map[start][col])
					continue;
				for (int end = start + 2; end < length; end++) {
					bool flag = true;
					for (int i = start; i <= end; i++) {
						if (map[i][col]) {
							flag = false;
							break;
						}
					}
					if (!flag)
						continue;
					int s_cols = col + 1, e_cols = col + 1;
					for (; s_cols < width && !map[start][s_cols]; s_cols++);
					for (; e_cols < width && !map[end][e_cols]; e_cols++);
					counter_c += (s_cols - col - 1) * (e_cols - col - 1);
				}
			}
		}
		
		// F-
		int counter_f = 0;
		for (int col = 0; col < width; col++) {
			for (int start = 0; start < length - 3; start++) {
				if (map[start][col])
					continue;
				for (int end = start + 3; end < length; end++) {
					bool flag = true;
					for (int i = start; i <= end; i++) {
						if (map[i][col]) {
							flag = false;
							break;
						}
					}
					if (!flag)
						continue;
					int s_cols = col + 1;
					for (; s_cols < width && !map[start][s_cols]; s_cols++);
					for (int other = start + 2; other < end; other++) {
						int o_cols = col + 1;
						for (; o_cols < width && !map[other][o_cols]; o_cols++);
						counter_f += (s_cols - col - 1) * (o_cols - col - 1);
					}
				}
			}
		}
		
		cout << (counter_c * c) % mod << ' ' << (counter_f * f) % mod << endl;
	}
	return 0;
}
