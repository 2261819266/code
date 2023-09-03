#include <cstdio>
#include <cstring>

int cnt[128];

int main() {
#ifdef LOCAL    
    LOCALfo
#endif
    int n;
    char ans[2][10] = {"No", "Yes"};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        memset(cnt, 0, sizeof(cnt));
        char s[100];
        scanf("%s", s);
        for (int i = 0; s[i]; i++) {
            cnt[s[i]]++;
        }
        int k = false;
        for (int i = 0; i < 128; i++) {
            if (cnt[i] >= 4) k = true;
        }
        if (cnt['X'] && cnt['D']) k = true;
        printf("%s\n", ans[k]);
    }
}