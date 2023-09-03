#include<bits/stdc++.h>
using namespace std;
int mn[1004][1004],kn[1004][1004],kp[1004][1004],kf[1004][1004];
char a[1004][1004];
int T,id,n,m,ansc=0,ansf=0,c1,f1;
void serch();
void add();
int main() {
	//freopen("plant.in","r",stdin);
	//freopen("plant.out","w",stdout);
	cin>>T>>id;
	while(T>0) {
		T--;
		cin>>n>>m>>c1>>f1;
		if(c1==f1==0) {
			cout<<0<<" "<<0;
			return 0;
		}
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				cin>>a[i][j],mn[i][j]=a[i][j]-'0';
		serch();
		add();
	}
	cout<<ansc<<" "<<ansf;
	return 0;
}
void serch() {
	int n1=0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) {
			if(mn[i][j]==0) {
				n1++;
				if(n1>=2)
					if(kp[i][j-1]!=-1&&j-1!=0)
						kn[i+2][j]++;
			} else {
				kp[i][j]=-1,n1=0;
			}
		}
	return;
}
void add() {
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) {
			if(kn[i][j]>0)
				kn[i+1][j]+=kn[i][j];
			if(kp[i][j-1]==-1||j-1==0||(kn[i][j-1]==0&&kp[i-1][j-1]==1))
				kn[i][j]=0;
			else if(kp[i][j]!=-1) {
				if(kn[i-1][j]==-1&&kn[i][j-1]==-1)
					kp[i][j]=-1;
				if(kn[i][j-1]!=-1)
					kn[i][j]+=kn[i][j-1],kf[i][j]+=kf[i][j-1];
				ansc+=kn[i][j],ansc*=c1;
				if(kn[i][j]-kn[i][j-1]>=1) {
					int u=1,o=i,s=0;
					while(u==1) {
						if(kp[o][j-1]!=1)
							s++,o++;
					}
					kf[i][j]+=(kn[i][j]-kn[i][j-1])*s;
				}
				ansf+=kf[i][j];
				ansf*=f1;
			}
			ansc%=998244353;
			ansf%=998244353;
		}
	return;
}




