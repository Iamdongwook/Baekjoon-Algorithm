#include <iostream>
#include <string>

using namespace std;

int N;

void solution()
{
    int i = 666;
    int series = 0;
    string target;

    while(1)
    {
        target = to_string(i);
        for(int i = 0; i < target.length(); i++)
            if(target[i] == '6' && target[i+1] == '6' && target[i+2] == '6')
            {
                series++
                break;
            }

        if(series == N) {
          cout << i;
          break;
        } else {
          i++;
        }   
    }
}
int main() {
    
    cin >> N;

    solution();
}
