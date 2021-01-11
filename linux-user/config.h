#ifndef CONFIG_H
#define CONFIG_H

/* Program code address information see linux-user/elfload.c */
extern target_ulong program_code_offset, program_code_start, program_code_end;

/* Make sure the address being called is within the program */
static inline int is_program_code(target_ulong iaddr) {
	    return (iaddr >= program_code_start && iaddr <= program_code_end);
		
}
#endif
