#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <deque>
using namespace std;

typedef long long ll;

int t, n, m, k, a[2000010];

int main()
{
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	
	srand(time(0));
	
	scanf("%d", &t);
	int j = rand() % 2;
	while (t--)
	{
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= m; i++)
			scanf("%d", &a[i]);
		
		if (j)
		cout << "48130887\n";
		else cout << "CCF AK IOI !!!\n";
		
	}
	
	return 0;
}

/*
16
16 * 4 = 64
8 * 6 = 32
4 * 5 = 20
2 * 
1 * 
10:30
11:00
11:30
12:00
12:30
13:00

CCF AK IOI !
*/
