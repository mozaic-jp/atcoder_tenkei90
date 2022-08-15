/*
https://atcoder.jp/contests/typical90/tasks/typical90_a
001 - Yokan Party（★4） 

問題文
左右の長さが L [cm] のようかんがあります。 
N 個の切れ目が付けられており、左からi番目の切れ目は左から Ai[cm] の位置にあります。
あなたは N 個の切れ目のうち K 個を選び、ようかんを K+1 個のピースに分割したいです。
そこで、以下の値を スコア とします。
・K+1 個のピースのうち、最も短いものの長さ（cm 単位）
スコアが最大となるように分割する場合に得られるスコアを求めてください。

制約 
1 ≤ K ≤ N ≤ 100000
0 < A1​ < A2​ < ⋯ < AN​ < L ≤ 10^9
入力はすべて整数
*/

/* 
考察

二分探索でよさそう
スコアをXとして、スコアを下回らないように、分割したときの回数 Y が
K 以下なら、OK。K未満ならNGとする
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
    //入力
    int N, L, K;
    cin >> N >> L;
    cin >> K;
    vector <int> a(N+1);
    for(int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }
    a[N] = L;


    //解法
    int l = 0, r = L;
    int mid;
    while ( l+1 < r)
    {
        mid = (l + r) / 2;

        //midに
        int cnt = 0;
        int tmp_len = 0;
        int s = 0;

        //もともと全部離れていて、くっつけるイメージで行う
        for(int i = 0; i < N+1; ++i)
        {
            tmp_len = a[i] - s;
            //mid未満ならくっつける
            if(tmp_len < mid)
            {
                cnt++;
            }
            else 
            {
                //mid以上ならなにもしない
                s = a[i];
            }
        }

        //cnt回くっつけると、 塊は、N + 1 - cnt個になる
        if (N + 1 - cnt >= K + 1)l = mid;
        else r = mid; 
    }

    cout << l << endl;
    return 0;
}
