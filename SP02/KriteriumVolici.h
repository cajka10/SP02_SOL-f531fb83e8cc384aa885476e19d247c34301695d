#pragma once
#include "Kriterium.h"
#include "Oblast.h"
template <typename T, typename O>
class KriteriumVolici : public Kriterium<int, Oblast>
{
public:
	KriteriumVolici();
	int evaluate(const Oblast& oblast) override {
		return oblast.get_pocet_zap_volicov(kolo);
	}

	void set_kolo(int kolo)
	{
		this->kolo = kolo;
	}
	

private:
	int kolo;
};

template<typename T, typename O>
inline KriteriumVolici<T, O>::KriteriumVolici()
{

}
