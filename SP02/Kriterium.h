#pragma once
template <typename T, typename O>
class Kriterium
{
public:
	Kriterium();
	~Kriterium();
	virtual T evaluate(const O& object) = 0;
};

template <typename T, typename O>
Kriterium<T, O>::~Kriterium()
{

}
template <typename T, typename O>
Kriterium<T, O>::Kriterium()
{

}