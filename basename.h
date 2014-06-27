#define GNAME_MAX 100
#define GBASENAME_SEP "__"

size_t G_get_numb_of_decimals(const char *);

char *G_double_to_str(double, size_t, size_t);

char *G_get_basename_sep();

char *G_join_basename_strings(const char**, size_t);

char *G_generate_basename(const char*, double, size_t, size_t);
