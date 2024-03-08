
/*
https://atcoder.jp/contests/typical90/tasks/typical90_y
025 - Digit Product Equation（★7）
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <complex>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>

#define ll long long
const ll MOD = 1000000007;
using namespace std;
ll ans;

//f(m)の取得
ll fm(string ms)
{
    ll res = 1;
    for(int i = 0; i < ms.size(); i++)
    {
        res *= (ll)(ms[i] - '0');
    }
    return res;
}

ll N, B;

//string s: 1から10^11 を昇順ソートしたもの 
//↓例 19の後に22が作られる。20、21は飛ばされる。
//1
//2
//..
//11
//...
//19
//22
//...
//29
//33
//...

//再起呼びだし
void dfs(int l, int temp, string s)
{
    if(l != 0)
    {
        // ここのtempが味噌。tempが5なら5~9で回すので
        for(int k = temp; k < 10; k++)
        {
            //intToCharの簡易版
            char ps = ('0' + k);
            //再起呼び出し　1桁目のやつはこの後はelseルート
            dfs(l - 1, k, s + ps);
        }
    }
    else
    {
        //作成した string s のf(m)を取得
        ll fs = fm(s);
        // m-f(m)= B を満たす mを探す
        // m = B + f(m)
        ll m = fs + B;
        if(m <= N)
        {
            //mがf(m)と同じ数字(s)で構成されているかを確認する。
            string ms = to_string(m);
            //昇順ソート
            sort(ms.begin(), ms.end());
            if(ms == s)
            {
                ans++;
            }
        }

    }
}

int main()
{

    cin >> N >> B;

    //mを探すのではなく、f(m)を探す問題

    //0がついてる奴は Bが0出ない限り当てはまらない
    //最大11個の1桁の整数を掛け算してでた値

    // N=255 B=15
    // 1 <= M <= N　の中で、
    // M - f(M) = B となる数値は何個あるか
    // M = 25のとき  25 - 10 = 15

    //数を昇順ソートしてもf(x)の値は変わらない
    //例　→ 427 を247　のf(x)と一致する

    for(int i = 1; i < 12; i++)
    {
        //1桁目から11桁目まで再起呼び出しする
        dfs(i, 0, "");
    }
    
    cout << ans << endl;

    return 0;
}