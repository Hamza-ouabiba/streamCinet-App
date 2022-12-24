#pragma once
#include "Movie.h"
#include "Serie.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Project5 {

	/// <summary>
	/// Description résumée de ViewMovie
	/// </summary>
	public ref class ViewMovie : public System::Windows::Forms::UserControl
	{
	private:
		Movie^ movie_;
	private: System::Windows::Forms::Panel^ panelImage;
	private: System::Windows::Forms::Panel^ blur;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ title;
	private: System::Windows::Forms::Panel^ panel1;

		   Serie^ serie_;
	public:
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
			this->panelImage = (gcnew System::Windows::Forms::Panel());
			this->blur = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->title = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panelImage->SuspendLayout();
			this->blur->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelImage
			// 
			this->panelImage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panelImage->Controls->Add(this->blur);
			this->panelImage->Location = System::Drawing::Point(0, 0);
			this->panelImage->Name = L"panelImage";
			this->panelImage->Size = System::Drawing::Size(1266, 610);
			this->panelImage->TabIndex = 0;
			// 
			// blur
			// 
			this->blur->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->blur->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->blur->Controls->Add(this->panel1);
			this->blur->Controls->Add(this->button1);
			this->blur->Controls->Add(this->title);
			this->blur->Location = System::Drawing::Point(0, 0);
			this->blur->Name = L"blur";
			this->blur->Size = System::Drawing::Size(1266, 610);
			this->blur->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(155, 214);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(261, 69);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Add to library";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// title
			// 
			this->title->AutoSize = true;
			this->title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->title->ForeColor = System::Drawing::SystemColors::Control;
			this->title->Location = System::Drawing::Point(138, 103);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(92, 25);
			this->title->TabIndex = 0;
			this->title->Text = L"Du texte";
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel1->Location = System::Drawing::Point(901, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(365, 610);
			this->panel1->TabIndex = 2;
			// 
			// ViewMovie
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->Controls->Add(this->panelImage);
			this->Name = L"ViewMovie";
			this->Size = System::Drawing::Size(1266, 610);
			this->Load += gcnew System::EventHandler(this, &ViewMovie::ViewMovie_Load);
			this->panelImage->ResumeLayout(false);
			this->blur->ResumeLayout(false);
			this->blur->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ViewMovie_Load(System::Object^ sender, System::EventArgs^ e) {
		if (movie_->GetTitle() != "")
		{
			this->panelImage->BackgroundImage = movie_->GetBakcDrop();
			this->title->Text = movie_->GetTitle();
			//this->overview->Text = movie_->GetOverview();
		}
		else
		{
			this->title->Text = serie_->GetName();
			this->panelImage->BackgroundImage = serie_->GetBakcDrop();
		}
	}
	};
}
