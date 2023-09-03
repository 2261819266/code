#include <bits/stdc++.h>
using namespace std;
int b[1500005][4],top[305],tail[305];
int T,n,k,m,a[1000005];
vector<int> s1[305];
bool check(){
	for(int i=1;i<=n;i++){
		if(top[i]>=tail[i]) return false;
	}
	return true;
}
void dfs(int dep,int now){
	if(now==m+1&&check()){
		cout <<dep<<endl;
		for(int i=1;i<=dep-1;i++){
			for(int j=0;j<b[i][3];j++){
				cout <<b[i][j]<<" ";
			}
			cout <<endl;
		}
		return;
	}
	if(now!=m+1){
		for(int i=1;i<=n;i++){
			b[dep][0]=1;
			b[dep][1]=i;
			b[dep][3]=2;
			if(a[now]==s1[i][top[i]]){
				top[i]--;
				dfs(dep+1,now+1);
				top[i]++;
				continue;
			}
			if(top[i]+1>s1[i].size()){
				s1[i].push_back(a[now]);
				top[i]++;
			}else s1[i][++top[i]]=a[now];
			dfs(dep+1,now+1);
			top[i]--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(s1[i][tail[i]]==s1[j][tail[j]]){
				b[dep][0]=2;
				b[dep][1]=i;
				b[dep][2]=j;
				b[dep][3]=3;
				tail[i]++;tail[j]++;
				dfs(dep+1,now+1);
				tail[i]--;tail[j]--;
			}
		}
	}
}
int main(){
	cin >>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin >>n>>m>>k;
		for(int i=1;i<=n;i++){
			cin >>a[i];
		}
		dfs(1,1);
	}
}
