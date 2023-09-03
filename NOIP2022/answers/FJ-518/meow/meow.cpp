#include<cstdio>
#include<deque>
#include<cstring>
#include<stack>
using namespace std;
int max(int a,int b){
	if(a>b)return a;
	return b;
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;++i){
		int h[305][3];
		memset(h,0,sizeof(h));
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		deque<int> q[n+1];
		stack<int> s;
		for(int i=1;i<=m;++i){
			int f;
			scanf("%d",&f);
			s.push(f);
			while(!s.empty()){
				int f=s.top();
				s.pop();
				int em=1;
				for(int k=1;k<=n;++k){
					if(q[k].empty())em=k;
					else if(q[k].back()==f){
						printf("1 %d\n",f);
						q[k].pop_back();
						em=-1;
						break;
					}
				}
				if(em!=-1){
					q[em].push_back(f);
					printf("%d %d\n",1,f);
					if(q[em].size()==1){
						h[f][h[f][0]+1]=em;
						h[f][0]++;
						if(h[f][0]==2){
							printf("2");
							if(h[f][1]>em)printf(" %d %d\n",em,h[f][1]);
							else printf(" %d %d\n",h[f][1],em);
							h[f][0]=0;
							q[h[f][1]].pop_front();
							q[em].pop_front();
						}
					}
				}
			}
		}
	}
	return 0;
}
