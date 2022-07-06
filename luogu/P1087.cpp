#include <cstdio>
#include <string.h>

const int N = 12, maxn = 4097;

struct node {
    int lc;
    char *data = new char[maxn];
    int rc;
    char k;
    node() { lc = rc = k = 0, memset(data, 0, sizeof(data)); }
    /* data */
};
node a[maxn];
int top;

void maketree(const char *s, int root = 0, int v = 0) {
    strcpy(a[++top].data, s);
    int len = strlen(s), t = top;
    if (root && v)
        (v == 1 ? a[root].lc : a[root].rc) = top;
    if (len == 1)
        return;
    char *s1 = new char[maxn], *s2 = new char[maxn];
    memset(s1, 0, maxn);
    memset(s2, 0, maxn);
    strncpy(s1, s, len / 2);
    strcpy(s2, s + len / 2);
    maketree(s1, t, 1);
    maketree(s2, t, 2);
    // maketree(strcpy())
}

void postorder_traversal(int x) {
    if (a[x].lc)
        postorder_traversal(a[x].lc);
    if (a[x].rc)
        postorder_traversal(a[x].rc);
    if (strlen(a[x].data) > 1)
        printf("%c",
               a[x].k = (a[a[x].lc].k == a[a[x].rc].k ? a[a[x].rc].k : 'F'));
    else
        printf("%c", a[x].k = (a[x].data[0] == '0' ? 'B' : 'I'));
}

char s[maxn];
int k;

int main() {
    scanf("%d%s", &k, s);
    maketree(s);
    postorder_traversal(1);
}