#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 5e5;
vector<int> graph[SIZE];
bool choose[SIZE];
int city_num, road_num;

int search(int city, int choose_count) {
	if (city == city_num)
		return choose_count > 0;
	int counter = 0; 
	choose[city] = true;
	counter += search(city + 1, choose_count + 1);
	choose[city] = false;
	counter += search(city + 1, choose_count);
	return counter;
}

int main() {
	cin >> city_num >> road_num;
	for (int i = 0; i < road_num; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	
	cout << search(0, 0) << endl;
	return 0;
}
