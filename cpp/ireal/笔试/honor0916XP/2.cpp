#include<iostream>
#include<vector>


using namespace std;

bool check(vector<vector<int>>& board, int x, int y, int num){
    for(int i = 0; i < 9; i++){
        if(board[x][i] == num) return false;
        if(board[i][y] == num) return false;
    }
    int startx = x / 3 * 3;
    int starty = y / 3 * 3;
    for(int i = startx; i < startx + 3; i++){
        for(int j = starty; j < starty + 3; j++){
            if(board[i][j] == num) return false;
        }
    }
    return true;
}

bool backtrack(vector<vector<int>>& board, int x, int y){
    if(y == 9){
        y = 0;
        x++;
    }
    if(x == 9) return true;
    if(board[x][y] != 0) return backtrack(board, x, y + 1);
    for(int i = 1; i <= 9; i++){
        if(check(board, x, y, i)){
            board[x][y] = i;
            if(backtrack(board, x, y + 1)) return true;
            board[x][y] = 0;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> board(9, vector<int>(9, 0));
    for(int i = 0; i < 9; i++){
        string s;
        cin >> s;
        for(int j = 0; j < 9; j++){
            board[i][j] = s[2*j + 1] - '0';
        }
    }
    backtrack(board, 0, 0);
    for(int i = 0; i < 9; i++){
        cout << "{";
        for(int j = 0; j < 9; j++){
            cout << board[i][j];
            if(j != 8) cout <<",";
        }
        cout << "}" << endl;
    }
}