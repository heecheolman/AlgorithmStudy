#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct Point
{
  int x;
  int y;
  int moveCount;
};

const int MAX = 100;
int N;
int M;
bool visited[MAX][MAX] = {
    false,
};
int map[MAX][MAX] = {
    0,
};

int escape(int x, int y)
{
  queue<Point> Queue;
  Point point;
  point.x = x;
  point.y = y;
  point.moveCount = 0;

  Queue.push(point);
  visited[point.x][point.y] = true;

  while (!Queue.empty())
  {
    Point current = Queue.front();
    Queue.pop();
    map[current.x][current.y] = current.moveCount;

    if (current.x == N - 1 && current.y == M - 1)
    {
      return current.moveCount;
    }

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
      int nextX = current.x + dx[i];
      int nextY = current.y + dy[i];
      if (
          0 <= nextX && nextX < N &&
          0 <= nextY && nextY < M &&
          !visited[nextX][nextY] &&
          map[nextX][nextY] == 1)
      {
        Point next;
        next.x = nextX;
        next.y = nextY;
        next.moveCount = current.moveCount + 1;
        visited[nextX][nextY] = true;
        Queue.push(next);
      }
    }
  }
  return 0;
}

int main()
{
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      scanf("%1d", &map[i][j]);
    }
  }

  int result = escape(0, 0);
  printf("%d", result + 1);

  return 0;
}