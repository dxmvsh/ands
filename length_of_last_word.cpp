#include<iostream>
using namespace std;

int lengthOfLastWord(string s) {
    string lastWord = "";
    for(int i=s.size() - 1; i>=0; i--) {
        if (lastWord.empty()) {
            if (s[i] != ' ') {
                lastWord += s[i];
            }
        } else {
            if (s[i] == ' ') {
                break;
            } else {
                lastWord += s[i];
            }
        }
    }
    return lastWord.size();
}

int main() {
    cout<<lengthOfLastWord("luffy is still joyboy");
    return 0;
}
