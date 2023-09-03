#include<bits/stdc++.h>
using namespace std;
const int N=1002;
struct FFF{
	bool op;
	int s1,s2;
}res[1000007];
deque<int> s1,s2;
int tmp[N][2];
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;
	scanf("%d",&T);
//	if(T%10==2){
		int n,m,k;
		while(T--){
			scanf("%d%d%d",&n,&m,&k);
			for(int i=1;i<=k;i++){
				tmp[i][0]=0;tmp[i][1]=0;
			}
			int x,num=0;
			for(int i=1;i<=m;i++){
				scanf("%d",&x);
				if(!s1.empty()&&s1.back()==x){
					s1.pop_back();
					res[++num].op=0;
					res[num].s1=1;
					continue;
				}
				if(!s2.empty()&&s2.back()==x){
					s2.pop_back();
					res[++num].op=0;
					res[num].s1=2;
					continue;
				}
				if(tmp[x][0]<tmp[x][1]){
					res[++num].op=0;
					res[num].s1=1;
					tmp[x][0]++;
					s1.push_back(x);
				}
				else{
					res[++num].op=0;
					res[num].s1=2;
					tmp[x][1]++;
					s2.push_back(x);
				}
				if(s1.front()==s2.front()){
					s1.pop_front();s2.pop_front();
					res[++num].op=1;
					res[num].s1=1;res[num].s2=2;
				}
			}
			printf("%d\n",num);
			for(int i=1;i<=num;i++){
				if(!res[i].op){
					printf("1 %d\n",res[i].s1);
				}
				else{
					printf("2 %d %d\n",res[i].s1,res[i].s2 );
				}
			}
			while(!s1.empty())s1.pop_back();
			while(!s2.empty())s2.pop_back();
		}
//	}
	return 0;
}
