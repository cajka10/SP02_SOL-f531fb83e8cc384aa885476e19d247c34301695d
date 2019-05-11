#pragma once
#include "Oblast.h"

class  Okres : public Oblast
{
private:
	std::string nazovKraju_;
public:
	Okres(std::string nazov);
	~Okres();

	std::string get_nazov_kraju() const
	{
		return nazovKraju_;
	}

	void set_nazov_kraju(const std::string& nazov_kraju)
	{
		nazovKraju_ = nazov_kraju;
	}
};
