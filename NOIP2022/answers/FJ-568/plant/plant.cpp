#include<bits/stdc++.h>

using namespace std;
const int N=1010;
char t[N][N];
bool hs(int x,int xx,int y,int yy,int yyy)
{
	for(int i=y;i<=yy;i++){
		if(t[x][i]=='1')return false;
	}
	for(int i=y;i<=yyy;i++){
		if(t[xx][i]=='1')return false;
	}
	for(int i=x;i<=xx;i++){
		if(t[i][y]=='1')return false;
	}
	return true;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,aaa;
	cin>>T>>aaa;
	int n,m,c,f;
	cin>>n>>m>>c>>f;
	if(c==0&&f==0){
		cout<<"0 0";
		return 0;
	}
	long long ansc=0,ansf=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>t[i][j];
		}
	}
	for(int x=1;x<=n;x++){
		for(int xx=x+2;xx<=n;xx++){
			for(int y=1;y<=m;y++){
				if(t[x][y]=='1'||t[xx][y]=='1')continue;
				for(int yy=y+1;yy<=m;yy++){
					for(int yyy=y+1;yyy<=m;yyy++){
						if(hs(x,xx,y,yy,yyy)){
							ansc++;
							for(int i=xx+1;i<=n;i++)if(t[i][y]=='0')ansf++;
						}
					}
				}
			}
		}
	}
	cout<<(c*ansc)%998244353<<" "<<(f*ansf)%998244353;
}

