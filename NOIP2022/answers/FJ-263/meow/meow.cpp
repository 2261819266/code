#include <iostream>
#include <cstdio>
#include <queue>
#include <memory.h>
#include <conio.h>
using namespace std;
deque<int> slot[301];

int T, n, m, k;	//tests, slots, cards, types
queue<int> cards;

int main() {
//	freopen("meow.in", "r", stdin);
//	freopen("meow.out", "w", stdout);
	scanf("%d", &T);
	for(int t = 0; t < T; t++) {
		//reset

		//input
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 0, a; i < m; i++) {
			scanf("%d", &a);
			cards.push(a);
		}
		//operate
		while(!cards.empty() ) {
			bool op = false;
			for(int i = 0; i < n; i++) {
					//operation 1
					if(!slot[i].empty() && slot[i].front() == cards.front() ) {
						printf("1 %d\n", 1 + i);
						op = true;
						slot[i].pop_front();
						cards.pop();

					}
					//operation 2
					if(!slot[i].empty() && slot[i].back() == cards.front() ) {
						for(int j = 0; j < n; j++) {
							if(slot[j].empty() == true && i != j) {
								slot[i].pop_back();
								cards.pop();
								printf("1 %d\n", j + 1);
								printf("2 %d %d\n", i + 1, j + 1);
								op = true;
							}
						}
					}

			}
			//no operation before
			if(!op) {
				int flag, minsize = 10000000;
				for(int i = 0; i < n; i++) {
					if(slot[i].size() < minsize) {
						flag = i, minsize = slot[i].size();
					}
				}
				slot[flag].push_front(cards.front() );
				cards.pop();
				printf("1 %d\n", flag + 1);
			}
		}
	}
	return 0;
}
