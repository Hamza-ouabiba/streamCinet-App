#pragma once
#include <curl/curl.h>
#include"json/json.h"

#include <iostream>
#include<string>
#include <msclr/marshal_cppstd.h>
#include "MyUserControl.h"
#define CURL_STATICLIB
using namespace std;
using namespace System::Drawing::Imaging;
using namespace System;
using namespace System::Windows::Forms;
namespace
{
	std::size_t callback(
		const char* in,
		std::size_t size,
		std::size_t num,
		std::string* out)
	{
		const std::size_t totalBytes(size * num);
		out->append(in, totalBytes);
		return totalBytes;
	}
}
namespace Project5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button6;

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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(727, 57);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"label3";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(59, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"label2";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(625, 57);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoScroll = true;
			this->flowLayoutPanel1->Location = System::Drawing::Point(247, 93);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(1723, 331);
			this->flowLayoutPanel1->TabIndex = 3;
			this->flowLayoutPanel1->WrapContents = false;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(3, 93);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(244, 824);
			this->panel1->TabIndex = 4;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(13, 214);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(214, 47);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Popular";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(13, 149);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(214, 47);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Latest";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(13, 81);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(214, 47);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Series";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 17);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(214, 47);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Movies";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(13, 284);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(214, 47);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Top Rated";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->BackColor = System::Drawing::Color::Black;
			this->panel2->Controls->Add(this->button8);
			this->panel2->Controls->Add(this->button7);
			this->panel2->Controls->Add(this->button6);
			this->panel2->Location = System::Drawing::Point(3, 1);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1719, 53);
			this->panel2->TabIndex = 5;
			// 
			// button6
			// 
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6->ForeColor = System::Drawing::Color::Transparent;
			this->button6->Location = System::Drawing::Point(260, 3);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(205, 50);
			this->button6->TabIndex = 0;
			this->button6->Text = L"Discovery";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->ForeColor = System::Drawing::Color::MediumBlue;
			this->button7->Location = System::Drawing::Point(0, 0);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(205, 50);
			this->button7->TabIndex = 1;
			this->button7->Text = L"StreamCinet";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button8->ForeColor = System::Drawing::Color::Transparent;
			this->button8->Location = System::Drawing::Point(461, 3);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(205, 50);
			this->button8->TabIndex = 2;
			this->button8->Text = L"Discovery";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1723, 1055);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		System::Drawing::Image^ DownloadImage(System::String^ _URL)
		{
			System::Drawing::Image^ _tmpImage = nullptr;

			try
			{
				// Open a connection
				System::Net::HttpWebRequest^ _HttpWebRequest = safe_cast<System::Net::HttpWebRequest^>(System::Net::HttpWebRequest::Create(_URL));

				_HttpWebRequest->AllowWriteStreamBuffering = true;

				// You can also specify additional header values like the user agent or the referer: (Optional)
				_HttpWebRequest->UserAgent = "Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 5.1)";
				_HttpWebRequest->Referer = "http://www.google.com/";

				// set timeout for 20 seconds (Optional)
				//_HttpWebRequest->Timeout = 20000;

				// Request response:
				System::Net::WebResponse^ _WebResponse = _HttpWebRequest->GetResponse();

				// Open data stream:
				System::IO::Stream^ _WebStream = _WebResponse->GetResponseStream();
				// convert webstream to image
				_tmpImage = Image::FromStream(_WebStream);
				// Cleanup
				_WebResponse->Close();
				_WebResponse->Close();
			}
			catch (Exception^ _Exception)
			{
				// Error
				Console::WriteLine("Exception caught in process: {0}", _Exception->ToString());
				return nullptr;
			}

			return _tmpImage;
		}
		
		string removeQuotations(string input)
		{
			int i;
			int j;
			int length = input.length();
			cout << "index of page inn function : "<<input;
			return input;
		}
		void getInformations(int index,string page)
		{
			CURL* curl = curl_easy_init();
			cout << page;
			std::string url("https://api.themoviedb.org/3/search/movie?api_key=10f96818301b77e61d73d48aa20d81f9&query=a&page=" + page);
			Json::Value ra;
			curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

			// Don't bother trying IPv6, which would increase DNS resolution time.
			curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);

			// Don't wait forever, time out after 10 seconds.
			curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

			// Follow HTTP redirects if necessary.
			curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

			// Response information.
			long httpCode(0);
			std::unique_ptr<std::string> httpData(new std::string());

			// Hook up data handling function.
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);

			// Hook up data container (will be passed as the last parameter to the
			// callback handling function).  Can be any pointer type, since it will
			// internally be passed as a void pointer.
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());

			// Run our HTTP GET command, capture the HTTP response code, and clean up.
			curl_easy_perform(curl);
			curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
			curl_easy_cleanup(curl);

			if (httpCode == 200)
			{
				// Response looks good - done using Curl now.  Try to parse the results
				// and print them out.
				//jsonData["results"][i]["original_title"]
				Json::Value jsonData;
				Json::Reader jsonReader;
				stringstream ss;
				string data;
				string site = "https://image.tmdb.org/t/p/w500";
				Json::StreamWriterBuilder builder;
				builder["indentation"] = "";
				if (jsonReader.parse(*httpData.get(), jsonData))
				{
						string title = jsonData["results"][index]["title"].toStyledString();
						data = site + Json::writeString(builder, jsonData["results"][index]["poster_path"]);
						data.erase(remove(data.begin(), data.end(), '"'), data.end());
						System::String^ unmanaged = msclr::interop::marshal_as<System::String^>(data);
						label3->Text = unmanaged;

						MyUserControl^ uc = gcnew MyUserControl(index, DownloadImage(unmanaged), msclr::interop::marshal_as<System::String^>(title));
						this->flowLayoutPanel1->Controls->Add(uc);
					///*Image^ image = Image::FromFile(unmanaged);
					//panel1->BackgroundImage = image;*/
				}
			}
		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		int indexPage;
		
		for (int i = 1;i <= 1;i++)
		{  
			for (int j = 1;j <= 19;j++)
			{
				stringstream ss;
				string indexStri;
				cout << "index page = " << i;
				indexPage = i;
				ss << indexPage;
				ss >> indexStri;
				getInformations(j, indexStri);
				
			}
		}
	}
	};
	
}
