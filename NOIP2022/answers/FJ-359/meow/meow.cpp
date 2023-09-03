#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 300+10;
const int inf = INT_MAX;
int read(){
	char ch=getchar();
	int f=1,s=0;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return f*s;
}
int t,cnt;
int n,m,k;
int b[N*3];
void init(){
	cnt=0;
	memset(b,0,sizeof(b));
}
/*namespace Task1{
	int ans=0;
	void work(){
		vector<int>q1,q2,v;
		for(int i=1;i<=m;i++){
			int a=read();
			v.push_back(a);
			if(v.size()>=2){
				
				while(!v.empty()){
					if(v[1]==v[2]){v.pop();v.pop();printf("1 1\n1 1\n");}
					else{
						if(q1.empty()){
							if(q2[q2.size()-1]==a){
//								q1.push_back(a);
								v.pop_front();
								printf("1 1\n2 1 2\n");
								continue;
							}
						}
						if(q2.empty()){
							if(q1[q1.size()-1]==a){
								v.pop_front();
								printf("1 2\n2 1 2\n");
								continue;
							}
						}
						if(a==q1[q1.size()-1]){q1.pop_back();printf("1 1\n");continue;}
						if(a==q2[q2.size()-1]){q2.pop_back();printf("1 2\n");continue;}	
						break;					
					}
				}
			}
		}
	}
}*/
signed main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	t=read();
	while(t--){
		n=read(),m=read(),k=read();
		init();		
		printf("%lld\n",m);
		for(int i=1;i<=m;i++){
			int a=read();
			if(!b[a])b[a]=++cnt;
			printf("1 %lld\n",b[a]);
		}
	}
	return 0;
}

