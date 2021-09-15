# Executable and Linkable Format (ELF)

<b> elf_or_not.c </b> - <a href = "https://github.com/abinashprabakar/Advanced-C/blob/main/ELF/elf_or_not.c">code</a>
	
		This program is to check whether the file is ELF or not

<h1> What is ELF ? </h1>

Executable and Linkable Format, is a common standard for executable files, object code, shared libraries, and core
dumps.

There are three main types of object files.
	
	1. A relocatable file holds code and data suitable for linking with other object files to create an 
	   executable or a shared object file.

	2. An executable file holds a program suitable for execution.

	3. A shared object file holds code and data suitable for linking in two contexts.

The reason behind that decision was the design of ELF – flexibility, extensibility, and cross-platform support for
different endian formats and address sizes. ELF’s design is not limited to a specific processor, instruction set, or
hardware architecture.

<img src="https://www.conradk.com/content/images/2018/06/man-elf-1.png">

<h1> Structure of an ELF file </h1>

ELF consists of two sections,

	1. ELF Header  -> it is 32 byte long and identifies the format of a file.
	2. File Data   -> it consists of three parts i.e Program Headers, Section Headers, Data

<img src = "https://assets.linux-audit.com/wp-content/uploads/2015/08/elf-header-linux-binary.png">

<h1><b> ELF Header </h1></b>

As can be seen in the above image, the ELF header starts with some magic. This ELF header magic provides information
about the file. The first hexadecimal parts define that this is an ELF file (45 = E, 4c = L, 46 = F), prefixed with 
the 7f value.
The ELF Header is mandatory. It ensures that data is correctly interpreted during linking or execution. 

<b> Class : </b>

	After the type declaration, there is a Class field defined. This value determines the architecture for
	the file.It can be 32-bit (= 01) or 64-bit (= 02) architecture. The magic shows a 02, which is translated
	by the readelf command as an ELF64 file. In other words, an ElF file using the 64-bit architecture.

<b> Data : </b>
	
	Next part is the data field. It knows two options: 01 for LSB also known as little-endian. Then there is the
	value 02, for MSB known as big-endian. This particular value helps to interpet the remaining objects
	correctly within the file. This is important, as different types of processors deal differently with the 
	incoming instructions and data structures. In this case, LSB is used, which is common for AMD64 processors.

<b> Version : </b>

	Next in line is another “01” in the magic, which is the version number.
	Currently, there is only 1 version type:currently, which is the value “01”.

<b> OS/ABI : </b>

	Each operating system has a big overlap in common functions. In addition, each of them has specific ones,
	or at least minor differences between them. The definition of the right set is done with an
	Application Binary Interface (ABI). This way the operating system and applications both know what to expect
	and functions are correctly forwarded. These two fields describe what ABI is used and the related version.
	In this case, the value is 00, which means no specific extension is used. The output shows this as System V.

<b> ABI Version : </b>

	ABI is short for Application Binary Interface and specifies a low-level interface between the operating
	system and a piece of executable code. When needed, a version for the ABI can be specified.

<b> Ehdr (ELF Header) </b>

The ELF header is described by the type ELf32_hdr or ELf64_hdr:

<img src = "https://hydrasky.com/wp-content/uploads/2018/10/Capture03102.png"> 

The fields have the following meanings:

<i> e_ident </i>

	This array of bytes specifies how to interpret the file, independent of the processor or the file's remaining
	contents.  Within this array everything is named by macros, which start with the prefix EI_ and may contain
	values which start with the prefix ELF.  The following macros are defined:

	EI_MAG0
		The first byte of the magic number. It must be filled with ELFMAG0. (0: 0x7f)

	EI_MAG1
		The second byte of the magic number. It must be filled with ELFMAG1. (1: 'E')
	
	EI_MAG2
		The third byte of the magic number. It must be filled with ELFMAG2. (2: 'L')

	EI_MAG3
		The fourth byte of the magic number. It must be filled with ELFMAG3. (3: 'F')

<i> e_type </i>  -  This member of the structure identifies the object file type:
	
	ET_NONE  -  An unknown type
	ET_REL   -  A relocatable file
	ET_EXEC  -  A executable file
	ET_DYN   -  A shared object
	ET_CORE  -  A core file

<i> e_machine </i>  - This member specifies the required architecture for an individual file. For example,

	EM_NONE  - An unknown machine
	EM_M32   - AT&T WE 32100
	EM_386   - Intel 80386
	EM_IA_64 - Intel Pentium

<i> e_version </i>  -  This member identifies the file version

	EV_NONE 0    - Invalid version
	EV_CURRENT  - Current version

<i> e_entry </i>

	This member gives the virtual address to which the system first transfers control, thus starting the process.
	If the file has no associated entry point, this member holds zero.

<i> e_phoff </i>
	This member holds the program header table's file offset in bytes.  If the file has no program header table,
	this member holds zero.

<i> e_shoff </i>

	This member holds the section header table's file offset in bytes.  If the file has no section header table,
	this member holds zero.

<i> e_flags </i>

	This member holds processor-specific flags associated with the file.  Flag names take the form 
	EF_`machine_flag'. Currently, no flags have been defined.

<i> e_ehsize </i>

	This member holds the ELF header's size in bytes.

<i> e_phemtsize </i>

	This member holds the size in bytes of one entry in the file's program header table; all entries are the same
	size.

<i> e_phnum </i>

	This member holds the number of entries in the program header table.  Thus the product of e_phentsize and
	e_phnum gives the table's size in bytes.  If a file has no program header, e_phnum holds the value zero.


<h1><b> File Data </b></h1>

Besides the ELF Header, ELF files consists of three parts,

    1. Program Headers or Segments
    2. Section Headers or Sections
    3. Data

<b> Program Headers </b>

	An ELF file consists of zero or more segments, and describes how to create a process/memory image for runtime
	execution. When the kernel sees these segments, it uses them to map them into virtual address space, using the
	mmap(2) system call. In other words, it converts predefined instructions into a memory image. If your ELF file
	is a normal binary, it requires these program headers. Otherwise, it simply won’t run. It uses these headers,
	with the underlying data structure, to form a process. This process is similar for shared libraries.

<img src = "https://mk0resourcesinf5fwsf.kinstacdn.com/wp-content/uploads/040216_2144_CompleteTou6.png">
<img src = "https://github.com/lakshminarayana8522/Advanced-C/raw/main/Gcc/figures/elfph.PNG">

The ELF program header is described by the Elf32_Phdr or Elf64_Phdr depending on the architecture:

	typedef struct {
	       unit32_t ptype;
	       Elf32_Off p_offset;
	       Elf32_Addr p_vaddr;
	       Elf32_Addr p_paddr;
               uint32_t   p_filesz;
               uint32_t   p_memsz;
               uint32_t   p_flags;
               uint32_t   p_align;
           } Elf32_Phdr;

	typedef struct {
               uint32_t   p_type;
               uint32_t   p_flags;
               Elf64_Off  p_offset;
               Elf64_Addr p_vaddr;
               Elf64_Addr p_paddr;
               uint64_t   p_filesz;
               uint64_t   p_memsz;
               uint64_t   p_align;
           } Elf64_Phdr;

   <b> GNU_EH_FRAME </b>

	This is a sorted queue used by the GNU C compiler (gcc). It stores exception handlers. So when something
	goes wrong, it can use this area to deal correctly with it.

   <b> GNU_STACK </b>

	This header is used to store stack information. The stack is a buffer, or scratch place, where items are
	stored, like local variables. This will occur with LIFO (Last In, First Out), similar to putting boxes on
	top of each other. When a process function is started a block is reserved. When the function is finished,
	it will be marked as free again.

   <i> Commands to see program headers </i>
   <ul>
   <li> dumpelf </li>
   <li> elfls -S /bin/ps </li>
   <li> eu-readelf -program-headers /bin/ps </li></ul>

<b> Section headers </b>

	Sections can be found in an ELF binary after the GNU C compiler transformed C code into assembly, followed
	by the GNU assembler, which creates objects of it.

	A segment can have 0 or more sections. For executable files there are four main sections: .text, .data,
	.rodata, and .bss. Each of these sections is loaded with different access rights, which can be seen with
	readelf -S.

<img src = "https://mk0resourcesinf5fwsf.kinstacdn.com/wp-content/uploads/040216_2211_CompleteTou3.png">

	typedef struct {
               uint32_t   sh_name;
               uint32_t   sh_type;
               uint32_t   sh_flags;
               Elf32_Addr sh_addr;
               Elf32_Off  sh_offset;
               uint32_t   sh_size;
               uint32_t   sh_link;
               uint32_t   sh_info;
               uint32_t   sh_addralign;
               uint32_t   sh_entsize;
           } Elf32_Shdr;

	typedef struct {
               uint32_t   sh_name;
               uint32_t   sh_type;
               uint64_t   sh_flags;
               Elf64_Addr sh_addr;
               Elf64_Off  sh_offset;
               uint64_t   sh_size;
               uint32_t   sh_link;
               uint32_t   sh_info;
               uint64_t   sh_addralign;
               uint64_t   sh_entsize;
           } Elf64_Shdr;

Various sections hold program and control information:

<b><i> .text </i></b>

	Contains executable code. It will be packed into a segment with read and execute access rights. It is only
	loaded once, as the contents will not change. This can be seen with the objdump utility.

<b><i> .data </i></b>

	Initialized data with read/write access rights that contribute to the program's memory image. This section is
	of type SHT_PROGBITS. The attribute types are SHF_ALLOC and SHF_WRITE.

<b><i> .rodata </i></b>

	Initialized data, with read access rights (only =A)

<b><i> .bss </i></b>

	Uninitialized data, with read/write access rights (=WA) that contributes to the program's memory image. 
	By definition, the system initializes the data with zeros when the program begins to run. This section is of
	type SHT_NOBITS. The attribute types are SHF_ALLOC and SHF_WRITE.

<b><i> .comment </b></i>

	This section holds version control information. This section is of type SHT_PROGBITS. No attribute types are
	used.

<b><i> .ctors </b></i>

	This section holds initialized pointers to the C++ constructor functions. This section is of type SHT_PROGBITS.
	The attribute types are SHF_ALLOC and SHF_WRITE.

<b><i> .data1 </b></i>

	This section holds initialized data that contribute to the program's memory image. This section is of type
	SHT_PROGBITS. The attribute types are SHF_ALLOC and SHF_WRITE.

<b><i> .debug </b></i>

	This section holds information for symbolic debugging. The contents are unspecified. This section is of type
	SHT_PROGBITS.  No attribute types are used.

<b><i> .dtors </b></i>

	This section holds initialized pointers to the C++ destructor functions. This section is of type SHT_PROGBITS.
	The attribute types are SHF_ALLOC and SHF_WRITE.

<b><i> .dynamic </b></i>

	This section holds dynamic linking information. The section's attributes will include the SHF_ALLOC bit.
	Whether the SHF_WRITE bit is set is processor-specific. This section is of type SHT_DYNAMIC.

<b><i> .dynstr </b></i>
	
	This section holds strings needed for dynamic linking, most commonly the strings that represent the names
	associated with symbol table entries.  This section is of type SHT_STRTAB.  The attribute type used is
	SHF_ALLOC.

<b><i> .gnu.version </b></i>

	This section holds the version symbol table, an array of ElfN_Half elements. This section is of type
	SHT_GNU_versym.  The attribute type used is SHF_ALLOC.

<b><i> .got </b></i>

	This section holds the global offset table. This section is of type SHT_PROGBITS. The attributes are
	processor-specific.

<b><i> .hash </b></i>

	This section holds a symbol hash table. This section is of type SHT_HASH. The attribute used is SHF_ALLOC.

<b><i> .init </b></i>

	This section holds executable instructions that contribute to the process initialization code.  When a program
	starts to run the system arranges to execute the code in this section before calling the main program entry
	point. This section is of type SHT_PROGBITS.  The attributes used are SHF_ALLOC and SHF_EXECINSTR.

<b><i> .interp </b></i>

	This section holds the pathname of a program interpreter. If the file has a loadable segment that includes the
	section, the section's attributes will include the SHF_ALLOC bit. Otherwise, that bit will be off. This
	section is of type SHT_PROGBITS.

<b><i> .symtab </b></i>

	This section holds a symbol table.  If the file has a loadable segment that includes the symbol table, the
	section's attributes will include the SHF_ALLOC bit. Otherwise, the bit will be off. This section is of type
	SHT_SYMTAB.

<i> Commands to see section and headers </i>

   <ul>
   <li> dumpelf </li>
   <li> elfls -p /bin/ps </li>   
   <li> eu-readelf -section-headers /bin/ps </li>
   <li> readelf -S /bin/ps </li>
   <li> objdump -h /bin/ps </li></ul>   


<h1> How to check whether the file is elf or not </h1>

To compile :
	
	gcc -g -o checkelf checkelf.c
	./checkelf filename

<img src = "E:\Notes\XS notes\github photos\elf.png">
