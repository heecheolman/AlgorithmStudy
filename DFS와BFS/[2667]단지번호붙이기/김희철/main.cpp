#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Point
{
  int x;
  int y;
};

const int MAX = 25;
int N;
int map[MAX][MAX] = {
    0,
};
int dong[MAX * MAX] = {
    0,
};
int danji = 2;

void attachDanji(int x, int y)
{
  queue<Point> Queue;
  Point point;
  point.x = x;
  point.y = y;
  Queue.push(point);
  map[point.x][point.y] = danji;
  dong[danji]++;

  while (!Queue.empty())
  {
    Point current = Queue.front();
    Queue.pop();

    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};

    for (int i = 0; i < 4; i++)
    {
      int nextX = current.x + dx[i];
      int nextY = current.y + dy[i];

      if (
          0 <= nextX && nextX < N &&
          0 <= nextY && nextY < N &&
          map[nextX][nextY] == 1)
      {
        Point nextPoint;
        nextPoint.x = nextX;
        nextPoint.y = nextY;
        map[nextX][nextY] = danji;
        dong[danji]++;
        Queue.push(nextPoint);
      }
    }
  }
}

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      scanf("%1d", &map[i][j]);
    }
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (map[i][j] == 1)
      {
        attachDanji(i, j);
        danji++;
      }
    }
  }

  printf("%d\n", danji - 2);
  sort(dong, dong + (MAX * MAX));
  for (int i = 0; i < MAX * MAX; i++)
  {
    if (dong[i] > 0)
    {
      printf("%d\n", dong[i]);
    }
  }

  return 0;
}