mtype = {read1,read2,begin,mod1,mod2,mod1andmod1,mod1andmod2,mod2andmod1,mod2andmod2};
mtype linearization[5];
byte linearization_index=0;
byte done = 0;
typedef mod_type {
   mtype mod;
   byte i;
   byte j;
};
byte s_index;
mtype read_content[41];
bool s_lock[20]=false;


byte s[20]=0;
proctype modify_container(mod_type mod)
{
  byte i1=mod.i1, j1=mod.j1;
  
  byte _idx_0=i1;
  do
    ::_idx_0<j1->
      do ::
        atomic {
          if 
            :: ! s_lock[_idx_0] -> s_lock[_idx_0] = true; break
            :: s_lock[_idx_0] -> skip
          fi
        }
      od;
      _idx_0=_idx_0+1
    :: break;
  od;
  linearization[linearization_index]=mod.mod;
  linearization_index = linearization_index+1;
  
  byte _idx_2=i1;
  do
    ::_idx_2<j1->
      if
        :: s[_idx_2] == begin -> s[_idx_2] = mod.mod
        :: s[_idx_2] == mod1 && mod.mod == mod1 -> s[_idx_2] = mod1andmod1
        :: s[_idx_2] == mod1 && mod.mod == mod2 -> s[_idx_2] = mod1andmod2
        :: s[_idx_2] == mod2 && mod.mod == mod1 -> s[_idx_2] = mod2andmod1
        :: s[_idx_2] == mod2 && mod.mod == mod2 -> s[_idx_2] = mod2andmod2
      fi;
      _idx_2=_idx_2+1
    :: break;
  od;
  byte _idx_1=j1;
  do
    ::_idx_1<i1->
      s_lock[_idx_1]=false;
      _idx_1=_idx_1+-1
    :: break;
  od;
  done=done+1;
}
proctype read_container(mtype read)
{
  byte i=mod.i, j=mod.j;
  
  byte _idx_3=i2;
  do
    ::_idx_3<j2->
      do ::
        atomic {
          if 
            :: ! s_lock[_idx_3] -> s_lock[_idx_3] = true; break
            :: s_lock[_idx_3] -> skip
          fi
        }
      od;
      _idx_3=_idx_3+1
    :: break;
  od;
  linearization[linearization_index]=read;
  linearization_index = linearization_index+1;
  
  byte _idx_5=i2;
  do
    ::_idx_5<j2->
      :: read == read1 -> read_content[_idx_5] = s[_idx_5]
      :: read == read2 -> read_content[20+_idx_5] = s[_idx_5]
      
      _idx_5=_idx_5+1
    :: break;
  od;
  byte _idx_4=j2;
  do
    ::_idx_4<i2->
      s_lock[_idx_4]=false;
      _idx_4=_idx_4+-1
    :: break;
  od;
  done=done+1;
}

init {
  
  byte i1,i2;
  byte j1,j2;
  atomic {
    run read_container(read1);
    run modify_container(mod1,i1,j1);
    run read_container(read2);
    run modify_container(mod2,i2,j2);
    
  }
}

never {
  do
   :: done == 4 -> break
   :: else -> skip
  od;
  if
   ::linearization[0]==mod1&&linearization[1]==mod2&&linearization[2]==read2&&linearization[3]==read1 -> s[s_index]!=mod1andmod2||read_content[20+s_index]!=mod1andmod2||read_content[s_index]!=mod1andmod2
   ::linearization[0]==mod1&&linearization[1]==mod2&&linearization[2]==read1&&linearization[3]==read2 -> s[s_index]!=mod1andmod2||read_content[s_index]!=mod1andmod2||read_content[20+s_index]!=mod1andmod2
   ::linearization[0]==mod1&&linearization[1]==read1&&linearization[2]==mod2&&linearization[3]==read2 -> s[s_index]!=mod1andmod2||read_content[s_index]!=mod1||read_content[20+s_index]!=mod1andmod2
   ::linearization[0]==read1&&linearization[1]==mod1&&linearization[2]==mod2&&linearization[3]==read2 -> s[s_index]!=mod1andmod2||read_content[s_index]!=begin||read_content[20+s_index]!=mod1andmod2
   ::linearization[0]==mod2&&linearization[1]==mod1&&linearization[2]==read2&&linearization[3]==read1 -> s[s_index]!=mod2andmod1||read_content[20+s_index]!=mod2andmod1||read_content[s_index]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==mod1&&linearization[2]==read1&&linearization[3]==read2 -> s[s_index]!=mod2andmod1||read_content[s_index]!=mod2andmod1||read_content[20+s_index]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read1&&linearization[2]==mod1&&linearization[3]==read2 -> s[s_index]!=mod2andmod1||read_content[s_index]!=mod2||read_content[20+s_index]!=mod2andmod1
   ::linearization[0]==read1&&linearization[1]==mod2&&linearization[2]==mod1&&linearization[3]==read2 -> s[s_index]!=mod2andmod1||read_content[s_index]!=begin||read_content[20+s_index]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read2&&linearization[2]==mod1&&linearization[3]==read1 -> s[s_index]!=mod2andmod1||read_content[20+s_index]!=mod2||read_content[s_index]!=mod2andmod1
   ::linearization[0]==mod2&&linearization[1]==read2&&linearization[2]==read1&&linearization[3]==mod1 -> s[s_index]!=mod2andmod1||read_content[20+s_index]!=mod2||read_content[s_index]!=mod2
   ::linearization[0]==mod2&&linearization[1]==read1&&linearization[2]==read2&&linearization[3]==mod1 -> s[s_index]!=mod2andmod1||read_content[s_index]!=mod2||read_content[20+s_index]!=mod2
   ::linearization[0]==read1&&linearization[1]==mod2&&linearization[2]==read2&&linearization[3]==mod1 -> s[s_index]!=mod2andmod1||read_content[s_index]!=begin||read_content[20+s_index]!=mod2
   ::linearization[0]==mod1&&linearization[1]==read2&&linearization[2]==mod2&&linearization[3]==read1 -> s[s_index]!=mod1andmod2||read_content[20+s_index]!=mod1||read_content[s_index]!=mod1andmod2
   ::linearization[0]==mod1&&linearization[1]==read2&&linearization[2]==read1&&linearization[3]==mod2 -> s[s_index]!=mod1andmod2||read_content[20+s_index]!=mod1||read_content[s_index]!=mod1
   ::linearization[0]==mod1&&linearization[1]==read1&&linearization[2]==read2&&linearization[3]==mod2 -> s[s_index]!=mod1andmod2||read_content[s_index]!=mod1||read_content[20+s_index]!=mod1
   ::linearization[0]==read1&&linearization[1]==mod1&&linearization[2]==read2&&linearization[3]==mod2 -> s[s_index]!=mod1andmod2||read_content[s_index]!=begin||read_content[20+s_index]!=mod1
   ::linearization[0]==read2&&linearization[1]==mod1&&linearization[2]==mod2&&linearization[3]==read1 -> s[s_index]!=mod1andmod2||read_content[20+s_index]!=begin||read_content[s_index]!=mod1andmod2
   ::linearization[0]==read2&&linearization[1]==mod1&&linearization[2]==read1&&linearization[3]==mod2 -> s[s_index]!=mod1andmod2||read_content[20+s_index]!=begin||read_content[s_index]!=mod1
   ::linearization[0]==read2&&linearization[1]==read1&&linearization[2]==mod1&&linearization[3]==mod2 -> s[s_index]!=mod1andmod2||read_content[20+s_index]!=begin||read_content[s_index]!=begin
   ::linearization[0]==read1&&linearization[1]==read2&&linearization[2]==mod1&&linearization[3]==mod2 -> s[s_index]!=mod1andmod2||read_content[s_index]!=begin||read_content[20+s_index]!=begin
   ::linearization[0]==read2&&linearization[1]==mod2&&linearization[2]==mod1&&linearization[3]==read1 -> s[s_index]!=mod2andmod1||read_content[20+s_index]!=begin||read_content[s_index]!=mod2andmod1
   ::linearization[0]==read2&&linearization[1]==mod2&&linearization[2]==read1&&linearization[3]==mod1 -> s[s_index]!=mod2andmod1||read_content[20+s_index]!=begin||read_content[s_index]!=mod2
   ::linearization[0]==read2&&linearization[1]==read1&&linearization[2]==mod2&&linearization[3]==mod1 -> s[s_index]!=mod2andmod1||read_content[20+s_index]!=begin||read_content[s_index]!=begin
   ::linearization[0]==read1&&linearization[1]==read2&&linearization[2]==mod2&&linearization[3]==mod1 -> s[s_index]!=mod2andmod1||read_content[s_index]!=begin||read_content[20+s_index]!=begin
   :: else -> accept: skip
  fi;
}
