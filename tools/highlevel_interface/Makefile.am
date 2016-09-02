pcg=$(top_srcdir)/src/pcg -t
debug=
comp=diff
target=
save=
th=

files=tables_generated.incl xforms2pt.pt code_files xform_interactions.pt create_tables.pt xform_tools.incl

EXTRA_DIST= $(files)

each:
	make pt
	make opt
	make diff

pt:
	$(pcg) $(debug) -L.. -pinputFile=$(target).xs -poutputFile=$(target).pt xforms2pt.pt

opt:
	$(pcg) $(debug) -pinputFile=$(target).c -poutputFile=$(target)_opt.c $(th) $(target).pt

diff:
	$(comp) $(target).pt $(save).pt
	$(comp) $(target)_opt.c $(save).c
