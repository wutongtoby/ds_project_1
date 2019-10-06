#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef struct Data {
    char type[3];
    int column;
};
class game {
    private:
        int rows, cols;
        bool** table;
        bool status; // alive or dead
    public:
        // the constructor
        game(int m, int n) : rows(m), cols(n), status(1) {
            int* temp = int[rows * cols]
            table = new int*[rows];
            for(int i = 0; i < rows; i++) {
                table[i] = temp + cols * i;
                for (int j = 0; j < cols; j++)
                    table[i][j] = 0;
            }
        }
        ~game(void) {
            delete [] table[0];
            delete table;
        }
        void newdata(Data d) {
            // will change the table to the newest form
        }
        bool still_alive(void) {
            return status;
        }
        void show_table {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++)
                    cout << table[i][j] << ' ';
            }
            
        }
}

int main(void) {
    int m, n;
    int i = 0, j = 0, k = 0;
    struct Data data[1001]; 

    cin >> m >> n;

    while (1) {
        cin >> data[j].type;
        if((strcmp(data[j].type, "End") == 0))
            break;
        cin >> data[j].column;
        j++;
    }
    game tetris(m, n);
    while (tetris.still_alive() && i < j) {
        tetris.newdata(data[i++]);
    }
    
    

    return 0;    
}