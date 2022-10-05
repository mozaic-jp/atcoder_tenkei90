
/*
https://atcoder.jp/contests/typical90/tasks/typical90_p
016 - Minimum Coins（★3)
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <complex>
#include <queue>
#include <map>
#include <algorithm>
#define ll long long
const ll MOD = 1000000007;
using namespace std;

int main()
{
    ll A,B,C,N;
    cin >> N;
    cin >> A >> B >> C;
    ll res = MOD;
    for(ll a = 0; a <= 9999; a++)
    {
        for(ll b = 0; a + b <= 9999; b++)
        {
            ll money = a * A + b * B;
            ll zan = N - (a * A + b * B);
            if(zan >= 0 && zan % C == 0)
            {
                ll c = zan / C;
                if(a + b + c <= 9999)
                {
                    res = min(res, a + b + c);
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}