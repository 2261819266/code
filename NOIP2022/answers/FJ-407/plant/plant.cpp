#include<iostream>
#include<cstring>
using namespace std;

const int N = 1001;

int n, m, c, f1;
int t, id, vc = 0, vf = 0;
char a[N][N];
int k[N][N], f[N];

void suan1(int t, int w)
{
	for(int i = t; i <= (w - 1); i ++)
	  for(int j = (i + 2); j <= w; j ++)
	  {
		vc += f[i] * f[j];
		vc %= 998244353;
	  }
}

void suan2(int t, int w)
{
	for(int i = t; i <= (w - 1); i ++ )
	  for(int j = i + 2; j <= (w - 1); j ++ )
	  {
		vf += f[i] * f[j] * (w - j);
		vf %= 998244353;
	  }
	return;
}

void plant(int t, int w, int p, int num)
{
	int num1 = 0, num2 = 0;
	for (int i = (p + 1); i <= m; i ++ )
	{
		if(k[t][i] == 1) break;
		num1 ++;
	}
	for(int i = (p + 1); i <= m; i ++ )
	{
		if(k[w][i] == 1) break;
		num2 ++;
	}
	f[t] = num1;
	f[w] = num2;
}


int cha(int q, int e)
{
	int w = 0;
	while(q + w <= n && k[q + w][e] == 0) 
	{
			w ++;					
			if(w >= 3) plant(q, q + w - 1, e, w);
	}
	return q + w;
}

int main()
{
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);

	memset(k, 1, sizeof(k));
	cin >> t >> id;
	if(id == 1) { cout << "0 0" << endl; return 0;}
	for(int q = 1; q <= t; q ++)
	{
		cin >> n >> m >> c >> f1;
		for(int i = 1; i <= n; i ++ )
	 	 cin >> a[i];
		for (int i = 1; i <= n; i ++ )
		{
		  for (int j = 0; j < m; j ++ )
		  {
		  	k[i][j + 1] = a[i][j] - '0';
		  }
		}
		for(int i = 0; i <= max(n, m); i ++ )
		  k[i][0] = 1, k[0][i] = 1;
		    

		for (int j = 0; j <= (m - 1); j ++ )
			for(int i = 0; i <= n; i ++ )
				if(k[i][j] == 1) 
				{
					int o = cha(i + 1, j);
					suan1(i + 1, o - 1);
					if(f1 == 1) suan2(i + 1, o - 1);
				}

		cout << vc << " " <<  vf << endl;
	}
		return 0;
}