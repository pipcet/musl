__asm__(
"\t.text \n"
"\t.globl " START " \n"
"\tdefun " START ", FiiiiiiiE\n"
"\t.labeldef_internal .L0\n"
"\t.dpc .L0\n"
"\tset_local $dpc\n"
"\tjump\n"
);
