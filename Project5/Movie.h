#pragma once
#include <string>
using namespace::std;
using namespace System;
using namespace Drawing;

public ref class Movie
{
private :
	int id_Movie;
	int id_Api;
	float Rating;
	String^ title;
	String^ Overview;
	DateTime Realease_Date;
	Image^ Poster;
	Image^ BakcDrop;
	bool existData;
public: 
	Movie()
	{
		this->id_Movie = 0;
		this->id_Api = 0;
		this->Rating = 0.0;
		this->title = "";
		this->Overview = "";
	}
	/*Movie(int id_Movie, int id_Api, String^ title, String^ Overview, float Rating, DateTime Realease_Date, Image^ Poster, Image^ BakcDrop)
	{
		this->id_Movie = id_Movie;
		this->id_Api = id_Api;
		this->title = title;
		this->Overview = Overview;
		this->Rating = Rating;
		this->Realease_Date = Realease_Date;
		this->Poster = Poster;
		this->BakcDrop = BakcDrop;
		this->existData = 0;
	}*/
	int GetIdMovie() {
		return this->id_Movie;
	}
	int GetIdApi() {
		return this->id_Api;
	}
	float GetRating() {
		return this->Rating;
	}
	bool GetExist()
	{
		return this->existData;
	}
	String^ GetTitle() {
		return this->title;
	}
	String^ GetOverview() {
		return Overview;
	}

	DateTime GetRealease_Date() {
		return this->Realease_Date;
	}
	Image^ GetPoster() {
		return this->Poster;
	}
	Image^ GetBakcDrop() {
		return this->BakcDrop;
	}

	//Set
	void SetIdMovie(int id) {
		this->id_Movie = id;
	}
	void SetIdApi(int id) {
		this->id_Api = id;
	}
	void SetRating(float rating) {
		this->Rating = rating;
	}
	void SetTitle(String^ title) {
		this->title = title;
	}
	void SetOverview(String^ Overview) {
		this->Overview = Overview;
	}
	void SetRealease_Date(DateTime Date) {
		this->Realease_Date = Date;
	}
	void SetPoster(Image^ img) {
		this->Poster = img;
	}
	void SetBakcDrop(Image^ img) {
		this->BakcDrop = img;
	}
	void SetExist(bool value)
	{
		this->existData = value;
	}
};

