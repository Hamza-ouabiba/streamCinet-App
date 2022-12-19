#pragma once
#include<curl/curl.h>
#include "json/json.h"
#include "MyUserControl.h"
#include <msclr/marshal_cppstd.h>
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
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public ref class Mani
{
public: 
	Mani(){}
	Json::Value getInformations( string url_ , string type)
	{
		try
		{
			CURL* curl = curl_easy_init();
			std::string url(url_);
			Json::Value jsonData;
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

				Json::Reader jsonReader;
				stringstream ss;
				string data;
				Json::StreamWriterBuilder builder;
				builder["indentation"] = "";
				if (jsonReader.parse(*httpData.get(), jsonData));
			}
			return jsonData;
		}
		catch (System::Exception^ ex)
		{
			
		}
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
			_HttpWebRequest->Timeout = 10000;

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
	int randomNumber()
	{
		srand(time(NULL));
		return rand() % 20;
	}
	void ShowBackGroundImageDashBoard(string url_,Panel^ flowP,Label^ over)
	{
		CURL* curl = curl_easy_init();
		std::string url(url_);
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
			string data;
			//changing size of image : with w1280
			string site = "https://image.tmdb.org/t/p/w1280";
			Json::StreamWriterBuilder builder;
			string overview;
			String^ overPase;
			builder["indentation"] = "";
			if (jsonReader.parse(*httpData.get(), jsonData))
			{
				data = site + Json::writeString(builder, jsonData["results"][randomNumber()]["backdrop_path"]);
				data.erase(remove(data.begin(), data.end(), '"'), data.end());
				System::String^ unmanaged = msclr::interop::marshal_as<System::String^>(data);
				flowP->BackgroundImage = DownloadImage(unmanaged);
				overview = jsonData["results"][randomNumber()]["overview"].toStyledString();
				overPase = msclr::interop::marshal_as<System::String^>(overview);
				over->Text = overPase;
			}
		}
	}
};

