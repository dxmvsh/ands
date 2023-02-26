//
//  main.cpp
//  contains_duplicate
//
//  Created by Dimash on 26.02.2023.
//

#include <iostream>
#include "vector"
#include "set"
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    set<int> numsSet;
    for(int num: nums) {
        int beforeInsertSize = (int) numsSet.size();
        numsSet.insert(num);
        if(beforeInsertSize == numsSet.size()) {
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    vector<int> v {1,1,1,3,3,4,3,2,4,2};
    cout<<containsDuplicate(v)<<endl;
    return 0;
}
