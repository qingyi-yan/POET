if [ "$#" -ne 1 ] || ! [ -d "$1" ]; then 
  echo "Usage: $0 DIRECTORY" >& 2
  exit 1
fi
path=$1; 
find $path/* -name "*.[fhcC]" > files.txt
find $path/* -name "*.cpp" >> files.txt
echo "" > out; echo "digraph {" > CallGraph.dot; echo "" > FoundLoops.txt; cat files.txt | awk '{print "echo " $0 "; echo " $0 " >> FoundLoops.txt; echo " $0 " >> out; pcg -pcall=\"CallGraph_now.txt\" -pout=\"FoundLoops_now.txt\" -pin=\"" $0 "\" FindLoops.pt; cat FoundLoops_now.txt >> FoundLoops.txt; cat FoundLoops_now.txt >> out; cat CallGraph_now.txt >> CallGraph.dot; cat CallGraph_now.txt >> out"; }' | sh; echo "}" >> CallGraph.dot
