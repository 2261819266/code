#include<bits/stdc++.h>
//#pragma GCC optimize(s)
//#pragma GCC optimize("Ofast")
using namespace std;
const int Mod=998244353;
int T,id,n,m,c,f,cnt=0;
int a[1010][1010]={};
struct Node{
	int u,v,u1,v1,v2;
}node[1000010]={};
bool check(int x,int l,int r){
	for(int i=l;i<=r;i++)
		if(a[x][i])
			return 0;
	return 1;
}
bool check_t(int x,int l,int r){
	for(int i=l;i<=r;i++)
		if(a[i][x])
			return 0;
	return 1;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	std::ios::sync_with_stdio(false);
	
	cin>>T>>id;
	for(int i=1;i<=T;i++){
		int C=0,F=0;
		cin>>n>>m>>c>>f;
		for(int j=1;j<=n;j++){
			string s;
			cin>>s;
			for(int len=0;len<s.size();len++){
				int temp=s[len]-'0';
				a[j][len+1]=temp;
			}	
		}	
		for(int x2=1;x2<=n;x2++){
			for(int x1=1;x1<x2-1;x1++){
				for(int y2=1;y2<=m;y2++){
					for(int y1=1;y1<=y2;y1++){
						for(int y0=1;y0<y1;y0++){
							if(check(x1,y0,y1)&&check(x2,y0,y2)&&check_t(y0,x1,x2)){
								C++;
								node[++cnt].u=x1;
								node[cnt].v=x2;
								node[cnt].u1=y0;
								node[cnt].v1=y1;
								node[cnt].v2=y2;
							}
						}
					}
				}
			}
		}
		for(int j=1;j<=cnt;j++){
			for(int x3=1;x3<=n;x3++){
				if(node[j].v>=x3) continue;
				if(check_t(node[j].u1,node[j].u,x3)){
					F++;
				}
			}
		}
		cout<<(c*C)%Mod<<" "<<(f*F)%Mod<<endl;
		cnt=0;
	}
	
	return 0;
}