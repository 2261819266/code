
/*
founder:Yu Xinhai
translate:Yu Xinhao
Creation date:2021.8.1(v.0.0.0)
This version Creation date:2021.8.4 18:36:26.(v.0.2.1)
Completion data:2021.8.5 20:25:46
file size: 17.5KB

化学大战 v.0.2.0
*/

#include <conio.h>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <map>
#include <windows.h>
#define min(X, Y) (X) < (Y) ? (X) : (Y)
#define Isxisy(X, Y) (((X) - 'A') % 32 == ((Y) - 'A') % 32)
#define Isnumber(X) ((X) >= '0' && (X) <= '9')
#define Isletter(X) (((X) >= 'A' && (X) <= 'Z') || (X) >= 'a' && (X) <= 'z')
#define pause system("pause")
#define maxn 31
#define maxf 105
#define maxin 4
#define max_attack 5
#define Backspace '\010'
#define Tab '\011'
#define Esc '\033'
#define __STR1 "formal.txt"
#define __STR2 "formal-nature.csv"
#define __STR3 "equation.txt"
#define __STR4 "luckydraw-proportion.txt"
#define R "r"
#define _STR1 "Your input is incorrect."
#define _STR2 "Please re-enter.\n\n"
#define _STR_1_2 "Your input is incorrect.Please re-enter.\n\n"
#define _STR3 "Not found it."
#define _STR_3_2 "Not found it.Please re-enter.\n\n"
#define _STR4 "Your %s has increased by %d\n\n"
#define _STR5 "You can't get it"
#define _STR6 "You get lucky draw.You can get:\n\n"
#define _STR7 "\n\nWhat do you want to get?\n"
#define _STR8 "You can't make it"
#define _STR9 " this way,because you don't have %s."
#define _STR10 "You can do it in these %d ways.\n\n"
#define _STR11 "Which way do you want to make it?\n"
#define _STR12 "You can make up to %d %s.How much %s do you want to make?\n"
#define _STR13 "You can't have it."
#define _STR14 "It can't attack"
#define _STR15 "You can attack the other party up to %d %s."
#define _STR16 "How huch %s do you want to attack?\n"
#define _STR17 "You let the other party lose %d drops of blood\n\n"
#define _STR18 "\t%s:\n\n\tWhat defense do you want?\n\t"
#define music1 "E:\\music\\1\\Victory.mp3"
#define music2 "E:\\music\\2\\14545.mp3"
#define music3 "E:\\music\\3\\13902.wav"
#define close "taskkill /f /im "
#define m1 system(music1)
#define m2 system(music2)
#define m3 system(music3)
#define close_mp3 system("taskkill /f /im PotPlayerMini64.exe")
#define close_wav system("taskkill /f /im 13902.wav")
FILE *FIN1 = fopen(__STR1, R);
FILE *FIN2 = fopen(__STR2, R);
FILE *FIN3 = fopen(__STR3, R);
FILE *FIN4 = fopen(__STR4, R);
COORD coordScreen = {0, 0};
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int K;

// 定义物品类
struct Thing {
    char *name = new char;

    Thing() {
        memset(name, 0, sizeof(name));
        cl = -1, initial_value = 0;
    }

    // 代号
    int cl;

    // 初始量
    int initial_value;

    // 储量
    int res;

    // 点击增量
    int press_inc;

    // 抽中比例
    int draw_prop;

    // 幸运大奖增量
    int lucky_inc;

    // 攻击力
    int agg;
};
Thing th[maxn];

bool Isxisy_str(const char *str1, const char *str2) {
    int n1 = strlen(str1), n2 = strlen(str2);
    if (n1 != n2)
        return false;
    for (int c = 0; c < n1; c++)
        if (!Isxisy(str1[c], str2[c]))
            return false;
    return true;
}

std::map<std::string, int> thing_cl;
std::map<std::string, Thing *> thing;
char *str_thing[maxn];
int top;

int getx() {
    // 获取光标位置X
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    return csbi.dwCursorPosition.X;
}

int gety() {
    // 获取光标位置Y
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    return csbi.dwCursorPosition.Y;
}

void gotoxy(int x, int y) {
    coordScreen.X = x;
    coordScreen.Y = y;
    SetConsoleCursorPosition(hConsole, coordScreen);
}

void gotoaddxy(int x, int y) {
    gotoxy(getx() + x, gety() + y);
    return;
}

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
equation f[maxf];
int f_top;

struct Player {
    void printf_formal_nature_exi() const {
        int e = 1;
        for (int c = 1; c < maxn; c++) {
            if (e % 21 == 0)
                printf("\n\n\n"), e++;
            int x = getx(), y = gety();
            if (t[c].cl != -1) {
                gotoaddxy(0, 1);
                printf("%d\t", exi[c]);
                gotoxy(x, y);
                printf("%s\t", t[c].name);
                e++;
            }
        }
        int x = getx(), y = gety();
        printf("Blood volume");
        gotoxy(x, y + 1);
        printf("%d/%d\n\n", exi[6], get_bv());
    }

    int get_bv() const { return exi[5] + exi[6] + exi[7]; }

    const char *name = new char;

    int exi[maxn];

    Thing *t = th;
};
Player player[3], *p = &player[1];

int lucky_draw_prop;
int make_thing_way[maxn][maxf], make_thing_n[maxn];

void make_map_thing_cl(FILE *fin) {
    int x;
    top = 0;
    char s;
    while (true) {
        fscanf(fin, "%d%c", &x, &s);
        if (x == -1)
            return;
        str_thing[top] = new char;
        fscanf(fin, "%s", str_thing[top]);
        thing_cl[str_thing[top++]] = x;
    }
}

void make_map(FILE *fin) {
    make_map_thing_cl(fin);
    int x;
    for (int c = 0; c < top; c++) {
        thing[str_thing[c]] = &th[thing_cl[str_thing[c]]];
        thing[str_thing[c]]->name = str_thing[c];
    }
}

void scanf_formal_nature(FILE *fin) {
    char *str = new char, s;
    while (s != '\n')
        fscanf(fin, "%c", &s);
    while (true) {
        int x;
        fscanf(fin, "%d,", &x);
        if (x == -1)
            return;
        Thing *s = &th[x];
        s->cl = x;
        fscanf(fin, "%d,%d,%d,%d,%d,%d", &s->res, &s->press_inc, &s->draw_prop,
               &s->lucky_inc, &s->initial_value, &s->agg);
    }
}

void get_equation(FILE *fin) {
    f_top = 0;
    char *str = new char;
    while (true) {
        int x;
        fscanf(fin, "%d%s", &x, str);
        if (x < 0)
            return;
        f[f_top++].get_equation(str + 1);
    }
}

int get_lucky_draw_proportion(FILE *fin) {
    fscanf(fin, "%d", &K);
    return K;
}

void get_make_thing_equation() {
    memset(make_thing_n, 0, sizeof(make_thing_n));
    for (int c = 0; c < f_top; c++) {
        for (int d = 1; d < maxn; d++) {
            if (f[c].pro[d])
                make_thing_way[d][++make_thing_n[d]] = c;
        }
    }
}

void initexi(Player *pl) {
    for (int c = 1; c < maxn; c++)
        if (pl->t[c].initial_value)
            pl->exi[c] = pl->t[c].initial_value;
}

void scan() {
    printf("Please press the first player's name:\n");
    scanf("%s", player[1].name);
    printf("Please press the second player's name:\n");
    scanf("%s", player[2].name);
    printf("To be continue:\n\n");
    pause;
}

void print(int k) {
    system("cls");
    // printf("****Chemical war****\n\n");
    printf("####\t  %s\n\n", p->name);
    p->printf_formal_nature_exi();
    printf("####\t  %s\n\n", (p + 1)->name);
    (p + 1)->printf_formal_nature_exi();
    printf("%s:\n\n", p[k].name);
    printf("What do you want to do?\n\n");
    printf("You can input what you want to do.\n");
    printf("\tsuch as:\"get something.\",\"draw.\",\"mack something .\"");
    printf(" or \"attack with something.\"\n\n");
}

int auto_fill(char **str) {

    char s, c = 1, *s1 = new char;
    bool a[maxn];
    memset(a, true, sizeof(a));
    int x = getx(), y = gety();
    for (int c = 0;; c++) {
    label:
        s = getch();
        if (s == '#') {
            printf("%s", "%d");
            return -2;
        }
        if (s == ' ' || s == '\015') {
            s1[c] = '\0';
            printf(" ");
            for (int d = 0; d < maxin; d++) {
                if (Isxisy_str(s1, str[d]))
                    return d;
            }
            return -1;
        }
        if (s == Tab) {
            for (int d = 0; d < maxin; d++)
                if (a[d]) {
                    gotoxy(x, y);
                    printf("%s", str[d]);
                    return d;
                }
            return -1;
        }
        if (s == Esc)
            return -1;
        if (!Isletter(s)) {
            c++;
            goto label;
        }
        for (int d = 0; d < maxin; d++) {
            if (Isxisy(s, str[d][c]) && a[d]) {
                gotoxy(x, y + 1);
                printf(str[d]);
                gotoxy(x + c, y);
                printf("%c", s);
                s1[c] = s;
            } else
                a[d] = false;
        }
    }
}

void format_str(char *str) {
    for (int c = 0; c < strlen(str); c++)
        if (!Isletter(str[c]) && !Isnumber(str[c])) {
            str[c] = '\0';
            break;
        }
}

int rd[maxn * maxn];

void init_draw() {
    rd[0] = 0;
    for (int c = 1; c < maxn; c++)
        for (int d = 1; d <= th[c].draw_prop; d++)
            rd[++rd[0]] = c;
    get_lucky_draw_proportion(FIN4);
    for (int c = 1; c <= K; c++)
        // 幸运大奖
        rd[++rd[0]] = -2;
}

int draw() {
    int k = rand() % rd[0] + 1;
    return rd[k];
}

void draw(int k) {
    int x = draw();
    if (x == -2) {
        printf(_STR6);
        for (int c = 1; c <= maxn; c++) {
            if (p->t[c].lucky_inc)
                printf("%s %d.\n", th[c].name, th[c].lucky_inc);
        }
        printf(_STR7);
        char *str = new char;
        while (scanf("%s", str) && thing_cl[str] == 0) {
            printf(_STR_3_2);
        }
        int x = thing_cl[str];
        int get_max;
        get_max = min(th[x].lucky_inc, th[x].res - p[k].exi[x]);
        printf(_STR4, th[x].name, get_max);
        p[k].exi[x] += get_max;
        return;
    }
    int e;
    e = p[k].exi[x] < th[x].res ? 1 : 0;
    printf(_STR4, th[x].name, e);
    p[k].exi[x] += e;
    return;
}

bool Is_thing_make_false(int k, int way, bool boo = true) {
    for (int c = 1; c < maxn; c++) {
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
    int g=0;
    for (int c = 1; c <= make_thing_n[x]  && g < n; c++) {
        int e;
        if (Is_thing_make_false(k, e = make_thing_way[x][c], false)) {
            way = e;
            g++;
        }
    }

    if (!Is_thing_make_false(k, way))
        return false;
    int get_max = th[x].res;
    for (int c = 1; c < maxn; c++) {
        if (f[way].pro[c])
            get_max = min(get_max, (th[c].res - p[k].exi[c]) / f[way].pro[c]);
    }
    for (int c = 1; c <= maxn; c++) {
        if (f[way].reac[c])
            get_max = min(get_max, p[k].exi[c] / f[way].reac[c]);
    }
    printf(_STR12, get_max * f[way].pro[x], th[x].name, th[x].name);
    scanf("%d", &nn);
    nn /= f[way].pro[x];
    nn > get_max ? nn = get_max : 0;
    for (int c = 1; c < maxn; c++)
        p[k].exi[c] -= f[way].reac[c] * nn;
    for (int c = 1; c < maxn; c++)
        p[k].exi[c] += f[way].pro[c] * nn;
    printf(_STR4, th[x].name, nn * f[way].pro[x]);
    return true;
}

void attack(int k, int x) {
    int attack_max = min(p[k].exi[x], max_attack), n;
    printf(_STR15, attack_max, th[x].name);
    printf(_STR16, th[x].name);
    scanf("%d", &n);
    n = min(n, attack_max);
    int e = p[!k].get_bv();
    int agg = th[x].agg * n;
    while (agg > 0 && p[!k].exi[12]) {
        if (agg == 1) {
            agg = 0;
            break;
        }
        p[!k].exi[12]--;
        agg -= 2;
    }
    if ((p[!k].exi[5] || p[!k].exi[7]) && agg) {
        printf(_STR18, p[!k].name);
        char *str = new char;
        scanf("%s", str);
        int s = thing_cl[str];
        while (agg && p[!k].exi[s]) {
            agg--;
            p[!k].exi[s]--;
        }
    }
    if ((p[!k].exi[5] || p[!k].exi[7]) && agg) {
        printf(_STR18, p[!k].name);
        char *str = new char;
        scanf("%s", str);
        int s = thing_cl[str];
        while (agg && p[!k].exi[s]) {
            agg--;
            p[!k].exi[s]--;
        }
    }
    p[!k].exi[6] -= agg;
    printf(_STR17, e - p[!k].get_bv());
    p[k].exi[x] -= n;
    m3;
}

void init() {
    system("color e0");
    SetConsoleTitle(TEXT("Chemical war v.0.2.0"));
    make_map(FIN1);
    scanf_formal_nature(FIN2);
    get_equation(FIN3);
    get_lucky_draw_proportion(FIN4);
    get_make_thing_equation();
    scan();
    initexi(p);
    initexi(p + 1);
    init_draw();
    close_mp3;
    m2;
}

void play() {
    int k = 0;
    while (true) {
        if (p[k].exi[6] <= 0) {
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
        st[3] = new char;
        strcpy(st[0], "draw");
        strcpy(st[1], "get");
        strcpy(st[2], "make");
        strcpy(st[3], "attack with");
        int kk = auto_fill(st);
        switch (kk) {
        case 0: {
            printf("\n\n");
            draw(k);
            pause;
            k = !k;
            continue;
        }

        case 1: {
            scanf("%s", str);
            format_str(str);
            int x = thing_cl[str];
            if (x == -1) {
                printf(_STR_3_2);
                continue;
            }
            int get_max;
            get_max = min(th[x].res - p[k].exi[x], th[x].press_inc);
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

        case 2: {
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

        case 3: {
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
            attack(k, x);
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
                player[a].exi[thing_cl[str]] = x;
                continue;
            }
            if (x == 2) {
                int a;
                scanf("%d%s%d", &a, str, &x);
                player[a].exi[thing_cl[str]] += x;
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

int main() {
    srand((unsigned)time(NULL));
    init();
    play();
    return 0;
}
