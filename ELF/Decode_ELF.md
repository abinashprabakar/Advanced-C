/* Sample program */

	#include<stdio.h>
	int a, b, c=2;			/* global variable */
	static int x, y=10, z=20;	/* global static variable */
	const char str[] = "hello";
	int main()
	{
		/* local variable */
		static int i, j, k, n=8, m=9;
		printf("Hello\n");
		return 0;
	}

<b><i> ELF Header: </b></i>

	Magic:	7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00
	Class:					ELF64
	Data: 					2's complement, little endian
      	Version:				1 (current)
      	OS/ABI:					UNIX - System V
      	ABI Version:				0
      	Type:					DYN (Shared object file)
      	Machine:				Advanced Micro Devices X86-64
      	Version:				0x1
      	Entry point address:			0x1060
      	Start of program headers:		64 (bytes into file)
      	Start of section headers:		14744 (bytes into file)
      	Flags:					0x0
      	Size of this header:			64 (bytes)
     	Size of program headers:		56 (bytes)
      	Number of program headers:		13
      	Size of section headers:		64 (bytes)
      	Number of section headers:		31
      	Section header string table index:	30

<b> ELF Header </b>
```
00000000  7f 45 4c 46 02 01 01 00  00 00 00 00 00 00 00 00  |.ELF............|
00000010  03 00 3e 00 01 00 00 00  60 10 00 00 00 00 00 00  |..>.....`.......|
00000020  40 00 00 00 00 00 00 00  98 39 00 00 00 00 00 00  |@........9......|
00000030  00 00 00 00 40 00 38 00  0d 00 40 00 1f 00 1e 00  |....@.8...@.....|
00000040  06 00 00 00 04 00 00 00  40 00 00 00 00 00 00 00  |........@.......|

e_ident[EI_MAG0..EI_MAG3]	0x7f + ELF		Magic Number
e_ident[EI_CLASS]		0x02			64-bit Architecture
e_ident[EI_DATA]		0x01			Little endian
e_ident[EI_VERSION]		0x01			ELF Version V1
e_ident[EI_OSABI]		0x00			System Version V
e_ident[EI_ABIVERSION]		0x00			Unused
e_ident[EI_PAD]			0x00000000000000	7 bytes unused
e_type				0x0003			ET_Shared
e_machine			0x003e			X86_64
e_version 			0x00000001		Version 1
e_entry 			0x00000000001060	Entry point address to which the system first transfer control
e_phoff				0x00000000000040	holds the program header table's file offset in bytes
e_shoff				0x00000000003ad0	holds the section header table's file offset in bytes
e_flags				0x00000000		Architecture-dependent interpretation
e_ehsize			0x0040			holds the ELF header's size in bytes
e_phentsize			0x0038			Size of program header table entry
e_phnum				0x000d			Number of program header table entries
e_shentsize			0x0040			Size of section header table entry
e_shnum				0x001f			Number of section header table entries	
e_shstrndx			0x001e			holds the section header table index of entry
```
<b> Program Header table: Entry </b>
   In ELF Header, the e_phoff member represents the program header table offset in this program
e_phoff = 0x00000000000040. This ELF file contains total 13 program header entries.
```
00000040  06 00 00 00 04 00 00 00  40 00 00 00 00 00 00 00  |........@.......|
00000050  40 00 00 00 00 00 00 00  40 00 00 00 00 00 00 00  |@.......@.......|
00000060  d8 02 00 00 00 00 00 00  d8 02 00 00 00 00 00 00  |................|
00000070  08 00 00 00 00 00 00 00  03 00 00 00 02 00 00 00  |................|

p_type		0x00000006		PHDR type
p_flags		0x00000004		PF_X | PF_R
p_offset	0x00000000000040	Offset of segment in file image
p_vaddr		0x00000000000040	Virtual address of segment in memory
p_paadr		0x00000000000040	Physical address of segment
p_filesz	0x000000000002d8	Size in bytes of segment in file image	
p_memsz		0x000000000002d8	Size in bytes of segment in memory
p_align		0x00000000000008	Alignment
```
<b> Section Header table: Entry </b>
   In ELF header, the e_shoff member represents the section header table offset in this program
e_shof = 0x0000000000003ad0. This ELF file contains total 30 sections.
```
00003ad0  00 00 00 00 00 00 00 00  57 00 00 00 f6 ff ff 6f  |........W.......o|  
00003ae0  02 00 00 00 00 00 00 00  a0 03 00 00 00 00 00 00  |.................|
00003af0  a0 03 00 00 00 00 00 00  24 00 00 00 00 00 00 00  |........$........|
00003b00  06 00 00 00 00 00 00 00  08 00 00 00 00 00 00 00  |.................|

sh_name		0x00000000		Offset in the section header table
sh_type		0x00000000		tyoe = NULL
sh_flags	0x0000000000000000	No flags to this section
sh_addr		0x0000000000000000	Address of the section
sh_offset	0x0000000000000000	Offset in the section where the section resides
sh_size		0x0000000000000000	Size of the section 
sh_link		0x00000000		No links to other section 
sh_info		0x00000000		More information about the section
sh_addralign	0x0000000000000000	Alignment
sh_entsize	0x0000000000000000	Size in bytes of each entry
```
<b><i> The last section is .shstrtab section which contains all the section</b></i>
```
00004250  11 00 00 00 03 00 00 00  00 00 00 00 00 00 00 00  |................|
00004260  00 00 00 00 00 00 00 00  b6 39 00 00 00 00 00 00  |.........9......|
00004270  1a 01 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
00004280  01 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
 
	sh_name		0x00000011		Offset in the section header table
        sh_type		0x00000003		type = STRTAB
        sh_flags	0x0000000000000000	No flags to this section
        sh_addr		0x0000000000000000	Address of the section
        sh_offset     	0x00000000000039b6	Offset in the file where the section resides
        sh_size		0x000000000000011a	Size of the section
        sh_link		0x00000000	  	No links to other sections
        sh_info		0x00000000		More information about the section
        sh_addralign	0x0000000000000001	Alignment 
        sh_entsize	0x0000000000000000	Size in bytes of each entry
```
<b> shstrtab section </b>
```
000039b0  32 2e 32 2e 35 00 00 2e  73 79 6d 74 61 62 00 2e  |2.2.5...symtab..|
000039c0  73 74 72 74 61 62 00 2e  73 68 73 74 72 74 61 62  |strtab..shstrtab|
000039d0  00 2e 69 6e 74 65 72 70  00 2e 6e 6f 74 65 2e 67  |..interp..note.g|
000039e0  6e 75 2e 70 72 6f 70 65  72 74 79 00 2e 6e 6f 74  |nu.property..not|
000039f0  65 2e 67 6e 75 2e 62 75  69 6c 64 2d 69 64 00 2e  |e.gnu.build-id..|
00003a00  6e 6f 74 65 2e 41 42 49  2d 74 61 67 00 2e 67 6e  |note.ABI-tag..gn|
00003a10  75 2e 68 61 73 68 00 2e  64 79 6e 73 79 6d 00 2e  |u.hash..dynsym..|
00003a20  64 79 6e 73 74 72 00 2e  67 6e 75 2e 76 65 72 73  |dynstr..gnu.vers|
00003a30  69 6f 6e 00 2e 67 6e 75  2e 76 65 72 73 69 6f 6e  |ion..gnu.version|
00003a40  5f 72 00 2e 72 65 6c 61  2e 64 79 6e 00 2e 72 65  |_r..rela.dyn..re|
00003a50  6c 61 2e 70 6c 74 00 2e  69 6e 69 74 00 2e 70 6c  |la.plt..init..pl|
00003a60  74 2e 67 6f 74 00 2e 70  6c 74 2e 73 65 63 00 2e  |t.got..plt.sec..|
00003a70  74 65 78 74 00 2e 66 69  6e 69 00 2e 72 6f 64 61  |text..fini..roda|
00003a80  74 61 00 2e 65 68 5f 66  72 61 6d 65 5f 68 64 72  |ta..eh_frame_hdr|
00003a90  00 2e 65 68 5f 66 72 61  6d 65 00 2e 69 6e 69 74  |..eh_frame..init|
00003aa0  5f 61 72 72 61 79 00 2e  66 69 6e 69 5f 61 72 72  |_array..fini_arr|
00003ab0  61 79 00 2e 64 79 6e 61  6d 69 63 00 2e 64 61 74  |ay..dynamic..dat|
00003ac0  61 00 2e 62 73 73 00 2e  63 6f 6d 6d 65 6e 74 00  |a..bss..comment.|
```
<b> Section Header table: Entry .data section </b>
```
00004110  06 01 00 00 01 00 00 00  03 00 00 00 00 00 00 00  |................|
00004120  00 40 00 00 00 00 00 00  00 30 00 00 00 00 00 00  |.@.......0......|
00004130  24 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |$...............|
00004140  08 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|

	sh_name		0x00000106		Offset in the section header table
        sh_type		0x00000001		type = PROGBITS
        sh_flags	0x0000000000000003	Read and Write
        sh_addr		0x0000000000004000	Address of the section
        sh_offset     	0x0000000000003000	Offset in the file where the section resides
        sh_size		0x0000000000000024	Size of the section
        sh_link		0x00000000	  	No links to other sections
        sh_info		0x00000000		More information about the section
        sh_addralign	0x0000000000000008	Alignment 
        sh_entsize	0x0000000000000000	Size in bytes of each entry

```
