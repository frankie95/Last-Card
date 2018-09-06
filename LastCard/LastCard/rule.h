#pragma once

namespace LastCard {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for rules
	/// </summary>
	public ref class rules : public System::Windows::Forms::Form
	{
	public:
		rules(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~rules()
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
	private: System::Windows::Forms::Button^  button1;

	private:
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
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(225, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ace: The direction of the play turn will reverse.";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(171, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(97, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Last Card";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 54);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(356, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Two: The next player either draws two cards from the stockpile or discards";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(41, 74);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(267, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L" another two-card  to add up for his next player to draw.";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(15, 94);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(337, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Eight:The current player can specify a suit for the next player to follow.";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(15, 114);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(169, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Jack: The next player skips a turn.";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(15, 134);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(342, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Jokers: Can be used as wild cards, which include  special action cards.";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(15, 154);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(269, 13);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Special-action card must not be the last card to discard.";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(15, 174);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(286, 13);
			this->label9->TabIndex = 8;
			this->label9->Text = L"The first player who discards all cards in hand is the winner.";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::Red;
			this->label10->Location = System::Drawing::Point(15, 194);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(347, 13);
			this->label10->TabIndex = 9;
			this->label10->Text = L"Forgetting declare \"Last Card\"  will lead to a penalty of five cards drawn.";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->ForeColor = System::Drawing::Color::Red;
			this->label11->Location = System::Drawing::Point(15, 214);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(408, 13);
			this->label11->TabIndex = 10;
			this->label11->Text = L"After 5 minutes, the player who has least number of handcard will become the winn" 
				L"er.";
			// 
			// button1
			// 
			this->button1->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button1->Location = System::Drawing::Point(182, 241);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 22);
			this->button1->TabIndex = 11;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// rules
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(439, 270);
			this->Controls->Add(this->button1);
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
			this->Name = L"rules";
			this->Text = L"Rules";
			this->Load += gcnew System::EventHandler(this, &rules::rules_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void rules_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	};
}
