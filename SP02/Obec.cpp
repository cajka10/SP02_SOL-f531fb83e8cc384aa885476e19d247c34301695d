#include "Obec.h"

Obec::Obec(string nazov) : Oblast(nazov)
{

}


bool  Obec::nachadzaSa(Oblast * oblast) const
{
	if (oblast->get_nazov() != this->get_nazov_okresu())
	{
		return false;
	}
	 
	return true;
}
Obec::~Obec()
{

}
