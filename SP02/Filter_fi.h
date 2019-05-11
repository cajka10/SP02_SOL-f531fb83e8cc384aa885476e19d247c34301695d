#pragma once
#include "Filter.h"
#include "Kriterium.h"
template <typename T, typename O>
class Filter_fi : public Filter<T, O>
{
public:
	Filter_fi();

	bool evaluate(const O& objekt,  Kriterium<T, O>& c) override
	{
		return c.evaluate(objekt) == alpha;
		
	}

	void set_alpha(const T& alpha)
	{
		this->alpha = alpha;
	}

private:
	T alpha;
};

template <typename T, typename O>
Filter_fi<T, O>::Filter_fi()
{
	
}
