/*
https://atcoder.jp/contests/typical90/tasks/typical90_d
004 - Cross Sum（★2）


【問題文】
H 行 W 列のマス目があります。
上から i (1≤i≤H) 行目、左から j (1≤j≤W) 列目にあるマス (i,j) には、
整数 A が書かれています。 
すべてのマス (i,j) (1≤i≤H,1≤j≤W) について、以下の値を求めてください。

マス (i,j) と同じ行または同じ列にあるマス（自分自身を含む）に書かれている整数を
すべて合計した値

【制約】
2 ≤ H, W ≤ 2000
1 ≤ A[i],A[j] ≤ 99
入力は全て整数

【考察】
毎回全マスの和を求めるとTLEとなるため、
列ごとの和、行ごとの和を求める
最後に列と行どちらにも足されている自分を引く

*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#define ll long long
const ll MOD = 1000000007;
using namespace std;


int main()
{
    int H,W;
    cin >> H >> W;

    vector <ll> H_sum(H, 0);
    vector <ll> W_sum(W, 0);
    vector <vector <int>> a(H,vector<int>(W,0));
    ll res;
    for(int i = 0; i < H; ++i)
    {
        for(int j = 0; j < W; ++j)
        {
            cin >> a[i][j];
            H_sum[i] += a[i][j];
            W_sum[j] += a[i][j];
        }
    }

    for(int i = 0; i < H; ++i)
    {
        for(int j = 0; j < W; ++j)
        {
            res = H_sum[i] + W_sum[j] - a[i][j];
            cout << res << "    ";
        }
        cout << endl;
    }
}



