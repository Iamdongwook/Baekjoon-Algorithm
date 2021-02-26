#include<iostream>
#include<algorithm>
using namespace std;
 
int day[16];
int money[16];
int ret;
int N; 
 
 
void dfs(int today, int sum) {
 
    ret = max(ret, sum);
 
    //N+1이 되는날 퇴사를 한다.
    //함수 종료 
    if (today == N + 1) {
        return;
    }

    //두가지 경우가 있다.
    //이해가 안가서 한참 헤멨다.
    //N+1이 되는날 퇴사를 해야하기 때문에 N번째 날까지 일을하는것이 MAX이다.
    //따라서 조건식을 정할때 <= N + 1 뜻은 최대 N까지 일하는것을 의미한다. 
    if (today + day[today] <= N + 1) { // 일을 함
        dfs(today + day[today], sum + money[today]);
    }
 
    if (today + 1 <= N + 1) { // 일을 안하고, 다음 날로 감
        dfs(today + 1, sum);
    }
}
 
int main() {
  
    cin >> N;
  
    for(int i=1; i<=N; i++) {
      cin >> day[i] >> money[i];
    }

    dfs(1,0);

    cout << ret << endl;
    return 0;
}
