     #include <ctype.h>
     #include <stdio.h>
     #include <stdlib.h>
     #include <unistd.h>
    
    void help()
    {
      printf("NAME\n   bfix - apply differences to a binary file\n\nSYNOPSIS\n   bfix [OPTIONS] file differences\n\nDESCRIPTION\n   bfix applies the differences (second argument) as printed\n   by bcmp(3) to the file (the first argument).\n   Before applying each difference, bfix verifies that the old value\n   of the byte in the file is the same as the old value in the\n   difference line. If option -r is specified, the differences are\n   reversed: the new value must be changed to the old value.\n\nOPTIONS\n   -h  print a summary of options and exit\n   -r  reverse the differences\n   -m  print a message each time a change is applied\n\nSEE ALSO\n   bcmp(3)\n");
    return;
    };
   
   char word[10];
   char jump[10];
   char old[10];
   char new[10];
   char new1[10];
   FILE *file_txt;
   FILE *file_diff;
   int h_flag = 0;
   int r_flag = 0;
   int m_flag = 0;
   int c;
   
   void reverse()
   {
     while(feof(file_diff)==0)
     {
       fscanf(file_diff, "%s" ,word);
       fscanf(file_diff, "%s" ,jump);
       fscanf(file_diff, "%s" ,old);
       fscanf(file_diff, "%s" ,new);       
       fseek(file_txt, (long)jump, SEEK_SET);
       fwrite(new, 2, 1, file_txt);
       fseek(file_txt, (long)jump, SEEK_SET);
       fscanf(file_txt, "%s" ,new1); 
       if(m_flag==1)       
        printf("byte before change: %s after change: %s\n",new,new1);
     }
   };
    
     int main (int argc, char **argv)
     {
       file_txt = fopen("b.txt", "r+");
       if(!file_txt)
       {
         printf("Error: could not open file b!\n");
       }
       
       file_diff = fopen("all.diff", "rt");
       if(!file_diff)
       {
         printf("Error: could not open file all.diff!\n");
       }
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

       if(h_flag==1)
         help();
       if(r_flag==1)
         reverse();
       
       fclose(file_txt);
       fclose(file_diff);
       
       return 0;
     }
     
