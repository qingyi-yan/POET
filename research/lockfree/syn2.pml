mtype = {read1,read2,begin,mod1,mod2,mod1andmod1,mod1andmod2,mod2andmod1,mod2andmod2};
mtype linearization[5];
byte linearization_index=0;
byte done = 0;

mtype read_content[3];
bool state_lock=false;


byte state=0;
proctype modify_container(mtype mod)
{
  
  
  do ::
    atomic {
      if 
        :: ! state_lock -> state_lock = true; break
        :: state_lock -> skip
      fi
    }
  od;
  linearization[linearization_index]=mod;
  linearization_index = linearization_index+1;
  
  if
    :: state == begin -> state = mod
    :: state == mod1 && mod == mod1 -> state = mod1andmod1
    :: state == mod1 && mod == mod2 -> state = mod1andmod2
    :: state == mod2 && mod == mod1 -> state = mod2andmod1
    :: state == mod2 && mod == mod2 -> state = mod2andmod2
  fi;
  state_lock=false;
  done=done+1;
}
proctype read_container(mtype read)
{
  
  
  do ::
    atomic {
      if 
        :: ! state_lock -> state_lock = true; break
        :: state_lock -> skip
      fi
    }
  od;
  linearization[linearization_index]=read;
  linearization_index = linearization_index+1;
  
  if
    :: read == read1 -> read_content[0] = state
    :: read == read2 -> read_content[1] = state
    
  fi;
  state_lock=false;
  done=done+1;
}

init {
  
  
  atomic {
    run read_container(read1);
    run modify_container(mod1);
    run read_container(read2);
    run modify_container(mod2);
    
  }
}

never {
  do
   :: done == 4 -> break
   :: else -> skip
  od;
  if
   ::linearization[0]==mod1&&linearization[1]==mod2&&linearization[2]==read2&&linearization[3]==read1 -> state!=mod1andmod2||read_content[1]!=mod1andmod2||read_content[0]!=mod1andmod2
   ::linearization[0]==mod1&&linearization[1]==mod2&&linearization[2]==read1&&linearization[3]==read2 -> state!=mod1andmod2||read_content[0]!=mod1andmod2||read_content[1]!=mod1andmod2
   ::linearization[0]==mod1&&linearization[1]==read1&&linearization[2]==mod2&&linearization[3]==read2 -> state!=mod1andmod2||read_content[0]!=mod1||read_content[1]!=mod1andmod2
   ::linearization[0]==read1&&linearization[1]==mod1&&linearization[2]==mod2&&linearization[3]==read2 -> state!=mod1andmod2||read_content[0]!=begin||read_content[1]!=mod1andmod2
   ::linearization[0]==mod2&&linearization[1]==mod1&&linearization[2]==read2&&linearization[3]==read1 -> state!=mod2andmod1||read_content[1]!=mod2andmod1||read_content[0]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==mod1&&linearization[2]==read1&&linearization[3]==read2 -> state!=mod2andmod1||read_content[0]!=mod2andmod1||read_content[1]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read1&&linearization[2]==mod1&&linearization[3]==read2 -> state!=mod2andmod1||read_content[0]!=mod2||read_content[1]!=mod2andmod1
   ::linearization[0]==read1&&linearization[1]==mod2&&linearization[2]==mod1&&linearization[3]==read2 -> state!=mod2andmod1||read_content[0]!=begin||read_content[1]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read2&&linearization[2]==mod1&&linearization[3]==read1 -> state!=mod2andmod1||read_content[1]!=mod2||read_content[0]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read2&&linearization[2]==read1&&linearization[3]==mod1 -> state!=mod2andmod1||read_content[1]!=mod2||read_content[0]!=mod2
   ::linearization[0]==mod2&&linearization[1]==read1&&linearization[2]==read2&&linearization[3]==mod1 -> state!=mod2andmod1||read_content[0]!=mod2||read_content[1]!=mod2
   ::linearization[0]==read1&&linearization[1]==mod2&&linearization[2]==read2&&linearization[3]==mod1 -> state!=mod2andmod1||read_content[0]!=begin||read_content[1]!=mod2
   ::linearization[0]==mod1&&linearization[1]==mod2&&linearization[2]==read2&&linearization[3]==read1 -> state!=mod1andmod2||read_content[1]!=mod1andmod2||read_content[0]!=mod1andmod2
   ::linearization[0]==mod1&&linearization[1]==mod2&&linearization[2]==read1&&linearization[3]==read2 -> state!=mod1andmod2||read_content[0]!=mod1andmod2||read_content[1]!=mod1andmod2
   ::linearization[0]==mod1&&linearization[1]==read1&&linearization[2]==mod2&&linearization[3]==read2 -> state!=mod1andmod2||read_content[0]!=mod1||read_content[1]!=mod1andmod2
   ::linearization[0]==read1&&linearization[1]==mod1&&linearization[2]==mod2&&linearization[3]==read2 -> state!=mod1andmod2||read_content[0]!=begin||read_content[1]!=mod1andmod2
   ::linearization[0]==mod2&&linearization[1]==mod1&&linearization[2]==read2&&linearization[3]==read1 -> state!=mod2andmod1||read_content[1]!=mod2andmod1||read_content[0]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==mod1&&linearization[2]==read1&&linearization[3]==read2 -> state!=mod2andmod1||read_content[0]!=mod2andmod1||read_content[1]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read1&&linearization[2]==mod1&&linearization[3]==read2 -> state!=mod2andmod1||read_content[0]!=mod2||read_content[1]!=mod2andmod1
   ::linearization[0]==read1&&linearization[1]==mod2&&linearization[2]==mod1&&linearization[3]==read2 -> state!=mod2andmod1||read_content[0]!=begin||read_content[1]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read2&&linearization[2]==mod1&&linearization[3]==read1 -> state!=mod2andmod1||read_content[1]!=mod2||read_content[0]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read2&&linearization[2]==read1&&linearization[3]==mod1 -> state!=mod2andmod1||read_content[1]!=mod2||read_content[0]!=mod2
   ::linearization[0]==mod2&&linearization[1]==read1&&linearization[2]==read2&&linearization[3]==mod1 -> state!=mod2andmod1||read_content[0]!=mod2||read_content[1]!=mod2
   ::linearization[0]==read1&&linearization[1]==mod2&&linearization[2]==read2&&linearization[3]==mod1 -> state!=mod2andmod1||read_content[0]!=begin||read_content[1]!=mod2
   ::linearization[0]==mod1&&linearization[1]==mod2&&linearization[2]==read2&&linearization[3]==read1 -> state!=mod1andmod2||read_content[1]!=mod1andmod2||read_content[0]!=mod1andmod2
   ::linearization[0]==mod1&&linearization[1]==mod2&&linearization[2]==read1&&linearization[3]==read2 -> state!=mod1andmod2||read_content[0]!=mod1andmod2||read_content[1]!=mod1andmod2
   ::linearization[0]==mod1&&linearization[1]==read1&&linearization[2]==mod2&&linearization[3]==read2 -> state!=mod1andmod2||read_content[0]!=mod1||read_content[1]!=mod1andmod2
   ::linearization[0]==read1&&linearization[1]==mod1&&linearization[2]==mod2&&linearization[3]==read2 -> state!=mod1andmod2||read_content[0]!=begin||read_content[1]!=mod1andmod2
   ::linearization[0]==mod2&&linearization[1]==mod1&&linearization[2]==read2&&linearization[3]==read1 -> state!=mod2andmod1||read_content[1]!=mod2andmod1||read_content[0]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==mod1&&linearization[2]==read1&&linearization[3]==read2 -> state!=mod2andmod1||read_content[0]!=mod2andmod1||read_content[1]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read1&&linearization[2]==mod1&&linearization[3]==read2 -> state!=mod2andmod1||read_content[0]!=mod2||read_content[1]!=mod2andmod1
   ::linearization[0]==read1&&linearization[1]==mod2&&linearization[2]==mod1&&linearization[3]==read2 -> state!=mod2andmod1||read_content[0]!=begin||read_content[1]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read2&&linearization[2]==mod1&&linearization[3]==read1 -> state!=mod2andmod1||read_content[1]!=mod2||read_content[0]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read2&&linearization[2]==read1&&linearization[3]==mod1 -> state!=mod2andmod1||read_content[1]!=mod2||read_content[0]!=mod2
   ::linearization[0]==mod2&&linearization[1]==read1&&linearization[2]==read2&&linearization[3]==mod1 -> state!=mod2andmod1||read_content[0]!=mod2||read_content[1]!=mod2
   ::linearization[0]==read1&&linearization[1]==mod2&&linearization[2]==read2&&linearization[3]==mod1 -> state!=mod2andmod1||read_content[0]!=begin||read_content[1]!=mod2
   ::linearization[0]==mod1&&linearization[1]==mod2&&linearization[2]==read2&&linearization[3]==read1 -> state!=mod1andmod2||read_content[1]!=mod1andmod2||read_content[0]!=mod1andmod2
   ::linearization[0]==mod1&&linearization[1]==mod2&&linearization[2]==read1&&linearization[3]==read2 -> state!=mod1andmod2||read_content[0]!=mod1andmod2||read_content[1]!=mod1andmod2
   ::linearization[0]==mod1&&linearization[1]==read1&&linearization[2]==mod2&&linearization[3]==read2 -> state!=mod1andmod2||read_content[0]!=mod1||read_content[1]!=mod1andmod2
   ::linearization[0]==read1&&linearization[1]==mod1&&linearization[2]==mod2&&linearization[3]==read2 -> state!=mod1andmod2||read_content[0]!=begin||read_content[1]!=mod1andmod2
   ::linearization[0]==mod2&&linearization[1]==mod1&&linearization[2]==read2&&linearization[3]==read1 -> state!=mod2andmod1||read_content[1]!=mod2andmod1||read_content[0]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==mod1&&linearization[2]==read1&&linearization[3]==read2 -> state!=mod2andmod1||read_content[0]!=mod2andmod1||read_content[1]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read1&&linearization[2]==mod1&&linearization[3]==read2 -> state!=mod2andmod1||read_content[0]!=mod2||read_content[1]!=mod2andmod1
   ::linearization[0]==read1&&linearization[1]==mod2&&linearization[2]==mod1&&linearization[3]==read2 -> state!=mod2andmod1||read_content[0]!=begin||read_content[1]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read2&&linearization[2]==mod1&&linearization[3]==read1 -> state!=mod2andmod1||read_content[1]!=mod2||read_content[0]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read2&&linearization[2]==read1&&linearization[3]==mod1 -> state!=mod2andmod1||read_content[1]!=mod2||read_content[0]!=mod2
   ::linearization[0]==mod2&&linearization[1]==read1&&linearization[2]==read2&&linearization[3]==mod1 -> state!=mod2andmod1||read_content[0]!=mod2||read_content[1]!=mod2
   ::linearization[0]==read1&&linearization[1]==mod2&&linearization[2]==read2&&linearization[3]==mod1 -> state!=mod2andmod1||read_content[0]!=begin||read_content[1]!=mod2
   ::linearization[0]==mod1&&linearization[1]==read2&&linearization[2]==mod2&&linearization[3]==read1 -> state!=mod1andmod2||read_content[1]!=mod1||read_content[0]!=mod1andmod2
   ::linearization[0]==mod1&&linearization[1]==read2&&linearization[2]==read1&&linearization[3]==mod2 -> state!=mod1andmod2||read_content[1]!=mod1||read_content[0]!=mod1
   ::linearization[0]==mod1&&linearization[1]==read1&&linearization[2]==read2&&linearization[3]==mod2 -> state!=mod1andmod2||read_content[0]!=mod1||read_content[1]!=mod1
   ::linearization[0]==read1&&linearization[1]==mod1&&linearization[2]==read2&&linearization[3]==mod2 -> state!=mod1andmod2||read_content[0]!=begin||read_content[1]!=mod1
   ::linearization[0]==read2&&linearization[1]==mod1&&linearization[2]==mod2&&linearization[3]==read1 -> state!=mod1andmod2||read_content[1]!=begin||read_content[0]!=mod1andmod2
   ::linearization[0]==read2&&linearization[1]==mod1&&linearization[2]==read1&&linearization[3]==mod2 -> state!=mod1andmod2||read_content[1]!=begin||read_content[0]!=mod1
   ::linearization[0]==read2&&linearization[1]==read1&&linearization[2]==mod1&&linearization[3]==mod2 -> state!=mod1andmod2||read_content[1]!=begin||read_content[0]!=begin
   ::linearization[0]==read1&&linearization[1]==read2&&linearization[2]==mod1&&linearization[3]==mod2 -> state!=mod1andmod2||read_content[0]!=begin||read_content[1]!=begin
   ::linearization[0]==read2&&linearization[1]==mod2&&linearization[2]==mod1&&linearization[3]==read1 -> state!=mod2andmod1||read_content[1]!=begin||read_content[0]!=mod2andmod1
   ::linearization[0]==read2&&linearization[1]==mod2&&linearization[2]==read1&&linearization[3]==mod1 -> state!=mod2andmod1||read_content[1]!=begin||read_content[0]!=mod2
   ::linearization[0]==read2&&linearization[1]==read1&&linearization[2]==mod2&&linearization[3]==mod1 -> state!=mod2andmod1||read_content[1]!=begin||read_content[0]!=begin
   ::linearization[0]==read1&&linearization[1]==read2&&linearization[2]==mod2&&linearization[3]==mod1 -> state!=mod2andmod1||read_content[0]!=begin||read_content[1]!=begin
   :: else -> accept: skip
  fi;
}
