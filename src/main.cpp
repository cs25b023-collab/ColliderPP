#include "../include/simulation.h"
#include "../include/parser/storage.h"

using namespace std;

int main(){
    std::vector<Any> a = {1,2,4};
    std::vector<Any> b = {24,6};
    std::vector<Any> big = {a,b};
    
    int c = big[0][0];


    cout<<c<<'\n';

    

    return 0;
}