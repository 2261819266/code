#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<stack>
#include<iostream>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,num=0;
	char rd=getchar();
	while(!isdigit(rd)){
		if(rd=='-') f=-1;
		rd=getchar();
	}
	while(isdigit(rd)){
		num=num*10+rd-48;
		rd=getchar();
	}
	return f*num;
}
int a[2000090],nex[2000090],num[1090],las[2000090];
bool mo[2000090];
int s[309][2],pos[2000090];
struct S{
	bool op;
	int x,y;
	void pr(){
		if(op) printf("2 %d %d\n",x,y);
	}
}out[2000090];
void solve(){
	int n=read(),m=read();read();
	for(int i=1;i<=m;i++) a[i]=read(),num[i]=0;
	for(int i=m;i>0;i--){
		nex[i]=num[a[i]];
		mo[i]=mo[nex[i]]^1;
		las[nex[i]]=i;
		num[a[i]]=i;
		out[i].op=0;
	}
	for(int i=1;i<=m;i++){
		if(!mo[i]){
			for(int j=1;j<=n;j++){
				if(s[j][1]) continue;
				if(s[j][0]==0) s[j][0]=i;
				else s[j][1]=i;
				pos[i]=j;
				break;
			}
		}
		else{
			int p=pos[las[i]];
			if(a[s[p][1]]==a[i]) pos[i]=p,s[p][1]=0;
			else{
				if(s[p][1]==0) pos[i]=p,s[p][0]=0;
				else{
					int _0=0,_1=0;
					for(int j=1;j<=n;j++){
						if(s[j][0]==0){
							_0=j;
							break;
						}
						else if(s[j][1]==0){
							_1=((s[_1][0]<s[j][0])?j:_1);
						}
					} 
					if(_0){
						pos[i]=_0,out[i].op=1,out[i].x=_0,out[i].y=p,s[p][0]=s[p][1];
						s[p][1]=0;
					}
					else{
						pos[s[_1][0]]=p;
						s[p][0]=s[p][1];
						s[p][1]=s[_1][0];
						s[_1][0]=0;
						pos[i]=_1;
						out[i].op=1,out[i].x=_1,out[i].y=p;
					}
				}
			}
		}
	}
	int tot=m;
	for(int i=1;i<=m;i++) if(out[i].op) tot++;
	printf("%d\n",tot);
	for(int i=1;i<=m;i++){
		printf("1 %d\n",pos[i]);
		out[i].pr();
	}
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T=read();
	while(T--) solve();
	return 0;
}
