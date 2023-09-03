#include<bits/stdc++.h>
using namespace std;
inline int readSingle() {
	char ch=getchar();
	while (ch < '0' || ch > '9') {
		ch=getchar();
	}
	return ch - '0';
}
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
inline void write(int target) {
	if (target > 9) {
		write(target/10);
	}
	putchar(target%10+'0');
}
inline void writeSpace() {
	putchar(' ');
}
inline void writeBr() {
	putchar('\n');
}
const long long mod = 998244353;
long long ansC=0,ansF=0;
int gardenMap[1010][1010];
int n,m,c,f;

void solve(int x,int y) {
	
	int lengths[1010];
	int possibleY[1010];
	memset(lengths, 0, sizeof(lengths));
	memset(possibleY, 0, sizeof(possibleY));
	int index = 0,index2=0;
	
	for (int i = y;i<n;i++) {
		if (gardenMap[i][x] == 1) {
			solve(x,i+1);
			break;
		}
		for (int j=x;j<m;j++) {
			if (gardenMap[i][j] == 0) {
				lengths[i]++;
			} else {
				break;
			}
		}
		if (lengths[i] > 0){
			index++;
			if (lengths[i] > 1) {
				possibleY[index2]=i;
				index2++;
			}
		}
	}

	if (index < 3) {
		return;
	}
	
	long long aC=0, aF=0;
	for (int i =0;i<index2-1;i++){
		for (int j=i+1;j<index2;j++) {
			if (possibleY[j] == possibleY[i]+1) {
				continue;
			}
			aC += ((lengths[possibleY[i]]-1)*(lengths[possibleY[j]]-1));
			if (possibleY[j] != n-1) {
				aF += ((lengths[possibleY[i]]-1)*(lengths[possibleY[j]]-1)) * (y+index-(possibleY[j]+1));
			}
		}
	}
	
	ansC += (aC%mod);
	ansC = ansC % mod;
	ansF += (aF%mod);
	ansF = ansF % mod;
}

// to lbh:
// do you know?
// you had me at hello.
// wuuuuuuuuuuuuuuuuuuuuuuuula

int main () {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	int T=read(),id=read();
	n=read();
	m=read();
	c=read();
	f=read();
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			gardenMap[i][j] = readSingle();
		}
	}
	
	// ? 为什么白送我一分
	// 谢谢你CCF
	if (c == 0 && f == 0) {
		cout<<"0 0";
		return 0;
	} else {
		for (int i=0;i<m;i++){
			solve(i,0);
		}
		cout<<ansC%mod<<" "<<ansF%mod;
	}
	
	return 0;
}
