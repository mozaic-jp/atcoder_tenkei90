/*
https://atcoder.jp/contests/typical90/tasks/typical90_c
003 - Longest Circular Road（★4）


【問題文】
N 個の都市があり、それぞれの都市に 1 から N までの番号が付けられています。 
また、N−1 本の道路があり、
i 本目 (1≤i≤N−1) の道路は都市 A[i]と都市 B[i]を双方向に結んでいます。 
どの都市の間も、いくつかの道路を通って移動可能なものとなっています。
さて、あなたは整数 u, v (1≤u<v≤N) を自由に選び、
都市 u と都市 v を双方向に結ぶ道路を 1 本だけ新設することができます。
そこで、以下で定められる値を スコア とします。

同じ道を 2 度通らずにある都市から同じ都市に戻ってくる経路における、
通った道の本数 （この値はただ 1 つに定まる）

スコアとして考えられる最大の値を出力してください。

【制約】
 3≤N≤100000
 1≤A[i]<B[i]≤N (1≤i≤N−1)
どの都市の間も、いくつかの道路を通って移動可能
与えられる入力は全て整数

【考察】
2回目最短経路を探す。

1回目にある地点(どこでもいいので、0とする)の最長経路(最短経路の最大値)を探索
2回目に最長経路の地点を始点として最長経路を探索
例えば下記のような経路なら、2と1を繋げば、最長経路+1が解答になる。
2-3-4-1

*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <queue>
#define ll long long
const ll MOD = 1000000007;
using namespace std;

int N;
int a[1 << 18];
int b[1 << 18];

//グラフ
const int INF = (1 << 29);
vector <int> G[1 << 18];
int dist[1 << 18];

//
void getdist(int start)
{
    //BFSで最短経路を計算
    for(int i = 1; i <= N; ++i)
    {
        dist[i] = INF;
    }

    queue<int> Q;
    Q.push(start);
    dist[start] = 0;

    while(!Q.empty())
    {
        int pos = Q.front();Q.pop();
        for(int to : G[pos])
        {
            if(dist[to] == INF)
            {
                dist[to] = dist[pos] + 1;   //toから1移動で移動できる範囲
                Q.push(to);
            }
        }
    }
}


int main()
{

    cin >> N;
    for(int i = 1; i <= N-1; i++)
    {
        cin >> a[i] >> b[i];
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    //2.
    //ある地点(適当な位置(今回は1)の最も長い最短距離を求める)
    getdist(1);
    int maxn1 = -1;
    int maxid1 = -1;
    for(int i = 1; i <= N; ++i)
    {
        //最大のdistを求める
        if(maxn1 < dist[i])
        {
            maxn1 = dist[i];
            maxid1= i;
        }
    }

    //3. maxid1からの最も長い最短距離を求める
    getdist(maxid1);
    int maxn2 = -1;
    for(int i = 1; i <= N; ++i)
    {
        //最大のdistを求める
        maxn2 = max(maxn2, dist[i]);
    }

    cout << maxn2 + 1 << endl;

    return 0;
}



