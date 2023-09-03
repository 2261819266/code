#include <bits/stdc++.h>
using namespace std;

const int N = 4e6 + 10;

int w[N];
deque<int> stk[610];
int bs[N][3];
int st[600][4];
int main(){
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t --){
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 1; i <= m; ++ i) scanf("%d", &w[i]);
		int cnt = 0;//back ÊÇÕ»¶¥£¬ frontÊÇÕ»µ× 
		if(n == 2)
		{
			for(int i = 1; i <= m; ++ i){
				
				if(stk[1].empty() && stk[2].empty()){
					stk[1].push_back(w[i]);
					cnt ++;
					bs[cnt][0] = 1;
					bs[cnt][1] = 1;
				}else{
					if(!stk[1].empty() && stk[2].empty()){
						if(stk[1].back() == w[i]){
							stk[1].pop_back();
							cnt ++;
							bs[cnt][0] = 1;
							bs[cnt][1] = 1;
						}else{
							cnt ++;
							bs[cnt][0] = 1;
							bs[cnt][1] = 2;
							stk[2].push_back(w[i]);
						}
					}else if(stk[1].empty() && !stk[2].empty()){
						if(stk[2].back() == w[i]){
					
							stk[2].pop_back();
							cnt ++;
							bs[cnt][0] = 1;
							bs[cnt][1] = 2;
						}else{
						
							cnt ++;
							bs[cnt][0] = 1;
							bs[cnt][1] = 1;
							stk[1].push_back(w[i]);
						}
					}else{
						if(stk[1].front() == stk[2].front()){
						
					        cnt ++;
					        stk[1].pop_front();
					        stk[2].pop_front();
					        bs[cnt][0] = 2;
					        bs[cnt][1] = 1;
					        bs[cnt][2] = 2;
				        }else{
				        	 
				        	if(stk[1].back() == w[i]){
							    
				        		stk[1].pop_back();
							    cnt ++;
							    bs[cnt][0] = 1;
							    bs[cnt][1] = 1;
						    }else if(stk[2].back() == w[i]){
						    
						    	stk[2].pop_back();
							    cnt ++;
							    bs[cnt][0] = 1;
							    bs[cnt][1] = 2;
						    }else{
						    
						    	cnt ++;
						    	bs[cnt][0] = 1;
						    	bs[cnt][1] = 1;
						    	stk[1].push_back(w[i]);
								
							}
						}
					}
				}
			}
		}
		cout << cnt << endl;
		for(int i = 1; i <= cnt; ++ i){
			if(bs[cnt][0] == 1){
				printf("1 %d\n", bs[i][1]);
			}else{
				printf("2 %d %d\n", bs[i][1], bs[i][2]);
			}
		}
	}
	return 0;
}

