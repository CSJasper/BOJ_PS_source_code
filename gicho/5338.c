#include <stdio.h>


int main(void)
{
   char* line[5];
   line[0] = "       _.-;;-._";
   line[1] = "'-..-'|   ||   |";
   line[2] = "'-..-'|_.-;;-._|";
   line[3] = "'-..-'|   ||   |";
   line[4] = "'-..-'|_.-''-._|";
   for(int i = 0 ; i < 5 ; i++ )
   {
      puts(line[i]);
   }
}
