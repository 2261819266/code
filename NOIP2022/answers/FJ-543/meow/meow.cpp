#include <bits/stdc++.h>
using namespace std;
int t;
int n, m, k;
vector<int> v[1005];
struct Minl
{
	int p;
	int a;
	int b;
} c[100050];
struct Sta
{
	int s[100050];
	int b;
	int h;
	
	Sta() {b = 0, h = 1;}
	
	inline bool empty() {return b == h;}
	
	inline void pop_back() {b++;}
	
	inline void pop_head() {h--;}
	
	inline void push_head(int x) {s[++b] = x, h++;}
};

inline int read()
{
	int x = 0, f = 1;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar())
		if (c == '-')
			f = -1;
	for (; c >= '0' && c <= '9'; c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

void solve()
{
	n = read(), m = read(), k = read();
	queue<int> q;
	int cnt = 0;
	for (int i = 1, x; i <= m; i++)
	{
		x = read();
		q.push(x);
	}
	if (n == 1)
	{
		cout << m << endl;
		for (int i = 1; i <= m; i++) cout << 1 << ' ' << 1 << endl;
		return;
	}
	c[++cnt] = (Minl){1, 1, 0};
	q.pop();
	while (!q.empty())
	{
		
	}
}

int main()
{
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	t = read();
	while (t--) solve();
	//This is a scary problem.(at least as me)
	/*
		            -----zyr-----
		        ----     zcx     ----
		    ----         cbh         ----
	>	stO--------------rsy--------------Orz   <
		    ----         xzy          ----
		        ----     lwx     ----
		            -----lzy-----
	*/
	return 0;
}
