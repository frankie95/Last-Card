#pragma once
#include "newac.h"
#include "lastcard.h"

namespace LastCard {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	/// <summary>
	/// Summary for winner
	/// </summary>
	public ref class winner : public System::Windows::Forms::Form
	{
	public:
		winner(login * pAccount,OperationOfCardGame* oG,int human,int totalGamer )
		{
			InitializeComponent();
			pAc=pAccount;
			og=oG;
			player=human;
			computer=totalGamer-player;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~winner()
		{	
			if (components)
			{
				delete components;
			}
		}

	private:
		login * pAc;
		OperationOfCardGame* og; 
		int player;
		int computer;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(29, 36);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Player1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(201, 36);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(12, 15);
			this->label2->TabIndex = 1;
			this->label2->Text = L"-";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(29, 69);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 15);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Player2";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(201, 69);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(12, 15);
			this->label4->TabIndex = 3;
			this->label4->Text = L"-";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(29, 101);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(49, 15);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Player3";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(201, 101);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(12, 15);
			this->label6->TabIndex = 5;
			this->label6->Text = L"-";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(29, 134);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(49, 15);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Player4";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(201, 134);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(12, 15);
			this->label8->TabIndex = 7;
			this->label8->Text = L"-";
			// 
			// button1
			// 
			this->button1->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button1->Location = System::Drawing::Point(103, 232);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 26);
			this->button1->TabIndex = 8;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(136, 9);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(128, 15);
			this->label9->TabIndex = 9;
			this->label9->Text = L"Number of hand card";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(93, 166);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(48, 15);
			this->label10->TabIndex = 10;
			this->label10->Text = L"label10";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(93, 199);
			this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(48, 15);
			this->label11->TabIndex = 11;
			this->label11->Text = L"label11";
			// 
			// winner
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(310, 288);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"winner";
			this->Text = L"Winner";
			this->Load += gcnew System::EventHandler(this, &winner::winner_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void winner_Load(System::Object^  sender, System::EventArgs^  e) {


				 int  cardNum[4];
				 int playerNum=og->getNumberOfPlayer();
				 cardNum[0]=og->player[0].returnNumberOfCard();
				 cardNum[1]=og->player[1].returnNumberOfCard();
				 switch(playerNum){
				 case 2:label5->Enabled=false;label6->Enabled=false;
							cardNum[2]=54;
				 case 3:label7->Enabled=false;label8->Enabled=false;
							cardNum[3]=54;
				 }
				 String ^ name=Marshal::PtrToStringAnsi((IntPtr)(*pAc).getnick(pAc->logged()));
				 String ^ text=" is the winner!";
			label1->Text=name;
			label2->Text=""+cardNum[0];
			label4->Text=""+cardNum[1];
			 switch(playerNum){
				 case 4:cardNum[3]=og->player[3].returnNumberOfCard();
					    label8->Text=""+cardNum[3];
				case 3:cardNum[2]=og->player[2].returnNumberOfCard();
					   label6->Text=""+cardNum[2];				
				 }
		
	int temp = cardNum[0]; //check max card num,store the max num
    for(int i=1;i<4;i++)
    {
        if(cardNum[i]<temp)
        temp=cardNum[i];
    }


	
	if(cardNum[0]==temp){  pAc->updatemark();
							pAc->update();
					  label10->Text=name+text;
					  label11->Text="The new score is "+(*pAc).getmark((*pAc).logged());

	}else if(cardNum[1]==temp){
			label10->Text=label3->Text+text;
			label11->Visible=false;}
	 else if(cardNum[2]==temp) {
			label10->Text=label5->Text+text;
			label11->Visible=false;}
	 else if(cardNum[3]==temp) {
			label10->Text=label7->Text+text;
			label11->Visible=false;}

			 
			 switch(player){
			case 1: switch(computer){
				    case 3: label7->Text="Computer 3";
				    case 2: label5->Text="Computer 2";
					case 1: label3->Text="Computer 1";	 
					}break;

			case 2:	switch(computer){
				    case 2: label7->Text="Computer 2";
					case 1: label5->Text="Computer 1";	 
					}	break;	 
			case 3:if(computer==1){
						label7->Text="Computer 1";	 
					}	break;	


			 }
			 }

	};
}
