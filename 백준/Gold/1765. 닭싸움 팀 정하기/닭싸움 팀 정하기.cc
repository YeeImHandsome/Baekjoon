#include<iostream>
#include<vector>
#include<queue>
 
#define endl "\n"
#define MAX 1000 + 1
using namespace std;
 
int N, M, Team_Num = 1;
int Already_In_Team[MAX];
vector<int> Enemy[MAX], Friend[MAX];
 
void Input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
 
        if (c == 'E')
        {
            Enemy[a].push_back(b);
            Enemy[b].push_back(a);
        }
        else
        {
            Friend[a].push_back(b);
            Friend[b].push_back(a);
        }
    }
}
 
void DFS(int Cur)
{
    Already_In_Team[Cur] = true;
    for (int i = 0; i < Friend[Cur].size(); i++)
    {
        int Next = Friend[Cur][i];
        if (Already_In_Team[Next] == false)
        {
            DFS(Next);
        }
    }
    for (int i = 0; i < Enemy[Cur].size(); i++)
    {
        int Next = Enemy[Cur][i];
        for (int j = 0; j < Enemy[Next].size(); j++)    // Enemy's Enemy is Friend with Cur ! 
        {
            int nNext = Enemy[Next][j];
            if (Already_In_Team[nNext] == false)
            {
                DFS(nNext);
            }
        }
    }
}
 
void Solution()
{
    int Answer = 0;
    for (int i = 1; i <= N; i++)
    {
        if (Already_In_Team[i] == false)
        {
            DFS(i);
            Answer++;
        }
    }
    cout << Answer << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
