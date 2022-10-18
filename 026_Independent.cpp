
/*
https://atcoder.jp/contests/typical90/tasks/typical90_z
026 - Independent Set on a Tree（★4）
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

    int N;
    cin >> N;

    //頂点が隣り合わないようにN/2個とる
    //木構造なので閉路はない
    // iとs ,iとt がつながっているとき、 sとtはつながっていない

    // 0とつながっているものを探す
    //そいつらを囲む
    //そいつらとつながっているものを囲む
    //それをリストにいれる
    //リストにいれたのとつながっているもの(到達してない)を探す
    // 囲む



    return 0;
}