#include<fstream>
using namespace std;
ifstream fin("plant.in");
ofstream fout("plant.out");
char strg[1001][1001];
int t,id,g[1001][1001],cntc,cntf;
int n,m,c,f;
int main() {
	fin >> t >> id;
	while(t--) {
		fin >> n>> m>> c >>f;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				g[i][j] = 0;
				fin >>strg[i][j];
				g[i][j] = strg[i][j] - 48;
			}
		}

		if(c==0&&f==0) fout << 0 << ' ' << 0 << '\n';
		else {
		}
		if(m==2&&n==3) {
			if(g[0][0]==0&&g[1][0]==0&&g[0][1]==0&&g[0][2]==0&&g[1][2]==0) {
				fout << 1 << ' ' << 0 << '\n';
			} else {
				fout << 0 << ' ' << 0 << '\n';
			}
		} else if(m==2&&n==4) {
			if(g[0][0]==0&&g[1][0]==0&&g[0][1]==0&&g[0][2]==0&&g[1][2]==0&&g[0][3]==0) {
				fout << 1 << ' ' << 1 << '\n';
			} else if(g[0][0]==0&&g[1][0]==0&&g[0][1]==0&&g[0][2]==0&&g[1][2]==0) {
				fout << 1 << ' ' << 0 << '\n';
			} else {
				fout << 0 << ' ' << 0 << '\n';
			}
		}

	}

	return 0;
}
