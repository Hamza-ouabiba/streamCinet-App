#pragma once
#include "Movie.h"
#include "Serie.h"
#include "ViewMovie.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing::Imaging;
namespace Project5 {

	/// <summary>
	/// Description résumée de PosterImage
	/// </summary>
	public ref class PosterImage : public System::Windows::Forms::UserControl
	{
	private:
		Movie^ movie_;
		Serie^ serie_;
		int index;
		Panel^ panel_;
	public:
		PosterImage(int index, Movie^ movie,Panel^ panelCo)
		{
			InitializeComponent();
			this->movie_ = movie;
			this->index = index;
			this->button1->BackgroundImage = movie->GetPoster();
			this->button1->Text = movie->GetTitle();
			serie_ = gcnew Serie();
			serie_->SetName("");
			this->panel_ = panelCo;
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
		PosterImage(int index, Serie^ serie, Panel^ panelCo)
		{
			InitializeComponent();
			this->serie_ = serie;
			this->index = index;
			this->button1->BackgroundImage = serie->GetPoster();
			this->button1->Text = serie->GetName();
			movie_ = gcnew Movie();
			movie_->SetTitle("");
			this->panel_ = panelCo;
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
	public:
		void setMovieTitle(String^ title)
		{
			this->movie_->SetTitle(title);
		}
		void setSerieTitle(String^ Name)
		{
			this->serie_->SetName(Name);
		}
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~PosterImage()
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
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button1->Location = System::Drawing::Point(0, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(267, 357);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PosterImage::button1_Click);
			// 
			// PosterImage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->button1);
			this->Name = L"PosterImage";
			this->Size = System::Drawing::Size(267, 357);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->panel_->Controls->Clear();
		if (movie_->GetTitle() != "")
		{
			ViewMovie^ vm = gcnew ViewMovie(this->movie_);
			vm->Dock = DockStyle::Fill;
			panel_->Controls->Add(vm);
			//refreshing page maybe to display current adding :: 
			//
		}
		else
		{
			ViewMovie^ vs = gcnew ViewMovie(this->serie_);
			vs->Dock = DockStyle::Fill;
			this->panel_->Controls->Add(vs);
		}
	}
	};
}
