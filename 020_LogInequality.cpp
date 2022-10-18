
/*
https://atcoder.jp/contests/typical90/tasks/typical90_t
020 - Log Inequality（★3）
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

int main()
{

    ll a,b,c;
    cin >> a >> b >> c;

    //log2 ​a < b * log2 ​c
    // b * log2 ​c = log2 c * 2^b
    string res;
    ll bc = 1;
    for(int i = 1; i <= b; i++)
    {
        bc *= c;
    } 

    if( a < bc)
    {
        res = "Yes";
    }
    else
    {
        res = "No";
    }
    cout << res << endl;
    //cout << a << endl;
    //cout << bc << endl;

    return 0;
}
