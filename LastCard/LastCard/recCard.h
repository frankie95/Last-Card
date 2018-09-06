#pragma once
#include "suitup.h"

namespace LastCard {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for recCard
	/// </summary>
	public ref class recCard : public System::Windows::Forms::Form
	{
	public:
		void cardName(int a,int b){
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
		recCard(OperationOfCardGame* pOG){
			InitializeComponent();
			pGame = pOG;
			switch (pGame->getNumberOfRecordCard()){
			case 54:	pictureBox54->Enabled = true;
						pictureBox54->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-54)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-54)].getsuit());
						pictureBox54->Image = Image::FromFile("card\\"+s+r+".gif");
			case 53:	pictureBox53->Enabled = true;
						pictureBox53->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-53)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-53)].getsuit());
						pictureBox53->Image = Image::FromFile("card\\"+s+r+".gif");
			case 52:	pictureBox52->Enabled = true;
						pictureBox52->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-52)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-52)].getsuit());
						pictureBox52->Image = Image::FromFile("card\\"+s+r+".gif");
			case 51:	pictureBox51->Enabled = true;
						pictureBox51->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-51)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-51)].getsuit());
						pictureBox51->Image = Image::FromFile("card\\"+s+r+".gif");
			case 50:	pictureBox50->Enabled = true;
						pictureBox50->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-50)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-50)].getsuit());
						pictureBox50->Image = Image::FromFile("card\\"+s+r+".gif");
			case 49:	pictureBox49->Enabled = true;
						pictureBox49->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-49)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-49)].getsuit());
						pictureBox49->Image = Image::FromFile("card\\"+s+r+".gif");
			case 48:	pictureBox48->Enabled = true;
						pictureBox48->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-48)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-48)].getsuit());
						pictureBox48->Image = Image::FromFile("card\\"+s+r+".gif");
			case 47:	pictureBox47->Enabled = true;
						pictureBox47->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-47)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-47)].getsuit());
						pictureBox47->Image = Image::FromFile("card\\"+s+r+".gif");
			case 46:	pictureBox46->Enabled = true;
						pictureBox46->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-46)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-46)].getsuit());
						pictureBox46->Image = Image::FromFile("card\\"+s+r+".gif");
			case 45:	pictureBox45->Enabled = true;
						pictureBox45->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-45)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-45)].getsuit());
						pictureBox45->Image = Image::FromFile("card\\"+s+r+".gif");
			case 44:	pictureBox44->Enabled = true;
						pictureBox44->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-44)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-44)].getsuit());
						pictureBox44->Image = Image::FromFile("card\\"+s+r+".gif");
			case 43:	pictureBox43->Enabled = true;
						pictureBox43->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-43)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-43)].getsuit());
						pictureBox43->Image = Image::FromFile("card\\"+s+r+".gif");
			case 42:	pictureBox42->Enabled = true;
						pictureBox42->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-42)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-42)].getsuit());
						pictureBox42->Image = Image::FromFile("card\\"+s+r+".gif");
			case 41:	pictureBox41->Enabled = true;
						pictureBox41->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-41)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-41)].getsuit());
						pictureBox41->Image = Image::FromFile("card\\"+s+r+".gif");
			case 40:	pictureBox40->Enabled = true;
						pictureBox40->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-40)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-40)].getsuit());
						pictureBox40->Image = Image::FromFile("card\\"+s+r+".gif");
			case 39:	pictureBox39->Enabled = true;
						pictureBox39->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-39)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-39)].getsuit());
						pictureBox39->Image = Image::FromFile("card\\"+s+r+".gif");
			case 38:	pictureBox38->Enabled = true;
						pictureBox38->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-38)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-38)].getsuit());
						pictureBox38->Image = Image::FromFile("card\\"+s+r+".gif");
			case 37:	pictureBox37->Enabled = true;
						pictureBox37->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-37)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-37)].getsuit());
						pictureBox37->Image = Image::FromFile("card\\"+s+r+".gif");
			case 36:	pictureBox36->Enabled = true;
						pictureBox36->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-36)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-36)].getsuit());
						pictureBox36->Image = Image::FromFile("card\\"+s+r+".gif");
			case 35:	pictureBox35->Enabled = true;
						pictureBox35->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-35)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-35)].getsuit());
						pictureBox35->Image = Image::FromFile("card\\"+s+r+".gif");
			case 34:	pictureBox34->Enabled = true;
						pictureBox34->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-34)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-34)].getsuit());
						pictureBox34->Image = Image::FromFile("card\\"+s+r+".gif");
			case 33:	pictureBox33->Enabled = true;
						pictureBox33->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-33)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-33)].getsuit());
						pictureBox33->Image = Image::FromFile("card\\"+s+r+".gif");
			case 32:	pictureBox32->Enabled = true;
						pictureBox32->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-32)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-32)].getsuit());
						pictureBox32->Image = Image::FromFile("card\\"+s+r+".gif");
			case 31:	pictureBox31->Enabled = true;
						pictureBox31->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-31)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-31)].getsuit());
						pictureBox31->Image = Image::FromFile("card\\"+s+r+".gif");
			case 30:	pictureBox30->Enabled = true;
						pictureBox30->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-30)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-30)].getsuit());
						pictureBox30->Image = Image::FromFile("card\\"+s+r+".gif");
			case 29:	pictureBox29->Enabled = true;
						pictureBox29->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-29)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-29)].getsuit());
						pictureBox29->Image = Image::FromFile("card\\"+s+r+".gif");
			case 28:	pictureBox28->Enabled = true;
						pictureBox28->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-28)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-28)].getsuit());
						pictureBox28->Image = Image::FromFile("card\\"+s+r+".gif");
			case 27:	pictureBox27->Enabled = true;
						pictureBox27->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-27)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-27)].getsuit());
						pictureBox27->Image = Image::FromFile("card\\"+s+r+".gif");
			case 26:	pictureBox26->Enabled = true;
						pictureBox26->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-26)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-26)].getsuit());
						pictureBox26->Image = Image::FromFile("card\\"+s+r+".gif");
			case 25:	pictureBox25->Enabled = true;
						pictureBox25->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-25)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-25)].getsuit());
						pictureBox25->Image = Image::FromFile("card\\"+s+r+".gif");
			case 24:	pictureBox24->Enabled = true;
						pictureBox24->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-24)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-24)].getsuit());
						pictureBox24->Image = Image::FromFile("card\\"+s+r+".gif");
			case 23:	pictureBox23->Enabled = true;
						pictureBox23->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-23)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-23)].getsuit());
						pictureBox23->Image = Image::FromFile("card\\"+s+r+".gif");
			case 22:	pictureBox22->Enabled = true;
						pictureBox22->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-22)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-22)].getsuit());
						pictureBox22->Image = Image::FromFile("card\\"+s+r+".gif");
			case 21:	pictureBox21->Enabled = true;
						pictureBox21->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-21)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-21)].getsuit());
						pictureBox21->Image = Image::FromFile("card\\"+s+r+".gif");
			case 20:	pictureBox20->Enabled = true;
						pictureBox20->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-20)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-20)].getsuit());
						pictureBox20->Image = Image::FromFile("card\\"+s+r+".gif");
			case 19:	pictureBox19->Enabled = true;
						pictureBox19->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-19)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-19)].getsuit());
						pictureBox19->Image = Image::FromFile("card\\"+s+r+".gif");
			case 18:	pictureBox18->Enabled = true;
						pictureBox18->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-18)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-18)].getsuit());
						pictureBox18->Image = Image::FromFile("card\\"+s+r+".gif");
			case 17:	pictureBox17->Enabled = true;
						pictureBox17->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-17)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-17)].getsuit());
						pictureBox17->Image = Image::FromFile("card\\"+s+r+".gif");
			case 16:	pictureBox16->Enabled = true;
						pictureBox16->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-16)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-16)].getsuit());
						pictureBox16->Image = Image::FromFile("card\\"+s+r+".gif");
			case 15:	pictureBox15->Enabled = true;
						pictureBox15->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-15)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-15)].getsuit());
						pictureBox15->Image = Image::FromFile("card\\"+s+r+".gif");
			case 14:	pictureBox14->Enabled = true;
						pictureBox14->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-14)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-14)].getsuit());
						pictureBox14->Image = Image::FromFile("card\\"+s+r+".gif");
			case 13:	pictureBox13->Enabled = true;
						pictureBox13->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-13)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-13)].getsuit());
						pictureBox13->Image = Image::FromFile("card\\"+s+r+".gif");
			case 12:	pictureBox12->Enabled = true;
						pictureBox12->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-12)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-12)].getsuit());
						pictureBox12->Image = Image::FromFile("card\\"+s+r+".gif");
			case 11:	pictureBox11->Enabled = true;
						pictureBox11->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-11)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-11)].getsuit());
						pictureBox11->Image = Image::FromFile("card\\"+s+r+".gif");
			case 10:	pictureBox10->Enabled = true;
						pictureBox10->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-10)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-10)].getsuit());
						pictureBox10->Image = Image::FromFile("card\\"+s+r+".gif");
			case 9:		pictureBox9->Enabled = true;
						pictureBox9->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-9)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-9)].getsuit());
						pictureBox9->Image = Image::FromFile("card\\"+s+r+".gif");
			case 8:		pictureBox8->Enabled = true;
						pictureBox8->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-8)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-8)].getsuit());
						pictureBox8->Image = Image::FromFile("card\\"+s+r+".gif");
			case 7:		pictureBox7->Enabled = true;
						pictureBox7->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-7)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-7)].getsuit());
						pictureBox7->Image = Image::FromFile("card\\"+s+r+".gif");
			case 6:		pictureBox6->Enabled = true;
						pictureBox6->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-6)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-6)].getsuit());
						pictureBox6->Image = Image::FromFile("card\\"+s+r+".gif");
			case 5:		pictureBox5->Enabled = true;
						pictureBox5->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-5)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-5)].getsuit());
						pictureBox5->Image = Image::FromFile("card\\"+s+r+".gif");
			case 4:		pictureBox4->Enabled = true;
						pictureBox4->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-4)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-4)].getsuit());
						pictureBox4->Image = Image::FromFile("card\\"+s+r+".gif");
			case 3:		pictureBox3->Enabled = true;
						pictureBox3->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-3)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-3)].getsuit());
						pictureBox3->Image = Image::FromFile("card\\"+s+r+".gif");
			case 2:		pictureBox2->Enabled = true;
						pictureBox2->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-2)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-2)].getsuit());
						pictureBox2->Image = Image::FromFile("card\\"+s+r+".gif");
			case 1:		pictureBox1->Enabled = true;
						pictureBox1->Visible = true;
						cardName(pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-1)].getrank(),pGame->card[*(pGame->getRecordCard()+(pGame->getNumberOfRecordCard())-1)].getsuit());
						pictureBox1->Image = Image::FromFile("card\\"+s+r+".gif");
			}
			//TODO: Add the constructor code here
			//
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~recCard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected: 

	private:
		OperationOfCardGame *pGame;
		String ^s;
		String ^r;
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
	private: System::Windows::Forms::PictureBox^  pictureBox25;
	private: System::Windows::Forms::PictureBox^  pictureBox26;
	private: System::Windows::Forms::PictureBox^  pictureBox27;
	private: System::Windows::Forms::PictureBox^  pictureBox28;
	private: System::Windows::Forms::PictureBox^  pictureBox29;
	private: System::Windows::Forms::PictureBox^  pictureBox30;
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
			 /// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
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
			this->pictureBox25 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox26 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox27 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox28 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox29 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox30 = (gcnew System::Windows::Forms::PictureBox());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox25))->BeginInit();
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
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Enabled = false;
			this->pictureBox1->Location = System::Drawing::Point(13, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(71, 96);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Enabled = false;
			this->pictureBox2->Location = System::Drawing::Point(90, 12);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(71, 96);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Visible = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Enabled = false;
			this->pictureBox3->Location = System::Drawing::Point(166, 12);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(71, 96);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Visible = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Enabled = false;
			this->pictureBox4->Location = System::Drawing::Point(242, 12);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(71, 96);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox4->TabIndex = 3;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Visible = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->Enabled = false;
			this->pictureBox5->Location = System::Drawing::Point(319, 12);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(71, 96);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox5->TabIndex = 4;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Visible = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->Enabled = false;
			this->pictureBox6->Location = System::Drawing::Point(396, 12);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(71, 96);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox6->TabIndex = 5;
			this->pictureBox6->TabStop = false;
			this->pictureBox6->Visible = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->Enabled = false;
			this->pictureBox7->Location = System::Drawing::Point(472, 12);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(71, 96);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox7->TabIndex = 6;
			this->pictureBox7->TabStop = false;
			this->pictureBox7->Visible = false;
			// 
			// pictureBox8
			// 
			this->pictureBox8->Enabled = false;
			this->pictureBox8->Location = System::Drawing::Point(548, 12);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(71, 96);
			this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox8->TabIndex = 7;
			this->pictureBox8->TabStop = false;
			this->pictureBox8->Visible = false;
			// 
			// pictureBox9
			// 
			this->pictureBox9->Enabled = false;
			this->pictureBox9->Location = System::Drawing::Point(625, 12);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(71, 96);
			this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox9->TabIndex = 8;
			this->pictureBox9->TabStop = false;
			this->pictureBox9->Visible = false;
			// 
			// pictureBox10
			// 
			this->pictureBox10->Enabled = false;
			this->pictureBox10->Location = System::Drawing::Point(702, 12);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(71, 96);
			this->pictureBox10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox10->TabIndex = 9;
			this->pictureBox10->TabStop = false;
			this->pictureBox10->Visible = false;
			// 
			// pictureBox11
			// 
			this->pictureBox11->Enabled = false;
			this->pictureBox11->Location = System::Drawing::Point(778, 12);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(71, 96);
			this->pictureBox11->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox11->TabIndex = 10;
			this->pictureBox11->TabStop = false;
			this->pictureBox11->Visible = false;
			// 
			// pictureBox12
			// 
			this->pictureBox12->Enabled = false;
			this->pictureBox12->Location = System::Drawing::Point(854, 12);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(71, 96);
			this->pictureBox12->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox12->TabIndex = 11;
			this->pictureBox12->TabStop = false;
			this->pictureBox12->Visible = false;
			// 
			// pictureBox13
			// 
			this->pictureBox13->Enabled = false;
			this->pictureBox13->Location = System::Drawing::Point(931, 12);
			this->pictureBox13->Name = L"pictureBox13";
			this->pictureBox13->Size = System::Drawing::Size(71, 96);
			this->pictureBox13->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox13->TabIndex = 12;
			this->pictureBox13->TabStop = false;
			this->pictureBox13->Visible = false;
			// 
			// pictureBox14
			// 
			this->pictureBox14->Enabled = false;
			this->pictureBox14->Location = System::Drawing::Point(1008, 12);
			this->pictureBox14->Name = L"pictureBox14";
			this->pictureBox14->Size = System::Drawing::Size(71, 96);
			this->pictureBox14->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox14->TabIndex = 13;
			this->pictureBox14->TabStop = false;
			this->pictureBox14->Visible = false;
			// 
			// pictureBox15
			// 
			this->pictureBox15->Enabled = false;
			this->pictureBox15->Location = System::Drawing::Point(52, 114);
			this->pictureBox15->Name = L"pictureBox15";
			this->pictureBox15->Size = System::Drawing::Size(71, 96);
			this->pictureBox15->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox15->TabIndex = 14;
			this->pictureBox15->TabStop = false;
			this->pictureBox15->Visible = false;
			// 
			// pictureBox16
			// 
			this->pictureBox16->Enabled = false;
			this->pictureBox16->Location = System::Drawing::Point(129, 114);
			this->pictureBox16->Name = L"pictureBox16";
			this->pictureBox16->Size = System::Drawing::Size(71, 96);
			this->pictureBox16->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox16->TabIndex = 15;
			this->pictureBox16->TabStop = false;
			this->pictureBox16->Visible = false;
			// 
			// pictureBox17
			// 
			this->pictureBox17->Enabled = false;
			this->pictureBox17->Location = System::Drawing::Point(205, 114);
			this->pictureBox17->Name = L"pictureBox17";
			this->pictureBox17->Size = System::Drawing::Size(71, 96);
			this->pictureBox17->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox17->TabIndex = 16;
			this->pictureBox17->TabStop = false;
			this->pictureBox17->Visible = false;
			// 
			// pictureBox18
			// 
			this->pictureBox18->Enabled = false;
			this->pictureBox18->Location = System::Drawing::Point(282, 114);
			this->pictureBox18->Name = L"pictureBox18";
			this->pictureBox18->Size = System::Drawing::Size(71, 96);
			this->pictureBox18->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox18->TabIndex = 17;
			this->pictureBox18->TabStop = false;
			this->pictureBox18->Visible = false;
			// 
			// pictureBox19
			// 
			this->pictureBox19->Enabled = false;
			this->pictureBox19->Location = System::Drawing::Point(358, 114);
			this->pictureBox19->Name = L"pictureBox19";
			this->pictureBox19->Size = System::Drawing::Size(71, 96);
			this->pictureBox19->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox19->TabIndex = 18;
			this->pictureBox19->TabStop = false;
			this->pictureBox19->Visible = false;
			// 
			// pictureBox20
			// 
			this->pictureBox20->Enabled = false;
			this->pictureBox20->Location = System::Drawing::Point(435, 114);
			this->pictureBox20->Name = L"pictureBox20";
			this->pictureBox20->Size = System::Drawing::Size(71, 96);
			this->pictureBox20->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox20->TabIndex = 19;
			this->pictureBox20->TabStop = false;
			this->pictureBox20->Visible = false;
			// 
			// pictureBox21
			// 
			this->pictureBox21->Enabled = false;
			this->pictureBox21->Location = System::Drawing::Point(511, 114);
			this->pictureBox21->Name = L"pictureBox21";
			this->pictureBox21->Size = System::Drawing::Size(71, 96);
			this->pictureBox21->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox21->TabIndex = 20;
			this->pictureBox21->TabStop = false;
			this->pictureBox21->Visible = false;
			// 
			// pictureBox22
			// 
			this->pictureBox22->Enabled = false;
			this->pictureBox22->Location = System::Drawing::Point(588, 114);
			this->pictureBox22->Name = L"pictureBox22";
			this->pictureBox22->Size = System::Drawing::Size(71, 96);
			this->pictureBox22->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox22->TabIndex = 21;
			this->pictureBox22->TabStop = false;
			this->pictureBox22->Visible = false;
			// 
			// pictureBox23
			// 
			this->pictureBox23->Enabled = false;
			this->pictureBox23->Location = System::Drawing::Point(664, 114);
			this->pictureBox23->Name = L"pictureBox23";
			this->pictureBox23->Size = System::Drawing::Size(71, 96);
			this->pictureBox23->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox23->TabIndex = 22;
			this->pictureBox23->TabStop = false;
			this->pictureBox23->Visible = false;
			// 
			// pictureBox24
			// 
			this->pictureBox24->Enabled = false;
			this->pictureBox24->Location = System::Drawing::Point(741, 114);
			this->pictureBox24->Name = L"pictureBox24";
			this->pictureBox24->Size = System::Drawing::Size(71, 96);
			this->pictureBox24->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox24->TabIndex = 23;
			this->pictureBox24->TabStop = false;
			this->pictureBox24->Visible = false;
			// 
			// pictureBox25
			// 
			this->pictureBox25->Enabled = false;
			this->pictureBox25->Location = System::Drawing::Point(817, 114);
			this->pictureBox25->Name = L"pictureBox25";
			this->pictureBox25->Size = System::Drawing::Size(71, 96);
			this->pictureBox25->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox25->TabIndex = 24;
			this->pictureBox25->TabStop = false;
			this->pictureBox25->Visible = false;
			// 
			// pictureBox26
			// 
			this->pictureBox26->Enabled = false;
			this->pictureBox26->Location = System::Drawing::Point(894, 114);
			this->pictureBox26->Name = L"pictureBox26";
			this->pictureBox26->Size = System::Drawing::Size(71, 96);
			this->pictureBox26->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox26->TabIndex = 25;
			this->pictureBox26->TabStop = false;
			this->pictureBox26->Visible = false;
			// 
			// pictureBox27
			// 
			this->pictureBox27->Enabled = false;
			this->pictureBox27->Location = System::Drawing::Point(970, 114);
			this->pictureBox27->Name = L"pictureBox27";
			this->pictureBox27->Size = System::Drawing::Size(71, 96);
			this->pictureBox27->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox27->TabIndex = 26;
			this->pictureBox27->TabStop = false;
			this->pictureBox27->Visible = false;
			// 
			// pictureBox28
			// 
			this->pictureBox28->Enabled = false;
			this->pictureBox28->Location = System::Drawing::Point(14, 216);
			this->pictureBox28->Name = L"pictureBox28";
			this->pictureBox28->Size = System::Drawing::Size(71, 96);
			this->pictureBox28->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox28->TabIndex = 27;
			this->pictureBox28->TabStop = false;
			this->pictureBox28->Visible = false;
			// 
			// pictureBox29
			// 
			this->pictureBox29->Enabled = false;
			this->pictureBox29->Location = System::Drawing::Point(90, 216);
			this->pictureBox29->Name = L"pictureBox29";
			this->pictureBox29->Size = System::Drawing::Size(71, 96);
			this->pictureBox29->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox29->TabIndex = 28;
			this->pictureBox29->TabStop = false;
			this->pictureBox29->Visible = false;
			// 
			// pictureBox30
			// 
			this->pictureBox30->Enabled = false;
			this->pictureBox30->Location = System::Drawing::Point(167, 216);
			this->pictureBox30->Name = L"pictureBox30";
			this->pictureBox30->Size = System::Drawing::Size(71, 96);
			this->pictureBox30->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox30->TabIndex = 29;
			this->pictureBox30->TabStop = false;
			this->pictureBox30->Visible = false;
			// 
			// pictureBox31
			// 
			this->pictureBox31->Enabled = false;
			this->pictureBox31->Location = System::Drawing::Point(244, 216);
			this->pictureBox31->Name = L"pictureBox31";
			this->pictureBox31->Size = System::Drawing::Size(71, 96);
			this->pictureBox31->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox31->TabIndex = 30;
			this->pictureBox31->TabStop = false;
			this->pictureBox31->Visible = false;
			// 
			// pictureBox32
			// 
			this->pictureBox32->Enabled = false;
			this->pictureBox32->Location = System::Drawing::Point(320, 216);
			this->pictureBox32->Name = L"pictureBox32";
			this->pictureBox32->Size = System::Drawing::Size(71, 96);
			this->pictureBox32->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox32->TabIndex = 31;
			this->pictureBox32->TabStop = false;
			this->pictureBox32->Visible = false;
			// 
			// pictureBox33
			// 
			this->pictureBox33->Enabled = false;
			this->pictureBox33->Location = System::Drawing::Point(396, 216);
			this->pictureBox33->Name = L"pictureBox33";
			this->pictureBox33->Size = System::Drawing::Size(71, 96);
			this->pictureBox33->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox33->TabIndex = 32;
			this->pictureBox33->TabStop = false;
			this->pictureBox33->Visible = false;
			// 
			// pictureBox34
			// 
			this->pictureBox34->Enabled = false;
			this->pictureBox34->Location = System::Drawing::Point(473, 216);
			this->pictureBox34->Name = L"pictureBox34";
			this->pictureBox34->Size = System::Drawing::Size(71, 96);
			this->pictureBox34->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox34->TabIndex = 33;
			this->pictureBox34->TabStop = false;
			this->pictureBox34->Visible = false;
			// 
			// pictureBox35
			// 
			this->pictureBox35->Enabled = false;
			this->pictureBox35->Location = System::Drawing::Point(550, 216);
			this->pictureBox35->Name = L"pictureBox35";
			this->pictureBox35->Size = System::Drawing::Size(71, 96);
			this->pictureBox35->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox35->TabIndex = 34;
			this->pictureBox35->TabStop = false;
			this->pictureBox35->Visible = false;
			// 
			// pictureBox36
			// 
			this->pictureBox36->Enabled = false;
			this->pictureBox36->Location = System::Drawing::Point(626, 216);
			this->pictureBox36->Name = L"pictureBox36";
			this->pictureBox36->Size = System::Drawing::Size(71, 96);
			this->pictureBox36->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox36->TabIndex = 35;
			this->pictureBox36->TabStop = false;
			this->pictureBox36->Visible = false;
			// 
			// pictureBox37
			// 
			this->pictureBox37->Enabled = false;
			this->pictureBox37->Location = System::Drawing::Point(702, 216);
			this->pictureBox37->Name = L"pictureBox37";
			this->pictureBox37->Size = System::Drawing::Size(71, 96);
			this->pictureBox37->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox37->TabIndex = 36;
			this->pictureBox37->TabStop = false;
			this->pictureBox37->Visible = false;
			// 
			// pictureBox38
			// 
			this->pictureBox38->Enabled = false;
			this->pictureBox38->Location = System::Drawing::Point(779, 216);
			this->pictureBox38->Name = L"pictureBox38";
			this->pictureBox38->Size = System::Drawing::Size(71, 96);
			this->pictureBox38->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox38->TabIndex = 37;
			this->pictureBox38->TabStop = false;
			this->pictureBox38->Visible = false;
			// 
			// pictureBox39
			// 
			this->pictureBox39->Enabled = false;
			this->pictureBox39->Location = System::Drawing::Point(856, 216);
			this->pictureBox39->Name = L"pictureBox39";
			this->pictureBox39->Size = System::Drawing::Size(71, 96);
			this->pictureBox39->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox39->TabIndex = 38;
			this->pictureBox39->TabStop = false;
			this->pictureBox39->Visible = false;
			// 
			// pictureBox40
			// 
			this->pictureBox40->Enabled = false;
			this->pictureBox40->Location = System::Drawing::Point(932, 216);
			this->pictureBox40->Name = L"pictureBox40";
			this->pictureBox40->Size = System::Drawing::Size(71, 96);
			this->pictureBox40->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox40->TabIndex = 39;
			this->pictureBox40->TabStop = false;
			this->pictureBox40->Visible = false;
			// 
			// pictureBox41
			// 
			this->pictureBox41->Enabled = false;
			this->pictureBox41->Location = System::Drawing::Point(1008, 216);
			this->pictureBox41->Name = L"pictureBox41";
			this->pictureBox41->Size = System::Drawing::Size(71, 96);
			this->pictureBox41->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox41->TabIndex = 40;
			this->pictureBox41->TabStop = false;
			this->pictureBox41->Visible = false;
			// 
			// pictureBox42
			// 
			this->pictureBox42->Enabled = false;
			this->pictureBox42->Location = System::Drawing::Point(52, 318);
			this->pictureBox42->Name = L"pictureBox42";
			this->pictureBox42->Size = System::Drawing::Size(71, 96);
			this->pictureBox42->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox42->TabIndex = 41;
			this->pictureBox42->TabStop = false;
			this->pictureBox42->Visible = false;
			// 
			// pictureBox43
			// 
			this->pictureBox43->Enabled = false;
			this->pictureBox43->Location = System::Drawing::Point(129, 318);
			this->pictureBox43->Name = L"pictureBox43";
			this->pictureBox43->Size = System::Drawing::Size(71, 96);
			this->pictureBox43->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox43->TabIndex = 42;
			this->pictureBox43->TabStop = false;
			this->pictureBox43->Visible = false;
			// 
			// pictureBox44
			// 
			this->pictureBox44->Enabled = false;
			this->pictureBox44->Location = System::Drawing::Point(205, 318);
			this->pictureBox44->Name = L"pictureBox44";
			this->pictureBox44->Size = System::Drawing::Size(71, 96);
			this->pictureBox44->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox44->TabIndex = 43;
			this->pictureBox44->TabStop = false;
			this->pictureBox44->Visible = false;
			// 
			// pictureBox45
			// 
			this->pictureBox45->Enabled = false;
			this->pictureBox45->Location = System::Drawing::Point(282, 318);
			this->pictureBox45->Name = L"pictureBox45";
			this->pictureBox45->Size = System::Drawing::Size(71, 96);
			this->pictureBox45->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox45->TabIndex = 44;
			this->pictureBox45->TabStop = false;
			this->pictureBox45->Visible = false;
			// 
			// pictureBox46
			// 
			this->pictureBox46->Enabled = false;
			this->pictureBox46->Location = System::Drawing::Point(358, 318);
			this->pictureBox46->Name = L"pictureBox46";
			this->pictureBox46->Size = System::Drawing::Size(71, 96);
			this->pictureBox46->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox46->TabIndex = 45;
			this->pictureBox46->TabStop = false;
			this->pictureBox46->Visible = false;
			// 
			// pictureBox47
			// 
			this->pictureBox47->Enabled = false;
			this->pictureBox47->Location = System::Drawing::Point(435, 318);
			this->pictureBox47->Name = L"pictureBox47";
			this->pictureBox47->Size = System::Drawing::Size(71, 96);
			this->pictureBox47->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox47->TabIndex = 46;
			this->pictureBox47->TabStop = false;
			this->pictureBox47->Visible = false;
			// 
			// pictureBox48
			// 
			this->pictureBox48->Enabled = false;
			this->pictureBox48->Location = System::Drawing::Point(511, 318);
			this->pictureBox48->Name = L"pictureBox48";
			this->pictureBox48->Size = System::Drawing::Size(71, 96);
			this->pictureBox48->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox48->TabIndex = 47;
			this->pictureBox48->TabStop = false;
			this->pictureBox48->Visible = false;
			// 
			// pictureBox49
			// 
			this->pictureBox49->Enabled = false;
			this->pictureBox49->Location = System::Drawing::Point(588, 318);
			this->pictureBox49->Name = L"pictureBox49";
			this->pictureBox49->Size = System::Drawing::Size(71, 96);
			this->pictureBox49->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox49->TabIndex = 48;
			this->pictureBox49->TabStop = false;
			this->pictureBox49->Visible = false;
			// 
			// pictureBox50
			// 
			this->pictureBox50->Enabled = false;
			this->pictureBox50->Location = System::Drawing::Point(664, 318);
			this->pictureBox50->Name = L"pictureBox50";
			this->pictureBox50->Size = System::Drawing::Size(71, 96);
			this->pictureBox50->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox50->TabIndex = 49;
			this->pictureBox50->TabStop = false;
			this->pictureBox50->Visible = false;
			// 
			// pictureBox51
			// 
			this->pictureBox51->Enabled = false;
			this->pictureBox51->Location = System::Drawing::Point(741, 318);
			this->pictureBox51->Name = L"pictureBox51";
			this->pictureBox51->Size = System::Drawing::Size(71, 96);
			this->pictureBox51->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox51->TabIndex = 50;
			this->pictureBox51->TabStop = false;
			this->pictureBox51->Visible = false;
			// 
			// pictureBox52
			// 
			this->pictureBox52->Enabled = false;
			this->pictureBox52->Location = System::Drawing::Point(817, 318);
			this->pictureBox52->Name = L"pictureBox52";
			this->pictureBox52->Size = System::Drawing::Size(71, 96);
			this->pictureBox52->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox52->TabIndex = 51;
			this->pictureBox52->TabStop = false;
			this->pictureBox52->Visible = false;
			// 
			// pictureBox53
			// 
			this->pictureBox53->Enabled = false;
			this->pictureBox53->Location = System::Drawing::Point(894, 318);
			this->pictureBox53->Name = L"pictureBox53";
			this->pictureBox53->Size = System::Drawing::Size(71, 96);
			this->pictureBox53->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox53->TabIndex = 52;
			this->pictureBox53->TabStop = false;
			this->pictureBox53->Visible = false;
			// 
			// pictureBox54
			// 
			this->pictureBox54->Enabled = false;
			this->pictureBox54->Location = System::Drawing::Point(970, 318);
			this->pictureBox54->Name = L"pictureBox54";
			this->pictureBox54->Size = System::Drawing::Size(71, 96);
			this->pictureBox54->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox54->TabIndex = 53;
			this->pictureBox54->TabStop = false;
			this->pictureBox54->Visible = false;
			// 
			// recCard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1092, 427);
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
			this->Controls->Add(this->pictureBox35);
			this->Controls->Add(this->pictureBox34);
			this->Controls->Add(this->pictureBox33);
			this->Controls->Add(this->pictureBox32);
			this->Controls->Add(this->pictureBox31);
			this->Controls->Add(this->pictureBox30);
			this->Controls->Add(this->pictureBox29);
			this->Controls->Add(this->pictureBox28);
			this->Controls->Add(this->pictureBox27);
			this->Controls->Add(this->pictureBox26);
			this->Controls->Add(this->pictureBox25);
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
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"recCard";
			this->Text = L"Discarding Record";
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox25))->EndInit();
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
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
