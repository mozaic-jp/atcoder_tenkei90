
/*
https://atcoder.jp/contests/typical90/tasks/typical90_ad
030 - K Factors（★5）
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
#include <string>

#define ll long long
const ll MOD = 1000000007;
using namespace std;



int main()
{

    int N, K;
    cin >> N >> K;
    
    vector <int> cnt(N, 0);
    // mod2か
    //素数を並べる
    //mod2か
    //mod3か
    //を繰り返す

    //2~N までの素因数の個数取得処理
    for(int i = 2; i <= N; i++)
    {
        if(cnt[i] >= 1)continue;

        //i=2の場合:j = 2,4,6,8,10
        //i=3の場合:j = 3,6,9,12
        for(int j = i; j <= N; j += i)
        {
            cnt[j] += 1;
        }
    }

    int res = 0;
    for(int i = 1; i <= N; i++)
    {
        if(cnt[i] >= K)res++;
    }

    cout << res << endl;

    return 0;

}

