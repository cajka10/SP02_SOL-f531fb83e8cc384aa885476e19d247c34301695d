#pragma once
#include <string>
#include "Oblast.h"
using namespace  std;
class Dedina : public Oblast
{
private:
	string nazovOkresu_;

public:
	Dedina(string nazov);
	~Dedina();
	bool nachadzaSa (Oblast* oblast) const;

	string get_nazov_okresu() const
	{
		return nazovOkresu_;
	}

	void set_nazov_okresu(const string& nazov_okresu)
	{
		nazovOkresu_ = nazov_okresu;
	}
};
