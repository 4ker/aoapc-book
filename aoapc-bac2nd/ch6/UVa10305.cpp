// UVa10305 Ordering Tasks
// Rujia Liu
// 题意：输入 n 和 m，以及 m 个二元组 (i,j)，求 1~n 的一个排列使得对于每个 (i,j)，i 在 j 的前面
// 算法：拓扑排序。注意 m 可能等于 0
#include <cstdio>
#include <cstring>
const int maxn = 1000;
int n, m, G[maxn][maxn], c[maxn], topo[maxn], t;

bool dfs( int u ) {
    c[u] = -1;
    for( int v = 0; v < n; v++ ) {
        if( G[u][v] ) {
            if( c[v]<0 ) { return false; }
        } else {
            if( !c[v]  ) { dfs(v); }
        }
    }
    c[u] = 1; topo[--t] = u;
    return true;
}

bool toposort() {
    t = n;
    memset( c, 0, sizeof(c) );
    for( int u = 0; u < n; u++) {
        if( !c[u] && !dfs(u) ) {
            return false;
        }
    }
    return true;
}

int main() {
    while( scanf("%d%d", &n, &m) == 2 && n ) {
        memset( G, 0, sizeof(G) );
        for( int i = 0; i < m; i++ ) {
            int u, v;
            scanf( "%d%d", &u, &v );
            G[u-1][v-1] = 1;
        }
        if( toposort() ) {
            for( int i = 0; i < n-1; i++ ) {
                printf("%d ", topo[i]+1);
            }
            printf("%d\n", topo[n-1]+1);
        } else {
            printf("No\n"); // 题目没说无解输出什么，应该是保证有解吧
        }
    }
}
