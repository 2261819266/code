#include <iostream>
#include <cstring>
#include <cstdio>
#include <list>
using namespace std;
/* freopen("meow.in","w",stdout) -> Hack SPJ :) */
int t,n,m,k,arr[2000010];
list<int> s[310];
int s1[4000010], s2[4000010];
bool ok = false;
void dfs(int dep,int cur){
	if(dep>m*2+1)	return;
	//printf("dep:%d, cur:%d, a:%d, b:%d\n",dep,cur,s[1].size(),s[2].size());
	if(cur==m+1){
		for(int i=1;i<=n;i++)
			if(s[i].size())	goto lab;
		printf("%d\n",dep-1);
		for(int i=1;i<dep;i++)
			if(s2[i])	printf("2 %d %d\n",s1[i],s2[i]);
			else printf("1 %d\n",s1[i]);
		ok = true;
		return;
		lab:;
	}
	if(cur<=m)
	for(int i=1;i<=n;i++){
		s1[dep] = i,s2[dep] = 0;
		if(s[i].size()&&s[i].back()==arr[cur]){
			s[i].pop_back();
			dfs(dep+1,cur+1);
			if(ok)	return;
			s[i].emplace_back(arr[cur]);
		}else{
			s[i].push_back(arr[cur]);
			dfs(dep+1,cur+1);
			if(ok)	return;
			s[i].pop_back();
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(s[i].size()&&s[j].size()&&s[i].front()==s[j].front()){
				s1[dep] = i,s2[dep] = j;
				int a = s[i].front(),b = s[j].front();
				s[i].pop_front(),s[j].pop_front();
				dfs(dep+1,cur);
				if(ok)	return;
				s[i].push_front(a),s[j].push_front(b);
			}
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&n,&m,&k);
		k = min(k,3);
		for(int i=1;i<=n;i++)	s[i].clear();
		ok = false;
		for(int i=1;i<=m;i++)	scanf("%d",arr+i);
		dfs(1,1);
		if(!ok)	printf("0\n");
		//if(!ok)	return 1;
	}
	return 0;
}
/* I love zxl forever */
/*
2
3 10 5
1 2 3 4 5 2 3 4 5 1
*/
