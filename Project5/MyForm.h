#pragma once
#include <curl/curl.h>
#include"json/json.h"
#include <msclr/marshal_cppstd.h>
#include "PosterImage.h"
#include "DashBoard.h"
#include "DiscoverUser.h"
#include "Library.h"
#include <ctime>
#include <ratio>
#include <chrono>
#include "Calendar_uc.h"

using namespace std;
using namespace std::chrono;
using namespace System::Drawing::Imaging;
using namespace System;
using namespace System::Windows::Forms;
namespace Project5 {
	using namespace System::Timers;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		Mani^ l = gcnew Mani();
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
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ calendarBtn;

	private: System::Windows::Forms::Button^ libraryBtn;
	private: System::Windows::Forms::Button^ menuBtn;

	private: System::Windows::Forms::Button^ discoverBtn;
	private: System::Windows::Forms::Panel^ panelContent;


	protected:
	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->calendarBtn = (gcnew System::Windows::Forms::Button());
			this->libraryBtn = (gcnew System::Windows::Forms::Button());
			this->menuBtn = (gcnew System::Windows::Forms::Button());
			this->discoverBtn = (gcnew System::Windows::Forms::Button());
			this->panelContent = (gcnew System::Windows::Forms::Panel());
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(727, 57);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"label3";
			this->label3->UseWaitCursor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(59, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"label2";
			this->label2->UseWaitCursor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(625, 57);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			this->label1->UseWaitCursor = true;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->Controls->Add(this->calendarBtn);
			this->panel2->Controls->Add(this->libraryBtn);
			this->panel2->Controls->Add(this->menuBtn);
			this->panel2->Controls->Add(this->discoverBtn);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1333, 50);
			this->panel2->TabIndex = 6;
			// 
			// calendarBtn
			// 
			this->calendarBtn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->calendarBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->calendarBtn->ForeColor = System::Drawing::Color::Gold;
			this->calendarBtn->Location = System::Drawing::Point(662, 0);
			this->calendarBtn->Name = L"calendarBtn";
			this->calendarBtn->Size = System::Drawing::Size(205, 53);
			this->calendarBtn->TabIndex = 7;
			this->calendarBtn->Text = L"Calendar";
			this->calendarBtn->UseVisualStyleBackColor = true;
			this->calendarBtn->Click += gcnew System::EventHandler(this, &MyForm::calendarBtn_Click);
			// 
			// libraryBtn
			// 
			this->libraryBtn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->libraryBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->libraryBtn->ForeColor = System::Drawing::Color::Gold;
			this->libraryBtn->Location = System::Drawing::Point(461, 0);
			this->libraryBtn->Name = L"libraryBtn";
			this->libraryBtn->Size = System::Drawing::Size(205, 53);
			this->libraryBtn->TabIndex = 2;
			this->libraryBtn->Text = L"My Library";
			this->libraryBtn->UseVisualStyleBackColor = true;
			this->libraryBtn->Click += gcnew System::EventHandler(this, &MyForm::libraryBtn_Click);
			// 
			// menuBtn
			// 
			this->menuBtn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->menuBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->menuBtn->ForeColor = System::Drawing::Color::Yellow;
			this->menuBtn->Location = System::Drawing::Point(0, 0);
			this->menuBtn->Name = L"menuBtn";
			this->menuBtn->Size = System::Drawing::Size(205, 50);
			this->menuBtn->TabIndex = 1;
			this->menuBtn->Text = L"StreamCinet";
			this->menuBtn->UseVisualStyleBackColor = true;
			this->menuBtn->Click += gcnew System::EventHandler(this, &MyForm::menuBtn_Click);
			// 
			// discoverBtn
			// 
			this->discoverBtn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->discoverBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->discoverBtn->ForeColor = System::Drawing::Color::Gold;
			this->discoverBtn->Location = System::Drawing::Point(260, 0);
			this->discoverBtn->Name = L"discoverBtn";
			this->discoverBtn->Size = System::Drawing::Size(205, 53);
			this->discoverBtn->TabIndex = 0;
			this->discoverBtn->Text = L"Discovery";
			this->discoverBtn->UseVisualStyleBackColor = true;
			this->discoverBtn->Click += gcnew System::EventHandler(this, &MyForm::discoverBtn_Click_1);
			// 
			// panelContent
			// 
			this->panelContent->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelContent->AutoScroll = true;
			this->panelContent->BackColor = System::Drawing::Color::Black;
			this->panelContent->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->panelContent->Location = System::Drawing::Point(3, 57);
			this->panelContent->Name = L"panelContent";
			this->panelContent->Size = System::Drawing::Size(1330, 537);
			this->panelContent->TabIndex = 6;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoScrollMargin = System::Drawing::Size(2, 10);
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1333, 599);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panelContent);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel2->ResumeLayout(false);
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

		DashBoard^ menu_ = gcnew DashBoard(this->panelContent);
		this->panelContent->Controls->Clear();
		menu_->Dock = DockStyle::Fill;
		this->panelContent->Controls->Add(menu_);
	}
	private: System::Void moviesBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void discoverBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void discoverBtn_Click_1(System::Object^ sender, System::EventArgs^ e) {
		high_resolution_clock::time_point start = high_resolution_clock::now();
		DiscoverUser^ du = gcnew DiscoverUser(this->panelContent);
		this->panelContent->Controls->Clear();
		du->Dock = DockStyle::Fill;
		this->panelContent->Controls->Add(du);
		// Stop the timer
		high_resolution_clock::time_point end = high_resolution_clock::now();

		// Calculate the elapsed time
		duration<double> elapsedTime = duration_cast<duration<double>>(end - start);
		// Print the elapsed time
		MessageBox::Show(elapsedTime.count() + " seconds");
	}
	private: System::Void menuBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm_Load(sender, e);
	}
	private: System::Void libraryBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		Library^ lb = gcnew Library(this->panelContent);
		this->panelContent->Controls->Clear();
		lb->Dock = DockStyle::Fill;
		this->panelContent->Controls->Add(lb);
	}
private: System::Void calendarBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	Calendar_uc^ cl = gcnew Calendar_uc(this->panelContent);
	this->panelContent->Controls->Clear();
	cl->Dock = DockStyle::Fill;
	this->panelContent->Controls->Add(cl);
}
};
	
}
