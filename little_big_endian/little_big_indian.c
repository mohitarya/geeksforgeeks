void show_mem_rep(char *start, int n) 
{
    int i;
        for (i = 0; i < n; i++)
                 printf(" %x.....add = %ld", start[i], (start + i));
                     printf("\n");
                     }
                      
                      /*Main function to call above function for 0x01234567*/
                      int main()
                      {
                         int i = 0x01234567;
                            show_mem_rep((char *)&i, sizeof(i));
                               getchar();
                                  return 0;
                                  }
