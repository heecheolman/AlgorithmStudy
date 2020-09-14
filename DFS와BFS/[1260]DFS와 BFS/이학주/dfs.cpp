#include<iostream>
#include<queue>
using namespace std;
 
#define MAX_VALUE 1001            //'N이 1~1000 이므로 1000번째 인덱스에 접근 -> 크기 1001까지 선언
int N, M, V;                    //노드 개수, 간선 개수, 시작할 노드 번호
int mat[MAX_VALUE][MAX_VALUE];    //인접행렬 배열 선언
int visit[MAX_VALUE];            //visit 배열 default 는 0으로. . . 
 
void dfs(int v) {
    
    cout << v << ' ' ;
    visit[v] = 1;            //방문한 노드를 visit 0에서 1로 변경
    for(int i=1; i<=N; i++) {
        if(visit[i] == 1 || mat[v][i] == 0)     
            continue;
        dfs(i);                //dfs에서 재귀를 사용
    }
}
 
void bfs(int v) {
    queue<int> q;            //bfs에서는 q를사용
    q.push(v);
    visit[v] = 0;            //방문한 노드를 visit 1에서 0으로 변경
    while(!q.empty()) {
        v = q.front();
        cout << q.front() << ' ';
        q.pop();
        for(int i=1; i<=N; i++) {
            if(visit[i] == 0 || mat[v][i] == 0) // 방문했는지, 연결되어있는지
                continue;
            q.push(i);
            visit[i] = 0;
        }
    }
}

int main() {
    int x, y;
    cin >> N >> M >> V;            //N은 노드개수, M은 간선의개수, V는 처음 위치의 기준이 되는 노드
    for(int i=0; i<M; i++) {    //간선의 개수만큼 서로 이어줄 x와 y노드를 입력받습니다.
        cin >> x >> y;            
        mat[x][y] = mat[y][x] = 1;    //인접행렬 표시
    }
    dfs(V);            
    cout << '\n';
    bfs(V);
    return 0;
}
