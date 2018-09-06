#include "login.h"
#include <fstream>
#include <string.h>
using namespace std;

login::login(){
	ifstream read("list.txt");
	read.getline(num,4);//get the number of player at the first line
	numOfPlayer=atoi(num);		//convert it to integer
	for (int i=0;i<numOfPlayer;i++){			//get the information of all player and store to the array,4 line for each player
		read.getline(username[i],20);	
		read.getline(pw[i],20);
		read.getline(nick[i],20);
		read.getline(marktxt[i],10);
		mark[i] = atoi(marktxt[i]);
	}
	read.close();
	log=-1;
};

void login::update()//rewrite the list.txt file with updated information
{							
	ofstream write("list.txt");
	write<<numOfPlayer<<endl;
	for (int i=0;i<numOfPlayer;i++){
		write<<username[i]<<endl;
		//for(int j;j<strlen(pw[i]);i++)
		//	pw[i][j]=(char)((int)pw[i][j]-j);
			
		write<<pw[i]<<endl;
		write<<nick[i]<<endl;
		write<<marktxt[i]<<endl;
	}
	write.close();
};

bool login::newac(char newun[20], char newpw[20], char newnick[20])//true is create new ac successed
{
	bool test;//check all correct
	for (int i=0;i<numOfPlayer;i++){
		test = true;
		for	(int j=0; j<strlen(newun)+1; j++)   //check if user name is repeated (case insensitive)
		{
			if (newun[j]>=65 && newun[j]<=90){
				if(!(newun[j]==username[i][j] || newun[j]+32==username[i][j]))
					test = false;
			}
			else if (newun[j]>=97 && newun[j]<=122){
				if(!(newun[j]==username[i][j] || newun[j]-32==username[i][j]))
					test = false;
			}
			else if (newun[j]!=username[i][j])
				test = false;
			if (!test)
				break;
		}
		if (test)
			return false;
	}

	strcpy(username[numOfPlayer],newun);			//add new information of the player to the array
	strcpy(pw[numOfPlayer],newpw);
	strcpy(nick[numOfPlayer],newnick);
	strcpy(marktxt[numOfPlayer],"0");
	numOfPlayer++;
	update();							//update the txt file
	return true;
};

void  login::signin(char readun[20], char readpw[20])//check the username and password is correct
{
	bool test;
	for (int i=0;i<numOfPlayer;i++){
		test = true;
		for	(int j=0; j<strlen(readun); j++){
			if (readun[j]>=65 && readun[j]<=90){
				if(!(readun[j]==username[i][j] || readun[j]+32==username[i][j]))
					test = false;
			}
			else if (readun[j]>=97 && readun[j]<=122){
				if(!(readun[j]==username[i][j] || readun[j]-32==username[i][j]))
					test = false;
			}
			else if (readun[j]!=username[i][j])
				test = false;
			if (!test)
				break;
		}
		if (test){
			//for(int j=0;i<strlen(pw[i]);i++)
			//	(char)((int)pw[i][j]+j);
			if (strcmp(readpw,pw[i])==0){
				log = i;// change log to the player numOfPlayer
				return;
			}
			else
				return;
		}
	}
	return;
};

char *login::getnick(int id){
	return nick[id];
};

char *login::getun(int id){
	return username[id];
};

int login::getmark(int id){
	return mark[id];
};

int login::logged()
{
	return log;
}

void login::best10(int* rank)// sort the int array from higest mark to lowest mark.
{
	int j, temp, ranktemp;
	int mk[50];
	
	for (int i=0; i<numOfPlayer; i++){
		*(rank+i)=i;
		mk[i]=mark[i];
	}
	for (int i=1; i<numOfPlayer; i++) //sort the mark
	{
		j=i;
		while (j>0 && mk[j] > mk[j-1]){
			temp = mk[j];
			ranktemp = *(rank+j);
			mk[j] = mk[j-1];
			*(rank+j) = *(rank+(j-1));
			mk[j-1] = temp;
			*(rank+(j-1)) = ranktemp;
			j--;
		}
	}
}

void login::updatemark(){
	mark[log]++	;
	itoa(mark[log],marktxt[log],10);//change the mark from integer to char for white in to the txt
}

int login::getnum(){
	return numOfPlayer;
}

login::~login(){
	update(); //when run distructor,it will update the txt file
}
