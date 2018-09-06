#pragma once
#include "signin.h"
#include "newac.h"
#include "ranking.h"
#include "setting.h"

namespace LastCard {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			log = false; //FLAG TO CHECK IF IT HAS BEEN LOGGED IN
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;

	private:
		/// <summary>
		bool log;
		login *pAc;
	private: System::Windows::Forms::Button^  button6;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 12);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Player:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(51, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 12);
			this->label2->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(51, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 12);
			this->label3->TabIndex = 2;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(204, 14);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 12);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Marks:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(238, 14);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 12);
			this->label5->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(71, 47);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(144, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Start New Game";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(71, 79);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(144, 23);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Ranking";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(71, 111);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(144, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Exit";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(200, 162);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 8;
			this->button4->Text = L"Sign in";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(119, 162);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 9;
			this->button5->Text = L"Register";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(12, 162);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(70, 23);
			this->button6->TabIndex = 10;
			this->button6->Text = L"Rules";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(288, 198);
			this->ControlBox = false;
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->Text = L"Last Card";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) { //FOR SIGNIN
				 if (log == true){
					 log = false;
					 button4->Text="Sign in";
					 button5->Enabled = true;
					 button5->Visible = true;
					 label2->Text="";
					 label3->Text="";
					 label5->Text="";
					 delete pAc;
				 }
				 else{
					 pAc = new login;
					 signin ^ F1 = gcnew signin(pAc);
					 F1->ShowDialog();
					 log = ((*pAc).logged() != -1);
					 if (log){
						button4->Text = "Sign out";
						button5->Enabled = false;
						button5->Visible = false;
						label2->Text=Marshal::PtrToStringAnsi((IntPtr)(*pAc).getnick((*pAc).logged()));
						label3->Text=Marshal::PtrToStringAnsi((IntPtr)(*pAc).getun((*pAc).logged()));
						label5->Text=""+(*pAc).getmark((*pAc).logged());
					 }
				 }
			 }
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) { //FOR OPEN THE REGISTRATION WINDOWS
				 pAc = new login;
				 newac ^ AC = gcnew newac(pAc);
				 AC->ShowDialog();
	
				 delete pAc;
			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) { //FOR EXIT //DELETE ALL POINTER
				 if (log)
					 delete pAc;
				 this->Close();
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) { //FOR OPEN THE GAME SETTING
				 if (log){
					 setting ^ Set = gcnew setting(pAc);
					 Set->ShowDialog();
					 label5->Text=""+(*pAc).getmark((*pAc).logged());
				 }
				 else{
					 MessageBox::Show("Please Sign in first!","ERROR",MessageBoxButtons::OK);
				 }
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) { //FOR OPEN THE RANKING WINDOW
				 if (!log){
					pAc = new login;
					ranking ^ Rank = gcnew ranking(pAc);
					Rank->ShowDialog();
					delete pAc;
				 }
				 else{
					ranking ^ Rank = gcnew ranking(pAc);
					Rank->ShowDialog(); 
				 }
			 }
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) { //FOR SHOWING THE RULE				
					rules^ Rules=gcnew rules;
					Rules->ShowDialog();
			 }
	};
}

