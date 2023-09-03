#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll Mod=998244353;
void read(int &x) {
	x=0;
	int w=1;
	char ch;
	while(ch<'0'||ch>'9') {
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+(ch-48);
		ch=getchar();
	}
	x*=w;
}
int T;
int id;
int n,m;
ll c,f;
string s[1000001];
int lef[1100][1100],dow[1100][1100];
bool b[1100][1100];
ll ansc,ansf;
int main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	read(T);
	read(id);
	for(int t=1; t<=T; ++t) {
		memset(b,0,sizeof(b));
		ansc=ansf=0;
		read(n);
		read(m);
		cin>>c>>f;
		for(int i=1; i<=n; ++i) {
			cin>>s[i];
			s[i]="!"+s[i];
		}
		for(int i=1; i<=n; ++i) {
			int num=0;
			for(int j=m; j>=1; --j) {
				if(s[i][j]=='0')num++;
				else num=0;
				lef[i][j]=num;
			}
		}
		for(int i=1; i<=m; ++i) {
			int num=0;
			for(int j=n; j>=1; --j) {
				if(s[j][i]=='0')num++;
				else num=0;
				dow[j][i]=num;
			}
		}
//		for(int i=1; i<=n; ++i,cout<<"\n")
//			for(int j=1; j<=m; ++j) {
//				cout<<dow[i][j]<<" ";
//			}
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=m; ++j)
				if(!b[i][j]&&s[i][j]=='0') {
					b[i][j]=1;
					if(lef[i][j]<2)continue;
					if(dow[i][j]<3)continue;

					ll sum=0;
					for(int k=i; k<=i+dow[i][j]-1; ++k) {
						b[k][i]=1;
						ansc=(ansc+1ll*sum*(lef[k][j]-1))%Mod;
						ansf=(ansf+1ll*sum*(lef[k][j]-1)*(i+dow[i][j]-1-k)%Mod)%Mod;
						if(k-1>=i)sum=(sum+lef[k-1][j]-1)%Mod;
					}
				}
		cout<<(ansc*c)%Mod<<" "<<(ansf*f)%Mod;
	}
}
/*

*/
