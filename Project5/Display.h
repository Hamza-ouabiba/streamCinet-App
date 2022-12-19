#pragma once
#pragma once
#include <curl/curl.h>
#include"json/json.h"
#include <windows.h>
#include <iostream>
#include<string>
#include <msclr/marshal_cppstd.h>
#include"ClassData.h"
#include"MyUserControl.h"
#include <msclr/marshal.h>
#define CURL_STATICLIB
using namespace System;
using namespace System::Configuration;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

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

	/// <summary>
	/// Summary for Display
	/// </summary>
	public ref class Display : public System::Windows::Forms::UserControl
	{
	public:
		Panel^ Display_Panel;
		Display(Panel ^ Panel)
		{

			InitializeComponent();
			this->Display_Panel = Panel;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Display()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	protected:

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
			this->SuspendLayout();
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoScroll = true;
			this->flowLayoutPanel1->AutoSize = true;
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(1086, 714);
			this->flowLayoutPanel1->TabIndex = 0;
			this->flowLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Display::flowLayoutPanel1_Paint);
			// 
			// Display
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Inherit;
			this->AutoScroll = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->Controls->Add(this->flowLayoutPanel1);
			this->Name = L"Display";
			this->Size = System::Drawing::Size(1086, 714);
			this->Load += gcnew System::EventHandler(this, &Display::Display_Load);
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

			int length = input.length();
			//cout << "index of page inn function : "<<input;
			return input;
		}
		void getInformations(int index, string page)
		{
			CURL* curl = curl_easy_init();
			//cout << page;
			std::string url("https://api.themoviedb.org/3/movie/popular?api_key=10f96818301b77e61d73d48aa20d81f9&page&page=" + page);
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

				Class_Movie^ Movie = gcnew Class_Movie();
				Json::StreamWriterBuilder builder;
				builder["indentation"] = "";
				if (jsonReader.parse(*httpData.get(), jsonData))
				{
					Movie->SetIdApi(jsonData["results"][index]["id"].asInt());
					Movie->SetRating(jsonData["results"][index]["vote_average"].asFloat());


					string title = jsonData["results"][index]["title"].toStyledString();
					title.erase(remove(title.begin(), title.end(), '"'));
					Movie->SetTitle(msclr::interop::marshal_as<System::String^>(title));

					string overview = jsonData["results"][index]["overview"].toStyledString();
					overview.erase(remove(overview.begin(), overview.end(), '"'));
					Movie->SetOverview(msclr::interop::marshal_as<System::String^>(overview));


					string date = jsonData["results"][index]["release_date"].toStyledString();
					date.erase(remove(date.begin(), date.end(), '"'));
					Movie->SetRealease_Date(DateTime::Parse(msclr::interop::marshal_as<System::String^>(date)));



					data = site + Json::writeString(builder, jsonData["results"][index]["poster_path"]);
					data.erase(remove(data.begin(), data.end(), '"'), data.end());
					System::String^ unmanaged = msclr::interop::marshal_as<System::String^>(data);

					Movie->SetPoster(DownloadImage(unmanaged));

					data = site + Json::writeString(builder, jsonData["results"][index]["backdrop_path"]);
					data.erase(remove(data.begin(), data.end(), '"'), data.end());
					unmanaged = msclr::interop::marshal_as<System::String^>(data);

					Movie->SetBakcDrop(DownloadImage(unmanaged));

					MyUserControl^ UC = gcnew MyUserControl(Movie, Display_Panel);
					this->flowLayoutPanel1->Controls->Add(UC);

					///*Image^ image = Image::FromFile(unmanaged);
					//panel1->BackgroundImage = image;*/
				}
			}
		}
#pragma endregion
	private: System::Void flowLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void Display_Load(System::Object^ sender, System::EventArgs^ e) {
		int indexPage;
		for (int i = 1; i <= 1; i++)
		{
			for (int j = 1; j <= 19; j++)
			{
				stringstream ss;
				string indexStri;
				//cout << "index page = " << i;
				indexPage = i;
				ss << indexPage;
				ss >> indexStri;
				getInformations(j, indexStri);

			}
		}
	}
};
}
