//
//  main.cpp
//  excel_sheet_number
//
//  Created by Strong on 23.02.2023.
//

#include <iostream>
using namespace std;

int binPow(int base, int power) {
    if (power == 0)
        return 1;
    if (power % 2 == 1)
        return binPow (base, power-1) * base;
    else {
        int b = binPow (base, power/2);
        return b * b;
    }
}

string substr(string s, int n) {
    string result = "";
    for(int i=0; i<n; i++)
        result += s[i];
    return result;
}
    
int titleToNumber(string title) {
    int power = (int) title.size() - 1;
    if(power == 0)
        return title[power] - 'A' + 1;
    return (titleToNumber(substr(title, power)) * 26) + ((title[power] - 'A') + 1);
}

int main(int argc, const char * argv[]) {
    cout<<titleToNumber("AB")<<endl;
    return 0;
}
