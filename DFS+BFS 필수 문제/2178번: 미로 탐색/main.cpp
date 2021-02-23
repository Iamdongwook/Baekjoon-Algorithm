#include<iostream>
#include<queue>

#define MAX 100

using namespace std;

int N,M;
int Map[MAX][MAX];
int visited[MAX][MAX];

int directX[] = {-1,1,0,0};
int directY[] = {0,0,-1,1};

void BFS(int y, int x, int s) {
  
  //큐 만들기 
  queue<pair<pair<int,int>,int>> q;
  
  //큐 push
  q.push(make_pair(make_pair(y,x),s));
  
  //방문 check
  visited[0][0] = 1;
  
  //큐가 빌때까지
  while(!q.empty()) {
    
    //큐 꺼내기 
    x = q.front().first.second;
    y = q.front().first.first;
    s = q.front().second;
    
    //큐 pop
    q.pop();

    //마지막 좌표 만났을때 원래는 (N,M)이지만
    //처음에 (0,0)부터 시작했으니까 -1
    if(x == M - 1 && y == N - 1) {
      cout << s << endl;
    }
    
    for(int i=0; i<4; i++) {
      
      int nextX = directX[i] + x;
      int nextY = directY[i] + y;
      
      //배열의 유효성 check 
      if(nextX<0 || nextY<0 || nextX>=M || nextY>N) {
        continue;
      }
      
      //다음 좌표가 1이고 방문하지 않았다면
      if(Map[nextY][nextX]&&!visited[nextY][nextX]) {
      
        //큐 push
        q.push(make_pair(make_pair(nextY,nextX), s + 1));
        
        //방문 check 
        visited[nextY][nextX] = 1;
      }
    }
  }
}

int main() {
  
  cin >> N >> M;
  
  for(int y=0; y<N; y++) {
    for(int x=0; x<M; x++) {
  
      //붙어서 입력받기
      scanf("%1d", &Map[y][x]);
    }
  }
  
  BFS(0,0,1);

 return 0;
}
