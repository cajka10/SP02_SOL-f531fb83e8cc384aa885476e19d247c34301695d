#include "Obec.h"

Obec::Obec(string nazov) : Oblast(nazov)
{

}


bool  Obec::nachadzaSa(string vyssiUzCelok) const
{
	if (this->get_nazov_okresu() != vyssiUzCelok)
	{
		return false;
	}
	else
	{
		return true;

	}
}
Obec::~Obec()
{

}
