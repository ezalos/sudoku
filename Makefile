# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 15:04:16 by ldevelle          #+#    #+#              #
#    Updated: 2019/02/04 05:27:30 by ldevelle         ###   ########.fr        #
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

SRCS		= main ghost print setup solve read

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

LIB_DIR	= ./../libft
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
		#@$(MAKE) -- C $(LIB_PATH)
		@$(call run_and_test, $(CC) $(CFLAGS) -I./$(HEAD_DIR) $(A_OBJ) $(LIB) -o $(NAME))

$(DIR_OBJ)%.o:$(SRC_PATH)/%.c
		@$(call run_and_test, $(CC) $(CFLAGS) -o $@ -c $<)

clean :
		#@$(MAKE) clean -- C $(LIB_PATH)
		@echo "\$(YELLOW)fill_objs \$(END)\\thas been \$(GREEN)\\t\\t\\t  $@\$(END)"
		@rm -f $(A_OBJ)

fclean : clean
		#@$(MAKE) fclean -- C $(LIB_PATH)
		@echo "\$(YELLOW)$(NAME) \$(END)\\t\\thas been \$(GREEN)\\t\\t\\t  $@\$(END)"
		@rm -rf $(NAME)

re :	fclean all

git :
		@git add -A
		@git status
		@git commit -am "Makefile automated push"
		@git push

t0 :	all
		./$(NAME) "9...7...." "2...9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68." ".9..5.741" "47......."
t1 : 	all
		./$(NAME) 1....7.9. .3..2...8 ..96..5.. ..53..9.. .1..8...2 6....4... 3......1. .4......7 ..7...3..
t2 :	all
		./$(NAME) ......... .....3.85 ..1.2.... ...5.7... ..4...1.. .9....... 5......73 ..2.1.... ....4...9

##########################
##						##
##		 .PHONY			##
##						##
##########################

.PHONY : clean fclean re all d git check show_ grep_ hide_ malloc_check onption offption push order testa testv teste testp
