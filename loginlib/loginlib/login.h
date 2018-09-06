class login{
public:
	login();
	~login();
	void update();
	bool newac(char newun[20], char newpw[20], char newnick[20]);
	void signin(char readun[20], char readpw[20]);
	int getmark(int id);
	char *getnick(int id);
	char *getun(int id);//get username
	int logged();//check logged or get the id of the player
	void best10(int* rank);
	int getnum();//get number of total registed player
	void updatemark();//the player's mark+1,the marktxt of the player +1
private:
	int log;//-1 when not logged in,otherwise store the id of player
	char username[50][20];//maximun 50 ac
	char pw[50][20];//50 player with the pw length of 20 
	char marktxt[50][10];//50 player with the maek length of 10 
	int mark[50];
	char nick[50][20];//50 player with the nick name length of 20 
	char num[3];//get the number of player in txt file
	int numOfPlayer;//store the  number of player in integer
};