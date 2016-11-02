#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int compare(const void * a, const void * b) {
   //int * a1 = (int *) a;
   //int * b1 = (int *) b;
   //printf("a is %d and b is %d\n", *a1, *b1);
   //return (*a1 < *b1 ? -1 : (*a1 > *b1 ? 1 : 0));
   printf ( "a is %d and b is %d\n", *(int*)a, *(int*)b  );
   return ( *(int*)a - *(int*)b  );
}

/*
void sort_special(char *array) {
   char temp[strlen(array) + 1];
   strncpy(temp, "", strlen(array) + 1);
   for (int i = 0; i < strlen(array); i++) {
      if (isdigit(array[i]) && ) temp[strlen(temp)] = array[i];
   }
   for (int i = 0; i < strlen(array); i++) {
      if (isupper(array[i])) temp[strlen(temp)] = array[i];
   }
   for (int i = 0; i < strlen(array); i++) {
      if (islower(array[i])) temp[strlen(temp)] = array[i];
   }
}
*/

void select_sort (char * array) {
   for (int i = 0; i < strlen(array); i++) {
      int minindex = i;
      for (int j = i + 1; j < strlen(array); j++) {
         if (array[minindex] > array[j]) minindex = j;
      }
      char temp = array[i];
      array[i] = array[minindex];
      array[minindex] = temp;
   }
}

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
   fscanf(in, "%d", &nlines);
   char buf[100000]; // assume that there won't be any lines bigger than this
   char check[100000]; // contains string of all characters that were seen
   char output[100000]; // contains string to be printed at end
   int debug = 0;
   while (fgets(buf, 99999, in)) {
      output[0] = '\0'; // clear output
      check[0] = '\0'; // clear check
      if (buf[0] == '\n') continue;
      //printf("Size of output should be 0: %lu\n", strlen(output));
      //
      //

      select_sort(buf);
      char temp = '\0';
      int printed = 1;
      for(int i = 0; i < strlen(buf); i++) {

         if (!isalnum(buf[i])) continue;

         
         

            /*
         if (!strchr(output, buf[i]) && strchr(check, buf[i])) { //if character in question already exists print if not yet printed
            int loc = strlen(output);
            output[loc] = buf[i];
            output[loc + 1] = '\0';
         } else if (!strchr(check, buf[i])) { // else put in output checker
            int loc = strlen(check);
            check[loc] = buf[i];
            check[loc + 1] = '\0';
         }
         */
      }
      //select_sort(output);
      //qsort(output, strlen(output), sizeof(char), compare);
      printf("\n");
      //printf("\n\n==The output string is: %s==\n\n", output);
      //if (debug++ > 2) return 0;
   }
   fclose(in);
   return 0;
}
