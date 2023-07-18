#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define LEAD_PLAIN	0
#define LEAD_OR		1
#define LEAD_AND		2
#define LEAD_CHAIN	3


#define READ_BULK 1024
#define WRITE_BULK 1024
#define GUST_BULK -1


#define UTILIZE_GETLINE 0
#define UTILIZE_STRTOK 0


#define SWITCH_LOWERCASE	1
#define SWITCH_UNSIGNED	2

#define SILENT_FILE	"shell_history"
#define SILENT_MAX	4096

extern char **environ;


/**
 * struct stream - singly linked list
 * @i: a num scope
 * @c: a str scope
 * @close: a posterior node
 */
typedef struct stream
{
	int i;
	char *c;
	struct stream *close;
} list_t;

/**
 *struct excuteinfo - holds false-args to overrun into a function,
 *		permitting regular prototype
 *@environ: adjust file env copy 
 *@history: nodule of the history
 *@alias: nodule of the alias
 *@env_changed: if any change of environ
 *@status: the last return value of excute state
 *@cmd_buf: the heading of the string pointer
 *@cmd_buf_type: command type or and
 *@readfd: the file directory of the read input
 *@histcount: the numeration of history line
  *@arg: the string contain arguements
 *@argv: the array of strings provoked from arguments
 *@path: the string for the stream cmd
 *@argc: the args numeration
 *@line_count: the flase numeration
 *@err_num: the false code 
 *@linecount_flag: the numeration of this line 
 *@fname: the platform name
 *@env: related copy of local lists
 */
typedef struct excuteinfo
{

	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	char *arg;
	char **argv;
	char *path;
	int argc;
	list_t *env;
	list_t *history;
	list_t *alias;

	char **cmd_buf;
	int cmd_buf_type; 
	int readfd;
	int histcount;
	char **environ;
	int env_changed;
	int status;
} info_t;

#define INPUT_INT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct formation - holds the formation of a string and function
 *@kind: the formation cmd 
 *@tsk: the task
 */
typedef struct formation
{
	char *kind;
	int (*tsk)(info_t *);
} builtin_table;

/* file_one.c */
int be_lead(info_t *, char *);
char *call_edge(char *, int, int);
char *detect_route(info_t *, char *, char *);

/* file_two.c */
int compile(info_t *, char **);
int detect_formation(info_t *);
void detect_lead(info_t *);
void spine_command(info_t *);

/* file_three.c */
int noose(char **);

/* file_four.c */
int _extent(char *);
int _combine(char *, char *);
char *begins_with(const char *, const char *);
char *_concat(char *, char *);

/* file_five.c */
void _place(char *);
int _design(char);
int _propose(char a, int b);
int _offer(char *c, int d);

/* file_six.c */
char *_copy(char *, char *, int);
char *concat(char *, char *, int);
char *_charge(char *, char);

/* file_seven.c */
char *copy(char *, char *);
char *_duplicate(const char *);
void _lay(char *);
int _force(char);

/* file_eight.c */
char *_trail(char *, char, unsigned int);
void actual(char **);
void *_correct(void *, unsigned int, unsigned int);

/* file_nine.c */
char **drag(char *, char *);
char **pull(char *, char);

/* file_ten.c */
int real(void **);

/* file_eleven.c */
int _resolve(char *);
void press_false(info_t *, char *);
int press_t(int, int);
char *switch_num(long int, int, int);
void break_cmt(char *);

/* file_twelve.c */
int honest(info_t *);
int be_locate(char, char *);
int _veritable(int);
int _untie(char *);

/* file_thirteen.c */
int _common(info_t *);
int _anonymity(info_t *);

/* file_fourteen.c */
int _outlet(info_t *);
int _compress(info_t *);
int _assist(info_t *);

/* file_fifteen.c */
void remove_data(info_t *);
void suit_data(info_t *, char **);
void rid_data(info_t *, int);

/* file_sixteen.c */
ssize_t take_chip(info_t *);
int _getline(info_t *, char **, size_t *);
void hitPass(int);

/* file_seventeen.c */
char **take_environ(info_t *);
int _unsuitthough(info_t *, char *);
int _suitthough(info_t *, char *, char *);

/* file_eighteen.c */
char *_takethough(info_t *, const char *);
int _though(info_t *);
int suitthough(info_t *);
int unsuitthough(info_t *);
int reside_though_stream(info_t *);

/* file_nineteen.c */
char *take_record_data(info_t *data);
int boost_record(info_t *data);
int stay_record(info_t *data);
int erect_record_stream(info_t *data, char *pol, int linecount);
int rear_record(info_t *data);

/* file_twenty.c */
list_t *put_nodule(list_t **, const char *, int);
list_t *put_nodule_close(list_t **, const char *, int);
size_t press_stream_chain(const list_t *);
int tense_nodule_at_point(list_t **, unsigned int);
void rid_stream(list_t **);

/* file_twentyone.c */
int be_string(info_t *, char *, size_t *);
void review_string(info_t *, char *, size_t *, size_t, size_t);
int exchange_anonymity(info_t *);
int exchange_labile(info_t *);
int exchange_chain(char **, char *);

/* file_twentytwo.c */
size_t stream_extent(const list_t *);
char **stream_at_chains(list_t *);
size_t press_stream(const list_t *);
list_t *nodule_begins_to(list_t *, char *, char);
ssize_t take_nodule_point(list_t *, list_t *);

#endif

