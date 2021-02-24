#include<iostream>
#include<algorithm>

#define MAX 1000

using namespace std;


int main() {

  int n, arr[MAX];
    
  cin >> n;
 
  for(int i=0; i<n; i++) {
    cin >> arr[i];
  }
    
  sort(arr, arr+n);

  int sum = arr[0]; 

  for(int i=1; i<n; i++) {
    arr[i] = arr[i-1] + arr[i];
    sum += arr[i];    
  }

  cout << sum << endl;
    
 return 0;
}

