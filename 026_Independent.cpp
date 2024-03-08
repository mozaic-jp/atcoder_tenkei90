
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

int N;

vector<vector<int>> P;
int colors[104000];

void dfs(int point, int point_color, int mae)
{

    //cout << point <<",";
    //すでに探索済かをどう表すか

    for(int i = 0; i < int(P[point].size()); i++)
    {
        int target = P[point][i];
        if(mae == target)continue;
        
        colors[target] = (point_color + 1) % 2;
        dfs(target, colors[target], point);
    }
}

int main()
{

    cin >> N;

    //二部グラフらしい
    //二部グラフとは、グラフGの点をXのグループ、Yのグループの2つに分けたときに、
    //X同士の点、Y同士の点、それぞれに辺がないグラフのこと

    //頂点が隣り合わないようにN/2個とる
    //木構造なので閉路はない
    // iとs ,iとt がつながっているとき、 sとtはつながっていない

    // 0とつながっているものを探す
    //そいつらを囲む
    //そいつらとつながっているものを囲む
    //それをリストにいれる
    //リストにいれたのとつながっているもの(到達してない)を探す
    // 囲む

    //深さ優先探索しながら、隣り合った点に、自分とは別の色をつけていく

    P = vector(N, vector<int>(0));
    for(int i = 0; i < N - 1; i++)
    {
        int a,b;
        cin >> a >> b;
        --a;--b;
        P[a].push_back(b);
        P[b].push_back(a);
    }

    
    colors[0] = 1;
    dfs(0, colors[0], -1);

    int sum = 0;
    for(int i = 0; i < N; i++)
    {
        sum += colors[i];
    }

    int target = 0;
    if(N / 2 <= sum)
    {
        //1を数える
        target = 1;
    }

    int cnt = 0;
    for(int i = 0; i < N; i++)
    {
        if(cnt >= N/2)break;
        if(colors[i] == target)
        {
            cnt++;
            cout << i + 1 << " ";
        }
    }
    cout << endl;







    return 0;
}