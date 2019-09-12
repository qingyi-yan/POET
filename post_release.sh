#/bin/sh
if [ $# != 1 ]; then echo "Require version number!"; exit; fi;
scp poet-$1.tar.gz blanca.uccs.edu:public_html/poet/releases
command='cd public_html/poet/releases; chmod 644 poet-'$1'.tar.gz; rm poet.tar.gz; ln -s poet-'$1'.tar.gz poet.tar.gz'
ssh blanca.uccs.edu ${command}

