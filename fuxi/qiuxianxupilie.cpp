#include <cstdio>
#include <string.h>

const int maxn = 100;

struct node {
    int lc;
    char data;
    int rc;
    node() { lc = rc = 0; }
    /* data */
};

node a[maxn];
int top;

int find(const char *a, char b) {
    for (int c = 0; c < strlen(a); c++)
        if (a[c] == b)
            return c;
    return -1;
}

void cc(const char *in, const char *post, int root = 0, int v = 0) {
    int c, d, e, len = strlen(in), t;
    a[++top].data = post[len - 1];
    if (root && len)
        (v == 1 ? a[root].lc : a[root].rc) = top;
    if (len <= 1) {
        return;
    }

    e = find(in, post[len - 1]);
    char *in1 = new char[maxn], *in2 = new char[maxn], *post1 = new char[maxn],
         *post2 = new char[maxn];
    memset(in1, 0, sizeof(in1));
    memset(in2, 0, sizeof(in2));
    memset(post1, 0, sizeof(post1));
    memset(post2, 0, sizeof(post2));
    strncpy(in1, in, e);
    strcpy(in2, in + e + 1);
    strncpy(post1, post, e);
    strncpy(post2, post + e, len - e - 1);
    t = top;
    cc(in1, post1, t, 1);
    cc(in2, post2, t, 2);
}

void preorder_traversal(int x) {
    printf("%c", a[x].data);
    if (a[x].lc)
        preorder_traversal(a[x].lc);
    if (a[x].rc)
        preorder_traversal(a[x].rc);
}

char preorder[maxn], inorder[maxn], postorder[maxn];
int len, c, d, e, n;

int main() {
    scanf("%s%s", inorder, postorder);
    cc(inorder, postorder);
    preorder_traversal(1);
}