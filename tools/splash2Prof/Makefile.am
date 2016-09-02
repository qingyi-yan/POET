comp=diff

each:
	${top_builddir}/src/pcg -pin=$(target).c -pout=$(target)_out.c -pvar=$(var) -pbranch=$(branch) -pnest=$(nest) -pfpdiv=$(fpdiv) -pfpara=$(fpara) -punroll_branch=$(unroll_branch) patProf.pt
	$(comp) $(target)_out.c $(target)_prof.c

check:
	make each target=raytrace/husetup var=1 branch=0 nest=0 fpdiv=0 fpara=0 unroll_branch=0
	make each target=water_nsquared/interf var=1 branch=1 nest=0 fpdiv=0 fpara=0 unroll_branch=0
	make each target=ocean_cp/multi var=0 branch=0 nest=1 fpdiv=0 fpara=0 unroll_branch=0
	make each target=barnes/gravsub var=0 branch=0 nest=0 fpdiv=1 fpara=0 unroll_branch=0
	make each target=ocean_ncp/laplacalc var=0 branch=0 nest=0 fpdiv=0 fpara=1 unroll_branch=0
	make each target=fmm/interactions var=0 branch=0 nest=0 fpdiv=0 fpara=0 unroll_branch=1

clean:
	rm -rf raytrace/*_out.c
	rm -rf water_nsquared/*_out.c
	rm -rf ocean_cp/*_out.c
	rm -rf barnes/*_out.c
	rm -rf ocean_ncp/*_out.c
	rm -rf fmm/*_out.c
