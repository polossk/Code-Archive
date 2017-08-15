#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 1000000100;

struct range {
    int x, y;
} prev[100010], cur[100010], blocked[100010];

inline bool comp1(range A, range B) {
    if (A.x == B.x)
        return A.y < B.y;
    return A.x < B.x;
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        blocked[i].x = xx; blocked[i].y = yy;
    }

    sort(blocked + 1, blocked + M + 1, comp1);
    int curCnt = 0, prevCnt = 1;
    prev[prevCnt].x = prev[prevCnt].y = 1;

    for (int i = 1; i <= M; ++i) {
        if (blocked[i].x != blocked[i - 1].x + 1) {
            prevCnt = 1;
            prev[1].y = N;
        }

        int j;
        for (j = i; j <= M && blocked[j].x == blocked[i].x; ++j); --j;
        curCnt = 0;
        int leftSegment = 1;
        for (int k = i; k <= j; ++k) {
            if (blocked[k].y - 1 >= leftSegment) {
                cur[++curCnt].x = leftSegment;
                cur[curCnt].y = blocked[k].y - 1;
            }
            leftSegment = blocked[k].y + 1;
        }
        if (leftSegment <= N) {
            cur[++curCnt].x = leftSegment;
            cur[curCnt].y = N;
        }

        for (int k = 1; k <= curCnt; ++k) {
            int st = 1, dr = prevCnt, ret = -1;
            while (st <= dr) {
                int med = (st + dr) / 2;
                if (prev[med].y >= cur[k].x) {
                    ret = prev[med].x;
                    dr = med - 1;
                } else
                    st = med + 1;
            }
            if (ret == -1 || ret > cur[k].y)
                cur[k].x = cur[k].y = INF;
            else
                cur[k].x = max(ret, cur[k].x);
        }

        prevCnt = 0;
        for (int k = 1; k <= curCnt; ++k)
            if (cur[k].x != INF && cur[k].y != INF)
                prev[++prevCnt] = cur[k];
        if (prevCnt == 0) {
            printf("-1");
            return 0;
        }
        i = j;
    }

    if (blocked[M].x != N) {
        prevCnt = 1;
        prev[1].y = N;
    }

    if (prev[prevCnt].y == N)
        printf("%d\n", 2 * N - 2);
    else
        printf("-1");
    return 0;
}