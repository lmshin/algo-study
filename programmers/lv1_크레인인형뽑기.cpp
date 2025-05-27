#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> basket;

    for (int i = 0; i < moves.size(); i++) {
        int col = moves[i] - 1;
        for (int j = 0; j < board.size(); j++) {
            if (board[j][col] != 0) {
                basket.push_back(board[j][col]);
                board[j][col] = 0;
                if (basket.size() > 1 && *(basket.end() - 1) == *(basket.end() - 2)) {
                    basket.pop_back();
                    basket.pop_back();
                    answer += 2;
                }
                break;
            }
        }
    }



    return answer;
}