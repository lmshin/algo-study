#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
unordered_map<string, vector<int>> db;

void parse(string info) {
    int start = 0;
    int length = info.size();
    string head_info;
    int score;
    vector<string> tmp;

    for (int i = 0; i < length; i++) {
        if (info[i] == ' ') {
            //cout << info.substr(start,i-start) << "\n";
            tmp.push_back(info.substr(start, i - start));
            start = i + 1;
        }
    }

    //cout << info.substr(start, length - start) << "\n";
    score = stoi(info.substr(start, length - start));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    string key = "";
                    key += (i ? "-" : tmp[0]);
                    key += " ";
                    key += (j ? "-" : tmp[1]);
                    key += " ";
                    key += (k ? "-" : tmp[2]);
                    key += " ";
                    key += (l ? "-" : tmp[3]);
                    //cout << key << "\n";
                    db[key].push_back(score);
                }
            }
        }
    }

}



vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for (int i = 0; i < info.size(); i++) {
        parse(info[i]);
    }

    //����
    for (auto& val : db) {
        sort(val.second.begin(), val.second.end());
    }

    //���� ó��
    for (int i = 0; i < query.size(); i++) {
        string key;
        int point;
        //score ������ ���� key ���� ���Ѵ�.

        //and ����
        key = query[i];
        int t = 3;
        while (t--) {
            int index = key.find("and");
            key.erase(index, 4);
        }

        //and�� ������ key�� ������ �Ѵ�.
        for (int j = 0; j < key.size(); j++) {
            if ('1' <= key[j] && key[j] <= '9') {
                point = stoi(key.substr(j, key.size() - j));
                key.erase(j - 1, key.size() - j + 1);
                break;
            }
        }

        //���� key ����
        cout << "key : " << key << "\n";

        //point ���� ������ �ִ�.
        //cout << "point : " << point << "\n";

        //�̺�Ž�� ����
        int start = 0, end = db[key].size();

        while (start < end) {
            int mid = (start + end) / 2;
            if (db[key][mid] < point) start = mid + 1;
            else end = mid;
        }

        int cnt = db[key].size() - start;
        answer.push_back(cnt);
    }


    return answer;
}