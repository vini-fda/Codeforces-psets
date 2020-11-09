#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n; //groups of schoolchildren
    /* 
        a[0] -> number of groups with 1 child
        a[1] -> number of groups with 2 children
        a[2] -> number of groups with 3 children
        a[3] -> number of groups with 4 children
    */
    int groups[4] = {0, 0, 0, 0}; //hashtable for amount of groups with a given amount of children
    cin >> n;
    int k;
    for(int i=0; i < n; i++) {
        cin >> k;
        //increment #groups with k children
        groups[k-1]++;
    }
    //groups with 1 child are divided by 4(integer division)
    //groups with 4 children already fill a taxi
    int min_taxis = groups[0] / 4 + groups[3];
    groups[0] %= 4;
    //groups with 2 children can fit evenly in a taxi
    //but there may be a remainder
    min_taxis += groups[1] / 2;
    groups[1] %= 2;

    //use the remaining groups with 1 child with the one with 2 children
    if(groups[0] != 0 && groups[1] != 0) {
        if (groups[0] <= 2) 
            groups[0] = 0;
        else
            groups[0] = 1;
        groups[1]--;
        min_taxis++;
    }
    //if there is still a lonely child...
    if(groups[0] == 1) {
        //put them with the group with 3 children
        if(groups[2] != 0) {
            groups[0] = 0;
            groups[2]--;
        } //or put them (alone) in a taxi
        //either way, increase the count of taxis
        min_taxis++;
    } else if(groups[0] > 1) {
        min_taxis++;
    }
    //the remaining groups with 3 children can't be 
    //evenly distributed in the taxis
    min_taxis += groups[2];
        
    
    cout << min_taxis << endl;
    return 0;
}
