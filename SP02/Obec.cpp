#include "Obec.h"

Obec::Obec(string nazov) : Oblast(nazov)
{

}


bool  Obec::nachadzaSa(string vyssiUzCelok) const
{
	if (this->get_nazov_okresu() == vyssiUzCelok || this->get_nazov_kraju() == vyssiUzCelok)
	{
		return true;
	}
	else
	{
		return false;

	}
}
Obec::~Obec()
{

}
