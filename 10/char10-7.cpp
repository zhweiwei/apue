#include <signal.h>
#include <unistd.h>

static void
sig_alrm(int)
{

}

usigned int 
sleep1(usigned int seconds)
{
  if(signal(SIGALRM,sig_alrm) == SIG_ERR){
    return seconds;
  }

  alarm(seconds);
  pause();
  return alarm(0);
}
