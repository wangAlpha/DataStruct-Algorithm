#include <algorithm>
#include <iostream>
#include <vector>
// ================= 代码实现开始 =================

/* 请在这里定义你需要的全局变量 */

// 给定一个n个点m条边的无向图，第i条边边权为i，求所有需要升级的边
// n：如题意
// m：如题意
// U：大小为m的数组，表示m条边的其中一个端点
// V：大小为m的数组，表示m条边的另一个端点
// 返回值：所有需要升级的边，从小到大排列；第一小问的答案自然即为返回值的size，所以你不必考虑如何返回size

const int N = 200001;
struct UnionSet {
    int f[N];

    void init(int n) {
        for (int i = 0; i <= n; ++i) {
            f[i] = i;
        }
    }
    int find(int x) {
        while (x != f[x]) {
            f[x] = f[f[x]];
            x = f[x];
        }
        return x;
    }

    bool merge(int x, int y) {
        int xID = find(x);
        int yID = find(y);

        if (xID == yID) {
            return false;
        }
        f[xID] = yID;
        return true;
    }
} us;

void getAnswer(int n, int m, std::vector<int> &U, std::vector<int> &V) {
    std::vector<int> ans;
    us.init(n);
    for (int i = m - 1; i >= 0; --i) {
        if (us.merge(U[i], V[i])) {
            ans.push_back(i + 1);
        }
    }
    printf("%d\n", int(ans.size()));
    for (int i = ans.size() - 1; i >= 0; --i) {
        printf("%d\n", ans[i]);
    }
}

// ================= 代码实现结束 =================

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<int> U, V;
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        U.push_back(u);
        V.push_back(v);
    }
    getAnswer(n, m, U, V);

    return 0;
}
