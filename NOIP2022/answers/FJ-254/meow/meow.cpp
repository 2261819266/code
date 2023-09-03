#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long 
#define itn int 
inline int read(){
	int x = 0, f = 1;
	char ch;
	ch = getchar();
	while(!isdigit(ch)){
		if(ch=='-'){
			f=-f;
		}
		ch = getchar();
	}
	while(isdigit(ch)){
		x = (x << 1) + (x << 3) +(ch - '0');
		ch = getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
		putchar(x%10+'0');
	}
	else putchar(x+'0');
}
int T,n,m,k;
stack<int> s;
const int N = 0x3f3f3f;
ll a[N];
vector<int> v[305];
char ss;
bool b[N];
bool c[N];
ll cc[N];
ll bb[N];
ll vtop[N];
ll sum,sum1,sum2;
queue<int> empv;
bool emp[N];
bool ans;
void bfs(){
	if(s.empty()){
		for(int i=1;i<=n;i++){
			if(v[i].empty()) sum2++;
		}
		if(sum2==n) {
			ans=true;
			return;
		}
	}
	if(b[s.top()] == true&&!empv.empty()){
		sum1++;
		write(2);
		printf(" ");
		write(bb[s.top()]);
		printf(" ");
		write(empv.front());
		printf("\n");
		vtop[bb[s.top()]]++;
		if(v[bb[s.top()]].size()==vtop[bb[s.top()]]+1){
			empv.push(bb[s.top()]);
			emp[bb[s.top()]] = true;
		} 
		//cout<<s.top()<<" "<<empv.front()<<" "<<bb[s.top()]<<endl;
		b[s.top()]=false;
		bb[s.top()] = -1;
		s.pop();
		bfs();
	}
	else while(!s.empty()){
			if(ans == true) break;
			if(c[s.top()] == true){
				sum1++;
				write(1);
				printf(" ");
				write(cc[s.top()]);
				printf("\n");
			//	cout<<s.top()<<" "<<cc[s.top()]<<endl;
				v[cc[s.top()]].pop_back();
				if(v[cc[s.top()]].empty()){
					empv.push(cc[s.top()]);
					emp[cc[s.top()]] = true;
				} 
				c[s.top()] = false;
				cc[s.top()] = -1;
				s.pop();
				bfs();
			}
			else{
				int s1 = s.top();
				for(int i=1;i<=n;i++){
					if(ans == true) break;
					if(emp[i] == true) {
						b[s1] = true;
						bb[s1] = i;
						vtop[i]++;
						emp[i] = false;
						while(empv.front()!=i){
							empv.push(empv.front());
							empv.pop();
						}
						empv.pop();
					}
					else {
						c[v[i].back()] = false;
						cc[v[i].back()] = -1;
					}
					v[i].push_back(s1);
					c[s1] = true;
					s.pop();
					cc[s1] = i;
					bfs();
					sum--;
					s.push(s1);
					v[i].pop_back();
					if(v[i].empty()||v[i].size()==vtop[i]+1){
						b[s1] = false;
						bb[s1] = -1;
						vtop[i]--;
						emp[i] = true;
						empv.push(i);
					}
					else{
						c[v[i].back()] = true;
						cc[v[i].back()] = i;
					}
					c[s1] = false;
					cc[s1] = -1;
					if(ans == true) break;
				}
			} 
		if(ans == true) break;
	}
}
int main(){
//	freopen("meow.in","r",stdin);
//	freopen("meow.out","w",stdout);
	ss = getchar();
	T = ss-'0';
	//cout<<T<<endl;
	while(T--){
		while(!empv.empty()) empv.pop();
		memset(emp,true,sizeof(emp));
		memset(vtop,-1,sizeof(vtop));
		memset(b,false,sizeof(b));
		memset(c,-1,sizeof(c));
		memset(bb,false,sizeof(bb));
		memset(cc,-1,sizeof(cc));
		ans = false;
		n = read();m = read();
		for(int i =1;i<=n;i++){
			empv.push(i);
		}
		ss = getchar();k = ss-'0';
	//	cout<<n<<" "<<m<<" "<<k<<endl;
		for(int i=1;i<=m;i++){
			a[i] = read();
		//	cout<<a[i]<<endl;
		}
		for(int i=m;i>=1;i--){
			s.push(a[i]);
		}
		bfs(); 
		write(sum1);
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
