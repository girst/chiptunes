#define c3(x) (0xff & (x>>24))
#define c2(x) (0xff & (x>>16))
#define c1(x) (0xff & (x>> 8))
#define c0(x) (0xff & (x    ))
#define LSL(x)    carry = x>>7; x <<= 1;
#define LSR(x)    carry = x&1; x >>= 1;
#define SWAP(x)   x = ((x & 0x0F) << 4 | (x & 0xF0) >> 4);
#define AND(x,y)  x &= y;
#define ANDI(x,n) x &= n;
#define OR(x,y)   x |= y;
#define ORI(x,n)  x |= n;
#define EOR(x,y)  x ^= y;
#define ADD(x,y)  carry = (x+y)>>8; x += y;
#define ADC(x,y,c)x += y; x+=c; //TODO: carry
#define SUB(x,y)  x -= y; //TODO: carry
#define SUBI(x,n) x -= (u8)n; //TODO: carry
#define INC(x)    x++; //WARN: does not set carry
#define MOV(x,y)  x = y;
#define LDI(x,n)  x = n;
#define SBRC(x,b) if (x & b) //skip if cleared => do if set
#define CLR(x)    x = 0;
#define RET       return;
#define RCALL	  //pseudo
int zero = 0; //status register zero bit
#define TST(x)    if(x==0)zero=1;else zero=0; //WARN: not a complete TST mockup
#define BREQ(l)   if(zero) goto l;
int carry = 0; //status register carry bit //WARN: not respected by all mocked instructions
int asmtmp = 0;
#define ROL(x)	asmtmp = x>>7; x <<= 1; x |= carry; carry = asmtmp;
#define ROR(x)	asmtmp = x&0x1; x >>= 1; x |= carry<<7; carry = asmtmp;
#define NEG(x)	x *= -1;
