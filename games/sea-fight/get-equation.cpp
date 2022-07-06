#ifndef _ge

#define _ge
#include "const.cpp"
#include "make-map.cpp"
struct equation {
    char *contest = new char;

    void init() {
        reac_find = pro_find = 0;
        memset(reac, 0, sizeof(reac));
        memset(pro, 0, sizeof(pro));
    }

    void get_equation(const char *str) {
        strcpy(contest, str);
        init();
        int c = -1, d = 0, e = 0, k = 0;
        char *str1 = new char;
        while (true) {
            c++;
            if (str[c] == '+' || str[c] == '=') {
                str1[e] = 0;
                reac[thing_cl[str1]] = k == 0 ? 1 : k;
                reac_find++;
                if (str[c] == '=') {
                    break;
                }
                d++;
                e = 0;
                k = 0;
                continue;
            }
            if (Isnumber(str[c]) && e == 0) {
                k *= 10;
                k += str[c] - '0';
                continue;
            }
            str1[e++] = str[c];
        }
        d = 0, e = 0, k = 0;
        while (true) {
            c++;
            if (str[c] == '+' || str[c] == '.') {
                str1[e] = 0;
                pro[thing_cl[str1]] = k == 0 ? 1 : k;
                pro_find++;
                if (str[c] == '.') {
                    return;
                }
                d++;
                e = 0;
                k = 0;
                continue;
            }
            if (Isnumber(str[c]) && e == 0) {
                k *= 10;
                k += str[c] - '0';
                continue;
            }
            str1[e++] = str[c];
        }
    }

    // 各个反应物数量
    int reac[maxn];

    // 各个生成物数量
    int pro[maxn];

    // 反应物种数
    int reac_find;

    // 生成物种数
    int pro_find;
};

void get_equation(FILE *fin, equation *f,int &f_top) {
    while (true) {
        int x;
        char *str = new char;
        fscanf(fin,"%d", &x);
        if (x == -1)
            return;
        fscanf(fin,"%s", str);
        f[f_top++].get_equation(str + 1);
    }
}

#endif