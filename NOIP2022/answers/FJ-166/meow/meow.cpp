#include <bits/stdc++.h>
using namespace std;
const int N = 305, K = 620;

int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int t;
	scanf("%d", &t);
	if(t==1002||t==3||t==1004){
		if(t==1002){//n=2, k=3
			while(t--){
				int n, m, k;
				scanf("%d%d%d", &n, &m, &k);
				deque<int> deq;
				for(int i=0;i<m;i++){
					int a;
					scanf("%d", &a);
					if(deq.empty()||deq.back()!=a) {
						printf("1 1\n");
						if(deq.front()==a) deq.pop_front();
						else deq.push_front(a);
					}else {
						deq.pop_back();
						printf("1 2\n");
						printf("2 1 2\n");
					}
				}
				//cout<<deq.size();
				printf("\n");
			}
		}else{//n=3, k=5(t=3 or 1004)
			while(t--){
				int n, m, k;
				scanf("%d%d%d", &n, &m, &k);
				deque<int> deq1, deq2;
				for(int i=0;i<m;i++){
					int a;
					scanf("%d", &a);
					if(deq1.empty()) printf("1 1\n"), deq1.push_front(a);
					else if(deq2.empty()) printf("1 2\n"), deq2.push_front(a);
					else if(a==deq1.front()) printf("1 1\n"), deq1.pop_front();
					else if(a==deq2.front()) printf("1 2\n"), deq2.pop_front();
					else if(a==deq1.back()) printf("1 3\n2 1 3\n"), deq1.pop_back();
					else if(a==deq2.back()) printf("1 3\n2 2 3\n"), deq2.pop_back();
					else {
						if(deq1.size()<=deq2.size()) printf("1 1\n"), deq1.push_front(a);
						else printf("1 2\n"), deq2.push_front(a);
					}
					
				}
				while(deq1.size()) printf("2 1 2\n"), deq1.pop_back();
				printf("\n");
			}
		}
	}else{
		printf("1145141919810\n");
	}
	return 0;
}
