# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 15:04:16 by ldevelle          #+#    #+#              #
#    Updated: 2019/02/06 18:46:26 by ldevelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sudoku

CC = gcc

CFLAGS = #-Wall -Wextra -Werror

DFLAGS = -Wall -Wextra -Werror -fsanitize=address,undefined -g3 -pedantic\
-O2 -Wchar-subscripts -Wcomment -Wformat=2 -Wimplicit-int\
-Werror-implicit-function-declaration -Wmain -Wparentheses -Wsequence-point\
-Wreturn-type -Wswitch -Wtrigraphs -Wunused -Wuninitialized -Wunknown-pragmas\
-Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast\
-Wwrite-strings -Wconversion -Wsign-compare -Waggregate-return\
-Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations\
-Wmissing-noreturn -Wformat -Wmissing-format-attribute\
-Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs\
-Winline -Wlong-long -Wunreachable-code

#CFLAGS = $(DFLAGS)

##############################################################################
##############################################################################
##																			##
##									----									##
##									IFEQ									##
##									----									##
##																			##
##############################################################################
##############################################################################

SRCS		= main print setup logic_tools solve simple_star smart_tools stars_tools delete

SRC_PATH	= ./srcs

DIR_OBJ 	= ./objs/

##########################
##						##
##	   ARCHITECTURE		##
##						##
##########################

A_SRC 		= $(patsubst %,$(SRC_PATH)/%.c,$(SRCS))
A_OBJ		= $(patsubst %,$(DIR_OBJ)%.o,$(SRCS))

OBJ 		= $(patsubst %,%.o,$(SRCS))

LIB_DIR		= ./../libft
HEAD		= sudo.h
HEAD_DIR	= ./includes
HEAD_PATH	= $(HEAD_DIR)/$(HEAD)

LIB			= $(LIB_DIR)/libft.a

##########################
##						##
##		  DEBUG			##
##						##
##########################

VALGRIND = valgrind --track-origins=yes --leak-check=full --show-leak-kinds=definite

##########################
##						##
##		 COLORS			##
##						##
##########################

RED     = \x1b[31m
GREEN   = \x1b[32m
YELLOW  = \x1b[33m
BLUE	= \x1b[34m
MAGENTA	= \x1b[35m
CYAN	= \x1b[36m
END     = \x1b[0m

COM_COLOR   = $(BLUE)
OBJ_COLOR   = $(CYAN)
OK_COLOR    = $(GREEN)
ERROR_COLOR = $(RED)
WARN_COLOR  = $(YELLOW)
NO_COLOR    = $(END)

OK_STRING    = [OK]
ERROR_STRING = [ERROR]
WARN_STRING  = [WARNING]
COM_STRING   = Compiling

MSG ?= Makefile automated push

define run_and_test
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
	$(1) 2> $@.log; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
	elif [ -s $@.log ]; then \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
	else  \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

##############################################################################
##############################################################################
##																			##
##									-----									##
##									RULES									##
##									-----									##
##																			##
##############################################################################
##############################################################################

##########################
##						##
##		  BASIC			##
##						##
##########################

all :	$(NAME)

$(NAME): $(A_OBJ) $(HEAD_PATH)
		@$(MAKE) -C $(LIB_DIR)
		@$(call run_and_test, $(CC) $(CFLAGS) -I./$(HEAD_DIR) $(A_OBJ) $(LIB) -o $(NAME))

$(DIR_OBJ)%.o:$(SRC_PATH)/%.c
		@$(call run_and_test, $(CC) $(CFLAGS) -o $@ -c $<)

clean :
		@echo "\$(YELLOW)fill_objs \$(END)\\thas been \$(GREEN)\\t\\t\\t  $@\$(END)"
		@rm -f $(A_OBJ)

fclean : clean
		@echo "\$(YELLOW)$(NAME) \$(END)\\t\\thas been \$(GREEN)\\t\\t\\t  $@\$(END)"
		@rm -rf $(NAME)

aclean : clean
		@$(MAKE) clean -C $(LIB_DIR)

afclean : aclean fclean
		@$(MAKE) fclean -C $(LIB_DIR)

re :	fclean all

are :	afclean all

git :
		@git add -A
		@git status
		git commit -am "$(MSG)"
		@git push

t0 :	all
		./$(NAME) ./tests/t0
t1 : 	all
		./$(NAME) ./tests/t1
t2 :	all
		./$(NAME) ./tests/t2
a1 :	all
		./$(NAME) ./tests/tests/good/s01a
e1 :	all
		./$(NAME) ./tests/tests/good/s06a

good :	all
		./$(NAME) ./tests/t0
		./$(NAME) ./tests/t2
		./$(NAME) ./tests/tests/good/s01a
		./$(NAME) ./tests/tests/good/s01b
		./$(NAME) ./tests/tests/good/s01c
		./$(NAME) ./tests/tests/good/s02a
		./$(NAME) ./tests/tests/good/s02b
		./$(NAME) ./tests/tests/good/s02c
		./$(NAME) ./tests/tests/good/s03a
		./$(NAME) ./tests/tests/good/s03b
		./$(NAME) ./tests/tests/good/s04a
		./$(NAME) ./tests/tests/good/s04c
		./$(NAME) ./tests/tests/good/s06a
		./$(NAME) ./tests/tests/good/s06b
		./$(NAME) ./tests/tests/good/s06c
		./$(NAME) ./tests/tests/good/s07a
		./$(NAME) ./tests/tests/good/s07b
		./$(NAME) ./tests/tests/good/s07c
		./$(NAME) ./tests/tests/good/s08a
		./$(NAME) ./tests/tests/good/s08b
		./$(NAME) ./tests/tests/good/s09a
		./$(NAME) ./tests/tests/good/s09c
		./$(NAME) ./tests/tests/good/s10a
		./$(NAME) ./tests/tests/good/s10b
		./$(NAME) ./tests/tests/good/s10c
		./$(NAME) ./tests/tests/good/s11b
		./$(NAME) ./tests/tests/good/s11c
		./$(NAME) ./tests/tests/good/s13a
		./$(NAME) ./tests/tests/good/s13b
		./$(NAME) ./tests/tests/good/s13c
		./$(NAME) ./tests/tests/good/s14a
		./$(NAME) ./tests/tests/good/s14b
		./$(NAME) ./tests/tests/good/s14c

##########################
##						##
##		 .PHONY			##
##						##
##########################

.PHONY : clean fclean re all git aclean afclean are
