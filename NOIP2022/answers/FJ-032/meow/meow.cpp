#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
int n, m, K;
const int MAXM = 2e6 + 10;
const int MAXN = 666;
int a[MAXM];
int f[MAXN][5], top[MAXN];
int vis1[MAXN], vis2[MAXN];
std::queue<int> q, h;
struct Modify {
    int op, a, b;   
    void prt() {
        if(op == 1) printf("1 %d\n", a);
        else printf("2 %d %d\n", a, b);
    }
};
struct Modify mod[MAXM * 2];
int mcnt;
void Add(int op, int a, int b = 0) {
    mod[++mcnt] = (Modify) {op, a, b};
//    mod[mcnt].prt(); 
}
void Work(int l, int id) { // id stack
//    meow("Work: %d %d\n", l, id);
    if(!vis2[id]) return;
    int t = vis2[id];
    Add(2, l, t);
    top[t]--;
    vis2[id] = 0;
    if(!top[t]) {
        vis1[id] = 0;
        return;
    }
    for(int i = 1; i <= top[t]; ++i) f[t][i] = f[t][i + 1];
    int x = f[t][1];
    if(vis2[x]) {
        Work(t, x);
    } else {
        vis2[x] = t;   
    }
} 
int main() {
    srand(time(0)); 
    freopen("meow.in", "r", stdin);
    freopen("meow.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        mcnt = 0;
        scanf("%d%d%d", &n, &m, &K);   
        for(int i = 1; i <= m; ++i) {
            scanf("%d", &a[i]);
        }   
        while(!q.empty()) q.pop();
        for(int i = 1; i <= n - 1; ++i) q.push(i);
        for(int i = 1; i <= n; ++i) vis1[i] = vis2[i] = 0;
        for(int i = 1; i <= m; ++i) {
//            meow("ADD: %d\n", i);
            if(vis1[a[i]]) {
                int x = vis1[a[i]]; // stack id
                top[x]--;
                vis1[a[i]] = 0;
                if(top[x] == 1) {
                    vis1[f[x][top[x]]] = x;
                } else {
                    vis2[a[i]] = 0;
                }
                Add(1, x);
            } else 
            if(vis2[a[i]]) {
                int x = vis2[a[i]];
                Add(1, n);
                Work(n, a[i]);
//                Add(2, x, n);
//                top[x]--;
//                if(top[x] == 0) {
//                    vis1[a[i]] = 0;
//                } else {
//                    vis2[f[x][top[x]]] = x;
//                }
//                vis2[a[i]] = 0;
            } else if(!q.empty()) {
                int x = q.front(); q.pop();
                Add(1, x);
                vis1[a[i]] = vis2[a[i]] = x;
                f[x][++top[x]] = a[i];
                h.push(x);
            } else if(!h.empty()) {
                int x = h.front(); h.pop();
                Add(1, x);
                int t = f[x][top[x]];
                vis1[t] = 0;
                vis1[a[i]] = x;
                f[x][++top[x]] = a[i];
            } else {
                if(a[i + 1] == a[i]) {
                    Add(1, n), Add(1, n);
                    ++i;   
                } else {
                    int x = vis2[a[i+1]];
                    Add(1, x);
                    vis1[a[i]] = vis2[a[i]] = x;
                    f[x][++top[x]] = a[i];
                } 
            }
//            meow("vis1: ");
//            for(int j = 1; j <= K; ++j) meow("%d ", vis1[j]);
//            meow("\nvis2: ");
//            for(int j = 1; j <= K; ++j) meow("%d ", vis2[j]);
//            meow("\n");
        }
        printf("%d\n", mcnt);
        for(int i = 1; i <= mcnt; ++i) mod[i].prt();
    }
    return 0;   
}
