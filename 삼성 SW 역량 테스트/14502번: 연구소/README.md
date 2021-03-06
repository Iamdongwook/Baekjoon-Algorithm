## 문제
인체에 치명적인 바이러스를 연구하던 연구소에서 바이러스가 유출되었다. 다행히 바이러스는 아직 퍼지지 않았고, 바이러스의 확산을 막기 위해서 연구소에 벽을 세우려고 한다.

연구소는 크기가 N×M인 직사각형으로 나타낼 수 있으며, 직사각형은 1×1 크기의 정사각형으로 나누어져 있다. 연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다. 

일부 칸은 바이러스가 존재하며, 이 바이러스는 상하좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있다. 새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.

예를 들어, 아래와 같이 연구소가 생긴 경우를 살펴보자.
<img width="1142" alt="스크린샷 2021-02-19 오후 1 52 20" src="https://user-images.githubusercontent.com/79130141/108459335-cedc6a80-72b9-11eb-84c1-bd3383a8dba2.png">
이때, 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 곳이다. 아무런 벽을 세우지 않는다면, 바이러스는 모든 빈 칸으로 퍼져나갈 수 있다.

2행 1열, 1행 2열, 4행 6열에 벽을 세운다면 지도의 모양은 아래와 같아지게 된다.
<img width="1141" alt="스크린샷 2021-02-19 오후 1 52 37" src="https://user-images.githubusercontent.com/79130141/108459342-d1d75b00-72b9-11eb-890b-91c59c2fbe53.png">
바이러스가 퍼진 뒤의 모습은 아래와 같아진다.
<img width="1140" alt="스크린샷 2021-02-19 오후 1 52 46" src="https://user-images.githubusercontent.com/79130141/108459349-d56ae200-72b9-11eb-9b56-6b6915a3b0b0.png">
벽을 3개 세운 뒤, 바이러스가 퍼질 수 없는 곳을 안전 영역이라고 한다. 위의 지도에서 안전 영역의 크기는 27이다.

연구소의 지도가 주어졌을 때 얻을 수 있는 안전 영역 크기의 최댓값을 구하는 프로그램을 작성하시오.

## 입력
첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 8)

둘째 줄부터 N개의 줄에 지도의 모양이 주어진다. 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치이다. 2의 개수는 2보다 크거나 같고, 10보다 작거나 같은 자연수이다.

빈 칸의 개수는 3개 이상이다.

## 출력
첫째 줄에 얻을 수 있는 안전 영역의 최대 크기를 출력한다.

<img width="1143" alt="스크린샷 2021-02-19 오후 1 56 30" src="https://user-images.githubusercontent.com/79130141/108459609-50cc9380-72ba-11eb-96ef-55a5fb81aa2c.png">

## 풀이
벽이 세워질 수 있는 모든 경우의 수를 생각해야하는 브루트 포스 문제이다. 순열 또는 조합을 활용하여 재귀함수인 백트래킹으로 모든 경우의 수를 구하면 된다. 


3개의 벽을 세웠다면 바이러스가 존재하는곳 부터 모든 빈칸으로 퍼져나가도록 BFS 또는 DFS를 이용하면 된다.


이후, 바이러스가 존재하지 않는 안전 영역의 크기를 구하면 된다. 

## 포인트
```c++
//좌 우 상 하
int directX[] = {-1,1,0,0};
int directY[] = {0,0,-1,1};

//BFS를 활용하였지만 DFS로도 풀어보기 
void BFS() {

  int virusMap[MAX][MAX];

  for(int y=0; y<N; y++) {
    for(int x=0; x<M; x++) {
      
      //바이러스가 퍼진다면 Map이 변화하기 때문에
      //바이러스가 퍼지기전 즉, 벽이 3개 세워진 Map을 복사해준다.
      virusMap[y][x] = Map[y][x];
    }
  }

  //큐 만들기 함수 이름 까먹지 말자
  queue<pair<int,int>> q;  

  for(int y=0; y<N; y++) {
    for(int x=0; x<M; x++) {
      if(virusMap[y][x]==2) {
      
        //push
        //함수 제발 까먹지 말자
        q.push(make_pair(y, x));
      }
    }
  }

  while(!q.empty()) {
    //큐 꺼내기 
    int x = q.front().second;
    int y = q.front().first;
    //pop해주는거 까먹지 말기 
    q.pop();

    //다음으로 이동할 네가지 방향 구해주기
    for(int i=0; i<4; i++) {
      int nextX = directX[i] + x;
      int nextY = directY[i] + y;

      //배열의 유효성 check
      if(nextX<0 || nextY<0 || nextX>=M || nextY>=N) {
        continue;
      }

      if(virusMap[nextY][nextX]==0) {
          q.push(make_pair(nextY,nextX));
          virusMap[nextY][nextX] = 2;
      }      
    }
  }

  int size=0;

  for(int y=0; y<N; y++) {
    for(int x=0; x<M; x++) {
      if(virusMap[y][x]==0) {
        size++;
      }
    }
  }
  
  //최대 안전영역을 갱신해준다.
  if(maxSize<size) {
    maxSize=size;
  }
}

//재귀함수를 이용하여 3개의 벽을 세워준다.
void solve(int cnt) {
  if(cnt==3) {
    BFS();
    
    //재귀함수 특성상 꼭 return 해주기  
    return;
  }
  for(int y=0; y<N; y++) {
    for(int x=0; x<M; x++) {
      if(Map[y][x]==0) {
        Map[y][x] = 1;
        
        //순열을 이용하였지만 조합으로도 풀어보기 
        solve(cnt+1);
        
        //백트래킹 특성
        Map[y][x]=0;
      }
    }
  } 
}
```
