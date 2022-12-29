#pragma once
#include "BlankUserControl.h"
#include "DaysUserControl.h"
#include "PosterPlanning.h"
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
	/// Description résumée de Calendar_uc
	/// </summary>
	public ref class Calendar_uc : public System::Windows::Forms::UserControl
	{
		static int month = DateTime::Now.Month;
		static int days = DateTime::Now.Day;
	private: System::Windows::Forms::FlowLayoutPanel^ listPanel;


		   static int year = DateTime::Now.Year;
	public:
		Calendar_uc()
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
		~Calendar_uc()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::FlowLayoutPanel^ calendarPan;
	private: System::Windows::Forms::Button^ prevBtn;
	private: System::Windows::Forms::Button^ nextBtn;
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
			this->calendarPan = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->prevBtn = (gcnew System::Windows::Forms::Button());
			this->nextBtn = (gcnew System::Windows::Forms::Button());
			this->listPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SuspendLayout();
			// 
			// calendarPan
			// 
			this->calendarPan->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->calendarPan->Location = System::Drawing::Point(0, 61);
			this->calendarPan->Name = L"calendarPan";
			this->calendarPan->Size = System::Drawing::Size(1059, 675);
			this->calendarPan->TabIndex = 0;
			// 
			// prevBtn
			// 
			this->prevBtn->Location = System::Drawing::Point(396, 13);
			this->prevBtn->Name = L"prevBtn";
			this->prevBtn->Size = System::Drawing::Size(99, 38);
			this->prevBtn->TabIndex = 1;
			this->prevBtn->Text = L"<";
			this->prevBtn->UseVisualStyleBackColor = true;
			this->prevBtn->Click += gcnew System::EventHandler(this, &Calendar_uc::prevBtn_Click);
			// 
			// nextBtn
			// 
			this->nextBtn->Location = System::Drawing::Point(944, 15);
			this->nextBtn->Name = L"nextBtn";
			this->nextBtn->Size = System::Drawing::Size(99, 38);
			this->nextBtn->TabIndex = 2;
			this->nextBtn->Text = L">";
			this->nextBtn->UseVisualStyleBackColor = true;
			this->nextBtn->Click += gcnew System::EventHandler(this, &Calendar_uc::nextBtn_Click);
			// 
			// listPanel
			// 
			this->listPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->listPanel->Location = System::Drawing::Point(1058, 0);
			this->listPanel->Name = L"listPanel";
			this->listPanel->Size = System::Drawing::Size(302, 736);
			this->listPanel->TabIndex = 3;
			// 
			// Calendar_uc
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->listPanel);
			this->Controls->Add(this->nextBtn);
			this->Controls->Add(this->prevBtn);
			this->Controls->Add(this->calendarPan);
			this->Name = L"Calendar_uc";
			this->Size = System::Drawing::Size(1360, 736);
			this->Load += gcnew System::EventHandler(this, &Calendar_uc::Calendar_uc_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void Calendar_uc_Load(System::Object^ sender, System::EventArgs^ e) {
		////to get days of month from sql server : 
		//SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
		//String^ Query = "select DAY(EOMONTH('2023-02-09')) days;";
		//SqlCommand Cmd(Query, % conx);
		//conx.Open();
		//SqlDataReader^ sqlReader = Cmd.ExecuteReader();
		///*int count = Convert::ToInt32(sqlReader["days"]->ToString());
		//MessageBox::Show("le temps est : " + count);*/
		//if (sqlReader->Read())
		//{
		//	int count = Convert::ToInt32(sqlReader[0]->ToString());
		//	for (int i = 1;i <= count;i++)
		//	{
		//		DaysUserControl^ du = gcnew DaysUserControl(i); 
		//		calendarPan->Controls->Add(du);
		//	}
		//}
		//first day of month : 
		DateTime start = DateTime(year,month,1);
		int days = DateTime::DaysInMonth(year,month);
		int daysOfWeek = Convert::ToInt32(start.DayOfWeek.ToString("d")) + 1;
		for (int i = 1;i < daysOfWeek;i++)
		{
			BlankUserControl^ bk = gcnew BlankUserControl();
			this->calendarPan->Controls->Add(bk);
		}
		for (int i = 1;i <= days;i++)
		{
			DaysUserControl^ uc = gcnew DaysUserControl(i, month, year);
			this->calendarPan->Controls->Add(uc);
			uc->setPanel(this->calendarPan);
		}
		
	}
	private: System::Void prevBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (month == 1)
		{
			month = 13;
			year--;
		}
		month--;
		//first day of month : 
		this->calendarPan->Controls->Clear();
		DateTime start = DateTime(year, month, 1);
		int days = DateTime::DaysInMonth(year, month);
		int daysOfWeek = Convert::ToInt32(start.DayOfWeek.ToString("d")) +1;
		if (daysOfWeek == 0)
			daysOfWeek = 7;
		for (int i = 1;i < daysOfWeek;i++)
		{
			BlankUserControl^ bk = gcnew BlankUserControl();
			this->calendarPan->Controls->Add(bk);
		}
		for (int i = 1;i <= days;i++)
		{
			DaysUserControl^ uc = gcnew DaysUserControl(i,month,year);
			this->calendarPan->Controls->Add(uc);
			uc->setPanel(this->calendarPan);
		}
	}
	//private: void loadData()
	//{
	//	SqlConnection conx("Data Source = .\\YASKA; Initial Catalog = DataBase_StreamCinet; Integrated Security = True");
	//	String^ Query = "SELECT *FROM MOVIE ;";
	//	SqlCommand Cmd(Query, % conx);
	//	conx.Open();
	//	SqlDataReader^ sqlReader = Cmd.ExecuteReader();
	//	int index = 0;
	//	listPanel->Controls->Clear();
	//	//for movies : 
	//	while (sqlReader->Read())
	//	{
	//		//creating an instance for every movie : 
	//		Movie^ movie_ = gcnew Movie();
	//		movie_->SetIdMovie(Convert::ToInt32(sqlReader[0]->ToString()));
	//		movie_->SetIdApi(Convert::ToInt32(sqlReader["ID_API"]->ToString()));
	//		movie_->SetTitle(sqlReader["TITLE"]->ToString());
	//		movie_->SetOverview(sqlReader["OVERVIEW"]->ToString());
	//		movie_->SetRealease_Date(Convert::ToDateTime(sqlReader["RELEASE_DATE"]->ToString()));
	//		movie_->SetRating((float)Convert::ToDouble(sqlReader["Rating"]->ToString()));

	//		// Create a MemoryStream to hold the image data
	//		MemoryStream^ ms = gcnew MemoryStream(sqlReader->GetSqlBinary(6).Value);
	//		// Load the image data into a Bitmap object
	//		Bitmap^ image = gcnew Bitmap(ms);
	//		movie_->SetPoster(image);

	//		ms = gcnew MemoryStream(sqlReader->GetSqlBinary(7).Value);
	//		// Load the image data into a Bitmap object
	//		image = gcnew Bitmap(ms);
	//		movie_->SetBakcDrop(image);
	//		movie_->SetExist(DataBaseOperations::Search_Movie(movie_->GetIdApi()));
	//		//creating a user control for it : 
	//		PlanningFormat^ movie_userc = gcnew PlanningFormat(index, movie_, listPanel);
	//		listPanel->Controls->Add(movie_userc);
	//		++index;
	//	}
	//	conx.Close();
	//	index = 0;
	//	String^ Query2 = "SELECT *FROM SERIE ;";
	//	conx.Open();
	//	SqlCommand Cmd2(Query2, % conx);
	//	SqlDataReader^ sqlReader2 = Cmd2.ExecuteReader();
	//	//for series: 
	//	while (sqlReader2->Read())
	//	{
	//		//creating an instance for every movie : 
	//		Serie^ serie_ = gcnew Serie();
	//		serie_->SetIdApi(Convert::ToInt32(sqlReader2[0]->ToString()));
	//		serie_->SetIdApi(Convert::ToInt32(sqlReader2["ID_API"]->ToString()));
	//		serie_->SetName(sqlReader2["TITLE"]->ToString());
	//		serie_->SetOverview(sqlReader2["OVERVIEW"]->ToString());
	//		serie_->SetRealease_Date(Convert::ToDateTime(sqlReader2["RELEASE_DATE"]->ToString()));
	//		serie_->SetRating((float)Convert::ToDouble(sqlReader2["Rating"]->ToString()));

	//		// Create a MemoryStream to hold the image data
	//		MemoryStream^ ms = gcnew MemoryStream(sqlReader2->GetSqlBinary(4).Value);
	//		// Load the image data into a Bitmap object
	//		Bitmap^ image = gcnew Bitmap(ms);
	//		serie_->SetPoster(image);

	//		ms = gcnew MemoryStream(sqlReader2->GetSqlBinary(5).Value);
	//		// Load the image data into a Bitmap object
	//		image = gcnew Bitmap(ms);
	//		serie_->SetBakcDrop(image);
	//		serie_->SetExist(DataBaseOperations::Search_Serie(serie_->GetIdApi()));
	//		//creating a user control for it : 
	//		PlanningFormat^ serie_userc = gcnew PlanningFormat(index, serie_, listPanel);
	//		listPanel->Controls->Add(serie_userc);
	//		++index;
	//	}
	//	conx.Close();
	//}
private: System::Void nextBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	if (month == 12)
		{
			month = 0;
			year++;
		}
		month++;
		//first day of month : 
		this->calendarPan->Controls->Clear();
		DateTime start = DateTime(year, month, 1);
		int days = DateTime::DaysInMonth(year, month);
		int daysOfWeek = Convert::ToInt32(start.DayOfWeek.ToString("d")) + 1;
		if (daysOfWeek == 0)
			daysOfWeek = 7;
		for (int i = 1;i < daysOfWeek;i++)
		{
			BlankUserControl^ bk = gcnew BlankUserControl();
			this->calendarPan->Controls->Add(bk);
		}
		for (int i = 1;i <= days;i++)
		{
			DaysUserControl^ uc = gcnew DaysUserControl(i, month, year);
			this->calendarPan->Controls->Add(uc);
			uc->setPanel(this->calendarPan);
		}
}
};
}
