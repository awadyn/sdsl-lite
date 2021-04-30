#include <sdsl/suffix_trees.hpp>
#include <fstream>

using namespace sdsl;

int main() {
	cst_sada<> cst;

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

//	sdsl::cst_sada<>::node_type root_proxy = cst.root();
//	cst_node_child_proxy<cst_sada<>> children_proxy = cst.children(root_proxy);
//
//	int i = 1;
//	while (i <= cst.degree(root_proxy) + 1) {
//		std::cout << "select_child(root, " << i << ") : " << cst.select_child(root_proxy, i) << std::endl;
//		std::cout << "edge(select_child(root, " << i << "), 1) : " << (int)cst.edge(cst.select_child(root_proxy, i), 1) << std::endl;
//		i++;
//	}

//	std::cout << "select_child(root, 1) : " << cst.select_child(root_proxy, 1) << std::endl;
//	std::cout << "edge(select_child(root, 1), 1) : " << (int)cst.edge(cst.select_child(root_proxy, 1), 1) << std::endl;
//	std::cout << "select_child(root, 2) : " << cst.select_child(root_proxy, 2) << std::endl;
//	std::cout << "edge(select_child(root, 2), 1) : " << (int)cst.edge(cst.select_child(root_proxy, 2), 1) << std::endl;
//	std::cout << "select_child(root, 3) : " << cst.select_child(root_proxy, 3) << std::endl;
//	std::cout << "edge(select_child(root, 3), 1) : " << (int)cst.edge(cst.select_child(root_proxy, 3), 1) << std::endl;
//	std::cout << "select_child(root, 4) : " << cst.select_child(root_proxy, 4) << std::endl;
//	std::cout << "edge(select_child(root, 4), 1) : " << (int)cst.edge(cst.select_child(root_proxy, 4), 1) << std::endl;
//	std::cout << "select_child(root, 5) : " << cst.select_child(root_proxy, 5) << std::endl;
//	std::cout << "edge(select_child(root, 5), 1) : " << (int)cst.edge(cst.select_child(root_proxy, 5), 1) << std::endl;
//	std::cout << "select_child(root, 6) : " << cst.select_child(root_proxy, 6) << std::endl;
//	std::cout << "edge(select_child(root, 6), 1) : " << (int)cst.edge(cst.select_child(root_proxy, 6), 1) << std::endl;
//	std::cout << "select_child(root, 7) : " << cst.select_child(root_proxy, 7) << std::endl;
//	std::cout << "edge(select_child(root, 7), 1) : " << (int)cst.edge(cst.select_child(root_proxy, 7), 1) << std::endl;
//	std::cout << "select_child(root, 8) : " << cst.select_child(root_proxy, 8) << std::endl;
//	std::cout << "edge(select_child(root, 8), 1) : " << (int)cst.edge(cst.select_child(root_proxy, 8), 1) << std::endl;
}
