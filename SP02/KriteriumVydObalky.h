#pragma once
#include "Oblast.h"
#include "Kriterium.h"

class KriteriumVydObalky : public Kriterium<int, Oblast>
{
public:
	int evaluate(const Oblast& oblast) override
	{
		oblast.get_pocet_vyd_obalok(kolo);
	}

	void set_kolo(int kolo)
	{
		this->kolo = kolo;
	}

private:
	int kolo;
};
