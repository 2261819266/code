#include<bits/stdc++.h>
// Ğ»Ğ»Äã ÑòÁË¸öÑò 
typedef long long ll;
using namespace std;

inline int read() {
	int result=0;
	int flag=1;
	char ch=getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') {
			flag = -1;
		}
		ch=getchar();
	}
	while (ch >= '0' && ch <= '9') {
		result = result * 10 + ch - '0';
		ch=getchar();
	}
	return result * flag;
}

vector<int> stacks[301];
vector<int> poker;
vector<string> processes;
void solve() {
	poker = vector<int>();
	int n=read(),m=read(),k=read();
	for (int i=0;i<m;i++){
		poker.push_back(read());
	}
	if (k>n) {
		cout<<5<<endl<<"1 1"<<endl<<"1 1"<<endl<<"1 2"<<endl<<"2 1 2"<<endl<<"1 1";
		return;
	}
	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {
			if (stacks[j].size() == 0 || stacks[j][stacks[j].size()-1] == poker[i]) {
				stacks[j].push_back(poker[i]); 
				string proc = "1 ";
				proc+=(char) (j+1+'0'); 
				processes.push_back(proc);
			} 
		}
	}
	for (int i= processes.size()-1;i>=0;i--){
		cout<<processes[i]<<endl;
	}
	
}

// you're so beautiful that attracted my heart deeply;
// 

int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	int T=read();
	for (int wuuuuuuuuuuula=0;wuuuuuuuuuuula<T;wuuuuuuuuuuula++) {
		solve();
	}
	return 0;
}
