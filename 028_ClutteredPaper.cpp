
/*
https://atcoder.jp/contests/typical90/tasks/typical90_ab
028 - Cluttered Paper（★4）
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


//それぞれの1マスに対して、何枚重なっているかを求められそう
//11と21が一致していても、線で一致なので面積にはならない
//各点の左上だけを持っているイメージでやらないとだめか

int main()
{

    int N;
    cin >> N;

    vector <vector <int>> xy(1001, vector<int>(1001, 0));
    
    //累積和　二次元imos

    for(int i = 0; i < N; i++)
    {
        int lx,ly,rx,ry;

        cin >> lx >> ly >> rx >> ry;
        xy[lx][ly] += 1;
        xy[lx][ry] -= 1;
        xy[rx][ly] -= 1;
        xy[rx][ry] += 1;
    }
    for(int x = 0; x <= 1000; x++)
    {
        for(int y = 1; y <= 1000; y++)
        {
            xy[x][y] += xy[x][y-1];
        }
    }

    for(int x = 1; x <= 1000; x++)
    {
        for(int y = 0; y <= 1000; y++)
        {
            xy[x][y] += xy[x-1][y];
        }
    }


    vector <int> res(1001, 0);

    for(int x = 0; x <= 1000; x++)
    {
        for(int y = 0; y <= 1000; y++)
        {
            //cout<< y << "," << x << ":" <<  yx[y][x] << endl;
            res[xy[x][y]] += 1; 
        }
    }    

    for(int i = 1; i <= N; i++)
    {
        cout << res[i] << endl;
    }

}

