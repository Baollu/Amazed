/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#ifndef MY_PROTOTYPE
    #define MY_PROTOTYPE
    #include <stdbool.h>



////  info robot  ///
enum room_type_e {
    DEFAULT = 0,
    START,
    END
};

typedef struct room_s {
    char *room;
    char *posx;
    char *posy;
    int nb_robot;
    enum room_type_e room_type;
    struct room_s *next;
} room_t;

void print_room(room_t *room);
int print_all_room(room_t *room);
room_t *init_room(void);
//////////////////////



///  link  ///
typedef struct link {
    char *name;
    int dist;
    enum room_type_e type;
    struct link **next;
} link_t;

link_t *create_link(char *name);
int get_nbr_connection(link_t *link);
void connect_links(link_t *link1, link_t *link2);
void print_link(link_t *link);
void print_link_connection(link_t *link);
//////////////



///  memory  ///
typedef struct memory_s {
    link_t *link;
    struct memory_s *next;
} memory_t;

memory_t *init_memory(void);
void add_to_memory(memory_t **memory, link_t *link);
bool is_in_memory(memory_t **memory, link_t *link);
void free_memory(memory_t *memory);
////////////////



////  info tunnels  ///
typedef struct paths_s {
    char *path1;
    char *path2;
    struct paths_s *next;
} paths_t;
///////////////////////



////  robustness  ////
int robustness(int ac, room_t **info_robot, paths_t **tunnels);
int check_data(room_t **room_info);
int check_name_room(room_t *room);
int check_coordonne(room_t *room);
int check_comment(char **array);
int args_check(int ac);
int find_robot_number(char **av, room_t **robot_info);
int is_room(char **words, room_t **robot_info, char *ref);
paths_t *init_tunnels(void);
int print_all_tunnels(paths_t *tunnels);
room_t *init_robot_info(void);
int find_start_end(char **str, room_t **robot_info);
int add_tunnels(char **str, paths_t **tunnels);
void push_to_list(char **words, room_t **robot_info, char *ref);
void push_tunnels(char **words, paths_t **tunnels);
//////////////////////

/// find path ///
void print_shortest_path(room_t *room, paths_t *tunnels);
void print_path(link_t **links, int nbr_robot);
void print_graph(link_t *base_link);
link_t *get_start(link_t **links);
link_t *get_closest(link_t *link);
/////////////////

int amazed(int ac);
char **delete_comment(char **str);
int nbr_start(char *data, char *str);
int nbr_end(char *data, char *str);


char *my_strcpy_j(char *dest, const char *src, int i);
char *my_strcat_j(char *add, char *str);
char *my_strip(char *str);
void print_arr(char **arr);
int my_arrlen(char **arr);
char **my_split(char *str, char c);
char **my_split_str(char *str, char *c);
char **my_str_to_word_array(char *str, char ref);
int my_nbrlen(int nbr);
int is_in_str(char letter, char *str);
void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr_u(unsigned nb);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
int check(char c);
int transform_into_nbr(char const *str, int start, int length, int neg);
int my_findnbr(char const *str, int i, int neg);
void insert(int *array2, int nbr, int size, int size_max);
int search(char *str, char const *to_find, int n);
int my_char_isalpha(char c);
int my_show_word_array(char const **tab);
int count_space_in_str(char const *str);
int my_grep(char *haystack, char *needle);
int nb_of_pointers(char **str);
int nb_word(char *str, char ref);
int my_printf(const char *format, ...);

#endif
