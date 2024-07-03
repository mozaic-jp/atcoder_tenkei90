
/*
https://atcoder.jp/contests/typical90/tasks/typical90_aa
027 - Sign Up Requests （★2）
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
    int N;
    cin >> N;

    map <string, bool> m;

    for(int i = 0; i < N; i++)
    {
        string name;
        cin >> name;

        decltype(m)::iterator it = m.find(name);
        if (it != m.end()) { // 見つかった
            continue;
        }
        else
        {
            m[name] = true;
            cout << i+1 << endl;
        }
    }
}


