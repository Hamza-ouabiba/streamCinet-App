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
	String^ Realease_Date;
	Image^ Poster;
	Image^ BakcDrop;
public: 
	Movie()
	{
		this->id_Movie = 0;
		this->id_Api = 0;
		this->Rating = 0.0;
		this->title = "";
		this->Overview = "";
	}
	Movie(int id_Movie, int id_Api, String^ title, String^ Overview, float Rating, String^ Realease_Date, Image^ Poster, Image^ BakcDrop)
	{
		this->id_Movie = id_Movie;
		this->id_Api = id_Api;
		this->title = title;
		this->Overview = Overview;
		this->Rating = Rating;
		this->Realease_Date = Realease_Date;
		this->Poster = Poster;
		this->BakcDrop = BakcDrop;
	}
	int GetIdMovie() {
		return this->id_Movie;
	}
	int GetIdApi() {
		return this->id_Api;
	}
	float GetRating() {
		return this->Rating;
	}

	String^ GetTitle() {
		return this->title;
	}
	String^ GetOverview() {
		return Overview;
	}

	String^ GetRealease_Date() {
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
	void SetRealease_Date(String^ Date) {
		this->Realease_Date = Date;
	}
	void SetPoster(Image^ img) {
		this->Poster = img;
	}
	void SetBakcDrop(Image^ img) {
		this->BakcDrop = img;
	}
};

