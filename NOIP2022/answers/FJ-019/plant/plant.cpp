//n^4 brute force
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e3+10;

const ll p=998244353;

int a[N][N],h[N][N];

char s[N];

void solve1(){
	int n,m,upp,downn;
	ll ansc=0,ansf=0,c,f;
	scanf("%d%d%lld%lld",&n,&m,&c,&f);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			a[i][j]=s[j]-'0';		
	}
	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--)
			if(!a[i][j])
				h[i][j]=h[i][j+1]+1;
	for(int i=1;i<=m;i++){
		a[0][i]=a[n+1][i]=1;
		for(int j=1;j<=n+1;j++){
			if(!a[j][i]&&a[j-1][i])
				upp=j;
			if(a[j][i]&&!a[j-1][i]){
				downn=j-1;
//				printf("%d %d\n",upp,downn);
				for(int i1=upp;i1<=downn-2;i1++){
					if(h[i1][i]==0)continue;
					for(int i2=i1+2;i2<=downn;i2++){
						if(h[i2][1]==0)continue;
//						printf("%d:%d %d %lld %lld\n",i,i1,i2,1ll*(h[i1][i]-1)*(h[i2][i]-1),1ll*(downn-i2)*(h[i1][i]-1)%p*(h[i2][i]-1));
						ansc=(ansc+1ll*(h[i1][i]-1)*(h[i2][i]-1)%p)%p;
						ansf=(ansf+1ll*(downn-i2)*(h[i1][i]-1)%p*(h[i2][i]-1)%p)%p;
					}
				}
			}
		}
	}
	printf("%lld %lld\n",ansc*c,ansf*f);	
}

vector<int>up1,down1;

void solve2(){
	int n,m;
	ll ansc=0,ansf=0,c,f,tmp;
	scanf("%d%d%lld%lld",&n,&m,&c,&f);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			a[i][j]=s[j]-'0';		
	}
	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--)
			if(!a[i][j])
				h[i][j]=h[i][j+1]+1;
	for(int i=1;i<=m;i++){
		a[0][i]=a[n+1][i]=1;
		for(int j=1;j<=n+1;j++){
			if(!a[j][i]&&a[j-1][i])
				up1.push_back(j);
			if(a[j][i]&&!a[j-1][i]){
				down1.push_back(j-1);
//				printf("%d %d\n",upp,downn);
			}
		}
		for(int ii=0;ii<up1.size();ii++){
			tmp=0;
			int up0=up1[ii],down0=down1[ii];
			for(int j=up0+2;j<=down0;j++){
				if(h[j-2][i])tmp=(tmp+h[j-2][i]-1)%p;
				if(h[j][i]){
					ansc=(ansc+1ll*tmp*(h[j][i]-1)%p)%p;
					ansf=(ansf+1ll*tmp*(h[j][i]-1)%p*(down0-j)%p)%p;
				}
//				printf("%d %d %lld\n",i,j,tmp);
			}
		}
		up1.clear();
		down1.clear();
	}
	printf("%lld %lld\n",ansc*c,ansf*f);
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++)	
			a[i][j]=h[i][j]=0;
}

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int t,id;
	scanf("%d%d",&t,&id);
	while(t--)solve2();
	return 0;
}
