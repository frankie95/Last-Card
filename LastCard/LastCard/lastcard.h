class Card   //for store one card's rank and suit. total 54 card class to store a poker.
{     
public:
    void set(int inputrank, int inputsuit); //define the card's rank and suit
    int getrank() ; //return the rank
    int getsuit() ;//return the suit
private:
    int rank;  //store the rank,0 is spade,1 is heart,2 is club,3 is diamond, 4 is joker
    int suit; //1-10 for 1-10,11 is J,12 is Q,13 is K, 14 is black joker,15 is red joker
};
class Player  //for store one player's card
{
public:
    void outCard(int cardNumber); //give out the card with the corresponding card number
    void inCard(int cardNumber);//draw the card with the corresponding card number to the hand card 
    void initialCard(int initialCard[]);// the initial draw card is five, pass the card array and copy the five card number to the hand card array
    int returnNumberOfCard() ; //return the number of hand card 
    int *returncard();//retuen the hand card array which contain the card number
private:
    int playerNumberOfCard;//the number of that player's hand card
    int handCard[54];//an array for store the card number of the card,maxinum is 54 make sure is big enough. 
};
class OperationOfCardGame{
public:
    OperationOfCardGame(int inputNumberOfPlayer);
	int randomNum(int number);// for random a number which is 0 to number-1
    void ShufflingUsedCard();//for shuffling the used card and put the card in to the cardArray 
    void Shuffling();//for shuffling all card
    void placeCardInSequence();//for start a new game to shuffling
    void createPlayer();//create the player class depends on the numberOfPlayer(computer + human)
    void initialDrawCard();//give each player five card then get the first card number, if the card is function card, it will place to the used card array and get another card until the card is normal card store card number to the startCard
    void drawCardToPlayer(int playerNum,int num);// draw the number of card to the player, if not enough card,it will call ShufflingUsedCard()
    void giveOutCard(int playerNum,int cardNum);//the player give out the card of that card number 
	int *getRecordCard();//return the record card for GUI showing the previous card
	int getStartCard();
	int getNumberOfPlayer();
	int getNumberOfRecordCard(); 
	int getNumberOfCard();
	int getNumberOfUsedCard();
	void setCardValue();//create 54 card	
    ~OperationOfCardGame();	//free the memory of the heap
	Player *player;
	Card *card;
	void showcard();//for testing 
private:
	int startCard;
    int cardArray[54];//like a stockpile
    int usedCard[54];//like a discard-pile
	int recordCard[54];//store the give out card history
	int numberOfRecordCard;
    int numberOfCard;
    int numberOfUsedCard;
    int numberOfPlayer;
};

class rule{
public:
	rule(OperationOfCardGame * Og);
	bool allowToDiscard(int cardNum);//check if allow to discard
	void discard(int cardNum);//update the rank suit and update the card that need to draw if rank=2.
	void redraw();
	void updatesuit(int insuit);//for "8" function card
	int getdraw();
	int getrank();
	int getsuit();
private:
	OperationOfCardGame* ruleOg;
	int draw;
	int suit;
	int rank;
	bool drawed;
};