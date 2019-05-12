#pragma once

#include "sort.h"
#include "../unsorted_sequence_table.h"

namespace structures
{

	/// <summary> Triedenie Heap sort. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	/// <typeparam name = "O"> Typ dat navratenych z kriteria, podla ktorych sa triedi. </typepram>
	template<typename K, typename T, typename O, typename S>
	class HeapSort : public Sort<K, T, O, S>
	{
	public:
		/// <summary> Utriedi tabulku triedenim Heap sort. </summary>
		/// <param name = "table"> NonortedSequenceTable, ktoru ma utriedit. </param>
		void sortAsc(UnsortedSequenceTable<K, T>& table, Kriterium<O, S>& kriterium ) override;
		void sortDesc(UnsortedSequenceTable<K, T>& table, Kriterium<O, S>& kriterium ) override;
		
		
	};
	
	template<typename K, typename T, typename O, typename S>
	inline void HeapSort<K, T, O ,S>::sortAsc(UnsortedSequenceTable<K, T>& table, Kriterium<O, S >& kriterium )
	{
		bool vymena;
		for (int i = 1; i < table.size(); i++) {
			int aktualny = i;
			do {
				vymena = false;
				int father = (aktualny - 1) / 2;
				if ((aktualny > 0) && (kriterium.evaluate(*table.getItemAtIndex(aktualny).accessData() )> kriterium.evaluate(*table.getItemAtIndex(father).accessData()))) {
					table.swap(aktualny, father);
					aktualny = father;
					vymena = true;
				}
			} while (vymena);
		}
		for (int i = table.size() - 1; i > 0; i--) {
			table.swap(0, i);
			int aktualny = 0;
			do {
				vymena = false;
				int max;
				int lavy = aktualny * 2 + 1;
				int pravy = aktualny * 2 + 2;
				if (lavy < i && pravy < i)
					max = kriterium.evaluate(*table.getItemAtIndex(lavy).accessData()) > kriterium.evaluate(*table.getItemAtIndex(pravy).accessData()) ? lavy : pravy;
				else
					max = lavy < i ? lavy : pravy;
				if (max < i && kriterium.evaluate(*table.getItemAtIndex(max).accessData()) > kriterium.evaluate(*table.getItemAtIndex(aktualny).accessData())) {
					table.swap(max, aktualny);
					aktualny = max;
					vymena = true;
				}
				//notify();
			} while (vymena);
		}
		
	}

	template <typename K, typename T, typename O, typename S>
	void HeapSort<K, T, O, S>::sortDesc(UnsortedSequenceTable<K, T>& table, Kriterium<O, S>& kriterium)
	{
		bool vymena;
		for (int i = 1; i < table.size(); i++) {
			int aktualny = i;
			do {
				vymena = false;
				int father = (aktualny - 1) / 2;
				if ((aktualny > 0) && (kriterium.evaluate(*table.getItemAtIndex(aktualny).accessData()) < kriterium.evaluate(*table.getItemAtIndex(father).accessData()))) {
					table.swap(aktualny, father);
					aktualny = father;
					vymena = true;
				}
			} while (vymena);
		}
		for (int i = table.size() - 1; i > 0; i--) {
			table.swap(0, i);
			int aktualny = 0;
			do {
				vymena = false;
				int min;
				int lavy = aktualny * 2 + 1;
				int pravy = aktualny * 2 + 2;
				if (lavy < i && pravy < i)
					min = kriterium.evaluate(*table.getItemAtIndex(lavy).accessData()) < kriterium.evaluate(*table.getItemAtIndex(pravy).accessData()) ? lavy : pravy;
				else
					min = lavy < i ? lavy : pravy;
				if (min < i && kriterium.evaluate(*table.getItemAtIndex(min).accessData()) < kriterium.evaluate(*table.getItemAtIndex(aktualny).accessData())) {
					table.swap(min, aktualny);
					aktualny = min;
					vymena = true;
				}
				//notify();
			} while (vymena);
		}
	}


}