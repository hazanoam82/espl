#include <elf.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char **argv) {

  int fd;
  void *map_start;
  struct stat fd_stat;
  Elf32_Ehdr *header;

  if( (fd = open(argv[1], O_RDWR)) < 0 ) {
	perror("error in open");
	exit(-1);
  }
	
  if( fstat(fd, &fd_stat) != 0 ) {
	perror("stat failed");
	exit(-1);
  }
	
  if ( (map_start = mmap(0, fd_stat.st_size, PROT_READ | PROT_WRITE , MAP_SHARED, fd, 0)) <0 ) {
	perror("mmap failed");
	exit(-4);
  }
	
  header = (Elf32_Ehdr *) map_start;
  
  int i=0;
  printf ("Magic: ");
   for( i=0; i<6; i++){
     
     printf ("%x ",header->e_ident[i]);
   }
    printf ("\n");

   int class=header->e_ident[EI_CLASS];
   if(class==0)
     printf("Class: ELFCLASSNONE\n");      
   if(class==1)
     printf("Class: ELFCLASS32\n");
   if(class==2)
    printf("Class: ELFCLASS64\n");
 
   int data1=header->e_ident[EI_DATA];
   if(data1==0)
     printf("Data: ELFDATANONE\n");
   if(data1==1)
     printf("Data: ELFDATA2LSB\n");
   if(data1==2)
     printf("Data: ELFDATA2MSB\n");
 
   printf("Version: %d\n",header->e_ident[EI_VERSION] ) ;
   
   if (header->e_type==0)
     printf("Type: No file type");
   if (header->e_type==1)
     printf("Type: Relocatable file");
   if (header->e_type==2)
     printf("Type: Executable file");
   if (header->e_type==3)
     printf("Type: Shared object file");
   if (header->e_type==4)
     printf("Type: Core file");
   if (header->e_type==0xff00)
     printf("Type: Processor-specific");
   if (header->e_type==0xffff)
     printf("Type: Processor-specific");
   printf("\n");
 
   int machine=header->e_machine;
   if(machine==0)
      printf("Machine: no machine\n");
   if(machine==1)
     printf("Machine: AT&T WE 32100\n");
   if(machine==2)
     printf("Machine: SPARC\n");
   if(machine==3)
     printf("Machine: intel 80386\n");
   if(machine==4)
     printf("Machine: Motorola 68000\n");
   if(machine==5)
    printf("Machine: Motorola 88000\n");
   if(machine==7)
    printf("Machine: Intel 80860\n");
   if(machine==8)
    printf("Machine: MIPS RS3000\n");
   
  printf("Version: 0x%X\n",header->e_version );
  printf("Entry: 0x%X\n",header->e_entry);
  printf("Start of program headers: %d\n",header->e_phoff ) ;
  printf("Start of section headers: %d\n",header->e_shoff ) ;
  printf("Flags: 0x%X\n",header->e_flags);
  printf("Size of this header: %d\n",header->e_ehsize);
  printf("Size of program headers: %d\n",header->e_phentsize );
  printf ("Number of program headers: %d\n", header->e_phnum);
  printf("Size of section headers: %d\n",header->e_shentsize );
  printf ("Number of section headers: %d\n", header->e_shnum);
  printf ("Section header string table index: %d\n",header->e_shstrndx);
 
   return 0;
}
