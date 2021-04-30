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
	outfile[i+1] = 't';
	outfile[i+2] = 'x';
	outfile[i+3] = 't';

	fprintf(stderr, "RUN: translating binary %s to ascii %s\n", infile, outfile);

	FILE *bin_seq, *ascii_seq;
	bin_seq = fopen(infile, "rb");
	ascii_seq = fopen(outfile, "w");
	if (!bin_seq || !ascii_seq) {
		fprintf(stderr, "ERROR: cannot open binary or ascii sequence file.\n");
		return -1;
	}

	uint16_t fid;
	while (fread(&fid, sizeof(uint16_t), 1, bin_seq))
		fprintf(ascii_seq, "%hu\n", fid);	

	{
		if (ferror(bin_seq)) {
			fprintf(stderr, "ERROR: error reading from %s.", infile);
			return -1;
		}
		if (ferror(ascii_seq)) {
			fprintf(stderr, "ERROR: error writing to %s.", outfile);
			return -1;
		}
		assert(feof(bin_seq));
	}

	fclose(bin_seq);
	fclose(ascii_seq);

	return 0;
}
