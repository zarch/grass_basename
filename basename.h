#define GNAME_MAX 100
#define GBASENAME_SEP "__"

size_t G_get_num_decimals(const char *);

char *G_double_to_basename_format(double, size_t, size_t);

char *G_get_basename_separator();

char *G_join_basename_strings(const char**, size_t);

char *G_generate_basename(const char*, double, size_t, size_t);
