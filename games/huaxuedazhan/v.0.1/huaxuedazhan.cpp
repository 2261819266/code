/*  化学大战  */

#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <windows.h>
#define min(X, Y) (X) < (Y) ? X : Y

// #define K true
bool K;
const int maxn = 30, maxf = 105;
struct Thing {
    char *name = new char;

    // 代号
    int cl;

    // 现存
    int exi;

    Thing() { memset(name, 0, sizeof(name)), cl = -1, exi = 0, fy_pro[0] = 0; }

    void getcl() {
        char *str = new char;
        int num;
        char s;
        FILE *fin = fopen("wupin.txt", "r");
        while (fscanf(fin, "%d%c%s", &num, &s, str))
            if (strcmp(name, str) == 0) {
                cl = num;
                return;
            }
    }

    int getlen() const { return strlen(name); }
    // 储量
    int res;

    // 点击增量
    int press_inc;

    // 抽中比例
    int dp;

    // 幸运大奖增量
    int lucky_inc;

    // 攻击力
    int agg;

    void get_wpxz(int c, const char *str, int r, int p, int d, int l, int e,
                  int a) {
        cl = c, strcpy(name, str), res = r, press_inc = p, dp = d,
        lucky_inc = l, exi = e, agg = a;
    }

    void printf_wpxz() const {
        printf("%d\t%s\t%d\t%d\t%d\t%d\n", cl, name, res, press_inc, dp,
               lucky_inc);
    }
    // 制作它所需关联的反应方程式的代号
    int fy_pro[5];
};

// 定义反应类
class fangying {
  private:
    // 反应物数量
    int rn = 1;

    // 反应物
    Thing reac[maxn];

    // 生成物数量
    int pn = 1;

    // 生成物
    Thing pro[maxn];

  public:
    bool k = false;

    void getf(const char *str) {
        char s;
        int c = 0;
        while (s = str[c++]) {
            if (s == '.')
                break;
            if (s == '=') {
                k = true;
                continue;
            }
            if (s == '+') {
                if (k)
                    pn++;
                else
                    rn++;
                continue;
            }
            if (k)
                pro[pn].name[pro[pn].getlen()] = s;
            else
                reac[rn].name[reac[rn].getlen()] = s;
        }

        for (c = 1; c <= rn; c++) {
            reac[c].getcl();
        }
        for (c = 1; c <= pn; c++) {
            pro[c].getcl();
        }

        k = true;
    }

    int *getpro() const {
        int *a = new int;
        for (int c = 1; c <= pn; c++)
            a[c] = pro[c].cl;
        a[0] = pn;
        return a;
    }
    int *getreac() const {
        int *a = new int;
        for (int c = 1; c <= rn; c++)
            a[c] = reac[c].cl;
        a[0] = rn;
        return a;
    }

} f[maxf];

class player {
  private:
    char *name = new char;

    // 血量
    int bv;

  public:
    Thing t[maxn];

    // 输入玩家名称
    void scan() { scanf("%s", name); }

    // 输出玩家名称
    void print(const char *str = "") const { printf("%s", name), printf(str); }

    // 输入物品性质
    void scanf_wpxz() {
        FILE *fin = fopen("wupinxinzhi.txt", "r");
        int c, r, p, d, l, e, a;
        char *str = new char;
        while (fscanf(fin, "%d", &c)) {
            if (c == -1)
                break;
            fscanf(fin, "%s%d%d%d%d%d%d", str, &r, &p, &d, &l, &e, &a);
            t[c].get_wpxz(c, str, r, p, d, l, e, a);
        }
    }

    // 输出物品性质
    void printf_wpxz() const {
        for (int c = 1; c < maxn; c++)
            if (t[c].cl != -1)
                t[c].printf_wpxz();
    }

    int get_bv() const { return t[6].exi + t[7].exi + t[5].exi; }

    void printf_wp(const char *str = "\t") const {
        for (int c = 1; c < maxn; c++)
            if (t[c].cl != -1)
                printf("%s%s", t[c].name, str);
        printf("Blood volume\n\n");
    }

    void printf_exi(const char *str = "\t") const {
        for (int c = 1; c < maxn; c++)
            if (t[c].cl != -1)
                printf("%d\t", t[c].exi, str);
        printf("%d\n\n", get_bv());
    }

    void get_fy_pro() {
        for (int c = 1; f[c].k; c++) {
            int *a = new int;
            a = f[c].getpro();
            for (int d = 1; d <= a[0]; d++)
                t[a[d]].fy_pro[++t[a[d]].fy_pro[0]] = c;
        }
    }

} p[3];

// 读取反应方程式
void get_equation() {
    FILE *fin = fopen("fanying.txt", "r");
    char s, str[101][101];
    int num, top;
    while (true) {
        // str[top] = new char;
        fscanf(fin, "%d%c%s", &num, &s, str[top]);
        if (num == -1)
            break;
        top++;
    }
    while (top)
        f[top].getf(str[--top]);
}

// 读入是否有幸运大奖
void get_K() {
    FILE *fin = fopen("xingyundajiang-true.txt", "r");
    fscanf(fin, "%d", &K);
}

// 输入玩家名字
void scan() {
    printf("Please press the first player's name:\n");
    p[1].scan();
    printf("Please press the second player's name:\n");
    p[0].scan();
    printf("To be continue:\n\n");
    system("pause");
}

// 输出信息
void print(int k) {
    system("cls");
    // printf("****Chemical war****\n\n");
    printf("####\t  ");
    p[1].print(":\n\n");
    p[1].printf_wp();
    p[1].printf_exi();
    printf("####\t  ");
    p[0].print(":\n\n");
    p[0].printf_wp();
    p[0].printf_exi();
    p[k].print(":\n\n");
    printf("What do you want to do?\n\nYou can input what you want to "
           "do.\n\tsuch as:\"get something.\",\"draw.\",\"mack something "
           "number(int=1).\" "
           "or \"attack with something number(int=1).\"\n\n");
}

// 判断是否为数字
bool Isnumber(char s) {
    if (s >= '0' && s <= '9')
        return true;
    return false;
}

// 定义抽奖数组  rd[0]存总比例 其他存抽中数值代表的可抽奖的物品代号
int rd[maxn * maxn];

void init_draw() {
    rd[0] = 0;
    for (int c = 1; c <= maxn; c++)
        for (int d = 1; d <= p->t[c].dp; d++)
            rd[++rd[0]] = c;
    get_K();
    for (int c = 1; c <= K; c++)
        // 幸运大奖
        rd[++rd[0]] = -2;
}

int draw() {
    int k = rand() % rd[0] + 1;
    return rd[k];
}

// 初始化
void init() {

    system("color e0");
    SetConsoleTitle(TEXT("Chemical war v.0.1.3.6"));
    get_equation();
    p[1].scanf_wpxz();
    p[0].scanf_wpxz();
    scan();
    p[1].get_fy_pro();
    p[0].get_fy_pro();
    init_draw();
}

// 判断是否为字母
bool Isletter(char s) {
    if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
        return true;
    return false;
}

// 点击增量
bool addexi(int k, int x) {

    if (x == -1) {
        printf("Your input is incorrect.Please re-enter.\n\n");
        return false;
    }
    if (p->t[x].press_inc) {
        if (p[k].t[x].exi + p->t[x].press_inc > p->t[x].res) {
            printf(
                "Your reserves of %s will full.You can only get %s by %d.Do "
                "you want to continue?(\"Y\"or else letter to be continue)\n",
                p->t[x].name, p->t[x].name, p->t[x].res - p->t[x].exi);
            char s;
            s = getch();
            if (s == 'Y') {
                printf("Your %s has increased by %d\n\n", p->t[x].name,
                       p->t[x].res - p[k].t[x].exi);
                p[k].t[x].exi = p->t[x].res;
                return true;
            }
            return false;
        }

        printf("Your %s has increased by %d\n\n", p->t[x].name,
               p->t[x].press_inc);
        p[k].t[x].exi += p->t[x].press_inc;
        return true;
    }
    printf("You can't get it.Please re-enter to continue.\n\n");
    return false;
}

void draw(int k) {
    int x = draw();
    if (x == -2) {
        printf("You get lucky draw.You can get:\n\n");
        for (int c = 1; c <= maxn; c++) {
            if (p->t[c].lucky_inc)
                printf("%s %d.\n", p->t[c].name, p->t[c].lucky_inc);
        }
        printf("\n\nWhat do you want to get?\n");
        int x = -2;
        char *str = new char;
        do {
            if (x == -1)
                printf("Your input is incorrect.Please re-enter.\n\n"), x--;
            scanf("%s", str);
            for (int d = 1; d <= maxn; d++)
                if (strcmp(p->t[d].name, str) == 0) {
                    x = d;
                }
        } while (!p->t[x++].lucky_inc);
        x--;
        int e = p[k].t[x].exi;
        p[k].t[x].exi += p->t[x].lucky_inc;
        p[k].t[x].exi > p->t[x].res ? p[k].t[x].exi = p->t[x].res : 1;
        printf("Your %s has increased by %d\n\n", p->t[x].name,
               p[k].t[x].exi - e);
        return;
    }
    int e = p[k].t[x].exi;
    p[k].t[x].exi++;
    p[k].t[x].exi > p->t[x].res ? p[k].t[x].exi = p->t[x].res : 1;
    printf("Your %s has increased by %d\n\n", p[k].t[x].name,
           p[k].t[x].exi - e);
    return;
}

bool make(int k, int x) {
    int y = p->t[x].fy_pro[1];
    int make_max = 0x7fffffff, *a = new int, c;
    a = f[y].getreac();
    for (c = 1; c <= a[0]; c++) {
        make_max = min(make_max, p[k].t[a[c]].exi);
        if (min(make_max, p[k].t[a[c]].res - p[k].t[a[c]].exi))
            if (make_max <= 0)
                break;
    }
    if (make_max <= 0) {
        printf(
            "You can't make it,because you don't have %s.Please re-enter.\n\n",
            p->t[c].name);
        system("pause");
        return false;
    }
    if (x == 6 || x == 4)
        make_max *= 2;
    printf("You can make up to %d %s.How much %s do you want to make?\n",
           make_max, p->t[x].name, p->t[x].name);
    int n;
    if (x == 6 || x == 4)
        make_max /= 2;
    scanf("%d", &n);
    if (x == 6 || x == 4)
        n /= 2;
    n = n > make_max ? make_max : n;
    n = n > p->t[x].res ? p->t[x].res : n;
    for (int c = 1; c <= a[0]; c++) {
        p[k].t[a[c]].exi -= n;
    }
    if (x == 6 || x == 4)
        n *= 2;
    p[k].t[x].exi += n;
    printf("You made %d %s\n\n", n, p->t[x].name);
    if (x == 22) {
        p[k].t[17].exi += n;
    }
    system("pause");
    return true;
}

void attack(int k, int x) {
    int max_a = p[k].t[x].exi;
    max_a > 2 ? max_a = 2 : 0;
    printf("You can attack the other party up to %d %s.How huch %s do you want "
           "to attack?\n",
           max_a, p->t[x].name, p->t[x].name);
    int n;
    scanf("%d", &n);

    n = n > max_a ? max_a : n;
    p[k].t[x].exi -= n;
    int agg = n * p->t[x].agg;
    int e = p[!k].t[6].exi;
    while (p[!k].t[12].exi && agg >= 1) {
        if (agg == 1) {
            agg--;
            continue;
        }
        p[!k].t[12].exi--;
        agg -= 2;
    }
    p[!k].t[6].exi -= agg;
    printf("You let the other party lose %d drops of blood\n\n",
           e - p[!k].t[6].exi);
    system("pause");
}

void play() {
    bool q = true;
    while (true) {
        if (p[q].get_bv() <= 0) {
            p[q].print(" is over,");
            p[!q].print(" is win!\n\nThe game is over\n\n");
            system("pause");
            return;
        }
        print(q);
        // freopen("CON","r",stdin);
        char *str = new char;
        scanf("%s", str);
        if (str[strlen(str) - 1] == '.')
            str[strlen(str) - 1] = '\0';
        if (strcmp(str, "get") == 0) {
            int x = -1;
            char s;
            // if (str[strlen(str) - 1] == '.')
            //     x = 1, str[strlen(str) - 1] = '\0';
            int len = 0, top = 0;
            while ((s = getchar()) != '.') {
                // scanf("%c",&s);
                if (Isletter(s) || (Isnumber(s) && len >= 1)) {
                    str[len++] = s;
                }
            }
            str[len++] = '\0';
            for (int c = 1; c <= maxn; c++)
                if (strcmp(str, p->t[c].name) == 0 && p->t[c].cl != -1) {
                    x = c;
                    break;
                }
            if (addexi(q, x))
                q = !q;
            system("pause");
            continue;
        }

        if (strcmp(str, "draw") == 0) {
            draw(q);
            q = !q;
            system("pause");
            continue;
        }

        if (strcmp(str, "make") == 0) {
            int x = -1;
            scanf("%s", str);
            if (str[strlen(str) - 1] == '.')
                str[strlen(str) - 1] = '\0';
            for (int c = 1; c <= maxn; c++) {
                if (strcmp(str, p->t[c].name) == 0) {
                    x = c;
                    break;
                }
            }
            if (x == -1 || !p->t[x].fy_pro[0]) {
                printf("You can't make it.Please re-enter.\n\n");
                continue;
            }
            if (make(q, x))
                q = !q;

            continue;
        }

        if (strcmp(str, "attack") == 0) {
            scanf("%s", str);
            if (str[strlen(str) - 1] == '.')
                str[strlen(str) - 1] = '\0';
            if (strcmp(str, "with") == 0) {
                scanf("%s", str);
                if (str[strlen(str) - 1] == '.')
                    str[strlen(str) - 1] = '\0';
                for (int c = 1; c <= maxn; c++) {
                    if (strcmp(p->t[c].name, str) == 0) {
                        if (p[q].t[c].exi) {
                            if (p[q].t[c].agg) {
                                attack(q, c);
                                q = !q;
                                continue;
                            } else {
                                printf("It can't attack.Please re-enter.\n\n");
                                continue;
                            }
                        } else {
                            printf("You don't have it.Please re-enter.\n\n");
                            continue;
                        }
                        continue;
                    }
                }
                continue;
            }
        }

        printf("Your input is incorrect.Please re-enter.\n\n");
        system("pause");
    }
}

int main() {
    srand((unsigned)time(NULL));
    init();
    play();
    system("pause");

    return 0;
}
