#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,a;
int cz[4000010][3],o[2010],r;
deque<int> q[310];
int main() {
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>t;
	while(t--) {
		scanf("%d%d%d",&n,&m,&k);
		int ans=0;
		r=0;
		memset(cz,0,sizeof cz);
		for(int i=1; i<=300; i++) q[i].clear();
		for(int i=1; i<=m; i++) {
			scanf("%d",&a);
			bool f=0;
			for(int i=1; i<=n-1; i++) {
				if(q[i].empty()) continue;
				if(q[i].back()==a) {
					q[i].pop_back();
					f=1;
					cz[++ans][0]=1,cz[ans][1]=i;
					break;
				}
			}
			if(f) continue;
			for(int i=1; i<=n-1; i++) {
				if(q[i].empty()) continue;
				if(q[i].front()==a) {
					q[i].pop_front();
					f=1;
					cz[++ans][0]=1,cz[ans][1]=n;
					cz[++ans][0]=2,cz[ans][1]=i,cz[ans][2]=n;
					break;
				}
			}
			if(f) {
				while(1) {
					bool fl=0;
					for(int i=1; i<=k; i++) o[i]=0;
					for(int i=1; i<=n-1; i++) {
						if(q[i].empty()) continue;
						if(o[q[i].front()]) {
							fl=1;
							cz[++ans][0]=2;
							cz[ans][1]=o[q[i].front()];
							cz[ans][2]=i;
							q[o[q[i].front()]].pop_front();
							q[i].pop_front();
						} else o[q[i].front()]=i;
					}
					if(!fl) break;
				}
				continue;
			}
			r++;
			if(r==n) r=1;
			q[r].push_back(a);
			cz[++ans][0]=1;
			cz[ans][1]=r;
		}
		while(1) {
			bool fl=0;
			for(int i=1; i<=k; i++) o[i]=0;
			for(int i=1; i<=n-1; i++) {
				if(q[i].empty()) continue;
				if(o[q[i].front()]) {
					fl=1;
					cz[++ans][0]=2;
					cz[ans][1]=o[q[i].front()];
					cz[ans][2]=i;
					q[o[q[i].front()]].pop_front();
					q[i].pop_front();
				} else o[q[i].front()]=i;
			}
			if(!fl) break;
		}
		printf("%d\n",ans);
		for(int i=1; i<=ans; i++) {
			if(cz[i][0]==1) {
				printf("1 %d\n",cz[i][1]);
			} else {
				printf("2 %d %d\n",cz[i][1],cz[i][2]);
			}
		}
	}
}
/*
1
3 10 5
1 2 3 4 5 2 3 4 5 1
*/
