#include<bits/stdc++.h>
using namespace std;
#define ll long long
int T,n,m,k,a[2000010],ans[4000010],s1[4000010],s2[4000010],tans=0;
deque<int> dq[4];int flg;//T==3
void dfs(int x){
	if(flg==1) return;
	if(x==m+1){
		if(dq[1].empty()&&dq[2].empty()&&dq[3].empty()){
			printf("%d\n",tans);
			for(int i=1;i<=tans;i++){
				printf("%d ",ans[i]);
				if(ans[i]==1) printf("%d\n",s1[i]);
				else printf("%d %d\n",s1[i],s2[i]);
			}
			flg=1;
			return;
		}
		return;
	}
	if(flg==1) return;
	if(!dq[1].empty()&&!dq[2].empty()&&dq[1].front()==dq[2].front()){
		int fr1=dq[1].front(),fr2=dq[2].front();
		dq[1].pop_front(),dq[2].pop_front();
		ans[++tans]=2,s1[tans]=1,s2[tans]=2;
		dfs(x);
		tans--,dq[1].push_front(fr1),dq[2].push_front(fr2);
	}
	if(flg==1) return;
	if(!dq[1].empty()&&!dq[3].empty()&&dq[1].front()==dq[3].front()){
		int fr1=dq[1].front(),fr2=dq[3].front();
		dq[1].pop_front(),dq[3].pop_front();
		ans[++tans]=2,s1[tans]=1,s2[tans]=3;
		dfs(x);
		tans--,dq[1].push_front(fr1),dq[3].push_front(fr2);
	}
	if(flg==1) return;
	if(!dq[2].empty()&&!dq[3].empty()&&dq[2].front()==dq[3].front()){
		int fr1=dq[2].front(),fr2=dq[3].front();
		dq[2].pop_front(),dq[3].pop_front();
		ans[++tans]=2,s1[tans]=2,s2[tans]=3;
		dfs(x);
		tans--,dq[2].push_front(fr1),dq[3].push_front(fr2);
	}
	for(int i=1;i<=3;i++){
		if(flg==1) return;
		if(!dq[i].empty()&&dq[i].back()==a[x]){
			int bk=dq[i].back();
			dq[i].pop_back();
			ans[++tans]=1,s1[tans]=i;
			dfs(x+1);
			tans--,dq[i].push_back(bk);
		}
		else{
			dq[i].push_back(a[x]);
			ans[++tans]=1,s1[tans]=i;
			dfs(x+1);
			tans--,dq[i].pop_back();
		}
		if(flg==1) return;
	}
	if(flg==1) return;
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	for(int www=1;www<=T;www++){
		tans=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i]);
		}
		if(T==1001){
			int pl[610];
			for(int i=1;i<=k;i++) pl[i]=0;
			for(int i=1;i<=m;i++){
				int x;
				if(a[i]&1) x=a[i]+1;
				else x=a[i]-1;
				if(pl[a[i]]==0){
					if(pl[x]==1) pl[a[i]]=2;
					else pl[a[i]]=1;
//					printf("1 %d\n",(a[i]+1)/2);
					ans[++tans]=1,s1[tans]=(a[i]+1)/2;
				}
				else if(pl[a[i]]==1){
					pl[a[i]]=0;
					if(pl[x]==2) pl[x]=1;
//					printf("1 %d\n",n);
					ans[++tans]=1,s1[tans]=n;
//					printf("2 %d %d\n",(a[i]+1)/2,n);
					ans[++tans]=2,s1[tans]=(a[i]+1)/2,s2[tans]=n;
				}
				else if(pl[a[i]]==2){
					pl[a[i]]=0;
//					printf("1 %d\n",(a[i]+1)/2);
					ans[++tans]=1,s1[tans]=(a[i]+1)/2;
				}
			}
			printf("%d\n",tans);
			for(int i=1;i<=tans;i++){
				printf("%d ",ans[i]);
				if(ans[i]==1) printf("%d\n",s1[i]);
				else printf("%d %d\n",s1[i],s2[i]);
			}
		}
		else{
			flg=0;
			while(!dq[1].empty()) dq[1].pop_back();
			while(!dq[2].empty()) dq[2].pop_back();
			while(!dq[3].empty()) dq[3].pop_back();
			dfs(1);
		}
	}
	return 0;
}
/*
3
3 10 5
1 2 3 4 5 2 3 4 5 1
3 10 5
1 2 3 4 5 2 3 4 5 1
3 10 5
1 2 3 4 5 2 3 4 5 1

1001
2 4 2
1 2 1 2

*/
