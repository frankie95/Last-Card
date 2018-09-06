#pragma once
#include "game.h"

namespace LastCard {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for setting
	/// </summary>
	public ref class setting : public System::Windows::Forms::Form
	{
	public:
		setting(login* pAccount)
		{
			InitializeComponent();
			pAc = pAccount;
			//
			numplay = 1;
			numcomp = 3;
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~setting()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button1;
	protected: 

	private: int numplay, numcomp;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
			 login* pAc;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Player:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 42);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Computer:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 71);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(187, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"* The maximum number of players is 4.";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(146, 149);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &setting::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(90, 18);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(13, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"1";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(90, 42);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(13, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"3";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->button2->Location = System::Drawing::Point(143, 14);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(20, 20);
			this->button2->TabIndex = 8;
			this->button2->Text = L"+";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &setting::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->button3->Location = System::Drawing::Point(169, 14);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(20, 20);
			this->button3->TabIndex = 9;
			this->button3->Text = L"-";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &setting::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->button4->Location = System::Drawing::Point(143, 38);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(20, 20);
			this->button4->TabIndex = 10;
			this->button4->Text = L"+";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &setting::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->button5->Location = System::Drawing::Point(169, 38);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(20, 20);
			this->button5->TabIndex = 11;
			this->button5->Text = L"-";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &setting::button5_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Location = System::Drawing::Point(9, 87);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->groupBox1->Size = System::Drawing::Size(212, 47);
			this->groupBox1->TabIndex = 12;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Gaming Time";
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(122, 21);
			this->radioButton2->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(70, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->Text = L"5 minutes";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(16, 21);
			this->radioButton1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(76, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"10 minutes";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(12, 153);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(112, 17);
			this->checkBox1->TabIndex = 13;
			this->checkBox1->Text = L"Discard Time Limit(10s)";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// setting
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(230, 181);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"setting";
			this->ShowIcon = false;
			this->Text = L"Game Setting";
			this->Load += gcnew System::EventHandler(this, &setting::setting_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 int time;
				 bool discardTime=false;
				 if (radioButton1->Checked)
						time = 600; 
				 if (radioButton2->Checked)
						time = 300; 
				 if (checkBox1->Checked)
					 discardTime=true;
			game ^ Gaming = gcnew game(numplay,numcomp,time,discardTime,pAc);
			Gaming->ShowDialog();
			this->Close();
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 numplay++;
				 if (numplay > 4)
					 numplay = 4;
				 if ((numplay + numcomp) > 4)
					 numcomp = 4 - numplay;
				 label4->Text = "" + numplay;
				 label5->Text = "" + numcomp;
			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 numplay--;
				 if (numplay < 1)
					 numplay = 1;
				 if ((numplay + numcomp) < 2)
					 numcomp = 1;
				 label4->Text = "" + numplay;
				 label5->Text = "" + numcomp;
			 }
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				 numcomp++;
				 if (numcomp > 3)
					 numcomp = 3;
				 if ((numplay + numcomp) > 4)
					 numplay = 4 - numcomp;
				 label4->Text = "" + numplay;
				 label5->Text = "" + numcomp;
			 }
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
				 numcomp--;
				 if (numcomp < 0)
					 numcomp = 0;
				 if ((numplay + numcomp) < 2)
					 numplay = 2;
				 label4->Text = "" + numplay;
				 label5->Text = "" + numcomp;
			}
	private: System::Void setting_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}