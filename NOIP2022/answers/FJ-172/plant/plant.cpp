#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
inline int read(){
	int s=0,t=1; char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')t=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=(s*10)+ch-'0';
		ch=getchar();
	}
	return s*t;
}
const int maxn=1010;
const int mod=998244353;
inline int read01(){
	char ch=getchar();
	while(ch<'0'||ch>'1') ch=getchar();
	if(ch=='0') return 0;
	else return 1;
}
int T,id;
int n,m,c,f,vc=0,vf=0;
bool mp[maxn][maxn];
inline int getn(int x,int y){
	int sum=0;
	for(int j=y+1;j<=m;j++){
		if(mp[x][j]) return sum;
		else sum++;
	}
	return sum;
}
inline int getm(int x,int y){
	int sum=0;
	for(int i=x+1;i<=n;i++){
		if(mp[i][y]) return sum;
		else sum++;
	}
	return sum;
}

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read(); id=read();
	while(T--){
		n=read(); m=read(); c=read(); f=read();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				mp[i][j]=read01();
			}
		}
		if(c==0&&f==0){
			printf("0 0\n");
			//continue;
		}else if(m==2){
			if(n==3){
				if(!mp[1][1]&&!mp[1][2]&&!mp[2][1]&&!mp[3][1]&&!mp[3][2]) printf("1 0\n");
				else printf("0 0\n");
			}
			else if(n==4){
				if(!mp[1][1]&&!mp[1][2]&&!mp[2][1]&&!mp[3][1]&&!mp[3][2]){
					if(!mp[4][1])printf("1 1\n");
					else printf("1 0\n");
				} 
				else printf("0 0\n");
			}
			//continue;
		}else{
			vc=0; vf=0;
			for(int xj=1;xj+1<=m;xj++){
				for(int xi=1;xi+2<=n;xi++){
				    if(mp[xi][xj]||mp[xi+1][xj]) continue;
				    
				    for(int xii=xi+2;xii<=n&&!mp[xii][xj];xii++){
				    	int s1=getn(xi,xj),s2=getn(xii,xj);
				    	if(!s1||!s2) continue;
				    	vc+=s1*s2;
				    	vc%=mod;
				    	if(f){
				    		int s3=getm(xii,xj);
				    		vf+=s1*s2*s3;
				    		vf%=mod;
						}
					}
				    
			    }
			}
			printf("%d %d\n",vc,vf);
		}
	}
	return 0;
}
