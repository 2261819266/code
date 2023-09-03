#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-'){
		ch = getchar();
		f = -1;
	}
	while(isdigit(ch)){
		X = (X<<1)+(X<<3)+ch-'0';
		ch = getchar();
	}
	return f*X;
}

const int M = 2e6+10;
const int N = 310;
int n,m,k;
int c[M],s[N][5],v[2*N];
int op,ans[M*2][3];


int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T = read();
	if(T%1000 == 1){
		while(T--){
			memset(c,0,sizeof(c));
			op = 0;
			n = read();
			m = read();
			k = read();
			for(int i=1;i<=m;i++)
				c[i] = read();
			for(int i=1;i<=m;i++){
				int id = (c[i]+1)/2;
				if(v[c[i]] == 0){
					v[c[i]] = id;
					if(s[id][0] != 0) s[id][1] = c[i];
					else s[id][0] = c[i];
					ans[++op][0] = 1;
					ans[op][1] = id;
				}else{
					if(s[id][0] == c[i]){
						if(s[id][1] == 0){
							ans[++op][0] = 1;
							ans[op][1] = id;
							v[c[i]] = 0;
							s[id][0] = 0;
						}else{
							ans[++op][0] = 1;
							ans[op][1] = n;
							ans[++op][0] = 2;
							ans[op][1] = id;
							ans[op][2] = n;
							v[c[i]] = 0;
							s[id][0] = s[id][1];
							s[id][1] = 0;
						}
					}else if(s[id][1] == c[i]){
						ans[++op][0] = 1;
						ans[op][1] = id;
						v[c[i]] = 0;
						s[id][1] = 0;
					}
				}
			}
			printf("%d\n",op);
			for(int i=1;i<=op;i++){
				printf("%d ",ans[i][0]);
				if(ans[i][0] == 1){
					printf("%d\n",ans[i][1]);
				}else{
					printf("%d %d\n",ans[i][1],ans[i][2]);
				}
			}
		}
		return 0;
	}
	else{
		while(T--){
			memset(c,0,sizeof(c));
			op = 0;
			n = read();
			m = read();
			k = read();
			for(int i=1;i<=m;i++)
				c[i] = read();
			for(int i=1;i<=m;i++){
				int id = (c[i]+1)/2;
				if(v[c[i]] == 0){
					v[c[i]] = id;
					if(s[id][0] != 0) s[id][1] = c[i];
					else s[id][0] = c[i];
					ans[++op][0] = 1;
					ans[op][1] = id;
				}else{
					if(s[id][0] == c[i]){
						if(s[id][1] == 0){
							ans[++op][0] = 1;
							ans[op][1] = id;
							v[c[i]] = 0;
							s[id][0] = 0;
						}else{
							int x = 0;
							for(int j=1;j<=n;j++)
								if(s[j][0] == 0){
									x = j;
									break;
								}
							ans[++op][0] = 1;
							ans[op][1] = x;
							ans[++op][0] = 2;
							ans[op][1] = id;
							ans[op][2] = x;
							v[c[i]] = 0;
							s[id][0] = s[id][1];
							s[id][1] = 0;
						}
					}else if(s[id][1] == c[i]){
						ans[++op][0] = 1;
						ans[op][1] = id;
						v[c[i]] = 0;
						s[id][1] = 0;
					}
				}
			}
			printf("%d\n",op);
			for(int i=1;i<=op;i++){
				printf("%d ",ans[i][0]);
				if(ans[i][0] == 1){
					printf("%d\n",ans[i][1]);
				}else{
					printf("%d %d\n",ans[i][1],ans[i][2]);
				}
			}
		}
	}
	return 0;
}
