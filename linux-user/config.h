#ifndef CONFIG_H
#define CONFIG_H

#define BUFF_LEN 128
#define ALLOCATE_BASE 0x400000
#define DUMP_INSN

/* Program code address information see linux-user/elfload.c */
extern target_ulong program_code_offset, program_code_start, program_code_end;

extern unsigned int index_path_scheme;
/* List of branch pairs */
extern GSList* path_scheme;

/* File paths for various files used for ingress/egress from top level */
extern char fname_path_scheme[BUFF_LEN], fname_path_trace[BUFF_LEN];
extern char fname_insn_tmp[BUFF_LEN], fname_dep_tmp[BUFF_LEN];

/* Struct representing branch path pair */
struct pair {
	target_ulong first;
	target_ulong second;
};

/* Comparison function to find where in the list of branches we are */
static inline int g_slist_compare_pair_first(const void* paira, const void* pairb) {
	struct pair* pa = (struct pair*)(paira);
	struct pair* pb = (struct pair*)(pairb);

	if (!pa || !pb) return -1;
	else return pa->first - pb->first;
}


/* Make sure the address being called is within the program */
static inline int is_program_code(target_ulong iaddr) {
	    return (iaddr >= program_code_start && iaddr <= program_code_end);
}

/* Check that address is above minimum base */
static inline int is_valid_addr(target_ulong iaddr) {
	return (iaddr > ALLOCATE_BASE);
}
#endif
