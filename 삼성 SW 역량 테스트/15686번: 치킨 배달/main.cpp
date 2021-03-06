#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 50

using namespace std;

struct Position {
  int y;
  int x;
};

int Map[MAX][MAX];
int visited[13];
int N,M;
int ans = 9999;

vector<Position> chicken, house;

int dist() {

  int sum = 0;
    
  for(int i=0; i<house.size(); i++) {
    int r1 = house[i].y;
    int c1 = house[i].x;
    int distance = 9999;
    for(int j=0; j<chicken.size(); j++) {
      if(visited[j]) {
      int r2 = chicken[j].y;
      int c2 = chicken[j].x;
      int temp = abs(r1-r2) + abs(c1-c2);
      distance = min(distance,temp);
      }
    }
    sum += distance;
  }
  return sum;
}

void dfs(int idx, int cnt) {

  if(cnt == M) {
    ans = min(ans,dist());
    return;
  }
    
  for(int i=idx; i<chicken.size(); i++) {
    if(!visited[i]) {
      visited[i] = true;
      dfs(i+1, cnt+1);
      visited[i] = false;
    }
  }
}

int main() {

  cin >> N >> M;

  for(int y=0; y<N; y++) {
    for(int x=0; x<N; x++) {
      cin >> Map[y][x];
      if(Map[y][x]==1) {
        house.push_back({y,x});
      }
      if(Map[y][x]==2) {
        chicken.push_back({y,x});
      }
    }
  }

  dfs(0,0);
  cout << ans << endl;

  return 0;
}
