#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


void help()
{
  printf("\nNAME\n  dir - print list of files in the directory\n\nSYNOPSIS\n  dir [OPTIONS] [directory]\n\nDESCRIPTION\n  dir prints a list of files in the directory specified as the argument,\n  on file per line.\n  If the directory name is not specified,\n  the list of files in the current directory is printed.\n\nOPTIONS\n  -h   print summary of options and exit.\n  -l   print file size in bytes before the file name.\n\n");
  return;
};


void sizefile()
{
}

 
int main(int argc, char **argv)
{
        DIR *dip;
        struct dirent *dit;
        struct stat fileStat;
        int i = 0;
        int h_flag = 0;
        int l_flag = 0;
        int c;
        
        
        opterr = 0;
        while ((c = getopt (argc, argv, "hl::")) != -1)
         switch (c)
           {
           case 'h':
	     h_flag=1;
             break;
           case 'l':
             l_flag = 1;
             break;        
           default:
             abort();
           }

        if(h_flag==1)
          help();
        
        
        
        /* check to see if user entered a directory name */
        if (argc < 2)
        {
                printf("Usage: %s <directory>\n", argv[0]);
                return 0;
        }
        
      
 
        /* DIR *opendir(const char *name);
         *
         * Open a directory stream to argv[1] and make sure
         * it's a readable and valid (directory) */
        if ((dip = opendir(argv[1])) == NULL)
        {
                perror("opendir");
                return 0;
        }
 
        printf("Directory stream is now open\n");
 
        /*  struct dirent *readdir(DIR *dir);
         *
         * Read in the files from argv[1] and print */
        while ((dit = readdir(dip)) != NULL)
        {
//                fstat((long)dip,&fileStat);    
                i++;
/*                if(l_flag==0)
                  printf("File: '%s', Size of this file:  %d bytes\n" ,dit->d_name, (int)fileStat.st_size);
                printf("\n%s ", dit->d_name);
*/      
	        printf("File: '%s', Size of this file:  %d bytes\n" ,dit->d_name, dit->d_reclen);
        }
 
        printf("\n\nreaddir() found a total of %i files\n", i);
 
        /* int closedir(DIR *dir);
         *
         * Close the stream to argv[1]. And check for errors. */
        if (closedir(dip) == -1)
        {
                perror("closedir");
                return 0;
        }
 
        printf("\nDirectory stream is now closed\n");
      
        return 1;
}
