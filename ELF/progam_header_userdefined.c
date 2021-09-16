#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef struct{
    uint8_t e_ident[16];
    uint16_t e_type; 
    uint16_t e_machine;
    uint32_t e_version;
    uint32_t e_entry;
    uint32_t e_phoff;
    uint32_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
}ELFHEADER;


typedef struct{
    uint32_t p_type;
}PHEADER;


typedef struct{
    uint32_t sh_name;
}SHEADER;


int main(int argc, char **argv)
{
    FILE *fin = fopen("elf", "rb");
    ELFHEADER elf;

    int x64 = 0;


    if(fin == NULL)
    {
        fprintf(stderr, "ERROR opening the file\n");
        exit(-1);
    }

    fread(&elf,sizeof(elf), 1, fin);

    printf("ELF Header:\n");

    printf("Magic:\t");
    for(int i = 0; i < 16; i++)
    {
        printf("%02x ", elf.e_ident[i]);
    }

    printf("\nClass:\t");
    if(elf.e_ident[4] == 1)
    {
        printf("ELF32\n");
        x64 = 0;
    }
    else
    {
        printf("ELF64\n");
        x64 = 1;
    }

    printf("Data:\t");
    if(elf.e_ident[5] == 1)
    {
        printf("little endian\n");
    }
    else
        printf("big endian\n");
    printf("Version: %x\n", elf.e_ident[6]);

    printf("OS:\t");

    switch(elf.e_ident[7])
    {
        case 0x00:
            printf("SYSTEM V\n");
            break;
        case 0x01:
             printf("HP-UX\n");
             break;
        case 0x02:
             printf("NET BSD\n");
             break;
        case 0x03:
            printf("Linux\n");
            break;
        case 0x04:
             printf("HP-UX\n");
             break;
        case 0x05:
             printf("GNU Hurd\n");
             break;
        case 0x06:
            printf("Solaris\n");
            break;
        case 0x07:
             printf("AIX\n");
             break;
        case 0x08:
             printf("IRIX\n");
             break;
        case 0x09:
            printf("FreeBSD\n");
            break;
        case 0x0A:
             printf("TRU64\n");
             break;
        case 0x0B:
             printf("Novell Modesto\n");
             break;
        case 0x0C:
            printf("OpenBSD\n");
            break;
        case 0x0D:
             printf("OpenVMS\n");
             break;
        case 0x0E:
             printf("NonStop Kernel\n");
             break;
        case 0x0F:
            printf("AROS\n");
            break;
        case 0x10:
             printf("Fenix OS\n");
             break;
        case 0x11:
             printf("CloudABI\n");
             break;
        case 0x12:
            printf("Stratus Technologies OpenVOS\n");
            break;
    }

    printf("ABI Version:\t %x\n", elf.e_ident[8]);
    printf("Type:\t");

    switch(elf.e_type)
    {
        case 0x00:
            printf("NONE\n");
            break;
        case 0x01:
             printf("REL\n");
             break;
        case 0x02:
             printf("EXEC\n");
             break;
        case 0x03:
            printf("DYN\n");
            break;
        case 0x04:
             printf("CORE\n");
             break;
        case 0x05:
             printf("LOOS\n");
             break;
        case 0x06:
            printf("HIOS\n");
            break;
        case 0x07:
             printf("LOPROC\n");
             break;
        case 0x08:
             printf("HIPROC\n");
             break;
    }

//    fseek(fin, 2, SEEK_CUR);
    printf("Machine:\t");


    switch(elf.e_machine)
    {
        case 0x00:
            printf("No specific instruction set\n");
            break;
        case 0x01:
             printf("AT&T WE 32100");
             break;
        case 0x02:
             printf("SPARC\n");
             break;
        case 0x03:
            printf("x86\n");
            break;
        case 0x04:
             printf("Motorola 68000k (M68k)\n");
             break;
        case 0x05:
             printf("Motorola 88000 (M88k)\n");
             break;
        case 0x06:
            printf("Intel MCU\n");
            break;
        case 0x07:
             printf("Intel 80860\n");
             break;
        case 0x08:
             printf("MIPS\n");
             break;
        case 0x09:
            printf("IBM_System/370\n");
            break;
        case 0x0A:
             printf("MIPS RS3000 Little-endian\n");
             break;
        case 0x0B:
             printf("Reserved for future use\n");
             break;
        case 0x0C:
            printf("Reserved for future use\n");
            break;
        case 0x0D:
             printf("Reserved for future use\n");
             break;
        case 0x0E:
            printf("Hewlett-Packard PA-RISC\n");
            break;
        case 0x0F:
             printf("Reserved for future use\n");
             break;
        case 0x13:
             printf("Intel 80960\n");
             break;
        case 0x14:
            printf("PowerPC\n");
            break;
        case 0x15:
             printf("PowerPC(64-bit)\n");
             break;
        case 0x16:
             printf("S390, including S390x\n");
             break;
        case 0x28:
            printf("ARM (up to ARMv7/Aarch32)\n");
            break;
        case 0x2A:
             printf("SuperH\n");
             break;
        case 0x32:
             printf("IA-64\n");
             break;
        case 0x3E:
            printf("amd64\n");
            break;
        case 0x8C:
             printf("TMS320C6000 Family\n");
             break;
        case 0xB7:
             printf("ARM 64-bits (ARMv8/Aarch64)\n");
             break;
        case 0xF3:
            printf("RISC-V\n");
            break;
        case 0xF7:
             printf("Berkeley Packet Filter\n");
             break;
    case 0x101:
        printf("WDC 65C816\n");
        break;


    }

        printf("Version:\t %x\n", elf.e_version);
//    fseek(fin, 4, SEEK_CUR);
    //fread(&elfx64,sizeof(elfx64), 1, fin);
    printf("Entry point address:\t %x\n", elf.e_entry);
    printf("Start of program headers:\t %x\n", elf.e_phoff);
    printf("Start of section headers:\t %x\n", elf.e_shoff);
    printf("Flags:\t %x\n", elf.e_flags);
    printf("Size of this header:\t ");


    if(x64 == 1) // if we have 64-bit architecture
    {
        printf("64 (bytes)\n");
    }
    else
        printf("52 (bytes)\n"); 


    printf("Size of program headers:\t %x\n", elf.e_phentsize);
    printf("Number of program headers:\t %x\n", elf.e_phnum);
    printf("Size of section headers:\t %x\n", elf.e_shentsize);
    printf("Number of section headers:\t %x\n",elf.e_shnum);
    printf("Section header string table index:\t %x\n", elf.e_shstrndx);
}
