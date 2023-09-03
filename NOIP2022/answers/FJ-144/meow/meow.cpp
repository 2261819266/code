#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

inline int read() {
	int x = 0 , ff = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') ff = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar(); 
	}
	return x * ff;
}

const int N = 305;
struct node{
	int op , x , y;
};

vector<node> vec; deque<int> d[N]; int T , n , m , k , a[N];
int main () {
	freopen("meow.in" , "r" , stdin); freopen("meow.out" , "w" , stdout);
	T = read();
	while(T--) {
		n = read(); m = read(); k = read();
		for(int i = 1;i <= m;i++) a[i] = read();
		if(k == 2 * n - 2) {
			for(int i = 1;i <= m;i++) {
				int to = a[i] / 2 + (a[i] & 1);
				if(d[to].size()) {
					if(d[to].back() == a[i]) vec.push_back((node){1 , to , 0}) , d[to].pop_back();
					else {
						vec.push_back((node){1 , n , 0});
						if(d[n].size() && d[n].back() == a[i]) d[n].pop_back();
						else d[n].push_back(a[i]);
					} 
				}
				else vec.push_back((node){1 , to , 0}) , d[to].push_back(a[i]);
			}
			while(d[n].size()) {
				int x = d[n].front();
				int to = x / 2 + (x & 1);
				if(d[to].size() && d[to].front() == x) {d[to].pop_front(); d[n].pop_front(); vec.push_back((node){2 , to , n});}
				else break;
			}
			for(int i = 1;i <= n;i++) d[i].clear();
			printf("%d\n" , vec.size()); 
			for(int i = 0;i < vec.size();i++) {
				if(vec[i].op == 1) printf("1 %d\n" , vec[i].x);
				else printf("2 %d %d\n" , vec[i].x , vec[i].y);
			}
			vec.clear();
		}
	}
	return 0;
}
