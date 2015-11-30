LEX= flex
YACC= bison -dy
CC= clang
INSTALL= install -m 0755
RM= rm -f

PREFIX= $(HOME)
DESTINATION= $(PREFIX)/bin
YSRC= $(wildcard *.y)
LSRC= $(wildcard *.l)
YCSRC= y.tab.c
LCSRC= lex.yy.c
YHDR= $(YCSRC:%.c=%.h)
OBJECTS= $(YCSRC:%.c=%.o) $(LCSRC:%.c=%.o) bfcore.o bfmem.o btree.o machine.o
TARGET= $(YSRC:%.y=%)


#-------------------------------------------------------------------------------
.PHONY: clean install mrproper test uninstall


all: $(TARGET)


test: $(TARGET) hello.bf
	./$?


install: $(TARGET)
	$(INSTALL) $< $(DESTINATION)


uninstall:
	$(RM) $(DESTINATION)/$(TARGET)


clean:
	$(RM) $(LCSRC) $(YCSRC) $(YHDR) $(OBJECTS)


mrproper: clean
	$(RM) $(TARGET)


$(TARGET): $(OBJECTS)
	$(CC) -o $@ -ll -ly $?


$(LCSRC): $(LSRC) $(YCSRC)
	$(LEX) -o $@ $<

$(YCSRC): $(YSRC)
	$(YACC) -o $@ $<


%.o: %.c
	$(CC) -c $< -o $@
