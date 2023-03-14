#include <iostream>
#include <vector>
using namespace std;

// RECURSIVE

void print(vector<int>vec) {
    if(vec.size() == 0) {
        cout<<"{}"<<endl;
        return;
    }
    for(auto x: vec) {
        cout<<x<<"  ";
    }
    cout<<endl;
}


// main subroutine
void printSubsequences(vector<int>vec, vector<int>subsequence,int index) {
    if(index >= vec.size()){
        print(subsequence);
        return;
    }

    // not including curr value
    printSubsequences(vec,subsequence,index+1);
    // including curr value
    subsequence.push_back(vec[index]);
    printSubsequences(vec,subsequence,index+1);
}
// subroutine ends here


int main()
{
    vector<int> vec;
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);

    vector<int> empty;
    printSubsequences(vec,empty,0);

    return 0;
}