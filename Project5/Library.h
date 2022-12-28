#pragma once
#include "Movie.h"
#using <System.dll>
#include <array>
#include "PosterImage.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::IO;
using namespace std;


namespace Project5 {

	/// <summary>
	/// Description résumée de Library
	/// </summary>
	public ref class Library : public System::Windows::Forms::UserControl
	{
		Panel^ panelContent;
	public:
		Library(Panel^ panelC)
		{
			InitializeComponent();
			this->panelContent = panelC;
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
		System::Drawing::Image^ ConvertByteToImage(unsigned char Data) {

			MemoryStream^ ms = gcnew MemoryStream(Data);
			try {
				return Image::FromStream(ms);;
			}
			catch (Exception^ e)
			{
				Console::WriteLine(e->Message);
			}
			finally {
				ms->Close();
			}
			return nullptr;
		}
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Library()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::FlowLayoutPanel^ libraryPanel;
	protected:

	protected:
	private: System::Windows::Forms::Button^ BtnSeries;
	private: System::Windows::Forms::Button^ BtnMovie;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::ComboBox^ comboBox1;

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
			this->libraryPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->BtnSeries = (gcnew System::Windows::Forms::Button());
			this->BtnMovie = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// libraryPanel
			// 
			this->libraryPanel->AutoScroll = true;
			this->libraryPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->libraryPanel->Location = System::Drawing::Point(0, 59);
			this->libraryPanel->Name = L"libraryPanel";
			this->libraryPanel->Size = System::Drawing::Size(1214, 522);
			this->libraryPanel->TabIndex = 5;
			// 
			// BtnSeries
			// 
			this->BtnSeries->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnSeries->Location = System::Drawing::Point(136, 11);
			this->BtnSeries->Name = L"BtnSeries";
			this->BtnSeries->Size = System::Drawing::Size(91, 36);
			this->BtnSeries->TabIndex = 1;
			this->BtnSeries->Text = L"Series";
			this->BtnSeries->UseVisualStyleBackColor = true;
			// 
			// BtnMovie
			// 
			this->BtnMovie->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnMovie->Location = System::Drawing::Point(28, 11);
			this->BtnMovie->Name = L"BtnMovie";
			this->BtnMovie->Size = System::Drawing::Size(91, 36);
			this->BtnMovie->TabIndex = 0;
			this->BtnMovie->Text = L"Movies";
			this->BtnMovie->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->BtnSeries);
			this->panel1->Controls->Add(this->BtnMovie);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1214, 59);
			this->panel1->TabIndex = 4;
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(954, 16);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(163, 33);
			this->comboBox1->TabIndex = 2;
			// 
			// Library
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->libraryPanel);
			this->Controls->Add(this->panel1);
			this->Name = L"Library";
			this->Size = System::Drawing::Size(1214, 581);
			this->Load += gcnew System::EventHandler(this, &Library::Library_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Library_Load(System::Object^ sender, System::EventArgs^ e) {
		SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
		String^ Query = "SELECT *FROM MOVIE ;";
		SqlCommand Cmd(Query, % conx);
		conx.Open();
		SqlDataReader^ sqlReader = Cmd.ExecuteReader();
		int index = 0;
		libraryPanel->Controls->Clear();
		//for movies : 
		while (sqlReader->Read())
		{
			//creating an instance for every movie : 
			Movie^ movie_ = gcnew Movie();
			movie_->SetIdMovie(Convert::ToInt32(sqlReader[0]->ToString()));
			movie_->SetIdApi(Convert::ToInt32(sqlReader["ID_API"]->ToString()));
			movie_->SetTitle(sqlReader["TITLE"]->ToString());
			movie_->SetOverview(sqlReader["OVERVIEW"]->ToString());
			movie_->SetRealease_Date(Convert::ToDateTime(sqlReader["RELEASE_DATE"]->ToString()));
			movie_->SetRating((float)Convert::ToDouble(sqlReader["Rating"]->ToString()));

			// Create a MemoryStream to hold the image data
			MemoryStream^ ms = gcnew MemoryStream(sqlReader->GetSqlBinary(6).Value);
			// Load the image data into a Bitmap object
			Bitmap^ image = gcnew Bitmap(ms);
			movie_->SetPoster(image);

			ms = gcnew MemoryStream(sqlReader->GetSqlBinary(7).Value);
			// Load the image data into a Bitmap object
			image = gcnew Bitmap(ms);
			movie_->SetBakcDrop(image);
			movie_->SetExist(DataBaseOperations::Search_Movie(movie_->GetIdApi()));
			//creating a user control for it : 
			PosterImage^ movie_userc = gcnew PosterImage(index,movie_,panelContent);
			libraryPanel->Controls->Add(movie_userc);
			++index;
		}
		conx.Close();
		index = 0;
		String^ Query2 = "SELECT *FROM SERIE ;";
		conx.Open();
		SqlCommand Cmd2(Query2, % conx);
		SqlDataReader^ sqlReader2 = Cmd2.ExecuteReader();
		//for series: 
		while (sqlReader2->Read())
		{
			//creating an instance for every movie : 
			Serie^ serie_ = gcnew Serie();
			serie_->SetIdApi(Convert::ToInt32(sqlReader2[0]->ToString()));
			serie_->SetIdApi(Convert::ToInt32(sqlReader2["ID_API"]->ToString()));
			serie_->SetName(sqlReader2["TITLE"]->ToString());
			serie_->SetOverview(sqlReader2["OVERVIEW"]->ToString()); 
			serie_->SetRealease_Date(Convert::ToDateTime(sqlReader2["RELEASE_DATE"]->ToString()));
			serie_->SetRating((float)Convert::ToDouble(sqlReader2["Rating"]->ToString()));

			// Create a MemoryStream to hold the image data
			MemoryStream^ ms = gcnew MemoryStream(sqlReader2->GetSqlBinary(4).Value);
			// Load the image data into a Bitmap object
			Bitmap^ image = gcnew Bitmap(ms);
			serie_->SetPoster(image);

			ms = gcnew MemoryStream(sqlReader2->GetSqlBinary(5).Value);
			// Load the image data into a Bitmap object
			image = gcnew Bitmap(ms);
			serie_->SetBakcDrop(image);
			serie_->SetExist(DataBaseOperations::Search_Serie(serie_->GetIdApi()));
			//creating a user control for it : 
			PosterImage^ serie_userc = gcnew PosterImage(index, serie_, panelContent);
			libraryPanel->Controls->Add(serie_userc);
			++index;
		}
		conx.Close();
	}
};
}
