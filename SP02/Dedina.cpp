#include "Obec.h"

Dedina::Dedina(string nazov) : Oblast(nazov)
{

}


bool  Dedina::nachadzaSa(Oblast * oblast) const
{
	if (oblast->get_nazov() != this->get_nazov_okresu())
	{
		return false;
	}
	return true;
}
Dedina::~Dedina()
{

}
