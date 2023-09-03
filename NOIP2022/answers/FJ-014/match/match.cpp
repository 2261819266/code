#include<bits/stdc++.h>
using namespace std;
unsigned long long p=999999,ans=0;
long long x[3005][3005];
int t,n,a[250005],b[250005],sta[250005][30],stb[250005][30],q,l,r;
long long fff(int from,int to)
{
	int len=log(to-from+1)/log(2);
//	cout<<max(sta[from][len],sta[to-(1<<len)+1][len])<<" "<<max(stb[from][len],stb[to-(1<<len)+1][len])<<endl;
	return max(sta[from][len],sta[to-(1<<len)+1][len])*max(stb[from][len],stb[to-(1<<len)+1][len]);
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&t,&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]),sta[i][0]=a[i];
	for (int i=0;i<n;i++) scanf("%d",&b[i]),stb[i][0]=b[i];
	for (int i=1;i<=log(n)/log(2);i++)
		for (int j=0;j+(1<<i)-1<n;j++)
			{sta[j][i]=max(sta[j][i-1],sta[j+(1<<(i-1))][i-1]);
			 stb[j][i]=max(stb[j][i-1],stb[j+(1<<(i-1))][i-1]);
			}
	for (int i=0;i<n;i++)
		for (int j=i;j<n;j++)
			x[i][j]=fff(i,j);
	scanf("%d",&q);
	for (int i=0;i<q;i++)
		{scanf("%d%d",&l,&r);
		 l--,r--;
		 ans=0;
		 for (int j=l;j<=r;j++)
			for (int k=j;k<=r;k++)
				{//cout<<j<<" "<<k<<" "<<x[j][k]<<endl;
				 ans+=x[j][k];
//				 if (ans>=p) ans%=p;
				}
		 printf("%llu\n",ans);
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2
2 1
1 2
1
1 2
*/
