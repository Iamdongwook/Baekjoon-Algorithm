#include <iostream>

using namespace std;

int func(int n) {

  if(n==0) return 0;
  else if(n==1) return 1;
  else  return func(n-1) + func(n-2); 
  //n = 5일때, func(4) + func(3) == func(5)
  //n = 4일때, func(3) + func(2) == func(4)
  //n = 3일때, func(2) + func(1) == func(3)
  //n = 2일때, func(1) + func(0) == func(2)
  
}

int main() {
  
  int n;
  cin >> n;

  int ret = func(n);
  cout << ret;
}
