#include <sdsl/suffix_trees.hpp>
#include <sdsl/bp_support_sada.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sdsl;

typedef cst_sct3<> cst_t;
typedef cst_sada<> csts_t;

int main(int argc, char* argv[])
{
    if (argc < 2) {
        cout << "usage: "<< argv[0] << " file" << std::endl;
        return 1;
    }

    int element_size = 1;
    if (argc > 2) {
        element_size = atoi(argv[2]);
    }

    csts_t csts;
    construct(csts, argv[1], element_size, element_size);
    auto roots = csts.root();

	std::cout << "root degree = " << csts.degree(roots) << std::endl;
	std::cout << "root id = " << csts.id(roots)
			<< ", root inv_id = " << csts.inv_id(roots) << std::endl;

    for (auto child: csts.children(roots)) {
	std::cout << "child: " << child
			<< ", label from root: " << extract(csts, child)
			<< ", child degree = " << csts.degree(child) << std::endl;
    }
    cout << "full text: " << extract(csts.csa, 0, csts.csa.size()-1) << endl;
}
