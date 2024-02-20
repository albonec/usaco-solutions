#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    int num_cases;
    cin >> num_cases;

    for(int i = 0; i < num_cases; ++i) {
        string input_str;
        cin >> input_str;

        char last_char = input_str.back();

        if(last_char == '0') {
            cout << "E" << endl;
        } else {
            cout << "B" << endl;
        }
    }

    return 0;
}
