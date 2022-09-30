
/*
https://atcoder.jp/contests/typical90/tasks/typical90_k
011 - Gravy Jobs（★6)
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <complex>
#include <algorithm>
#define ll long long
const ll MOD = 1000000007;
using namespace std;


// 入力フォーマット
// 行数
// 締切日　かかる日数 報酬
// 入力例
// 1
// 12 3 69853 
// 12日目が締め切りで3日かかる。実施すると69853もらえる。

struct work
{
    int dead;
    int cost;
    int salary;
    
    // 最後のconstを忘れると"instantiated from here"というエラーが出てコンパイルできないので注意
    bool operator<( const work& right ) const {
        return dead == right.dead ? cost < right.cost : dead < right.dead;
    }
};

int main()
{
    //1≤N≤5000
    //順番付きのナップサック問題っぽい
    
    //dp[i] //i日目の時点での最高報酬
    //仕事はやったらおわりにしないといけない。→おわりにしたもののリストも必要?
    //各仕事に対しての状態はやるかやらないかのみ

    int N;
    cin >> N;
    vector <work> works(N);
    for(int i = 0; i < N; ++i)
    {
        cin >> works[i].dead >> works[i].cost >> works[i].salary;
    }
    //締切日の昇順ソート
    sort(works.begin(), works.end());


    //dp[i] //i日目の時点での最高報酬
    vector<vector<ll>> dp(N+1, vector<ll>(5001, 0));

    for(int i = 0; i < N; i++)
    {
        //締め切りの最大が5000なので、5000で考える
        for(int j = 0; j <= 5000; j++)
        {
            //仕事をやらない場合
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);

            //仕事をやる場合
            if(j + works[i].cost <= works[i].dead)
            {
                dp[i+1][j + works[i].cost] = max(dp[i+1][ + works[i].cost], dp[i][j] + works[i].salary);
            }
        }
    }

    ll res = 0;
    for(int i = 0; i <= 5000; i++)
    {
        res = max(res, dp[N][i]);
    }

    cout << res << endl;

    return 0;
}
