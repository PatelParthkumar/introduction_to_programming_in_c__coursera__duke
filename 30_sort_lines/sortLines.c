#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

FILE ** init_streams(size_t * nof_streams, int argc, char ** argv) {
  *nof_streams = 0;
  FILE ** streams = NULL;
  if (argc == 1) {
    *nof_streams = 1;
    streams = &stdin;
  }
  else {
    *nof_streams = argc - 1;
    streams = realloc(streams, *nof_streams*sizeof(*streams));
    for (int ifile = 0; ifile < *nof_streams; ++ifile) {
      streams[ifile] = fopen(argv[1+ifile], "r");
      if (streams[ifile] == NULL) {
	fprintf(stderr, "The file could not be opened\n");
	exit(EXIT_FAILURE);
      }
    }  // for: all filenames
  }

  return streams;
}  // get the streams

char ** read_stream(FILE * stream, size_t * nof_lines) {
  // reads the content of a single stream (thus a char ** type)

  char ** buffer = NULL;
  char * line = NULL;
  size_t sz = 0;
  size_t iline = 0;
  while (getline(&line, &sz, stream) >= 0) {
    
    buffer = realloc(buffer, (iline+1)*sizeof(*buffer));  // make buffer larger
    buffer[iline] = line;  // fill latest buffer with content
    line = NULL;  // reset pointer to line to NULL
    ++iline;
  } // while EOF/Ctrl+D is not encountered

  *nof_lines = iline;
  
  free(line);
  
  return buffer;
}  // read single stream

void print_buffer(char ** buffer, int nof_lines) {
  for (int iline = 0; iline < nof_lines; ++iline) {
    printf("%s", buffer[iline]);
  }
}

int main(int argc, char ** argv) {
  
  char ** buffer = NULL;

  size_t nof_streams = 0;
  FILE ** streams = init_streams(&nof_streams, argc, argv);

  size_t nof_lines = 0;
  for (int istream = 0; istream < nof_streams; ++istream) {
    buffer = read_stream(streams[istream], &nof_lines);

    sortData(buffer, nof_lines);

    print_buffer(buffer, nof_lines);

    for (size_t iline = 0; iline < nof_lines; ++iline) {
      free(buffer[iline]);
    }  // for: all lines
    free(buffer);
    free(streams[istream]);
  }  // loop all steams

  free(streams);
  
  return EXIT_SUCCESS;
}
