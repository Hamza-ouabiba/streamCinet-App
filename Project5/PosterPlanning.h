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
	/// Description résumée de PosterPlanning
	/// </summary>
	public ref class PosterPlanning : public System::Windows::Forms::UserControl
	{
	private:
		Movie^ movie_;
		Serie^ serie_;
		Panel^ control;
		int idPlanning;
	private: System::Windows::Forms::Button^ button1;
	public:
		PosterPlanning(Movie^ mv, Panel^ control,int id)
		{
			InitializeComponent();
			movie_ = mv;
			this->button1->BackgroundImage = movie_->GetPoster();
			this->button1->Text = mv->GetTitle();
			this->idPlanning = id;
			this->control = control;
			serie_ = gcnew Serie();
			serie_->SetName("");
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
		PosterPlanning(Serie^ serie, Panel^ control,int id)
		{
			InitializeComponent();
			serie_ = serie;
			movie_ = gcnew Movie();
			this->idPlanning = id;
			this->control = control;
			this->button1->BackgroundImage = serie_->GetPoster();
			this->button1->Text = serie_->GetName();
			movie_->SetTitle("");
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
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
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container^ components;

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
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Transparent;
			this->button1->Location = System::Drawing::Point(0, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(353, 90);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &PosterPlanning::button1_Click);
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &PosterPlanning::button1_MouseClick);
			//this->button1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &PosterPlanning::button1_MouseDoubleClick);

			// 
			// PosterPlanning
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->button1);
			this->Name = L"PosterPlanning";
			this->Size = System::Drawing::Size(353, 90);
			this->Load += gcnew System::EventHandler(this, &PosterPlanning::PosterPlanning_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void deletePlanningMovie()
	{
		MessageBox::Show("id of planning is : " + this->idPlanning + " and id_movie is : " + this->movie_->GetIdMovie());
		String^ Query2 = "DELETE FROM planning_movie WHERE id = " + this->idPlanning + " " + "and ID_MOVIE = " + this->movie_->GetIdMovie();
		SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
		conx.Open();
		int index = 0;
		SqlCommand Cmd2(Query2, % conx);
		SqlDataReader^ sqlReader2 = Cmd2.ExecuteReader();
	}
	private: void deletePlanningSerie()
	{
		String^ Query2 = "DELETE FROM planning_serie WHERE id = " + this->idPlanning + " " + "and ID_SERIE = " + this->serie_->GetIdSerie();
		SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
		conx.Open();
		int index = 0;
		SqlCommand Cmd2(Query2, % conx);
		SqlDataReader^ sqlReader2 = Cmd2.ExecuteReader();
	}
	private: System::Void PosterPlanning_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		/*this->control->Controls->Clear();
		if (movie_->GetTitle() != "")
		{
			ViewMovie^ vm = gcnew ViewMovie(this->movie_);
			vm->Dock = DockStyle::Fill;
			control->Controls->Add(vm);
			MessageBox::Show("hna");
		}
		else
		{
			ViewMovie^ vs = gcnew ViewMovie(this->serie_);
			vs->Dock = DockStyle::Fill;
			this->control->Controls->Add(vs);
		}*/
	}
	
	private: System::Void button1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (movie_->GetTitle() != "")
		{
			MessageBox::Show("deleting movie");
			deletePlanningMovie();
		}
		else
		{
			MessageBox::Show("deleting serie : ");
			deletePlanningSerie();
		}
	}
};
}
