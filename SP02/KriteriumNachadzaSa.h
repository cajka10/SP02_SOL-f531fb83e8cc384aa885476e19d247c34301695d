#pragma once
#include "Kriterium.h"
#include "Obec.h"
template <typename T, typename O>
class KriteriumNachadzaSa : public Kriterium<bool, Obec> {
public:
	KriteriumNachadzaSa();
	bool evaluate(const Obec& object) override
	{
		return object.nachadzaSa(vyssiUzCelok);
	}


	void set_vyssi_uz_celok(const string& vyssi_uz_celok)
	{
		vyssiUzCelok = vyssi_uz_celok;
	}

private: 
	string vyssiUzCelok;
};

template <typename T, typename O>
KriteriumNachadzaSa<T, O>::KriteriumNachadzaSa()
{
	
}

