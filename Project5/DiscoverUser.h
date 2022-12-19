#pragma once
#include <string>
#include "Mani.h"
#include "Movie.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;

namespace Project5 {

	/// <summary>
	/// Description résumée de DiscoverUser
	/// </summary>
	public ref class DiscoverUser : public System::Windows::Forms::UserControl
	{
	public:
		Mani^ l = gcnew Mani();
		DiscoverUser(void)
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
		~DiscoverUser()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::FlowLayoutPanel^ discoverMovie;
	protected:

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ ratedBtn;

	private: System::Windows::Forms::Button^ popularBtn;



	private: System::Windows::Forms::Button^ seriesBtn;
	private: System::Windows::Forms::Button^ moviesBtn;



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
			this->discoverMovie = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->ratedBtn = (gcnew System::Windows::Forms::Button());
			this->popularBtn = (gcnew System::Windows::Forms::Button());
			this->seriesBtn = (gcnew System::Windows::Forms::Button());
			this->moviesBtn = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// discoverMovie
			// 
			this->discoverMovie->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->discoverMovie->AutoScroll = true;
			this->discoverMovie->Location = System::Drawing::Point(258, 34);
			this->discoverMovie->Name = L"discoverMovie";
			this->discoverMovie->Size = System::Drawing::Size(1025, 734);
			this->discoverMovie->TabIndex = 0;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel1->Controls->Add(this->ratedBtn);
			this->panel1->Controls->Add(this->popularBtn);
			this->panel1->Controls->Add(this->seriesBtn);
			this->panel1->Controls->Add(this->moviesBtn);
			this->panel1->Location = System::Drawing::Point(0, 34);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(258, 950);
			this->panel1->TabIndex = 5;
			// 
			// ratedBtn
			// 
			this->ratedBtn->Location = System::Drawing::Point(23, 225);
			this->ratedBtn->Name = L"ratedBtn";
			this->ratedBtn->Size = System::Drawing::Size(214, 47);
			this->ratedBtn->TabIndex = 4;
			this->ratedBtn->Text = L"Top Rated";
			this->ratedBtn->UseVisualStyleBackColor = true;
			// 
			// popularBtn
			// 
			this->popularBtn->Location = System::Drawing::Point(23, 159);
			this->popularBtn->Name = L"popularBtn";
			this->popularBtn->Size = System::Drawing::Size(214, 47);
			this->popularBtn->TabIndex = 3;
			this->popularBtn->Text = L"Popular";
			this->popularBtn->UseVisualStyleBackColor = true;
			this->popularBtn->Click += gcnew System::EventHandler(this, &DiscoverUser::popularBtn_Click);
			// 
			// seriesBtn
			// 
			this->seriesBtn->Location = System::Drawing::Point(23, 91);
			this->seriesBtn->Name = L"seriesBtn";
			this->seriesBtn->Size = System::Drawing::Size(214, 47);
			this->seriesBtn->TabIndex = 1;
			this->seriesBtn->Text = L"Series";
			this->seriesBtn->UseVisualStyleBackColor = true;
			this->seriesBtn->Click += gcnew System::EventHandler(this, &DiscoverUser::seriesBtn_Click);
			// 
			// moviesBtn
			// 
			this->moviesBtn->Location = System::Drawing::Point(23, 18);
			this->moviesBtn->Name = L"moviesBtn";
			this->moviesBtn->Size = System::Drawing::Size(214, 47);
			this->moviesBtn->TabIndex = 0;
			this->moviesBtn->Text = L"Movies";
			this->moviesBtn->UseVisualStyleBackColor = true;
			// 
			// DiscoverUser
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->discoverMovie);
			this->Name = L"DiscoverUser";
			this->Size = System::Drawing::Size(1317, 790);
			this->Load += gcnew System::EventHandler(this, &DiscoverUser::DiscoverUser_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
		private: string urlWithSize(string url, string size)
		{
			return url + size;
		}
		private: void ShowFlowPanel(string url,string type)
		{
			Json::Value dataMovies = l->getInformations(url, type);
			stringstream ss;
			string poster_ = "https://image.tmdb.org/t/p/w500";
			string backDrop_ = "https://image.tmdb.org/t/p/w1280";
			discoverMovie->Controls->Clear();
			for (int i = 1;i <= 19;i++)
			{
				if (type == "title")
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
					mv->SetTitle(msclr::interop::marshal_as<System::String^>(title));

					string overview = dataMovies["results"][i]["overview"].toStyledString();
					mv->SetOverview(msclr::interop::marshal_as<System::String^>(overview));


					string date = dataMovies["results"][i]["release_date"].toStyledString();
					mv->SetRealease_Date(msclr::interop::marshal_as<System::String^>(date));



					string data = poster_ + dataMovies["results"][i]["poster_path"].toStyledString();
					data.erase(remove(data.begin(), data.end(), '"'), data.end());
					System::String^ unmanaged = msclr::interop::marshal_as<System::String^>(data);

					mv->SetPoster(l->DownloadImage(unmanaged));
					data = backDrop_ + dataMovies["results"][i]["backdrop_path"].toStyledString();
					data.erase(remove(data.begin(), data.end(), '"'), data.end());
					unmanaged = msclr::interop::marshal_as<System::String^>(data);

					mv->SetBakcDrop(l->DownloadImage(unmanaged));

					//adding a user Control related to this movie : 
					MyUserControl^ movie_uc = gcnew MyUserControl(i, mv);
					this->discoverMovie->Controls->Add(movie_uc);
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
					serie->SetName(msclr::interop::marshal_as<System::String^>(title));

					string overview = dataMovies["results"][i]["overview"].toStyledString();
					serie->SetOverview(msclr::interop::marshal_as<System::String^>(overview));


					string date = dataMovies["results"][i]["release_date"].toStyledString();
					serie->SetRealease_Date(msclr::interop::marshal_as<System::String^>(date));

					string data = poster_ + dataMovies["results"][i]["poster_path"].toStyledString();
					data.erase(remove(data.begin(), data.end(), '"'), data.end());
					System::String^ unmanaged = msclr::interop::marshal_as<System::String^>(data);

					serie->SetPoster(l->DownloadImage(unmanaged));

					data = backDrop_ + dataMovies["results"][i]["backdrop_path"].toStyledString();
					data.erase(remove(data.begin(), data.end(), '"'), data.end());
					unmanaged = msclr::interop::marshal_as<System::String^>(data);

					serie->SetBakcDrop(l->DownloadImage(unmanaged));
					//adding a user Control related to this movie : 
					MyUserControl^ serie_uc = gcnew MyUserControl(i, serie);
					this->discoverMovie->Controls->Add(serie_uc);
				}
			}
		}
#pragma endregion
	private: System::Void DiscoverUser_Load(System::Object^ sender, System::EventArgs^ e) {
		string urlDiscover_movies = "https://api.themoviedb.org/3/discover/movie?api_key=10f96818301b77e61d73d48aa20d81f9&page=";
		ShowFlowPanel(urlDiscover_movies, "title");
	}
	private: System::Void seriesBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		string urlDiscover_series = "https://api.themoviedb.org/3/discover/tv?api_key=10f96818301b77e61d73d48aa20d81f9&page=";
		ShowFlowPanel(urlDiscover_series, "name");
	}
	private: System::Void popularBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		string urlDiscover_popular_m = "https://api.themoviedb.org/3/movie/popular?api_key=10f96818301b77e61d73d48aa20d81f9&page=";
		ShowFlowPanel(urlDiscover_popular_m, "title");
	}
};
}
