#pragma once
#include <string> 
#include <msclr/marshal_cppstd.h>
#include "DataBaseOperations.h"
using namespace::std;
using namespace System;
using namespace Drawing;



public ref class Serie
{
private:
	int id_Serie;
	int id_Api;
	bool Exist;
	String^ Name;
	String^ Overview;
	String^ Country;
	float Rating;
	DateTime Realease_Date;
	Image^ Poster;
	Image^ BakcDrop;
public: 
	Serie()
	{
	}
	Serie(Serie^ Serie) {

		this->id_Serie = Serie->id_Serie;
		this->id_Api = Serie->id_Api;
		this->Name = Serie->Name;
		this->Country = Serie->Country;
		this->Overview = Serie->Overview;
		this->Rating = Serie->Rating;
		this->Realease_Date = Serie->Realease_Date;
		this->Poster = Serie->Poster;
		this->BakcDrop = Serie->BakcDrop;

	}
	Serie(int id_Serie, int id_Api, String^ Name, String^ Overview, String^ Country, float Rating, DateTime Realease_Date, Image^ Poster, Image^ BakcDrop)
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
	int GetIdSerie() {
		return this->id_Serie;
	}
	bool GetExist()
	{
		return this->Exist;
	}
	int GetIdApi() {
		return this->id_Api;
	}
	float GetRating() {
		return this->Rating;
	}

	String^ GetName() {
		return this->Name;
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
	String^ GetCountry()
	{
		return this->Country;
	}
	//Set
	void SetIdSerie(int id) {
		this->id_Serie = id;
	}
	void SetIdApi(int id) {
		this->id_Api = id;
	}
	void SetRating(float rating) {
		this->Rating = rating;
	}
	void SetName(String^ name) {
		this->Name = name;
	}
	void SetOverview(String^ Overview) {
		this->Overview = Overview;
	}
	void SetRealease_Date(DateTime date) {
		this->Realease_Date = date;
	}
	void SetPoster(Image^ img) {
		this->Poster = img;
	}
	void SetBakcDrop(Image^ img) {
		this->BakcDrop = img;
	}
	void SetExist(bool value)
	{
		this->Exist = value;
	}
	void SetCountry(String^ country)
	{
		this->Country = country;
	}
};


