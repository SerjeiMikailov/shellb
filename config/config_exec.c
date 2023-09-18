#include <stdlib.h>
#include "config.h"

void editor_select()
{
  if(editor == 2)
  {
    system("vim $HOME/shellbsrc/shellb/config/config.c");
  } else if(editor == 3)
  {
    system("code $HOME/shellbsrc/shellb/config/config.c");  
  } else if(editor == 1)
  {
    system("nano $HOME/shellbsrc/shellb/config/config.c");  
  }

}
