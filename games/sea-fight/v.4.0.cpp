
/*
Creation date:2021.8.6 15:31:07

sea fight v.4.0

*/

#include "allfile.cpp"
#include <conio.h>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <windows.h>
Thing th[maxn];
Player pl[3], *p = &pl[1];
equation f[maxe];
int f_top = 0;
int make_thing_way[maxn][maxe], make_thing_n[maxn];
int CL;

void get_make_thing_equation() {
    memset(make_thing_n, 0, sizeof(make_thing_n));
    for (int c = 0; c < f_top; c++) {
        for (int d = 0; d < maxn; d++) {
            if (f[c].pro[d])
                make_thing_way[d][++make_thing_n[d]] = c;
        }
    }
}

void print(int k) {
    system("cls");
    // printf("****Chemical war****\n\n");
    printf("####\t  %s\n\n", p->name);
    p->printf_formal_nature_exi(th);
    printf("####\t  %s\n\n", (p + 1)->name);
    (p + 1)->printf_formal_nature_exi(th);
    printf("%s:\n\n", p[k].name);
    printf("What do you want to do?\n\n");
    printf("You can input what you want to do.\n");
    printf("\tsuch as:\"get something.\",\"mack something .\"");
    printf(" or \"attack with something (on something).\"\n\n");
}

bool Is_thing_make_false(int k, int way, bool boo = true) {
    for (int c = 0; c < maxn; c++) {
        if (f[way].reac[c] > p[k].exi[c]) {
            if (boo)
                printf(_STR8), printf(_STR9, th[c].name);
            return false;
        }
    }
    return true;
}

bool make(int k, int x) {
    int nn = 0, way, n;
    n = 1;
    way = make_thing_way[x][1];
    if (make_thing_n[x] > 1) {
        for (int c = 1; c <= make_thing_n[x]; c++) {
            if (Is_thing_make_false(k, make_thing_way[x][c], false)) {
                nn++, n = nn == 1 ? c : n;
            }
        }
        if (nn == 0) {
            printf("%s%s", _STR8, _STR2);
            return false;
        }
    }
    if (nn > 1) {
        int g = 0;
        printf(_STR10, nn);
        for (int c = 1; c <= make_thing_n[x] && g < nn; c++) {
            int e;
            if (Is_thing_make_false(k, e = make_thing_way[x][c], false)) {
                printf("\t%d=>%s\n", ++g, f[e].contest);
            }
        }
        printf(_STR11);
        scanf("%d", &n);
        n > nn ? n = nn : 0;
    }
    int g = 0;
    for (int c = 1; c <= make_thing_n[x] && g < n; c++) {
        int e;
        if (Is_thing_make_false(k, e = make_thing_way[x][c], false)) {
            way = e;
            g++;
        }
    }

    if (!Is_thing_make_false(k, way))
        return false;
    int get_max = th[x].res;
    for (int c = 0; c < maxn; c++) {
        if (f[way].pro[c])
            get_max =
                std::min(get_max, (th[c].res - p[k].exi[c]) / f[way].pro[c]);
    }
    for (int c = 0; c <= maxn; c++) {
        if (f[way].reac[c])
            get_max = std::min(get_max, p[k].exi[c] / f[way].reac[c]);
    }
    printf(_STR12, get_max * f[way].pro[x], th[x].name, th[x].name);
    scanf("%d", &nn);
    nn /= f[way].pro[x];
    nn > get_max ? nn = get_max : 0;
    for (int c = 0; c < maxn; c++)
        p[k].exi[c] -= f[way].reac[c] * nn;
    for (int c = 0; c < maxn; c++) {
        p[k].exi[c] += f[way].pro[c] * nn;
        if (th[c].is == 'G' && f[way].pro[c]) {
            for (int d = 0; d < f[way].pro[c] * nn; d++) {
                p[k].gunbv[c].push(th[c].bv);
            }
        }
    }
    printf(_STR4, th[x].name, nn * f[way].pro[x]);
    return true;
}

void attack(int k, int x, int guncl, int aggcl = 0) {
    if (aggcl > 0) {
        int attack_max = std::min(p[k].exi[x], p[k].exi[guncl]), n;
        printf("Which %s do you want to attack?\n", th[aggcl].name);
        int y;
        scanf("%d", &y);
        y--;
        y > p[!k].gunbv[aggcl].size() ? y = p[!k].gunbv[aggcl].size() : 0;
        printf(_STR15, attack_max, th[x].name);
        printf(_STR16, th[x].name);
        scanf("%d", &n);
        n = std::min(n, attack_max);
        int agg = th[x].agg * n;
        m3;
        p[!k].gunbv[aggcl][y] -= agg;
        if (p[!k].gunbv[aggcl][y] <= 0) {
            p[!k].gunbv[aggcl].pop(y);
            printf("The other part's %s is bomb", th[aggcl].name);
        }
        p[k].exi[guncl] -= n;
        return;
    }
    int attack_max = std::min(p[k].exi[x], p[k].exi[guncl]), n;
    printf(_STR15, attack_max, th[x].name);
    printf(_STR16, th[x].name);
    scanf("%d", &n);
    n = std::min(n, attack_max);
    int e = p[!k].get_bv();
    int agg = th[x].agg * n;
    m3;
    p[!k].exi[aggcl] -= agg;
    printf(_STR17, e - p[!k].get_bv());
    p[k].exi[x] -= n;
}

void play() {
    int k = 0;
    while (true) {
        close_wav;
        if (p[k].get_bv() <= 0) {
            m3;
            m3;
            m3;
            printf("%s is over,", p[k].name);
            printf("%s is win!\n\nThe game is over\n\n", p[!k].name);
            system("pause");
            return;
        }

        print(k);
        char *str = new char;
        char *st[maxin];
        st[0] = new char;
        st[1] = new char;
        st[2] = new char;
        strcpy(st[0], "get");
        strcpy(st[1], "make");
        strcpy(st[2], "attack with");
        int kk = auto_fill(st);
        switch (kk) {
        case 0: {
            scanf("%s", str);
            format_str(str);
            int x = thing_cl[str];
            if (x == -1) {
                printf(_STR_3_2);
                continue;
            }
            int get_max;
            get_max = std::min(th[x].res - p[k].exi[x], th[x].press_inc);
            if (get_max == 0) {
                printf("%s%s", _STR5, _STR2);
                continue;
            }
            p[k].exi[x] += get_max;
            printf(_STR4, th[x].name, get_max);
            k = !k;
            pause;
            continue;
            break;
        }

        case 1: {
            scanf("%s", str);
            format_str(str);
            int x = thing_cl[str];
            if (make_thing_n[x] == 0) {
                printf("%s.%s", _STR8, _STR2);
                pause;
                continue;
            }
            if (make(k, x))
                k = !k;
            pause;
            continue;
        }

        case 2: {
            scanf("%s", str);
            format_str(str);
            int x = thing_cl[str];
            if (th[x].agg == 0) {
                printf("%s%s", _STR14, _STR2);
                continue;
            }
            if (p[k].exi[x] == 0) {
                printf("%s%s", _STR13, _STR2);
                continue;
            }
            int a_from;
            if (th[x].is == 'S') {
                scanf(" %s %s", str, str);
                a_from = thing_cl[str];
                if (p[k].exi[a_from] == 0) {
                    printf("You don't have %s%s\n\n", th[a_from].name, _STR2);
                    pause;
                    continue;
                }
                if (th[a_from].is != 'G') {
                    printf("%s can't fire!%s", th[a_from].name, _STR2);
                    pause;
                    continue;
                }
                bool n = false;
                for (int c = 0; c < th[a_from].an; c++)
                    if (th[a_from].attack[c] == true)
                        n = true;
                if (!n) {
                    printf("%s%s", _STR21, _STR2);
                    pause;
                    continue;
                }
            }
            int n = 1;
            for (int c = 0; c < maxn; c++) {
                if (th[c].is == 'G' && th[a_from].attack[c])
                    n += p[!k].gunbv[c].size();
            }
            if (n > 1) {
                printf(_STR19);
                for (int c = 0; c < maxn; c++) {
                    if (th[c].is == 'G' && th[a_from].attack[c]) {
                        printf(",%s", th[c].name);
                    }
                }
                printf(_STR20);
                int aggcl;
                char *str = new char;
                scanf("%s", str);

                if (Isxisy_str(str, "ship"))
                    aggcl = 0;
                else
                    aggcl = thing_cl[str];
                attack(k, x, a_from, aggcl);
                k = !k;
                pause;
                continue;
            }
            attack(k, a_from, x);
            k = !k;
            pause;
            continue;
        }

        case -2: {
            int x;
            char *str = new char;
            scanf("%d", &x);
            if (x == 1) {
                int a;
                scanf("%d%s%d", &a, str, &x);
                pl[a].exi[thing_cl[str]] = x;
                continue;
            }
            if (x == 2) {
                int a;
                scanf("%d%s%d", &a, str, &x);
                pl[a].exi[thing_cl[str]] += x;
                continue;
            }
            if (x == 3) {
                k = !k;
            }
        }

        default: {
            printf(_STR_1_2);
            pause;
            break;
        }
        }
    }
}

void init() {
    make_top();
    char *str1 = new char, *str2 = new char;
    system("color e0");
    SetConsoleTitle(TEXT("sea fight v.4.0\n"));
    get_formal_Basic_info(FIN1, th);
    get_neture(FIN2, th);
    printf(_P1);
    scanf("%s", str1);
    printf(_P2);
    scanf("%s", str2);
    p->init_exi(th, str1);
    (p + 1)->init_exi(th, str2);
    make_map(th);
    get_equation(FIN3, f, f_top);
    get_make_thing_equation();
    close_mp3;
    m1;
    m2;
    CL = clock();
}

int main() {
    init();
    play();
    pause;
}