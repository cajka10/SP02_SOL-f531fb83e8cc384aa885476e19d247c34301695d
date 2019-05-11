#pragma once
#include <string>

class Kluc
{
private:
	std::string nazov;
	int volici1;
	double ucast1;

	int volici2;
	double ucast2;

public:
	Kluc(std::string nazov, int volici1, double ucast1, int volici2, int ucast2)
	{
		this->nazov = nazov;
		this->ucast1 = ucast1;
		this->volici1 = volici1;
		this->ucast2 = ucast2;
		this->volici2 = volici2;
	}
	Kluc()
	{
		
	}
	~Kluc()
	{
		
	}

	std::string nazov1() const
	{
		return nazov;
	}

	void set_nazov(const std::string& nazov)
	{
		this->nazov = nazov;
	}

	int get_volici(int kolo) const
	{
		if (kolo == 1)
		{
			return volici1;

		}
		else if(kolo == 2) {
			return  volici2;
		}
		else
		{
			return volici1 + volici2;
		}
	}

	void set_volici1(int volici1)
	{
		this->volici1 = volici1;
	}

	double get_ucast(int kolo) const
	{
		if (kolo == 1)
		{
			return ucast1;

		}
		else if (kolo == 2) {
			return  ucast2;
		}
		else
		{
			return ucast1 + ucast2;
		}
	}

	void set_ucast1(double ucast1)
	{
		this->ucast1 = ucast1;
	}

	void set_volici2(int volici2)
	{
		this->volici2 = volici2;
	}

	void set_ucast2(double ucast2)
	{
		this->ucast2 = ucast2;
	}
};
