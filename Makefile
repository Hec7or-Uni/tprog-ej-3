PROG:=main
SRCS:=main.cc

CXX:=g++ -Wall

OBJS:=$(SRCS:.cc=.o)
DEPS:=$(SRCS:.cc=.d)

all: $(PROG)

main.o:	StoreLast.h
main.o:	StoreMax.h
main.o:	StoreSum.h
main.o:	StoreAvg.h
main.o:	Logger.h

$(PROG): $(OBJS)
	$(CXX) -o $@ $^

%.o: %.cc
	$(CXX) -MMD -c $<

.PHONY: edit go

go: $(PROG)
	$(PROG)

edit:
	@geany -s -i $(SRCS) *.h &

clean:
	@rm -f $(PROG) *.o *.gch *.d core tags

-include $(DEPS)
