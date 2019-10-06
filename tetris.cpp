#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
    fstream input, output;
    char buffer[300];

    input.open("tetris.data", ios::in);
    output.open("tetris.final", ios::out);

    if (!input) {
        cout << "can't open the file\n";

    }
    else {
        input.read(buffer, sizeof(buffer));
    }
    cout << buffer<<endl;
    return 0;
    
}