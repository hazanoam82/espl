cmp: cmp.o hsvmhr.o
	gcc -m32 -o cmp cmp.o hsvmhr.o
cmp.o: cmp.c
	gcc -m32 -c -o cmp.o cmp.c
%.o: %.asm
	nasm -g -f elf -o $@ $<