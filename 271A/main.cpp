#include <iostream>
#include <string>
using namespace std;

bool has_distinct_digits(string y) {
    //y is guaranteed to be between 1000 and 9000(inclusive)
    for(int i=0; i < 4; i++) {
        for(int j=i+1; j < 4; j++) {
            if(y[i] == y[j])
                return false;
        }
    }
    return true;
}

void next_year(string& year) {
    year = to_string(stoi(year) + 1);
}

int main(int argc, char const *argv[])
{
    string year;
    cin >> year;
    next_year(year);
    while(!has_distinct_digits(year)) 
        next_year(year);
    cout << year << endl;
    return 0;
}
