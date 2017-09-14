CFLAGS=-Wall -g
CC = cc

#This make rule ensures that all targets
#are compiled with the CFLAGS flags and
#the output is put into the bin/ directory
#(eg. running "make helloworld" creates bin/helloworld)
#(you can then run the file with ./bin/helloworld)
#
#This approach allows .gitignore to prevent any compiled files
#being accidentally added to the repository.
%: %.c
	$(CC) $(CFLAGS) $< -o bin/$@


#This make rule empties out the bin/ directory
#Useful when testing make, building from scratch,
#or pushing to git (though .gitignore should prevent
#any files in bin/ being commited and accidentally pushed)
clean:
	rm -rf bin/*
