#include "network.h"
#include "random.h"
#include <iostream>

void Network::resize (const size_t& count) {
	RandomNumbers random; 
	if (not values.empty()) {
		if (count>values.size()) {
			for (size_t i(0); i<count; ++i) {
				values.push_back(random.normal());
				}
			}
		if (count<values.size()) {
			for (size_t i(count); i<values.size(); ++i) {
				values.pop_back();
				}
			for (size_t j(0); j<values.size(); ++j) {
				values[j]=random.normal();
				}
			}
		}
	else {
		for (size_t i(0); i<count ; ++i) {
			values.push_back(random.normal());
			}
		} 
	}

bool Network::add_link (const size_t& _i, const size_t& _j) {
	if (not(values.empty())) {
		if (_i!=_j) {
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
			return false;
		}
		else return false;
				
		}
	else return false;
	}

size_t Network::random_connect(const double& _mean) {
	links.clear();
	RandomNumbers random;
	size_t link_r(0); //number of newly created links
	std::vector<int> degrees(values.size());
	random.poisson(degrees, _mean);
	
	for (size_t i(0); i<degrees.size(); ++i) {
		if (degrees[i]>0) {
			std::vector<int> link_to(degrees[i]);
			random.uniform_int(link_to, 0, values.size()-1);
			for (size_t j(0); j<link_to.size(); ++j) {
				if (this->add_link(i, link_to[j])) {
					++link_r;
					}
				}
			}
		}
	return link_r; 
	}

size_t Network::set_values(const std::vector<double>& _vector) {
	if (not values.empty()) {
		size_t R(0);
		if (_vector.size()>values.size()) {
			for (size_t i(0); i<values.size(); ++i) {
				values[i]=_vector[i];
				++R;
				}
			}
		else {
			for (size_t i(0); i<_vector.size(); ++i) {
				values[i]=_vector[i];
				++R;
				}
			}
		return R;
		}
	else {
		values=_vector;
		return values.size();
		}
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
		return 0;
		}
	return 0;
	}

double Network::value(const size_t& _n) const {
	if (not(values.empty())) {
		for (size_t i(0); i<values.size(); ++i) {
			if (i==_n) { return values[i];}
			}
		}
	std::cerr<<"No existing nodes"<<std::endl;
	//return 0;
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
