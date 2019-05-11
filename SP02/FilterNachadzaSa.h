#pragma once
#include "Filter_fi.h"
#include "Obec.h"

class  FilterNachadzaSa : public Filter_fi<bool, Obec>
{
public:
	FilterNachadzaSa();
};
