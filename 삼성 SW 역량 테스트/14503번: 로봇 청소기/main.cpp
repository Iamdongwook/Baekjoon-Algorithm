#include<iostream>
#define MAX 50

using namespace std;

int N,M;
int r,c,d;
int Map[MAX][MAX];
int clean=0;

int directX[] = {0,1,0,-1};
int directY[] = {-1,0,1,0};

int main() {

  cin >> N >> M;
  cin >> r >> c >> d;

  for(int y=0; y<N; y++) {
    for(int x=0; x<M; x++) {
      cin >> Map[y][x];
    }
  } 

  while(1) {

    if(Map[r][c]==0) {
      Map[r][c]=2;
      clean++;
    }

    int nextStep = 0;
    for(int i=0; i<4; i++) {
      d = (d + 3) % 4;
      int nextX = directX[d] + c;
      int nextY = directY[d] + r;

      if(Map[nextY][nextX]==0) {
        c = nextX;
        r = nextY;
        nextStep = 1;
        break;
      }
    }

    if(nextStep==1) {
        continue;
    }
    
    int backStep = (d + 2) % 4;
    c = directX[backStep] + c;
    r = directY[backStep] + r;

    if(Map[r][c]==1) {
      break;
    } 
  }

  cout << clean << endl;

  return 0;
}
