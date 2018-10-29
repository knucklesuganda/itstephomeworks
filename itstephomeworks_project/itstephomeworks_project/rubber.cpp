#include "rubber.h"

rubber::rubber(){
	this->stamina = 0;
	this->weather_type = 0;
}

rubber::rubber(bool weather_type = 0, int stamina = 1000){

	set_type(weather_type);
	set_stamina(stamina);

}

void rubber::set_type(bool type){
	this->weather_type = type;
}

void rubber::set_stamina(int stamina){

	if (stamina > 0)
		this->stamina = stamina;
	else 
		this->stamina = 0;

}

bool rubber::get_type() const {
	return this->weather_type;
}

int rubber::get_stamina() const {
	return this->stamina;
}

string rubber::get_info() const {

	string res = "Rubber type:" + to_string(this->weather_type);
	res += "\nStamina:" + to_string(this->stamina) + "\n";
	return res;

}

void rubber::rotation(){

	this->stamina--;
	if (this->stamina == 0)
		this->~rubber();

}

rubber::~rubber(){
	cout << "Rubber has been torned";
}