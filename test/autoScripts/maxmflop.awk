BEGIN { FS=":"; pcg=""; 
   max[0]=max[1]=max[2]=max[3]= 0; 
   name[0]="gemm"; name[1]="gemv"; name[2]="ger"; name[3]="getrf"; 
   user[0]=user[1]=user[2]=user[3]="";
}
/pcg/||/LoopProcessor/ { pcg=$0; 
        if ($0 ~ "gemm") app=0; 
        else if ($0 ~ "gemv") app=1;
        else if ($0 ~ "ger") app=2;
        else if ($0 ~ "getrf") app=3;
      }
/user/ { user[app] = (user[app] $0 "\n"); }
/MFLOPS|mflop/ { if (max[app] < $NF) {
             max3[app]=max2[app]; command3[app]=command2[app]; 
             max2[app]=max[app]; command2[app]=command[app]; 
             max[app] = $NF; command[app]=pcg;
           }
           else if (max2[app] == 0) {
             max2[app] = $NF; command2[app]=pcg;
           }
           else if (max3[app] == 0) {
             max3[app] = $NF; command3[app]=pcg;
           }
         }
END {  for (app=0; app < 4; ++app)
         { print command[app]; print "MFLOPS: " max[app]; 
           print command2[app]; print "MFLOPS: " max2[app] 
           print command3[app]; print "MFLOPS: " max3[app] 
  	   print user[app];
         }
    }
