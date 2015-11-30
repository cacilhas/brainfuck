#ifndef _BRAINFUCK_H
#define _BRAINFUCK_H

#ifdef __cplusplus
extern "C" {
#endif


void yyerror(const char *);
int yylex(void);

void bf_add_operator(const char);
void bf_perform(void);


#ifdef __cplusplus
}  // extern "C"
#endif


#endif  // _BRAINFUCK_H
