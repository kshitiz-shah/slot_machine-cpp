#include<iostream>
#include<string>
#include <sstream>
#include <limits> 
#include<random>
#include<map>
#include<vector>
#include<algorithm>
#include <chrono> // For std::chrono::system_clock
//slot_machine_using_c++.cpp

int MAX_LINES = 3;
int MAX_BET =100;
int MIN_BET =1;

int COL =3;
int ROW =3;

using namespace std;

map<char, int> symbol = {
        {'#', 9},
        {'@', 6},
        {'$', 6},
        {'&', 8}
    };

    map<char, int> multiplier = {
        {'#', 6},
        {'@', 4},
        {'$', 3},
        {'&', 2}
    };




 int slot_machine(int ROWS, int COLUMNS, map<char, int> symbols,int line, int &amounts) {

     // Seed the random number generator with the current time
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);

     // Store the slot machine grid
    std::vector<std::vector<char>> grid(ROWS, std::vector<char>(COLUMNS));

    // Print a random symbol for each position in the slot machine grid
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            // Create a uniform distribution over the range of symbols
            uniform_int_distribution<> dis(0, symbols.size() - 1);

            // Generate a random index
            int index = dis(gen);

            // Advance the iterator to the randomly chosen position
            auto it = symbols.begin();
            advance(it, index);

            // Print the random symbol
           cout << it->first << " | ";

          
              // Store the random symbol in the grid
            grid[i][j] = it->first;


        }
        cout << endl;


    }

    
    for(int i=0;i<line;i++){
       
        
        if(grid[i][0] == grid[i][1] && grid[i][0] ==  grid[i][2] ){
            amounts*=multiplier[grid[i][0]];
            return amounts;
          
        }
       
    }
    return 0;

}



int deposit(){
   int  deposit_amount; 
    
 while(true){

    cout<<"Enter the amount you want to deposit:"<<endl;
    cin>>deposit_amount;

    
    if( deposit_amount >0){
       cout<<"your deposit amount is :"<<deposit_amount<<endl;
        break;
    }
 
    else{
        cout<<"please input a proper amount."<<endl;
        cin.clear(); // Clear error state
       cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        
       /* By including cin.clear() and cin.ignore(), you're resetting the error state of cin and clearing any 
        invalid characters from the input buffer after a failed input operation. This allows the program to
         recover from the error and continue prompting the user for input.

         Therefore, removing these lines would result in the program getting stuck in an infinite loop, as it would be
          unable to recover from the failed input operation and would keep attempting to read the same invalid input.

         */
    } 
}
return deposit_amount;
}


int no_of_lines(){
     int line ;

    while(true){

   
    cout<<"Enter the number of lines between (1-"<<MAX_LINES<<"):";
    cin>>line;
    if(line >= 1 && line <= MAX_LINES){
        break;
    }
    else{
         cout<<"please input a proper number of lines."<<endl;
        cin.clear(); // Clear error state
       cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input

    }

    }
    return line;
}

int bet_amount(int lines){
    int bet_amount;
    while(true){
    cout<<"enter the amount you want to bet on  1 line :"<<endl;
    

    if(cin >> bet_amount ){
      if(bet_amount >= MIN_BET && bet_amount <= MAX_BET){
        cout<<"you are betting :$ "<<bet_amount<<endl;
        break;
    }
     else {
        cout<<"please select a amount between "<<MIN_BET<<" and "<<MAX_BET<<endl;
       }
    }
    else{
         cout<<"please selsect a proper amount."<<endl;
        cin.clear(); // Clear error state
       cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }  
     
    }
    return bet_amount;

}


 int balance =deposit();

int main(){


 int lines =no_of_lines();
 int amount,total_bet;

while(true){
     amount =bet_amount(lines);
  total_bet = lines *amount;

 if(total_bet>balance){
    cout<<"You don't have enough balance. Your current balance is "<<balance<<endl;
 }
 else{
    cout<<"You are betting a total of "<<total_bet<<"$ on "<<lines<<" lines."<<endl;
    break;

 }
 

}
 int slots = slot_machine(ROW, COL, symbol,lines, amount);
balance= balance -total_bet;

balance= balance + amount;

cout<<"You won :"<<amount<<endl;
cout<<"your current balance is "<<balance<<endl;

    //print_slot_machine(slots);

while(true){
    char ans;
    cout<<"DO YOU WANT TO PLAY AGAIN ??"<<endl;
    cout<<"PRESS Y TO  START AND Q TO QUIT."<<endl;
    cin>>ans;
    if(ans == 'Q' || ans == 'q' ){
        cout<<"YOU REMAINING BALANCE WILL BE :"<<balance;
        break;
       
    }
    else{
        main();
    }


}
    return 0;

 
}
