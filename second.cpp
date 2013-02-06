//============================================================================
// Name        : second.cpp
// Author      : Anna Dackiewicz
// Version     :
// Copyright   :
// Description : Getting all permutations.
//============================================================================

#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

void printMultimapOfIntAndVector(const multimap<int, vector<int> >& theResult) {
	for (multimap<int, vector<int> >::const_iterator result_it =
			theResult.begin(); result_it != theResult.end(); ++result_it) {
		cout << result_it->first << "\t";
		for (vector<int>::const_iterator vec_iterator =
				result_it->second.begin();
				vec_iterator != result_it->second.end(); ++vec_iterator) {
			cout << *vec_iterator << " ";
		}
		cout << endl;
	}
}

multimap<int, vector<int> > getAllPermutations(multiset<int> theSet) {
	multimap<int, vector<int> > theResult;

	if (theSet.empty()) {
		// If theSet is empty.
		vector<int> tmp_vector;
		theResult.insert(make_pair(0, tmp_vector));
	} else if (theSet.size() == 1) {
		// If theSet has only one element.
		vector<int> tmp_vector;
		tmp_vector.push_back(*(theSet.begin()));
		theResult.insert(make_pair(*(theSet.begin()), tmp_vector));
	} else {
		multiset<int> tmp_set = theSet;
		tmp_set.erase(tmp_set.begin());
		multimap<int, vector<int> > tmp_res = getAllPermutations(tmp_set);
		printMultimapOfIntAndVector(tmp_res);
		for (multimap<int, vector<int> >::iterator it = tmp_res.begin();
				it != tmp_res.end(); ++it) {
			printMultimapOfIntAndVector(theResult);
			for (int i = 0; i < it->second.size(); ++i) {
				vector<int> add_begin;
				for (int j = 0; j < i; ++j) {
					add_begin.push_back(it->second[j]);
				}
				add_begin.push_back(*(theSet.begin()));
				for (int j = i; j < it->second.size(); ++j) {
					add_begin.push_back(it->second[j]);
				}
				theResult.insert(make_pair(it->first + *(theSet.begin()),
						add_begin));
			}
			// Add at the end
			{
				vector<int> add_begin;
				for (int i = 0; i < it->second.size(); ++i) {
					add_begin.push_back(it->second[i]);
				}
				add_begin.push_back(*(theSet.begin()));
				theResult.insert(make_pair(it->first + *(theSet.begin()),
						add_begin));

			}
		}
	}
	printMultimapOfIntAndVector(theResult);
	return theResult;
}

int main() {
	cout << "Tmp" << endl; // prints PRI projekt 3
	multiset<int> theSet;
	theSet.insert(1);
	theSet.insert(3);
	theSet.insert(2);

	multimap<int, vector<int> > theResult = getAllPermutations(theSet);
	printMultimapOfIntAndVector(theResult);
	return 0;
}
