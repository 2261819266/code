#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<ctime>
#include<sstream>
#include<string>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;

int n, m, k, a[2000009], stacks[309][609], sz[309], addr[609], provided[609], p_sz, ops[4000009], s1[4000009], s2[4000009];

int randint(int l, int r){
	return l+rand()%(r-l+1);
}

int main(){
	freopen("meow.in", "r", stdin); freopen("meow.out", "w", stdout);

	srand(time(0));

	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		for(int i=1; i<=m; i++){
			cin>>a[i];
		}
		for(int i=1; i<=n-1; i++){
			provided[p_sz++]=i;
		}
		int op=0;
		for(int i=1; i<=m; i++){
			int now = a[i], s = addr[now];
			if(s!=0){
				if(s>0){
					ops[op]=1; s1[op]=s;
					op++;
					sz[s]--;
					provided[p_sz++]=s;
				} else{
					ops[op]=1; s1[op]=n;
					op++;
					ops[op]=2; s1[op]=-s; s2[op]=n;
					op++;
					sz[-s]--;
					memmove(stacks[-s], stacks[-s]+1, sz[-s]*sizeof(int));
					addr[stacks[-s][0]]=s;
					provided[p_sz++]=-s;
				}
			} else{
				if(p_sz>0){
					int r = randint(0, p_sz-1), home = provided[r];
					stacks[home][sz[home]++]=now;
					if(sz[home]>=2){
						provided[r] = provided[p_sz-1];
						p_sz--;
					}
					addr[now]=sz[home]==1 ? -home : +home;
					ops[op]=1; s1[op]=home;
					op++;
				} else{
					int r1;
					do r1=randint(1, n-1); while(r1==addr[a[i+1]]);
					stacks[r1][sz[r1]++]=now;
					addr[now]=sz[r1]==1 ? -r1 : +r1;
					ops[op]=1; s1[op]=r1;
					op++;
				}
			}
		}
		cout<<op<<"\n";
		for(int i=0; i<op; i++){
			if(ops[i]==1){
				cout<<"1 "<<s1[i]<<"\n";
			} else{
				cout<<"2 "<<s1[i]<<" "<<s2[i]<<"\n";
			}
		}
	}
	
	return 0;
}
