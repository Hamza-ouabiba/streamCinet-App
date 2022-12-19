#pragma once
#include "Movie.h"
#include "ViewMovie.h"
#include "Serie.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing::Imaging;
namespace Project5 {
	/// <summary>
	/// Description résumée de MyUserControl
	/// </summary>
	public ref class MyUserControl : public System::Windows::Forms::UserControl
	{
	private:
		Movie^ movie_;
		Serie^ serie_;
		int index;
	public:
		
		MyUserControl(int index,Movie^ movie)
		{
			InitializeComponent();
			this->movie_ = movie;
			this->index = index;
			this->button1->BackgroundImage = movie->GetPoster();
			this->button1->Text = movie->GetTitle();
			serie_ = gcnew Serie();
			serie_->SetName("");
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
		MyUserControl(int index, Serie^ serie)
		{
			InitializeComponent();
			this->serie_ = serie;
			this->index = index;
			this->button1->BackgroundImage = serie->GetPoster();
			this->button1->Text = serie->GetName();
			movie_ = gcnew Movie();
			movie_->SetTitle("");
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::Control;
			this->button1->Location = System::Drawing::Point(0, 0);
			this->button1->Margin = System::Windows::Forms::Padding(10, 0, 10, 10);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(200, 290);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyUserControl::button1_Click);
			// 
			// MyUserControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(10);
			this->Name = L"MyUserControl";
			this->Size = System::Drawing::Size(200, 290);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (movie_->GetTitle() != "")
		{
			ViewMovie^ vm = gcnew ViewMovie(this->movie_);
			vm->Show();
		}
		else
		{
			ViewMovie^ vs = gcnew ViewMovie(this->serie_);
			vs->Show();
		}
	}
	};
}
