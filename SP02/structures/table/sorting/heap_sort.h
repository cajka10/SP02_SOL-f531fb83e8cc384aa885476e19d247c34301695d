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
		bool swapping;
		for (int i = 1; i < table.size(); i++) {
			int current = i;
			do {
				swapping = false;
				int father = (current - 1) / 2;
				if ((current > 0) && (kriterium.evaluate(*table.getItemAtIndex(current).accessData() )> kriterium.evaluate(*table.getItemAtIndex(father).accessData()))) {
					table.swap(current, father);
					current = father;
					swapping = true;
				}
			} while (swapping);
		}
		for (int i = table.size() - 1; i > 0; i--) {
			table.swap(0, i);
			int current = 0;
			do {
				swapping = false;
				int max;
				int left = current * 2 + 1;
				int right = current * 2 + 2;
				if (left < i && right < i)
					max = kriterium.evaluate(*table.getItemAtIndex(left).accessData()) > kriterium.evaluate(*table.getItemAtIndex(right).accessData()) ? left : right;
				else
					max = left < i ? left : right;
				if (max < i && kriterium.evaluate(*table.getItemAtIndex(max).accessData()) > kriterium.evaluate(*table.getItemAtIndex(current).accessData())) {
					table.swap(max, current);
					current = max;
					swapping = true;
				}
				//notify();
			} while (swapping);
		}
		
	}

	template <typename K, typename T, typename O, typename S>
	void HeapSort<K, T, O, S>::sortDesc(UnsortedSequenceTable<K, T>& table, Kriterium<O, S>& kriterium)
	{
		bool swapping;
		for (int i = 1; i < table.size(); i++) {
			int current = i;
			do {
				swapping = false;
				int father = (current - 1) / 2;
				if ((current > 0) && (kriterium.evaluate(*table.getItemAtIndex(current).accessData()) < kriterium.evaluate(*table.getItemAtIndex(father).accessData()))) {
					table.swap(current, father);
					current = father;
					swapping = true;
				}
			} while (swapping);
		}
		for (int i = table.size() - 1; i > 0; i--) {
			table.swap(0, i);
			int current = 0;
			do {
				swapping = false;
				int min;
				int left = current * 2 + 1;
				int right = current * 2 + 2;
				if (left < i && right < i)
					min = kriterium.evaluate(*table.getItemAtIndex(left).accessData()) < kriterium.evaluate(*table.getItemAtIndex(right).accessData()) ? left : right;
				else
					min = left < i ? left : right;
				if (min < i && kriterium.evaluate(*table.getItemAtIndex(min).accessData()) < kriterium.evaluate(*table.getItemAtIndex(current).accessData())) {
					table.swap(min, current);
					current = min;
					swapping = true;
				}
				//notify();
			} while (swapping);
		}
	}


}