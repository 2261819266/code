#include<bits/stdc++.h>
using namespace std;

int read(){
	int w=0,ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')w=w*10+ch-48,ch=getchar();
	return w;
}

#define MAXN 1003
int n,m,c,f;
int ansc,ansf;
bitset<MAXN>mp[MAXN];
int sx[MAXN],s[MAXN],stop=0;
const int mod=998244353;

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int t=read(),id=read();
	n=read(),m=read(),c=read(),f=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			char ch=getchar();
			while(ch!='0'&&ch!='1')ch=getchar();
			mp[i][j]=ch-48;
		}
	for(int i=1;i+2<=n;i++){
		for(int j=1;j+1<=m;j++){
			if(mp[i][j])continue;
			// 枚举左上角
			int cnt=0;
			stop=0;
			for(int k=i;k<=n&&!mp[k][j];k++){
				int cntt=0;
				for(int l=j+1;l<=m&&!mp[k][l];l++)cntt++;
				if(cntt>0)cnt++,s[++stop]=cntt,sx[stop]=k;;
			}// 向下延伸
			if(cnt<2)continue;// 不够 
//			cout<<"debug "<<stop<<' '<<s[1]<<' '<<s[2]<<endl;
			for(int k=1;k<=stop;k++){
				for(int l=k+1;l<=stop;l++){
					if(sx[l]-sx[k]<=1)continue;
//					cout<<"debug "<<sx[l]<<' '<<cnt<<endl;
//					cout<<"cala "<<k<<' '<<l<<' '<<s[k]<<' '<<sx[l]<<' '<<s[l]<<endl;
					ansc+=s[k]*s[l];
				}
			}
		}
	}// C
	for(int i=1;i+3<=n;i++){
		for(int j=1;j+1<=m;j++){
			if(mp[i][j])continue;
			int cnt=0;
			stop=0;	
			for(int k=i;k<=n&&!mp[k][j];k++){
				int cntt=0;
				for(int l=j+1;l<=m&&!mp[k][l];l++)cntt++;
				if(cntt>0)cnt++,s[++stop]=cntt,sx[stop]=k;;
			}// 向下延伸
			if(cnt<2)continue;// 不够 
			for(int k=1;k<=stop;k++){
				for(int l=k+1;l<=stop;l++){
					if(sx[l]-sx[k]<=1)continue;
					if(i+cnt==sx[l])continue;
					ansf+=s[k]*s[l];
				}
			}
//			cout<<"\ndebug "<<i<<' '<<cnt<<endl;
		}
	}// F
	printf("%d %d",(ansc*c)%mod,(ansf*f)%mod);
	return 0;
}
/*
1 0
4 3 1 1
001
010
000
000
*/

// 1 12:53 fali
