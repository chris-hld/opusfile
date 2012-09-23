#include "internal.h"

#if defined(OP_ENABLE_ASSERTIONS)
void op_fatal_impl(const char *_str,const char *_file,int _line){
  fprintf(stderr,"Fatal (internal) error in %s, line %i: %s\n",
   _file,_line,_str);
  abort();
}
#endif

/*A version of strncasecmp() that is guaranteed to only ignore the case of
   ASCII characters.*/
int op_strncasecmp(const char *_a,const char *_b,int _n){
  int i;
  for(i=0;i<_n;i++){
    int a;
    int b;
    int d;
    a=_a[i];
    b=_b[i];
    if(a>='a'&&a<='z')a-='a'-'A';
    if(b>='a'&&b<='z')b-='a'-'A';
    d=a-b;
    if(d)return d;
  }
  return 0;
}