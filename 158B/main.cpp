#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n; //groups of schoolchildren
    cin >> n;

    //hashtable for amount of groups with a given amount of children
    map<uint8_t, uint32_t> groups;
    groups[1] = groups[2] = groups[3] = groups[4] = 0;


    int k;
    for(int i=0; i < n; i++) {
        cin >> k;
        //increment #groups with k children
        groups[k]++;
    }

    int min_taxis = 0;
    //4 children already fill a taxi
    min_taxis += groups[4];
    //2 groups of 2 children can fit evenly in a taxi
    min_taxis += groups[2] / 2;
    groups[2] %= 2;

    //---------------
    //Groups with 3 children may go with a lonely child
    //If there are no more lonely children, there will
    //be a vacant seat in the taxi
    for(uint32_t i = 0; i < groups[3]; i++) {
        if(groups[1] > 0)
            groups[1]--;
        min_taxis++;
    }
    //Lonely children can fit in a taxi
    min_taxis += groups[1] / 4;
    groups[1] %= 4;


    //If there is a couple of children
    if(groups[2] == 1) {
        //If there are 0, 1 or 2 lonely children
        //put them with the couple
        if(groups[1] <= 2)
            groups[1] = 0;
        else //if there are 3, take 2 and the other goes alone :(
            groups[1] = 1;
        min_taxis++;
    }
    //Add the (maybe) remaining child(ren) to a single taxi
    if(groups[1] > 0)
        min_taxis++;


    cout << min_taxis << endl;
    return 0;
}
