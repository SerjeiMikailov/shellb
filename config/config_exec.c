#include <stdlib.h>
#include "config.h"
#include "../src/App.h"

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

void watermark_change()
{
  if(style_watermark_enable == 1)
  {
    shellb();
  } else if(style_watermark_enable == 0)
  {
    int cleitus = 0;
  }
}

void compile()
{
  if(compiler == 1)
  {
    system("(cd $HOME/shellbsrc/shellb && sh savecfg.sh --gcc)");
  } else if(compiler == 2)
  {
    system("(cd $HOME/shellbsrc/shellb && sh savecfg.sh --clang)");
  }
}
