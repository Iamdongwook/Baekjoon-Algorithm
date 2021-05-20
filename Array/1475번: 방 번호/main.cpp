#include <iostream>

using namespace std;

//포인트는 6과 9를 뒤집어서 사용할수 있다. 

int main() {
  
  int check[10] = {};

  int num;
  cin >> num;

  while(true) {
    check[num%10]++; //이렇게 되면 뒷자리 부터 넣을수 있음 
    if(num/10 == 0) break; //base condition
    num = num/10; //몫을 넣어준다.  
  }

  int ret = 0;
  
  for(int i=0; i<10; i++) {
    //이 조건을 식으로 나타내는데 머리를 쓰지 못함
    if(i!=6 && i!=9) {
      ret = max(ret,check[i]);
    }
  }
  //코드를 참고하고 생각해보니 이런식을 만들 수 있구나 유연하게 생각하기 
  cout << max(ret, (check[6] + check[9] + 1) / 2);  
}
