#include <string>
#include <vector>
#include <iostream>
using namespace std;

string convert(string m) {
    string result = "";

    for (int i = 0; i < m.size(); i++) {
        //다음이 #인 경우
        if (i + 1 < m.size() && m[i + 1] == '#') {
            switch (m[i]) {
            case 'A':
                result += 'a';
                break;
            case 'C':
                result += 'c';
                break;
            case 'D':
                result += 'd';
                break;
            case 'F':
                result += 'f';
                break;
            case 'G':
                result += 'g';
                break;
            default:
                break;
            }
            i++;
        }
        else {
            result += m[i];
        }
    }

    return result;
}

string solution(string m, vector<string> musicinfos) {

    string answer = "(None)";
    int max_running_time = 0, running_time = 0;

    m = convert(m);

    //"12:00,12:14,HELLO,CDEFGAB"
    for (auto music : musicinfos) {
        int start_h = stoi(music.substr(0, 2));
        int start_m = stoi(music.substr(3, 2));
        int end_h = stoi(music.substr(6, 2));
        int end_m = stoi(music.substr(9, 2));
        int running_time = (end_h * 60 + end_m) - (start_h * 60 + start_m);

        music = music.substr(12, music.size());
        string title = music.substr(0, music.find(','));
        string song = music.substr(music.find(',') + 1, music.size());

        song = convert(song);

        if (running_time < song.size()) {
            song = song.substr(0, running_time);
        }
        else {
            int i = 0;
            int len = song.size();
            while (song.size() < running_time) {
                song += song[i % len];
                i++;
            }
        }

        if (song.find(m) != string::npos) {
            if (running_time > max_running_time) {
                max_running_time = running_time;
                answer = title;
            }
        }
    }

    return answer;
}