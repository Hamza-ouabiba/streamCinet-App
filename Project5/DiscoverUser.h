#pragma once
#include <string>
#include "Mani.h"
#include "PosterImage.h"
#include "Movie.h"
#include<iostream>
#include <windows.h> // required for Sleep function
#include "ComboVal.h" 
using namespace System;
using namespace System::Threading;
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
	private:
		Mani^ l = gcnew Mani();
		static String^ locationUser;
	private: System::Windows::Forms::ComboBox^ comboCat;
		   Panel^ panel_;
	public:
		DiscoverUser(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
		DiscoverUser(Panel^ panelContent)
		{
			InitializeComponent();
			this->panel_ = panelContent;
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
	private: System::Windows::Forms::Button^ searchBtn;
	private: System::Windows::Forms::TextBox^ search;




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
			this->comboCat = (gcnew System::Windows::Forms::ComboBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->ratedBtn = (gcnew System::Windows::Forms::Button());
			this->popularBtn = (gcnew System::Windows::Forms::Button());
			this->seriesBtn = (gcnew System::Windows::Forms::Button());
			this->moviesBtn = (gcnew System::Windows::Forms::Button());
			this->searchBtn = (gcnew System::Windows::Forms::Button());
			this->search = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// discoverMovie
			// 
			this->discoverMovie->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->discoverMovie->AutoScroll = true;
			this->discoverMovie->Location = System::Drawing::Point(194, 37);
			this->discoverMovie->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->discoverMovie->Name = L"discoverMovie";
			this->discoverMovie->Size = System::Drawing::Size(782, 596);
			this->discoverMovie->TabIndex = 0;
			this->discoverMovie->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &DiscoverUser::discoverMovie_Paint);
			// 
			// comboCat
			// 
			this->comboCat->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->comboCat->FormattingEnabled = true;
			this->comboCat->Location = System::Drawing::Point(194, 6);
			this->comboCat->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->comboCat->Name = L"comboCat";
			this->comboCat->Size = System::Drawing::Size(345, 21);
			this->comboCat->TabIndex = 12;
			this->comboCat->SelectedIndexChanged += gcnew System::EventHandler(this, &DiscoverUser::comboCat_SelectedIndexChanged);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Black;
			this->panel1->Controls->Add(this->ratedBtn);
			this->panel1->Controls->Add(this->popularBtn);
			this->panel1->Controls->Add(this->seriesBtn);
			this->panel1->Controls->Add(this->moviesBtn);
			this->panel1->Location = System::Drawing::Point(0, 28);
			this->panel1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(194, 772);
			this->panel1->TabIndex = 5;
			// 
			// ratedBtn
			// 
			this->ratedBtn->Location = System::Drawing::Point(17, 183);
			this->ratedBtn->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ratedBtn->Name = L"ratedBtn";
			this->ratedBtn->Size = System::Drawing::Size(160, 38);
			this->ratedBtn->TabIndex = 4;
			this->ratedBtn->Text = L"Top Rated";
			this->ratedBtn->UseVisualStyleBackColor = true;
			// 
			// popularBtn
			// 
			this->popularBtn->Location = System::Drawing::Point(17, 129);
			this->popularBtn->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->popularBtn->Name = L"popularBtn";
			this->popularBtn->Size = System::Drawing::Size(160, 38);
			this->popularBtn->TabIndex = 3;
			this->popularBtn->Text = L"Popular";
			this->popularBtn->UseVisualStyleBackColor = true;
			this->popularBtn->Click += gcnew System::EventHandler(this, &DiscoverUser::popularBtn_Click);
			// 
			// seriesBtn
			// 
			this->seriesBtn->Location = System::Drawing::Point(17, 74);
			this->seriesBtn->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->seriesBtn->Name = L"seriesBtn";
			this->seriesBtn->Size = System::Drawing::Size(160, 38);
			this->seriesBtn->TabIndex = 1;
			this->seriesBtn->Text = L"Series";
			this->seriesBtn->UseVisualStyleBackColor = true;
			this->seriesBtn->Click += gcnew System::EventHandler(this, &DiscoverUser::seriesBtn_Click);
			// 
			// moviesBtn
			// 
			this->moviesBtn->Location = System::Drawing::Point(17, 15);
			this->moviesBtn->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->moviesBtn->Name = L"moviesBtn";
			this->moviesBtn->Size = System::Drawing::Size(160, 38);
			this->moviesBtn->TabIndex = 0;
			this->moviesBtn->Text = L"Movies";
			this->moviesBtn->UseVisualStyleBackColor = true;
			this->moviesBtn->Click += gcnew System::EventHandler(this, &DiscoverUser::moviesBtn_Click);
			// 
			// searchBtn
			// 
			this->searchBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->searchBtn->Location = System::Drawing::Point(922, 6);
			this->searchBtn->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->searchBtn->Name = L"searchBtn";
			this->searchBtn->Size = System::Drawing::Size(52, 26);
			this->searchBtn->TabIndex = 11;
			this->searchBtn->Text = L"Search";
			this->searchBtn->UseVisualStyleBackColor = true;
			this->searchBtn->Click += gcnew System::EventHandler(this, &DiscoverUser::searchBtn_Click);
			// 
			// search
			// 
			this->search->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->search->Location = System::Drawing::Point(580, 8);
			this->search->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->search->Multiline = true;
			this->search->Name = L"search";
			this->search->Size = System::Drawing::Size(338, 25);
			this->search->TabIndex = 10;
			// 
			// DiscoverUser
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->Controls->Add(this->comboCat);
			this->Controls->Add(this->discoverMovie);
			this->Controls->Add(this->searchBtn);
			this->Controls->Add(this->search);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"DiscoverUser";
			this->Size = System::Drawing::Size(988, 642);
			this->Load += gcnew System::EventHandler(this, &DiscoverUser::DiscoverUser_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		private: string urlWithSize(string url, string size)
		{
			return url + size;
		}
		private: void ShowFlowPanel(string url,string type)
		{
			Json::Value dataMovies = l->getInformations(url);
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
					string backN = dataMovies["results"][i]["backdrop_path"].toStyledString();
					string postN = dataMovies["results"][i]["poster_path"].toStyledString();
					string date = dataMovies["results"][i]["release_date"].toStyledString();
					date.erase(remove(date.begin(), date.end(), '"'), date.end());
					backN.erase(remove(backN.begin(), backN.end(), '"'), backN.end());
					postN.erase(remove(postN.begin(), postN.end(), '"'), postN.end());
					cout << "backN : "<<backN<<"postN"<<postN;
					System::Threading::Thread::Sleep(10);
					if (dataMovies["results"][i]["backdrop_path"].asString() != "" && dataMovies["results"][i]["poster_path"].asString() != "" && dataMovies["results"][i]["release_date"].asString() != "")
					{
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

						mv->SetRealease_Date(Convert::ToDateTime(msclr::interop::marshal_as<System::String^>(date)));

						string data = poster_ + dataMovies["results"][i]["poster_path"].toStyledString();
						data.erase(remove(data.begin(), data.end(), '"'), data.end());
						date = "";
						System::String^ unmanaged = msclr::interop::marshal_as<System::String^>(data);

						mv->SetPoster(l->DownloadImage(unmanaged));
						data = backDrop_ + dataMovies["results"][i]["backdrop_path"].toStyledString();
						data.erase(remove(data.begin(), data.end(), '"'), data.end());
						unmanaged = msclr::interop::marshal_as<System::String^>(data);

						mv->SetBakcDrop(l->DownloadImage(unmanaged));
						//mv->SetExist(DataBaseOperations::Exist_Movie(mv->GetIdApi()));
						//adding a user Control related to this movie : 
						PosterImage^ movie_uc = gcnew PosterImage(i, mv,panel_);
						this->discoverMovie->Controls->Add(movie_uc);
					}
				}
				else if (type == "name")
				{
					Serie^ serie = gcnew Serie();
					int id;
					string date = dataMovies["results"][i]["first_air_date"].toStyledString();
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
					overview.erase(remove(overview.begin(), overview.end(), '"'), overview.end());
					serie->SetOverview(msclr::interop::marshal_as<System::String^>(overview));


					date.erase(remove(date.begin(), date.end(), '"'), date.end());
					serie->SetRealease_Date(Convert::ToDateTime(msclr::interop::marshal_as<System::String^>(date)));

					string data = poster_ + dataMovies["results"][i]["poster_path"].toStyledString();
					data.erase(remove(data.begin(), data.end(), '"'), data.end());
					System::String^ unmanaged = msclr::interop::marshal_as<System::String^>(data);

					string country = dataMovies["results"][i]["origin_country"].toStyledString();
					serie->SetCountry(msclr::interop::marshal_as<System::String^>(country));

					serie->SetPoster(l->DownloadImage(unmanaged));

					data = backDrop_ + dataMovies["results"][i]["backdrop_path"].toStyledString();
					data.erase(remove(data.begin(), data.end(), '"'), data.end());
					unmanaged = msclr::interop::marshal_as<System::String^>(data);

					//serie->SetExist(DataBaseOperations::Exist_Serie(serie->GetIdApi()));
					serie->SetBakcDrop(l->DownloadImage(unmanaged));

					//adding a user Control related to this movie : 
					PosterImage^ serie_uc = gcnew PosterImage(i, serie,panel_);
					this->discoverMovie->Controls->Add(serie_uc);
				}
			}
		}
	private: string getCategorieNameById(string type,string idCat)
	{
		string url = "https://api.themoviedb.org/3/genre/movie/list?api_key=10f96818301b77e61d73d48aa20d81f9&page=1";
		string name;
		Json::Value dataCategories = l->getInformations(url);
		for (int i = 0;i <= 19;i++)
		{
			if (idCat == dataCategories["genres"][i]["id"].toStyledString())
				name = dataCategories["genres"][i]["name"].toStyledString();
		}
		name.erase(remove(name.begin(), name.end(), '"'), name.end());
		return name;
	}
	private: void loadComboBoxCategories(string type,string url)
	{
		Json::Value dataMovies = l->getInformations(url);
		
		for (int i = 0;i <= 19;i++)
		{
			if (type == "title")
			{
				string categorieId = dataMovies["results"][i]["genre_ids"][0].toStyledString();
				System::String^ unmanaged = msclr::interop::marshal_as<System::String^>(getCategorieNameById(type,categorieId));
				ComboVal^ cv = gcnew ComboVal();
				cv->title = unmanaged;
				cv->id = msclr::interop::marshal_as<System::String^>(categorieId);
				this->comboCat->DisplayMember = "title";
				this->comboCat->ValueMember = "id";
				this->comboCat->Items->Add(cv);
			}
			else
			{
				string categorieId = dataMovies["results"][i]["genre_ids"][0].toStyledString();
				System::String^ unmanaged = msclr::interop::marshal_as<System::String^>(getCategorieNameById(type, categorieId));
				ComboVal^ cv = gcnew ComboVal();
				cv->title = unmanaged;
				cv->id = msclr::interop::marshal_as<System::String^>(categorieId);
				this->comboCat->DisplayMember = cv->title;
				this->comboCat->ValueMember = cv->id;
				this->comboCat->Items->Add(cv);
			}
		}
	}
#pragma endregion
	private: System::Void DiscoverUser_Load(System::Object^ sender, System::EventArgs^ e) {

		string urlDiscover_movies = "https://api.themoviedb.org/3/discover/movie?api_key=10f96818301b77e61d73d48aa20d81f9&page=";
		ShowFlowPanel(urlDiscover_movies, "title");
		loadComboBoxCategories("title",urlDiscover_movies);
	}
	private: System::Void seriesBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		string urlDiscover_series = "https://api.themoviedb.org/3/discover/tv?api_key=10f96818301b77e61d73d48aa20d81f9&page=";
		ShowFlowPanel(urlDiscover_series, "name");
		locationUser = "series";
	}
	private: System::Void popularBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		string urlDiscover_popular_m = "https://api.themoviedb.org/3/movie/popular?api_key=10f96818301b77e61d73d48aa20d81f9&page=";
		ShowFlowPanel(urlDiscover_popular_m, "title");
	}
	private: System::Void moviesBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		DiscoverUser_Load(sender, e);
		locationUser = "movies";
	}
	private: System::Void searchBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ urlSearch = "https://api.themoviedb.org/3/search/movie?api_key=10f96818301b77e61d73d48aa20d81f9&page=1&query=" + search->Text;
		ShowFlowPanel(msclr::interop::marshal_as<std::string>(urlSearch), "title");
		
		/*urlSearch = "https://api.themoviedb.org/3/search/tv?api_key=10f96818301b77e61d73d48aa20d81f9&page=1&query=h" + search->Text;
		ShowFlowPanel(msclr::interop::marshal_as<std::string>(urlSearch), "name");*/
	}
	private: void displayCategories(string url,string type)
	{
		if (type == "title")
		{
			string url = "https://api.themoviedb.org/3/genre/movie/list?api_key=10f96818301b77e61d73d48aa20d81f9&page=1";
		}
	}
	private: System::Void comboCat_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ categorie = comboCat->SelectedValue->ToString();
		MessageBox::Show(categorie);
		//if user is in the movies section : 
		if (locationUser == "movies")
		{
			string urlDiscover_movies = "https://api.themoviedb.org/3/discover/movie?api_key=10f96818301b77e61d73d48aa20d81f9&page=";
			//getting each id of a movie and then test it to a particular id of category: 

		}
}
private: System::Void discoverMovie_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}
