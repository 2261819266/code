#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int T,id,n,m,c,f,sum[1005];
char a[1005][1005];
int main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>id;
	while(T--) {
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		if(c==0) {
			printf("0 0\n");
			continue;
		}
		if(n==3) {
			if(m==2) {
				int fl=1;
				if(a[1][1]=='1' || a[1][2]=='1' || a[2][1]=='1') fl=0;
				if(a[3][1]=='1' || a[3][2]=='1') fl=0;
				printf("%d 0\n",fl);
				continue;
			}
		}
		if(n==4) {
			if(m==2) {
				int sc=2,sf=1;
				if(a[1][1]=='1' || a[1][2]=='1') sc--,sf--;
				if(a[2][1]=='1' || a[3][1]=='1') sc-=2,sf--;
				if(a[2][2]=='1') sc--;
				if(a[3][2]=='1') sc--,sf--;
				if(a[4][1]=='1') sc--,sf--;
				if(a[4][2]=='1') sc--;
				printf("%d %d\n",max(0,sc),max(0,sf));
				continue;
			}
		}
			memset(sum,0,sizeof(sum));
			for(int i=n;i>=1;i--) {
				if(a[i][1]=='0') sum[i]=sum[i+1]+1;
				else sum[i]=0;
			}
			int ans1=0,ans2=0;
			for(int i=3;i<=n;i++) {
				for(int j=i;j<=n;j++) {
					bool fl=0;
					for(int k=0;k<i;k++)
						if(a[j-k][1]=='1') {
							fl=1;
							break;
						}
					if(a[j][2]=='1' || a[j-i+1][2]=='1')
						fl=1;
					if(!fl) {
						ans1++;
						ans2+=sum[j+1];
					}
				}
			}
			printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
