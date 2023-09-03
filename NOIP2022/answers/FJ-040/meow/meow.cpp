#include <bits/stdc++.h>

int t, i, n, m, k, cnt, c[10];
std::deque < int > q[10];
std::string op[10001];

bool chk2(int a);
bool chk1(int a, int b, int now);
void psh(int a, int now);

bool dfs(int now)
{
	chk2(1);
	chk2(2);
	chk2(3);	
	
	if (now > m)
		return q[1].empty() && q[2].empty() && q[3].empty();
	
	
	int tmp, tmp1, tmp2;
	
	cnt++;
	
	if (chk1(1, 2, now) | chk1(1, 3, now) | chk1(2, 3, now))
		return 1;
	
	psh(1, now);
	psh(2, now);
	psh(3, now);
	
	cnt--;
}

bool chk2(int a)
{
	if (q[a].size() > 1)
	{
		int tmp = q[a].back();
		q[a].pop_back();
		
		if (tmp == q[a].back())
			q[a].pop_back();
			
		else
			q[a].push_back(tmp);		
	}

}

bool chk1(int a, int b, int now)
{
	
	bool flg;
	
	if (!q[a].empty() && q[a].front() == q[b].front())
	{
		int tmp = q[a].front();
		q[a].pop_front();
		q[b].pop_front();
		op[cnt] = (std::string)"2 " + (char)(a + 48) + " " + (char)(b + 48);
		flg = dfs(now + 1);
		q[a].push_front(tmp);
		q[b].push_front(tmp);	
	}	
	
	return flg;
}

void psh(int a, int now)
{
	bool flg;
	
	op[cnt] = (std::string)"1 " + (char)(a + 48);
	q[a].push_back(c[now]);
	dfs(now + 1);
	q[a].pop_back();	
}

int main()
{
//	freopen("meow.in", "r", stdin);
//	freopen("meow.out", "w", stdout);

	scanf("%d", &t);
	
	while (t--)
	{
		scanf("%d%d%d", &n, &m, &k);
		
		for (i = 1; i <= m; i++)
			scanf("%d", c + i);
		
		dfs(1);
		
		for (i = 1; i <= cnt; i++)
			std::cout << op[i] << '\n';
	}
}

