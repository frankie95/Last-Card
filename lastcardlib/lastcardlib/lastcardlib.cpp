#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "lastcard.h"
using namespace std;

void Card::set(int inputrank, int inputsuit){ 
    rank = inputrank;
    suit = inputsuit;
}
int Card::getrank() {
    return rank;
}
int Card::getsuit() {
    return suit;
}

void Player::outCard(int cardNumber){
    int temp;
    for (int i = 0; i<playerNumberOfCard; i++){  //find the card array position contain the card number
        if (handCard[i] == cardNumber){
            temp = i;
            break;
        }
	}
	playerNumberOfCard -= 1; //give out a card,then player hand card number -1
    for (temp; temp<playerNumberOfCard;temp++)//move start from the position of that card number, all card array position-1
		handCard[temp]=handCard[temp+1]; 
}
void Player::inCard(int cardNumber){   
    handCard[playerNumberOfCard] = cardNumber;  //place the card to the array of the playerNumberOfCard
    playerNumberOfCard += 1;//the number of hand card +1
}
void Player::initialCard(int initialCard[]){
    for (int i = 0; i<5; i++)     //place five card to the hand card
		handCard[i] = initialCard[i];
	playerNumberOfCard = 5;
}
int Player::returnNumberOfCard() {
    return playerNumberOfCard;
}
int *Player::returncard(){
    return handCard;
}

OperationOfCardGame::OperationOfCardGame(int inputNumberOfPlayer){
    srand((unsigned)time(NULL)); // set random seed
    setCardValue();              // creat 54 class of card
    Shuffling();
    numberOfCard = 54;          //with joker,there are 54 card
    numberOfUsedCard = 0;
	numberOfRecordCard=0;
    numberOfPlayer = inputNumberOfPlayer;
    createPlayer();
    initialDrawCard();
}
void OperationOfCardGame::ShufflingUsedCard(){
	if(numberOfUsedCard>1)      //only when numberOfUsedCard>1 will shuffle used card,to make sure the latest out card will not appear in the stockpile
	{
    for (int i = 0; i<numberOfUsedCard-1; i++){		//shuffle used card		
        int random = rand() % (numberOfUsedCard-1);  //exchange the card with random number of the  array
        int temp = usedCard[i];
        usedCard[i] = usedCard[random];
        usedCard[random] = temp;
    }
	for (int i = 0; i<numberOfUsedCard-1; i++){   //place shuffled used card to card array,since only when card array=0 will call this function, it will place start from cardArray[0]
		cardArray[i]=usedCard[i];
	}
	usedCard[0]=usedCard[numberOfUsedCard-1];
	numberOfCard=numberOfUsedCard-1;
	numberOfUsedCard=1;
	}
}
int OperationOfCardGame::getNumberOfRecordCard(){
	return  numberOfRecordCard;
}
void OperationOfCardGame::Shuffling(){
    placeCardInSequence();   //place card number in order,0 to 53, repersent the card number 
    for (int i = 0; i<54; i++){       //exchange the card with random number of the  array
        int random = rand() % 54;
        int temp = cardArray[i];
        cardArray[i] = cardArray[random];
        cardArray[random] = temp;
    }
}
void OperationOfCardGame::placeCardInSequence(){
    for (int i = 0; i<54; i++)     
        cardArray[i] = i;		//54 number repersent 54 card,from 0 to 53
}
void OperationOfCardGame::createPlayer(){
    player = new Player[numberOfPlayer];	//create pointer of player class store to heap
}
void OperationOfCardGame::initialDrawCard(){
    for (int i = 0; i<numberOfPlayer; i++){			
        numberOfCard = numberOfCard - 5;	
        player[i].initialCard(cardArray + numberOfCard);//draw the last 5 card to the player
    }
	bool flag=false; //if the function card,flag=false

	int i=1;
	while(flag==false)//run until the card is not a function card
	{
		usedCard[i-1]=cardArray[numberOfCard-i];		
		recordCard[i-1]=cardArray[numberOfCard-i];
		numberOfUsedCard++;
		numberOfRecordCard++;
		if(card[cardArray[numberOfCard-i]].getrank()!=1 && card[cardArray[numberOfCard-i]].getrank()!=2 && card[cardArray[numberOfCard-i]].getrank()!=8 && card[cardArray[numberOfCard-i]].getrank()!=11 && card[cardArray[numberOfCard-i]].getrank()!=14 && card[cardArray[numberOfCard-i]].getrank()!=15){
			startCard=cardArray[numberOfCard-i]; //if the card is not function card, it will copy to the startCard
			flag=true;							//change the flag to true,finish loop
		}
		numberOfCard--;
		i++;
	}
}
void OperationOfCardGame::drawCardToPlayer(int playerNum,int num = 2){//default number of draw card is 2
    for (int i = 0; i < num; i++){
		if(numberOfCard==0)    //not enough card draw,will shuffle the used card and place to the card array
			ShufflingUsedCard();
		if(numberOfCard==0)   //after runing the ShufflingUsedCard() if the numberOfCard is still zero, it means all card are drawn, it will break
			break;
        numberOfCard--;
        player[playerNum].inCard(cardArray[numberOfCard]); 
    }
}
void OperationOfCardGame::giveOutCard(int playerNum, int cardNum){//for discarding
    player[playerNum].outCard(cardNum);         
    usedCard[numberOfUsedCard] = cardNum;   
    numberOfUsedCard++;
	if(numberOfRecordCard!=54){
		recordCard[numberOfRecordCard]=cardNum;
		numberOfRecordCard++;
	}
	else{
		for(int i=0;i<53;i++)     //maximun record 54 card,when excess,all card will shift one,the oldest card will be replaced.
			recordCard[i]=recordCard[i+1];
		recordCard[53]=cardNum;
	}
}
int *OperationOfCardGame::getRecordCard(){
	return recordCard;
}
int OperationOfCardGame::getNumberOfPlayer(){
	return numberOfPlayer;
}
int OperationOfCardGame::getStartCard(){
	return startCard;
}
int OperationOfCardGame::getNumberOfCard(){
	return numberOfCard;
}
int OperationOfCardGame::getNumberOfUsedCard(){
	return numberOfUsedCard;
}
void OperationOfCardGame::setCardValue(){//for initialize card's rank and suit
    card = new Card[54]; //create a pointer of 54 card class store in heap
    for (int i = 0; i<52; i++){
        card[i].set(i % 13 + 1, i % 4); //random 1 to 13 for rank, 0 to 3 for suit
    }
    card[52].set(14, 4); //set black joker
    card[53].set(15, 4); //set red joker
}
int OperationOfCardGame::randomNum(int number){
	return rand()%number;
}
OperationOfCardGame::~OperationOfCardGame(){
    delete[] card;		//free the memory
    delete[] player;	//free the memory
}

rule::rule(OperationOfCardGame * Og){//required a  OperationOfCardGame pointer to set the initial suit and rank for rule
	ruleOg=Og;						
	int in=Og->getStartCard();   
	suit = ruleOg->card[in].getsuit();
	rank = ruleOg->card[in].getrank();
	draw = 2; 
	drawed = true; //check the card has been drawn after discard 2,if it is true, the card has been drawn,then player can discaard with same rank or suit
}
bool rule::allowToDiscard(int cardNum){//true means can discard,false means cannot discard
	int inputSuit=ruleOg->card[cardNum].getsuit();
	int inputRank=ruleOg->card[cardNum].getrank();
	if(inputRank==14||inputRank==15) //joker always can discard(gui will check if it is last card)
		return true;

	if(rank != 2 || drawed) //the rank not equal to 2 or the card has been drawn, it only need to check if the rank or suit is equal
	{
		if(inputSuit== suit||inputRank== rank)
			return true;
	}
	else //the rank is 2 and card not yet drawn,the input rank must be 2
	{	
		if(inputRank==2)
			return true;
	}
	return false;
}
void rule::discard(int cardNum){		
	int inputSuit=ruleOg->card[cardNum].getsuit();
	int inputRank=ruleOg->card[cardNum].getrank();
	if(inputRank==14||inputRank==15)//joker is like the latest card
	{
		inputRank=rank;
		inputSuit=suit;
	}
	if (inputRank == 2)
	{
		drawed = false;// all player have to discard 2,	until someone draw card		
		if (rank == 2)
			draw+=2;//when rank equal to 2 and inputRank equal to 2(discard 2 cards of rank equal to 2), the draw need to +2
	}
	suit=inputSuit;		//update the suit
	rank=inputRank;		//update the rank
}
int rule::getdraw()//return the number of card that need to draw
{
	return draw;
}
void rule::redraw(){
	draw = 2;//reset the draw card number
	drawed = true;//someone drawn card
}
int rule::getrank(){
	return rank;
}
int rule::getsuit(){
	return suit;
}
void rule::updatesuit(int insuit)
{
	suit = insuit;
}