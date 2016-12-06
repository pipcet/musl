__asm__(
"\t.text \n"
"\t.globl " START " \n"
"\tdefun " START ", FiiiiiiiE\n"
"\tnextcase\n"
"\t.labeldef_internal .L0\n"
"\t.dpc .L0\n"
"\tset_local $dpc\n"
"\tend\n"
"\ti32.const 0\n"
"\treturn\n"
"\tend\n"
"\tendefun " START "\n"
);
