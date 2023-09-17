#include <stdlib.h>
#include "config.h"

void editor_select()
{
  if(editor == 2)
  {
    system("vim $HOME/projects/shellb/config/config.c");
  } else if(editor == 3)
  {
    system("code $HOME/projects/shellb/config/config.c");  
  } else if(editor == 1)
  {
    system("nano $HOME/projects/shellb/config/config.c");  
  }

}
