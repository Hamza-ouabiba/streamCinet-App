#pragma once  
#include "SignUp.h"
#include "DataBaseOperations.h"
#include "DataBaseConnection.h"
#include "UserClass.h"  
namespace Project5 {

	using namespace System;
	using namespace System::Data::SqlClient;
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
	    static UserClass^ User;
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

	protected:
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::TextBox^ tbPassword;
	private: System::Windows::Forms::TextBox^ tbEmail;


	private: System::Windows::Forms::Label^ lbPassword;
	private: System::Windows::Forms::Label^ lbEmail;

	private: System::Windows::Forms::Button^ button3;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->tbEmail = (gcnew System::Windows::Forms::TextBox());
			this->lbPassword = (gcnew System::Windows::Forms::Label());
			this->lbEmail = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(252, 202);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(151, 37);
			this->button1->TabIndex = 45;
			this->button1->Text = L"Sign Up";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Login::button1_Click);
			// 
			// tbPassword
			// 
			this->tbPassword->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPassword->Location = System::Drawing::Point(232, 123);
			this->tbPassword->Multiline = true;
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->PasswordChar = '*';
			this->tbPassword->Size = System::Drawing::Size(215, 27);
			this->tbPassword->TabIndex = 42;
			// 
			// tbEmail
			// 
			this->tbEmail->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbEmail->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbEmail->Location = System::Drawing::Point(232, 72);
			this->tbEmail->Multiline = true;
			this->tbEmail->Name = L"tbEmail";
			this->tbEmail->Size = System::Drawing::Size(215, 24);
			this->tbEmail->TabIndex = 41;
			this->tbEmail->TextChanged += gcnew System::EventHandler(this, &Login::tbEmail_TextChanged);
			// 
			// lbPassword
			// 
			this->lbPassword->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbPassword->ForeColor = System::Drawing::Color::White;
			this->lbPassword->Location = System::Drawing::Point(56, 123);
			this->lbPassword->Name = L"lbPassword";
			this->lbPassword->Size = System::Drawing::Size(196, 31);
			this->lbPassword->TabIndex = 38;
			this->lbPassword->Text = L"Password";
			this->lbPassword->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbEmail
			// 
			this->lbEmail->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbEmail->ForeColor = System::Drawing::Color::White;
			this->lbEmail->Location = System::Drawing::Point(56, 65);
			this->lbEmail->Name = L"lbEmail";
			this->lbEmail->Size = System::Drawing::Size(205, 31);
			this->lbEmail->TabIndex = 37;
			this->lbEmail->Text = L"Email";
			this->lbEmail->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// button3
			// 
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(61, 202);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(151, 37);
			this->button3->TabIndex = 47;
			this->button3->Text = L"Login";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Login::button3_Click);
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::Disable;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->ClientSize = System::Drawing::Size(478, 286);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->tbEmail);
			this->Controls->Add(this->lbPassword);
			this->Controls->Add(this->lbEmail);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Login";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Login";
			this->Load += gcnew System::EventHandler(this, &Login::Login_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		bool CheckUser() {

			try {
				SqlConnection conx(DataBaseConnection::ConnectionString());
				conx.Open(); 

				String^ Query = "Select ID_USER,PASSWORD,NAME, EMAIL from Users where EMAIL = @Email and PASSWORD = @PASSWORD; ";
				SqlCommand Cmd(Query, % conx);
				Cmd.Parameters->AddWithValue("@Email", User->GetEmail());
				Cmd.Parameters->AddWithValue("@PASSWORD", User->GetPassword());

				SqlDataReader^ reader = Cmd.ExecuteReader();

				if (reader->HasRows) {

					while (reader->Read())
					{
						User->SetIdUser(Convert::ToInt32(reader["ID_USER"]->ToString())); 
						User->SetPassword(reader["PASSWORD"]->ToString());
						User->SetEmail(reader["EMAIL"]->ToString());
						User->SetUsername(reader["NAME"]->ToString()); 
					}
					reader->Close();


					conx.Close();
					return true;
				}
				else {

					MessageBox::Show("user not exist");
					return false;
				}

			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
			return false;

		}
#pragma endregion
	private: System::Void Login_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		 SignUp^ form = gcnew SignUp(); 
		 form->Show();
		 this->Hide();
	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

		User = gcnew UserClass();

		User->SetEmail(tbEmail->Text);
		User->SetPassword(tbPassword->Text);

		if (CheckUser()) {
			MessageBox::Show("loged in");
			this->Hide();  
		}
		else {
			MessageBox::Show("not");
		}

}
private: System::Void tbEmail_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
