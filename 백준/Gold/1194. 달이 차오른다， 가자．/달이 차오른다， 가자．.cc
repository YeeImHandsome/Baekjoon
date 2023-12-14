#include <cstdio>
#include <cctype>
#include <queue>
#include <tuple>

using namespace std;

char maze[50][50];
int visited[50][50][1<<6];
int N, M;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

bool safe(int y, int x) {
    return y>=0 && x>=0 && y<N && x<M;
}

int main() {
    scanf("%d %d", &N, &M);
    int sy, sx;
    for(int i=0; i<N; ++i) {
        getchar();
        for(int j=0; j<M; ++j) {
            maze[i][j] = getchar();
            if(maze[i][j] == '0') {
                sy = i;
                sx = j;
            }
        }
    }

    // count, y, x, key
    priority_queue<tuple<int,int,int,int>> pq;
    pq.push({0, sy, sx, 0});
    int answer = 1e9;

    while(!pq.empty()) {
        auto [cnt, y, x, k] = pq.top(); pq.pop();
        cnt = -cnt;
        
        if(maze[y][x] == '1') {
            answer = cnt;
            break;
        }

        for(int d=0; d<4; ++d) {
            int ny = y + dy[d];
            int nx = x + dx[d];

            if(!safe(ny, nx) || maze[ny][nx] == '#') continue;
            
            if(isupper(maze[ny][nx]) && !(k & (1 << (maze[ny][nx] - 'A')))) continue;

            int key = k;
            
            if(islower(maze[ny][nx])) {
                key |= 1 << (maze[ny][nx] - 'a');
            }

            if(!visited[ny][nx][key]) {
                visited[ny][nx][key] = 1;
                pq.push({-(cnt+1), ny, nx, key});
            }
        }
    }

    if(answer == 1e9) printf("-1");
    else printf("%d", answer);

    return 0;
}