
/*
https://atcoder.jp/contests/typical90/tasks/typical90_m
013 - Passing（★5）
*/


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

// 入力
long long N, M;
long long A[100009], B[100009], C[100009];

// グラフ・最短距離
long long dist[100009];
long long dist1[100009];
long long distN[100009];
vector<pair<int, long long>> G[100009];

void dijkstra(int stt) {

    //優先度つきキュー pair(移動コスト, 位置)
    priority_queue< pair<long long , int>, vector<pair<long long, int>>, greater<pair<long long, int>> > Q;
    
    //INFを設定(最小コスト)
    for(int i = 1; i <= N; i++)dist[i] = (1LL << 60);
    //開始位置のコストは0
    dist[stt] = 0;
    //開始位置の移動コストは0
    Q.push(make_pair(0, stt));

    while (!Q.empty()) {
        int pos = Q.top().second;
        Q.pop();
        //posから移動できる位置に対して
        for(int i = 0; i < G[pos].size(); i++)
        {
            int to = G[pos][i].first;
            long long cost = G[pos][i].second;
            // 開始位置からtoへの移動コスト > 開始位置からposへの移動コスト + posからtoへの移動コスト
            if(dist[to] > dist[pos] + cost)
            {
                dist[to] = dist[pos] + cost;
                Q.push(make_pair(dist[to], to));
            }
        }
    }
}


int main()
{

    //k=1,2,⋯,N それぞれについて、街 1 から街 k を経由して街 N まで移動するときにかかる時間の最小値を求める
    //1 → k の最小、 k → Nの最小を求めればいいっぽい

    cin >> N >> M;
    
    for(int i = 1; i <= M; ++i)
    {
        cin >> A[i] >> B[i] >> C[i];
        G[A[i]].push_back(make_pair(B[i], C[i]));
        G[B[i]].push_back(make_pair(A[i], C[i]));
    }

    // i = 1;
    dijkstra(1);
    for(int i = 1; i <= N; ++i)
    {
        dist1[i] = dist[i];
    }
    

    // i = N;
    dijkstra(N);
    for(int i = 1; i <= N; ++i)
    {
        distN[i] = dist[i];
    }

    for(int i = 1; i <= N; ++i)
    {
        long long res = dist1[i] + distN[i];
        cout << res << endl;
    }

    return 0;
}
