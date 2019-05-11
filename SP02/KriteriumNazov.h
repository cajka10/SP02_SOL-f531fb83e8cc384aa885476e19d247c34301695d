#pragma once
#include <string>
#include "Kriterium.h"
#include "Oblast.h"

template <typename T, typename O>
class KriteriumNazov : public Kriterium<std::string, Oblast>
{
public:
	std::string evaluate(const Oblast& oblast) override
	{
		return oblast.get_nazov();
	}
	KriteriumNazov();

};

template<typename T, typename O>
inline KriteriumNazov<T, O>::KriteriumNazov()
{
}




