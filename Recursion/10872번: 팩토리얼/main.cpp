#include<iostream>

using namespace std;

int func(int N) {
    
    //base condition
    if(N==0) {
        return 1;
    } else {
        return N * func(N - 1); 
    }
}

int main() {
    
    int N;
    cin >> N;
    
    int ret = func(N);
    cout << ret;
    
}
