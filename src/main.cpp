#include <iostream>
#include <string>
#include <utility>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

typedef pair<unsigned int, unsigned int> apath;
typedef set<apath> candidate_list;
typedef candidate_list::iterator cl_it;

bool contains_target_characters( string s, string t) {
	bool all_found = true;
	for (auto c: t) {
		auto result = s.find(c);
		if (string::npos == result){
			all_found = false;
			break;
		}
	}
	return all_found;
}


bool create_new_window_if(unsigned int i, unsigned int j, string& os, string& target, candidate_list& cl) {
	bool new_path_found = false;
	auto t_s = os.substr(i, j);
	if ( contains_target_characters(t_s, target)) {
		auto n_pp = std::make_pair(i, j);
		auto r = cl.emplace(n_pp);
		new_path_found = r.second; // true if the new path was inserted in the set, which means it was not a repeated member.
		if (new_path_found) {
			cout << "New path found <" << i << ", " << j << ">" << endl;
		}
	}
	return new_path_found;
}



string minWindowSubstring(string strArr[], int arrLength) {
	string result = "";

	if (arrLength != 2){
		return "Error: array must contain two strings";
	}
	else {
		auto os = strArr[0];
		auto target =  strArr[1];

		candidate_list cl;

//		The first candidate has to be the original string itself
		auto is_good_candidate = contains_target_characters(os, target);
		if (is_good_candidate == true ) {
			apath first_path = make_pair(0, os.size()-1);
			cl.emplace(first_path); // this is the default best answer
			for (auto c_i = target.begin(); c_i < target.end(); c_i++){
				for (unsigned int pos = 0; pos < os.size(); pos++){
					if ( *c_i == os[pos]) {
						for (auto pp = cl.begin(); pp != cl.end(); pp++) {
							if ( (pp->first == pos) || (pp->second == pos) ) {
								cout << "Found a boundary letter " << *c_i << " in: <" << pp->first << ", " << pp->second << "> continuing ..." << endl;
								continue;
							}
							// there are three cases possible: 'pos' is before first, after second, or between them
							if ( pp->first > pos) {
								create_new_window_if(pos, pp->second, os, target, cl);
							} else if (pp->second < pos) {
								create_new_window_if(pp->first, pos, os, target, cl);
							} else if (pp->first < pos) { // at this point 'pos' must be between first and second
								create_new_window_if(pp->first, pos, os, target, cl);
								create_new_window_if(pos, pp->second, os, target, cl);
							}
							else {
								cerr << "Impossible option found!" << endl;
							}
						}
					}
				}
			}
			unsigned int m_i = os.size();
			unsigned int p = 0;
			cout << "---" << endl;
			cout << "Summary of paths found" << endl;
			cout << "---" << endl;
			for (auto i = cl.begin(); i != cl.end(); i++ ) {
				auto len = i->second - i->first + 1;
				cout << "<" << i->first << ", " << i->second << ">, " << len << endl;
				if (len >= target.size()) {
					m_i = std::min(m_i, len);
					p = i->first;
				}
			}
			result = os.substr(p, m_i);
		}
		else {
			cout << "The original string '" << os << "' does not contain the target substring '" << target << "'" << endl;
		}
	}
	return result;
}




int main(int argc, char * argv []) {

	if (argc != 3 ) {
		cout << "Usage: first argument muts be string of n characters, second argument string of m characters, m < n." << endl;
		exit(0);
	} else {
		string a[2] = {argv[1], argv[2]};
		cout << "Original string: " << argv[1] << endl;
		cout << "target string: " << argv[2] << endl;

		// keep this function call here
		int arrLength = sizeof(a) / sizeof(*a);
		cout << minWindowSubstring(a, arrLength);
	}
	return 0;
}
