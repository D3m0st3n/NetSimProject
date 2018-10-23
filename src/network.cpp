#include "network.h"

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

bool Network::add_link (const size_t&, const size_t&) {}

size_t Network::random_connect(const double&) {}

size_t Network::set_values(const std::vector<double>& _vector) {
	values=_vector;
	return values.size();
	}

size_t Network::size() const { return values.size();}

size_t Network::degree(const size_t &_n) const {}

double Network::value(const size_t &_n) const {
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
				if (i<j) {k=_sorted[i];
					_sorted[i]=_sorted[j];
					_sorted[j]=k;}
				}
			}
		return _sorted;
		}
		
	else return _sorted;
	}

std::vector<size_t> Network::neighbors(const size_t&) const {}
