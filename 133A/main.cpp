#include <iostream>
#include <string>

using namespace std;
/*     
    "H" prints "Hello, World!",
    "Q" prints the source code of the program itself,
    "9" prints the lyrics of "99 Bottles of Beer" song,
    "+" increments the value stored in the internal accumulator.

    Instructions "H" and "Q" are case-sensitive and must be uppercase. 
    The characters of the program which are not instructions are ignored.
*/

int main(int argc, char const *argv[])
{
    string source_code;
    cin >> source_code;
    for(auto c : source_code) {
        switch (c)
        {
        case 'H': case 'Q': case '9':
            cout << "YES" << endl;
            return 0;
        default:
            break;
        }
    }
    cout << "NO" << endl;
    return 0;
}
