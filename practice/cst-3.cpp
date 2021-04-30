#include <sdsl/suffix_trees.hpp>
#include <fstream>

using namespace sdsl;

int main() {
	cst_sada<> cst;

	// generate int vector
	// create csa from int vector
	// check csa size

	construct(cst, "temp.seq.rep", 2);

	sdsl::cst_sada<>::node_type root_proxy = cst.root();
	sdsl::csa_sada<> csa_proxy= cst.csa;

	std::cout << "nodes : " << cst.nodes() << std::endl;
	std::cout << "cst.size() : " << cst.size() << std::endl;
	std::cout << "csa.size() : " << cst.csa.size() << std::endl;
	std::cout << "suffixes : " << cst.size(root_proxy) << std::endl;
	std::cout << "inner nodes : " << cst.nodes() - cst.size(root_proxy) << std::endl;

	std::cout << "root : " << root_proxy << std::endl; 
	std::cout << "id(root) : " << cst.id(root_proxy) << std::endl; 
	std::cout << "inv_id(root_id) : " << cst.inv_id(cst.id(root_proxy)) << std::endl; 

	std::cout << "degree(root) : " << cst.degree(root_proxy) << std::endl; 

}
