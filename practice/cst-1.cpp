#include <sdsl/suffix_trees.hpp>
#include <fstream>

using namespace sdsl;

/* not working; need to figure out integer trees */

int main() {
	int_vector<> data(10, 0, 64);
	size_t i;
	for (i = 1; i <= data.size(); i ++)
		data[i-1] = (int)i;

	enc_vector<> enc_data = data;

	for (i = 0; i < enc_data.size(); i ++)
		std::cout << enc_data[i] << std::endl;

	cst_sada<csa_sada<enc_vector<int_vector<>>>> cst;

	construct_im(cst, enc_data);

//	construct_im(cst, "abababc", 1);
//	std::cout << "nodes : " << cst.nodes() << std::endl;
//	std::cout << "suffixes : " << cst.csa.size() << std::endl;
//	std::cout << "inner nodes : " << cst.nodes() - cst.csa.size() << std::endl;

	// get child node that starts with char b
//	auto v = cst.select_child(cst.child(cst.root(), 'b'),1);
//	auto e1 = cst.edge(v, 1);
//	auto e2 = cst.edge(v, 2);
//	auto e3 = cst.edge(v, 3);
//	auto e4 = cst.edge(v, 4);
//	auto e5 = cst.edge(v, 5);
//	auto d = cst.depth(v);
//	std::cout << "edge(v, [1, 2, 3, 4, 5]): " << e1 << ", " << e2 << 	\
//		" ," << e3 << " ," << e4  << " ," << e5 << " ," << std::endl;
//	std::cout << "v : " << d << "-[" << cst.lb(v) << "," << cst.rb(v) << "]" << std::endl;
//	std::cout << "extract(cst, v) : " << extract(cst, v) << std::endl;
}
