#pragma once
#include "Kriterium.h"
#include "Oblast.h"
template <typename T, typename O>
class KriteriumUcast : public Kriterium<double, Oblast>
{
public:
	KriteriumUcast();

	double evaluate(const Oblast& oblast) override
	{
		return oblast.get_ucast_volicov_percenta(kolo);
	}

	void set_kolo(int kolo)
	{
		this->kolo = kolo;
	}
	
private:
	int kolo;
};

template <typename T, typename O>
KriteriumUcast<T, O>::KriteriumUcast()
{

}

