#include<bits/stdc++.h>
#define maxm 2000005
#define maxn 305
using namespace std;

typedef long long ll;

void FR(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
}

int a[maxn];
int ont[maxn*2];//ontop
deque<int> st[305];
int n,m,k;

int totans;
int ans[maxn];
int s1[maxn],s2[maxn];

void check_bot(){
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(st[i].front()==st[j].front()){
				st[i].pop_front(),st[j].pop_front();
				//printf("2 %d %d\n",i,j);
				ans[totans]=2;
				s1[totans]=i,s2[totans]=j;
				totans++;
			}
		}
	}
}

int main(){
	FR();
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;++i) scanf("%d",&a[i]);
		for(int i=1;i<=m;++i){
			int emp=-1;
			bool flag=0;
			for(int i=1;i<=n;++i){
				if(st[i].empty()) emp=i;
				else if(st[i].back()==a[i]){
					//printf("1 %d\n",i);
					ans[totans]=1;
					s1[totans]=i;
					totans++;
					st[i].pop_back();
					emp=-1;
					flag=1;
					break;
				}
			}
			if(emp>0){
				//printf("1 %d\n",emp);
				ans[totans]=1;
				s1[totans]=emp;
				totans++;
				check_bot();
			}
			if(!flag){
				//printf("1 1\n");
					ans[totans]=1;
					s1[totans]=1;
					totans++;
			}
		}
		printf("%d\n",totans);
		for(int i=0;i<totans;++i){
			printf("%d %d",ans[i],s1[i]);
			if(ans[i]==2) printf(" %d",s2[i]);
			printf("\n");
		}
	}
	return 0;
}

