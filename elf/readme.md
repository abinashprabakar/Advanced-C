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
	After the type declaration, there is a Class field defined. This value determines the architecture for the file.	It can be 32-bit (= 01) or 64-bit (= 02) architecture. The magic shows a 02, which is translated by the 
	readelf command as an ELF64 file. In other words, an ElF file using the 64-bit architecture.

<b> Data: </b>
	
