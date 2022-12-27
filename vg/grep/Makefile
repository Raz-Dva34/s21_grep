NAME=s21_grep

CC=clang
FLG=-Wall -Wextra -Werror
SRC=grep/grep_e_flag.c grep/grep_f_flag.c grep/grep_flag_parcer.c\
 	grep/grep_functions.c grep/grep_o_flag.c grep/grep_reader.c\
	grep/output_flag_data.c grep/s21_grep.c

OBJ=$(SRC:.c=.o)

all: $(SRC) $(NAME)
	@echo "\033[32;1m───[.o]-files => o_files-dir\033[0m"
	@if ! ls | grep o_files ; then \
		mkdir o_files ; \
	fi
	@mv grep/*.o o_files
	@printf "\033[32;4mHello, $(USER)!\nIt's a grep by killedhi!\nEnjoy :)\033[0m\n"

$(NAME): $(OBJ)
	@echo "\033[32;1m└──Get object files\033[0m"
	@echo "\033[32;1m┌──Compile\033[0m"
	$(CC) $(FLG) $(OBJ) -o $@

run: testfiles
	./s21_grep -o the testfiles/test.txt testfiles/test2.txt

rerun: re run

.cpp.o:
	$(CC) $(FLG) $< -o $@

clean:
	@echo "\033[32;1m───Object files have been removed\033[0m"
	@rm -rf o_files
	@echo "\033[32;1m───Testfiles files have been removed\033[0m"
	@rm -rf testfiles

fclean: clean
	@if ls | grep s21_grep ; then \
		rm ${NAME} ; \
		printf "\e[1A\e[0C\b" ; \
	fi
	@echo "\033[32;1m───The project has been cleared\033[0m"

re: fclean all
#________________FOR_TESTS______________________________

testfiles:
	@mkdir testfiles
	@printf "Bchool the years are the most amazing years in life of every person\nStrict and lenient teachers\n\n\tthe Every time a teacher goes into the classroom\n\nwill\n\nSoon, summer holidays will beginFIIIIIN" > testfiles/test.txt
	@printf "\n\tQqweryuiom dasdfghjkl the\n\n\nwill\n\n\nPOIUYTREWQ\n" > testfiles/test2.txt
	@printf "Привет путник! Это ты удачно зашёл, но не туда...\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n+1 к любознательности\n" > testfiles/readme.txt

.PHONY:     all clean fclean re