#pragma once
#include "Mani.h"
#include "PosterImage.h"
#include "DataBaseOperations.h"
#include "Movie.h"
#include "Serie.h"
#include<iostream>
using namespace System;
using namespace System::ComponentModel;
using namespace System::Threading;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;
namespace Project5 {

	/// <summary>
	/// Description résumée de DashBoard
	/// </summary>
	public ref class DashBoard : public System::Windows::Forms::UserControl
	{
		Mani^ l = gcnew Mani();

	private: System::Windows::Forms::RichTextBox^ overview;
		   Panel^ panel;
	public:
		DashBoard()
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
		DashBoard(Panel^ panelContent)
		{
		
			InitializeComponent();
			this->panel = panelContent;
		}
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~DashBoard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ imagePanel;
	private: System::Windows::Forms::FlowLayoutPanel^ movie;
	private: System::Windows::Forms::FlowLayoutPanel^ serie;
	private: System::Windows::Forms::Button^ trailerBtn;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	protected:
	protected:
	protected:
	protected:
	protected:
	protected:
	protected:
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
			this->imagePanel = (gcnew System::Windows::Forms::Panel());
			this->overview = (gcnew System::Windows::Forms::RichTextBox());
			this->trailerBtn = (gcnew System::Windows::Forms::Button());
			this->movie = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->serie = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->imagePanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// imagePanel
			// 
			this->imagePanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->imagePanel->Controls->Add(this->overview);
			this->imagePanel->Controls->Add(this->trailerBtn);
			this->imagePanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->imagePanel->Location = System::Drawing::Point(0, 0);
			this->imagePanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->imagePanel->Name = L"imagePanel";
			this->imagePanel->Size = System::Drawing::Size(1284, 601);
			this->imagePanel->TabIndex = 3;
			this->imagePanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &DashBoard::imagePanel_Paint);
			// 
			// overview
			// 
			this->overview->BackColor = System::Drawing::Color::Black;
			this->overview->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->overview->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->overview->ForeColor = System::Drawing::Color::White;
			this->overview->Location = System::Drawing::Point(123, 290);
			this->overview->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->overview->Name = L"overview";
			this->overview->Size = System::Drawing::Size(772, 202);
			this->overview->TabIndex = 1;
			this->overview->Text = L"";
			this->overview->TextChanged += gcnew System::EventHandler(this, &DashBoard::overview_TextChanged);
			// 
			// trailerBtn
			// 
			this->trailerBtn->BackColor = System::Drawing::Color::White;
			this->trailerBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->trailerBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->trailerBtn->Location = System::Drawing::Point(127, 212);
			this->trailerBtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->trailerBtn->Name = L"trailerBtn";
			this->trailerBtn->Size = System::Drawing::Size(235, 46);
			this->trailerBtn->TabIndex = 0;
			this->trailerBtn->Text = L"Watch Trailer Now";
			this->trailerBtn->UseVisualStyleBackColor = false;
			this->trailerBtn->Click += gcnew System::EventHandler(this, &DashBoard::trailerBtn_Click);
			// 
			// movie
			// 
			this->movie->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->movie->Location = System::Drawing::Point(41, 641);
			this->movie->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->movie->Name = L"movie";
			this->movie->Size = System::Drawing::Size(1260, 357);
			this->movie->TabIndex = 4;
			this->movie->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &DashBoard::movie_Paint);
			// 
			// serie
			// 
			this->serie->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->serie->Location = System::Drawing::Point(43, 1046);
			this->serie->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->serie->Name = L"serie";
			this->serie->Size = System::Drawing::Size(1260, 367);
			this->serie->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::Control;
			this->label1->Location = System::Drawing::Point(12, 614);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 20);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Movies";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::Control;
			this->label2->Location = System::Drawing::Point(13, 1007);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 20);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Series";
			// 
			// DashBoard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::Black;
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->imagePanel);
			this->Controls->Add(this->movie);
			this->Controls->Add(this->serie);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"DashBoard";
			this->Size = System::Drawing::Size(1284, 1083);
			this->Load += gcnew System::EventHandler(this, &DashBoard::DashBoard_Load);
			this->imagePanel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void setData(Json::Value dataMovies, string url, int i, string type)
		{
			int indexPage = 0;


		}
		void InitializeUserControl(string url, string type)
		{
			Json::Value dataMovies = l->getInformations(url);
			stringstream ss;
			string poster_ = "https://image.tmdb.org/t/p/w500";
			string backDrop_ = "https://image.tmdb.org/t/p/w1280";
			for (int i = 1;i <= 19;i++)
			{
				if (type == "title" && dataMovies["results"][i]["release_date"].asString() != "null")
				{
					//creating a movie object : 
					Movie^ mv = gcnew Movie();
					int id;
					string url_poster = poster_ + dataMovies["results"][i]["poster_path"].toStyledString();
					string backdrop_url = backDrop_ + dataMovies["results"][i]["backdrop_path"].toStyledString();
					//remove quotation marks because of JSON 
					url_poster.erase(remove(url_poster.begin(), url_poster.end(), '"'), url_poster.end());
					backdrop_url.erase(remove(backdrop_url.begin(), backdrop_url.end(), '"'), backdrop_url.end());
					//setting data of movie : 
					ss << dataMovies["results"][i]["id"].toStyledString();
					ss >> id;
					mv->SetIdApi(id);

					string title = dataMovies["results"][i][type].toStyledString();
					title.erase(remove(title.begin(), title.end(), '"'), title.end());
					mv->SetTitle(msclr::interop::marshal_as<System::String^>(title));

					string overview = dataMovies["results"][i]["overview"].toStyledString();
					mv->SetOverview(msclr::interop::marshal_as<System::String^>(overview));


					string date = dataMovies["results"][i]["release_date"].toStyledString();
					date.erase(remove(date.begin(), date.end(), '"'), date.end());
					mv->SetRealease_Date(Convert::ToDateTime(msclr::interop::marshal_as<System::String^>(date)));


					string data = poster_ + dataMovies["results"][i]["poster_path"].toStyledString();
					data.erase(remove(data.begin(), data.end(), '"'), data.end());
					System::String^ unmanaged = msclr::interop::marshal_as<System::String^>(data);

					mv->SetPoster(l->imageDown(unmanaged));
					data = backDrop_ + dataMovies["results"][i]["backdrop_path"].toStyledString();
					data.erase(remove(data.begin(), data.end(), '"'), data.end());
					unmanaged = msclr::interop::marshal_as<System::String^>(data);

					mv->SetBakcDrop(l->imageDown(unmanaged));
					//adding a user Control related to this movie : 
					PosterImage^ movie_uc = gcnew PosterImage(i, mv, this->panel);
					this->movie->Controls->Add(movie_uc);
					cout << "creating movies";
				}
				else if (type == "name")
				{
					Serie^ serie = gcnew Serie();
					int id;
					string url_poster = poster_ + dataMovies["results"][i]["poster_path"].toStyledString();
					string backdrop_url = backDrop_ + dataMovies["results"][i]["backdrop_path"].toStyledString();
					//remove quotation marks because of JSON 
					url_poster.erase(remove(url_poster.begin(), url_poster.end(), '"'), url_poster.end());
					backdrop_url.erase(remove(backdrop_url.begin(), backdrop_url.end(), '"'), backdrop_url.end());
					//setting data of movie : 
					ss << dataMovies["results"][i]["id"].toStyledString();
					ss >> id;
					serie->SetIdApi(id);

					string title = dataMovies["results"][i][type].toStyledString();
					title.erase(remove(title.begin(), title.end(), '"'), title.end());
					serie->SetName(msclr::interop::marshal_as<System::String^>(title));

					string overview = dataMovies["results"][i]["overview"].toStyledString();
					serie->SetOverview(msclr::interop::marshal_as<System::String^>(overview));


					string date = dataMovies["results"][i]["first_air_date"].toStyledString();
					date.erase(remove(date.begin(), date.end(), '"'), date.end());
					serie->SetRealease_Date(Convert::ToDateTime(msclr::interop::marshal_as<System::String^>(date)));

					string data = poster_ + dataMovies["results"][i]["poster_path"].toStyledString();
					data.erase(remove(data.begin(), data.end(), '"'), data.end());
					System::String^ unmanaged = msclr::interop::marshal_as<System::String^>(data);

					string country = dataMovies["results"][i]["origin_country"].toStyledString();
					serie->SetCountry(msclr::interop::marshal_as<System::String^>(country));

					serie->SetPoster(l->imageDown(unmanaged));

					data = backDrop_ + dataMovies["results"][i]["backdrop_path"].toStyledString();
					data.erase(remove(data.begin(), data.end(), '"'), data.end());
					unmanaged = msclr::interop::marshal_as<System::String^>(data);

					serie->SetBakcDrop(l->imageDown(unmanaged));
					//adding a user Control related to this movie : 
					PosterImage^ serie_uc = gcnew PosterImage(i, serie, this->panel);
					this->serie->Controls->Add(serie_uc);
					cout << "creating series";
				}
			}
		}
#pragma endregion
	private: System::Void DashBoard_Load(System::Object^ sender, System::EventArgs^ e) {
		
		//setting overview : 
		if (Login::User->GetIdUser() != NULL)
		{
			string urlDiscover_movies = "https://api.themoviedb.org/3/discover/movie?api_key=10f96818301b77e61d73d48aa20d81f9&page=1";
			string urlDiscover_series = "https://api.themoviedb.org/3/discover/tv?api_key=10f96818301b77e61d73d48aa20d81f9&page=1";
			InitializeUserControl(urlDiscover_movies,"title");
			InitializeUserControl(urlDiscover_series, "name");
			string idApi = l->ShowBackGroundImageDashBoard(urlDiscover_movies, imagePanel, overview);
			String^ idParse = msclr::interop::marshal_as<System::String^>(idApi);
			trailerBtn->Name = l->getTrailer(idApi);
		}
		else
		{
			MessageBox::Show("Veuillez se conncter d'abord : ");
			Login^ form;
			form->Show();
		}
	}
	private: System::Void movie_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void imagePanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void overview_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void trailerBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ ytbLink = "https://www.youtube.com/watch?v=";
		System::Diagnostics::Process::Start(ytbLink + trailerBtn->Name);
	}
};
}
