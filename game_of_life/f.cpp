#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;


//game board class//

class game_of_life
{
private:
    int board[90][90];
    string ruleset[256];
    vector<string> live_cells;
    void livecells_lister();
public:
    game_of_life();
    void print_game();
    void update_board();
    void board_set(int cord[81][3]);
    void rule_set(string rule);
    int get_element(int cord_x,int cord_y);
    ~game_of_life();
};
//board creation
game_of_life::game_of_life()
{
    for (int i = 0; i < 90; i++)
    {
        for (int j = 0; j < 90; j++)
        {
            board[i][j]=0;
        }
        
    }
    
}
//initial game setting 
void game_of_life::rule_set(string rules)
{
    int string_size;
    string string_="";
    int op1;
    int number_rules;
    string_size=rules.length();
    for (int i = 0; i < number_rules; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            op1=(j+(8*i));
            string_=string_+rules[op1];
        }
        ruleset[i]=string_;
        string_="";
    }
    
}

void game_of_life::board_set(int cord[81][3])
{
    int nova_cord_x;
    int nova_cord_y;
    int init_value;

    for (int i = 0; i < 81; i++)
    {
        nova_cord_x=cord[i][0]+45;
        nova_cord_y=cord[i][1]+45;
        init_value=cord[i][2];
        board[nova_cord_x][nova_cord_y]=init_value;
    }
    
}
//"game" "engine" 
void game_of_life::update_board()
{
    livecells_lister();
    
}
//utilities
void game_of_life::livecells_lister()
{
    string string__;
    int cord_x;
    int cord_y;
    for (int i = 0; i < 90; i++)
    {
        for (int j = 0; j < 90; j++)
        {
            int cord_x;
            int cord_y;
            if (board[i][j]!=0)
            {
                cord_x=i;
                cord_y=j;
                string__=to_string(cord_x);
                string__=string__+to_string(cord_y);
                live_cells.push_back(string__);
            }

        }
                
    }
    
}
int game_of_life::get_element(int cord_x,int cord_y)
{
    return (board[cord_x][cord_y]);
}
void game_of_life::print_game()
{
        for (int i = 0; i < 90; i++)
    {
        for (int j = 0; j < 90; j++)
        {
             cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
//class deletion
game_of_life::~game_of_life()
{
    
}


//"end of the game class"




//random function//
int generateRandomTwoDigitNumber() {
    random_device rd;   // Obtain a random number from hardware
    mt19937 eng(rd());  // Seed the generator
    uniform_int_distribution<> distr(0, 1000);  // Range for two-digit numbers

    return distr(eng);  // Generate a random two-digit number
}



//main 
int main()
{
    game_of_life board =game_of_life();
    while (true){
        board.update_board();
    }
}