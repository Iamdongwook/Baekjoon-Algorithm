#include<iostream>

#define MAX 50

using namespace std;

struct PERSON {
    int x;
    int y;
    int s;
};

int N;
int check[MAX];
PERSON person[MAX];

void solution() {
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      if(person[i].x < person[j].x && person[i].y < person[j].y) {
        person[i].s++;
      }
    }
  }    
  for(int i=0; i<N; i++) {
    cout << person[i].s + 1 << " ";
  }
}

int main() {
    
 cin >> N; 
 
 // N = 5, i = 0 ~ 4
 for(int i=0; i<N; i++) {
     cin >> person[i].x >> person[i].y;        
 }

 solution();
    
 return 0;
}
