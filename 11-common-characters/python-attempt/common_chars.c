#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
   if (argc != 2) {
      fprintf(stderr, "Specify simply the input file\n");
      exit(1);
   }

   FILE *in = fopen(argv[1], "r");
   if (!in) {
      fprintf(stderr, "File read error\n");
      exit(1);
   }

   int nlines = 0;
   //fscanf(in, "%d", &nlines);
   char buf[100000]; // assume that there won't be any lines bigger than this
   char output[100000]; // contains string of all characters that were seen
   int debug = 0;
   while (fgets(buf, 99999, in)) {
      output[0] = '\0'; // clear output
      printf("Size of output should be 0: %lu\n", strlen(output));
      for(int i = 0; i < strlen(buf); i++) {
         if (strchr(output, buf[i]) != NULL) { //if character in question already exists
            putc(buf[i], stdout); // printing to stdout
         } else { // else put in output checker
            output[strlen(output)] = buf[i];
         }
      }
      //putc('\n', stdout);
      printf("\n==The output string is: %s==\n", output);
      if (debug++ > 2) return 0;
   }
   fclose(in);
   return 0;
}
