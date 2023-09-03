#include <bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int s[300][10100];
int l[310];
int r[310];
int a[2000100];
int sum[310][620];
int size[310];
int id;
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&t);
	id = t % 10;
	while (t--){
		scanf("%d%d%d",&n,&m,&k);
		memset(s,0,sizeof(s));
		for (int i=0;i<=309;++i)
		    l[i]=1,r[i]=0;
		for (int i=1;i<=m;++i)
		{
			scanf("%d",&a[i]);
		}
		int ans = 0;
		if (k == 2 * n - 2 || id == 1)
		{
			for (int i=1;i<=m;++i)
			{
				int node = (a[i]-1)/2+1;
				if (s[node][r[node]] == a[i])    
				{
					ans++;r[node]--;
				}
				else if (s[node][l[node]]==a[i])
				{
					ans+=2;
					l[node]++;
				} else {
					s[node][++r[node]] = a[i];
					ans++;
				}
			}
			printf("%d\n",ans);
			memset(s,0,sizeof(s));
			for (int i=0;i<=309;++i)
		    	l[i]=1,r[i]=0;
			for (int i=1;i<=m;++i)
			{
				int node = (a[i]-1)/2+1;
				if (s[node][r[node]] == a[i])    
				{
					printf("1 %d\n",node);
					r[node]--;
				}
				else if (s[node][l[node]]==a[i])
				{
					printf("1 %d\n",n);
					printf("2 %d %d\n",node,n);
					l[node]++;
				} else {
					s[node][++r[node]] = a[i];
					printf("1 %d\n",node);
				}
			}
		}
		else {
			int ans = 0;
			memset(s,0,sizeof(s));
			for (int i=0;i<=309;++i)
		    	l[i]=1,r[i]=0;
			for (int i=1;i<=m;++i)
			{
				bool flag=false,f1=false,f2=false,f3=false;
				for (int j=1;j<=n;++j){
					if (r[j] == l[j]-1){
						flag = true;
						break;
					}
				}
				for (int j=1;j<=n;++j)
				{
					if (s[j][r[j]] == a[i])
					{
						f1=true;
						ans++;
						sum[j][a[i]]--;
						r[j]--;
						size[j]--;
						break;
					}
				}
				if (f1)    continue;
				if (flag)
				{
					for (int j=1;j<=n;++j)
					{
						if (a[i] == s[j][l[j]]){
							f2=true;
							l[j]++;
							sum[j][a[i]]--;
							ans+=2;
							size[j]--;
							break;
						}
					}
					if (f2)    continue;
				}
				int k1 = 1,j=1;
				while (sum[j][a[i]] >= k1)
				{
					++j;
					if (j == n+1){
						k1++;
						j=1;
					}
				}
				int minn=2e9,target=0;
				int z = j;
				for (z = j;z<=n;z++){
					if (minn > size[z]){
						minn = size[z];
						target = z;
					}
				}
				ans++;
				s[target][++r[target]] = a[i];
				size[target]++;
				sum[target][a[i]]++;
				for (int i=1;i<=k;++i)
				{
					for (int j=1;j<=n;++j)
					{
						for (int z=1;z<=n;++z)
						{
							if (s[j][l[j]] == s[z][l[z]] && s[z][l[z]] != 0 && z != j){
								l[j]++;
								l[z]++;
								ans++;
							}
						}
					}
				}
			}
			printf("%d\n",ans);
			memset(s,0,sizeof(s));
			for (int i=0;i<=309;++i)
		    	l[i]=1,r[i]=0;
			for (int i=1;i<=m;++i)
			{
				bool flag=false,f1=false,f2=false,f3=false;
				int y=0;
				for (int j=1;j<=n;++j){
					if (r[j] == l[j]-1){
						flag = true;
						y=j;
						break;
					}
				}
				for (int j=1;j<=n;++j)
				{
					if (s[j][r[j]] == a[i])
					{
						f1=true;
					    printf("1 %d\n",j);
						sum[j][a[i]]--;
						r[j]--;
						size[j]--;
						break;
					}
				}
				if (f1)    continue;
				if (flag)
				{
					for (int j=1;j<=n;++j)
					{
						if (a[i] == s[j][l[j]]){
							f2=true;
							printf("1 %d\n",y);
							printf("2 %d %d\n",j,y);
							l[j]++;
							size[j]--;
							sum[j][a[i]]--;
							ans+=2;
							break;
						}
					}
					if (f2)    continue;
				}
				int k1 = 1,j=1;
				while (sum[j][a[i]] >= k1)
				{
					++j;
					if (j == n+1){
						k1++;
						j=1;
					}
				}
				int minn=2e9,target=0;
				int z = j;
				for (int z = j;z<=n;z++){
					if (minn > size[z]){
						minn = size[z];
						target = z;
					}
				}
				ans++;
				s[target][++r[target]] = a[i];
				size[target]++;
				sum[target][a[i]]++;
				printf("1 %d\n",target);
				for (int i=1;i<=k;++i)
				{
					for (int j=1;j<=n;++j)
					{
						for (int z=1;z<=n;++z)
						{
							if (s[j][l[j]] == s[z][l[z]] && s[z][l[z]] != 0 && z != j){
								l[j]++;
								l[z]++;
								printf("2 %d %d\n",j,z);
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
