#pragma once
#include "Movie.h"
#include "Serie.h"
namespace Project5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de ViewMovie
	/// </summary>
	public ref class ViewMovie : public System::Windows::Forms::Form
	{
		Movie^ movie_;
		Serie^ serie_;
		bool serie_or_movie;
	public:
		ViewMovie()
		{
			movie_->SetTitle("");
			serie_->SetName("");
		}
		ViewMovie(Movie^ movie)
		{
			InitializeComponent();
			this->movie_ = movie;
			serie_ = gcnew Serie();
			serie_->SetName("");
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
		ViewMovie(Serie^ serie)
		{
			InitializeComponent();
			this->serie_ = serie;
			movie_ = gcnew Movie();
			movie_->SetTitle("");
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~ViewMovie()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ paneImage;



	private: System::Windows::Forms::Panel^ blur;
	private: System::Windows::Forms::Label^ title;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;

	protected:

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
			this->paneImage = (gcnew System::Windows::Forms::Panel());
			this->blur = (gcnew System::Windows::Forms::Panel());
			this->title = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->paneImage->SuspendLayout();
			this->blur->SuspendLayout();
			this->SuspendLayout();
			// 
			// paneImage
			// 
			this->paneImage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->paneImage->Controls->Add(this->blur);
			this->paneImage->Location = System::Drawing::Point(-2, -1);
			this->paneImage->Name = L"paneImage";
			this->paneImage->Size = System::Drawing::Size(1028, 769);
			this->paneImage->TabIndex = 0;
			// 
			// blur
			// 
			this->blur->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->blur->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->blur->Controls->Add(this->title);
			this->blur->Controls->Add(this->button1);
			this->blur->Location = System::Drawing::Point(-2, -1);
			this->blur->Name = L"blur";
			this->blur->Size = System::Drawing::Size(1028, 770);
			this->blur->TabIndex = 0;
			// 
			// title
			// 
			this->title->AutoSize = true;
			this->title->BackColor = System::Drawing::Color::Transparent;
			this->title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->title->ForeColor = System::Drawing::Color::White;
			this->title->Location = System::Drawing::Point(124, 190);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(98, 32);
			this->title->TabIndex = 5;
			this->title->Text = L"label1";
			// 
			// button1
			// 
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(114, 424);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(233, 75);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Add To library";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(31, 782);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 29);
			this->label1->TabIndex = 1;
			this->label1->Text = L"CAST";
			// 
			// ViewMovie
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(1361, 945);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->paneImage);
			this->Name = L"ViewMovie";
			this->Text = L"ViewMovie";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &ViewMovie::ViewMovie_Load);
			this->paneImage->ResumeLayout(false);
			this->blur->ResumeLayout(false);
			this->blur->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ViewMovie_Load(System::Object^ sender, System::EventArgs^ e) {
		if (movie_->GetTitle() != "")
			this->paneImage->BackgroundImage = movie_->GetBakcDrop();
		else
			this->paneImage->BackgroundImage = serie_->GetBakcDrop();
	}
	};
}
