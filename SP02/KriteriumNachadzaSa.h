#pragma once
#include "Kriterium.h"
#include "Obec.h"
template <typename T, typename O>
class KriteriumNachadzaSa : public Kriterium<bool, Obec> {
public:
	KriteriumNachadzaSa();
	bool evaluate(const Obec& object) override
	{
		return object.nachadzaSa(oblast_);
	}

	void set_oblast(Obec* oblast)
	{
		oblast_ = oblast;
	}

private: Obec* oblast_;
};

template <typename T, typename O>
KriteriumNachadzaSa<T, O>::KriteriumNachadzaSa()
{
	
}

