CC=gcc
CFLAGS=-W -Wall -O2 -fstack-protector-all
DFLAGS= lib/BSD/strsec.c -D_FORTIFY_SOURCE=2
DIR=src/
DIROUT=bin/
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	LDFLAGS=-Wl -lpthread
else
	LDFLAGS=-Wl,-z,relro,-z,now -lpthread
endif

Raptor: $(DIR)Raptor.c 
	@echo "           boing         boing         boing           "   
	@echo " e-e           . - .         . - .         . - .        "  
	@echo "(\_/)\       '       \`.   ,'       \`.   ,'       .      "  
	@echo " \`-'\ \`--.___,         . .           . .          .     "  
	@echo "    '\( ,_.-'                                           "  
	@echo "       \\               \"             \"          Compile !"    
	@echo "       ^\' "
	$(CC) $(CFLAGS) $(DFLAGS) -c $(DIR)*.c
	$(CC) -o $(DIROUT)Raptor *.o $(LDFLAGS)
	$(shell make clean)
	@echo "  "
	@echo " Execute \"bin/Raptor\" to start...  "   
clean:
	rm -f *.o Raptor
	



