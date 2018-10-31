#include <map>
#include <vector>

/*!
  This is a network of nodes with bidirectional links: if <b>(a, b)</b> is a link then <b>(b, a)</b> is also a link.

  Each node supports a *double* value, and the list of nodes is in fact defined by the list of their values.
 */

class Network {

public:
    Network() {}

/*! 
     Resizes the list of nodes (\ref values) and also resets all values.
     After this function is called \ref values has size *n* and contains random numbers (normal distribution, mean=0, sd=1).
*/
    void resize(const size_t&); /*DONE*/
/*! Adds a bidirectional link between two nodes
  @param[in] a,b the indexes if the two nodes 
  @param[out] success the link was succesfully inserted (true if both nodes exist and the link did not exist yet)
 */
    bool add_link(const size_t&, const size_t&); /*DONE*/
/*! Creates random connections between nodes: each node *n* will be linked with *degree(n)* other nodes (randomly chosen),
 where *degree(n)* is Poisson-distributed.
  All previous links are erased first.
  @param mean_deg the average of the Poisson distribution.
  @param[out] numbers of \ref links created
 */
    size_t random_connect(const double&); /*WIP*/
/*! Resets all node values.
  @param[in] vector of new node values
  @param[out] number of nodes succesfully reset
 */
    size_t set_values(const std::vector<double>&);/*DONE*/
/*! Number of nodes */
    size_t size() const; /*DONE*/
/*! Degree (number of links) of node no *n* */
    size_t degree(const size_t &_n) const; /*DONE*/
/*! Value of node no *n* */
    double value(const size_t &_n) const; /*DONE*/
/*! All node values in descending order */
    std::vector<double> sorted_values() const; /*DONE*/
/*! All neighbors (linked) nodes of node no *n* */
    std::vector<size_t> neighbors(const size_t&) const; /*DONE*/

private:
    std::vector<double> values;
    std::multimap<size_t, size_t> links;

};
