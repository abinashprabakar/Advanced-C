<center> Executable and Linkable Format (ELF) </center>


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

<h1> ELF Header </h1>

As can be seen in the above image, the ELF header starts with some magic. This ELF header magic provides information
about the file. The first hexadecimal parts define that this is an ELF file (45 = E, 4c = L, 46 = F), prefixed with 
the 7f value.
The ELF Header is mandatory. It ensures that data is correctly interpreted during linking or execution. 

<b> Class : </b>

	After the type declaration, there is a Class field defined. This value determines the architecture for
	the file.It can be 32-bit (= 01) or 64-bit (= 02) architecture. The magic shows a 02, which is translated
	by the readelf command as an ELF64 file. In other words, an ElF file using the 64-bit architecture.

<b> Data: </b>
	
	Next part is the data field. It knows two options: 01 for LSB also known as little-endian. Then there is the
	value 02, for MSB known as big-endian. This particular value helps to interpet the remaining objects
	correctly within the file. This is important, as different types of processors deal differently with the 
	incoming instructions and data structures. In this case, LSB is used, which is common for AMD64 processors.

<b> Version: </b>

	Next in line is another “01” in the magic, which is the version number.
	Currently, there is only 1 version type:currently, which is the value “01”.

<b> OS/ABI: </b>

	Each operating system has a big overlap in common functions. In addition, each of them has specific ones,
	or at least minor differences between them. The definition of the right set is done with an
	Application Binary Interface (ABI). This way the operating system and applications both know what to expect
	and functions are correctly forwarded. These two fields describe what ABI is used and the related version.
	In this case, the value is 00, which means no specific extension is used. The output shows this as System V.

<b> ABI Version: </b>

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
