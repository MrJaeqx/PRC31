PROJECT_NAME=Meetserie

CFLAGS=-Wall -Werror -ggdb -O0 -Iproduct

SHARED_SOURCES=product/$(PROJECT_NAME).cpp

MAIN_SOURCES=product/menu.cpp \
             $(SHARED_SOURCES) \
             product/MeetserieExtra.cpp

TEST_SOURCES=test/Test$(PROJECT_NAME).cpp \
			 $(SHARED_SOURCES)       

TEST_LIBS=-lgtest -lgtest_main -lpthread

GCC=g++

all: $(PROJECT_NAME)

$(PROJECT_NAME): $(MAIN_SOURCES) Makefile product/*.h
	@$(GCC) $(CFLAGS) $(MAIN_SOURCES) -o $@

Test$(PROJECT_NAME): $(TEST_SOURCES) Makefile product/*.h
	@$(GCC) $(CFLAGS) $(TEST_SOURCES) -o $@ $(TEST_LIBS) -Itest

clean:
	@rm -rf Test$(PROJECT_NAME) $(PROJECT_NAME)

test: Test$(PROJECT_NAME)
	@./Test$(PROJECT_NAME)