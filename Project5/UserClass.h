#pragma once
 
#include <string>

using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::SqlClient;

public ref class UserClass
{
 private:

	int idUser;
	int ID_WATCH_LIST;
	String^ Username;
	String^ Email;
	String^ Password;
	String^ WatchListName;

	 
public :
	UserClass() {

	} 

	int GetIdUser() {
		return this->idUser;
	}
	int GetIdWatchList()
	{
		return this->ID_WATCH_LIST;
	}
	String^ GetUsername() {
		return this->Username;
	}
	String^ GetEmail() {
		return this->Email;
	} 
	String^ GetWatchListName() {
		return this->WatchListName;
	}
	String^ GetPassword() {
		return this->Password;
	}
	//Set
	void SetIdUser(int id) {
		this->idUser = id;
	}
	void SetIdWatchList(int id) {
		this->ID_WATCH_LIST = id;
	}
	void SetUsername(String^ Username) {
		this->Username= Username;
	}
	void SetEmail(String^ s) {
		this->Email = s;
	}
	void SetWatchListName(String^ WatchListName) {
		this->WatchListName = WatchListName;
	}
	void SetPassword(String^ rating) {
		this->Password = rating;
	}

	 

};

