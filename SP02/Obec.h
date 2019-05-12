#pragma once
#include <string>
#include "Oblast.h"
using namespace  std;
class Obec : public Oblast
{
private:
	string nazovOkresu_;
	string nazovKraju_;
public:
	Obec(string nazov);
	~Obec();
	bool nachadzaSa (string vyssiUzCelok) const;

	string get_nazov_okresu() const
	{
		return nazovOkresu_;
	}

	void set_nazov_okresu(const string& nazov_okresu)
	{
		nazovOkresu_ = nazov_okresu;
	}

	string get_nazov_kraju() const
	{
		return nazovKraju_;
	}

	void set_nazov_kraju(const string& nazov_kraju)
	{
		nazovKraju_ = nazov_kraju;
	}
};
