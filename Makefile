.PHONY: ls le pilha all clean


all: ls le pilha

ls:
	$(MAKE) -C 1_lista_sequencial

le:
	$(MAKE) -C 2_lista_encadeada

pilha:	
	$(MAKE) -C 3_pilhas


clean:
	$(MAKE) clean -C 1_lista_sequencial
	$(MAKE) clean -C 2_lista_encadeada
	$(MAKE) clean -C 3_pilhas
