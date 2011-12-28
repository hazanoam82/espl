
  #include <stdio.h>
  #include <stdlib.h>
  #include <unistd.h>
  #include <diff.h>
    
    void help()
    {
      printf("NAME\n   bfix - apply differences to a binary file\n\nSYNOPSIS\n   bfix [OPTIONS] file differences\n\nDESCRIPTION\n   bfix applies the differences (second argument) as printed\n   by bcmp(3) to the file (the first argument).\n   Before applying each difference, bfix verifies that the old value\n   of the byte in the file is the same as the old value in the\n   difference line. If option -r is specified, the differences are\n   reversed: the new value must be changed to the old value.\n\nOPTIONS\n   -h  print a summary of options and exit\n   -r  reverse the differences\n   -m  print a message each time a change is applied\n\nSEE ALSO\n   bcmp(3)\n");
    return;
    };
   
 
   FILE *file_txt;
   FILE *file_diff;
   int h_flag = 0;
   int r_flag = 0;
   int m_flag = 0;
   int c;
    
     int main (int argc, char **argv)
     {
       opterr = 0;
       while ((c = getopt (argc, argv, "hrm::")) != -1)
         switch (c)
           {
           case 'h':
	     h_flag=1;
             break;
           case 'r':
             r_flag = 1;
             break;
           case 'm':
             m_flag = 1;
             break;          
           default:
             abort ();
           }
      if (!(file_txt = fopen(argv[optind],"r+"))) {

        printf("bad input file name\n");

        return;

       }

      if (!(file_diff = fopen(argv[optind+1],"r"))) {

        printf("bad diff file name\n");

        return;
      }
      
    char line[128];

    int diffNum=0;
 
    struct diff current;

    while (fgets(line,128,file_diff) ) {

      printf("read diff line: %s\n",line);

      parsediff(line,&current);

      fseek(file_txt,current.offset,SEEK_SET);

      char value[1];

      printf("new: %c  old: %c \n", current.new, current.old);

      if (r_flag==1) {    
 
        fputc(-current.new,file_txt);

      }

      else

        fputc(-current.old,file_txt);


      if (m_flag==1)

        printf("a change applied at byte %ld\n", current.offset);    

      }
       
      fclose(file_txt);
       
      fclose(file_diff);
       
       return 0;
     }
     
