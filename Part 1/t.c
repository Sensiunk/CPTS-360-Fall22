typedef unsigned int u32;

char *ctable = "0123456789ABCDEF";
int  BASE = 10; 
int HEXBASE = 16;

int main(int argc, char *argv[ ], char *env[ ])
{
    myprintf("char=%c string=%s       dec=%u  hex=%x neg=%d\n", 'A', "this is a test",  100,   100,   -100);
}

void myprintf(char *fmt, ...)
{
    char *cp = fmt;
    int *ip = &fmt + 1;

    while (*cp != '\0')
    {
        if (*cp == '%')
        {
            cp++;
            switch (*cp)
            {
            case 'c':
                putchar(*ip);
                ip++;
                break;

            case 's':
                prints(*ip);
                ip++;
                break;

            case 'u':
                printu(*ip);
                ip++;
                break;

            case 'x':
                printx(*ip);
                ip++;
                break;

            case 'd':
                printd(*ip);
                ip++;
                break;
            
            default:
                break;
            }
            cp++;
        }
        else
        {
            putchar(*cp);
            cp++;
        }
    }
}

int rpu(u32 x)
{  
    char c;
    if (x){
       c = ctable[x % BASE];   
       rpu(x / BASE);
       putchar(c);           
    }
}

int rpx(u32 x)
{  
    char c;
    if (x){
       c = ctable[x % HEXBASE];   
       rpu(x / BASE);
       putchar(c);           
    }
}

int rpd(int x)
{  
    char c;
    if (x){
       c = ctable[x % BASE];   
       rpu(x / BASE);
       putchar(c);           
    }
}

int prints(char *s)
{
    for(int i = 0; s[i] != '\0'; i++)
    {
        putchar(s[i]);
    }
}

int printu(u32 x)
{
   (x==0)? putchar('0') : rpu(x);
   putchar(' ');
}

int printx(u32 x)
{
    putchar('0');
    putchar('x');
    (x==0)? putchar('0') : rpx(x);
    putchar(' ');
}

int printd(int x)
{
    if (x == 0)
    {
        putchar('0');
        return 0;
    }
    if (x < 0)
    {
        putchar('-');
        x = x * -1;
    }
    rpd(x);
    putchar(' ');
}