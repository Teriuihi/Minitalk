all:
	$(MAKE) -C Server
	$(MAKE) -C Client

bonus:
	$(MAKE) -C Server bonus
	$(MAKE) -C Client bonus

clean:
	$(MAKE) -C Server clean
	$(MAKE) -C Client clean

fclean:
	$(MAKE) -C Server fclean
	$(MAKE) -C Client fclean

re: fclean

.PHONY: make all clean fclean re
