
/*
https://atcoder.jp/contests/typical90/tasks/typical90_u
021 - Come Back in One Piece（★5） 
*/

//N頂点M辺の有効グラフ
//頂点 x から頂点 y に向かうパス、頂点 y から頂点 x に向かうパスが、どちらも存在する

//キーワード
//強連結成分分解(SCC)
//有向グラフにおいて 「お互いに行き来できる ⟺ 同じグループ」を満たすように頂点をグループ分けすること

#include <bits/stdc++.h>
#include <atcoder/scc>
using namespace std;
using namespace atcoder;

int main() {
    int N, M;
    cin >> N >> M;
    
    // SCC を適用するためのグラフを構築する
    scc_graph G(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u;--v;
        G.add_edge(u, v);
    }
    
    // SCC
    auto sccs = G.scc();
    
    // 出力
    //cout << scc.size() << endl;
    //for (auto list : scc) {
    //    cout << list.size();
    //    for (auto v : list) cout << " " << v;
    //    cout << endl;
    //}
    
    long ans = 0;
    for(auto scc: sccs) {
        long size = scc.size();
        ans += size * (size - 1) / 2;
    }
    cout << ans << endl;
    
}