#pragma once
#include "String.h"

#include <iostream>
using namespace std;

String::String() {

	length = 0;
	str = nullptr;

}

String::String(int len){
	
	length = len;
	str = new char[len];

}

String::String(const char *str){

	this->length = strlen(str);
	this->str = new char[length + 1];
	strcpy_s(this->str, length + 1, str);

}

String::String(const String &copy_str){

	this->length = copy_str.length;
	this->str = new char[this->length];
	strcpy_s(this->str, length + 1, copy_str.str);

}

int String::get_length(){
	return length;
}

const char *String::get_string(){
	return str;
}

void String::set_str(const char * str) {

	if (length != strlen(str)){

		delete[] this->str;
		this->length = strlen(str);
		this->str = new char[length + 1];

	}

	strcpy_s(this->str, length + 1, str);

}

void String::print(){
	cout << str;
}

void String::input(){

	char cpstr[1024];
	cin.getline(cpstr, 1024);
	set_str(cpstr);

}

void String::clear() {

	this->~String();

}

void String::insert(int pos, const char *str){

	if (pos > length || pos < 0 || str == nullptr) 
		return;

	if(length == 0 && pos == 0){

		set_str(str);
		return;

	}

	char *temp_str = new char[length + strlen(str) + 1];

	for (int i = 0; i < pos; i++)
		temp_str[i] = this->str[i];

	for (int i = pos; i < strlen(str) + pos; i++)
		temp_str[i] = str[i - pos];

	for (int i = pos + strlen(str); i < length + strlen(str); i++)
		temp_str[i] = this->str[i - strlen(str)];

	temp_str[length + strlen(str) - 1] = '\0';

	delete[] this->str;
	length += strlen(str);
	this->str = temp_str;

}

void String::append(const char * str){
	this->insert(length, str);
}

void String::erase(int pos, int length){
}

String::~String(){

	if(length != 0)delete[] str;

	str = nullptr;
	length = 0;

}