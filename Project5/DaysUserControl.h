#pragma once
#include<string>
#include<iostream>
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;


namespace Project5 {

	/// <summary>
	/// Description résumée de DaysUserControl
	/// </summary>
	public ref class DaysUserControl : public System::Windows::Forms::UserControl
	{
	private:
		int dayOfweek;
		int mo;
		int year;
		Panel^ panelContent;
	public:
		DaysUserControl(int index)
		{
			InitializeComponent();
			this->dayOfweek = index;
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
		DaysUserControl(int index,int month,int year)
		{
			InitializeComponent();
			this->dayOfweek = index;
			this->mo = month;
			this->year = year;
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
		void setPanel(Panel^ panel)
		{
			this->panelContent = panel;
		}
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~DaysUserControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ days;
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
			this->days = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// days
			// 
			this->days->Dock = System::Windows::Forms::DockStyle::Fill;
			this->days->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->days->Location = System::Drawing::Point(0, 0);
			this->days->Name = L"days";
			this->days->Size = System::Drawing::Size(194, 111);
			this->days->TabIndex = 0;
			this->days->Text = L"1";
			this->days->UseVisualStyleBackColor = true;
			this->days->Click += gcnew System::EventHandler(this, &DaysUserControl::days_Click);
			// 
			// DaysUserControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->days);
			this->Name = L"DaysUserControl";
			this->Size = System::Drawing::Size(194, 111);
			this->Load += gcnew System::EventHandler(this, &DaysUserControl::DaysUserControl_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void DaysUserControl_Load(System::Object^ sender, System::EventArgs^ e) {
			this->days->Text = this->dayOfweek.ToString();
		}
	private: System::Void days_Click(System::Object^ sender, System::EventArgs^ e) {
		panelContent->Controls->Clear();
		MessageBox::Show("today is : " + this->dayOfweek + "/" + this->mo + "/" + this->year);
	}
	};
}
