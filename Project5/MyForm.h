#pragma once
#include <curl/curl.h>
#include"json/json.h"
#include <msclr/marshal_cppstd.h>
#include "MyUserControl.h"
#include "Dashboard.h"
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
	/// Description résumée de MyForm
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
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ seriesBtn;

	private: System::Windows::Forms::Button^ moviesBtn;

	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Panel^ panelContent;




	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel3;



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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->seriesBtn = (gcnew System::Windows::Forms::Button());
			this->moviesBtn = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->panelContent = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panelContent->SuspendLayout();
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
			// panel1
			// 
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->seriesBtn);
			this->panel1->Controls->Add(this->moviesBtn);
			this->panel1->Location = System::Drawing::Point(-5, 93);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(252, 950);
			this->panel1->TabIndex = 4;
			this->panel1->UseWaitCursor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(23, 292);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(214, 47);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Top Rated";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->UseWaitCursor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(23, 226);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(214, 47);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Popular";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->UseWaitCursor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(23, 161);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(214, 47);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Latest";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->UseWaitCursor = true;
			// 
			// seriesBtn
			// 
			this->seriesBtn->Location = System::Drawing::Point(23, 91);
			this->seriesBtn->Name = L"seriesBtn";
			this->seriesBtn->Size = System::Drawing::Size(214, 47);
			this->seriesBtn->TabIndex = 1;
			this->seriesBtn->Text = L"Series";
			this->seriesBtn->UseVisualStyleBackColor = true;
			this->seriesBtn->UseWaitCursor = true;
			// 
			// moviesBtn
			// 
			this->moviesBtn->Location = System::Drawing::Point(23, 18);
			this->moviesBtn->Name = L"moviesBtn";
			this->moviesBtn->Size = System::Drawing::Size(214, 47);
			this->moviesBtn->TabIndex = 0;
			this->moviesBtn->Text = L"Movies";
			this->moviesBtn->UseVisualStyleBackColor = true;
			this->moviesBtn->UseWaitCursor = true;
			this->moviesBtn->Click += gcnew System::EventHandler(this, &MyForm::moviesBtn_Click);
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->BackColor = System::Drawing::Color::Black;
			this->panel2->Controls->Add(this->button8);
			this->panel2->Controls->Add(this->button7);
			this->panel2->Controls->Add(this->button6);
			this->panel2->Location = System::Drawing::Point(3, 1);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1485, 53);
			this->panel2->TabIndex = 5;
			this->panel2->UseWaitCursor = true;
			// 
			// button8
			// 
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button8->ForeColor = System::Drawing::Color::Transparent;
			this->button8->Location = System::Drawing::Point(461, 3);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(205, 50);
			this->button8->TabIndex = 2;
			this->button8->Text = L"Discovery";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->UseWaitCursor = true;
			// 
			// button7
			// 
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->ForeColor = System::Drawing::Color::MediumBlue;
			this->button7->Location = System::Drawing::Point(0, 0);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(205, 50);
			this->button7->TabIndex = 1;
			this->button7->Text = L"StreamCinet";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->UseWaitCursor = true;
			// 
			// button6
			// 
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6->ForeColor = System::Drawing::Color::Transparent;
			this->button6->Location = System::Drawing::Point(260, 3);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(205, 50);
			this->button6->TabIndex = 0;
			this->button6->Text = L"Discovery";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->UseWaitCursor = true;
			// 
			// panelContent
			// 
			this->panelContent->Controls->Add(this->label6);
			this->panelContent->Controls->Add(this->flowLayoutPanel3);
			this->panelContent->Location = System::Drawing::Point(253, 93);
			this->panelContent->Name = L"panelContent";
			this->panelContent->Size = System::Drawing::Size(1456, 1017);
			this->panelContent->TabIndex = 6;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->label6->Location = System::Drawing::Point(33, 847);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(133, 25);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Latest Movies";
			this->label6->UseWaitCursor = true;
			// 
			// flowLayoutPanel3
			// 
			this->flowLayoutPanel3->AutoScroll = true;
			this->flowLayoutPanel3->Location = System::Drawing::Point(31, 893);
			this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
			this->flowLayoutPanel3->Size = System::Drawing::Size(1408, 348);
			this->flowLayoutPanel3->TabIndex = 4;
			this->flowLayoutPanel3->UseWaitCursor = true;
			this->flowLayoutPanel3->WrapContents = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1723, 1055);
			this->Controls->Add(this->panelContent);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panelContent->ResumeLayout(false);
			this->panelContent->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		Dashboard^ menu_ = gcnew Dashboard();
		menu_->Dock = DockStyle::Fill;
		this->panelContent->Controls->Clear();
		this->panelContent->Controls->Add(menu_);
	}
	private: System::Void moviesBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		/*string discoverUrl = "https://api.themoviedb.org/3/discover/movie?api_key=10f96818301b77e61d73d48aa20d81f9&page=";
		int indexPage;
		this->panelContent->Controls->Clear();
		FlowLayoutPanel^ flowLayoutPanel1;
		flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel);
		flowLayoutPanel1->AutoScroll = true;
		flowLayoutPanel1->Location = System::Drawing::Point(39, 37);
		flowLayoutPanel1->Dock = DockStyle::Fill;
		flowLayoutPanel1->Name = L"flowLayoutPanel1";
		flowLayoutPanel1->Size = System::Drawing::Size(1397, 888);
		flowLayoutPanel1->TabIndex = 3;
		flowLayoutPanel1->WrapContents = true;
		panelContent->Controls->Add(flowLayoutPanel1);
		for (int i = 1;i <= 1;i++)
		{
			for (int j = 1;j <= 19;j++)
			{
				stringstream ss;
				string indexStri;
				cout << "index page = " << i;
				indexPage = i;
				ss << indexPage;
				ss >> indexStri;
				getInformations(j, discoverUrl, indexStri,flowLayoutPanel1,"title");

			}
		}*/
	}
};
	
}
