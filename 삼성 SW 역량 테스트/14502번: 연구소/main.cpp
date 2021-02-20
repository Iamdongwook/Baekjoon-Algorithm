//dfs+bfs
#include<iostream>
#include<algorithm>
#include<queue>

#define MAX 8
using namespace std;

int N,M;
int Map[MAX][MAX];
int maxSize = 0;

int directX[] = {-1,1,0,0};
int directY[] = {0,0,-1,1};

void virusSpread() {

    int virusMap[MAX][MAX];
                
    for(int y=0; y<N; y++) {
        for(int x=0; x<M; x++) {
            virusMap[y][x] = Map[y][x];
        }
    }
    
    //큐 만들기
    queue<pair<int,int>> q;
    
    for(int y=0; y<N; y++) {
        for(int x=0; x<M; x++) {
            if(virusMap[y][x]==2) {
                q.push(make_pair(y,x));
            }
        }
    }
    
    while(!q.empty()) {
        //큐 꺼내기
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        
        //방향 check 
        for(int i=0; i<4; i++) {
            int nextX = directX[i] + x;
            int nextY = directY[i] + y;
           
            //배열의 유효성 check 
            if(nextX < 0 || nextY < 0 || nextX >= M || nextY >= N) {
                continue;
            }
            
            if(!virusMap[nextY][nextX]) {
                q.push(make_pair(nextY,nextX));
                virusMap[nextY][nextX] = 2;
            }
        }
    }

    int size = 0;
    
    for(int y=0; y<N; y++) {
      for(int x=0; x<M; x++) {
        if(virusMap[y][x]==0) {
          size++;
        }
      }
    }

    maxSize = max(maxSize,size);
    
    /*
    if(maxSize<empty) {
      maxSize = size;
    }
    */
}

void makeWall(int cnt) {
    if(cnt==3) {
        virusSpread();
        return;
    }
    
    for(int y=0; y<N; y++) {
        for(int x=0; x<M; x++) {
            if(!Map[y][x]) {
                Map[y][x] = 1;
                makeWall(cnt+1);
                Map[y][x] = 0;
            } 
        }
    }
}

int main(void) {
    
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N >> M;
    
    for(int y=0; y<N; y++) {
        for(int x=0; x<M; x++) {
            cin >> Map[y][x];
        }
    }
    
    makeWall(0);
    
    cout << maxSize;
    
    return 0;
}

//dfs로만 풀기 
#include<iostream>
#include<algorithm>

#define MAX 8

using namespace std;

int N,M;
int maxSize=0;
int Map[MAX][MAX];
int virusMap[MAX][MAX];
int visited[MAX][MAX];

//좌 우 상 하 
int directX[] = {-1,1,0,0};
int directY[] = {0,0,-1,1};

void dfs(int y, int x) {

  //방문표시 
  visited[y][x] = 1;
  
  for(int i=0; i<4; i++) {
    int nextX = directX[i] + x;
    int nextY = directY[i] + y;

    if(nextX<0 || nextY<0 || nextX>=M || nextY>=N) {
      continue;
    }

    if(!visited[nextY][nextX]&&!virusMap[nextY][nextX]) {
      virusMap[nextY][nextX]=2;
      dfs(nextY, nextX);
    } 
  }
}

//방문표시 초기화 
void init() {
  for(int y=0; y<N; y++) {
    for(int x=0; x<M; x++) {
      visited[y][x]=0;
    }
  }
}

void makeWall(int cnt) {
  if(cnt==3) {
    //맵 복사하기 
    for(int y=0; y<N; y++) {
      for(int x=0; x<M; x++) {
        virusMap[y][x] = Map[y][x];
      }
    }

    for(int y=0; y<N; y++) {
      for(int x=0; x<M; x++) {
        if(virusMap[y][x]==2) {
          dfs(y,x);
        }
      }
    }

    //visited[][] 초기화 
    init();

    int size = 0;

    for(int y=0; y<N; y++) {
      for(int x=0; x<M; x++) {
        if(virusMap[y][x]==0) {
          size++;
        }
      }
    }

    //안정 영역 갱신 
    maxSize = max(maxSize,size);

    return;
  }
  for(int y=0; y<N; y++) {
    for(int x=0; x<M; x++) {
      if(!Map[y][x]) {
        Map[y][x]=1;
        makeWall(cnt+1);
        Map[y][x]=0;
      }
    }
  }
}

int main() {

  cin >> N >> M;

  for(int y=0; y<N; y++) {
    for(int x=0; x<M; x++) {
      cin >> Map[y][x];
    }
  }

  makeWall(0);

  cout << maxSize;

  return 0;
}
