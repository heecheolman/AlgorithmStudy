#include <cstdio>
#include <queue>
using namespace std;

struct Tomato
{
  int x;
  int y;
  int z;
  int day;
};

const int MAX = 100;
const int dx[6] = {0, 0, -1, 1, 0, 0};
const int dy[6] = {1, -1, 0, 0, 0, 0};
const int dz[6] = {0, 0, 0, 0, -1, 1};

bool visited[MAX][MAX][MAX] = {
    false,
};
int map[MAX][MAX][MAX] = {
    0,
};
int M, N, H;
int day = 0;

queue<Tomato> Queue;

bool isAllRipe()
{
  for (int z = 0; z < H; z++)
  {
    for (int y = 0; y < N; y++)
    {
      for (int x = 0; x < M; x++)
      {
        if (!visited[z][y][x])
        {
          return false;
        }
      }
    }
  }
  return true;
}

void bfs()
{
  while (!Queue.empty())
  {
    Tomato current = Queue.front();
    Queue.pop();
    int nextX, nextY, nextZ;
    for (int i = 0; i < 6; i++)
    {
      nextX = current.x + dx[i];
      nextY = current.y + dy[i];
      nextZ = current.z + dz[i];

      if (
          0 <= nextX && nextX < M &&
          0 <= nextY && nextY < N &&
          0 <= nextZ && nextZ < H &&
          !visited[nextZ][nextY][nextX])
      {
        Tomato next;
        next.x = nextX;
        next.y = nextY;
        next.z = nextZ;
        next.day = current.day + 1;
        day = next.day;
        visited[nextZ][nextY][nextX] = true;
        Queue.push(next);
      }
    }
  }
}

int main()
{
  scanf("%d %d %d", &M, &N, &H);
  Tomato tomato;
  for (int z = 0; z < H; z++)
  {
    for (int y = 0; y < N; y++)
    {
      for (int x = 0; x < M; x++)
      {
        scanf("%d", &map[z][y][x]);
        int value = map[z][y][x];
        if (value == 1)
        {
          tomato.z = z;
          tomato.y = y;
          tomato.x = x;
          tomato.day = 0;
          visited[z][y][x] = true;
          Queue.push(tomato);
        }
        else if (value == -1)
        {
          visited[z][y][x] = true;
        }
      }
    }
  }

  bfs();

  isAllRipe() ? printf("%d", day) : printf("-1");

  return 0;
}