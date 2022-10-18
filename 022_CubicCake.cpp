
/*
https://atcoder.jp/contests/typical90/tasks/typical90_v
022 - Cubic Cake（★2）
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

//最大公約数をとる
ll toru(ll a, ll b)
{
    ll res = 0;
    if(a < b)
    {
        ll tmp = a;
        a = b;
        b = tmp;
    }

    if(a % b == 0)
    {
        return b;
    }
    else 
    {
        res = toru(b, a % b);
    }

    return res;

}



int main()
{
    ll a, b, c;

    cin >> a >> b >> c;

    ll kobai = toru(a,b);
    
    kobai = toru(c, kobai);

    ll res = a/kobai + b/kobai + c/kobai -3;

    cout << res << endl;


    return 0;
}