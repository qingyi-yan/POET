mtype = {read1,read2,begin,mod1,mod2,mod1andmod1,mod1andmod2,mod2andmod1,mod2andmod2};
mtype linearization[5];
byte linearization_index=0;
byte done = 0;

mtype read_content[3];

byte State_index=1;
mtype State_content[5];
byte state=0;
proctype modify_container(mtype mod)
{
  
  byte oldstate=0;
  byte newstate=0;
  
  do
    ::
      State_content[newstate]=State_content[oldstate];
      if
        :: State_content[newstate] == begin -> State_content[newstate] = mod
        :: State_content[newstate] == mod1 && mod == mod1 -> State_content[newstate] = mod1andmod1
        :: State_content[newstate] == mod1 && mod == mod2 -> State_content[newstate] = mod1andmod2
        :: State_content[newstate] == mod2 && mod == mod1 -> State_content[newstate] = mod2andmod1
        :: State_content[newstate] == mod2 && mod == mod2 -> State_content[newstate] = mod2andmod2
      fi;
      atomic {
        if
          :: (state==oldstate) ->
               atomic { state = newstate; linearization[linearization_index]=mod;
               linearization_index = linearization_index+1;
                } break; 
          :: else -> skip
        fi
      }
      
    
  od;
  done=done+1;
}
proctype read_container(mtype read)
{
  
  byte oldstate=0;
  byte newstate=0;
  State_content[newstate]=State_content[oldstate];
  if
    :: read == read1 -> read_content[0] = State_content[newstate]
    :: read == read2 -> read_content[1] = State_content[newstate]
    
  fi;
  done=done+1;
}

init {
  State_content[0]=begin;
  
  
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
   ::linearization[0]==mod1&&linearization[1]==mod2&&linearization[2]==read2&&linearization[3]==read1 -> State_content[state]!=mod1andmod2||read_content[1]!=mod1andmod2||read_content[0]!=mod1andmod2
   ::linearization[0]==mod1&&linearization[1]==mod2&&linearization[2]==read1&&linearization[3]==read2 -> State_content[state]!=mod1andmod2||read_content[0]!=mod1andmod2||read_content[1]!=mod1andmod2
   ::linearization[0]==mod1&&linearization[1]==read1&&linearization[2]==mod2&&linearization[3]==read2 -> State_content[state]!=mod1andmod2||read_content[0]!=mod1||read_content[1]!=mod1andmod2
   ::linearization[0]==read1&&linearization[1]==mod1&&linearization[2]==mod2&&linearization[3]==read2 -> State_content[state]!=mod1andmod2||read_content[0]!=begin||read_content[1]!=mod1andmod2
   ::linearization[0]==mod2&&linearization[1]==mod1&&linearization[2]==read2&&linearization[3]==read1 -> State_content[state]!=mod2andmod1||read_content[1]!=mod2andmod1||read_content[0]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==mod1&&linearization[2]==read1&&linearization[3]==read2 -> State_content[state]!=mod2andmod1||read_content[0]!=mod2andmod1||read_content[1]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read1&&linearization[2]==mod1&&linearization[3]==read2 -> State_content[state]!=mod2andmod1||read_content[0]!=mod2||read_content[1]!=mod2andmod1
   ::linearization[0]==read1&&linearization[1]==mod2&&linearization[2]==mod1&&linearization[3]==read2 -> State_content[state]!=mod2andmod1||read_content[0]!=begin||read_content[1]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read2&&linearization[2]==mod1&&linearization[3]==read1 -> State_content[state]!=mod2andmod1||read_content[1]!=mod2||read_content[0]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read2&&linearization[2]==read1&&linearization[3]==mod1 -> State_content[state]!=mod2andmod1||read_content[1]!=mod2||read_content[0]!=mod2
   ::linearization[0]==mod2&&linearization[1]==read1&&linearization[2]==read2&&linearization[3]==mod1 -> State_content[state]!=mod2andmod1||read_content[0]!=mod2||read_content[1]!=mod2
   ::linearization[0]==read1&&linearization[1]==mod2&&linearization[2]==read2&&linearization[3]==mod1 -> State_content[state]!=mod2andmod1||read_content[0]!=begin||read_content[1]!=mod2
   ::linearization[0]==mod1&&linearization[1]==mod2&&linearization[2]==read2&&linearization[3]==read1 -> State_content[state]!=mod1andmod2||read_content[1]!=mod1andmod2||read_content[0]!=mod1andmod2
   ::linearization[0]==mod1&&linearization[1]==mod2&&linearization[2]==read1&&linearization[3]==read2 -> State_content[state]!=mod1andmod2||read_content[0]!=mod1andmod2||read_content[1]!=mod1andmod2
   ::linearization[0]==mod1&&linearization[1]==read1&&linearization[2]==mod2&&linearization[3]==read2 -> State_content[state]!=mod1andmod2||read_content[0]!=mod1||read_content[1]!=mod1andmod2
   ::linearization[0]==read1&&linearization[1]==mod1&&linearization[2]==mod2&&linearization[3]==read2 -> State_content[state]!=mod1andmod2||read_content[0]!=begin||read_content[1]!=mod1andmod2
   ::linearization[0]==mod2&&linearization[1]==mod1&&linearization[2]==read2&&linearization[3]==read1 -> State_content[state]!=mod2andmod1||read_content[1]!=mod2andmod1||read_content[0]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==mod1&&linearization[2]==read1&&linearization[3]==read2 -> State_content[state]!=mod2andmod1||read_content[0]!=mod2andmod1||read_content[1]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read1&&linearization[2]==mod1&&linearization[3]==read2 -> State_content[state]!=mod2andmod1||read_content[0]!=mod2||read_content[1]!=mod2andmod1
   ::linearization[0]==read1&&linearization[1]==mod2&&linearization[2]==mod1&&linearization[3]==read2 -> State_content[state]!=mod2andmod1||read_content[0]!=begin||read_content[1]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read2&&linearization[2]==mod1&&linearization[3]==read1 -> State_content[state]!=mod2andmod1||read_content[1]!=mod2||read_content[0]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read2&&linearization[2]==read1&&linearization[3]==mod1 -> State_content[state]!=mod2andmod1||read_content[1]!=mod2||read_content[0]!=mod2
   ::linearization[0]==mod2&&linearization[1]==read1&&linearization[2]==read2&&linearization[3]==mod1 -> State_content[state]!=mod2andmod1||read_content[0]!=mod2||read_content[1]!=mod2
   ::linearization[0]==read1&&linearization[1]==mod2&&linearization[2]==read2&&linearization[3]==mod1 -> State_content[state]!=mod2andmod1||read_content[0]!=begin||read_content[1]!=mod2
   ::linearization[0]==mod1&&linearization[1]==mod2&&linearization[2]==read2&&linearization[3]==read1 -> State_content[state]!=mod1andmod2||read_content[1]!=mod1andmod2||read_content[0]!=mod1andmod2
   ::linearization[0]==mod1&&linearization[1]==mod2&&linearization[2]==read1&&linearization[3]==read2 -> State_content[state]!=mod1andmod2||read_content[0]!=mod1andmod2||read_content[1]!=mod1andmod2
   ::linearization[0]==mod1&&linearization[1]==read1&&linearization[2]==mod2&&linearization[3]==read2 -> State_content[state]!=mod1andmod2||read_content[0]!=mod1||read_content[1]!=mod1andmod2
   ::linearization[0]==read1&&linearization[1]==mod1&&linearization[2]==mod2&&linearization[3]==read2 -> State_content[state]!=mod1andmod2||read_content[0]!=begin||read_content[1]!=mod1andmod2
   ::linearization[0]==mod2&&linearization[1]==mod1&&linearization[2]==read2&&linearization[3]==read1 -> State_content[state]!=mod2andmod1||read_content[1]!=mod2andmod1||read_content[0]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==mod1&&linearization[2]==read1&&linearization[3]==read2 -> State_content[state]!=mod2andmod1||read_content[0]!=mod2andmod1||read_content[1]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read1&&linearization[2]==mod1&&linearization[3]==read2 -> State_content[state]!=mod2andmod1||read_content[0]!=mod2||read_content[1]!=mod2andmod1
   ::linearization[0]==read1&&linearization[1]==mod2&&linearization[2]==mod1&&linearization[3]==read2 -> State_content[state]!=mod2andmod1||read_content[0]!=begin||read_content[1]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read2&&linearization[2]==mod1&&linearization[3]==read1 -> State_content[state]!=mod2andmod1||read_content[1]!=mod2||read_content[0]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read2&&linearization[2]==read1&&linearization[3]==mod1 -> State_content[state]!=mod2andmod1||read_content[1]!=mod2||read_content[0]!=mod2
   ::linearization[0]==mod2&&linearization[1]==read1&&linearization[2]==read2&&linearization[3]==mod1 -> State_content[state]!=mod2andmod1||read_content[0]!=mod2||read_content[1]!=mod2
   ::linearization[0]==read1&&linearization[1]==mod2&&linearization[2]==read2&&linearization[3]==mod1 -> State_content[state]!=mod2andmod1||read_content[0]!=begin||read_content[1]!=mod2
   ::linearization[0]==mod1&&linearization[1]==mod2&&linearization[2]==read2&&linearization[3]==read1 -> State_content[state]!=mod1andmod2||read_content[1]!=mod1andmod2||read_content[0]!=mod1andmod2
   ::linearization[0]==mod1&&linearization[1]==mod2&&linearization[2]==read1&&linearization[3]==read2 -> State_content[state]!=mod1andmod2||read_content[0]!=mod1andmod2||read_content[1]!=mod1andmod2
   ::linearization[0]==mod1&&linearization[1]==read1&&linearization[2]==mod2&&linearization[3]==read2 -> State_content[state]!=mod1andmod2||read_content[0]!=mod1||read_content[1]!=mod1andmod2
   ::linearization[0]==read1&&linearization[1]==mod1&&linearization[2]==mod2&&linearization[3]==read2 -> State_content[state]!=mod1andmod2||read_content[0]!=begin||read_content[1]!=mod1andmod2
   ::linearization[0]==mod2&&linearization[1]==mod1&&linearization[2]==read2&&linearization[3]==read1 -> State_content[state]!=mod2andmod1||read_content[1]!=mod2andmod1||read_content[0]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==mod1&&linearization[2]==read1&&linearization[3]==read2 -> State_content[state]!=mod2andmod1||read_content[0]!=mod2andmod1||read_content[1]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read1&&linearization[2]==mod1&&linearization[3]==read2 -> State_content[state]!=mod2andmod1||read_content[0]!=mod2||read_content[1]!=mod2andmod1
   ::linearization[0]==read1&&linearization[1]==mod2&&linearization[2]==mod1&&linearization[3]==read2 -> State_content[state]!=mod2andmod1||read_content[0]!=begin||read_content[1]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read2&&linearization[2]==mod1&&linearization[3]==read1 -> State_content[state]!=mod2andmod1||read_content[1]!=mod2||read_content[0]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read2&&linearization[2]==read1&&linearization[3]==mod1 -> State_content[state]!=mod2andmod1||read_content[1]!=mod2||read_content[0]!=mod2
   ::linearization[0]==mod2&&linearization[1]==read1&&linearization[2]==read2&&linearization[3]==mod1 -> State_content[state]!=mod2andmod1||read_content[0]!=mod2||read_content[1]!=mod2
   ::linearization[0]==read1&&linearization[1]==mod2&&linearization[2]==read2&&linearization[3]==mod1 -> State_content[state]!=mod2andmod1||read_content[0]!=begin||read_content[1]!=mod2
   ::linearization[0]==mod1&&linearization[1]==read2&&linearization[2]==mod2&&linearization[3]==read1 -> State_content[state]!=mod1andmod2||read_content[1]!=mod1||read_content[0]!=mod1andmod2
   ::linearization[0]==mod1&&linearization[1]==read2&&linearization[2]==read1&&linearization[3]==mod2 -> State_content[state]!=mod1andmod2||read_content[1]!=mod1||read_content[0]!=mod1
   ::linearization[0]==mod1&&linearization[1]==read1&&linearization[2]==read2&&linearization[3]==mod2 -> State_content[state]!=mod1andmod2||read_content[0]!=mod1||read_content[1]!=mod1
   ::linearization[0]==read1&&linearization[1]==mod1&&linearization[2]==read2&&linearization[3]==mod2 -> State_content[state]!=mod1andmod2||read_content[0]!=begin||read_content[1]!=mod1
   ::linearization[0]==read2&&linearization[1]==mod1&&linearization[2]==mod2&&linearization[3]==read1 -> State_content[state]!=mod1andmod2||read_content[1]!=begin||read_content[0]!=mod1andmod2
   ::linearization[0]==read2&&linearization[1]==mod1&&linearization[2]==read1&&linearization[3]==mod2 -> State_content[state]!=mod1andmod2||read_content[1]!=begin||read_content[0]!=mod1
   ::linearization[0]==read2&&linearization[1]==read1&&linearization[2]==mod1&&linearization[3]==mod2 -> State_content[state]!=mod1andmod2||read_content[1]!=begin||read_content[0]!=begin
   ::linearization[0]==read1&&linearization[1]==read2&&linearization[2]==mod1&&linearization[3]==mod2 -> State_content[state]!=mod1andmod2||read_content[0]!=begin||read_content[1]!=begin
   ::linearization[0]==read2&&linearization[1]==mod2&&linearization[2]==mod1&&linearization[3]==read1 -> State_content[state]!=mod2andmod1||read_content[1]!=begin||read_content[0]!=mod2andmod1
   ::linearization[0]==read2&&linearization[1]==mod2&&linearization[2]==read1&&linearization[3]==mod1 -> State_content[state]!=mod2andmod1||read_content[1]!=begin||read_content[0]!=mod2
   ::linearization[0]==read2&&linearization[1]==read1&&linearization[2]==mod2&&linearization[3]==mod1 -> State_content[state]!=mod2andmod1||read_content[1]!=begin||read_content[0]!=begin
   ::linearization[0]==read1&&linearization[1]==read2&&linearization[2]==mod2&&linearization[3]==mod1 -> State_content[state]!=mod2andmod1||read_content[0]!=begin||read_content[1]!=begin
   :: else -> accept: skip
  fi;
}
