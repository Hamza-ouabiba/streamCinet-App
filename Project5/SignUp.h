#pragma once  
#include "DataBaseConnection.h"


namespace Project5 {

	using namespace System;
	using namespace System::Data::SqlClient;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SignUp
	/// </summary>
	public ref class SignUp : public System::Windows::Forms::Form
	{

		 
	public:

		SignUp(void)
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
		~SignUp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button2;
	protected:
	private: System::Windows::Forms::Button^ button1;


	private: System::Windows::Forms::TextBox^ tbPassword;
	private: System::Windows::Forms::TextBox^ tbEmail;
	private: System::Windows::Forms::TextBox^ tbName;

	private: System::Windows::Forms::Label^ lbPassword;
	private: System::Windows::Forms::Label^ lbEmail;

	private: System::Windows::Forms::Label^ lbName;

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->tbEmail = (gcnew System::Windows::Forms::TextBox());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->lbPassword = (gcnew System::Windows::Forms::Label());
			this->lbEmail = (gcnew System::Windows::Forms::Label());
			this->lbName = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(288, 276);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(159, 37);
			this->button2->TabIndex = 34;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(76, 276);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(159, 37);
			this->button1->TabIndex = 33;
			this->button1->Text = L"Sign Up";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SignUp::button1_Click);
			// 
			// tbPassword
			// 
			this->tbPassword->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPassword->Location = System::Drawing::Point(279, 196);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->PasswordChar = '*';
			this->tbPassword->Size = System::Drawing::Size(223, 19);
			this->tbPassword->TabIndex = 30;
			// 
			// tbEmail
			// 
			this->tbEmail->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbEmail->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbEmail->Location = System::Drawing::Point(288, 128);
			this->tbEmail->Name = L"tbEmail";
			this->tbEmail->Size = System::Drawing::Size(214, 19);
			this->tbEmail->TabIndex = 29;
			// 
			// tbName
			// 
			this->tbName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbName->Location = System::Drawing::Point(288, 83);
			this->tbName->Multiline = true;
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(214, 18);
			this->tbName->TabIndex = 28;
			// 
			// lbPassword
			// 
			this->lbPassword->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbPassword->ForeColor = System::Drawing::Color::White;
			this->lbPassword->Location = System::Drawing::Point(57, 189);
			this->lbPassword->Name = L"lbPassword";
			this->lbPassword->Size = System::Drawing::Size(189, 31);
			this->lbPassword->TabIndex = 26;
			this->lbPassword->Text = L"Password";
			this->lbPassword->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbEmail
			// 
			this->lbEmail->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbEmail->ForeColor = System::Drawing::Color::White;
			this->lbEmail->Location = System::Drawing::Point(57, 128);
			this->lbEmail->Name = L"lbEmail";
			this->lbEmail->Size = System::Drawing::Size(213, 31);
			this->lbEmail->TabIndex = 25;
			this->lbEmail->Text = L"Email";
			this->lbEmail->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbName
			// 
			this->lbName->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbName->ForeColor = System::Drawing::Color::White;
			this->lbName->Location = System::Drawing::Point(57, 71);
			this->lbName->Name = L"lbName";
			this->lbName->Size = System::Drawing::Size(286, 40);
			this->lbName->TabIndex = 23;
			this->lbName->Text = L"User name";
			this->lbName->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// SignUp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->ClientSize = System::Drawing::Size(524, 359);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->tbEmail);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->lbPassword);
			this->Controls->Add(this->lbEmail);
			this->Controls->Add(this->lbName);
			this->Name = L"SignUp";
			this->Text = L"SignUp";
			this->Load += gcnew System::EventHandler(this, &SignUp::SignUp_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void SignUp_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	
		   void AddUser() {
		 
		 
				   try {
				 
					   SqlConnection conx(DataBaseConnection::ConnectionString());
					   conx.Open();
					   String^ Query = "Select EMAIL from Users where EMAIL = @Email; ";
					   SqlCommand Cmd(Query, % conx);
					   Cmd.Parameters->AddWithValue("@Email", tbEmail->Text);

					   SqlDataReader^ reader = Cmd.ExecuteReader();

					   if (reader->RecordsAffected == -1) {

						   reader->Close();

						   String^ Query = "INSERT INTO Users (EMAIL,PASSWORD,NAME) VALUES (@EMAIL,@PASSWORD,@NAME) ; ";
						   SqlCommand Command(Query, % conx);

						   Command.Parameters->AddWithValue("@EMAIL", tbEmail->Text);
						   Command.Parameters->AddWithValue("@PASSWORD", tbPassword->Text);
						   Command.Parameters->AddWithValue("@NAME",  tbName->Text);


						   if (Command.ExecuteNonQuery() ){ 
							   this->Hide(); 
							  
						   }

					   }
					   else {

						   MessageBox::Show("Email already exist!!! ");
					   }


					   conx.Close();

				   }
				   catch (Exception^ ex) {
					   MessageBox::Show(ex->Message);
				   }
			   }

		   private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

			   if (tbEmail->Text != "" && tbPassword->Text != "" && tbName->Text != "") {

				   AddUser();
			   }
		   }
};
	 
}; 
