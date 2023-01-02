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
	String^ Username;
	String^ Email;
	String^ Password; 


public:
	UserClass() {

	}

	int GetIdUser() {
		return this->idUser;
	} 
	String^ GetUsername() {
		return this->Username;
	}
	String^ GetEmail() {
		return this->Email;
	} 
	String^ GetPassword() {
		return this->Password;
	}
	//Set
	void SetIdUser(int id) {
		this->idUser = id;
	} 
	void SetUsername(String^ Username) {
		this->Username = Username;
	}
	void SetEmail(String^ s) {
		this->Email = s;
	} 
	void SetPassword(String^ rating) {
		this->Password = rating;
	}



};

