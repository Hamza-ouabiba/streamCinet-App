#pragma once
#include "Movie.h" 
#include "Serie.h"
#include "DataBaseConnection.h"
#include "PosterImage.h"
#include "DataBaseOperations.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Data::SqlClient;

namespace Project5 {

	/// <summary>
	/// Summary for Library
	/// </summary>
	public ref class Library : public System::Windows::Forms::UserControl
	{

	public:
		Panel^ Display_Panel;
		
		bool Choice; //false : for selected choice series
					//true : for  selected choice movies

		SqlConnection^ conx = DataBaseConnection::Connection();
		Library(Panel^ P)
		{
			InitializeComponent();
			Display_Panel = P;
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Library()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	protected:
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ Series;
	private: System::Windows::Forms::Button^ Movies;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ComboBox^ comboBox1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->Series = (gcnew System::Windows::Forms::Button());
			this->Movies = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Location = System::Drawing::Point(3, 78);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(1262, 712);
			this->flowLayoutPanel1->TabIndex = 0;
			this->flowLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Library::flowLayoutPanel1_Paint);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->Series);
			this->panel1->Controls->Add(this->Movies);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1268, 72);
			this->panel1->TabIndex = 1;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Library::panel1_Paint);
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(725, 26);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(219, 28);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Library::textBox1_TextChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(1017, 26);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(157, 28);
			this->comboBox1->TabIndex = 2;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Library::comboBox1_SelectedIndexChanged);
			// 
			// Series
			// 
			this->Series->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Series->Location = System::Drawing::Point(136, 18);
			this->Series->Name = L"Series";
			this->Series->Size = System::Drawing::Size(91, 36);
			this->Series->TabIndex = 1;
			this->Series->Text = L"Series";
			this->Series->UseVisualStyleBackColor = true;
			this->Series->Click += gcnew System::EventHandler(this, &Library::Series_Click);
			// 
			// Movies
			// 
			this->Movies->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Movies->Location = System::Drawing::Point(28, 18);
			this->Movies->Name = L"Movies";
			this->Movies->Size = System::Drawing::Size(91, 36);
			this->Movies->TabIndex = 0;
			this->Movies->Text = L"Movies";
			this->Movies->UseVisualStyleBackColor = true;
			this->Movies->Click += gcnew System::EventHandler(this, &Library::Movies_Click);
			// 
			// Library
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Name = L"Library";
			this->Size = System::Drawing::Size(1268, 793);
			this->Load += gcnew System::EventHandler(this, &Library::Library_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void flowLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void Library_Load(System::Object^ sender, System::EventArgs^ e) {
		Choice = true;
		loadCategory_Movie();
		//All_Movies();
		comboBox1->SelectedIndex = 0;
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		if (textBox1->Text) {
			if (Choice) {
				if (comboBox1->SelectedIndex == 0) {
					MovieByTitle();
				}
				else {
					MovieByCategoryAndTitle();
				}
			}
			else {
				SerieByTitle();
			}
		}
		else {
			if (Choice) {
				if (comboBox1->SelectedIndex == 0) {
					All_Movies();
				}
				else {
					MovieByCategory();
				}
			}
			else {
				All_Series();
			}
		}

	}
	private: System::Void Series_Click(System::Object^ sender, System::EventArgs^ e) {

		Choice = false;
		loadCategory_Serie();
		//All_Series();
		comboBox1->SelectedIndex = 0;
	}
	private: System::Void Movies_Click(System::Object^ sender, System::EventArgs^ e) {
		Choice = true;
		loadCategory_Movie();
		//All_Movies();
		comboBox1->SelectedIndex = 0;
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (comboBox1->SelectedIndex != 0) {
			if (Choice) {
				if (textBox1->Text == "") {
					MovieByCategory();
				}
				else {
					MovieByCategoryAndTitle();
				}
			}
			else {
				if (textBox1->Text == "") {
					SerieByCategory();
				}
				else {
					SerieByCategoryAndTitle();
				}

			}
		}
		else {
			if (Choice) {
				if (textBox1->Text) {
					MovieByTitle();
				}
				else {
					All_Movies();
				}
			}
			else {
				if (textBox1->Text) {
					SerieByTitle();
				}
				else {
					All_Series();
				}
			}
		}

	}


/////////////////lOAD CATEGORY//////////////////////////////////////////////////////////////////////////////////////////////////////

		   void loadCategory_Movie() {
			   String^ queryString = "SELECT * FROM CATEGORY ;";

			   SqlCommand^ command = gcnew SqlCommand(queryString, conx);

			   conx->Open();

			   SqlDataReader^ reader = command->ExecuteReader();
			   comboBox1->Items->Clear();
			   comboBox1->Items->Add("All");
			   while (reader->Read())
			   {
				   comboBox1->Items->Add(reader["CATEGORY"]->ToString());
			   }
			   conx->Close();
		   }
		   void loadCategory_Serie() {
			   String^ queryString = "SELECT CATEGORY FROM CATEGORY_SERIE ;";

			   SqlCommand^ command = gcnew SqlCommand(queryString, conx);

			   conx->Open();

			   SqlDataReader^ reader = command->ExecuteReader();
			   comboBox1->Items->Clear();
			   comboBox1->Items->Add("All");

			   while (reader->Read())
			   {
				   comboBox1->Items->Add(reader["CATEGORY"]->ToString());
			   }
			   conx->Close();
		   }


///////////////Search functions//////////////////////////////////////////////////////////////

		   void GetMoviesByQuery(String^ Query) {
			   MemoryStream^ ms;
			   PosterImage^ UC;
			   Movie^ Mv;
			   try {
				   SqlCommand Cmd(Query, conx);
				   conx->Open();
				   SqlDataReader^ Read = Cmd.ExecuteReader();
				   flowLayoutPanel1->Controls->Clear();

				   while (Read->Read()) {

					   Mv = gcnew Movie();

					   Mv->SetIdMovie(Convert::ToInt32(Read[0]->ToString()));
					   Mv->SetIdApi(Convert::ToInt32(Read["ID_API"]->ToString()));
					   Mv->SetTitle(Read["TITLE"]->ToString());
					   Mv->SetOverview(Read["OVERVIEW"]->ToString());
					   Mv->SetRealease_Date(Convert::ToDateTime(Read["RELEASE_DATE"]->ToString()));
					   Mv->SetRating((float)Convert::ToDouble(Read["Rating"]->ToString()));

					   // Create a MemoryStream to hold the image data
					   ms = gcnew MemoryStream(Read->GetSqlBinary(6).Value);
					   // Load the image data into a Bitmap object
					   Bitmap^ image = gcnew Bitmap(ms);
					   Mv->SetPoster(image);

					   ms = gcnew MemoryStream(Read->GetSqlBinary(7).Value);
					   // Load the image data into a Bitmap object
					   image = gcnew Bitmap(ms);
					   Mv->SetBakcDrop(image);

					   UC = gcnew PosterImage(0,Mv, Display_Panel);
					   flowLayoutPanel1->Controls->Add(UC);

				   }
				   conx->Close();
			   }
			   catch (Exception^ ex) {
				   MessageBox::Show(ex->Message);

			   }
		   }

		   void All_Movies() {
			   String^ Query = "SELECT *FROM MOVIE ;";
			   GetMoviesByQuery(Query);
		   }

		   void MovieByTitle()
		   {
			   String^ Query = "SELECT *FROM MOVIE where TITLE like '" + textBox1->Text + "%'; ";
			   GetMoviesByQuery(Query);
		   }
		   void MovieByCategory()
		   {
			   String^ Query2 = "SELECT ID_MOVIE FROM MOVIECATEGORY where ID_CATEGORY = (select ID_CATEGORY from CATEGORY where CATEGORY like '" + comboBox1->Text + "%' )";
			   String^ Query = "SELECT *FROM MOVIE where ID_MOVIE = any(" + Query2 + ") ";
			   GetMoviesByQuery(Query);
		   }
		   void MovieByCategoryAndTitle()
		   {
			   String^ Query2 = "SELECT ID_MOVIE FROM MOVIECATEGORY where  ID_CATEGORY = (select ID_CATEGORY from CATEGORY where CATEGORY like '" + comboBox1->Text + "%' )";
			   String^ Query = "SELECT *FROM MOVIE where TITLE like '" + textBox1->Text + "%' and ID_MOVIE = any(" + Query2 + ") ";
			   GetMoviesByQuery(Query);
		   }


///////////::// Search Serie :::::::::////////////////////////////////////////////////////////////////
		
		   void GetSeriesByQuery(String^ Query) {

			   MemoryStream^ ms;
			   PosterImage^ UC;
			   Serie^ Sr;

			   try {
				   SqlCommand Cmd(Query, conx);
				   conx->Open();
				   SqlDataReader^ Read = Cmd.ExecuteReader();
				   flowLayoutPanel1->Controls->Clear();

				   while (Read->Read()) {

					   Sr = gcnew Serie();

					   Sr->SetIdSerie(Convert::ToInt32(Read[0]->ToString()));
					   Sr->SetIdApi(Convert::ToInt32(Read["ID_API"]->ToString()));
					   Sr->SetName(Read["TITLE"]->ToString());
					   Sr->SetOverview(Read["OVERVIEW"]->ToString());
					   Sr->SetRealease_Date(Convert::ToDateTime(Read["RELEASE_DATE"]->ToString()));
					   Sr->SetRating((float)Convert::ToDouble(Read["Rating"]->ToString()));

					   // Create a MemoryStream to hold the image data
					   ms = gcnew MemoryStream(Read->GetSqlBinary(6).Value);
					   // Load the image data into a Bitmap object
					   Bitmap^ image = gcnew Bitmap(ms);
					   Sr->SetPoster(image);

					   ms = gcnew MemoryStream(Read->GetSqlBinary(7).Value);
					   // Load the image data into a Bitmap object
					   image = gcnew Bitmap(ms);
					   Sr->SetBakcDrop(image);

					   UC = gcnew PosterImage(0,Sr, Display_Panel);
					   flowLayoutPanel1->Controls->Add(UC);
				   }
				   conx->Close();
			   }
			   catch (Exception^ ex) {
				   MessageBox::Show(ex->Message);
			   }
		   }

		   void All_Series() {
			   String^ Query = "SELECT *FROM SERIE ;";
			   GetSeriesByQuery(Query);
		   }
		   void SerieByTitle()
		   {
			   String^ Query = "SELECT *FROM SERIE where TITLE like '" + textBox1->Text + "%'; ";
			   GetSeriesByQuery(Query);
		   }
		   void SerieByCategory()
		   {
			   String^ Query2 = "SELECT ID_SERIE FROM SERIECATEGORY where ID_CATEGORY = (select ID_CATEGORY from CATEGORY_SERIE where CATEGORY like '" + comboBox1->Text + "%' )";
			   String^ Query = "SELECT *FROM SERIE where ID_SERIE = any(" + Query2 + ") ";
			   GetSeriesByQuery(Query);
		   }
		   void SerieByCategoryAndTitle()
		   {
			   String^ Query2 = "SELECT ID_SERIE FROM SERIECATEGORY where  ID_CATEGORY = (select ID_CATEGORY from CATEGORY where CATEGORY like '" + comboBox1->Text + "%' )";
			   String^ Query = "SELECT *FROM SERIE where TITLE like '" + textBox1->Text + "%' and ID_SERIE = any(" + Query2 + ") ";
			   GetSeriesByQuery(Query);
		   }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}
