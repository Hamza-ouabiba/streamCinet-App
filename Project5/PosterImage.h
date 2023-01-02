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
	
	public:
		Movie^ movie_;
		Serie^ serie_;
		int index;
		Panel^ panel_;
		PosterImage(int index, Movie^ movie,Panel^ panelCo)
		{
			InitializeComponent();
			movie_ = movie;
			serie_ = gcnew Serie();
			serie_->SetName("");
			this->index = index;

			this->button1->BackgroundImage = movie_->GetPoster();
			this->button1->Text = movie_->GetTitle();
			
			this->panel_ = panelCo;
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
		PosterImage(int index, Serie^ serie, Panel^ panelCo)
		{
			InitializeComponent();
			this->index = index;
			movie_ = gcnew Movie();
			movie_->SetTitle("");
			serie_ = serie;
			
			this->button1->BackgroundImage = serie_->GetPoster();
			this->button1->Text = serie_->GetName();

			this->panel_ = panelCo;
			//
			//TODO: ajoutez ici le code du constructeur
			//
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
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(0, 0);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(267, 357);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PosterImage::button1_Click);
			// 
			// PosterImage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"PosterImage";
			this->Size = System::Drawing::Size(267, 357);
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			this->panel_->Controls->Clear();
			if (movie_->GetTitle() != "")
			{
				ViewMovie^ vm = gcnew ViewMovie(movie_);
				vm->Dock = DockStyle::Fill;
				panel_->Controls->Add(vm);
			}
			else
			{
				ViewMovie^ vs = gcnew ViewMovie(serie_);
				vs->Dock = DockStyle::Fill;
				this->panel_->Controls->Add(vs);
			}
		}
	};
}
