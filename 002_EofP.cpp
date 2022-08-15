/*
https://atcoder.jp/contests/typical90/tasks/typical90_b
002 - Encyclopedia of Parentheses（★3） 

【問題文】
長さ N の正しいカッコ列をすべて、辞書順に出力してください。
ただし、正しいカッコ列は次のように定義されています :

() は正しいカッコ列である
S が正しいカッコ列であるとき、文字列 ( +S+ ) は正しいカッコ列である
S,T が正しいカッコ列であるとき、文字列 S+T は正しいカッコ列である
それ以外の文字列はすべて、正しいカッコ列でない
例えば、

()()
(()())(())
()()()()()()()()
は正しいカッコ列ですが、

)(
)))()(((
((((a))))
は正しいカッコ列ではありません。

また、 ( の方が ) よりも辞書順で早いものとします。

【制約】
1≤N≤20
N は整数

【入力例】
4

【出力例】
(())
()()
*/

/*
【考察】
()は、2文字1組のため、
Nが奇数のときは、空を出力でいい。
辞書順では、( の方が ) よりも早いため、
(が N/2並んだ状態が最も最初になる
((()))
(()())
(())()
()(())
()()()

最も後ろなのは、
()()()


*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#define ll long long
const ll MOD = 1000000007;
using namespace std;

bool judge (string s)
{
    int depth = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == '(')depth++;
        if(s[i] == ')')depth--;
        //すべてのiについて左からi文字目までの時点で、'('の数が')'以上でないなら
        if(depth < 0)return false;
    }
    if(depth == 0)return true;
    return false;
}

int main()
{
    int N;
    cin >> N;
    //辞書順に出力
    for(int i = 0; i < (1 << N); ++i)
    {
        string candidate  = "";
        for(int j = N-1; j >= 0; j--)
        {
            if((i & (1 << j)) == 0)
            {
                candidate += "(";
            }else
            {
                candidate += ")";
            }
        }
        bool res = judge(candidate);
        if(res)cout << candidate << endl;
    }
    return  0;
}

