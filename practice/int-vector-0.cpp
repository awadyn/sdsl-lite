#include <sdsl/int_vector.hpp>
#include <sdsl/suffix_trees.hpp>
#include <sdsl/construct.hpp>
#include <fstream>

using namespace sdsl;
using namespace std;


// for use by csXprintf function
std::string format("%3I%3S %3s %3P %3p %3L %3B  %T");
std::string header("  i SA ISA PSI  LF LCP BWT  TEXT");
static const std::streamsize BUF_SIZE=4096;
char line[BUF_SIZE];


int main() {
#if 0
	// option 1: construct cst using 1-byte tokens
	cst_sada<> cst;
	cout << "Constructing suffix tree cst.." << endl;
	construct(cst, "string.hex", 1);
#endif

#if 0
	// option 2: construct cst using 2-byte tokens
	cst_sada<> cst;
	cout << "Constructing suffix tree cst.." << endl;
	construct(cst, "string.hex", 2);

#endif

#if 1
	// option 3: construct cst using int vector
	int_vector<> v;
	cout << "Constructing int_vector v.." << endl;
	load_vector_from_file(v, "string.hex", 2);
	cout << "v.size() = " << v.size() << ", v.width() = " << (int)v.width() << endl;
	cst_sada<csa_wt<wt_int<rrr_vector<>>>> cst;
	cout << "Constructing suffix tree cst.." << endl;
	construct_im(cst, v);
#endif

#if 0
	// application using tip trace file
//	int_vector<> v;
//	cout << "Constructing int_vector v.." << endl;
//	load_vector_from_file(v, "temp.seq.rep", 2);
//	cout << "v.size() = " << v.size() << ", v.width() = " << (int)v.width() << endl;

	// here is some magic I don't fully understand: rrr_vector and wt_int
	// these data structures seem to be necessary for this approach;
	// could not find a way to do this via intvector directly
	cst_sada<csa_wt<wt_int<rrr_vector<>>>> cst;
	cout << "Constructing suffix tree cst.." << endl;
	construct_im(cst, v);
#endif

	cout << "cst.size() = " << cst.size() << endl;
	cout << "cst.nodes() = " << cst.nodes() << endl;
	cout << "internal nodes = " << cst.nodes() - cst.size() << endl;


// this function computes and prints suffix tree relevant values for every suffix
//
// uncomment for small tests, but note that it takes a long time 
// to compute otherwise
#if 1
        csXprintf(cout, format, cst, '\n');
#endif
}
