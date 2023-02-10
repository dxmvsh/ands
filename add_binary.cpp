#include<iostream>
using namespace std;

string addBinary(string a, string b) {
    string result = "";
    int i=a.size() - 1, j = b.size() - 1;
    int extra = 0;
    while (i >= 0 && j >= 0) {
        if (a[i] == '1' && b[j] == '1') {
            if (extra == 1) {
                result = "1" + result;
            } else {
                result = "0" + result;
                extra = 1;
            }
        }
        if ((a[i] == '1' && b[j] == '0') || (a[i] == '0' && b[j] == '1')) {
            if (extra == 1) {
                result = "0" + result;
            } else {
                result = "1" + result;
            }
        }
        if (a[i] == '0' && b[j] == '0') {
            if (extra == 1) {
                result = "1" + result;
                extra = 0;
            } else {
                result = "0" + result;
            }
        }
        i--;
        j--;
    }
    if (i == -1 && j == -1) {
        if (extra) {
            return "1" + result;
        } else {
            return result;
        }
    }
    if(i == -1) {
        string remainder = b.substr(0, j + 1);
        if (!extra) {
            result = remainder + result;
        } else {
            result = addBinary("1", remainder) + result;
        }
    }
    if (j == -1) {
        string remainder = a.substr(0, i + 1);
        if (!extra) {
            result = remainder + result;
        } else {
            result = addBinary("1", remainder) + result;
        }
    }
    return result;
}

int main() {
    cout<<addBinary("11", "11");
    return 0;
}
