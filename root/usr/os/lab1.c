// os0.c -- simple timer isr test

#include <u.h>

int current;

out(port, val)  { asm(LL,8); asm(LBL,16); asm(BOUT); }
ivec(void *isr) { asm(LL,8); asm(IVEC); }
stmr(int val)   { asm(LL,8); asm(TIME); }
halt(val)       { asm(LL,8); asm(HALT); }

alltraps()
{
  asm(PSHA);
  asm(PSHB);

  current++;

  asm(POPB);
  asm(POPA);
  asm(RTI);
}

print_ticks(){
  out (1, '1');
  out (1, '0');
  out (1, '0');
  out (1, ' ');
  out (1, 't');
  out (1, 'i');
  out (1, 'c');
  out (1, 'k');
  out (1, 's');
  out (1, '\n');
}

main()
{
  current = 0;

  stmr(1000);
  ivec(alltraps);
  
  asm(STI);
  
  while (1) {
    if (current == 100){
		print_ticks();
		current = 0;
	}
  }

  halt(0);
}
