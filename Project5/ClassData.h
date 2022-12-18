#pragma once
#include <string>
using namespace::std;
using namespace System;
using namespace Drawing;
 
	 public ref class Class_Movie
	{
	private:
		int id_Movie;
		int id_Api;
		float Rating;
		String^ title;
		String^ Overview;
		DateTime Realease_Date;
		Image^ Poster;
		Image^ BakcDrop;

	public:
		Class_Movie() {
		 
		}
		Class_Movie(Class_Movie ^MV) {

			this->id_Movie = MV->id_Movie;
			this->id_Api = MV->id_Api;
			this->title = MV->title;
			this->Overview = MV->Overview;
			this->Rating = MV->Rating;
			this->Realease_Date = MV->Realease_Date;
			this->Poster = MV->Poster;
			this->BakcDrop = MV->BakcDrop;
		}
		Class_Movie(int id_Movie, int id_Api, String^ title, String^ Overview, float Rating, DateTime Realease_Date, Image^ Poster, Image^ BakcDrop)
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
		~Class_Movie() {
		}
		//Get
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
		void SetPoster(Image^ img){
			this->Poster = img;
		}
		void SetBakcDrop(Image^ img) {
			this->BakcDrop = img;
		}
	};

	public ref class Class_Serie
	{
	private:
		int id_Serie;
		int id_Api;
		String^ Name;
		String^ Overview;
		String^ Country;
		float Rating;
		DateTime Realease_Date;
		Image^ Poster;
		Image^ BakcDrop;


	public:
		Class_Serie(int id_Serie, int id_Api, String^ Name, String^ Overview, String^ Country, float Rating, DateTime Realease_Date, Image^ Poster, Image^ BakcDrop)
		{
			this->id_Serie = id_Serie;
			this->id_Api = id_Api;
			this->Name = Name;
			this->Country = Country;
			this->Overview = Overview;
			this->Rating = Rating;
			this->Realease_Date = Realease_Date;
			this->Poster = Poster;
			this->BakcDrop = BakcDrop;

		}
		~Class_Serie() {
		}



	};
 

