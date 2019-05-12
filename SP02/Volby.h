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
	structures::UnsortedSequenceTable<string, Oblast*>* neutriedeneObce_;

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
// L - typ kluca
// S - typ Objektov v tabulke, a ktore davam do kriteria
// O - navratovy typ kriteria
/*
template <typename L, typename S, typename O>
void Volby::zotriedPodla( Kriterium<O, S>& kriterium )
{
	structures::HeapSort<L, S, O>* heap_sort = new structures::HeapSort<L, S, O>();
	structures::UnsortedSequenceTable<L, S>* pomObce = new structures::UnsortedSequenceTable<L, S>();

	for (auto item : *obce_)
	{
		if (filterUcast->evaluate(*item->accessData(), *kUcast))
		{
			pomObce->insert(item->accessData()->get_nazov(), *item->accessData());
		}
	}
	heap_sort->sort(*pomObce, kriterium);

	for (auto item : *pomObce)
	{
		Oblast* obec = reinterpret_cast<Oblast*>(*item->accessData());
		obec->vypisInfo();
	}
	delete heap_sort;
	delete pomObce;
}



template <typename L, typename S>
 void Volby::zotriedPodla(Kriterium<string, S>& kriterium)
 {
	 structures::HeapSort<L, S*>* heap_sort = new structures::HeapSort<L, S*>();
	 structures::UnsortedSequenceTable<L, S*>* pomObce = new structures::UnsortedSequenceTable<L, S*>();

	 for (auto *item : *obce_)
	 {
		 L kluc = kriterium.evaluate(*item->accessData());
		 if (filterUcast->evaluate(*item->accessData(), *kUcast))
		 {

			 pomObce->insert(kluc, item->accessData());

		 }
	 }
	 heap_sort->sort(*pomObce, );

	 for (auto *item : *pomObce)
	 {
		 item->accessData()->vypisInfo();
	 }
	 delete heap_sort;
	 delete pomObce;

 }*/




