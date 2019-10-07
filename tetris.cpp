#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Data {
    char type[3];
    int column;
    bool block[4][4] = {0};
    int block_weidth;
    int block_height;

    void set_Data(void) {
        if (strcmp(type, "T1") == 0) {
                block_height = 2;
                block_weidth = 3;
                block[0][0] = 1, block[0][1] = 1,block[0][2] = 1;
                block[1][1] = 1; 
            }
            else if (strcmp(type, "T2") == 0) {
                block_height = 3;
                block_weidth = 2;
                block[0][1] = 1;
                block[1][0] = 1, block[1][1] = 1;
                block[2][1] = 1;
            }
            else if (strcmp(type, "T3") == 0) {
                block_height = 2;
                block_weidth = 3;
                block[0][1] = 1;
                block[1][0] = 1, block[1][1] = 1, block[1][2] = 1;
            }
            else if (strcmp(type, "T4") == 0) {
                block_height = 3;
                block_weidth = 2;
                block[0][0] = 1;
                block[0][1] = 1, block[1][1] = 1;
                block[2][0] = 1;
            }
            else if (strcmp(type, "L1") == 0) {
                block_height = 3;
                block_weidth = 2;
                block[0][0] = 1;
                block[1][0] = 1;
                block[2][0] = 1, block[2][1] = 1; 
            }
            else if (strcmp(type, "L2") == 0) {
                block_height = 2;
                block_weidth = 3;
                block[0][0] = 1, block[0][1] = 1, block[0][2] = 1;
                block[1][0] = 1;
            }
            else if (strcmp(type, "L3") == 0) {
                block_height = 3;
                block_weidth = 2;
                block[0][0] = 1, block[0][1] = 1;
                block[1][1] = 1;
                block[2][1] = 1;
            }
            else if (strcmp(type, "L4") == 0) {
                block_height = 2;
                block_weidth = 3;
                block[0][2] = 1;
                block[1][0] = 1, block[1][1] = 1, block[1][2] = 1;
            }
            else if (strcmp(type, "J1") == 0) {
                block_height = 3;
                block_weidth = 2;
                block[0][1] = 1;
                block[1][1] = 1;
                block[2][0] = 1, block[2][1] = 1;
            }
            else if (strcmp(type, "J2") == 0) {
                block_height = 2;
                block_weidth = 3;
                block[0][0] = 1;
                block[1][0] = 1, block[1][1] = 1, block[1][2] = 1;
            }
            else if (strcmp(type, "J3") == 0) {
                block_height = 3;
                block_weidth = 2;
                block[0][0] = 1, block[0][1] = 1;
                block[1][0] = 1;
                block[2][0] = 1;
            }
            else if (strcmp(type, "J4") == 0) {
                block_height = 2;
                block_weidth = 3;
                block[0][0] = 1, block[0][1] = 1, block[0][2] = 1;
                block[1][2] = 1;
            }
            else if (strcmp(type, "I1") == 0) {
                block_height = 4;
                block_weidth = 1;
                block[0][0] = 1;
                block[1][0] = 1;
                block[2][0] = 1;
                block[3][0] = 1;
            }
            else if (strcmp(type, "I2") == 0) {
                block_height = 1;
                block_weidth = 4;
                block[0][0] = 1, block[0][1] = 1, block[0][2] = 1, block[0][3] = 1;
            }
            else if (strcmp(type, "O") == 0) {
                block_height = 2;
                block_weidth = 2;
                block[0][0] = 1, block[0][1] = 1;
                block[1][0] = 1, block[1][1] = 1;
            }
            else 
                throw "the type of block dosen't exist\n";
            }
    }
};
class game {
    private:
        int rows, cols;
        bool** table;
        bool alive; // alive or dead
    public:
        // the constructor, the rows are give 5 units longer
        game(int m, int n) : rows(m + 5), cols(n), alive(1) {
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
        void draw_table(Data, int); // draw some block on the table
        
        bool check_alive(void); // if the top of the table has block, set alive = 0
        bool still_alive(void) {
            return alive;
        }
        void show_table(void) {
            for (int i = 5; i < rows; i++) {
                for (int j = 0; j < cols; j++)
                    cout << table[i][j];
                cout << endl;
            }
        }
};

void game:: newdata(Data d) { 
    // let block fall step by step, checking if it is stucked
    // if stucked,call draw_table() , then call clear_horizontal(), then call check_alive()
    bool stuck = 0;

    // i meas which rows the block have arrived
    for (int i = 1; i <= m + 5 - d.block_height && stuck == 0; i++) {
        // check each square occupied by the blockS
        for (int j = 0; j < d.block_height; j++) {
            for (int k = 0; k < d.block_weidth; k++) {
                if (d.block[j][k] == 1 && table[i + j][d.column - 1 + k] == 1)
                    stuck = 1;
            }
        }
    }
    if (stuck == 1) // stuck at some place
        i--;
    draw_table(d, i); draw the block d on the diagram
    clear_horizontal();
    check_alive();
}

void game:: draw_table(Data d, int row) {
// i means which rows can the block fall
    for (int i = 0; i < d.block_height; i++) {
        for (int j = 0; j < d.block_weidth; j++) {
            if (block[i][j] == 1)
                table[row + i][d.column - 1 + j] = 1;
        }
    }
}

void game:: check_alive(void) {
    for (int i = 0; i < 5 && alive == 1; i++) 
        for (int j = 0; j < n && alive == 1; j++) 
            if (table[i][j] == 1)
                alive = 0;
}

void game:: clear_horizontal(void) {
    int i, j, k;
    bool full;
    for (k = 0; k < 4; k++) {
        for (j = 0; j < n && table[m + 5 - k][j] == 1; j++);
        if (j == n) { //means some row is full
            for (i = m + 4 - k; i > 4; i--)
                for (j = 0; j < n; j++)
                    table[i + 1][j] = table[i][j];
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
    while (tetris.still_alive() && i < j) { // j means the total number of data 
        tetris.newdata(data[i++]);
    }
    
    tetris.show_table();
    return 0;    
}