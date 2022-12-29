#pragma once
#include <iostream>
#include <json/json.h>
#include <curl/curl.h>
#include <vector>
using namespace::std;
using namespace System;
using namespace System::Windows::Forms;
static ref class LocalData
{
public :
	static vector<Json::Value>* discoverData = new vector<Json::Value>;
	static vector<Json::Value>* popularData = new vector<Json::Value>;
	static vector<Json::Value>* backGroundDash = new vector<Json::Value>;
	static vector<Json::Value>* Movies = new vector<Json::Value>;
	static vector<Json::Value>* Series = new vector<Json::Value>;
	static Json::Value getDiscoverData()
	{
		return discoverData->at(0);	
	}
	static Json::Value getPopularData() {
		return popularData;
	}
	static Json::Value getMoviesData()
	{
		return Movies->at(0);
	}
	static Json::Value getSeriesData()
	{
		return Series->at(0);
	}
	static void setDiscoverData(Json::Value data)
	{
		discoverData->push_back(data);
	}
	static void setPopularData(Json::Value data)
	{
		popularData->push_back(data);
	}
	static void get(Json::Value data)
	{
		backGroundDash->push_back(data);
	}
	static void setSeries(Json::Value data)
	{
		Movies->push_back(data);
	}
	static void setMovies(Json::Value data)
	{
		Series->push_back(data);
	}
};

