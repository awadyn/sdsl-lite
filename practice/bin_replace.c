#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char* argv[]) {
	if (argc == 1) {
		fprintf(stderr, "BAD RUN: must pass in binary sequence file name.\n");
		return -1;
	}

	char *infile = argv[1];
	char *outfile = (char *)malloc(sizeof(infile) + 4);
	int i = 0;
	char *itr = infile;
	while (*itr) {
		outfile[i] = *itr;
		itr ++;
		i ++;
	}
	outfile[i] = '.';
	outfile[i+1] = 'r';
	outfile[i+2] = 'e';
	outfile[i+3] = 'p';

	fprintf(stderr, "RUN: replacing zero values in binary %s with MAX FID 595\n", infile);

	FILE *bin_seq;
	FILE *bin_seq_rep;
	bin_seq = fopen(infile, "rb");
	bin_seq_rep = fopen(outfile, "wb");
	if (!bin_seq) {
		fprintf(stderr, "ERROR: cannot open binary sequence file for reading.\n");
		return -1;
	}
	if (!bin_seq_rep) {
		fprintf(stderr, "ERROR: cannot open binary sequence file for writing.\n");
		return -1;
	}

	uint16_t fid;
	uint16_t fid_rep = 0x253;

	while (fread(&fid, sizeof(uint16_t), 1, bin_seq)) {
		if (fid == 0) { 
			if (fwrite(&fid_rep, sizeof(uint16_t), 1, bin_seq_rep) == -1) {
				fprintf(stderr, "ERROR: cannot write to binary sequence file.\n");
			};
			//if (fwrite(&fid_rep_2, sizeof(uint16_t), 1, bin_seq_rep) == -1) {
			//	fprintf(stderr, "ERROR: cannot write to binary sequence file.\n");
			//};
		} else {
			if (fwrite(&fid, sizeof(uint16_t), 1, bin_seq_rep) == -1) {
				fprintf(stderr, "ERROR: cannot write to binary sequence file.\n");
			}
		}
	}

	{
		if (ferror(bin_seq)) {
			fprintf(stderr, "ERROR: error reading from %s.", infile);
			return -1;
		}
		if (ferror(bin_seq_rep)) {
			fprintf(stderr, "ERROR: error writing to %s.", outfile);
			return -1;
		}
		assert(feof(bin_seq));
	}

	fclose(bin_seq);
	fclose(bin_seq_rep);

	return 0;
}

