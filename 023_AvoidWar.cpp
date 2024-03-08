
/*
https://atcoder.jp/contests/typical90/tasks/typical90_w
023 - Avoid War（★7）
*/

//キングを縦横斜めに隣り合うように配置しないパターンを数え上げる
//左上から右下にかけて、キングを0個、キングを1個、キングを2個…のパターンを実際にやってみたらできる気はする。
// 軸を決めた場合に、何個配置できるかを考えたほうがいい？
// カエル算みたいた帰納法の問題か


//長さWの01文字列の中で、1が2つ連続しないものの個数は、fib(W)個。
//fib(1) → 1個 
//fib(2) → 1個
//fib(3) → fib(2) + fib(1) = 2個  000 100 010 001 101
//fib(4) → fib(3) + fib(2) = 3個
//fib(5) → fib(4) + fib(3) = 5個
//fib(6) → fib(5) + fib(4) = 8個

//解説読んでも最後のfibはわからん


#include <iostream>
#include <string>
#include <map>
using namespace std;

// Input
int H, W;
char c[25][25];         //初期状態 *とoが書かれている

// Map
int cnt[25];
bool used[25][25];
int nex0[25][1 << 18];
int nex1[25][1 << 18];
int state[25][1 << 18];
map<int, pair<int, bool>> Map[25]; //次見る状態の番号、状態の番号、通り数

// DP
int mod = 1000000007;
int dp[25][25][1 << 18];

// 1を配置できるか
bool hantei(int sx, int sy) {
	int dx[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
	int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

    //上下左右斜め
	for (int i = 0; i < 8; i++) {
		//移動位置をtx,ty
        int tx = sx + dx[i], ty = sy + dy[i];
		//移動できるか
        if (tx < 0 || ty < 0 || ty >= W) continue;
		
        //既に使用しているか
        if (used[tx][ty] == true) return false;
	}
	return true;
}


/*
pos:位置
dep:深さ
str:
*/
void dfs(int pos, int dep, int str) {
    //pos = (0~W-1)のとき、sx = 0 
    int sx = pos / W;
    //
    int sy = pos % W;

    if(dep == W + 1)
    {
        int idx = cnt[sy];
        bool flag = hantei(sx, sy);
        //state -> str  
        state[sy][idx] = str;
        
        Map[sy][str] = make_pair(idx, flag);
        cnt[sy] += 1;
        return;
    }


    dfs(pos + 1, dep + 1, str);

    //
    if(hantei(sx,sy) == true)
    {
        //dfsの間は、usedをtrueにしておく
        used[sx][sy] = true;
        dfs(pos +1, dep + 1, str + (1 << dep));
        used[sx][sy] = false;
    }




}


int main()
{
    cin >> H >> W;
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            cin >> c[i][j];
        }
    }

    for(int i = 0; i < W; i++)
    {
        dfs(i, 0, 0);
    }

    for(int i = 0; i < W; i++)
    {
        for(int j = 0; j < cnt[i]; j++)
        {
            int t = state[i][j];
            int t0 = (t >> 1);
            int t1 = (t >> 1) + (1 << W);
            
            nex0[i][j] = Map[(i+1) % W][t0].first;

            if(Map[i][t].second == true)
            {
                nex1[i][j] = Map[(i+1) % W][t1].first;
            }
            else
            {
                nex1[i][j] = -1;
            }
        }
    }

    dp[0][0][0] = 1;
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            int n1 = i, n2 = j+1;
            if(n2 == W)
            {
                n1 += 1; n2 = 0;
            }

            for(int k = 0; k < cnt[j]; k++)
            {
                if(dp[i][j][k] == 0)continue;
                dp[n1][n2][nex0[j][k]] += dp[i][j][k];
                dp[n1][n2][nex0[j][k]] %= mod;

                if(nex1[j][k] != -1 && c[i][j] == '.') 
                {
					dp[n1][n2][nex1[j][k]] += dp[i][j][k];
					dp[n1][n2][nex1[j][k]] %= mod;
                }
        }
    }

}



