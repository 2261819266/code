#include <bits/stdc++.h>

const int MaxN=301,MaxM=2e6;
struct operation{
	int method,s1,s2;
};
std::queue<operation> answer;
std::deque<int> plate[MaxN];
std::deque<int> card;
int pos[2*MaxN];

void _op1(int s1){
	int c=card.front();
	if(plate[s1].front()==c){
		plate[s1].pop_front();
		pos[c]=0;
	}
	else{
		plate[s1].push_front(c);
		pos[c]=s1;
	}
	card.pop_front();
	operation ans;
	ans.method=1;ans.s1=s1;
	answer.push(ans);
}

void _op2(int s1,int s2){
	if(plate[s1].back()==plate[s2].back()){
		pos[plate[s1].back()]=0;
		plate[s1].pop_back();
		plate[s2].pop_back();
		operation ans;
		ans.method=2;ans.s1=s1;ans.s2=s2;
		answer.push(ans);
	}
}

int main() {
	std::freopen("meow.in","r",stdin);
	std::freopen("meow.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		int c;
		for(int i=0;i<m;i++){
			scanf("%d",&c);
			card.push_back(c);
		}
		int e1=1,e2=0;
		int count=0;
		int s1;
		int i;
		while(!card.empty()){
			c=card.front();
			if(pos[c]){
				s1=pos[c];
				if(plate[s1].back()==c&&e1){
					_op1(e1);
					_op2(e1,s1);
					if(plate[s1].empty()) e1=std::min(e1,s1);
				}
				else{
					s1=pos[c];
					_op1(s1);
					if(e2==0)e2=s1;
					else e2=std::min(e2,s1);
				}
				count--;
			}
			else{
				if(count<2*n-2){
					if(e2){
						_op1(e2);
						for(i=e2+1;i<=n;i++){
							if(plate[i].size()==1){
								e2=i;
								break;
							}
						}
						if(i==n+1){
							e2=0;
						}
					}
					else{
						_op1(e1);
						if(e2==0)e2=e1;
						else e2=std::min(e2,e1);
						for(i=e1+1;i<=n;i++){
							if(plate[i].size()==0){
								e1=i;
								break;
							}
						}
						if(i==n+1){
							e1=0;
						}
					}
				}
				else{
					int c1=card.front();
					card.pop_front();
					int c2=card.front();
					card.push_front(c1);
					if(pos[c2]&&plate[pos[c2]].back()==c2){
						_op1((e1+1)%n+1);
					}
					else{
						_op1(e1);
						e2=e1;
						e1=0;
					}
				}
				count++;
			}
		}
		printf("%d\n",answer.size());
		while(!answer.empty()){
			operation ans=answer.front();
			if(ans.method==1){
				printf("1 %d\n",ans.s1);
			}
			if(ans.method==2){
				printf("2 %d %d\n",ans.s1,ans.s2);
			}
			answer.pop();
		}
	}
	return 0;
}
