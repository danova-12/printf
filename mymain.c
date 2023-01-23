#include "main.h"

int _printf(const char *format, ...)
{
    int i=0, j=0;
    va_list valist;
    va_start(valist,format);

    char buff[BUFSIZ];
    while(format[i] != '\0')
    {
        if(format[i] == '%')
        {
            i++;
        switch(format[i])
        {
        case 'c':
        {

                buff[j] = (char)(va_arg(valist,int));//data type must be int
                j++;
                break;
        }
        case 's':

        {
                char *f= va_arg(valist,char*);
                int k =0;
                while(f[k] != '\0')
                {
                    buff[j]=f[k];
                    j++;
                    k++;
                }
                break;

        }
        case '%':
            buff[j] = format[i];
            j++;
            break;

        }
        }
        else
        {
            buff[i]=format[j];
            j++;
        }
        i++;
    }
    write(1,buff,j);
    return j;
}

