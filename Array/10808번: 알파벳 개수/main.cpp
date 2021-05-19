#include <iostream>

using namespace std;

//string baekjoon string 처음부터 끝까지 있는것들 확인

int main() {

/*
  int alphabet[26] = {}; //배열 초기화 0~25

  
  string s; //string에 마음대로 배열을 넣을수가 있구나 
  cin >> s;

  // 0 1 2 3 4 5 6 7 8 9 10 < 11
  for(int i=0; i<s.length(); i++) {

    alphabet[s[i] - 'a']=+1; 
    //'a' - 'a' = 0 이라는것을 이용
    //++을 해주는 이유는? 예를 들어 s[i]가 'b'일때  - 'a' = 1 인것을 알수 있다.
    //++을 해줘야 카운트가 들어가기 때문에 근데 =+도 상관없을듯 
  }

  for(int i=0; i<26; i++) {
    cout << alphabet[i] << ' ';
  }
*/
  for(int i = 'a'; i <= 'z'; i++) {
    cout << (char)i << ':' << i << '\n';
  }
}
