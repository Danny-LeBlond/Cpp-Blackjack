//Name:Danny LeBlond
//Date:jun 14, 2023
//class: CSC1060C00 Computer Science I
//program discribtion: blackjack
//diagram (in website open file ("activty diagram open in website.drawio"))https://app.diagrams.net/      
#include <chrono>//for pausing the program to read rules

#include <cstdlib>//helps make random numbers

#include <fstream>//used for file reading and wrighting to.

#include <iostream>//for inputs and outputs

#include <numeric>//used to find the sum of the cards

#include <string>// this helps take in the players name and helps with choice making

#include <thread>//this is also used to help stop the program when the player is trying to read the rules

#include <vector>// helps to hold and change and keep track of the cards 

using namespace std;// so i dont have to put in std:: everytime

//this is the rules 
int rule(){

    //makes a variable or name tag for the file i want to open (its called file)
    ifstream file("rules.txt");

    //makes sure the file opens 
    if (file.is_open()){

        //This is where the rules will be put into 
        string line;
        while(getline(file, line)){
            cout<< line<<endl;}}

     //this is to pause the program for 10 sec to let the player read the rules        
    this_thread::sleep_for(chrono::seconds(10));
    return 0;

    //closes the file
    file.close();}

//The real start of blackjack    
int main(){
    

    //places to put players name
    string player_name;

    //asks the player for name
    cout<<"\nWelcome to blackjack!!!\nType your name in for the game on the line below!"<<endl;

    //puts the name into player_name
    cin>>player_name;

    //takes the first letter in the players name and makes it upper case
    player_name[0]=toupper(player_name[0]);

    //seed for the random number generator 
    srand(time(0));

    //makes a line space
    cout<<"\n";

    //yes or no spot to see if they want the rules for the game
    string rules_question;
    cout<<"Would you like to see the rules type y for yes and n for no: \n";
    cin>> rules_question;

    //makes sure they answer with either y or n
    while (rules_question!= "y" && rules_question!= "n"){
        cout<<"that wasnt y or n try again";
        cin>>rules_question;}

    //if they want the rules this runs the rule fuction at the top     
    if (rules_question=="y"){
        rule();}

//give out a random amount of money for the player to start with (2000-10000)
    int money=2000+(rand()%8000);
    string keep_money="";
    cout<<"\n"<<player_name<<" you'll start out with $"<< money<<"\n"<<endl;

    //where the bet will be stored 
    int bet;

//cards and there sums
    vector<int>human_cards;
    vector<int>computer_cards;
    int hum_sum= accumulate(human_cards.begin(),human_cards.end(),0);
    int comp_sum= accumulate(computer_cards.begin(),computer_cards.end(),0); 


//when money is gone or they want to quit (goes all the way to the bottom)
   string bet_double_answer;
   while(money>=1 && keep_money!="q"){

    //asking how much they want to bet
        cout<< "\nHow much money would you like to bet (whole dollar amounts only)! you have $"<< money<<endl;
        cin>>bet;

        //if they try to bet more then they have
        while (bet>money){
            cout<<"Try that again please."<<endl;
            cin>>bet;}


// goes threw twice. its for getting the first two cards 
            int deal_count=2;
            while (deal_count!=0){
                
                //count down for two cards 
                deal_count= deal_count-1;

                //makes a % number 
                int card_for_human =  (rand() % 101);


                //ace are 8% of a deck 
                if (card_for_human<=8){

                    //if the ace will make there cards over 21 this will just add 1 instead of 11
                    if (hum_sum>10){
                        human_cards.push_back(1);}

                        //this adds an ace as 11
                    else{
                            human_cards.push_back(11);}}


                 //there are 31% kings,queen,jacks, and tens in a deck            
                else if(card_for_human<=38){
                    //adds a ten to the deck 
                    human_cards.push_back(10);}

                // the rest of the cards
                else{

                    //makes a random card from 2 to nine to add to the players hand
                    int up_to_nine = 2 + (rand() % 8);
                    human_cards.push_back(up_to_nine);}

                    //gets the sum of the players cards 
                hum_sum= accumulate(human_cards.begin(),human_cards.end(),0);

                //same way as the players cards are handed out but for the computer/dealer
                //% for card
                int card_for_computer=(rand()%101);

                //ace
                if(card_for_computer<=8){
                    if (comp_sum<11){
                        computer_cards.push_back(11);}
                    else{
                        computer_cards.push_back(1);}}
                //ten cards        
                else if (card_for_computer<=38){
                    computer_cards.push_back(10);}

                    //everything else (2 to 9 cards)
                else{
                    int computer_one_nine=2+(rand()%9);
                    computer_cards.push_back(computer_one_nine);}

                    //sum of computer cards
                comp_sum= accumulate(computer_cards.begin(),computer_cards.end(),0);} 

            // this just tell the player there first two cards and the dealers first card only
            //from here
            cout<<"\nDEALER'S first card is: "<<computer_cards[0]<<endl;
            cout<< player_name<<" your card/cards is/are :";
            for(int i=0;i < human_cards.size();i++){
                cout<< human_cards[i]<<" ";} cout<<"\n"; 
            cout<<player_name<<"'s sum: "<<hum_sum<<endl;
            //to here

            // the answer to if they want to double down
            int times_2_bet;

            // this is for hitting and staying
            string hit= "h";

            //you only want to ask the question of double down once 
            int one=1;

            //hit starts out as h so it will go threw unless changed
            while(hit== "h" ){
                int bet_double=1;
                while (bet_double!=0){
                    while (one==1){

                      //asking if they would like to double down 
                        cout<<"\nWould you like to double down (double your bet).\nYou can only double down once per hand and you will only get one more card.\nType y for double bet type n for no: ";

                        // where the answer goes for if they want to double down
                        cin>>bet_double_answer;
                        cout<<endl;

                        //checks to make sure they answer correctly
                         while(bet_double_answer!= "y" && bet_double_answer!="n" ){
                                cout<< " that wasnt y or n try again";
                                cin>>bet_double_answer;}

                        //if they want to double down and they dont have enough money for it
                        if (bet_double_answer=="y"&& bet*2>money){

                            //changes the answer so it only goes threw once
                            bet_double_answer="n";

                            //says they dont have the money to do the double down
                            cout<<"You dont got that kind of money were just gonna skip that double down."<<endl;}
                            
                            // makes one = o to break the loop 
                            one=one-1;}

                        //if they have the money for it and they want to double down 
                        if(bet_double_answer== "y" ){

                            //stops the loop 
                            bet_double=0;

                            //makes the bet times 2
                            bet=bet*2;

                            //stops the loop for asking to hit
                            times_2_bet=0;

                            //makes it go to n two lines down no matter what
                            bet_double_answer="n";

                            hit="h";}

                        //if they dont double down they will get asked if they would like to hit or stay
                        if  (bet_double_answer=="n"){
                            if (times_2_bet!=0 && hum_sum<22 && bet<= money){
                                bet_double=1;
                                cout<<"Would you like to hit?\nType h for hit and s for stay"<<endl;
                                cin>>hit;

                                //checks to make sure they answer correctly
                                while (hit!="h" && hit!= "s" ){
                                    cout<<"that wasnt h or s try again.: ";
                                    cin>>hit;}}


                                    //if they hit=="h" this will grab a card for only the player
                            if (hit=="h"){

                                //makes a random %
                                int card_for_human =  (rand() % 101);

                                // for aces 
                                if (card_for_human<=7){

                                    // 11+11 would be 22 so if cards are above ten it will give u a 1 valued ace
                                    if (hum_sum>10){
                                        human_cards.push_back(1);}

                                        //11 valued ace
                                    else{
                                        human_cards.push_back(11);}}

                                    //the ten cards
                                else if(card_for_human<=33){//human tens
                                    human_cards.push_back(10);}

                                //any other card
                                else{
                                    int up_to_nine=2+(rand()%9);
                                    human_cards.push_back(up_to_nine);}

                                    //gets the sum of the players cards
                                hum_sum= accumulate(human_cards.begin(),human_cards.end(),0);

                                //checks to make sure the players cards arent above 21 because of an ace.
                                //if they are it will change it to a 1  
                                if (hum_sum>21){
                                    for(int i=0;i < human_cards.size();i++){
                                    if (human_cards[i]==11){
                                        human_cards[i]=1;
                                        hum_sum= accumulate(human_cards.begin(),human_cards.end(),0);}}}

                                //if its not because of an ace the player just looses this hand         
                                if (hum_sum>21){
                                    cout<<endl<<"That's over 21 you loose.";

                                    //takes the bet amount away from the players overall money
                                    money=money-bet;

                                    //tells the player how much money they have left
                                    cout<<"You now have $"<<money<<endl;
                                    hit="s";}

                                    //gets the sum of the computer and the players cards
                                hum_sum= accumulate(human_cards.begin(),human_cards.end(),0);
                                comp_sum= accumulate(computer_cards.begin(),computer_cards.end(),0);

                                //shows the cards of the players card
                                for(int i=0;i < human_cards.size();i++){
                                    cout<< human_cards[i]<<" ";} cout<<"\n"; 

                                    //tells the sum of the players cards
                                cout<<player_name<<"'s sum: "<<hum_sum<<endl;
                                cout<<endl;

                                // if they made a double bet this will make it so they only get one card
                                if (times_2_bet==0){
                                    hit="s";}}

                            // for when they stay
                            if(hit=="s"){

                                //for to get the computer to stop grabbing cards
                                string comp_dealing_call;

                                //for the computer to get more cards and as long as the computer and player not over 22
                                while (comp_dealing_call !="stop" && hum_sum<22 &&comp_sum<21){

                                    //in normal casinos dealers  always hit up to 17
                                    if(comp_sum<=16){

                                        //makes a random % 
                                        int card_for_computer=(rand()%101);

                                        // ace cards
                                        if(card_for_computer<=7){

                                            // if its an ace and the computers sum is above 10 it will make the ace a 1
                                            if (comp_sum>10){
                                                computer_cards.push_back(1);}

                                                //makes the ace a 11 
                                            else{
                                                computer_cards.push_back(11);}}

                                                // the ten cards
                                        else if (card_for_computer<=33){
                                            computer_cards.push_back(10);}

                                            //all the other cards (2 to 9)
                                        else {
                                            int computer_one_nine=2+(rand()%9);
                                            computer_cards.push_back(computer_one_nine);}}

                                     // checks to make sure the computer isnt over 21 because of an ace and if it is changes it to a 1       
                                    else if (comp_sum>21){
                                        for(int i=0;i < computer_cards.size();i++){
                                        if (computer_cards[i]==11){
                                            computer_cards[i]=1;
                                            comp_sum= accumulate(computer_cards.begin(),computer_cards.end(),0);}}}


                                     // stops the dealer from grabbing cards when its above 16       
                                    else{
                                        comp_dealing_call="stop";}

                                    //gets the final sum of both dealer and players cards to compair them 
                                    comp_sum= accumulate(computer_cards.begin(),computer_cards.end(),0);}
                                    hum_sum= accumulate(human_cards.begin(),human_cards.end(),0);

                                    // if the human wins
                                if (hum_sum > comp_sum && hum_sum<=21){
                                    cout<<"\nThe sum of "<<player_name<<"'s cards are "<<hum_sum<<endl;
                                    cout<<"All of "<<player_name<<"'s cards are :";
                                    //shows the cards of the player
                                    for(int i=0;i < human_cards.size();i++){
                                        cout<< human_cards[i]<<" ";} cout<<endl;  
                                    
                                    
                                    cout<<"The sum of the computer cards were "<<comp_sum<<endl;
                                    cout<<"The computer cards were: ";
                                    //shows the cards of the dealer
                                    for(int i=0;i < computer_cards.size();i++){
                                        cout<< computer_cards[i]<<" ";}cout<<endl;

                                        //adds the money won to players "money"
                                    money=money+bet;
                                    cout<<player_name<<" won this hand\nyou win :$ "<<bet<<endl;}



                                    // the dealer won the hand 
                            else if (comp_sum > hum_sum && comp_sum <=21){ 
                                cout<<"\n"<<player_name<<", you lost this hand"<<endl;
                                money=money-bet;
                                cout<<"The sum of "<<player_name<<"'s cards are "<<hum_sum<<endl;
                                cout<<"The sum of the computer cards were "<<comp_sum<<endl;
                                cout<<"The computer cards were: ";

                                //shows the dealers cards you will already know yours 
                                for(int i=0;i < computer_cards.size();i++){
                                    cout<< computer_cards[i]<<" ";}cout<<endl;
                                cout<<player_name<<" lost this hand.\nYou loose :$ "<<bet<<endl;}

                                //if the player and dealer tie
                            else if(comp_sum==hum_sum){
                                cout<<"\nIt was a tie!!!";
                                cout<<"The sum of "<<player_name<<"'s cards are "<<hum_sum<<endl;
                                cout<<"The sum of the computer cards were "<<comp_sum<<endl;
                                cout<<"The computer cards were: ";
                                //shows the dealers cards 
                                for(int i=0;i < computer_cards.size();i++){
                                    cout<< computer_cards[i]<<" ";}cout<<endl;
                                cout<<player_name<< " now has $"<<money<<endl;}

                                // if the dealer goes over 21 the player will win
                            else if(comp_sum>21 && hum_sum<=21){
                                cout<<"\nThe sum of "<<player_name<<"'s cards are "<<hum_sum<<endl;
                                cout<<"All of "<<player_name<<"'s cards are :";

                                //shows the players cards
                                for(int i=0;i < human_cards.size();i++){
                                    cout<< human_cards[i]<<" ";} cout<<endl;  
                                cout<<"The sum of the computer cards were "<<comp_sum<<endl;
                                cout<<"The computer cards were: ";

                                //shows the dealers cards
                                for(int i=0;i < computer_cards.size();i++){
                                    cout<< computer_cards[i]<<" ";}cout<<endl;
                                money=money+bet;
                                cout<<player_name<<" won this hand\nYou win :$ "<<bet<<endl;}
                            hit="";
                    
                        bet_double=0;}}}
                hit="stop"; }


                //asking if they would like to leave with the money that they have left or if they would like to play again
            cout<<"\nIf you would like to walk out with $"<<money<<" press q (q is for quitters)\nIf you would like to keep playing type n (n is for winners) ";
            cin >> keep_money;

            //makes sure they answer the question correctly
            while (keep_money !="q" && keep_money!="n"){
                cout<<"that was not q or n. try again";
                cin>>keep_money;}
                
                //gets rid of all the card that are in everyones hands to restart if need be
                human_cards.clear();
                computer_cards.clear();

                //if they dont want to play anymore this will stop the game
                if (keep_money=="n"){
                    bet_double_answer="n";
                    times_2_bet=1;}}

      //this is for the highscore name                     
    string name;
    //this is for the highscore itself
    int score;

    //makes a name tag for the file scoreboard named highscore
    ifstream highscore("scoreboard.txt"); 

    //checks to make sure thye have money  
    if (money>0){
        //if the file opens correctly 
        if (highscore.is_open()){

            //looks in the file and makes the first thing go to name and the second thing go to score
            while(highscore >> name >> score){

                // checks to see if the player playing as more money then the player on the scoreboard
                if (money>score){
                    //closes the reading part of the file.
                    highscore.close();

                    //opens the wrighting part of the file
                    ofstream highscore ("scoreboard.txt",ios::trunc);

                    //over wrights the old players name and score with the new one
                    highscore<< player_name <<" "<< money<<endl;

                    //close the file
                    highscore.close();

                    //tells the player that they have the new high score and it was added 
                    cout<<"\n\n\nYou got the highscore we added you to the scoreboard."<<endl;}


                 //they have money left over but didnt make the highscore 
                 //it will just tell them who is the highscore and what it is   
                else{
                    highscore.close();
                    cout<< "\n\n\nThe high score is by "<<name<<" who got:$"<<score<<" walking out of here."<<endl;}}}
        cout<<"\nSorry to see you leave "<<player_name<<" its been fun!!! You came out with $"<<money<<". Hope to see you again your always welcome."<<"\n\n\n";}
    
    
    //they have 0 dollars so it give a mean message telling them the highscore and to leave
    else{

        cout<< "\n\n\nThe person who is better then you is"<<name<< "They walked out with $"<<score<<". Do better\n";
        cout<<"Thank you (forgot your name) for all your money. Please come back when you get more money, otherwise dont come back. Your not welcome here, bye, get out!!!\n\n\n";}
        return 0;}