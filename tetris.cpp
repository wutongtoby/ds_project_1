#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Data {
    char type[3];
    int column;
};
class game {
    private:
        int rows, cols;
        bool** table;
        bool alive; // alive or dead
    public:
        // the constructor
        game(int m, int n) : rows(m + 4), cols(n), status(1) {
            bool* temp = new bool[rows * cols];
            table = new bool*[rows];
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
        void newdata(Data); // to throw new data into the game
        void clear_horizontal(void); // to clear horizontal line on the table    
        bool check_alive(void); // if the top of the table has block, alive = 0
        bool still_alive(void) {
            return alive;
        }
        void show_table(void) {
            for (int i = 4; i < rows; i++) {
                for (int j = 0; j < cols; j++)
                    cout << table[i][j];
                cout << endl;
            }
        }
};

void game:: newdata(Data d) {
    // catorgorize the block 
    // let block fall step by step, checking if it is stucked
    // if stucked, call clear_horizontal(), then call check_alive()
    int block_height, block_weidth;
    bool block[4][4] = {0};

    if (strcmp(d.type, "T1") == 0) {
        block_height = 2;
        block_weidth = 3;
        block[0][0] = 1, block[0][1] = 1,block[0][2] = 1;
        block[1][1] = 1; 
    }
    else if (strcmp(d.type, "T2") == 0) {
        block_height = 3;
        block_weidth = 2;
        block[0][1] = 1;
        block[1][0] = 1, block[1][1] = 1;
        block[2][1] = 1;
    }
    else if (strcmp(d.type, "T3") == 0) {
        block_height = 2;
        block_weidth = 3;
        block[0][1] = 1;
        block[1][0] = 1, block[1][1] = 1, block[1][2] = 1;
    }
    else if (strcmp(d.type, "T4") == 0) {
        block_height = 3;
        block_weidth = 2;
        block[0][0] = 1;
        block[0][1] = 1, block[1][1] = 1;
        block[2][0] = 1;
    }
    else if (strcmp(d.type, "L1") == 0) {
        block_height = 3;
        block_weidth = 2;
        block[0][0] = 1;
        block[1][0] = 1;
        block[2][0] = 1, block[2][1] = 1; 
    }
    else if (strcmp(d.type, "L2") == 0) {
        block_height = 2;
        block_weidth = 3;
        block[0][0] = 1, block[0][1] = 1, block[0][2] = 1;
        block[1][0] = 1;
    }
    else if (strcmp(d.type, "L3") == 0) {
        block_height = 3;
        block_weidth = 2;
        block[0][0] = 1, block[0][1] = 1;
        block[1][1] = 1;
        block[2][1] = 1;
    }
    else if (strcmp(d.type, "L4") == 0) {
        block_height = 2;
        block_weidth = 3;
        block[0][2] = 1;
        block[1][0] = 1, block[1][1] = 1, block[1][2] = 1;
    }
    else if (strcmp(d.type, "J1") == 0) {
        block_height = 3;
        block_weidth = 2;
        block[0][1] = 1;
        block[1][1] = 1;
        block[2][0] = 1, block[2][1] = 1;
    }
    else if (strcmp(d.type, "J2") == 0) {
        block_height = 2;
        block_weidth = 3;
        block[0][0] = 1;
        block[1][0] = 1, block[1][1] = 1, block[1][2] = 1;
    }
    else if (strcmp(d.type, "J3") == 0) {
        block_height = 3;
        block_weidth = 2;
        block[0][0] = 1, block[0][1] = 1;
        block[1][0] = 1;
        block[2][0] = 1;
    }
    else if (strcmp(d.type, "J4") == 0) {
        block_height = 2;
        block_weidth = 3;
        block[0][0] = 1, block[0][1] = 1, block[0][2] = 1;
        block[1][2] = 1;
    }
    else if (strcmp(d.type, "I1") == 0) {
        block_height = 4;
        block_weidth = 1;
        block[0][0] = 1;
        block[1][0] = 1;
        block[2][0] = 1;
        block[3][0] = 1;
    }
    else if (strcmp(d.type, "I2") == 0) {
        block_height = 1;
        block_weidth = 4;
        block[0][0] = 1, block[0][1] = 1, block[0][2] = 1, block[0][3] = 1;
    }
    else if (strcmp(d.type, "O") == 0) {
        block_height = 2;
        block_weidth = 2;
        block[0][0] = 1, block[0][1] = 1;
        block[1][0] = 1, block[1][1] = 1;
    }
    else 
        throw "the type of block dosen't exist\n";
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
    game tetris(m, n); /*
    while (tetris.still_alive() && i < j) {
        tetris.newdata(data[i++]);
    }
    */
    tetris.show_table();
    return 0;    
}