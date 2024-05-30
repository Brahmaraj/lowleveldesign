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
        int getHead(){
            return Head;
        }
        int getTail(){
            return Tail;
        }
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
        int getHead(){
            return Head;
        }
        int getTail(){
            return Tail;
        }
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
        string getName(){
            return Name;
        }
        int getScore(){
            return Score;
        }
        void setScore(int score){
            this->Score = score;
        }
};

class Board{
    private : 
        int Row;
        int Col;
        vector<vector<int> > MyBoard;
    public :
        Board(int row, int col){
            this->Row = row;
            this->Col = col;
            vector<vector<int> > myBoard(Row, vector<int>(Col, 0));
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

class EncounterSnake_Ladder{
    private:
        unordered_map<int, int> headToTail;
    public:
        EncounterSnake_Ladder(vector<Snake*> snakes, vector<Ladder*> ladders){
            for(int i=0;i<snakes.size();i++){
                headToTail[snakes[i]->getHead()] = snakes[i]->getTail();
            }
            for(int i=0;i<ladders.size();i++){
                headToTail[ladders[i]->getHead()] = snakes[i]->getTail();
            }
        }
        unordered_map<int, int> getHeadToTail(){
            return headToTail;
        }

};

class UpdateScore{
    private:
        unordered_map<Player, int> playerToScore;
    public:
        pair<bool, int> updateMyScore(Player* player, int score, EncounterSnake_Ladder* headToTail){
            int currScore = player->getScore() + score;
            int finalScore =  headToTail->getHeadToTail().find(currScore) != headToTail->getHeadToTail().end() ? headToTail->getHeadToTail()[currScore] : currScore;
            player->updateScore(finalScore);
            //cout<<"Player " + player->getName() + " moves to " + to_string(player->getScore())<<endl;
            return make_pair(reachedHome(player, finalScore), finalScore);
        }
        bool reachedHome(Player* player, int score){
            if(score >= 100)
                return true;
            return false;
        }
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
    Die* mydie = new Die(6);
    EncounterSnake_Ladder* snakeAndLaddersHead = new EncounterSnake_Ladder(snakes, ladders);
    unordered_map<int, int> headToTail = snakeAndLaddersHead->getHeadToTail();
    UpdateScore* scoreUpdater = new UpdateScore();
    do{
        for(int i=0;i<players.size();i++){
            int dieScore = mydie->RollDie();
            string playerName = players[i]->getName();
            int oldScore = players[i]->getScore();
            cout<<"Player " + playerName + " has rolled die to " + to_string(dieScore)<<endl;
            pair<bool, int> reachedAndScore =  scoreUpdater->updateMyScore(players[i], dieScore, snakeAndLaddersHead);
            int newScore = players[i]->getScore();
            cout<<"Player " + playerName + " Moved from " + to_string(oldScore) + " to " + to_string(newScore)<<endl;
            if(reachedAndScore.first)
                return 1;
        }
    } while (true);
    return 0;
};


