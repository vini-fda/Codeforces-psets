#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    cin.ignore(16, '\n');
    string games;
    cin >> games;
    int anton = 0;
    int danik = 0;
    for(auto it = games.begin(); it != games.end(); it++) {
        switch(*it) {
            case 'A':
                ++anton; break;
            case 'D':
                ++danik; break;
            default:
                cout << "Error! Letter is neither A nor B" << endl;
        }
    }

    if(anton > danik)
        cout << "Anton" << endl;
    else if(anton == danik)
        cout << "Friendship" << endl;
    else
        cout << "Danik" << endl;
        

    return 0;
}
