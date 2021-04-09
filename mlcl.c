#include <err.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define CLMAX 4000

int main(int argc, char *argv[])
{
  FILE *inp;

  if (argc == 1) {
    inp = stdin;
  } else {
    inp = fopen(argv[1], "r");
    if (inp == NULL) {
      err(2, "when opening %s", argv[1]);
    }
  }

  char cmdline[CLMAX] = "";
  int cmdlinelen = 0;
  char line[CLMAX];
  int linelen;

  while (fgets(line, CLMAX, inp) != NULL) {
    linelen = strlen(line);
    if (line[0] == '#') continue;
    if (cmdlinelen + linelen >= CLMAX) {
      fprintf(stderr, "%s: the constructed command line would be too long\n", argv[0]);
      return 1;
    }
    if (line[linelen-1] == '\n') {
      line[linelen-1] = ' ';
    }
    strcat(cmdline, line);
    cmdlinelen += linelen;
  }

  // printf("%s\n", cmdline);
  if (execl("/bin/bash", "/bin/bash", "-c", cmdline, (char*)NULL) == -1) {
    err(3, "when execing /bin/bash");
  }

  return 0;
}
