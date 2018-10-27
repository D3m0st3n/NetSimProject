#include "network.h"
#include <iostream>

void Network::resize (const size_t& count) { /*See how to manage default value for initializing new values*/
	if (count>values.size()) {
		for (size_t i(0); i<count; ++i) {
			values.push_back(0.);
			}
		}
	if (count<values.size()) {
		for (size_t i(count); i<values.size(); ++i) {
			values.pop_back();
			}
		}
	}

bool Network::add_link (const size_t& _i, const size_t& _j) {
	if (not(values.empty())) {
		
		//We create to list of elements that have _i and _j as keys
		auto search_i(links.equal_range(_i));
		auto search_j(links.equal_range(_j));
		
		//We compare every element of each list
		for (auto i=search_i.first; i!=search_i.second; ++i) {
			for (auto j=search_j.first; j!=search_j.second; ++j ) {
				 if (i->first==j->second or j->first==i->second) {
					 return false;
					 }
				} 
			}
		
		
		
		if (_i<values.size() and _j<values.size()) {
			links.insert({_i,_j});
			links.insert({_j,_i});
			return true;
			}
		
		else return false;
				
		}
	else return false;
	}

size_t Network::random_connect(const double&) {
	return values.size();
	}

size_t Network::set_values(const std::vector<double>& _vector) {
	values=_vector;
	return values.size();
	}

size_t Network::size() const { return values.size();}

size_t Network::degree(const size_t& _n) const {
	if (not values.empty()) {
		if (_n<values.size()) {
			size_t degree(0);
			auto search(links.equal_range(_n));
			for (auto it=search.first; it!=search.second; ++it) {
				if (_n==it->first) {
					++degree;
					}
				}
			return degree;
			}
		}
	}

double Network::value(const size_t& _n) const {
	if (not(values.empty())) {
		for (size_t i(0); i<values.size(); ++i) {
			if (i==_n) { return values[i];}
			}
		}
	/*How to manage empty vectors???*/
	}

std::vector<double> Network::sorted_values() const {
	std::vector<double> _sorted(values);
	if (not(values.empty())) {
		
		double k;
		
		for (size_t i(0); i<_sorted.size(); ++i) {
			for (size_t j(i); j<_sorted.size(); ++j) {
				if (_sorted[i]<_sorted[j]) {k=_sorted[i];
					_sorted[i]=_sorted[j];
					_sorted[j]=k;}
				}
			}
		return _sorted;
		}
		
	else return _sorted; 
	}

std::vector<size_t> Network::neighbors(const size_t& _n) const {
	if (not values.empty()) {
		if (_n<values.size()) {
			std::vector<size_t> neighbors;
			for (auto it=links.begin(); it!=links.end(); ++it) {
				if (_n==it->first) {
					neighbors.push_back(it->second);
					}
				}
			return neighbors;
			}
		else std::cerr<<"Index out of the list"<<std::endl;
		}
	else std::cerr<<"List of nodes empty"<<std::endl;
	}
