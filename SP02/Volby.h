#pragma once
#include "structures/table/sorted_sequence_table.h"
#include "Obec.h"
#include "structures/table/unsorted_sequence_table.h"
#include "Kraj.h"
#include "Okres.h"
#include "Kriterium.h"
#include "structures/table/sorting/heap_sort.h"
#include "Filter.h"
#include "Filter_fi.h"
#include "FilterFI.h"
#include "KriteriumNazov.h"
#include "KriteriumVolici.h"
#include "KriteriumUcast.h"
#include "KriteriumNachadzaSa.h"

class Volby
{
private:
	structures::SortedSequenceTable<string, Obec*>* obce_;
	structures::SortedSequenceTable<string, Kraj*>* kraje_;
	structures::SortedSequenceTable<string, Okres*>* okresy_;
	

	FilterFI<double, Oblast>* filterUcast;
	Filter_fi<bool, Obec>* filterNachadzaSa;
	Filter_fi<string, Oblast>* filterNazov;
	FilterFI<int, Oblast>* filterVolici;


	KriteriumVolici<int, Oblast>* kVolici;
	Kriterium<string, Oblast>* kNazov;
	KriteriumUcast<double, Oblast>* kUcast;
	KriteriumNachadzaSa<bool, Obec>* kNachadzaSa;


public:
	Volby();
	~Volby();
	void nacitajSubory();
	void vypisMenu();
	void vypisPodla();
	void vypisPodlaNazvu();
	void vypisPodlaVolicov();
	void vypisPodlaUcasti();
	void zoradMenu();

	void zoradVsetko();
	void zoradPodla();
	template<typename L, typename S, typename O>

	void zotriedPodla( Kriterium<O,  S>& kriterium);

};





