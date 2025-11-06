#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> v;

    while (answer < enemy.size()) {

        //현재 라운드의 적의 수많은 병수를 감소 시킨다.
        n -= enemy[answer];

        //v에 해당 라운드의 병사수를 기록
        v.push(enemy[answer]);

        //라운드 증가
        answer++;

        //한 라운드가 끝난 뒤에 수비여부 판단
        if (n >= 0) continue;
        else if (n < 1 && k >= 1) {//죽었는데 무적권이 있는경우
            //막아낸 경우 중 적이 가장 많았던 라운드에 무적권을 쓰고 넘어감
            n += v.top();
            v.pop();
            k--;
        }
        //죽었는데 무적권 없는 경우, 마지막 round 출력
        else {
            return --answer;
        }
    }

    return answer;
}