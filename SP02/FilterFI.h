#pragma once
#include "Filter.h"
#include "Kriterium.h"
template <typename T, typename O>
class FilterFI : public Filter<T, O>
{
public:
	bool evaluate(const O& o,  Kriterium<T, O>& c)
	{
		T result = c.evaluate(o);
		return result >= alpha && result <= beta;

	}

	void set_alpha(const T& alpha)
	{
		this->alpha = alpha;
	}

	void set_beta(const T& beta)
	{
		this->beta = beta;
	}
	FilterFI();

private:
	T alpha;
	T beta;
};

template <typename T, typename O>
FilterFI<T, O>::FilterFI()
{

}