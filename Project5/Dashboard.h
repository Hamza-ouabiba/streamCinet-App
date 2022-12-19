#pragma once
#include "Mani.h"
#include<iostream>
using namespace System;
using namespace System::ComponentModel;
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
	public:
		DashBoard(void)
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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ overview;
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
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->imagePanel = (gcnew System::Windows::Forms::Panel());
			this->overview = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->movie = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->serie = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->imagePanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// imagePanel
			// 
			this->imagePanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->imagePanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->imagePanel->Controls->Add(this->overview);
			this->imagePanel->Controls->Add(this->button1);
			this->imagePanel->Location = System::Drawing::Point(6, 3);
			this->imagePanel->Name = L"imagePanel";
			this->imagePanel->Size = System::Drawing::Size(1471, 549);
			this->imagePanel->TabIndex = 3;
			// 
			// overview
			// 
			this->overview->AutoSize = true;
			this->overview->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->overview->ForeColor = System::Drawing::SystemColors::Control;
			this->overview->Location = System::Drawing::Point(135, 281);
			this->overview->Name = L"overview";
			this->overview->Size = System::Drawing::Size(53, 20);
			this->overview->TabIndex = 1;
			this->overview->Text = L"label1";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::White;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(127, 212);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(235, 45);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Watch Trailer Now";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// movie
			// 
			this->movie->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->movie->Location = System::Drawing::Point(6, 577);
			this->movie->Name = L"movie";
			this->movie->Size = System::Drawing::Size(1474, 277);
			this->movie->TabIndex = 4;
			// 
			// serie
			// 
			this->serie->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->serie->Location = System::Drawing::Point(6, 884);
			this->serie->Name = L"serie";
			this->serie->Size = System::Drawing::Size(1474, 277);
			this->serie->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::Control;
			this->label1->Location = System::Drawing::Point(29, 555);
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
			this->label2->Location = System::Drawing::Point(34, 854);
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
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->imagePanel);
			this->Controls->Add(this->movie);
			this->Controls->Add(this->serie);
			this->Name = L"DashBoard";
			this->Size = System::Drawing::Size(1477, 1070);
			this->Load += gcnew System::EventHandler(this, &DashBoard::DashBoard_Load);
			this->imagePanel->ResumeLayout(false);
			this->imagePanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void setData(Json::Value dataMovies,string url,int i,string type)
		{
			int indexPage = 0;
			
			
		}
		void InitializeUserControl(string url,string type)
		{
			Json::Value dataMovies = l->getInformations(url, type);
			stringstream ss;
			string poster_ = "https://image.tmdb.org/t/p/w500";
			string backDrop_ = "https://image.tmdb.org/t/p/w1280";
			for (int i = 1;i <= 19;i++)
			{
				if (type == "title")
				{
					cout << "creating movies";
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
					this->movie->Controls->Add(movie_uc);
				}
				else if (type == "name")
				{
					cout << "creating series";
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
					this->serie->Controls->Add(serie_uc);
				}
			}
		}
#pragma endregion
	private: System::Void DashBoard_Load(System::Object^ sender, System::EventArgs^ e) {
		string urlDiscover_movies = "https://api.themoviedb.org/3/discover/movie?api_key=10f96818301b77e61d73d48aa20d81f9&page=1";
		string urlDiscover_series = "https://api.themoviedb.org/3/discover/tv?api_key=10f96818301b77e61d73d48aa20d81f9&page=1";
		//setting overview : 
		InitializeUserControl(urlDiscover_movies,"title");
		InitializeUserControl(urlDiscover_series, "name");
		l->ShowBackGroundImageDashBoard(urlDiscover_movies, imagePanel, overview);
	}
	};
}
