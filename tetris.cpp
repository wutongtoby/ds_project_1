#include <iostream>
#include <string.h>
#include <fstream>
#include <time.h>

using namespace std;

fstream fout;

struct Data {
    char type[3];
    int column;
    bool block[4][4];
    int block_weidth;
    int block_height;

    void set_Data(void) {
        for (int i = 0; i < 4; i++)
            for(int j = 0 ; j < 4; j++)
                block[i][j] = 0;
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
        void show_table(void);
        void check_alive(void); // if there are blocks on the top 4 rows of the table, set alive = 0
        bool still_alive(void) {return alive;}
        
};

void game:: show_table(void) {
    cout << "   ";
    fout << "   ";
    for (int i = 0; i < cols; i++) {
        fout << i + 1 << ' ';
        cout << i + 1 << ' '; 
    }
    fout << endl;
    cout << endl;
    for (int i = 4; i < rows; i++) {
        fout << '#' << (i >= 10? i - 10: i) << ' ';
        cout << '#' << (i >= 10? i - 10: i) << ' ';
        for (int j = 0; j < cols; j++) {
            fout << table[i][j] << ' ';
            cout << table[i][j] << ' ';
        }
        fout << endl;
        cout << endl;
    }
}

void game:: newblock(Data d) { 
    bool stuck = 0;
    int i;

    d.set_Data();
    // i meas which rows the block have arrive
    for (i = 0; i <= rows - d.block_height && stuck == 0; i++) {
        // check each squares occupied by the blocks
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
    int i = 0, j = 0;
    struct Data data[1001]; // 100 block + end
    fstream fin;
    clock_t start_t, end_t;

    start_t = clock();
    fin.open("other.data", ios::in);
    fout.open("tetris.final", ios::out);
    fin >> m >> n;
    
    while (j != 1001) {
        fin >> data[j].type;
        if((strcmp(data[j].type, "End") == 0))
            break;
        fin >> data[j].column;
        j++;
    }
    
    if (j == 1001) {
        cout << "too many blocks!!!" << endl;
        return 1;
    }

    fin.close();

    game tetris(m, n); 

    while (tetris.still_alive() && i < j) { // j means the total number of data 
        tetris.newblock(data[i++]);
    }
    tetris.show_table();
    fout.close();
    end_t = clock();
    cout << "total run time of the program is " << (end_t - start_t) / CLOCKS_PER_SEC;
    cout << endl;
    cout << j <<endl;
    return 0;    
}