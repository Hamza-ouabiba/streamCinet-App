#pragma once 
#include "DataBaseConnection.h"  
#include "Movie.h"  
#include "Mani.h"
#include "Serie.h" 
#include"json/json.h"  
#using <System.Net.Http.dll>
#using <System.Runtime.InteropServices.dll>
#include "Login.h"
 
using namespace System::Net::Http;
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
	/// Summary for ViewMovie
	/// </summary>
	public ref class ViewMovie : public System::Windows::Forms::UserControl
	{

	private: System::Windows::Forms::Label^ Category1_label;
	
	private: System::Windows::Forms::Label^ Category2_label;
	private: System::Windows::Forms::Label^ Category3_label;
	private: System::Windows::Forms::Panel^ panel2;

	private: System::Windows::Forms::DataGridView^ dataGridView1;
 

	

	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Episodes;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel6;

	private: System::Windows::Forms::RichTextBox^ Overview;


	public:
		Mani^ l;
		Serie^ serie_;
		Movie^ movie_;
	public:
		int idUser = 30;
		ViewMovie(Movie^ MV)
		{
			InitializeComponent();
		

			movie_ = MV;
			serie_ = gcnew Serie();
			serie_->SetName("");
			Title_label->Text = movie_->GetTitle();
			this->movie_->SetExist(DataBaseOperations::Exist_Movie(movie_->GetIdApi(), Login::User->GetIdUser()));
			this->Overview->Text = movie_->GetOverview();
			this->Overview->ForeColor = this->BackColor;


			this->Rating_label->Text = movie_->GetRating().ToString();
			this->Date_label->Text = movie_->GetRealease_Date().ToString("dd/MM/yyyy");
			label4->Text = "";

			Category1_label->Text = "";
			Category2_label->Text = "";
			Category3_label->Text = "";
			this->panel2->BackgroundImage = movie_->GetBakcDrop();
			//
			//TODO: Add the constructor code here
			//
		}
		ViewMovie(Serie^ Serie)
		{
			InitializeComponent();
		
			movie_ = gcnew Movie();
			movie_->SetTitle("");
			this->serie_ = Serie; 
			this->Title_label->Text = serie_->GetName();
			this->Date_label->Text = serie_->GetRealease_Date().ToString("dd/MM/yyyy");
			this->serie_->SetExist(DataBaseOperations::Exist_Serie(serie_->GetIdApi(), Login::User->GetIdUser()));
			this->Overview->Text = serie_->GetOverview();
			this->Overview->ForeColor = this->BackColor;

			this->Rating_label->Text = serie_->GetRating().ToString();
			//oui
			this->panel2->BackgroundImage = serie_->GetBakcDrop();
			label4->Text = serie_->GetCountry();
			Category1_label->Text = "";
			Category2_label->Text = "";
			Category3_label->Text = ""; 
			
			//TODO: Add the constructor code here
			//
		}


		private: System::Windows::Forms::Button^ BtnLibrary_AddRemove;
		public:
		private: System::Windows::Forms::Label^ Title_label;
		private: System::Windows::Forms::Button^ BtnTrailer;

		private: System::Windows::Forms::Label^ label10;

		private: System::Windows::Forms::Label^ label4;


		private: System::Windows::Forms::Label^ Date_label;

		private: System::Windows::Forms::Label^ Rating_label;
		private: System::Windows::Forms::Panel^ panel1;
	

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ViewMovie()
		{
			if (components)
			{
				delete components;
			}
		}

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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle9 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle10 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->BtnLibrary_AddRemove = (gcnew System::Windows::Forms::Button());
			this->Title_label = (gcnew System::Windows::Forms::Label());
			this->BtnTrailer = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Date_label = (gcnew System::Windows::Forms::Label());
			this->Rating_label = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Episodes = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->Category1_label = (gcnew System::Windows::Forms::Label());
			this->Category2_label = (gcnew System::Windows::Forms::Label());
			this->Category3_label = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->Overview = (gcnew System::Windows::Forms::RichTextBox());
			this->panel1->SuspendLayout();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel6->SuspendLayout();
			this->SuspendLayout();
			// 
			// BtnLibrary_AddRemove
			// 
			this->BtnLibrary_AddRemove->BackColor = System::Drawing::Color::Transparent;
			this->BtnLibrary_AddRemove->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BtnLibrary_AddRemove->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->BtnLibrary_AddRemove->ForeColor = System::Drawing::Color::White;
			this->BtnLibrary_AddRemove->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BtnLibrary_AddRemove->Location = System::Drawing::Point(284, 124);
			this->BtnLibrary_AddRemove->Margin = System::Windows::Forms::Padding(4);
			this->BtnLibrary_AddRemove->Name = L"BtnLibrary_AddRemove";
			this->BtnLibrary_AddRemove->Size = System::Drawing::Size(253, 63);
			this->BtnLibrary_AddRemove->TabIndex = 16;
			this->BtnLibrary_AddRemove->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->BtnLibrary_AddRemove->UseVisualStyleBackColor = false;
			this->BtnLibrary_AddRemove->Click += gcnew System::EventHandler(this, &ViewMovie::BtnLibrary_AddRemove_Click);
			// 
			// Title_label
			// 
			this->Title_label->AutoSize = true;
			this->Title_label->BackColor = System::Drawing::Color::Transparent;
			this->Title_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title_label->ForeColor = System::Drawing::Color::White;
			this->Title_label->Location = System::Drawing::Point(55, 43);
			this->Title_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Title_label->Name = L"Title_label";
			this->Title_label->Size = System::Drawing::Size(215, 31);
			this->Title_label->TabIndex = 27;
			this->Title_label->Text = L"Game of thrones";
			this->Title_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// BtnTrailer
			// 
			this->BtnTrailer->BackColor = System::Drawing::Color::Transparent;
			this->BtnTrailer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BtnTrailer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnTrailer->ForeColor = System::Drawing::Color::White;
			this->BtnTrailer->Location = System::Drawing::Point(65, 124);
			this->BtnTrailer->Margin = System::Windows::Forms::Padding(4);
			this->BtnTrailer->Name = L"BtnTrailer";
			this->BtnTrailer->Size = System::Drawing::Size(167, 63);
			this->BtnTrailer->TabIndex = 15;
			this->BtnTrailer->Text = L"Watch Trailer";
			this->BtnTrailer->UseVisualStyleBackColor = false;
			this->BtnTrailer->Click += gcnew System::EventHandler(this, &ViewMovie::BtnTrailer_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::White;
			this->label10->Location = System::Drawing::Point(4, 0);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(126, 29);
			this->label10->TabIndex = 25;
			this->label10->Text = L"Overview :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(1170, 63);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(86, 31);
			this->label4->TabIndex = 21;
			this->label4->Text = L"label4";
			// 
			// Date_label
			// 
			this->Date_label->AutoSize = true;
			this->Date_label->BackColor = System::Drawing::Color::Transparent;
			this->Date_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Date_label->ForeColor = System::Drawing::Color::White;
			this->Date_label->Location = System::Drawing::Point(55, 281);
			this->Date_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Date_label->Name = L"Date_label";
			this->Date_label->Size = System::Drawing::Size(74, 31);
			this->Date_label->TabIndex = 19;
			this->Date_label->Text = L"2017";
			// 
			// Rating_label
			// 
			this->Rating_label->AutoSize = true;
			this->Rating_label->BackColor = System::Drawing::Color::Transparent;
			this->Rating_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Rating_label->ForeColor = System::Drawing::Color::White;
			this->Rating_label->Location = System::Drawing::Point(257, 281);
			this->Rating_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Rating_label->Name = L"Rating_label";
			this->Rating_label->Size = System::Drawing::Size(86, 31);
			this->Rating_label->TabIndex = 20;
			this->Rating_label->Text = L"label3";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel1->Location = System::Drawing::Point(1311, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(357, 874);
			this->panel1->TabIndex = 28;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->dataGridView1);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(0, 82);
			this->panel4->Margin = System::Windows::Forms::Padding(4);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(357, 792);
			this->panel4->TabIndex = 2;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle9->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			dataGridViewCellStyle9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle9->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle9->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle9->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle9->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle9;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Episodes });
			dataGridViewCellStyle10->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(52)));
			dataGridViewCellStyle10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle10->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle10->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle10->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle10->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle10;
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 40;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(357, 792);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ViewMovie::dataGridView1_CellContentClick);
			this->dataGridView1->DoubleClick += gcnew System::EventHandler(this, &ViewMovie::dataGridView1_DoubleClick);
			// 
			// Episodes
			// 
			this->Episodes->HeaderText = L"Episodes";
			this->Episodes->MinimumWidth = 6;
			this->Episodes->Name = L"Episodes";
			this->Episodes->ReadOnly = true;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Transparent;
			this->panel3->Controls->Add(this->comboBox1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel3->Location = System::Drawing::Point(0, 0);
			this->panel3->Margin = System::Windows::Forms::Padding(4);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(357, 82);
			this->panel3->TabIndex = 1;
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(32, 20);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(280, 33);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &ViewMovie::comboBox1_SelectedIndexChanged);
			// 
			// Category1_label
			// 
			this->Category1_label->AutoSize = true;
			this->Category1_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Category1_label->ForeColor = System::Drawing::Color::White;
			this->Category1_label->Location = System::Drawing::Point(55, 353);
			this->Category1_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Category1_label->Name = L"Category1_label";
			this->Category1_label->Size = System::Drawing::Size(86, 31);
			this->Category1_label->TabIndex = 29;
			this->Category1_label->Text = L"label1";
			// 
			// Category2_label
			// 
			this->Category2_label->AutoSize = true;
			this->Category2_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Category2_label->ForeColor = System::Drawing::Color::White;
			this->Category2_label->Location = System::Drawing::Point(200, 353);
			this->Category2_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Category2_label->Name = L"Category2_label";
			this->Category2_label->Size = System::Drawing::Size(86, 31);
			this->Category2_label->TabIndex = 30;
			this->Category2_label->Text = L"label1";
			// 
			// Category3_label
			// 
			this->Category3_label->AutoSize = true;
			this->Category3_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Category3_label->ForeColor = System::Drawing::Color::White;
			this->Category3_label->Location = System::Drawing::Point(365, 353);
			this->Category3_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Category3_label->Name = L"Category3_label";
			this->Category3_label->Size = System::Drawing::Size(86, 31);
			this->Category3_label->TabIndex = 31;
			this->Category3_label->Text = L"label1";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel2->Controls->Add(this->panel6);
			this->panel2->Controls->Add(this->Title_label);
			this->panel2->Controls->Add(this->Category3_label);
			this->panel2->Controls->Add(this->BtnTrailer);
			this->panel2->Controls->Add(this->Category2_label);
			this->panel2->Controls->Add(this->Rating_label);
			this->panel2->Controls->Add(this->Category1_label);
			this->panel2->Controls->Add(this->Date_label);
			this->panel2->Controls->Add(this->BtnLibrary_AddRemove);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1311, 874);
			this->panel2->TabIndex = 32;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ViewMovie::panel2_Paint);
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->Overview);
			this->panel6->Controls->Add(this->label10);
			this->panel6->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel6->Location = System::Drawing::Point(0, 632);
			this->panel6->Margin = System::Windows::Forms::Padding(4);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(1311, 242);
			this->panel6->TabIndex = 33;
			// 
			// Overview
			// 
			this->Overview->BackColor = System::Drawing::Color::White;
			this->Overview->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Overview->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->Overview->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Overview->ForeColor = System::Drawing::Color::Black;
			this->Overview->Location = System::Drawing::Point(0, 33);
			this->Overview->Margin = System::Windows::Forms::Padding(4);
			this->Overview->Name = L"Overview";
			this->Overview->Size = System::Drawing::Size(1311, 209);
			this->Overview->TabIndex = 34;
			this->Overview->Text = L"okokok";
			// 
			// ViewMovie
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"ViewMovie";
			this->Size = System::Drawing::Size(1668, 874);
			this->Load += gcnew System::EventHandler(this, &ViewMovie::ViewMovie_Load);
			this->panel1->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	 

		///:::::::::://////:DATA BASE ://////:::::::::://////::::::::::///

		void Insert_Serie_Category(int idApiCategory) {
			try {
				SqlConnection conx(DataBaseConnection::ConnectionString());
				conx.Open();
				String^ Query = "INSERT INTO SERIECATEGORY(ID_CATEGORY,ID_SERIE) VALUES(@ID_API, @ID_SERIE); ";
				SqlCommand Command(Query, % conx);
				Command.Parameters->AddWithValue("@ID_API", DataBaseOperations::GetIdCategory_Serie(idApiCategory));
				Command.Parameters->AddWithValue("@ID_SERIE", serie_->GetIdSerie());
				Command.ExecuteNonQuery();
				conx.Close();
				movie_->SetExist(true);

			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}
		void AddCategoryToSerie(int idApiMovie) {

			String^ Url = "https://api.themoviedb.org/3/tv/" + idApiMovie + "?api_key=10f96818301b77e61d73d48aa20d81f9";


			HttpClient^ client = gcnew HttpClient();

			HttpResponseMessage^ response = client->GetAsync(Url)->Result;

			String^ jsonString = response->Content->ReadAsStringAsync()->Result;

			std::string jsonString2 = msclr::interop::marshal_as<std::string>(jsonString);

			/// ::::////////////////////////////////////////////////////////////////

			if (response->IsSuccessStatusCode)
			{
				// Response looks good - done using Curl now.  Try to parse the results
				// and print them out.#using <mscorlib.dll>
				//jsonData["results"][i]["original_title"]
				Json::Value jsonData;
				Json::Reader jsonReader;

				Json::StreamWriterBuilder builder;
				builder["indentation"] = "";


				if (jsonReader.parse(jsonString2, jsonData))
				{
					for (int i = 0; i < 3; i++)
					{
						int idcategory = jsonData["genres"][i]["id"].asInt();
						if (idcategory) {
							Insert_Serie_Category(idcategory);
						}
						else {
							break;
						}

					}
				}
			}
		}
		void AddToWatchListSerie(int ID_SERIE) {
			try {
				SqlConnection conx(DataBaseConnection::ConnectionString());
				conx.Open();
				String^ Query = "INSERT INTO Library_Serie(ID_SERIE,ID_USER) VALUES(@ID_SERIE,@ID_USER); ";
				SqlCommand Command(Query, % conx);
				Command.Parameters->AddWithValue("@ID_USER", Login::User->GetIdUser());
				Command.Parameters->AddWithValue("@ID_SERIE", ID_SERIE);

				Command.ExecuteNonQuery();

				conx.Close();

			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}

		}

		void AddToDataBase_Serie() {

			try {
				SqlConnection conx(DataBaseConnection::ConnectionString());
				conx.Open();
				if (DataBaseOperations::GetIdSerieByApi(serie_->GetIdApi()) == -1) {


					String^ Query = "INSERT INTO SERIE(ID_API,TITLE,RATING,RELEASE_DATE,OVERVIEW,POSTER,BACKDROP,COUNTRY) VALUES(@ID_API,@TITLE,@RATING,@RELEASE_DATE,@OVERVIEW,@POSTER,@BACKDROP,@COUNTRY); ";
					SqlCommand Command(Query, % conx);
					Command.Parameters->AddWithValue("@TITLE", serie_->GetName());
					Command.Parameters->AddWithValue("@ID_API", serie_->GetIdApi());
					Command.Parameters->AddWithValue("@RATING", serie_->GetRating());
					Command.Parameters->AddWithValue("@RELEASE_DATE", serie_->GetRealease_Date());
					Command.Parameters->AddWithValue("@OVERVIEW", serie_->GetOverview());
					Command.Parameters->AddWithValue("@COUNTRY", serie_->GetCountry());

					MemoryStream^ ms;
					try {
						ms = gcnew MemoryStream();
						serie_->GetPoster()->Save(ms, System::Drawing::Imaging::ImageFormat::Jpeg);
						Command.Parameters->AddWithValue("@POSTER", ms->ToArray());

						ms = gcnew MemoryStream();
						serie_->GetBakcDrop()->Save(ms, System::Drawing::Imaging::ImageFormat::Jpeg);
						Command.Parameters->AddWithValue("@BACKDROP", ms->ToArray());

					}
					catch (Exception^ ex) {
						MessageBox::Show(ex->Message);
					}
					finally {
						ms->Close();
					}

					Command.ExecuteNonQuery();

					//
					serie_->SetIdSerie(DataBaseOperations::LastInsertedSerie());

					AddCategoryToSerie(serie_->GetIdApi());

				}
				else {
					serie_->SetIdSerie(DataBaseOperations::GetIdSerieByApi(serie_->GetIdApi()));
				}

				//add to  Library_Serie
				AddToWatchListSerie(serie_->GetIdSerie());

				serie_->SetExist(true);
				conx.Close();

			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}


		}

		void DisplayCategory_Serie_FromDataBase() {
			try {
				int i = 1;
				SqlConnection conx(DataBaseConnection::ConnectionString());
				String^ queryString = "SELECT ID_CATEGORY FROM SERIECATEGORY where ID_SERIE = @ID_SERIE;";
				// select CATEGORY from CATEGORY where ID_CATEGORY = any(SELECT ID_CATEGORY FROM MOVIECATEGORY where ID_MOVIE = 109)
				SqlCommand^ command = gcnew SqlCommand(queryString, % conx);
				command->Parameters->AddWithValue("@ID_SERIE", serie_->GetIdSerie());

				conx.Open();

				SqlDataReader^ reader = command->ExecuteReader();
				while (reader->Read())
				{
					if (i == 1) {

						Category1_label->Text = DataBaseOperations::CategorySerie_ByIdCategory(Convert::ToInt32(reader[0]->ToString()));
					}
					else if (i == 2) {
						Category2_label->Text = DataBaseOperations::CategorySerie_ByIdCategory(Convert::ToInt32(reader[0]->ToString()));
					}
					else if (i == 3) {
						Category3_label->Text = DataBaseOperations::CategorySerie_ByIdCategory(Convert::ToInt32(reader[0]->ToString()));
					}
					i++;
				}
				conx.Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}

		}
	 


		void RemoveFromDataBase_Serie() {
			try {

				SqlConnection conx(DataBaseConnection::ConnectionString());
				conx.Open();
				String^ Query = "DELETE FROM Library_Serie where ID_SERIE = @ID_SERIE and ID_USER=@ID_USER;";
				SqlCommand Command(Query, % conx);
				Command.Parameters->AddWithValue("@ID_SERIE", serie_->GetIdSerie());
				Command.Parameters->AddWithValue("@ID_USER", Login::User->GetIdUser());
				Command.ExecuteNonQuery();
				conx.Close(); 

				serie_->SetExist(false);
				
				try {

					SqlConnection conx(DataBaseConnection::ConnectionString());
					conx.Open();
					String^ Query = "DELETE FROM SERIE where ID_SERIE not in (SELECT ID_SERIE FROM Library_Serie) ;";
					SqlCommand Command(Query, % conx); 
					Command.ExecuteNonQuery();
					conx.Close();

				}
				catch (Exception^ ex) {
					MessageBox::Show(ex->Message);
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}
		void AddEpisodeToEp(int idApiMovie) {

			String^ Url = "https://api.themoviedb.org/3/tv/114410/season/1?api_key=10f96818301b77e61d73d48aa20d81f9";

			HttpClient^ client = gcnew HttpClient();

			HttpResponseMessage^ response = client->GetAsync(Url)->Result;

			String^ jsonString = response->Content->ReadAsStringAsync()->Result;

			std::string jsonString2 = msclr::interop::marshal_as<std::string>(jsonString);

			/// ::::////////////////////////////////////////////////////////////////

			if (response->IsSuccessStatusCode)
			{
				// Response looks good - done using Curl now.  Try to parse the results
				// and print them out.#using <mscorlib.dll>
				//jsonData["results"][i]["original_title"]
				Json::Value jsonData;
				Json::Reader jsonReader;

				Json::StreamWriterBuilder builder;
				builder["indentation"] = "";


				if (jsonReader.parse(jsonString2, jsonData))
				{
					for (int i = 0; i < 3; i++)
					{
						int idcategory = jsonData["genres"][i]["id"].asInt();
						if (idcategory) {
							Insert_Serie_Category(idcategory);
						}
						else {
							break;
						}

					}
				}
			}
		}

		void DisplayCategory_Serie_FromApi() {
			try {


				String^ Url = "https://api.themoviedb.org/3/tv/" + serie_->GetIdApi() + "?api_key=10f96818301b77e61d73d48aa20d81f9";
				HttpClient^ client = gcnew HttpClient();


				HttpResponseMessage^ response = client->GetAsync(Url)->Result;

				String^ jsonString = response->Content->ReadAsStringAsync()->Result;

				std::string jsonString2 = msclr::interop::marshal_as<std::string>(jsonString);


				if (response->IsSuccessStatusCode)
				{
					// Response looks good - done using Curl now.  Try to parse the results
					// and print them out.
					//jsonData["results"][i]["original_title"]
					Json::Value jsonData;
					Json::Reader jsonReader;

					Json::StreamWriterBuilder builder;
					builder["indentation"] = "";


					if (jsonReader.parse(jsonString2, jsonData))
					{
						for (int i = 0; i < 3; i++)

							for (int i = 0; i < 3; i++)
							{
								int idcategory = jsonData["genres"][i]["id"].asInt();
								if (idcategory) {
									if (i == 0) {
										Category1_label->Text = DataBaseOperations::CategorySerie_ByIdApiCategory(idcategory);
									}
									else if (i == 1) {
										Category2_label->Text = DataBaseOperations::CategorySerie_ByIdApiCategory(idcategory);
									}
									else if (i == 2) {
										Category3_label->Text = DataBaseOperations::CategorySerie_ByIdApiCategory(idcategory);
									}
								}
								else {
									break;
								}

							}
					}
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}
		/// ///////////API //	/// ///////////
		void DisplayEpisodes_Serie_FromApi(int Season) {
			try {

				String^ Url = "https://api.themoviedb.org/3/tv/" + serie_->GetIdApi() + "/season/" + Season + "?api_key=10f96818301b77e61d73d48aa20d81f9";
				HttpClient^ client = gcnew HttpClient();


				HttpResponseMessage^ response = client->GetAsync(Url)->Result;

				String^ jsonString = response->Content->ReadAsStringAsync()->Result;

				std::string jsonString2 = msclr::interop::marshal_as<std::string>(jsonString);


				if (response->IsSuccessStatusCode)
				{
					// Response looks good - done using Curl now.  Try to parse the results
					// and print them out.
					//jsonData["results"][i]["original_title"]
					Json::Value jsonData;
					Json::Reader jsonReader;


					if (jsonReader.parse(jsonString2, jsonData))
					{
						int i = 0;

						int Season = jsonData["episodes"][i]["season_number"].asInt();
						dataGridView1->Rows->Clear();
						while (true) {
							int Episode = jsonData["episodes"][i]["episode_number"].asInt();

							if (Episode) {
								string title1 = jsonData["episodes"][i]["name"].toStyledString();
								title1.erase(remove(title1.begin(), title1.end(), '"'), title1.end());
								String^ name = msclr::interop::marshal_as<System::String^>(title1);

								string title = jsonData["episodes"][i]["overview"].toStyledString();
								title.erase(remove(title.begin(), title.end(), '"'), title.end());
								String^ overview = msclr::interop::marshal_as<System::String^>(title);

								dataGridView1->Rows->Add(Episode + " - " + name);
								i++;
							}
							else {
								break;
							}
						}

					}
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}

		String ^Overview_Episode_FromApi(int Season,int Episode){
			try {
		 
				String^ Url = "https://api.themoviedb.org/3/tv/" + serie_->GetIdApi() + "/season/" + Season + "/episode/"+ Episode +"?api_key=10f96818301b77e61d73d48aa20d81f9";
				HttpClient^ client = gcnew HttpClient();


				HttpResponseMessage^ response = client->GetAsync(Url)->Result;

				String^ jsonString = response->Content->ReadAsStringAsync()->Result;

				std::string jsonString2 = msclr::interop::marshal_as<std::string>(jsonString);


				if (response->IsSuccessStatusCode)
				{
					// Response looks good - done using Curl now.  Try to parse the results
					// and print them out.
					//jsonData["results"][i]["original_title"]
					Json::Value jsonData;
					Json::Reader jsonReader;


					if (jsonReader.parse(jsonString2, jsonData))
					{
						int i = 0;
						string title = jsonData["overview"].toStyledString();
						title.erase(remove(title.begin(), title.end(), '"'), title.end());
						String^ overview = msclr::interop::marshal_as<System::String^>(title);
					
						return overview;

					}
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}
		void LoadSeasonsFromApi() {

			try {
				String^ Url = "https://api.themoviedb.org/3/tv/" + serie_->GetIdApi() + "?api_key=10f96818301b77e61d73d48aa20d81f9";
				HttpClient^ client = gcnew HttpClient();


				HttpResponseMessage^ response = client->GetAsync(Url)->Result;

				String^ jsonString = response->Content->ReadAsStringAsync()->Result;

				std::string jsonString2 = msclr::interop::marshal_as<std::string>(jsonString);


				if (response->IsSuccessStatusCode)
				{
					// Response looks good - done using Curl now.  Try to parse the results
					// and print them out.
					//jsonData["results"][i]["original_title"]
					Json::Value jsonData;
					Json::Reader jsonReader;


					if (jsonReader.parse(jsonString2, jsonData))
					{

						comboBox1->Items->Clear();

						int Seasons = jsonData["number_of_seasons"].asInt();

						for (int i = 1; i <= Seasons; i++) {

							comboBox1->Items->Add("Season " + i);

						}

					}
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}
		void Display_Serie_FromApi() {
			try {


				String^ Url = "https://api.themoviedb.org/3/movie/" + movie_->GetIdApi() + "?api_key=10f96818301b77e61d73d48aa20d81f9";
				HttpClient^ client = gcnew HttpClient();


				HttpResponseMessage^ response = client->GetAsync(Url)->Result;

				String^ jsonString = response->Content->ReadAsStringAsync()->Result;

				std::string jsonString2 = msclr::interop::marshal_as<std::string>(jsonString);


				if (response->IsSuccessStatusCode)
				{
					// Response looks good - done using Curl now.  Try to parse the results
					// and print them out.
					//jsonData["results"][i]["original_title"]
					Json::Value jsonData;
					Json::Reader jsonReader;

					Json::StreamWriterBuilder builder;
					builder["indentation"] = "";


					if (jsonReader.parse(jsonString2, jsonData))
					{
						for (int i = 0; i < 3; i++)

							for (int i = 0; i < 3; i++)
							{
								int idcategory = jsonData["genres"][i]["id"].asInt();
								if (idcategory) {
									if (i == 0) {
										Category1_label->Text = DataBaseOperations::CategoryMovie_ByIdApiCategory(idcategory);
									}
									else if (i == 1) {
										Category2_label->Text = DataBaseOperations::CategoryMovie_ByIdApiCategory(idcategory);
									}
									else if (i == 2) {
										Category3_label->Text = DataBaseOperations::CategoryMovie_ByIdApiCategory(idcategory);
									}
								}
								else {
									break;
								}

							}
					}
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}



		/////////////////////////////Movie:::::::::////////////////////////////


		void Insert_Movie_Category(int idApiCategory) {
			try {
				SqlConnection conx(DataBaseConnection::ConnectionString());
				conx.Open();
				String^ Query = "INSERT INTO MOVIECATEGORY(ID_CATEGORY,ID_MOVIE) VALUES(@ID_API, @ID_MOVIE) ; ";
				SqlCommand Command(Query, % conx);
				Command.Parameters->AddWithValue("@ID_API", DataBaseOperations::GetIdCategory_Movie(idApiCategory));
				Command.Parameters->AddWithValue("@ID_MOVIE", movie_->GetIdMovie());
				Command.ExecuteNonQuery();
				conx.Close();
				movie_->SetExist(true);

			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}

		void AddCategoryToMovie(int idApiMovie) {

			String^ Url = "https://api.themoviedb.org/3/movie/" + idApiMovie + "?api_key=10f96818301b77e61d73d48aa20d81f9";
			HttpClient^ client = gcnew HttpClient();

			HttpResponseMessage^ response = client->GetAsync(Url)->Result;

			String^ jsonString = response->Content->ReadAsStringAsync()->Result;

			std::string jsonString2 = msclr::interop::marshal_as<std::string>(jsonString);

			/// ::::////////////////////////////////////////////////////////////////

			if (response->IsSuccessStatusCode)
			{
				// Response looks good - done using Curl now.  Try to parse the results
				// and print them out.
				//jsonData["results"][i]["original_title"]
				Json::Value jsonData;
				Json::Reader jsonReader;

				Json::StreamWriterBuilder builder;
				builder["indentation"] = "";


				if (jsonReader.parse(jsonString2, jsonData))
				{
					for (int i = 0; i < 3; i++)
					{
						int idcategory = jsonData["genres"][i]["id"].asInt();
						if (idcategory) {
							Insert_Movie_Category(idcategory);
						}
						else {
							break;
						}

					}//att nchof wa7d l9ta : ma3rrt : 
				}
			}
		}
		void AddToWatchListMovie(int ID_MOVIE) {
			try {
				SqlConnection conx(DataBaseConnection::ConnectionString());
				conx.Open();
				String^ Query = "INSERT INTO Library_Movie(ID_MOVIE,ID_USER) VALUES(@ID_MOVIE,@ID_USER); ";
				SqlCommand Command(Query, % conx);
				Command.Parameters->AddWithValue("@ID_USER", Login::User->GetIdUser());
				//njreb hna ???
				Command.Parameters->AddWithValue("@ID_MOVIE", ID_MOVIE);
				//non
				Command.ExecuteNonQuery();

				conx.Close();

			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}

		}

		void AddToDataBase_Movie() {

		try {

				SqlConnection conx(DataBaseConnection::ConnectionString());
				conx.Open();
			 if (DataBaseOperations::GetIdMovieByApi(movie_->GetIdApi()) == -1) {
 
					String^ Query = "INSERT INTO MOVIE(ID_API,TITLE,RATING,RELEASE_DATE,OVERVIEW,POSTER,BACKDROP) VALUES(@ID_API,@TITLE,@RATING,@RELEASE_DATE,@OVERVIEW,@POSTER,@BACKDROP); ";
					SqlCommand Command(Query, % conx);
					Command.Parameters->AddWithValue("@TITLE", movie_->GetTitle());
					Command.Parameters->AddWithValue("@ID_API", movie_->GetIdApi());
					Command.Parameters->AddWithValue("@RATING", movie_->GetRating());
					Command.Parameters->AddWithValue("@RELEASE_DATE", movie_->GetRealease_Date());
					Command.Parameters->AddWithValue("@OVERVIEW", movie_->GetOverview());
					MemoryStream^ ms;
					try {
						ms = gcnew MemoryStream();
						movie_->GetPoster()->Save(ms, System::Drawing::Imaging::ImageFormat::Jpeg);
						Command.Parameters->AddWithValue("@POSTER", ms->ToArray());

						ms = gcnew MemoryStream();
						movie_->GetBakcDrop()->Save(ms, System::Drawing::Imaging::ImageFormat::Jpeg);
						Command.Parameters->AddWithValue("@BACKDROP", ms->ToArray());
					}
					finally {
						ms->Close();
					}
					Command.ExecuteNonQuery();
					movie_->SetIdMovie(DataBaseOperations::LastInsertedMovie());
					//i9der;: 
					MessageBox::Show(Convert::ToString(DataBaseOperations::LastInsertedMovie()));

					// add to Library_Movie
					AddCategoryToMovie(movie_->GetIdApi());
				  
				}
				else {
					movie_->SetIdMovie(DataBaseOperations::GetIdMovieByApi(movie_->GetIdApi()));
				}
			 ///ouii else : 
				movie_->SetExist(true);
				AddToWatchListMovie(movie_->GetIdMovie());

				 conx.Close();

			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}


		}
		void RemoveFromDataBase_Movie() {
			try {

				SqlConnection conx(DataBaseConnection::ConnectionString());
				conx.Open();
				//had les parametres han7iydhom @à
				String^ Query = "DELETE FROM Library_Movie where ID_MOVIE = " + movie_->GetIdMovie() + " and ID_USER = " + Login::User->GetIdUser();
				MessageBox::Show(Query);
				SqlCommand Command(Query, % conx);
				/*Command.Parameters->AddWithValue("@ID_MOVIE", movie_->GetIdMovie());
				Command.Parameters->AddWithValue("@ID_USER", Login::User->GetIdUser());*/
				Command.ExecuteNonQuery();
				conx.Close();

				movie_->SetExist(false);

				try {

					SqlConnection conx(DataBaseConnection::ConnectionString());
					conx.Open();
					String^ Query = "DELETE FROM SERIE where ID_SERIE not in (SELECT ID_SERIE FROM Library_Serie) ;";
					SqlCommand Command(Query, % conx);
					Command.ExecuteNonQuery();
					conx.Close();

				}
				catch (Exception^ ex) {
					MessageBox::Show(ex->Message);
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}
		void DisplayCategory_Movie_FromDataBase() {
			try {
				int i = 1;
				SqlConnection conx(DataBaseConnection::ConnectionString());
				String^ queryString = "SELECT ID_CATEGORY FROM MOVIECATEGORY where ID_MOVIE = @ID_MOVIE;";
				// select CATEGORY from CATEGORY where ID_CATEGORY = any(SELECT ID_CATEGORY FROM MOVIECATEGORY where ID_MOVIE = 109)
				SqlCommand^ command = gcnew SqlCommand(queryString, % conx);
				command->Parameters->AddWithValue("@ID_MOVIE", movie_->GetIdMovie());

				conx.Open();

				SqlDataReader^ reader = command->ExecuteReader();
				while (reader->Read())
				{
					if (i == 1) {

						Category1_label->Text = DataBaseOperations::CategoryMovie_ByIdCategory(Convert::ToInt32(reader[0]->ToString()));
					}
					else if (i == 2) {
						Category2_label->Text = DataBaseOperations::CategoryMovie_ByIdCategory(Convert::ToInt32(reader[0]->ToString()));
					}
					else if (i == 3) {
						Category3_label->Text = DataBaseOperations::CategoryMovie_ByIdCategory(Convert::ToInt32(reader[0]->ToString()));
					}
					i++;
				}
				conx.Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}

		}
		void DisplayCategory_Movie_FromApi() {
			try {


				String^ Url = "https://api.themoviedb.org/3/movie/" + movie_->GetIdApi() + "?api_key=10f96818301b77e61d73d48aa20d81f9";
				HttpClient^ client = gcnew HttpClient();


				HttpResponseMessage^ response = client->GetAsync(Url)->Result;

				String^ jsonString = response->Content->ReadAsStringAsync()->Result;

				std::string jsonString2 = msclr::interop::marshal_as<std::string>(jsonString);


				if (response->IsSuccessStatusCode)
				{
					// Response looks good - done using Curl now.  Try to parse the results
					// and print them out.
					//jsonData["results"][i]["original_title"]
					Json::Value jsonData;
					Json::Reader jsonReader;

					Json::StreamWriterBuilder builder;
					builder["indentation"] = "";


					if (jsonReader.parse(jsonString2, jsonData))
					{
						for (int i = 0; i < 3; i++)

							for (int i = 0; i < 3; i++)
							{
								int idcategory = jsonData["genres"][i]["id"].asInt();
								if (idcategory) {
									if (i == 0) {
										Category1_label->Text = DataBaseOperations::CategoryMovie_ByIdApiCategory(idcategory);
									}
									else if (i == 1) {
										Category2_label->Text = DataBaseOperations::CategoryMovie_ByIdApiCategory(idcategory);
									}
									else if (i == 2) {
										Category3_label->Text = DataBaseOperations::CategoryMovie_ByIdApiCategory(idcategory);
									}
								}
								else {
									break;
								}

							}
					}
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}

		///:::::::::://///:::::::::://////:::::::::://////::::::::::///


	private: System::Void ViewMovie_Load(System::Object^ sender, System::EventArgs^ e) {

		if (movie_->GetTitle() != "") {
			//saaat rah db khs normalement f load dyal discovery wach kadar liha setexsit : 
			//hna ila messagitiha ghatkon false : makayn lach : 
			//nsetti exist hna : 

			if (movie_->GetExist()) {
				panel1->Visible = false;
				DisplayCategory_Movie_FromDataBase();
				BtnLibrary_AddRemove->Text = "Remove from Library";
				BtnLibrary_AddRemove->Image = Image::FromFile("icons\\remove.png");

			}
			else {
		
				DisplayCategory_Movie_FromApi();
				BtnLibrary_AddRemove->Text = "Add To Library";
				BtnLibrary_AddRemove->Image = Image::FromFile("icons\\add.png");

			}
		}
		else if(serie_->GetName() != "") {
			panel1->Visible = true;
			if (serie_->GetExist()) { 
				
				LoadSeasonsFromApi();
				comboBox1->SelectedIndex = 0;

				DisplayEpisodes_Serie_FromApi(1);
				DisplayCategory_Serie_FromDataBase();

				BtnLibrary_AddRemove->Text = "Remove from Library";
				BtnLibrary_AddRemove->Image = Image::FromFile("icons\\remove.png");

			}
			else {
				LoadSeasonsFromApi();
				comboBox1->SelectedIndex = 0;
				DisplayEpisodes_Serie_FromApi(1);
				 

				DisplayCategory_Serie_FromApi();
				BtnLibrary_AddRemove->Text = "Add To Library";
				BtnLibrary_AddRemove->Image = Image::FromFile("icons\\add.png");

			}
		}
		


	}
	private: System::Void BtnLibrary_AddRemove_Click(System::Object^ sender, System::EventArgs^ e) {

		if (Login::User) {

			if (movie_->GetTitle() != "") {

				if (movie_->GetExist()) {
					RemoveFromDataBase_Movie();
					BtnLibrary_AddRemove->Text = "Add To Library";
					BtnLibrary_AddRemove->Image = Image::FromFile("icons\\add.png");
				}
				else {
					AddToDataBase_Movie();
					BtnLibrary_AddRemove->Text = "Remove from Library";
					BtnLibrary_AddRemove->Image = Image::FromFile("icons\\remove.png");
				}

				//BtnLibrary_AddRemove->ImageAlign = ImageAlign::MiddleLeft;

			}
			else if (serie_->GetName() != "") {
				if (serie_->GetExist()) {
					RemoveFromDataBase_Serie();
					BtnLibrary_AddRemove->Text = "Add To Library";
					BtnLibrary_AddRemove->Image = Image::FromFile("icons\\add.png");
				}
				else {
					AddToDataBase_Serie();
					BtnLibrary_AddRemove->Text = "Remove from Library";
					BtnLibrary_AddRemove->Image = Image::FromFile("icons\\remove.png");
				}

			}
		}
		else {
			Login^ form = gcnew Login();
			form->Show();
		}
	}
private: System::Void BtnTrailer_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ ytbLink = "https://www.youtube.com/watch?v=";
	if (movie_->GetTitle() != "")
	{
		String^ idApiMovie = Convert::ToString(movie_->GetIdApi());
		String^ keyTrailer = l->getTrailer(msclr::interop::marshal_as<std::string>(idApiMovie));
		if (keyTrailer != "")
			System::Diagnostics::Process::Start(ytbLink + l->getTrailer(msclr::interop::marshal_as<std::string>(idApiMovie)));
		else
			MessageBox::Show("no available trailer for this movie :( ");
	}
	else
	{
		String^ idApiSerie = Convert::ToString(serie_->GetIdApi());
		String^ keyTrailer = l->getTrailer(msclr::interop::marshal_as<std::string>(idApiSerie));
		if (keyTrailer != "")
			System::Diagnostics::Process::Start(ytbLink + l->getTrailer(msclr::interop::marshal_as<std::string>(idApiSerie)));
		else
			MessageBox::Show("no available trailer for this serie :(");
	}
}
private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
 
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

	
	if (serie_->GetName() != "" && comboBox1->Text !="") {
		if (serie_->GetExist()) { 

			DisplayEpisodes_Serie_FromApi(comboBox1->SelectedIndex+1);
			  
			DisplayCategory_Serie_FromDataBase();
			BtnLibrary_AddRemove->Text = "Remove from Library";
			BtnLibrary_AddRemove->Image = Image::FromFile("icons\\remove.png");

		}
		else { 
			DisplayEpisodes_Serie_FromApi(comboBox1->SelectedIndex + 1); 

			DisplayCategory_Serie_FromApi();
			BtnLibrary_AddRemove->Text = "Add To Library";
			BtnLibrary_AddRemove->Image = Image::FromFile("icons\\add.png");

		}
	}
}
 
 
private: System::Void dataGridView1_DoubleClick(System::Object^ sender, System::EventArgs^ e) {


	int selectedRowIndex;

	if (dataGridView1->SelectedRows->Count > 0)
	{
		selectedRowIndex = dataGridView1->SelectedRows[0]->Index;
		Overview->Text = Overview_Episode_FromApi(comboBox1->SelectedIndex + 1, selectedRowIndex + 1);

	}
}
 
 
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}
