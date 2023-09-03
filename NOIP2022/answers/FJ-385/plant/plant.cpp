// T1 _ 1s _ 512MB
#include <bits/stdc++.h>
#define FOR(x, l, r) for(int x=l; x<=r; ++x)
#define ROF(x, r, l) for(int x=r; x>=l; --x)
#define Add_Mod(x, y) x = (x + y) % P
using namespace std;
const int M = 1010;
const int P = 998244353;
int T, id, n, m, c, f;
int xx[M][M], yy[M][M], zz[M][M];
char s[M][M];
void getans_C()
{
	long long res = 0, num;
	FOR (i, 3, n) 
	{
		FOR (j, 1, m)
		if (s[i][j] == '0' && s[i-1][j] == '0')
		{
			Add_Mod(res, 1ll*yy[i-2][j]*(xx[i][j]-1)%P);
		}
	}
	cout << res << " ";
}
void getans_F()
{
	long long res = 0, num;
	FOR (i, 3, n) 
	{
		FOR (j, 1, m)
		if (s[i][j] == '0' && s[i-1][j] == '0')
		{
			Add_Mod(res, 1ll*yy[i-2][j]*(xx[i][j]-1)%P*(zz[i][j]-1)%P);
		}
	}
	cout << res << endl;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("plant.in" , "r" , stdin);
	freopen("plant.out", "w" , stdout);
	
	cin >> T >> id;
	while (T -- )
	{
		memset(xx, 0, sizeof(xx));
		memset(yy, 0, sizeof(yy));
		memset(zz, 0, sizeof(zz));
		
		cin >> n >> m >> c >> f;
		FOR (i, 1, n)
		{
			cin >> s[i] + 1;
		}
		FOR (i, 1, n) ROF (j, m, 1)
		{
			if (s[i][j] == '0')
				xx[i][j] = xx[i][j+1] + 1;
		}
		FOR (i, 1, n) FOR (j, 1, m)
		{
			if (s[i][j] == '0')
				yy[i][j] = yy[i-1][j] + xx[i][j] - 1;
		}
		ROF (i, n, 1) FOR(j, 1, m)
		{
			if (s[i][j] == '0')
				zz[i][j] = zz[i+1][j] + 1;
		}
		if (c == 0) cout << "0 ";
		else getans_C();
		if (f == 0) cout << "0" << endl;
		else getans_F();
	}
	return 0;
}
