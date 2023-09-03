#include<bits/stdc++.h>
using namespace std;
struct st{
	int op,s1,s2;
}f1;
queue<st> q;
int t,n,m,k,l[305],s[305][5],i,bo[605],a[2000005],cnt,h;
inline void j1(int ss){
	q.push(st{1,ss,0});
	if(s[ss][l[ss]]==a[i]) l[ss]--;
	else s[ss][++l[ss]]=a[i];
}
inline void j2(int s1,int s2){
	if(s1>s2) swap(s1,s2);
	q.push(st{2,s1,s2});
	for(int i=2;i<=l[s1];i++) s[s1][i-1]=s[s1][i];
	l[s1]--;
}
inline void print(){
	cout<<q.size()<<'\n';
	while(!q.empty()){
		f1=q.front();q.pop();cout<<f1.op<<' '<<f1.s1;
		if(f1.op==2) cout<<' '<<f1.s2<<'\n';
		else cout<<'\n';
	}
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		memset(l,0,sizeof(l));
		memset(s,0,sizeof(s));
		memset(bo,0,sizeof(bo));
		cin>>n>>m>>k;
		for(i=1;i<=m;i++) cin>>a[i];
		for(i=1;i<=m;i++){
			if(!bo[a[i]]){
				cnt++;
				if(cnt>=n){
					cnt=1;
					bool bo1=0;
					for(int j=1;j<=n;j++)
						if(l[j]<=1){bo1=1;bo[a[i]]=j;j1(cnt);break;}
					if(bo1) continue;
					if(bo[a[i+1]]==1) cnt=2;
					bo[a[i]]=cnt;j1(cnt);
					++i;
					if(l[bo[a[i]]]==a[i]) j1(bo[a[i]]);
					else j1(n),j2(n,bo[a[i]]);
				}
				j1(cnt);bo[a[i]]=cnt;
			}else if(s[bo[a[i]]][l[bo[a[i]]]]==a[i]) j1(bo[a[i]]);
			else j1(n),j2(n,bo[a[i]]);
		}
		print();
	}
	return 0;
}
