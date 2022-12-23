#pragma once
#include "ClassData.h"
#include "Movie_UC.h" 

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Project5 {

	/// <summary>
	/// Summary for MyUserControl
	/// </summary>
	public ref class MyUserControl : public System::Windows::Forms::UserControl
	{
	public:
		
		Class_Movie^ Movie;
		Panel^ f;
		MyUserControl(Class_Movie^ MV,Panel ^f)
		{
			InitializeComponent();
			Movie = gcnew Class_Movie(MV);
			this->f = f; 
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyUserControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyUserControl::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(0, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(200, 290);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyUserControl::button1_Click);
			// 
			// MyUserControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->button1);
			this->Name = L"MyUserControl";
			this->Size = System::Drawing::Size(200, 290);
			this->Load += gcnew System::EventHandler(this, &MyUserControl::MyUserControl_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyUserControl_Load(System::Object^ sender, System::EventArgs^ e) {
		this->button1->BackgroundImage = Movie->GetPoster();
		this->button1->Text = Movie->GetTitle();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		f->Controls->Clear();
		Movie_UC ^UC = gcnew Movie_UC(Movie);
		f->Controls->Add(UC);	
		UC->Dock = DockStyle::Fill;
		
	}
	};
}
