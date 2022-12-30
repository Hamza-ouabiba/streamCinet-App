#pragma once
#include "Serie.h"
#include "Movie.h"
#include "ViewMovie.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace Project5 {

	/// <summary>
	/// Description r�sum�e de PosterPlanning
	/// </summary>
	public ref class PosterPlanning : public System::Windows::Forms::UserControl
	{
	private:
		Movie^ movie_;
		Serie^ serie_;
		Panel^ control;
	private: System::Windows::Forms::Button^ button1;
	public:
		PosterPlanning(Movie^ mv,Panel^ control)
		{
			InitializeComponent();
			movie_ = mv;
			this->button1->BackgroundImage = movie_->GetPoster();
			this->control = control;
			serie_ = gcnew Serie();
			serie_->SetName("");
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
		PosterPlanning(Serie^ serie,Panel^control)
		{
			InitializeComponent();
			serie_ = serie;
			movie_ = gcnew Movie();
			this->control = control;
			this->button1->BackgroundImage = serie_->GetPoster();
			movie_->SetTitle("");
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
		/// </summary>
		~PosterPlanning()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button1->Location = System::Drawing::Point(0, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(335, 117);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PosterPlanning::button1_Click);
			// 
			// PosterPlanning
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->button1);
			this->Name = L"PosterPlanning";
			this->Size = System::Drawing::Size(335, 117);
			this->Load += gcnew System::EventHandler(this, &PosterPlanning::PosterPlanning_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void PosterPlanning_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->control->Controls->Clear();
		if (movie_->GetTitle() != "")
		{

			ViewMovie^ vm = gcnew ViewMovie(this->movie_);
			vm->Dock = DockStyle::Fill;
			control->Controls->Add(vm);
		}
		else
		{
			ViewMovie^ vs = gcnew ViewMovie(this->serie_);
			vs->Dock = DockStyle::Fill;
			this->control->Controls->Add(vs);
		}
	}
	};
}
