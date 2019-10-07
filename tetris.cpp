#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Data {
    char type[3];
    int column;
    bool block[4][4];
    int block_weidth;
    int block_height;

    void set_Data(void) {
        for (int i = 0; i < 16; i++)
            block[0][i] = 0;
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
            block[1][0] = 1, block[1][1] = 1;
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
        else if (strcmp(type, "S1") == 0) {
            block_height = 2;
            block_weidth = 3;
            block[0][1] = 1, block[0][2] = 1;
            block[1][0] = 1, block[1][1] = 1;
        }
        else if (strcmp(type, "S2") == 0) {
            block_height = 3;
            block_weidth = 2;
            block[0][0] = 1;
            block[1][0] = 1, block[1][1] = 1;
            block[2][1] = 1;
        }
        else if (strcmp(type, "Z1") == 0) {
            block_height = 2;
            block_weidth = 3;
            block[0][0] = 1, block[0][1] = 1;
            block[1][1] = 1,block[1][2] = 1;
        }
        else if (strcmp(type, "Z2") == 0) {
            block_height = 3;
            block_weidth = 2;
            block[0][1] = 1;
            block[1][0] = 1, block[1][1] = 1;
            block[2][0] = 1;
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
};
class game {
    private:
        int rows, cols;
        bool** table;
        bool alive; // alive or dead
    public:
        // the constructor, the rows are give 4 units longer
        game(int m, int n) : rows(m + 4), cols(n), alive(1) {
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
            delete [] table;
        }
        void newblock(Data); // to throw new block into the game
        void clear_horizontal(void); // to clear horizontal line on the table    
        void draw_table(Data, int); // draw some block on the table
        void check_alive(void); // if there are blocks on the top 4 rows of the table, set alive = 0
        bool still_alive(void) {return alive;}
        void show_table(void) {
            cout << "   ";
            for (int i = 0; i < cols; i++)
                cout<< i + 1 << ' ';
            cout << endl;
            for (int i = 4; i < rows; i++) {
                cout <<'#' << (i >= 10? i - 10: i)<< ' ';
                for (int j = 0; j < cols; j++)
                    cout << table[i][j] << ' ';
                cout << endl;
            }
        }
};

void game:: newblock(Data d) { 
    bool stuck = 0;
    int i;

    d.set_Data();

    /* check if the data set by the setData() is correct-----yes
    cout << d.block_height <<' '<<d.block_weidth<<endl;
    for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 4; k++)
            cout << d.block[j][k];
        cout <<endl;
    }
    */

    // i meas which rows the block have arrive
    for (i = 0; i <= rows - d.block_height && stuck == 0; i++) {
        // check each squares occupied by the blockS
        for (int j = 0; j < d.block_height; j++) {
            for (int k = 0; k < d.block_weidth; k++) {
                if (d.block[j][k] == 1 && table[i + j][d.column - 1 + k] == 1) 
                    stuck = 1;
            }
        }
    }
    if (stuck == 1)
        i -= 2;
    else if (i == rows - d.block_height + 1) 
        i--;
    if (stuck == 1)
        cout << endl << "stuck\n";
    cout <<"i is "<< i <<endl;
    //draw the block d on the table
    draw_table(d, i); 
    //clear the row that is full
    clear_horizontal();
    //check if it is still alive
    check_alive();
}

void game:: draw_table(Data d, int row) {
    for (int i = 0; i < d.block_height; i++)
        for (int j = 0; j < d.block_weidth; j++)
            if (d.block[i][j] == 1)
                table[row + i][d.column - 1 + j] = 1;
}

void game:: check_alive(void) {
    for (int i = 0; i < 4 && alive == 1; i++) 
        for (int j = 0; j < cols && alive == 1; j++) 
            if (table[i][j] == 1)
                alive = 0;
}

void game:: clear_horizontal(void) {
    int i, j, k, l;
    for (i = rows - 1; i > 3; i--) {
        for (j = 0; j < cols && table[i][j] == 1; j++);
        if (j == cols) { 
            for (k = i; k > 0; k--)
                for (l = 0; l < cols; l++)
                table[k][l] = table[k - 1][l];
            i++;
        }
    }
}
int main(void) {
    int m, n;
    int i = 0, j = 0, k = 1;
    struct Data data[1001]; 
    /*FILE *infile;
    FILE *outfile;

    infile = fopen("tetris", "r");
    if (infile == NULL)
        throw "the file is empty\n";
    fscanf(infile, "%d%d", &m, &n);
    */
    cin >> m >> n;

    while (1) {
        //fscanf(infile, "%s", data[j].type);
        cin >> data[j].type;
        if((strcmp(data[j].type, "End") == 0))
            break;
        //fscanf(infile, "%s", data[j].type);
        cin >> data[j].column;
        j++;
    }

    game tetris(m, n); 
    while (tetris.still_alive() && i < j) { // j means the total number of data 
        tetris.newblock(data[i++]);
        cout << i<<endl;
        tetris.show_table();
    }
    
    return 0;    
}