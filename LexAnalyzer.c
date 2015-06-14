#include <stdio.h>
#include <conio.h>

char *stringDelimiter(char *str, char *comp);
void main()
{
        char ch;
        FILE *fp;
        fp = fopen("input.txt","r"); // read mode

       char charactersRead[1000];
       char *str, delimit[2];
        delimit[0] = ' ';
        delimit[1] = '\0';;
       int i;
       while( ( ch = fgetc(fp) ) != EOF )
       {
            if(!iscntrl(ch))
            {
                charactersRead[i] = ch;
				i++;
            }
			else
            {
                charactersRead[i] = ' ';
                i++;
            }

        }
        charactersRead[i] = '\0';

        str= stringDelimiter (charactersRead,delimit);
        printf("Lexical Item\t\tLexical Value\n");


        while (str != NULL)
        {
            char *ch = str;
            char *i;
            if(stringCompare(str,"DEFINITIONS",11)==0 || stringCompare(str,"AUTOMATIC",9)==0 || stringCompare(str,"TAGS",4)==0 || stringCompare(str,"BEGIN",5)==0 || stringCompare(str,"SEQUENCE",8)==0 || stringCompare(str,"VisibleString",13)==0 || stringCompare(str,"SIZE",4)==0 || stringCompare(str,"NumericString",13)==0 || stringCompare(str,"OPTIONAL",8)==0 || stringCompare(str,"FROM",4)==0 || stringCompare(str,"INTEGER",7)==0 || stringCompare(str,"BOOLEAN",7)==0 || stringCompare(str,"END",3)==0)
            {
                   printf("\nReserved word\t\t%s",str);
                   str = stringDelimiter (NULL, " ");
                   continue;
            }

            int j;
            for(j=0;j<lengthOf(str);j++)
            {
                    char *i;
                    i=ch;
                    //Type reference
                     if(i[0]>=65 && i[0]<=90)
                     {

                        if((i[j]>=97 && i[j]<=122)||(i[j]>=48 && i[j]<=57)||(i[j]>=65 && i[j]<=90)||(i[j]==45))
                        {
                           if((i[j]==45 && i[j+1]==45)|| (i[lengthOf(str)-1]==45))
                            {
                                break;

                            }
                            else if(j==lengthOf(str)-1)
                            {
                                printf("\nType reference\t\t%s",str);
                            }
                        }
                        else
                        {
                            break;
                        }

                     }
                     //Identifier
                     else if(i[0]>=97 && i[0]<=122)
                     {
                        if((i[j]>=97 && i[j]<=122)||(i[j]>=48 && i[j]<=57)||(i[j]>=65 && i[j]<=90)||(i[j]==45))
                        {
                           if((i[j]==45 && i[j+1]==45)|| (i[lengthOf(str)-1]==45))
                            {
                                break;

                            }
                            else if(j==lengthOf(str)-1)
                            {
                                printf("\nIdentifier\t\t%s",str);
                            }
                        }
                        else
                        {
                            break;
                        }
                     }
                      //Number
                    else if(i[0]>=48 && i[0]<=57)
                    {
                         if(i[j]>=48 && i[j]<=57)
                         {
                             if(j==lengthOf(str)-1)
                                printf("\nNumber\t\t\t%s",str);
                         }

                    }
                     // Assignment lexical item

                    else if(i[0]==58 && i[1]==58 && i[2]==61)
                    {
                        if(j==2 && (lengthOf(str))==3)
                        {
                            printf("\nAssignment operator",str);
                            break;
                        }

                    }
                    // Range separator
                    else if(i[0]==46 && i[1]==46)
                    {
                            printf("\nRange separator");
                            break;
                    }
                    else if(i[0]==123)
                    {
                            printf("\nLCURLY");
                            break;
                    }
                    else if(i[0]==125)
                    {
                            printf("\nRCURLY");
                            break;
                    }
                    else if(i[0]==44)
                    {
                            printf("\nComma");
                            break;
                    }
                    else if(i[0]==40)
                    {
                            printf("\nLParen");
                            break;
                    }
                    else if(i[0]==41)
                    {
                            printf("\nRParen");
                            break;
                    }
                    else if(i[0]==124)
                    {
                            printf("\nBar");
                            break;
                    }
                    else if(i[0]==34)
                    {
                            printf("\nQuote");
                            break;
                    }
                    else
                    {
                        printf("\nUnrecognized input");
                    }
            }
            str = stringDelimiter (NULL, delimit);

        }
        fclose(fp);

        getch();

    }

int lengthOf(char *t)
{
    int count=0;
    while(*t!='\0')
    {
        count++;
        t++;
    }
    return(count);

}
int stringCompare(const char *s1, const char *s2)
{
    while((*s1 && *s2) && (*s1 == *s2))
        s1++,s2++;
    return *s1 - *s2;
}

char *stringDelimiter(char *str, char *comp)
{
	static int pos;
	static char *s;
	int i =0, start = pos;

	// Copying the string for further calls of stringDelimiter
	if(str!=NULL)
		s = str;

	i = 0;
	int j = 0;
	//While not end of string
	while(s[pos] != '\0')
	{
		j = 0;
		//Comparing of one of the delimiter matches the character in the string
		while(comp[j] != '\0')
		{
			//Pos point to the next location in the string that we have to read
			if(s[pos] == comp[j])
			{
				//Replace the delimter by \0 to break the string
				s[pos] = '\0';
				pos = pos+1;
				//Checking for the case where there is no relevant string before the delimeter.
				//start specifies the location from where we have to start reading the next character
				if(s[start] != '\0')
					return (&s[start]);
				else
				{
					// Move to the next string after the delimiter
					start = pos;
					// Decrementing as it will be incremented at the end of the while loop
					pos--;
					break;
				}
			}
			j++;
		}
		pos++;
	}//End of Outer while
	s[pos] = '\0';
	if(s[start] == '\0')
		return NULL;
	else
		return &s[start];
}

          
        
