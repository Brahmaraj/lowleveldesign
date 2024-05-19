#include<iostream>
#include<vector>

using namespace std;

class Snake{
    private:
        int Head;
        int Tail;
    public:
        Snake(int head, int tail){
            this->Head = head;
            this->Tail = tail;
        };
};

class Ladder{
    private:
        int Head;
        int Tail;
    public:
        Ladder(int head, int tail){
            this->Head = head;
            this->Tail = tail;
        };
};

class Player{
    private:
        string Name;
        int Score;
    public:
        Player(string name, int score = 0){
            this->Name = name;
            this->Score = score;
        };
};

class Board{
    private : 
        int Row;
        int Col;
        vector<vector<int>> MyBoard;
    public :
        Board(int row, int col){
            this->Row = row;
            this->Col = col;
            vector<vector<int>> myBoard(Row, vector<int>(Col, 0));
            MyBoard = myBoard;
        };

};

int main(){

};


