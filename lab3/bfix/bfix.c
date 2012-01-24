#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "diff.h"


void helper() {
	printf("NAME\n   bfix - apply differences to a binary file\n\nSYNOPSIS\n   bfix [OPTIONS] file differences\n\nDESCRIPTION\n   bfix applies the differences (second argument) as printed\n   by bcmp(3) to the file (the first argument).\n   Before applying each difference, bfix verifies that the old value\n   of the byte in the file is the same as the old value in the\n   difference line. If option -r is specified, the\ndifferences are\n   reversed: the new value must be changed to the old value.\n\nOPTIONS\n   -h  print a summary of options and exit\n   -r  reverse the differences\n   -m  print a message each time a change is\napplied\n\nSEE ALSO\n    bcmp(3)\n\n");
};

int main (int argc, char **argv) {
	char v=0,help=0,r=0;
	char c;
	char flag=0;
	while ( (c=getopt(argc,argv,"hrm")) != -1 ) {
		switch (c) {
			case 'h':
				helper();
				return;
			case 'r':
				r=1;
				break;
			case 'm':
				v=1;
				break;
		}
	}
	FILE *input,*diffFile;
	if (!(input = fopen(argv[optind],"r+"))) {
		printf("bad input file name\n");
		return;
	}
	if (!(diffFile = fopen(argv[optind+1],"r"))) {
		printf("bad diff file name\n");
		return;
	}
	char line[128];
	struct diff current;
	while ( fgets(line,128,diffFile) ) {
		printf("read diff line: %s\n",line);
		parsediff(line,&current);
		fseek(input,current.offset,SEEK_SET);
		char value[1];
		printf("new: %i  old: %i \n", current.new, current.old);
		if (r==1) {		
			fputc(-current.new,input);
		}
		else
			fputc(-current.old,input);
		if (v==1)
			printf("a change applied at byte %ld\n", current.offset);		
	}
		
	
}
