#pragma once
#include"DataBaseOperations.h"
#include "UserClass.h" 
namespace Project5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		static UserClass^ User ;
		Login(void)
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
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button2;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ WatchlistName;
	private: System::Windows::Forms::TextBox^ tbConfrimPassword;
	private: System::Windows::Forms::TextBox^ tbPassword;
	private: System::Windows::Forms::TextBox^ tbEmail;
	private: System::Windows::Forms::TextBox^ tbName;
	private: System::Windows::Forms::Label^ lbConfirmPassword;
	private: System::Windows::Forms::Label^ lbPassword;
	private: System::Windows::Forms::Label^ lbEmail;
	private: System::Windows::Forms::Label^ lbPhone;
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
			this->WatchlistName = (gcnew System::Windows::Forms::TextBox());
			this->tbConfrimPassword = (gcnew System::Windows::Forms::TextBox());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->tbEmail = (gcnew System::Windows::Forms::TextBox());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->lbConfirmPassword = (gcnew System::Windows::Forms::Label());
			this->lbPassword = (gcnew System::Windows::Forms::Label());
			this->lbEmail = (gcnew System::Windows::Forms::Label());
			this->lbPhone = (gcnew System::Windows::Forms::Label());
			this->lbName = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(293, 398);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(151, 37);
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
			this->button1->Location = System::Drawing::Point(81, 398);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(151, 37);
			this->button1->TabIndex = 33;
			this->button1->Text = L"Login";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Login::button1_Click);
			// 
			// WatchlistName
			// 
			this->WatchlistName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->WatchlistName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->WatchlistName->Location = System::Drawing::Point(293, 172);
			this->WatchlistName->Multiline = true;
			this->WatchlistName->Name = L"WatchlistName";
			this->WatchlistName->Size = System::Drawing::Size(215, 22);
			this->WatchlistName->TabIndex = 32;
			// 
			// tbConfrimPassword
			// 
			this->tbConfrimPassword->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbConfrimPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbConfrimPassword->Location = System::Drawing::Point(293, 298);
			this->tbConfrimPassword->Name = L"tbConfrimPassword";
			this->tbConfrimPassword->PasswordChar = '*';
			this->tbConfrimPassword->Size = System::Drawing::Size(215, 19);
			this->tbConfrimPassword->TabIndex = 31;
			// 
			// tbPassword
			// 
			this->tbPassword->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPassword->Location = System::Drawing::Point(293, 232);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->PasswordChar = '*';
			this->tbPassword->Size = System::Drawing::Size(215, 19);
			this->tbPassword->TabIndex = 30;
			// 
			// tbEmail
			// 
			this->tbEmail->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbEmail->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbEmail->Location = System::Drawing::Point(293, 127);
			this->tbEmail->Name = L"tbEmail";
			this->tbEmail->Size = System::Drawing::Size(215, 19);
			this->tbEmail->TabIndex = 29;
			// 
			// tbName
			// 
			this->tbName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbName->Location = System::Drawing::Point(293, 68);
			this->tbName->Multiline = true;
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(215, 18);
			this->tbName->TabIndex = 28;
			// 
			// lbConfirmPassword
			// 
			this->lbConfirmPassword->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbConfirmPassword->ForeColor = System::Drawing::Color::White;
			this->lbConfirmPassword->Location = System::Drawing::Point(43, 291);
			this->lbConfirmPassword->Name = L"lbConfirmPassword";
			this->lbConfirmPassword->Size = System::Drawing::Size(278, 31);
			this->lbConfirmPassword->TabIndex = 27;
			this->lbConfirmPassword->Text = L"Confirm the password";
			this->lbConfirmPassword->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbPassword
			// 
			this->lbPassword->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbPassword->ForeColor = System::Drawing::Color::White;
			this->lbPassword->Location = System::Drawing::Point(43, 232);
			this->lbPassword->Name = L"lbPassword";
			this->lbPassword->Size = System::Drawing::Size(278, 31);
			this->lbPassword->TabIndex = 26;
			this->lbPassword->Text = L"Password";
			this->lbPassword->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbEmail
			// 
			this->lbEmail->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbEmail->ForeColor = System::Drawing::Color::White;
			this->lbEmail->Location = System::Drawing::Point(43, 120);
			this->lbEmail->Name = L"lbEmail";
			this->lbEmail->Size = System::Drawing::Size(205, 31);
			this->lbEmail->TabIndex = 25;
			this->lbEmail->Text = L"Email";
			this->lbEmail->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbPhone
			// 
			this->lbPhone->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbPhone->ForeColor = System::Drawing::Color::White;
			this->lbPhone->Location = System::Drawing::Point(43, 177);
			this->lbPhone->Name = L"lbPhone";
			this->lbPhone->Size = System::Drawing::Size(221, 31);
			this->lbPhone->TabIndex = 24;
			this->lbPhone->Text = L"Watch list name";
			this->lbPhone->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbName
			// 
			this->lbName->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbName->ForeColor = System::Drawing::Color::White;
			this->lbName->Location = System::Drawing::Point(43, 56);
			this->lbName->Name = L"lbName";
			this->lbName->Size = System::Drawing::Size(278, 40);
			this->lbName->TabIndex = 23;
			this->lbName->Text = L"User name";
			this->lbName->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->ClientSize = System::Drawing::Size(552, 504);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->WatchlistName);
			this->Controls->Add(this->tbConfrimPassword);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->tbEmail);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->lbConfirmPassword);
			this->Controls->Add(this->lbPassword);
			this->Controls->Add(this->lbEmail);
			this->Controls->Add(this->lbPhone);
			this->Controls->Add(this->lbName);
			this->Name = L"Login";
			this->Text = L"Login";
			this->Load += gcnew System::EventHandler(this, &Login::Login_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Login_Load(System::Object^ sender, System::EventArgs^ e) {



	}

		   bool CheckUser() {

			   try {
				   SqlConnection conx(DataBaseConnection::ConnectionString());
				   conx.Open();

				   MessageBox::Show( User->GetEmail() + " " +  User->GetPassword());

				   String^ Query = "Select ID_USER,ID_WATCH_LIST,PASSWORD,NAME, EMAIL from Users where EMAIL = @Email and PASSWORD = @PASSWORD; ";
				   SqlCommand Cmd(Query, % conx);
				   Cmd.Parameters->AddWithValue("@Email",  User->GetEmail());
				   Cmd.Parameters->AddWithValue("@PASSWORD",  User->GetPassword());

				   SqlDataReader^ reader = Cmd.ExecuteReader();

				   if (reader->HasRows) {

					   while (reader->Read())
					   {
						   User->SetIdUser(Convert::ToInt32(reader["ID_USER"]->ToString()));
						   User->SetIdWatchList(Convert::ToInt32(reader["ID_WATCH_LIST"]->ToString()));
					       User->SetPassword(reader["PASSWORD"]->ToString());
						   User->SetEmail(reader["EMAIL"]->ToString());
						   User->SetUsername(reader["NAME"]->ToString());
						   User->SetWatchListName(DataBaseOperations::GetWatchListName(User->GetIdWatchList()));
					   }
					   reader->Close();


					   conx.Close();
					   return true;
				   }
				   else {

					   MessageBox::Show("user not exist");

				   }

			   }
			   catch (Exception^ ex) {
				   MessageBox::Show(ex->Message);
			   }
			   return false;

		   }

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

			 User = gcnew UserClass();

			 User->SetEmail(tbEmail->Text);
			 User->SetPassword(tbPassword->Text);

			if (CheckUser()) {
				MessageBox::Show("logedin");
				this->Hide();
		 
			}
			else {
				MessageBox::Show("not");
			}
	}
};
}
