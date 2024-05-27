#include<iostream>
#include<vector>
#include<set>
#include <unordered_set>
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
        void updateScore(int score){
            this->Score = score;
        }
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

class Die{
    private:
        int Side;
    public:
        Die(int side){
            this->Side = side;
        }
        int RollDie(){
            return rand()%Side;
        }
};

class UpdateScore{
    void updateMyScore(Player player, int score){
        player.updateScore(score);
    }
};

class EncounterSnake_Ladder{
    
};

int main(){
    int row = 10, col = 10, noOfPlayer = 0, noOfSnakes = 0, noOfLadders = 0;
    cout<<"Enter No of Player, No Of Snakes, No of Ladders";
    cin>>noOfPlayer>>noOfSnakes>>noOfLadders;
    Board* board = new Board(row, col);
    vector<Player*> players;
    cout<<"Enter Player Names";
    for(int i=0;i<noOfPlayer;i++){
        string name;
        cin>>name;
        Player* player = new Player(name);
        players.push_back(player);
    }
    vector<Snake*> snakes;
    cout<<"Enter Snakes Position : first head and then tail";
    for(int i=0;i<noOfSnakes;i++){
        int head = 0, tail = 0;
        cin>>head>>tail;
        Snake* snake = new Snake(head, tail);
        snakes.push_back(snake);
    }
    unordered_set<int> headOfSnakes;
    unordered_set<int> tailOfSnakes;
    vector<Ladder*> ladders;
    cout<<"Enter Ladders Position : first head and then tail";
    for(int i=0;i<noOfLadders;i++){
        int head = 0, tail = 0;
        cin>>head>>tail;
        if(headOfSnakes.find(head) != headOfSnakes.end()){
            cout<<"cannot have same head as snake";
            i--;
            continue;
        }
        if(tailOfSnakes.find(tail) != tailOfSnakes.end()){
            cout<<"cannot have same tail as snake";
            i--;
            continue;
        }
        Ladder* ladder = new Ladder(head, tail);
        ladders.push_back(ladder);
    }
};


