#pragma once
#include <array>
#using <System.dll>
#include "ClassData.h" 
#include "MainClass.h" 
#include"MyUserControl.h"
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
	/// Summary for MyLibrary
	/// </summary>
	public ref class MyLibrary : public System::Windows::Forms::UserControl
	{
	public:
		Panel^ Display_Panel;
		MyLibrary(Panel^ P)
		{
			InitializeComponent();
			Display_Panel = P;
			//TODO: Add the constructor code here
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
		/// Clean up any resources being used.
		/// </summary>
		~MyLibrary()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ BtnMovie;
	protected:
	private: System::Windows::Forms::Button^ BtnSeries;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->BtnMovie = (gcnew System::Windows::Forms::Button());
			this->BtnSeries = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
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
			this->BtnMovie->Click += gcnew System::EventHandler(this, &MyLibrary::BtnMovie_Click);
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
			// panel1
			// 
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->BtnSeries);
			this->panel1->Controls->Add(this->BtnMovie);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1155, 59);
			this->panel1->TabIndex = 2;
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(954, 16);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(163, 28);
			this->comboBox1->TabIndex = 2; 
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoScroll = true;
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 59);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(1155, 585);
			this->flowLayoutPanel1->TabIndex = 3;
			this->flowLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyLibrary::flowLayoutPanel1_Paint);
			// 
			// MyLibrary
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Inherit;
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->panel1);
			this->Name = L"MyLibrary";
			this->Size = System::Drawing::Size(1155, 644);
			this->Load += gcnew System::EventHandler(this, &MyLibrary::MyLibrary_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		void DisplayMovies() {
		 
				SqlConnection conx(MainClass::ConnectionString());

				String^ Query = "SELECT *FROM MOVIE ;";
				SqlCommand Cmd(Query, % conx);
				conx.Open();
				SqlDataReader^ Read = Cmd.ExecuteReader();
				this->flowLayoutPanel1->Controls->Clear();
				while (Read->Read()) {
					Class_Movie^ Movie = gcnew Class_Movie();

					Movie->SetIdMovie(Convert::ToInt32(Read[0]->ToString()));
					Movie->SetIdApi(Convert::ToInt32(Read["ID_API"]->ToString()));
					Movie->SetTitle(Read["TITLE"]->ToString());
					Movie->SetOverview(Read["OVERVIEW"]->ToString());
					Movie->SetRealease_Date(Convert::ToDateTime(Read["RELEASE_DATE"]->ToString()));
					Movie->SetRating((float)Convert::ToDouble(Read["Rating"]->ToString()));

					// Create a MemoryStream to hold the image data
					MemoryStream^ ms = gcnew MemoryStream(Read->GetSqlBinary(6).Value);
					// Load the image data into a Bitmap object
					Bitmap^ image = gcnew Bitmap(ms);
					Movie->SetPoster(image);

					ms = gcnew MemoryStream(Read->GetSqlBinary(7).Value);
					// Load the image data into a Bitmap object
					image = gcnew Bitmap(ms);
					Movie->SetBakcDrop(image);


					//array<Byte>^ _ImageData;
					// _ImageData = safe_cast<std::array<Byte>^>(Read["POSTER"]);
					//static_cast<unsigned char>
						//_MemoryStream = gcnew MemoryStream(Convert::ToByte(Read["BACKDROP"]));
						//image = gcnew Bitmap(_MemoryStream);
					//MemoryStream^ _MemoryStream = gcnew System::IO::MemoryStream(_ImageData);
					//_ImageData = System::Drawing::Image::FromStream(_MemoryStream);

					/*

					Type^ type = Read->GetFieldType(6);
					String^ typeName = type->ToString();
					MessageBox::Show(typeName);

					if (!Convert::IsDBNull(Read["POSTER"]) && !Convert::IsDBNull(Read["BACKDROP"])) {

					//	MemoryStream^ _MemoryStream = gcnew MemoryStream(Convert::ToBase64CharArray(Read["POSTER"]));
					//	Bitmap^ image = gcnew Bitmap(_MemoryStream);
					//	Movie->SetPoster(image);

					//_ImageData = System::Drawing::Image::FromStream(_MemoryStream);
						//Movie->SetPoster(image);

						//_MemoryStream = gcnew MemoryStream(Convert::ToBase64String(Read["BACKDROP"]));
						//image = gcnew Bitmap(_MemoryStream);
						//Movie->SetBakcDrop(image);
					}*/
					
					MyUserControl^ UC = gcnew MyUserControl(Movie, Display_Panel);
					this->flowLayoutPanel1->Controls->Add(UC);
		 
			}
		}
	private: System::Void flowLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void BtnMovie_Click(System::Object^ sender, System::EventArgs^ e) {
		DisplayMovies();
	}
	private: System::Void MyLibrary_Load(System::Object^ sender, System::EventArgs^ e) {
		DisplayMovies();

	}


	 
};
}
