#include <set>
#include <iostream>
#include <tuple>

using namespace std;

tuple<set<int>> f(){return make_tuple(set<int>{1,2,3,4,5,6,7,8});}
int main(){
    for(auto&& n : get<0>(f())){
        cout << n << endl;
    }
}
