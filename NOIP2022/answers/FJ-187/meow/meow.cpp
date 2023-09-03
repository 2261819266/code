//这题出得很好，下次不要再出这种题了 
#include<bits/stdc++.h>
using namespace std;
const int M = 2e6+10;
const int N = 610;
int bat[N];
int top[N];
int ne[M];
int ba[N];
int a[M];
bool del[N];
struct node1{
	int o,s1,s2;
};
queue<node1>q;
deque<int>de[310];
void init(){
	memset(ne,0,sizeof(ne));
	memset(ba,0,sizeof(ba));
	memset(a,0,sizeof(a));
	memset(del,0,sizeof(del));
}
void upt(int i){
	if(de[i].empty())return;
	q.push((node1){2,bat[de[i].front()],i});
	int x=de[i].front();
	de[bat[x]].pop_front();
	bat[de[bat[x]].front()]=bat[x];
	de[i].pop_front();
	if(bat[de[i].front()])upt(i);
	else bat[de[i].front()]=i;
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		int n,m,k,op;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i]);
			if(ne[a[i]])ba[i]=a[ne[a[i]]];
			ne[a[i]]=i-1;
		}
		for(int i=1;i<=m;i++){
			printf("%d\n",ba[i]);
		}
		for(int i=1;i<=m;i++){
			if(top[a[i]]){
				q.push((node1){1,top[a[i]],0});
				de[top[a[i]]].pop_back();
				top[de[top[a[i]]].back()]=top[a[i]];
				top[a[i]]=0;
				continue;
			}
			if(ba[i]){
				if(top[ba[i]]){
					q.push((node1){1,top[ba[i]],0});
					de[top[ba[i]]].push_back(a[i]);
					top[a[i]]=top[ba[i]];
					top[ba[i]]=0;
					continue;
				}else{
					for(int i=1;i<=n+1;i++){
						if(i==n+1){
							top[de[1].back()]=0;
							top[a[i]]=1;
							de[1].push_back(a[i]);
							q.push((node1){1,a[i],0});
						}else if(de[i].empty()){
							top[a[i]]=i;
							de[i].push_back(a[i]);
							q.push((node1){i,a[i],0});
						}	
					}
				}
			}else{
				for(int i=1;i<=n+1;i++){
					if(i==n+1){
						top[de[1].back()]=0;
						top[a[i]]=1;
						de[1].push_back(a[i]);
						q.push((node1){1,a[i],0});
					}else if(de[i].empty()){
						top[a[i]]=i;
						de[i].push_back(a[i]);
						q.push((node1){i,a[i],0});
					}	
				}
			}
		}
		int n1=n;
		while(n1>0){
			for(int i=1;i<=n;i++){
				if(de[i].empty()&&(!del[i])){
					n1--;
					del[i]=1;
				}
				if(bat[de[i].front()]){
					upt(i);
				}
			}
		}
		printf("%d\n",q.size());
		while(!q.empty()){
			node1 temp=q.front();
			q.pop();
			if(temp.o==1){
				printf("1 %d",temp.s1);
			}else if(temp.o==2){
				printf("2 %d %d",temp.s1,temp.s2);
			}
		}
	}
	return 0;
}//做不出来，跑了，明年见 
