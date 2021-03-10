#include<iostream>
#define MAX 51

using namespace std;

int T;
int N,M,K;
int Map[MAX][MAX];

int directX[] = {-1,1,0,0};
int directY[] = {0,0,-1,1};

void dfs(int y, int x) {
    
    Map[y][x] = 0;
    
    for(int i=0; i<4; i++) {
        int nextX = directX[i] + x;
        int nextY = directY[i] + y;
        
        if(nextX<0 || nextY<0 || nextX>=M || nextY>=N) {
            continue;
        }
        
        if(Map[nextY][nextX]) {
            Map[nextY][nextX] = 0;
            dfs(nextY,nextX);
        }
    }
}

int main() {
    

    cin >> T;

    while(T--) {

      int count = 0;

      cin >> N >> M >> K;

      for(int j=0; j<K; j++) {
          int x;
          int y;
          cin >> y >> x;
          Map[y][x] = 1;
      }

      for(int y=0; y<N; y++) {
          for(int x=0; x<M; x++) {
              if(Map[y][x]) {
                  dfs(y,x);
                  count++;
              }    
          }
      }
      cout << count << endl;
    }

    /*    
    for(int i=0; i<T; i++) {
        int count = 0;
        cin >> N >> M >> K;
        for(int j=0; j<K; j++) {
            int x;
            int y;
            cin >> y >> x;
            Map[y][x] = 1;
        }
        for(int y=0; y<N; y++) {
            for(int x=0; x<M; x++) {
                if(Map[y][x]) {
                    dfs(y,x);
                    count++;
                }    
            }
        }
        cout << count << endl;
    }
    */
    
    return 0;
}
