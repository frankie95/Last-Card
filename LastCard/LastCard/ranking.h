#pragma once
#include "newac.h"

namespace LastCard {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for ranking
	/// </summary>
	public ref class ranking : public System::Windows::Forms::Form
	{
	public:
		ranking(login* pAccount)
		{
			InitializeComponent();
			pAc = pAccount;
			rank = new int[50];
			(*pAc).best10(rank);
			
			//
			switch ((*pAc).getnum()){
			default:
			case 10:
			this->label43->Text = Marshal::PtrToStringAnsi((IntPtr)(*pAc).getun(*(rank+9)));
			this->label44->Text = Marshal::PtrToStringAnsi((IntPtr)(*pAc).getnick(*(rank+9)));
			this->label45->Text = ""+(*pAc).getmark(*(rank+9));	
			case 9:
			this->label39->Text = Marshal::PtrToStringAnsi((IntPtr)(*pAc).getun(*(rank+8)));
			this->label40->Text = Marshal::PtrToStringAnsi((IntPtr)(*pAc).getnick(*(rank+8)));
			this->label41->Text = ""+(*pAc).getmark(*(rank+8));
			case 8:
			this->label35->Text = Marshal::PtrToStringAnsi((IntPtr)(*pAc).getun(*(rank+7)));
			this->label36->Text = Marshal::PtrToStringAnsi((IntPtr)(*pAc).getnick(*(rank+7)));
			this->label37->Text = ""+(*pAc).getmark(*(rank+7));
			case 7:
			this->label31->Text = Marshal::PtrToStringAnsi((IntPtr)(*pAc).getun(*(rank+6)));
			this->label32->Text = Marshal::PtrToStringAnsi((IntPtr)(*pAc).getnick(*(rank+6)));
			this->label33->Text = ""+(*pAc).getmark(*(rank+6));
			case 6:
			this->label27->Text = Marshal::PtrToStringAnsi((IntPtr)(*pAc).getun(*(rank+5)));
			this->label28->Text = Marshal::PtrToStringAnsi((IntPtr)(*pAc).getnick(*(rank+5)));
			this->label29->Text = ""+(*pAc).getmark(*(rank+5));
			case 5:
			this->label23->Text = Marshal::PtrToStringAnsi((IntPtr)(*pAc).getun(*(rank+4)));
			this->label24->Text = Marshal::PtrToStringAnsi((IntPtr)(*pAc).getnick(*(rank+4)));
			this->label25->Text = ""+(*pAc).getmark(*(rank+4));
			case 4:
			this->label19->Text = Marshal::PtrToStringAnsi((IntPtr)(*pAc).getun(*(rank+3)));
			this->label20->Text = Marshal::PtrToStringAnsi((IntPtr)(*pAc).getnick(*(rank+3)));
			this->label21->Text = ""+(*pAc).getmark(*(rank+3));
			case 3:
			this->label15->Text = Marshal::PtrToStringAnsi((IntPtr)(*pAc).getun(*(rank+2)));
			this->label16->Text = Marshal::PtrToStringAnsi((IntPtr)(*pAc).getnick(*(rank+2)));
			this->label17->Text = ""+(*pAc).getmark(*(rank+2));
			case 2:
			this->label11->Text = Marshal::PtrToStringAnsi((IntPtr)(*pAc).getun(*(rank+1)));
			this->label12->Text = Marshal::PtrToStringAnsi((IntPtr)(*pAc).getnick(*(rank+1)));
			this->label13->Text = ""+(*pAc).getmark(*(rank+1));
			case 1:
			this->label7->Text = Marshal::PtrToStringAnsi((IntPtr)(*pAc).getun(*rank));
			this->label8->Text = Marshal::PtrToStringAnsi((IntPtr)(*pAc).getnick(*rank));
			this->label9->Text = ""+(*pAc).getmark(*(rank));
			case 0:
				break;
			}
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ranking()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::Label^  label33;
	private: System::Windows::Forms::Label^  label34;
	private: System::Windows::Forms::Label^  label35;
	private: System::Windows::Forms::Label^  label36;
	private: System::Windows::Forms::Label^  label37;
	private: System::Windows::Forms::Label^  label38;
	private: System::Windows::Forms::Label^  label39;
	private: System::Windows::Forms::Label^  label40;
	private: System::Windows::Forms::Label^  label41;
	private: System::Windows::Forms::Label^  label42;
	private: System::Windows::Forms::Label^  label43;
	private: System::Windows::Forms::Label^  label44;
	private: System::Windows::Forms::Label^  label45;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		int* rank;
		login* pAc;
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
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(51, 4);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(182, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"TOP TEN PLAYERS";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 37);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(24, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"No.";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(68, 37);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(55, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Username";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(159, 37);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(60, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Nick Name";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(242, 37);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(31, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Mark";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(15, 56);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(13, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"1";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(68, 56);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(10, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"-";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(159, 56);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(10, 13);
			this->label8->TabIndex = 7;
			this->label8->Text = L"-";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(242, 56);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(10, 13);
			this->label9->TabIndex = 8;
			this->label9->Text = L"-";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(15, 79);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(13, 13);
			this->label10->TabIndex = 9;
			this->label10->Text = L"2";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(68, 79);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(10, 13);
			this->label11->TabIndex = 10;
			this->label11->Text = L"-";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(159, 79);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(10, 13);
			this->label12->TabIndex = 11;
			this->label12->Text = L"-";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(242, 79);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(10, 13);
			this->label13->TabIndex = 12;
			this->label13->Text = L"-";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(15, 102);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(13, 13);
			this->label14->TabIndex = 13;
			this->label14->Text = L"3";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(68, 102);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(10, 13);
			this->label15->TabIndex = 14;
			this->label15->Text = L"-";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(159, 102);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(10, 13);
			this->label16->TabIndex = 15;
			this->label16->Text = L"-";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(242, 102);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(10, 13);
			this->label17->TabIndex = 16;
			this->label17->Text = L"-";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(15, 125);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(13, 13);
			this->label18->TabIndex = 17;
			this->label18->Text = L"4";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(68, 125);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(10, 13);
			this->label19->TabIndex = 18;
			this->label19->Text = L"-";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(159, 125);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(10, 13);
			this->label20->TabIndex = 19;
			this->label20->Text = L"-";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(242, 125);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(10, 13);
			this->label21->TabIndex = 20;
			this->label21->Text = L"-";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(15, 147);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(13, 13);
			this->label22->TabIndex = 21;
			this->label22->Text = L"5";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(68, 147);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(10, 13);
			this->label23->TabIndex = 22;
			this->label23->Text = L"-";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(159, 147);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(10, 13);
			this->label24->TabIndex = 23;
			this->label24->Text = L"-";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(242, 147);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(10, 13);
			this->label25->TabIndex = 24;
			this->label25->Text = L"-";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(15, 170);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(13, 13);
			this->label26->TabIndex = 25;
			this->label26->Text = L"6";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(68, 170);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(10, 13);
			this->label27->TabIndex = 26;
			this->label27->Text = L"-";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(159, 170);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(10, 13);
			this->label28->TabIndex = 27;
			this->label28->Text = L"-";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(242, 170);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(10, 13);
			this->label29->TabIndex = 28;
			this->label29->Text = L"-";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(15, 193);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(13, 13);
			this->label30->TabIndex = 29;
			this->label30->Text = L"7";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(68, 193);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(10, 13);
			this->label31->TabIndex = 30;
			this->label31->Text = L"-";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(159, 193);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(10, 13);
			this->label32->TabIndex = 31;
			this->label32->Text = L"-";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(242, 193);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(10, 13);
			this->label33->TabIndex = 32;
			this->label33->Text = L"-";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(15, 216);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(13, 13);
			this->label34->TabIndex = 33;
			this->label34->Text = L"8";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(68, 216);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(10, 13);
			this->label35->TabIndex = 34;
			this->label35->Text = L"-";
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(159, 216);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(10, 13);
			this->label36->TabIndex = 35;
			this->label36->Text = L"-";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(242, 216);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(10, 13);
			this->label37->TabIndex = 36;
			this->label37->Text = L"-";
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(15, 238);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(13, 13);
			this->label38->TabIndex = 37;
			this->label38->Text = L"9";
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(68, 238);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(10, 13);
			this->label39->TabIndex = 38;
			this->label39->Text = L"-";
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(159, 238);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(10, 13);
			this->label40->TabIndex = 39;
			this->label40->Text = L"-";
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(242, 238);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(10, 13);
			this->label41->TabIndex = 40;
			this->label41->Text = L"-";
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(12, 261);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(19, 13);
			this->label42->TabIndex = 41;
			this->label42->Text = L"10";
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(68, 261);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(10, 13);
			this->label43->TabIndex = 42;
			this->label43->Text = L"-";
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(159, 261);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(10, 13);
			this->label44->TabIndex = 43;
			this->label44->Text = L"-";
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Location = System::Drawing::Point(242, 261);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(10, 13);
			this->label45->TabIndex = 44;
			this->label45->Text = L"-";
			// 
			// ranking
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 284);
			this->Controls->Add(this->label45);
			this->Controls->Add(this->label44);
			this->Controls->Add(this->label43);
			this->Controls->Add(this->label42);
			this->Controls->Add(this->label41);
			this->Controls->Add(this->label40);
			this->Controls->Add(this->label39);
			this->Controls->Add(this->label38);
			this->Controls->Add(this->label37);
			this->Controls->Add(this->label36);
			this->Controls->Add(this->label35);
			this->Controls->Add(this->label34);
			this->Controls->Add(this->label33);
			this->Controls->Add(this->label32);
			this->Controls->Add(this->label31);
			this->Controls->Add(this->label30);
			this->Controls->Add(this->label29);
			this->Controls->Add(this->label28);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"ranking";
			this->Text = L"Ranking";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
