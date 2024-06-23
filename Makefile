.PHONY: all clean rebuild debug help

all:
	./build.sh

clean:
	./build.sh --clean

rebuild:
	./build.sh --rebuild

debug:
	./build.sh --debug

help:
	./build.sh --help

%:
	./build.sh $@