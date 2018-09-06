#pragma once
#include "suitup.h"
#include "recCard.h"
#include "newac.h"
#include "rule.h"
#include "winner.h"

namespace LastCard {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for game
	/// </summary>
	public ref class game : public System::Windows::Forms::Form
	{
	public:
		void AIOutCard(){ //FOR COMPUTER PLAYER TO DRAW CARD OR DISCARD
			if (pIfAI[gamer]){
				int j = 0;
				int canDis[24];
				for (int i = 0; i < (pGame->player+gamer)->returnNumberOfCard(); i++){
					 if (pRL->allowToDiscard(*(pGame->player[gamer].returncard()+i)) && !(((pGame->player+gamer)->returnNumberOfCard() == 1) && (pGame->card[*(pGame->player[gamer].returncard())].getrank() == 1 || pGame->card[*(pGame->player[gamer].returncard())].getrank() == 2 || pGame->card[*(pGame->player[gamer].returncard())].getrank() == 8 || pGame->card[*(pGame->player[gamer].returncard())].getrank() == 11 || pGame->card[*(pGame->player[gamer].returncard())].getrank() == 14 || pGame->card[*(pGame->player[gamer].returncard())].getrank() == 15))){
						 canDis[j]=*(pGame->player[gamer].returncard()+i);
						 j++;
					 }
				 }
				 if (j != 0){
					 if ((pGame->player+gamer)->returnNumberOfCard()==2)
						 last = true;
					 int r = pGame->randomNum(j);
					 outcard(canDis[r]);
					 if (pRL->getrank() == 8)
						 pRL->updatesuit(pGame->randomNum(4));
					 disable();
					 update();
				 }
				 else{
					 if (!(pGame->getNumberOfCard() == 0 && pGame->getNumberOfUsedCard() == 1)){
					 switch (numgamer){
						case 2:	switch(gamer){
								case 1: drawup();
										break;
								}
								break;
						case 3: switch(gamer){
								case 1: drawleft();
										break;
								case 2: drawright();
										break;
								}
								break;
						case 4:	switch(gamer){
								case 0: drawdown();
										break;
								case 1:	drawleft();
										break;
								case 2: drawup();
										break;
								case 3: drawright();
										break;
								}
					 }
					}
					 pGame->drawCardToPlayer(gamer,pRL->getdraw());
					 upgamer(0);
					 pRL->redraw();
					 disable();
					 update();
				 }
			}
		}
		void AIset(int human, int comp){	//TO SET WHICH IS COMPUTER OR HUMAN//FALSE FOR HUMAN TRUE FOR AI
			pIfAI = new bool[numgamer];
			switch (human){
				case 1:	switch (comp){
							case 3: *(pIfAI+3) = true;
							case 2:	*(pIfAI+2) = true;
							case 1:	*(pIfAI+1) = true;
									*(pIfAI) = false;
						}
						break;
				case 2: switch (comp){
							case 2: *(pIfAI+3) = true;
							case 1: *(pIfAI+2) = true;
							case 0: *(pIfAI+1) = false;
									*(pIfAI) = false;
						}
						break;
				case 3:	switch (comp){
							case 1: *(pIfAI+3) = true;
							case 0: *(pIfAI+2) = false;
									*(pIfAI+1) = false;
									*(pIfAI) = false;
						}
						break;
				case 4: for (int i = 0; i<4; i++)
							*(pIfAI+i) = false;
						break;
			}
		}
		void startVisible(){//for showing the button,box after the animation;
			disable();
			pictureBox29->Enabled = true;
			label12->Visible=true;
			label2->Visible=true;
			button1->Visible=true;
			button2->Visible=true;
			button3->Visible=true;
			checkBox1->Visible=true;
			label3->Visible=true;
			timer1->Enabled = !(timer1->Enabled);
			timer2->Enabled =true;
			cardName(pGame->card[pGame->getStartCard()].getrank(),pGame->card[pGame->getStartCard()].getsuit());
			pictureBox30->Visible=true;
			pictureBox30->Image = Image::FromFile("card\\"+s+r+".gif");
			label4->Visible=true;
			label5->Visible=true;
			label6->Visible=true;
			label7->Visible=true;
			label8->Visible=true;
			label9->Visible=true;
			label10->Visible=true;
			label11->Visible=true;
			update();
		}
		void outcard(int card){ //INPUT THE CARD NUMBER FOR DISCARDING
			if (!(pIfAI[gamer]))//if this is a player outcard, it will reset the wait time to 6 for next time count down
			{
				timer4->Enabled=false;
				label15->Visible=false;
				waitTime=10;
			}
			if (pRL->allowToDiscard(card) && !(((pGame->player+gamer)->returnNumberOfCard() == 1) && (pGame->card[card].getrank() == 1 || pGame->card[card].getrank() == 2 || pGame->card[card].getrank() == 8 || pGame->card[card].getrank() == 11 || pGame->card[card].getrank() == 14 || pGame->card[card].getrank() == 15))){
				switch (numgamer){
				case 2:	switch(gamer){
						case 0: givedown();
								break;
						case 1: giveup();
								break;
						}
						break;
				case 3: switch(gamer){
						case 0: givedown();
								break;
						case 1: giveleft();
								break;
						case 2: giveright();
								break;
						}
						break;
				case 4:	switch(gamer){
						case 0: givedown();
								break;
						case 1:	giveleft();
								break;
						case 2: giveup();
								break;
						case 3: giveright();
								break;
						}
				}
				pRL->discard(card);
				pGame->giveOutCard(gamer,card);
				if((pGame->player+gamer)->returnNumberOfCard() == 1 &&  last == false)
					pGame->drawCardToPlayer(gamer,5);
				if(pRL->getrank() == 8 && !pIfAI[gamer]){
					disable();
					update();
					suitup ^ F1 = gcnew suitup(pRL);
					F1->ShowDialog();
				}
				if((pGame->player+gamer)->returnNumberOfCard() == 0){
					disable();
					update();
					
					showWinner();
				}
				upgamer(pRL->getrank());
				disable();
				update();
			}
		}
		void upgamer(int RR){ //FOR GAME FLOW OF GAME//RR IS THE RANK OF CARD DISCARDING
			if (RR != 1 && RR != 11){
				if (rev){
					if (gamer < (numgamer-1))
						gamer++;
					else
						gamer = 0;
				}
				else{
					if (gamer > 0)
						gamer--;
					else
						gamer = (numgamer-1);
				}
			}
			else if (RR == 1){
				rev = (!rev);
				if (rev){
					if (gamer < (numgamer-1))
						gamer++;
					else
						gamer = 0;
				}
				else{
					if (gamer > 0)
						gamer--;
					else
						gamer = (numgamer-1);
				}
			}
			else{
				if (rev){
					if (gamer < (numgamer-1))
						gamer++;
					else
						gamer = 0;
				}
				else{
					if (gamer > 0)
						gamer--;
					else
						gamer = (numgamer-1);
				}
				if (rev){
					if (gamer < (numgamer-1))
						gamer++;
					else
						gamer = 0;
				}
				else{
					if (gamer > 0)
						gamer--;
					else
						gamer = (numgamer-1);
				}
			}
		}
		void cardName(int a,int b){ //TURN THE VALUE OF CARD TO STRING FOR CALLING THE PICTURE FILE
			if(a==11)
				r="j";
			else if(a==12)
				r="q";
			else if(a==13)
				r="k";
			else if(a==14)
				r="b";
			else if(a==15)
				r="r";
			else
				r=""+a;
			switch(b){
			case 0:s="s";break;
			case 1:s="h";break;
			case 2:s="c";break;
			case 3:s="d";break;
			case 4:s="j";break;
			}
		}
		void disable(){	//TURN OBJECT DISABLE AND INVISIBLE FOR NEW UPDATE
			last = false;
			label1->Visible = false;
			checkBox1->Enabled = false;
			checkBox1->Visible = false;
			checkBox1->Checked = false;
			button1->Enabled = false;
			button1->Visible = false;
			pictureBox36->Visible = false;
			pictureBox37->Visible = false;
			pictureBox38->Visible = false;
			pictureBox39->Visible = false;
			pictureBox40->Visible = false;
			pictureBox41->Visible = false;
			pictureBox42->Visible = false;
			pictureBox43->Visible = false;
			pictureBox44->Visible = false;
			pictureBox45->Visible = false;
			pictureBox46->Visible = false;
			pictureBox47->Visible = false;
			pictureBox48->Visible = false;
			pictureBox49->Visible = false;
			pictureBox50->Visible = false;
			pictureBox51->Visible = false;
			pictureBox52->Visible = false;
			pictureBox53->Visible = false;
			pictureBox54->Visible = false;
			pictureBox55->Visible = false;
			pictureBox56->Visible = false;
			pictureBox57->Visible = false;
			pictureBox58->Visible = false;
			pictureBox59->Visible = false;
			pictureBox36->Enabled = false;
			pictureBox37->Enabled = false;
			pictureBox38->Enabled = false;
			pictureBox39->Enabled = false;
			pictureBox40->Enabled = false;
			pictureBox41->Enabled = false;
			pictureBox42->Enabled = false;
			pictureBox43->Enabled = false;
			pictureBox44->Enabled = false;
			pictureBox45->Enabled = false;
			pictureBox46->Enabled = false;
			pictureBox47->Enabled = false;
			pictureBox48->Enabled = false;
			pictureBox49->Enabled = false;
			pictureBox50->Enabled = false;
			pictureBox51->Enabled = false;
			pictureBox52->Enabled = false;
			pictureBox53->Enabled = false;
			pictureBox54->Enabled = false;
			pictureBox55->Enabled = false;
			pictureBox56->Enabled = false;
			pictureBox57->Enabled = false;
			pictureBox58->Enabled = false;
			pictureBox59->Enabled = false;
			pictureBox1->Enabled = false;
			pictureBox1->Visible = false;
			pictureBox2->Enabled = false;
			pictureBox2->Visible = false;
			pictureBox3->Enabled = false;
			pictureBox3->Visible = false;
			pictureBox4->Enabled = false;
			pictureBox4->Visible = false;
			pictureBox5->Enabled = false;
			pictureBox5->Visible = false;
			pictureBox6->Enabled = false;
			pictureBox6->Visible = false;
			pictureBox7->Enabled = false;
			pictureBox7->Visible = false;
			pictureBox8->Enabled = false;
			pictureBox8->Visible = false;
			pictureBox9->Enabled = false;
			pictureBox9->Visible = false;
			pictureBox10->Enabled = false;
			pictureBox10->Visible = false;
			pictureBox11->Enabled = false;
			pictureBox11->Visible = false;
			pictureBox12->Enabled = false;
			pictureBox12->Visible = false;
			pictureBox13->Enabled = false;
			pictureBox13->Visible = false;
			pictureBox14->Enabled = false;
			pictureBox14->Visible = false;
			pictureBox15->Enabled = false;
			pictureBox15->Visible = false;
			pictureBox16->Enabled = false;
			pictureBox16->Visible = false;
			pictureBox17->Enabled = false;
			pictureBox17->Visible = false;
			pictureBox18->Enabled = false;
			pictureBox18->Visible = false;
			pictureBox19->Enabled = false;
			pictureBox19->Visible = false;
			pictureBox20->Enabled = false;
			pictureBox20->Visible = false;
			pictureBox21->Enabled = false;
			pictureBox21->Visible = false;
			pictureBox22->Enabled = false;
			pictureBox22->Visible = false;
			pictureBox23->Enabled = false;
			pictureBox23->Visible = false;
			pictureBox24->Enabled = false;
			pictureBox24->Visible = false;
		}
		void update(){ //WHEN THE GAME FLOW AND THE VALUE UPDATE, UPDATE ALL OBJECT WITH LATEST INFORMATION
		
			switch (numgamer){
			case 4: label11->Text = ""+(pGame->player+3)->returnNumberOfCard();
					if ((pGame->player+3)->returnNumberOfCard() == 1)
						label11->Text = "LAST CARD!";
					label10->Text = ""+(pGame->player+2)->returnNumberOfCard();
					if ((pGame->player+2)->returnNumberOfCard() == 1)
						label10->Text = "LAST CARD!";
					label9->Text = ""+(pGame->player+1)->returnNumberOfCard();
					if ((pGame->player+1)->returnNumberOfCard() == 1)
						label9->Text = "LAST CARD!";
					label8->Text = ""+(pGame->player)->returnNumberOfCard();
					if ((pGame->player)->returnNumberOfCard() == 1)
						label8->Text = "LAST CARD!";
					break;
			case 3: label11->Text = ""+(pGame->player+2)->returnNumberOfCard();
					if ((pGame->player+2)->returnNumberOfCard() == 1)
						label11->Text = "LAST CARD!";
					label9->Text = ""+(pGame->player+1)->returnNumberOfCard();
					if ((pGame->player+1)->returnNumberOfCard() == 1)
						label9->Text = "LAST CARD!";
					label8->Text = ""+(pGame->player)->returnNumberOfCard();
					if ((pGame->player)->returnNumberOfCard() == 1)
						label8->Text = "LAST CARD!";
					break;
			case 2:	label10->Text = ""+(pGame->player+1)->returnNumberOfCard();
					if ((pGame->player+1)->returnNumberOfCard() == 1)
						label10->Text = "LAST CARD!";
					label8->Text = ""+(pGame->player)->returnNumberOfCard();
					if ((pGame->player)->returnNumberOfCard() == 1)
						label8->Text = "LAST CARD!";
					break;
			}
			cardName(pRL->getrank(), pRL->getsuit());
			pictureBox30->Image = Image::FromFile("card\\"+s+r+".gif"); //show the latest DISCARD-PILE
			if (pGame->getNumberOfCard() == 0 && pGame->getNumberOfUsedCard() == 1)// no card to draw will change image
				pictureBox29->Image = Image::FromFile("card\\pass.png");
			else
				pictureBox29->Image = Image::FromFile("card\\b1fv.gif");
			label1->Text = "Player "+(gamer+1);
			if(gamer==0)
				label1->Text=Marshal::PtrToStringAnsi((IntPtr)(*pAc).getnick((*pAc).logged()));

			switch (numgamer)//for different player num, it will run different case
			{
				case 2:	switch (gamer){
							case 0: pictureBox32->Size = System::Drawing::Size(82+(pGame->player+gamer)->returnNumberOfCard()*11,118);  //for draw the yellow label to indicate the player's term
									pictureBox32->Visible = true;
									pictureBox34->Visible = false;
									break;
							case 1: pictureBox34->Size = System::Drawing::Size(82+(pGame->player+gamer)->returnNumberOfCard()*11,118);
									pictureBox32->Visible = false;
									pictureBox34->Visible = true;
									break;
						}
						break;
				case 3:	switch (gamer){
							case 0: pictureBox32->Size = System::Drawing::Size(82+(pGame->player+gamer)->returnNumberOfCard()*11,118);
									pictureBox32->Visible = true;
									pictureBox33->Visible = false;
									pictureBox35->Visible = false;
									break;
							case 1: pictureBox33->Size = System::Drawing::Size(118,82+(pGame->player+gamer)->returnNumberOfCard()*11);
									pictureBox32->Visible = false;
									pictureBox33->Visible = true;
									pictureBox35->Visible = false;
									break;
							case 2: pictureBox35->Size = System::Drawing::Size(118,82+(pGame->player+gamer)->returnNumberOfCard()*11);
									pictureBox32->Visible = false;
									pictureBox33->Visible = false;
									pictureBox35->Visible = true;
									break;
						}
						break;
				case 4:	switch (gamer){
							case 0: pictureBox32->Size = System::Drawing::Size(82+(pGame->player+gamer)->returnNumberOfCard()*11,118);
									pictureBox32->Visible = true;
									pictureBox33->Visible = false;
									pictureBox34->Visible = false;
									pictureBox35->Visible = false;
									break;
							case 1: pictureBox33->Size = System::Drawing::Size(118,82+(pGame->player+gamer)->returnNumberOfCard()*11);
									pictureBox32->Visible = false;
									pictureBox33->Visible = true;
									pictureBox34->Visible = false;
									pictureBox35->Visible = false;
									break;
							case 2: pictureBox34->Size = System::Drawing::Size(82+(pGame->player+gamer)->returnNumberOfCard()*11,118);
									pictureBox32->Visible = false;
									pictureBox33->Visible = false;
									pictureBox34->Visible = true;
									pictureBox35->Visible = false;
									break;
							case 3: pictureBox35->Size = System::Drawing::Size(118,82+(pGame->player+gamer)->returnNumberOfCard()*11);
									pictureBox32->Visible = false;
									pictureBox33->Visible = false;
									pictureBox34->Visible = false;
									pictureBox35->Visible = true;
									break;
						}
						break;
			}			

			switch (numgamer)//for different number of gamer,it will use different case to show the number of card picture
			{
				case 2:	if ((pGame->player)[0].returnNumberOfCard() != 0)
							pictureBox31->Image = Image::FromFile("card\\cardNum\\v"+(pGame->player)[0].returnNumberOfCard()+".png");
						else
							pictureBox31->Visible = false;
						if ((pGame->player)[1].returnNumberOfCard() != 0)
							pictureBox27->Image = Image::FromFile("card\\cardNum\\v"+(pGame->player)[1].returnNumberOfCard()+".png");
						else
							pictureBox27->Visible = false;
						break;
				case 3: if ((pGame->player)[0].returnNumberOfCard() != 0)
							pictureBox31->Image = Image::FromFile("card\\cardNum\\v"+(pGame->player)[0].returnNumberOfCard()+".png");
						else
							pictureBox31->Visible = false;
						if ((pGame->player)[1].returnNumberOfCard() != 0)
							pictureBox26->Image = Image::FromFile("card\\cardNum\\l"+(pGame->player)[1].returnNumberOfCard()+".png");
						else
							pictureBox26->Visible = false;
						if ((pGame->player)[2].returnNumberOfCard() != 0)
							pictureBox28->Image = Image::FromFile("card\\cardNum\\r"+(pGame->player)[2].returnNumberOfCard()+".png");
						else
							pictureBox28->Visible = false;
						break;
				case 4: if ((pGame->player)[0].returnNumberOfCard() != 0)
							pictureBox31->Image = Image::FromFile("card\\cardNum\\v"+(pGame->player)[0].returnNumberOfCard()+".png");
						else
							pictureBox31->Visible = false;
						if ((pGame->player)[1].returnNumberOfCard() != 0)
							pictureBox26->Image = Image::FromFile("card\\cardNum\\l"+(pGame->player)[1].returnNumberOfCard()+".png");
						else
							pictureBox26->Visible = false;
						if ((pGame->player)[2].returnNumberOfCard() != 0)
							pictureBox27->Image = Image::FromFile("card\\cardNum\\v"+(pGame->player)[2].returnNumberOfCard()+".png");
						else
							pictureBox27->Visible = false;
						if ((pGame->player)[3].returnNumberOfCard() != 0)
							pictureBox28->Image = Image::FromFile("card\\cardNum\\r"+(pGame->player)[3].returnNumberOfCard()+".png");
						else
							pictureBox28->Visible = false;
						break;
			}
			if (!(pIfAI[gamer]) && numHum != 1)//check it is computer or player,if player,shows card
			{	timer4->Enabled=true;
				checkBox1->Enabled = true;
				checkBox1->Visible = true;
				button1->Enabled = true;
				button1->Visible = true;
				label1->Visible = true;
				switch ((pGame->player+gamer)->returnNumberOfCard()){
					case 24: cardName(pGame->card[*(pGame->player[gamer].returncard()+23)].getrank(),pGame->card[*(pGame->player[gamer].returncard()+23)].getsuit());//get the 24th card
							 pictureBox24->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox24->Enabled = true;
							 pictureBox24->Visible = true;
					case 23: cardName(pGame->card[*(pGame->player[gamer].returncard()+22)].getrank(),pGame->card[*(pGame->player[gamer].returncard()+22)].getsuit());
							 pictureBox23->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox23->Enabled = true;
							 pictureBox23->Visible = true;
					case 22: cardName(pGame->card[*(pGame->player[gamer].returncard()+21)].getrank(),pGame->card[*(pGame->player[gamer].returncard()+21)].getsuit());
							 pictureBox22->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox22->Enabled = true;
							 pictureBox22->Visible = true;
					case 21: cardName(pGame->card[*(pGame->player[gamer].returncard()+20)].getrank(),pGame->card[*(pGame->player[gamer].returncard()+20)].getsuit());
							 pictureBox21->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox21->Enabled = true;
							 pictureBox21->Visible = true;
					case 20: cardName(pGame->card[*(pGame->player[gamer].returncard()+19)].getrank(),pGame->card[*(pGame->player[gamer].returncard()+19)].getsuit());
							 pictureBox20->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox20->Enabled = true;
							 pictureBox20->Visible = true;
					case 19: cardName(pGame->card[*(pGame->player[gamer].returncard()+18)].getrank(),pGame->card[*(pGame->player[gamer].returncard()+18)].getsuit());
							 pictureBox19->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox19->Enabled = true;
							 pictureBox19->Visible = true;
					case 18: cardName(pGame->card[*(pGame->player[gamer].returncard()+17)].getrank(),pGame->card[*(pGame->player[gamer].returncard()+17)].getsuit());
							 pictureBox18->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox18->Enabled = true;
							 pictureBox18->Visible = true;
					case 17: cardName(pGame->card[*(pGame->player[gamer].returncard()+16)].getrank(),pGame->card[*(pGame->player[gamer].returncard()+16)].getsuit());
							 pictureBox17->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox17->Enabled = true;
							 pictureBox17->Visible = true;
					case 16: cardName(pGame->card[*(pGame->player[gamer].returncard()+15)].getrank(),pGame->card[*(pGame->player[gamer].returncard()+15)].getsuit());
							 pictureBox16->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox16->Enabled = true;
							 pictureBox16->Visible = true;
					case 15: cardName(pGame->card[*(pGame->player[gamer].returncard()+14)].getrank(),pGame->card[*(pGame->player[gamer].returncard()+14)].getsuit());
							 pictureBox15->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox15->Enabled = true;
							 pictureBox15->Visible = true;
					case 14: cardName(pGame->card[*(pGame->player[gamer].returncard()+13)].getrank(),pGame->card[*(pGame->player[gamer].returncard()+13)].getsuit());
							 pictureBox14->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox14->Enabled = true;
							 pictureBox14->Visible = true;
					case 13: cardName(pGame->card[*(pGame->player[gamer].returncard()+12)].getrank(),pGame->card[*(pGame->player[gamer].returncard()+12)].getsuit());
							 pictureBox13->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox13->Enabled = true;
							 pictureBox13->Visible = true;
					case 12: cardName(pGame->card[*(pGame->player[gamer].returncard()+11)].getrank(),pGame->card[*(pGame->player[gamer].returncard()+11)].getsuit());
							 pictureBox12->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox12->Enabled = true;
							 pictureBox12->Visible = true;
					case 11: cardName(pGame->card[*(pGame->player[gamer].returncard()+10)].getrank(),pGame->card[*(pGame->player[gamer].returncard()+10)].getsuit());
							 pictureBox11->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox11->Enabled = true;
							 pictureBox11->Visible = true;
					case 10: cardName(pGame->card[*(pGame->player[gamer].returncard()+9)].getrank(),pGame->card[*(pGame->player[gamer].returncard()+9)].getsuit());
							 pictureBox10->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox10->Enabled = true;
							 pictureBox10->Visible = true;
					case 9: cardName(pGame->card[*(pGame->player[gamer].returncard()+8)].getrank(),pGame->card[*(pGame->player[gamer].returncard()+8)].getsuit());
							pictureBox9->Image = Image::FromFile("card\\"+s+r+".gif");
							pictureBox9->Enabled = true;
							pictureBox9->Visible = true;
					case 8: cardName(pGame->card[*(pGame->player[gamer].returncard()+7)].getrank(),pGame->card[*(pGame->player[gamer].returncard()+7)].getsuit());
							pictureBox8->Image = Image::FromFile("card\\"+s+r+".gif");
							pictureBox8->Enabled = true;
							pictureBox8->Visible = true;
					case 7: cardName(pGame->card[*(pGame->player[gamer].returncard()+6)].getrank(),pGame->card[*(pGame->player[gamer].returncard()+6)].getsuit());
							pictureBox7->Image = Image::FromFile("card\\"+s+r+".gif");
							pictureBox7->Enabled = true;
							pictureBox7->Visible = true;
					case 6: cardName(pGame->card[*(pGame->player[gamer].returncard()+5)].getrank(),pGame->card[*(pGame->player[gamer].returncard()+5)].getsuit());
							pictureBox6->Image = Image::FromFile("card\\"+s+r+".gif");
							pictureBox6->Enabled = true;
							pictureBox6->Visible = true;
					case 5: cardName(pGame->card[*(pGame->player[gamer].returncard()+4)].getrank(),pGame->card[*(pGame->player[gamer].returncard()+4)].getsuit());
							pictureBox5->Image = Image::FromFile("card\\"+s+r+".gif");
							pictureBox5->Enabled = true;
							pictureBox5->Visible = true;
					case 4: cardName(pGame->card[*(pGame->player[gamer].returncard()+3)].getrank(),pGame->card[*(pGame->player[gamer].returncard()+3)].getsuit());
							pictureBox4->Image = Image::FromFile("card\\"+s+r+".gif");
							pictureBox4->Enabled = true;
							pictureBox4->Visible = true;
					case 3: cardName(pGame->card[*(pGame->player[gamer].returncard()+2)].getrank(),pGame->card[*(pGame->player[gamer].returncard()+2)].getsuit());
							pictureBox3->Image = Image::FromFile("card\\"+s+r+".gif");
							pictureBox3->Enabled = true;
							pictureBox3->Visible = true;
					case 2: cardName(pGame->card[*(pGame->player[gamer].returncard()+1)].getrank(),pGame->card[*(pGame->player[gamer].returncard()+1)].getsuit());
							pictureBox2->Image = Image::FromFile("card\\"+s+r+".gif");
							pictureBox2->Enabled = true;
							pictureBox2->Visible = true;
					case 1: cardName(pGame->card[*(pGame->player[gamer].returncard())].getrank(),pGame->card[*(pGame->player[gamer].returncard())].getsuit());
							pictureBox1->Image = Image::FromFile("card\\"+s+r+".gif");
							pictureBox1->Enabled = true;
							pictureBox1->Visible = true;
				}
			}
			else if (numHum == 1){
				timer4->Enabled=true;
				checkBox1->Enabled = true;
				checkBox1->Visible = true;
				button1->Enabled = true;
				button1->Visible = true;				
				label1->Text=Marshal::PtrToStringAnsi((IntPtr)(*pAc).getnick((*pAc).logged()));
				label1->Visible = true;
				switch (pGame->player->returnNumberOfCard()){
					case 24: cardName(pGame->card[*(pGame->player->returncard()+23)].getrank(),pGame->card[*(pGame->player->returncard()+23)].getsuit());//get the 24th card
							 pictureBox24->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox24->Enabled = true;
							 pictureBox24->Visible = true;
					case 23: cardName(pGame->card[*(pGame->player->returncard()+22)].getrank(),pGame->card[*(pGame->player->returncard()+22)].getsuit());
							 pictureBox23->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox23->Enabled = true;
							 pictureBox23->Visible = true;
					case 22: cardName(pGame->card[*(pGame->player->returncard()+21)].getrank(),pGame->card[*(pGame->player->returncard()+21)].getsuit());
							 pictureBox22->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox22->Enabled = true;
							 pictureBox22->Visible = true;
					case 21: cardName(pGame->card[*(pGame->player->returncard()+20)].getrank(),pGame->card[*(pGame->player->returncard()+20)].getsuit());
							 pictureBox21->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox21->Enabled = true;
							 pictureBox21->Visible = true;
					case 20: cardName(pGame->card[*(pGame->player->returncard()+19)].getrank(),pGame->card[*(pGame->player->returncard()+19)].getsuit());
							 pictureBox20->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox20->Enabled = true;
							 pictureBox20->Visible = true;
					case 19: cardName(pGame->card[*(pGame->player->returncard()+18)].getrank(),pGame->card[*(pGame->player->returncard()+18)].getsuit());
							 pictureBox19->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox19->Enabled = true;
							 pictureBox19->Visible = true;
					case 18: cardName(pGame->card[*(pGame->player->returncard()+17)].getrank(),pGame->card[*(pGame->player->returncard()+17)].getsuit());
							 pictureBox18->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox18->Enabled = true;
							 pictureBox18->Visible = true;
					case 17: cardName(pGame->card[*(pGame->player->returncard()+16)].getrank(),pGame->card[*(pGame->player->returncard()+16)].getsuit());
							 pictureBox17->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox17->Enabled = true;
							 pictureBox17->Visible = true;
					case 16: cardName(pGame->card[*(pGame->player->returncard()+15)].getrank(),pGame->card[*(pGame->player->returncard()+15)].getsuit());
							 pictureBox16->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox16->Enabled = true;
							 pictureBox16->Visible = true;
					case 15: cardName(pGame->card[*(pGame->player->returncard()+14)].getrank(),pGame->card[*(pGame->player->returncard()+14)].getsuit());
							 pictureBox15->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox15->Enabled = true;
							 pictureBox15->Visible = true;
					case 14: cardName(pGame->card[*(pGame->player->returncard()+13)].getrank(),pGame->card[*(pGame->player->returncard()+13)].getsuit());
							 pictureBox14->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox14->Enabled = true;
							 pictureBox14->Visible = true;
					case 13: cardName(pGame->card[*(pGame->player->returncard()+12)].getrank(),pGame->card[*(pGame->player->returncard()+12)].getsuit());
							 pictureBox13->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox13->Enabled = true;
							 pictureBox13->Visible = true;
					case 12: cardName(pGame->card[*(pGame->player->returncard()+11)].getrank(),pGame->card[*(pGame->player->returncard()+11)].getsuit());
							 pictureBox12->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox12->Enabled = true;
							 pictureBox12->Visible = true;
					case 11: cardName(pGame->card[*(pGame->player->returncard()+10)].getrank(),pGame->card[*(pGame->player->returncard()+10)].getsuit());
							 pictureBox11->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox11->Enabled = true;
							 pictureBox11->Visible = true;
					case 10: cardName(pGame->card[*(pGame->player->returncard()+9)].getrank(),pGame->card[*(pGame->player->returncard()+9)].getsuit());
							 pictureBox10->Image = Image::FromFile("card\\"+s+r+".gif");
							 pictureBox10->Enabled = true;
							 pictureBox10->Visible = true;
					case 9: cardName(pGame->card[*(pGame->player->returncard()+8)].getrank(),pGame->card[*(pGame->player->returncard()+8)].getsuit());
							pictureBox9->Image = Image::FromFile("card\\"+s+r+".gif");
							pictureBox9->Enabled = true;
							pictureBox9->Visible = true;
					case 8: cardName(pGame->card[*(pGame->player->returncard()+7)].getrank(),pGame->card[*(pGame->player->returncard()+7)].getsuit());
							pictureBox8->Image = Image::FromFile("card\\"+s+r+".gif");
							pictureBox8->Enabled = true;
							pictureBox8->Visible = true;
					case 7: cardName(pGame->card[*(pGame->player->returncard()+6)].getrank(),pGame->card[*(pGame->player->returncard()+6)].getsuit());
							pictureBox7->Image = Image::FromFile("card\\"+s+r+".gif");
							pictureBox7->Enabled = true;
							pictureBox7->Visible = true;
					case 6: cardName(pGame->card[*(pGame->player->returncard()+5)].getrank(),pGame->card[*(pGame->player->returncard()+5)].getsuit());
							pictureBox6->Image = Image::FromFile("card\\"+s+r+".gif");
							pictureBox6->Enabled = true;
							pictureBox6->Visible = true;
					case 5: cardName(pGame->card[*(pGame->player->returncard()+4)].getrank(),pGame->card[*(pGame->player->returncard()+4)].getsuit());
							pictureBox5->Image = Image::FromFile("card\\"+s+r+".gif");
							pictureBox5->Enabled = true;
							pictureBox5->Visible = true;
					case 4: cardName(pGame->card[*(pGame->player->returncard()+3)].getrank(),pGame->card[*(pGame->player->returncard()+3)].getsuit());
							pictureBox4->Image = Image::FromFile("card\\"+s+r+".gif");
							pictureBox4->Enabled = true;
							pictureBox4->Visible = true;
					case 3: cardName(pGame->card[*(pGame->player->returncard()+2)].getrank(),pGame->card[*(pGame->player->returncard()+2)].getsuit());
							pictureBox3->Image = Image::FromFile("card\\"+s+r+".gif");
							pictureBox3->Enabled = true;
							pictureBox3->Visible = true;
					case 2: cardName(pGame->card[*(pGame->player->returncard()+1)].getrank(),pGame->card[*(pGame->player->returncard()+1)].getsuit());
							pictureBox2->Image = Image::FromFile("card\\"+s+r+".gif");
							pictureBox2->Enabled = true;
							pictureBox2->Visible = true;
					case 1: cardName(pGame->card[*(pGame->player->returncard())].getrank(),pGame->card[*(pGame->player->returncard())].getsuit());
							pictureBox1->Image = Image::FromFile("card\\"+s+r+".gif");
							pictureBox1->Enabled = true;
							pictureBox1->Visible = true;
				}
			}
		}
		void showWinner(){ //WHEN TIME'S UP OR SOMEONE DISCARDING ALL CARD
			timer2->Enabled=false;
			winner^ Winner=gcnew winner(pAc, pGame,numHum,numgamer);
			Winner->ShowDialog();
			this->Close();
		}
		void drawleft(){ //ANIMATION FOR DRAW CARD;
			if(anFlag){
				cardX=pictureBox29->Location.X;
				timer3->Enabled=true;
				dleft=true;
				anFlag=false;
			}		
		}
		void drawright(){ //ANIMATION FOR DRAW CARD;
			if(anFlag){
				cardX=pictureBox29->Location.X;
				timer3->Enabled=true;
				anFlag=false;
				dright=true;
			}
		}
		void drawup(){//ANIMATION FOR DRAW CARD;
			if(anFlag){
				cardY=pictureBox29->Location.Y;
				timer3->Enabled=true;
				anFlag=false;
				dup=true;
			}
		}
		void drawdown(){//ANIMATION FOR DRAW CARD;
			if(anFlag){
				cardY=pictureBox29->Location.Y;
				timer3->Enabled=true;
				anFlag=false;
				ddown=true;
			}
		}
		void giveup(){//ANIMATION FOR DISCARD;
			if(anFlag){
				cardY=pictureBox27->Location.Y;
				cardX=pictureBox27->Location.X;
				timer3->Enabled=true;
				anFlag=false;
				gup=true;
			}
		}
		void giveright(){//ANIMATION FOR DISCARD;
			if(anFlag){
				cardY=pictureBox28->Location.Y;
				cardX=pictureBox28->Location.X;
				timer3->Enabled=true;
				anFlag=false;
				gright=true;
			}
		}
		void giveleft(){ //ANIMATION FOR DISCARD;
			if(anFlag){
				cardY=pictureBox26->Location.Y;
				cardX=pictureBox26->Location.X;
				timer3->Enabled=true;
				anFlag=false;
				gleft=true;
			}
		}
		void givedown(){//ANIMATION FOR DISCARD;
			if(anFlag){
				cardY=pictureBox31->Location.Y;
				cardX=pictureBox31->Location.X;
				timer3->Enabled=true;
				anFlag=false;
				gdown=true;
			}
		}
		game(int Player, int Computer,int Time,bool DiscardTime, login *pAccount){ //CONSTRUCTOR OF THE FORM
			InitializeComponent();
			x=0;//initial the x for counting the x to run the start animation
			numgamer = Player+Computer;
			pGame = new OperationOfCardGame(numgamer);
			pAc = pAccount;
			pRL = new rule(pGame);
			AIset(Player, Computer);
			waitTime=10;//wait discard time =10s
			discardTime=DiscardTime;
			this->SetStyle(static_cast<ControlStyles>(ControlStyles::AllPaintingInWmPaint|ControlStyles::DoubleBuffer|ControlStyles::UserPaint),true);
			this->UpdateStyles();
			rev = true;  
			gamer = 0; //to determine which player is playing,0,1,2,3
			y=1;//set the initial animation card number
			z=0;//the initial animation position of the drawcard diraction 
			time=Time;
			numHum = Player;
			label15->Visible=false;
			label12->Visible=false;
			label2->Visible=false;
			button1->Visible=false;
			button2->Visible=false;
			checkBox1->Visible=false;
			label3->Visible=false;
			button3->Visible=false;
			anFlag=true;
			last=false;
			label4->Text = Marshal::PtrToStringAnsi((IntPtr)(*pAc).getnick((*pAc).logged()));
			pictureBox29->Image= Image::FromFile("card\\b1fv.gif");
			switch (Player){
			case 4:	label7->Text="Player 4";
					label6->Text="Player 3";
					label5->Text="Player 2";
					break;
			case 3: label5->Text="Player 2";
					if (Computer == 1){
						label6->Text="Player 3";
						label7->Text="Computer 1";
					}
					else
						label7->Text="Player 3";
					break;
			case 2: switch (Computer){
					case 2:	label5->Text="Player 2";
							label7->Text="Computer 2";
							label6->Text="Computer 1";
							break;
					case 1:	label5->Text="Player 2";
							label7->Text="Computer 1";
							break;
					case 0: label6->Text="Player 2";
					}
					break;
			case 1: switch (Computer){
					case 3: label7->Text="Computer 3";
							label6->Text="Computer 2";
							label5->Text="Computer 1";
							break;
					case 2: label5->Text="Computer 1";
							label7->Text="Computer 2";
							break;
					case 1: label6->Text="Computer 1";
							break;
					}
			}


		}
	private:
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~game()
		{delete pIfAI;
			if (components)
			{
				delete components;
				
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected: 
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::PictureBox^  pictureBox6;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::PictureBox^  pictureBox8;
	private: System::Windows::Forms::PictureBox^  pictureBox9;
	private: System::Windows::Forms::PictureBox^  pictureBox10;
	private: System::Windows::Forms::PictureBox^  pictureBox11;
	private: System::Windows::Forms::PictureBox^  pictureBox12;
	private: System::Windows::Forms::PictureBox^  pictureBox13;
	private: System::Windows::Forms::PictureBox^  pictureBox14;
	private: System::Windows::Forms::PictureBox^  pictureBox15;
	private: System::Windows::Forms::PictureBox^  pictureBox16;
	private: System::Windows::Forms::PictureBox^  pictureBox17;
	private: System::Windows::Forms::PictureBox^  pictureBox18;
	private: System::Windows::Forms::PictureBox^  pictureBox19;
	private: System::Windows::Forms::PictureBox^  pictureBox20;
	private: System::Windows::Forms::PictureBox^  pictureBox21;
	private: System::Windows::Forms::PictureBox^  pictureBox22;
	private: System::Windows::Forms::PictureBox^  pictureBox23;
	private: System::Windows::Forms::PictureBox^  pictureBox24;
	private: System::Windows::Forms::PictureBox^  pictureBox26;
	private: System::Windows::Forms::PictureBox^  pictureBox27;
	private: System::Windows::Forms::PictureBox^  pictureBox28;
	private: System::Windows::Forms::PictureBox^  pictureBox29;
	private: System::Windows::Forms::PictureBox^  pictureBox30;

	private:
		/// <summary>
		OperationOfCardGame *pGame;
		rule *pRL;
		String^ s;//for getting card suit name
		String^ r;//for getting card rank name
		int gamer;
		bool rev;
		int x;//for control the speed for first animation
		int numgamer,numHum,y,z,time,cardX,cardY;
		login *pAc;
		bool dleft,dright,dup,ddown,gleft,gright,gup,gdown; //control the animation
		bool anFlag;//make sure only onn animation show at the sametime,when true ,it means no animation is showing
		bool *pIfAI;
		bool last;
		bool discardTime;
		int waitTime;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox31;
	private: System::Windows::Forms::PictureBox^  pictureBox32;
	private: System::Windows::Forms::PictureBox^  pictureBox33;
	private: System::Windows::Forms::PictureBox^  pictureBox34;
	private: System::Windows::Forms::PictureBox^  pictureBox35;
	private: System::Windows::Forms::PictureBox^  pictureBox36;
	private: System::Windows::Forms::PictureBox^  pictureBox37;
	private: System::Windows::Forms::PictureBox^  pictureBox38;
	private: System::Windows::Forms::PictureBox^  pictureBox39;
	private: System::Windows::Forms::PictureBox^  pictureBox40;
	private: System::Windows::Forms::PictureBox^  pictureBox41;
	private: System::Windows::Forms::PictureBox^  pictureBox42;
	private: System::Windows::Forms::PictureBox^  pictureBox43;
	private: System::Windows::Forms::PictureBox^  pictureBox44;
	private: System::Windows::Forms::PictureBox^  pictureBox45;
	private: System::Windows::Forms::PictureBox^  pictureBox46;
	private: System::Windows::Forms::PictureBox^  pictureBox47;
	private: System::Windows::Forms::PictureBox^  pictureBox48;
	private: System::Windows::Forms::PictureBox^  pictureBox49;
	private: System::Windows::Forms::PictureBox^  pictureBox50;
	private: System::Windows::Forms::PictureBox^  pictureBox51;
	private: System::Windows::Forms::PictureBox^  pictureBox52;
	private: System::Windows::Forms::PictureBox^  pictureBox53;
	private: System::Windows::Forms::PictureBox^  pictureBox54;
	private: System::Windows::Forms::PictureBox^  pictureBox55;
	private: System::Windows::Forms::PictureBox^  pictureBox56;
	private: System::Windows::Forms::PictureBox^  pictureBox57;
	private: System::Windows::Forms::PictureBox^  pictureBox58;
	private: System::Windows::Forms::PictureBox^  pictureBox59;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Timer^  timer3;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label6;

private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::Timer^  timer4;


private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::Label^  label7;



	private: System::ComponentModel::IContainer^  components;


#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox14 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox15 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox16 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox17 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox18 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox19 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox20 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox21 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox22 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox23 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox24 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox26 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox27 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox28 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox29 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox30 = (gcnew System::Windows::Forms::PictureBox());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->pictureBox31 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox32 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox33 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox34 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox35 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox36 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox37 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox38 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox39 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox40 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox41 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox42 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox43 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox44 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox45 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox46 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox47 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox48 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox49 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox50 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox51 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox52 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox53 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox54 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox55 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox56 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox57 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox58 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox59 = (gcnew System::Windows::Forms::PictureBox());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->button3 = (gcnew System::Windows::Forms::Button());
				 this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->label5 = (gcnew System::Windows::Forms::Label());
				 this->label6 = (gcnew System::Windows::Forms::Label());
				 this->label8 = (gcnew System::Windows::Forms::Label());
				 this->label9 = (gcnew System::Windows::Forms::Label());
				 this->label10 = (gcnew System::Windows::Forms::Label());
				 this->label11 = (gcnew System::Windows::Forms::Label());
				 this->label12 = (gcnew System::Windows::Forms::Label());
				 this->timer4 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->label15 = (gcnew System::Windows::Forms::Label());
				 this->label7 = (gcnew System::Windows::Forms::Label());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox9))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox10))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox11))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox12))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox13))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox14))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox15))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox16))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox17))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox18))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox19))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox20))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox21))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox22))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox23))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox24))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox26))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox27))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox28))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox29))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox30))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox31))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox32))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox33))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox34))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox35))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox36))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox37))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox38))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox39))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox40))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox41))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox42))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox43))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox44))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox45))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox46))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox47))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox48))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox49))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox50))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox51))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox52))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox53))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox54))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox55))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox56))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox57))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox58))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox59))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // pictureBox1
				 // 
				 this->pictureBox1->Enabled = false;
				 this->pictureBox1->Location = System::Drawing::Point(50, 476);
				 this->pictureBox1->Name = L"pictureBox1";
				 this->pictureBox1->Size = System::Drawing::Size(71, 96);
				 this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox1->TabIndex = 0;
				 this->pictureBox1->TabStop = false;
				 this->pictureBox1->Click += gcnew System::EventHandler(this, &game::pictureBox1_Click);
				 // 
				 // pictureBox2
				 // 
				 this->pictureBox2->Enabled = false;
				 this->pictureBox2->Location = System::Drawing::Point(127, 476);
				 this->pictureBox2->Name = L"pictureBox2";
				 this->pictureBox2->Size = System::Drawing::Size(71, 96);
				 this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox2->TabIndex = 1;
				 this->pictureBox2->TabStop = false;
				 this->pictureBox2->Click += gcnew System::EventHandler(this, &game::pictureBox2_Click);
				 // 
				 // pictureBox3
				 // 
				 this->pictureBox3->Enabled = false;
				 this->pictureBox3->Location = System::Drawing::Point(204, 476);
				 this->pictureBox3->Name = L"pictureBox3";
				 this->pictureBox3->Size = System::Drawing::Size(71, 96);
				 this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox3->TabIndex = 2;
				 this->pictureBox3->TabStop = false;
				 this->pictureBox3->Click += gcnew System::EventHandler(this, &game::pictureBox3_Click);
				 // 
				 // pictureBox4
				 // 
				 this->pictureBox4->Enabled = false;
				 this->pictureBox4->Location = System::Drawing::Point(281, 476);
				 this->pictureBox4->Name = L"pictureBox4";
				 this->pictureBox4->Size = System::Drawing::Size(71, 96);
				 this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox4->TabIndex = 3;
				 this->pictureBox4->TabStop = false;
				 this->pictureBox4->Click += gcnew System::EventHandler(this, &game::pictureBox4_Click);
				 // 
				 // pictureBox5
				 // 
				 this->pictureBox5->Enabled = false;
				 this->pictureBox5->Location = System::Drawing::Point(358, 476);
				 this->pictureBox5->Name = L"pictureBox5";
				 this->pictureBox5->Size = System::Drawing::Size(71, 96);
				 this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox5->TabIndex = 4;
				 this->pictureBox5->TabStop = false;
				 this->pictureBox5->Click += gcnew System::EventHandler(this, &game::pictureBox5_Click);
				 // 
				 // pictureBox6
				 // 
				 this->pictureBox6->Enabled = false;
				 this->pictureBox6->Location = System::Drawing::Point(435, 476);
				 this->pictureBox6->Name = L"pictureBox6";
				 this->pictureBox6->Size = System::Drawing::Size(71, 96);
				 this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox6->TabIndex = 5;
				 this->pictureBox6->TabStop = false;
				 this->pictureBox6->Click += gcnew System::EventHandler(this, &game::pictureBox6_Click);
				 // 
				 // pictureBox7
				 // 
				 this->pictureBox7->Enabled = false;
				 this->pictureBox7->Location = System::Drawing::Point(512, 476);
				 this->pictureBox7->Name = L"pictureBox7";
				 this->pictureBox7->Size = System::Drawing::Size(71, 96);
				 this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox7->TabIndex = 6;
				 this->pictureBox7->TabStop = false;
				 this->pictureBox7->Click += gcnew System::EventHandler(this, &game::pictureBox7_Click);
				 // 
				 // pictureBox8
				 // 
				 this->pictureBox8->Enabled = false;
				 this->pictureBox8->Location = System::Drawing::Point(589, 476);
				 this->pictureBox8->Name = L"pictureBox8";
				 this->pictureBox8->Size = System::Drawing::Size(71, 96);
				 this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox8->TabIndex = 7;
				 this->pictureBox8->TabStop = false;
				 this->pictureBox8->Click += gcnew System::EventHandler(this, &game::pictureBox8_Click);
				 // 
				 // pictureBox9
				 // 
				 this->pictureBox9->Enabled = false;
				 this->pictureBox9->Location = System::Drawing::Point(666, 476);
				 this->pictureBox9->Name = L"pictureBox9";
				 this->pictureBox9->Size = System::Drawing::Size(71, 96);
				 this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox9->TabIndex = 8;
				 this->pictureBox9->TabStop = false;
				 this->pictureBox9->Click += gcnew System::EventHandler(this, &game::pictureBox9_Click);
				 // 
				 // pictureBox10
				 // 
				 this->pictureBox10->Enabled = false;
				 this->pictureBox10->Location = System::Drawing::Point(743, 476);
				 this->pictureBox10->Name = L"pictureBox10";
				 this->pictureBox10->Size = System::Drawing::Size(71, 96);
				 this->pictureBox10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox10->TabIndex = 9;
				 this->pictureBox10->TabStop = false;
				 this->pictureBox10->Click += gcnew System::EventHandler(this, &game::pictureBox10_Click);
				 // 
				 // pictureBox11
				 // 
				 this->pictureBox11->Enabled = false;
				 this->pictureBox11->Location = System::Drawing::Point(820, 476);
				 this->pictureBox11->Name = L"pictureBox11";
				 this->pictureBox11->Size = System::Drawing::Size(71, 96);
				 this->pictureBox11->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox11->TabIndex = 10;
				 this->pictureBox11->TabStop = false;
				 this->pictureBox11->Click += gcnew System::EventHandler(this, &game::pictureBox11_Click);
				 // 
				 // pictureBox12
				 // 
				 this->pictureBox12->Enabled = false;
				 this->pictureBox12->Location = System::Drawing::Point(897, 476);
				 this->pictureBox12->Name = L"pictureBox12";
				 this->pictureBox12->Size = System::Drawing::Size(71, 96);
				 this->pictureBox12->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox12->TabIndex = 11;
				 this->pictureBox12->TabStop = false;
				 this->pictureBox12->Click += gcnew System::EventHandler(this, &game::pictureBox12_Click);
				 // 
				 // pictureBox13
				 // 
				 this->pictureBox13->Enabled = false;
				 this->pictureBox13->Location = System::Drawing::Point(50, 578);
				 this->pictureBox13->Name = L"pictureBox13";
				 this->pictureBox13->Size = System::Drawing::Size(71, 96);
				 this->pictureBox13->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox13->TabIndex = 12;
				 this->pictureBox13->TabStop = false;
				 this->pictureBox13->Click += gcnew System::EventHandler(this, &game::pictureBox13_Click);
				 // 
				 // pictureBox14
				 // 
				 this->pictureBox14->Enabled = false;
				 this->pictureBox14->Location = System::Drawing::Point(127, 578);
				 this->pictureBox14->Name = L"pictureBox14";
				 this->pictureBox14->Size = System::Drawing::Size(71, 96);
				 this->pictureBox14->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox14->TabIndex = 13;
				 this->pictureBox14->TabStop = false;
				 this->pictureBox14->Click += gcnew System::EventHandler(this, &game::pictureBox14_Click);
				 // 
				 // pictureBox15
				 // 
				 this->pictureBox15->Enabled = false;
				 this->pictureBox15->Location = System::Drawing::Point(204, 578);
				 this->pictureBox15->Name = L"pictureBox15";
				 this->pictureBox15->Size = System::Drawing::Size(71, 96);
				 this->pictureBox15->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox15->TabIndex = 14;
				 this->pictureBox15->TabStop = false;
				 this->pictureBox15->Click += gcnew System::EventHandler(this, &game::pictureBox15_Click);
				 // 
				 // pictureBox16
				 // 
				 this->pictureBox16->Enabled = false;
				 this->pictureBox16->Location = System::Drawing::Point(281, 578);
				 this->pictureBox16->Name = L"pictureBox16";
				 this->pictureBox16->Size = System::Drawing::Size(71, 96);
				 this->pictureBox16->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox16->TabIndex = 15;
				 this->pictureBox16->TabStop = false;
				 this->pictureBox16->Click += gcnew System::EventHandler(this, &game::pictureBox16_Click);
				 // 
				 // pictureBox17
				 // 
				 this->pictureBox17->Enabled = false;
				 this->pictureBox17->Location = System::Drawing::Point(358, 578);
				 this->pictureBox17->Name = L"pictureBox17";
				 this->pictureBox17->Size = System::Drawing::Size(71, 96);
				 this->pictureBox17->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox17->TabIndex = 16;
				 this->pictureBox17->TabStop = false;
				 this->pictureBox17->Click += gcnew System::EventHandler(this, &game::pictureBox17_Click);
				 // 
				 // pictureBox18
				 // 
				 this->pictureBox18->Enabled = false;
				 this->pictureBox18->Location = System::Drawing::Point(435, 578);
				 this->pictureBox18->Name = L"pictureBox18";
				 this->pictureBox18->Size = System::Drawing::Size(71, 96);
				 this->pictureBox18->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox18->TabIndex = 17;
				 this->pictureBox18->TabStop = false;
				 this->pictureBox18->Click += gcnew System::EventHandler(this, &game::pictureBox18_Click);
				 // 
				 // pictureBox19
				 // 
				 this->pictureBox19->Enabled = false;
				 this->pictureBox19->Location = System::Drawing::Point(512, 578);
				 this->pictureBox19->Name = L"pictureBox19";
				 this->pictureBox19->Size = System::Drawing::Size(71, 96);
				 this->pictureBox19->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox19->TabIndex = 18;
				 this->pictureBox19->TabStop = false;
				 this->pictureBox19->Click += gcnew System::EventHandler(this, &game::pictureBox19_Click);
				 // 
				 // pictureBox20
				 // 
				 this->pictureBox20->Enabled = false;
				 this->pictureBox20->Location = System::Drawing::Point(589, 578);
				 this->pictureBox20->Name = L"pictureBox20";
				 this->pictureBox20->Size = System::Drawing::Size(71, 96);
				 this->pictureBox20->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox20->TabIndex = 19;
				 this->pictureBox20->TabStop = false;
				 this->pictureBox20->Click += gcnew System::EventHandler(this, &game::pictureBox20_Click);
				 // 
				 // pictureBox21
				 // 
				 this->pictureBox21->Enabled = false;
				 this->pictureBox21->Location = System::Drawing::Point(666, 578);
				 this->pictureBox21->Name = L"pictureBox21";
				 this->pictureBox21->Size = System::Drawing::Size(71, 96);
				 this->pictureBox21->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox21->TabIndex = 20;
				 this->pictureBox21->TabStop = false;
				 this->pictureBox21->Click += gcnew System::EventHandler(this, &game::pictureBox21_Click);
				 // 
				 // pictureBox22
				 // 
				 this->pictureBox22->Enabled = false;
				 this->pictureBox22->Location = System::Drawing::Point(743, 578);
				 this->pictureBox22->Name = L"pictureBox22";
				 this->pictureBox22->Size = System::Drawing::Size(71, 96);
				 this->pictureBox22->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox22->TabIndex = 21;
				 this->pictureBox22->TabStop = false;
				 this->pictureBox22->Click += gcnew System::EventHandler(this, &game::pictureBox22_Click);
				 // 
				 // pictureBox23
				 // 
				 this->pictureBox23->Enabled = false;
				 this->pictureBox23->Location = System::Drawing::Point(820, 578);
				 this->pictureBox23->Name = L"pictureBox23";
				 this->pictureBox23->Size = System::Drawing::Size(71, 96);
				 this->pictureBox23->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox23->TabIndex = 22;
				 this->pictureBox23->TabStop = false;
				 this->pictureBox23->Click += gcnew System::EventHandler(this, &game::pictureBox23_Click);
				 // 
				 // pictureBox24
				 // 
				 this->pictureBox24->Enabled = false;
				 this->pictureBox24->Location = System::Drawing::Point(897, 578);
				 this->pictureBox24->Name = L"pictureBox24";
				 this->pictureBox24->Size = System::Drawing::Size(71, 96);
				 this->pictureBox24->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox24->TabIndex = 23;
				 this->pictureBox24->TabStop = false;
				 this->pictureBox24->Click += gcnew System::EventHandler(this, &game::pictureBox24_Click);
				 // 
				 // pictureBox26
				 // 
				 this->pictureBox26->Location = System::Drawing::Point(50, 117);
				 this->pictureBox26->Name = L"pictureBox26";
				 this->pictureBox26->Size = System::Drawing::Size(100, 50);
				 this->pictureBox26->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox26->TabIndex = 25;
				 this->pictureBox26->TabStop = false;
				 // 
				 // pictureBox27
				 // 
				 this->pictureBox27->Location = System::Drawing::Point(462, 22);
				 this->pictureBox27->Name = L"pictureBox27";
				 this->pictureBox27->Size = System::Drawing::Size(100, 50);
				 this->pictureBox27->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox27->TabIndex = 26;
				 this->pictureBox27->TabStop = false;
				 // 
				 // pictureBox28
				 // 
				 this->pictureBox28->Location = System::Drawing::Point(897, 117);
				 this->pictureBox28->Name = L"pictureBox28";
				 this->pictureBox28->Size = System::Drawing::Size(100, 50);
				 this->pictureBox28->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox28->TabIndex = 27;
				 this->pictureBox28->TabStop = false;
				 // 
				 // pictureBox29
				 // 
				 this->pictureBox29->Enabled = false;
				 this->pictureBox29->Location = System::Drawing::Point(462, 190);
				 this->pictureBox29->Name = L"pictureBox29";
				 this->pictureBox29->Size = System::Drawing::Size(71, 96);
				 this->pictureBox29->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox29->TabIndex = 28;
				 this->pictureBox29->TabStop = false;
				 this->pictureBox29->Click += gcnew System::EventHandler(this, &game::pictureBox29_Click);
				 // 
				 // pictureBox30
				 // 
				 this->pictureBox30->Location = System::Drawing::Point(615, 190);
				 this->pictureBox30->Name = L"pictureBox30";
				 this->pictureBox30->Size = System::Drawing::Size(71, 96);
				 this->pictureBox30->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox30->TabIndex = 29;
				 this->pictureBox30->TabStop = false;
				 this->pictureBox30->Visible = false;
				 this->pictureBox30->Click += gcnew System::EventHandler(this, &game::pictureBox30_Click);
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Location = System::Drawing::Point(47, 448);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(0, 12);
				 this->label1->TabIndex = 30;
				 // 
				 // pictureBox31
				 // 
				 this->pictureBox31->Location = System::Drawing::Point(462, 352);
				 this->pictureBox31->Name = L"pictureBox31";
				 this->pictureBox31->Size = System::Drawing::Size(100, 50);
				 this->pictureBox31->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox31->TabIndex = 31;
				 this->pictureBox31->TabStop = false;
				 // 
				 // pictureBox32
				 // 
				 this->pictureBox32->BackColor = System::Drawing::Color::Yellow;
				 this->pictureBox32->Location = System::Drawing::Point(451, 341);
				 this->pictureBox32->Name = L"pictureBox32";
				 this->pictureBox32->Size = System::Drawing::Size(165, 118);
				 this->pictureBox32->TabIndex = 32;
				 this->pictureBox32->TabStop = false;
				 this->pictureBox32->Visible = false;
				 // 
				 // pictureBox33
				 // 
				 this->pictureBox33->BackColor = System::Drawing::Color::Yellow;
				 this->pictureBox33->Location = System::Drawing::Point(39, 105);
				 this->pictureBox33->Name = L"pictureBox33";
				 this->pictureBox33->Size = System::Drawing::Size(118, 219);
				 this->pictureBox33->TabIndex = 33;
				 this->pictureBox33->TabStop = false;
				 this->pictureBox33->Visible = false;
				 // 
				 // pictureBox34
				 // 
				 this->pictureBox34->BackColor = System::Drawing::Color::Yellow;
				 this->pictureBox34->Location = System::Drawing::Point(451, 11);
				 this->pictureBox34->Name = L"pictureBox34";
				 this->pictureBox34->Size = System::Drawing::Size(165, 118);
				 this->pictureBox34->TabIndex = 34;
				 this->pictureBox34->TabStop = false;
				 this->pictureBox34->Visible = false;
				 // 
				 // pictureBox35
				 // 
				 this->pictureBox35->BackColor = System::Drawing::Color::Yellow;
				 this->pictureBox35->Location = System::Drawing::Point(886, 105);
				 this->pictureBox35->Name = L"pictureBox35";
				 this->pictureBox35->Size = System::Drawing::Size(118, 170);
				 this->pictureBox35->TabIndex = 35;
				 this->pictureBox35->TabStop = false;
				 this->pictureBox35->Visible = false;
				 // 
				 // pictureBox36
				 // 
				 this->pictureBox36->BackColor = System::Drawing::Color::Red;
				 this->pictureBox36->Enabled = false;
				 this->pictureBox36->Location = System::Drawing::Point(47, 473);
				 this->pictureBox36->Name = L"pictureBox36";
				 this->pictureBox36->Size = System::Drawing::Size(77, 102);
				 this->pictureBox36->TabIndex = 36;
				 this->pictureBox36->TabStop = false;
				 this->pictureBox36->Visible = false;
				 // 
				 // pictureBox37
				 // 
				 this->pictureBox37->BackColor = System::Drawing::Color::Red;
				 this->pictureBox37->Enabled = false;
				 this->pictureBox37->Location = System::Drawing::Point(124, 473);
				 this->pictureBox37->Name = L"pictureBox37";
				 this->pictureBox37->Size = System::Drawing::Size(77, 102);
				 this->pictureBox37->TabIndex = 37;
				 this->pictureBox37->TabStop = false;
				 this->pictureBox37->Visible = false;
				 // 
				 // pictureBox38
				 // 
				 this->pictureBox38->BackColor = System::Drawing::Color::Red;
				 this->pictureBox38->Enabled = false;
				 this->pictureBox38->Location = System::Drawing::Point(201, 473);
				 this->pictureBox38->Name = L"pictureBox38";
				 this->pictureBox38->Size = System::Drawing::Size(77, 102);
				 this->pictureBox38->TabIndex = 38;
				 this->pictureBox38->TabStop = false;
				 this->pictureBox38->Visible = false;
				 // 
				 // pictureBox39
				 // 
				 this->pictureBox39->BackColor = System::Drawing::Color::Red;
				 this->pictureBox39->Enabled = false;
				 this->pictureBox39->Location = System::Drawing::Point(278, 473);
				 this->pictureBox39->Name = L"pictureBox39";
				 this->pictureBox39->Size = System::Drawing::Size(77, 102);
				 this->pictureBox39->TabIndex = 39;
				 this->pictureBox39->TabStop = false;
				 this->pictureBox39->Visible = false;
				 // 
				 // pictureBox40
				 // 
				 this->pictureBox40->BackColor = System::Drawing::Color::Red;
				 this->pictureBox40->Enabled = false;
				 this->pictureBox40->Location = System::Drawing::Point(355, 473);
				 this->pictureBox40->Name = L"pictureBox40";
				 this->pictureBox40->Size = System::Drawing::Size(77, 102);
				 this->pictureBox40->TabIndex = 40;
				 this->pictureBox40->TabStop = false;
				 this->pictureBox40->Visible = false;
				 // 
				 // pictureBox41
				 // 
				 this->pictureBox41->BackColor = System::Drawing::Color::Red;
				 this->pictureBox41->Enabled = false;
				 this->pictureBox41->Location = System::Drawing::Point(432, 473);
				 this->pictureBox41->Name = L"pictureBox41";
				 this->pictureBox41->Size = System::Drawing::Size(77, 102);
				 this->pictureBox41->TabIndex = 41;
				 this->pictureBox41->TabStop = false;
				 this->pictureBox41->Visible = false;
				 // 
				 // pictureBox42
				 // 
				 this->pictureBox42->BackColor = System::Drawing::Color::Red;
				 this->pictureBox42->Enabled = false;
				 this->pictureBox42->Location = System::Drawing::Point(509, 473);
				 this->pictureBox42->Name = L"pictureBox42";
				 this->pictureBox42->Size = System::Drawing::Size(77, 102);
				 this->pictureBox42->TabIndex = 42;
				 this->pictureBox42->TabStop = false;
				 this->pictureBox42->Visible = false;
				 // 
				 // pictureBox43
				 // 
				 this->pictureBox43->BackColor = System::Drawing::Color::Red;
				 this->pictureBox43->Enabled = false;
				 this->pictureBox43->Location = System::Drawing::Point(586, 473);
				 this->pictureBox43->Name = L"pictureBox43";
				 this->pictureBox43->Size = System::Drawing::Size(77, 102);
				 this->pictureBox43->TabIndex = 43;
				 this->pictureBox43->TabStop = false;
				 this->pictureBox43->Visible = false;
				 // 
				 // pictureBox44
				 // 
				 this->pictureBox44->BackColor = System::Drawing::Color::Red;
				 this->pictureBox44->Enabled = false;
				 this->pictureBox44->Location = System::Drawing::Point(663, 473);
				 this->pictureBox44->Name = L"pictureBox44";
				 this->pictureBox44->Size = System::Drawing::Size(77, 102);
				 this->pictureBox44->TabIndex = 44;
				 this->pictureBox44->TabStop = false;
				 this->pictureBox44->Visible = false;
				 // 
				 // pictureBox45
				 // 
				 this->pictureBox45->BackColor = System::Drawing::Color::Red;
				 this->pictureBox45->Enabled = false;
				 this->pictureBox45->Location = System::Drawing::Point(740, 473);
				 this->pictureBox45->Name = L"pictureBox45";
				 this->pictureBox45->Size = System::Drawing::Size(77, 102);
				 this->pictureBox45->TabIndex = 45;
				 this->pictureBox45->TabStop = false;
				 this->pictureBox45->Visible = false;
				 // 
				 // pictureBox46
				 // 
				 this->pictureBox46->BackColor = System::Drawing::Color::Red;
				 this->pictureBox46->Enabled = false;
				 this->pictureBox46->Location = System::Drawing::Point(817, 473);
				 this->pictureBox46->Name = L"pictureBox46";
				 this->pictureBox46->Size = System::Drawing::Size(77, 102);
				 this->pictureBox46->TabIndex = 46;
				 this->pictureBox46->TabStop = false;
				 this->pictureBox46->Visible = false;
				 // 
				 // pictureBox47
				 // 
				 this->pictureBox47->BackColor = System::Drawing::Color::Red;
				 this->pictureBox47->Enabled = false;
				 this->pictureBox47->Location = System::Drawing::Point(894, 473);
				 this->pictureBox47->Name = L"pictureBox47";
				 this->pictureBox47->Size = System::Drawing::Size(77, 102);
				 this->pictureBox47->TabIndex = 47;
				 this->pictureBox47->TabStop = false;
				 this->pictureBox47->Visible = false;
				 // 
				 // pictureBox48
				 // 
				 this->pictureBox48->BackColor = System::Drawing::Color::Red;
				 this->pictureBox48->Enabled = false;
				 this->pictureBox48->Location = System::Drawing::Point(47, 575);
				 this->pictureBox48->Name = L"pictureBox48";
				 this->pictureBox48->Size = System::Drawing::Size(77, 102);
				 this->pictureBox48->TabIndex = 48;
				 this->pictureBox48->TabStop = false;
				 this->pictureBox48->Visible = false;
				 // 
				 // pictureBox49
				 // 
				 this->pictureBox49->BackColor = System::Drawing::Color::Red;
				 this->pictureBox49->Enabled = false;
				 this->pictureBox49->Location = System::Drawing::Point(124, 575);
				 this->pictureBox49->Name = L"pictureBox49";
				 this->pictureBox49->Size = System::Drawing::Size(77, 102);
				 this->pictureBox49->TabIndex = 49;
				 this->pictureBox49->TabStop = false;
				 this->pictureBox49->Visible = false;
				 // 
				 // pictureBox50
				 // 
				 this->pictureBox50->BackColor = System::Drawing::Color::Red;
				 this->pictureBox50->Enabled = false;
				 this->pictureBox50->Location = System::Drawing::Point(201, 575);
				 this->pictureBox50->Name = L"pictureBox50";
				 this->pictureBox50->Size = System::Drawing::Size(77, 102);
				 this->pictureBox50->TabIndex = 50;
				 this->pictureBox50->TabStop = false;
				 this->pictureBox50->Visible = false;
				 // 
				 // pictureBox51
				 // 
				 this->pictureBox51->BackColor = System::Drawing::Color::Red;
				 this->pictureBox51->Enabled = false;
				 this->pictureBox51->Location = System::Drawing::Point(278, 575);
				 this->pictureBox51->Name = L"pictureBox51";
				 this->pictureBox51->Size = System::Drawing::Size(77, 102);
				 this->pictureBox51->TabIndex = 51;
				 this->pictureBox51->TabStop = false;
				 this->pictureBox51->Visible = false;
				 // 
				 // pictureBox52
				 // 
				 this->pictureBox52->BackColor = System::Drawing::Color::Red;
				 this->pictureBox52->Enabled = false;
				 this->pictureBox52->Location = System::Drawing::Point(355, 575);
				 this->pictureBox52->Name = L"pictureBox52";
				 this->pictureBox52->Size = System::Drawing::Size(77, 102);
				 this->pictureBox52->TabIndex = 52;
				 this->pictureBox52->TabStop = false;
				 this->pictureBox52->Visible = false;
				 // 
				 // pictureBox53
				 // 
				 this->pictureBox53->BackColor = System::Drawing::Color::Red;
				 this->pictureBox53->Enabled = false;
				 this->pictureBox53->Location = System::Drawing::Point(432, 575);
				 this->pictureBox53->Name = L"pictureBox53";
				 this->pictureBox53->Size = System::Drawing::Size(77, 102);
				 this->pictureBox53->TabIndex = 53;
				 this->pictureBox53->TabStop = false;
				 this->pictureBox53->Visible = false;
				 // 
				 // pictureBox54
				 // 
				 this->pictureBox54->BackColor = System::Drawing::Color::Red;
				 this->pictureBox54->Enabled = false;
				 this->pictureBox54->Location = System::Drawing::Point(509, 575);
				 this->pictureBox54->Name = L"pictureBox54";
				 this->pictureBox54->Size = System::Drawing::Size(77, 102);
				 this->pictureBox54->TabIndex = 54;
				 this->pictureBox54->TabStop = false;
				 this->pictureBox54->Visible = false;
				 // 
				 // pictureBox55
				 // 
				 this->pictureBox55->BackColor = System::Drawing::Color::Red;
				 this->pictureBox55->Enabled = false;
				 this->pictureBox55->Location = System::Drawing::Point(586, 575);
				 this->pictureBox55->Name = L"pictureBox55";
				 this->pictureBox55->Size = System::Drawing::Size(77, 102);
				 this->pictureBox55->TabIndex = 55;
				 this->pictureBox55->TabStop = false;
				 this->pictureBox55->Visible = false;
				 // 
				 // pictureBox56
				 // 
				 this->pictureBox56->BackColor = System::Drawing::Color::Red;
				 this->pictureBox56->Enabled = false;
				 this->pictureBox56->Location = System::Drawing::Point(663, 575);
				 this->pictureBox56->Name = L"pictureBox56";
				 this->pictureBox56->Size = System::Drawing::Size(77, 102);
				 this->pictureBox56->TabIndex = 56;
				 this->pictureBox56->TabStop = false;
				 this->pictureBox56->Visible = false;
				 // 
				 // pictureBox57
				 // 
				 this->pictureBox57->BackColor = System::Drawing::Color::Red;
				 this->pictureBox57->Enabled = false;
				 this->pictureBox57->Location = System::Drawing::Point(740, 575);
				 this->pictureBox57->Name = L"pictureBox57";
				 this->pictureBox57->Size = System::Drawing::Size(77, 102);
				 this->pictureBox57->TabIndex = 57;
				 this->pictureBox57->TabStop = false;
				 this->pictureBox57->Visible = false;
				 // 
				 // pictureBox58
				 // 
				 this->pictureBox58->BackColor = System::Drawing::Color::Red;
				 this->pictureBox58->Enabled = false;
				 this->pictureBox58->Location = System::Drawing::Point(817, 575);
				 this->pictureBox58->Name = L"pictureBox58";
				 this->pictureBox58->Size = System::Drawing::Size(77, 102);
				 this->pictureBox58->TabIndex = 58;
				 this->pictureBox58->TabStop = false;
				 this->pictureBox58->Visible = false;
				 // 
				 // pictureBox59
				 // 
				 this->pictureBox59->BackColor = System::Drawing::Color::Red;
				 this->pictureBox59->Enabled = false;
				 this->pictureBox59->Location = System::Drawing::Point(894, 575);
				 this->pictureBox59->Name = L"pictureBox59";
				 this->pictureBox59->Size = System::Drawing::Size(77, 102);
				 this->pictureBox59->TabIndex = 59;
				 this->pictureBox59->TabStop = false;
				 this->pictureBox59->Visible = false;
				 // 
				 // button1
				 // 
				 this->button1->Location = System::Drawing::Point(990, 581);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(75, 24);
				 this->button1->TabIndex = 60;
				 this->button1->Text = L"Help";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &game::button1_Click);
				 // 
				 // checkBox1
				 // 
				 this->checkBox1->AutoSize = true;
				 this->checkBox1->Location = System::Drawing::Point(983, 559);
				 this->checkBox1->Name = L"checkBox1";
				 this->checkBox1->Size = System::Drawing::Size(99, 16);
				 this->checkBox1->TabIndex = 61;
				 this->checkBox1->Text = L"LAST CARD!!!";
				 this->checkBox1->UseVisualStyleBackColor = true;
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 13, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 this->label2->Location = System::Drawing::Point(441, 167);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(123, 22);
				 this->label2->TabIndex = 62;
				 this->label2->Text = L"STOCKPILE";
				 // 
				 // button2
				 // 
				 this->button2->Location = System::Drawing::Point(990, 613);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(75, 24);
				 this->button2->TabIndex = 63;
				 this->button2->Text = L"Rules";
				 this->button2->UseVisualStyleBackColor = true;
				 this->button2->Click += gcnew System::EventHandler(this, &game::button2_Click);
				 // 
				 // timer1
				 // 
				 this->timer1->Enabled = true;
				 this->timer1->Tick += gcnew System::EventHandler(this, &game::timer1_Tick);
				 // 
				 // timer2
				 // 
				 this->timer2->Interval = 1000;
				 this->timer2->Tick += gcnew System::EventHandler(this, &game::timer2_Tick);
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(136)));
				 this->label3->Location = System::Drawing::Point(9, 7);
				 this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(0, 25);
				 this->label3->TabIndex = 64;
				 // 
				 // button3
				 // 
				 this->button3->Location = System::Drawing::Point(990, 645);
				 this->button3->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
				 this->button3->Name = L"button3";
				 this->button3->Size = System::Drawing::Size(75, 24);
				 this->button3->TabIndex = 65;
				 this->button3->Text = L"Pause";
				 this->button3->UseVisualStyleBackColor = true;
				 this->button3->Click += gcnew System::EventHandler(this, &game::button3_Click);
				 // 
				 // timer3
				 // 
				 this->timer3->Interval = 10;
				 this->timer3->Tick += gcnew System::EventHandler(this, &game::timer3_Tick);
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Bold));
				 this->label4->ForeColor = System::Drawing::Color::Red;
				 this->label4->Location = System::Drawing::Point(446, 312);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(0, 25);
				 this->label4->TabIndex = 66;
				 this->label4->Visible = false;
				 // 
				 // label5
				 // 
				 this->label5->AutoSize = true;
				 this->label5->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->label5->ForeColor = System::Drawing::Color::Red;
				 this->label5->Location = System::Drawing::Point(163, 190);
				 this->label5->Name = L"label5";
				 this->label5->Size = System::Drawing::Size(0, 25);
				 this->label5->TabIndex = 67;
				 this->label5->Visible = false;
				 // 
				 // label6
				 // 
				 this->label6->AutoSize = true;
				 this->label6->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Bold));
				 this->label6->ForeColor = System::Drawing::Color::Red;
				 this->label6->Location = System::Drawing::Point(364, 111);
				 this->label6->Name = L"label6";
				 this->label6->Size = System::Drawing::Size(0, 25);
				 this->label6->TabIndex = 68;
				 this->label6->Visible = false;
				 // 
				 // label8
				 // 
				 this->label8->AutoSize = true;
				 this->label8->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Bold));
				 this->label8->ForeColor = System::Drawing::Color::Red;
				 this->label8->Location = System::Drawing::Point(566, 312);
				 this->label8->Name = L"label8";
				 this->label8->Size = System::Drawing::Size(0, 25);
				 this->label8->TabIndex = 70;
				 this->label8->Visible = false;
				 // 
				 // label9
				 // 
				 this->label9->AutoSize = true;
				 this->label9->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Bold));
				 this->label9->ForeColor = System::Drawing::Color::Red;
				 this->label9->Location = System::Drawing::Point(163, 219);
				 this->label9->Name = L"label9";
				 this->label9->Size = System::Drawing::Size(0, 25);
				 this->label9->TabIndex = 71;
				 this->label9->Visible = false;
				 // 
				 // label10
				 // 
				 this->label10->AutoSize = true;
				 this->label10->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Bold));
				 this->label10->ForeColor = System::Drawing::Color::Red;
				 this->label10->Location = System::Drawing::Point(364, 140);
				 this->label10->Name = L"label10";
				 this->label10->Size = System::Drawing::Size(0, 25);
				 this->label10->TabIndex = 72;
				 this->label10->Visible = false;
				 // 
				 // label11
				 // 
				 this->label11->AutoSize = true;
				 this->label11->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Bold));
				 this->label11->ForeColor = System::Drawing::Color::Red;
				 this->label11->Location = System::Drawing::Point(778, 219);
				 this->label11->Name = L"label11";
				 this->label11->Size = System::Drawing::Size(0, 25);
				 this->label11->TabIndex = 73;
				 this->label11->Visible = false;
				 // 
				 // label12
				 // 
				 this->label12->AutoSize = true;
				 this->label12->Font = (gcnew System::Drawing::Font(L"Verdana", 13.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 this->label12->Location = System::Drawing::Point(582, 167);
				 this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->label12->Name = L"label12";
				 this->label12->Size = System::Drawing::Size(159, 22);
				 this->label12->TabIndex = 74;
				 this->label12->Text = L"DISCARD-PILE";
				 // 
				 // timer4
				 // 
				 this->timer4->Interval = 1000;
				 this->timer4->Tick += gcnew System::EventHandler(this, &game::timer4_Tick);
				 // 
				 // label15
				 // 
				 this->label15->AutoSize = true;
				 this->label15->Font = (gcnew System::Drawing::Font(L"Maiandra GD", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
				 this->label15->Location = System::Drawing::Point(1004, 505);
				 this->label15->Name = L"label15";
				 this->label15->Size = System::Drawing::Size(0, 24);
				 this->label15->TabIndex = 77;
				 // 
				 // label7
				 // 
				 this->label7->AutoSize = true;
				 this->label7->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Bold));
				 this->label7->ForeColor = System::Drawing::Color::Red;
				 this->label7->Location = System::Drawing::Point(739, 190);
				 this->label7->Name = L"label7";
				 this->label7->Size = System::Drawing::Size(0, 25);
				 this->label7->TabIndex = 69;
				 this->label7->Visible = false;
				 // 
				 // game
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(1094, 695);
				 this->Controls->Add(this->label7);
				 this->Controls->Add(this->label15);
				 this->Controls->Add(this->label12);
				 this->Controls->Add(this->label11);
				 this->Controls->Add(this->label10);
				 this->Controls->Add(this->label9);
				 this->Controls->Add(this->label8);
				 this->Controls->Add(this->label6);
				 this->Controls->Add(this->label5);
				 this->Controls->Add(this->label4);
				 this->Controls->Add(this->button3);
				 this->Controls->Add(this->label3);
				 this->Controls->Add(this->button2);
				 this->Controls->Add(this->label2);
				 this->Controls->Add(this->checkBox1);
				 this->Controls->Add(this->button1);
				 this->Controls->Add(this->pictureBox31);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->pictureBox30);
				 this->Controls->Add(this->pictureBox29);
				 this->Controls->Add(this->pictureBox28);
				 this->Controls->Add(this->pictureBox27);
				 this->Controls->Add(this->pictureBox26);
				 this->Controls->Add(this->pictureBox24);
				 this->Controls->Add(this->pictureBox23);
				 this->Controls->Add(this->pictureBox22);
				 this->Controls->Add(this->pictureBox21);
				 this->Controls->Add(this->pictureBox20);
				 this->Controls->Add(this->pictureBox19);
				 this->Controls->Add(this->pictureBox18);
				 this->Controls->Add(this->pictureBox17);
				 this->Controls->Add(this->pictureBox16);
				 this->Controls->Add(this->pictureBox15);
				 this->Controls->Add(this->pictureBox14);
				 this->Controls->Add(this->pictureBox13);
				 this->Controls->Add(this->pictureBox12);
				 this->Controls->Add(this->pictureBox11);
				 this->Controls->Add(this->pictureBox10);
				 this->Controls->Add(this->pictureBox9);
				 this->Controls->Add(this->pictureBox8);
				 this->Controls->Add(this->pictureBox7);
				 this->Controls->Add(this->pictureBox6);
				 this->Controls->Add(this->pictureBox5);
				 this->Controls->Add(this->pictureBox4);
				 this->Controls->Add(this->pictureBox3);
				 this->Controls->Add(this->pictureBox2);
				 this->Controls->Add(this->pictureBox1);
				 this->Controls->Add(this->pictureBox35);
				 this->Controls->Add(this->pictureBox32);
				 this->Controls->Add(this->pictureBox34);
				 this->Controls->Add(this->pictureBox33);
				 this->Controls->Add(this->pictureBox59);
				 this->Controls->Add(this->pictureBox58);
				 this->Controls->Add(this->pictureBox57);
				 this->Controls->Add(this->pictureBox56);
				 this->Controls->Add(this->pictureBox55);
				 this->Controls->Add(this->pictureBox54);
				 this->Controls->Add(this->pictureBox53);
				 this->Controls->Add(this->pictureBox52);
				 this->Controls->Add(this->pictureBox51);
				 this->Controls->Add(this->pictureBox50);
				 this->Controls->Add(this->pictureBox49);
				 this->Controls->Add(this->pictureBox48);
				 this->Controls->Add(this->pictureBox47);
				 this->Controls->Add(this->pictureBox46);
				 this->Controls->Add(this->pictureBox45);
				 this->Controls->Add(this->pictureBox44);
				 this->Controls->Add(this->pictureBox43);
				 this->Controls->Add(this->pictureBox42);
				 this->Controls->Add(this->pictureBox41);
				 this->Controls->Add(this->pictureBox40);
				 this->Controls->Add(this->pictureBox39);
				 this->Controls->Add(this->pictureBox38);
				 this->Controls->Add(this->pictureBox37);
				 this->Controls->Add(this->pictureBox36);
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
				 this->Name = L"game";
				 this->Text = L"Last Card";
				 this->Load += gcnew System::EventHandler(this, &game::game_Load);
				 this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &game::game_Paint);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox9))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox10))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox11))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox12))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox13))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox14))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox15))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox16))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox17))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox18))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox19))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox20))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox21))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox22))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox23))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox24))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox26))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox27))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox28))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox29))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox30))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox31))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox32))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox33))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox34))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox35))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox36))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox37))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox38))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox39))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox40))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox41))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox42))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox43))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox44))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox45))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox46))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox47))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox48))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox49))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox50))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox51))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox52))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox53))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox54))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox55))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox56))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox57))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox58))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox59))->EndInit();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void pictureBox29_Click(System::Object^  sender, System::EventArgs^ e) {
				 if (!(pIfAI[gamer]))//if this is a player outcard, it will reset the wait time to 6 for next time count down
			{
				timer4->Enabled=false;
				label15->Visible=false;
				waitTime=10;	 				 
				 //FOR PLAYER TO DRAW CARD
				 if((pGame->player+gamer)->returnNumberOfCard() <23){
					 if (!(pGame->getNumberOfCard() == 0 && pGame->getNumberOfUsedCard() == 1)){
						 switch (numgamer){
							case 2:	switch(gamer){
									case 0: drawdown();
											break;
									case 1: drawup();
											break;
									}
									break;
							case 3: switch(gamer){
									case 0: drawdown();
											break;
									case 1: drawleft();
											break;
									case 2: drawright();
											break;
									}
									break;
							case 4:	switch(gamer){
									case 0: drawdown();
											break;
									case 1:	drawleft();
											break;
									case 2: drawup();
											break;
									case 3: drawright();
											break;
									}
							}
					 }
					 pGame->drawCardToPlayer(gamer,pRL->getdraw());
					 if (rev){
						 if (gamer < (numgamer-1))
							 gamer++;
						 else
							 gamer = 0;
					 }
					 else{
						 if (gamer > 0)
							 gamer--;
						 else
							 gamer = (numgamer-1);
					 }
					 pRL->redraw();
					 disable();
					 update();
				 }
				 else{
					 MessageBox::Show("YOU GOT TOO MANY CARD!","ERROR",MessageBoxButtons::OK);
				 }
				 }
			 }
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) { //FOR PLAYER TO CHOOSE WHICH CARD TO DISCARD
				 if (!(pIfAI[gamer])){
				 last = checkBox1->Checked;
				 outcard(*((pGame->player+gamer)->returncard()));
				 }
			 }
	private: System::Void pictureBox2_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (!(pIfAI[gamer])){
				 last = checkBox1->Checked;
				 outcard(*((pGame->player+gamer)->returncard()+1));
				 }
			 }
	private: System::Void pictureBox3_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (!(pIfAI[gamer])){
				 last = checkBox1->Checked;
				 outcard(*((pGame->player+gamer)->returncard()+2));
				 }
			 }
	private: System::Void pictureBox4_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (!(pIfAI[gamer])){
				 last = checkBox1->Checked;
				 outcard(*((pGame->player+gamer)->returncard()+3));
				 }
			 }
	private: System::Void pictureBox5_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (!(pIfAI[gamer])){
				 last = checkBox1->Checked;
				 outcard(*((pGame->player+gamer)->returncard()+4));
				 }
			 }
	private: System::Void pictureBox6_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (!(pIfAI[gamer])){
				 last = checkBox1->Checked;
				 outcard(*((pGame->player+gamer)->returncard()+5));
				 }
			 }
	private: System::Void pictureBox7_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (!(pIfAI[gamer])){
				 last = checkBox1->Checked;
				 outcard(*((pGame->player+gamer)->returncard()+6));
				 }
			 }
	private: System::Void pictureBox8_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (!(pIfAI[gamer])){
					last = checkBox1->Checked;
					outcard(*((pGame->player+gamer)->returncard()+7));
				 }
			 }
	private: System::Void pictureBox9_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (!(pIfAI[gamer])){
				 last = checkBox1->Checked;
				 outcard(*((pGame->player+gamer)->returncard()+8));
				 }
			 }
	private: System::Void pictureBox10_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (!(pIfAI[gamer])){
				 last = checkBox1->Checked;
				 outcard(*((pGame->player+gamer)->returncard()+9));
				 }
			 }
	private: System::Void pictureBox11_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (!(pIfAI[gamer])){
				 last = checkBox1->Checked;
				 outcard(*((pGame->player+gamer)->returncard()+10));
				 }
			 }
	private: System::Void pictureBox12_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (!(pIfAI[gamer])){
				 last = checkBox1->Checked;
				 outcard(*((pGame->player+gamer)->returncard()+11));
				 }
			 }
	private: System::Void pictureBox13_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (!(pIfAI[gamer])){
				 last = checkBox1->Checked;
				 outcard(*((pGame->player+gamer)->returncard()+12));
				 }
			 }
	private: System::Void pictureBox14_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (!(pIfAI[gamer])){
				 last = checkBox1->Checked;
				 outcard(*((pGame->player+gamer)->returncard()+13));
				 }
			 }
	private: System::Void pictureBox15_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (!(pIfAI[gamer])){
				 last = checkBox1->Checked;
				 outcard(*((pGame->player+gamer)->returncard()+14));
				 }
			 }
	private: System::Void pictureBox16_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (!(pIfAI[gamer])){
				 last = checkBox1->Checked;
				 outcard(*((pGame->player+gamer)->returncard()+15));
				 }
			 }
	private: System::Void pictureBox17_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (!(pIfAI[gamer])){
				 last = checkBox1->Checked;
				 outcard(*((pGame->player+gamer)->returncard()+16));
				 }
			 }
	private: System::Void pictureBox18_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (!(pIfAI[gamer])){
				 last = checkBox1->Checked;
				 outcard(*((pGame->player+gamer)->returncard()+17));
				 }
			 }
	private: System::Void pictureBox19_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (!(pIfAI[gamer])){
				 last = checkBox1->Checked;
				 outcard(*((pGame->player+gamer)->returncard()+18));
				 }
			 }
	private: System::Void pictureBox20_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (!(pIfAI[gamer])){
				 last = checkBox1->Checked;
				 outcard(*((pGame->player+gamer)->returncard()+19));
				 }
			 }
	private: System::Void pictureBox21_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (!(pIfAI[gamer])){
				 last = checkBox1->Checked;
				 outcard(*((pGame->player+gamer)->returncard()+20));
				 }
			 }
	private: System::Void pictureBox22_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (!(pIfAI[gamer])){
				 last = checkBox1->Checked;
				 outcard(*((pGame->player+gamer)->returncard()+21));
				 }
			 }
	private: System::Void pictureBox23_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (!(pIfAI[gamer])){
				 last = checkBox1->Checked;
				 outcard(*((pGame->player+gamer)->returncard()+22));
				 }
			 }
	private: System::Void pictureBox24_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (!(pIfAI[gamer])){
				 last = checkBox1->Checked;
				 outcard(*((pGame->player+gamer)->returncard()+23));
				 }
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) { //ADDITIONAL FEATURE! //TO HELP THE PLAYER TO DECIDE WHICH CARD TO DISCARD
				 if (!(pIfAI[gamer])){
				 bool helpCard[24];
				 bool flag=false;//to check if all card can't give out.
				 for (int i = 0; i < (pGame->player+gamer)->returnNumberOfCard(); i++){
					 helpCard[i] = (pRL->allowToDiscard(*(pGame->player[gamer].returncard()+i)) && !(((pGame->player+gamer)->returnNumberOfCard() == 1) && (pGame->card[*(pGame->player[gamer].returncard())].getrank() == 1 || pGame->card[*(pGame->player[gamer].returncard())].getrank() == 2 || pGame->card[*(pGame->player[gamer].returncard())].getrank() == 8 || pGame->card[*(pGame->player[gamer].returncard())].getrank() == 11 || pGame->card[*(pGame->player[gamer].returncard())].getrank() == 14 || pGame->card[*(pGame->player[gamer].returncard())].getrank() == 15)));
					 if(helpCard[i])
						 flag=true;
				 }
				 if(!flag){
					 MessageBox::Show("You cannot give out card,please draw card from the STOCKPILE","",MessageBoxButtons::OK);
				 }
				 switch ((pGame->player+gamer)->returnNumberOfCard()){
					 case 24: if (helpCard[23])
								  pictureBox59->Visible = true;
					 case 23: if (helpCard[22])
								  pictureBox58->Visible = true;
					 case 22: if (helpCard[21])
								  pictureBox57->Visible = true;
					 case 21: if (helpCard[20])
								  pictureBox56->Visible = true;
					 case 20: if (helpCard[19])
								  pictureBox55->Visible = true;
					 case 19: if (helpCard[18])
								  pictureBox54->Visible = true;
					 case 18: if (helpCard[17])
								  pictureBox53->Visible = true;
					 case 17: if (helpCard[16])
								  pictureBox52->Visible = true;
					 case 16: if (helpCard[15])
								  pictureBox51->Visible = true;
					 case 15: if (helpCard[14])
								  pictureBox50->Visible = true;
					 case 14: if (helpCard[13])
								  pictureBox49->Visible = true;
					 case 13: if (helpCard[12])
								  pictureBox48->Visible = true;
					 case 12: if (helpCard[11])
								  pictureBox47->Visible = true;
					 case 11: if (helpCard[10])
								  pictureBox46->Visible = true;
					 case 10: if (helpCard[9])
								  pictureBox45->Visible = true;
					 case 9: if (helpCard[8])
								 pictureBox44->Visible = true;
					 case 8: if (helpCard[7])
								 pictureBox43->Visible = true;
					 case 7: if (helpCard[6])
								 pictureBox42->Visible = true;
					 case 6: if (helpCard[5])
								 pictureBox41->Visible = true;
					 case 5: if (helpCard[4])
								 pictureBox40->Visible = true;
					 case 4: if (helpCard[3])
								 pictureBox39->Visible = true;
					 case 3: if (helpCard[2])
								 pictureBox38->Visible = true;
					 case 2: if (helpCard[1])
								 pictureBox37->Visible = true;
					 case 1: if (helpCard[0])
								 pictureBox36->Visible = true;
				 }
			 }
			 }
	private: System::Void pictureBox30_Click(System::Object^  sender, System::EventArgs^  e) { //ADDITIONAL FEATURE! //TO CHECK BACK THE CARD WHICH HAS BEEN DISCARD
				 timer2->Enabled=false;
				 recCard ^ F2 = gcnew recCard(pGame);
				 F2->ShowDialog();
				 timer2->Enabled=true;
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) { //SHOW RULES OF THE GAME
				 timer2->Enabled=false;
				 timer4->Enabled=false;
				 rules^ Rules=gcnew rules;
				 Rules->ShowDialog();
				 timer2->Enabled=true;
				 timer4->Enabled=true;
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) { 
				 x++;
				 if(numgamer==4){	
					 if(y==6){
						 startVisible();
						 return; //for stop running the code below
					 }

					 switch(z){
						case 0:	drawleft();
								break;
						case 1:	drawup();
								break;
						case 2:	drawright();
								break;
						case 3:	drawdown();
								break;
					 }		

					 if(x%4==0){
					 switch(z){
						case 0:	pictureBox26->Image = Image::FromFile("card\\cardNum\\l"+y+".png");
								break;
						case 1:	pictureBox27->Image = Image::FromFile("card\\cardNum\\v"+y+".png");
								break;
						case 2:	pictureBox28->Image = Image::FromFile("card\\cardNum\\r"+y+".png");
								break;
						case 3:	pictureBox31->Image = Image::FromFile("card\\cardNum\\v"+y+".png");
								y++;
								break;					
					 }
					 z++;
					 if(z>3)
						 z=0;
					 }}
				 else if(numgamer==3){
					 if(y==6){
						 startVisible();
						 return;
					 }


					 switch(z){
						case 0:	drawleft();
								break;
						case 1:	drawright();
								break;
						case 2:	drawdown();
								break;
					 }		

					 if(x%4==0){
					 switch(z){
						 case 0:pictureBox26->Image = Image::FromFile("card\\cardNum\\l"+y+".png");
								break;
						 case 1:pictureBox28->Image = Image::FromFile("card\\cardNum\\r"+y+".png");
								break;
						 case 2:pictureBox31->Image = Image::FromFile("card\\cardNum\\v"+y+".png");
								y++;
								break;
					 }
					 z++;
					 if(z>2)
						 z=0;}
				 }else if(numgamer==2){
					 if(y==6){
						 startVisible();
						 return;
					 }

					  switch(z){
						case 0:	drawup();
								break;
						case 1:	drawdown();
								break;

					 }		
					 if(x%4==0){
					 switch(z){
					 case 0:pictureBox27->Image = Image::FromFile("card\\cardNum\\v"+y+".png");
							break;
					 case 1:pictureBox31->Image = Image::FromFile("card\\cardNum\\v"+y+".png");
							y++;
							break;
					 }
					 z++;
					 if(z>1)
						 z=0;
					 }}

			 }//for start animation
	private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {	//Timer for count down and call the AI to move			 
				 AIOutCard();
				 int m=time/60;
				 int s=time%60;
				 if(s>9){ 
					 label3->Text="0"+m+":"+s;
					 if(m>9)
					 label3->Text=""+m+":"+s;
				 }
				 else{
					 label3->Text="0"+m+":0"+s;
					 if(m>9)
					 label3->Text=""+m+":0"+s;
				 }

				 time--;
				 if(time<0)
					 showWinner();
			 }	
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 timer2->Enabled=false;
				 timer4->Enabled=false;
				 MessageBox::Show("Press OK to continue","Pause",MessageBoxButtons::OK);
				 timer2->Enabled=true;
				 timer4->Enabled=true;
			 }//button for pause the count down
	private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e) {//FOR ANIMATION
				 this->Invalidate();		
			 }
	private: System::Void game_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {//FOR ANIMATION
				 Graphics ^g = e->Graphics;
				 if(dleft){
					 if(cardX<=pictureBox26->Location.X){
						 dleft=false;
						 timer3->Enabled=false;
						 anFlag=true;
					 }
					 if(dleft){
						 cardX-=20;
						 Bitmap ^bp = gcnew Bitmap("card\\b1fh.gif");
						 g->DrawImage(bp,cardX, pictureBox29->Location.Y); 
					 }
				 }
				 if(dright){
					 if(cardX>=pictureBox28->Location.X){
						 dright=false;
						 anFlag=true;
						 timer3->Enabled=false;
					 }
					 if(dright){
						 cardX+=20;
						 Bitmap ^bp = gcnew Bitmap("card\\b1fh.gif");
						 g->DrawImage(bp,cardX, pictureBox29->Location.Y); 
					 }
				 }
				 if(dup){
					 if(cardY<=pictureBox27->Location.Y){
						 dup=false;
						 anFlag=true;
						 timer3->Enabled=false;
					 }
					 if(dup){
						 cardY-=9;
						 Bitmap ^bp = gcnew Bitmap("card\\b1fv.gif");
						 g->DrawImage(bp,pictureBox29->Location.X, cardY); 
					 }
				 }
				 if(ddown){
					 if(cardY>=pictureBox31->Location.Y){
						 ddown=false;
						 anFlag=true;
						 timer3->Enabled=false;
					 }
					 if(ddown){
						 cardY+=9;
						 Bitmap ^bp = gcnew Bitmap("card\\b1fv.gif");
						 g->DrawImage(bp,pictureBox29->Location.X, cardY); 
					 }
				 }		
				 if(gup){
					 if(cardY>=pictureBox30->Location.Y&&cardX>=pictureBox30->Location.X){
						 gup=false;
						 anFlag=true;
						 timer3->Enabled=false;
						 cardName(pRL->getrank(),pRL->getsuit());
						 pictureBox30->Image = Image::FromFile("card\\"+s+r+".gif");
					 }		
					 if(gup){
						 if(cardY<pictureBox30->Location.Y)
							 cardY+=10;
						 if(cardX<pictureBox30->Location.X)
							 cardX+=10;
						 Bitmap ^bp = gcnew Bitmap("card\\b1fv.gif");
						 g->DrawImage(bp,cardX, cardY); 
					 }
				 }
				 if(gright){
					 if(cardY>=pictureBox30->Location.Y&&cardX<=pictureBox30->Location.X){
						 gright=false;
						 anFlag=true;
						 timer3->Enabled=false;
						 cardName(pRL->getrank(),pRL->getsuit());
						 pictureBox30->Image = Image::FromFile("card\\"+s+r+".gif");
					 }	
					 if(gright){
						 if(cardY<pictureBox30->Location.Y)
							 cardY+=10;
						 if(cardX>pictureBox30->Location.X)
							 cardX-=10;
						 Bitmap ^bp = gcnew Bitmap("card\\b1fh.gif");
						 g->DrawImage(bp,cardX, cardY); 
					 }
				 }	
				 if(gleft){
					 if(cardY>=pictureBox30->Location.Y&&cardX>=pictureBox30->Location.X){
						 gleft=false;
						 anFlag=true;
						 timer3->Enabled=false;
						 cardName(pRL->getrank(),pRL->getsuit());
						 pictureBox30->Image = Image::FromFile("card\\"+s+r+".gif");
					 }		
					 if(gleft){
						 if(cardY<pictureBox30->Location.Y)
							 cardY+=30;
						 if(cardX<pictureBox30->Location.X)
							 cardX+=30;
						 Bitmap ^bp = gcnew Bitmap("card\\b1fh.gif");
						 g->DrawImage(bp,cardX, cardY); 
					 }
				 }	
				 if(gdown){
					 if(cardY<=pictureBox30->Location.Y&&cardX>=pictureBox30->Location.X){
						 gdown=false;
						 anFlag=true;
						 timer3->Enabled=false;
						 cardName(pRL->getrank(),pRL->getsuit());
						 pictureBox30->Image = Image::FromFile("card\\"+s+r+".gif");
					 }		
					 if(gdown){
						 if(cardY>pictureBox30->Location.Y)
							 cardY-=10;
						 if(cardX<pictureBox30->Location.X)
							 cardX+=10;
						 Bitmap ^bp = gcnew Bitmap("card\\b1fv.gif");
						 g->DrawImage(bp,cardX, cardY); 
					 }
				 }
			 }
	private: System::Void game_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void timer4_Tick(System::Object^  sender, System::EventArgs^  e) {
			if(discardTime){
			 label15->Visible=true;
			 label15->Text=""+waitTime;
			 if(waitTime<1){
				timer4->Enabled=false;
				label15->Visible=false;
			 	if((pGame->player+gamer)->returnNumberOfCard() <23){
					 if (!(pGame->getNumberOfCard() == 0 && pGame->getNumberOfUsedCard() == 1)){
						 switch (numgamer){
							case 2:	switch(gamer){
									case 0: drawdown();
											break;
									case 1: drawup();
											break;
									}
									break;
							case 3: switch(gamer){
									case 0: drawdown();
											break;
									case 1: drawleft();
											break;
									case 2: drawright();
											break;
									}
									break;
							case 4:	switch(gamer){
									case 0: drawdown();
											break;
									case 1:	drawleft();
											break;
									case 2: drawup();
											break;
									case 3: drawright();
											break;
									}
							}
					 }
					 pGame->drawCardToPlayer(gamer,pRL->getdraw());
					 if (rev){
						 if (gamer < (numgamer-1))
							 gamer++;
						 else
							 gamer = 0;
					 }
					 else{
						 if (gamer > 0)
							 gamer--;
						 else
							 gamer = (numgamer-1);
					 }
					 pRL->redraw();
					 disable();
					 update();
				 }		 
				 waitTime=10;
				 return;
			 }
			 waitTime--;
			}
		}
	};
}