#pragma once
#include <curl/curl.h>
#include"json/json.h"
#include <windows.h>
#include <iostream>
#include<string>
#include"ClassData.h"
#include"MyUserControl.h"
#include "Display.h" 
#include "MyLibrary.h"
using namespace std;
using namespace System::Drawing::Imaging;
using namespace System;
using namespace System::Windows::Forms;
 
namespace Project5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description r�sum�e de MyForm
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
	 
		MyForm(void)
		{
			InitializeComponent();
			
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:




	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button6;

	private: System::Windows::Forms::Panel^ Main_Pannel;
	private: System::Windows::Forms::Panel^ Display_Panel;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;




	protected:
	private:
		/// <summary>
		/// Variable n�cessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�thode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette m�thode avec l'�diteur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->Main_Pannel = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Display_Panel = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->Main_Pannel->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(2, -1);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(156, 746);
			this->panel1->TabIndex = 4;
			// 
			// button5
			// 
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::White;
			this->button5->Location = System::Drawing::Point(9, 291);
			this->button5->Margin = System::Windows::Forms::Padding(2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(140, 38);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Top Rated";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::White;
			this->button4->Location = System::Drawing::Point(9, 234);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(140, 38);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Popular";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(9, 181);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(140, 38);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Latest";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(9, 126);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(140, 38);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Series";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(9, 74);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(140, 38);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Movies";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(76)),
				static_cast<System::Int32>(static_cast<System::Byte>(124)));
			this->panel2->Controls->Add(this->button8);
			this->panel2->Controls->Add(this->button7);
			this->panel2->Controls->Add(this->button6);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(2, 2);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1345, 46);
			this->panel2->TabIndex = 5;
			// 
			// button8
			// 
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button8->ForeColor = System::Drawing::Color::Transparent;
			this->button8->Location = System::Drawing::Point(346, 2);
			this->button8->Margin = System::Windows::Forms::Padding(2);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(154, 41);
			this->button8->TabIndex = 2;
			this->button8->Text = L"My Library";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button7
			// 
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->ForeColor = System::Drawing::Color::MediumBlue;
			this->button7->Location = System::Drawing::Point(0, 0);
			this->button7->Margin = System::Windows::Forms::Padding(2);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(154, 41);
			this->button7->TabIndex = 1;
			this->button7->Text = L"StreamCinet";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6->ForeColor = System::Drawing::Color::Transparent;
			this->button6->Location = System::Drawing::Point(195, 2);
			this->button6->Margin = System::Windows::Forms::Padding(2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(154, 41);
			this->button6->TabIndex = 0;
			this->button6->Text = L"Discovery";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// Main_Pannel
			// 
			this->Main_Pannel->AutoSize = true;
			this->Main_Pannel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->Main_Pannel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->Main_Pannel->Controls->Add(this->tableLayoutPanel1);
			this->Main_Pannel->Controls->Add(this->panel1);
			this->Main_Pannel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Main_Pannel->Location = System::Drawing::Point(0, 0);
			this->Main_Pannel->Name = L"Main_Pannel";
			this->Main_Pannel->Size = System::Drawing::Size(1512, 786);
			this->Main_Pannel->TabIndex = 7;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->panel2, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->Display_Panel, 0, 1);
			this->tableLayoutPanel1->Location = System::Drawing::Point(163, -3);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1349, 785);
			this->tableLayoutPanel1->TabIndex = 8;
			// 
			// Display_Panel
			// 
			this->Display_Panel->AutoScroll = true;
			this->Display_Panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Display_Panel->Location = System::Drawing::Point(3, 53);
			this->Display_Panel->Name = L"Display_Panel";
			this->Display_Panel->Size = System::Drawing::Size(1343, 729);
			this->Display_Panel->TabIndex = 7;
			this->Display_Panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel3_Paint);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1512, 786);
			this->Controls->Add(this->Main_Pannel);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->Main_Pannel->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		 
		 
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	 

		WCHAR path[260];

		GetModuleFileName(NULL, path, 260);

		HWND console = FindWindow(L"ConsoleWindowClass", path);

		if (IsWindow(console)) {
			ShowWindow(console, SW_HIDE);
		}

		this->Display_Panel->Controls->Clear();
		Display^ UC = gcnew Display(Display_Panel);
		this->Display_Panel->Controls->Add(UC);
	 
		
	}
	 
 
private: System::Void flowLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void panel3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Display_Panel->Controls->Clear();
		MyLibrary^ UC = gcnew MyLibrary(Display_Panel);
		this->Display_Panel->Controls->Add(UC);
}
};
	
}
