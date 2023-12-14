
#include <iostream>
using namespace std;
int N, M, L;
string route;
string board[301];
#define DEVIDENUM 1000000007
long long twoDimensionSum[301][301][50];

void preTwoDimension(int k) {
  for (int i = 1; i <= N; i++)
    for (int j = 2; j <= M; j++)
      twoDimensionSum[i][j][k] += (twoDimensionSum[i][j - 1][k] % DEVIDENUM);
  for (int i = 2; i <= N; i++)
    for (int j = 1; j <= M; j++)
      twoDimensionSum[i][j][k] += (twoDimensionSum[i - 1][j][k] % DEVIDENUM);
}

long long twoDimension(int a, int b, int c, int d, int k) {
  return (twoDimensionSum[c][d][k] - twoDimensionSum[a][d][k] -
          twoDimensionSum[c][b][k] + twoDimensionSum[a][b][k] +
          DEVIDENUM * 2) %
         DEVIDENUM;
}

// k번째 순서에 유니콘이 k-1의 유니콘(k-1일 때의 2차원 부분합 영역을 다 더한다.
// )과 연속해서 올 수 있는 경우의 수. 이 값이 새로운 2차원 값이 된다.

void unicorn(int i, int j, int k) {
  long long answer = 0;
  if (i - 2 > 0 && j - 2 > 0) {
    answer += twoDimension(0, 0, i - 2, j - 2, k - 1) -
              twoDimension(i - 3, j - 3, i - 2, j - 2, k - 1);
  }
  answer += DEVIDENUM * 2;
  answer %= DEVIDENUM;
  if (i - 2 > 0 && j + 2 < M + 1) {
    answer += (twoDimension(0, j + 1, i - 2, M, k - 1) -
               twoDimension(i - 3, j + 1, i - 2, j + 2, k - 1));
  }
  answer += DEVIDENUM * 2;
  answer %= DEVIDENUM;
  if (i + 2 < N + 1 && j - 2 > 0) {
    answer += (twoDimension(i + 1, 0, N, j - 2, k - 1) -
               twoDimension(i + 1, j - 3, i + 2, j - 2, k - 1));
  }
  answer += DEVIDENUM * 2;
  answer %= DEVIDENUM;
  if (i + 2 < N + 1 && j + 2 < M + 1) {
    answer += (twoDimension(i + 1, j + 1, N, M, k - 1) -
               twoDimension(i + 1, j + 1, i + 2, j + 2, k - 1));
  }
  answer += DEVIDENUM * 2;
  answer %= DEVIDENUM;
  twoDimensionSum[i][j][k] = answer;
}

int main() {
  fill(&twoDimensionSum[0][0][0], &twoDimensionSum[0][0][0] + 301 * 301 * 50,
       0);
  cin >> N >> M >> L >> route;
  for (int i = 1; i <= N; i++) {
    cin >> board[i];
    board[i] = '0' + board[i];
  }
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      if (board[i][j] == route[0])
        twoDimensionSum[i][j][0] = 1;
    }

  preTwoDimension(0);
  for (int k = 1; k < route.size(); k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        if (route[k] == board[i][j]) {
          unicorn(i, j, k);
        }
      }
    }
    preTwoDimension(k);
  }

  long long answer = twoDimensionSum[N][M][route.size() - 1];
  answer %= DEVIDENUM;
  cout << answer;
  return 0;
}