# commande pour compiler
CC=gcc
CP=cp
RM=rm -fr
CFLAGS=-Wall

#nom des dossiers
SRC=src
OBJ=obj
DATA=data
SAVE=save

#arguments pour trouver les éléments dans les dossiers
SRCS=$(wildcard $(SRC)/*.c)
HEADS=$(wildcard $(SRC)/*.h)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

RESTORESRC=$(wildcard $(SAVE)/*.c)
RESTOREHEAD=$(wildcard $(SAVE)/*.h)

#dossier pour l executable
BIN=bin
EXE=main
PROG=$(BIN)/$(EXE)

#variable pour l archivage
nameArchive=barre_romain

#programme du make
all:$(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -lm

$(OBJ)/%.o: $(SRC)/%.c $(HEADS)
	$(CC) $(CFLAGS) -c $< -o $@ -lm

.PHONY: clean save restore give

# cree la structure de base d un projet
stpprj:
	@mkdir $(SRC) $(OBJ) $(BIN)

# effectue une sauvegarde des differents repertoires et de leurs contenues
save:
ifeq ($(wildcard $(SAVE)/.),)
	@mkdir $(SAVE)
	@$(CP) $(SRCS) $(HEADS) $(SAVE)
	@echo Fichiers sauvegarde.
else
	@echo Fichier deja existant
endif

# restore un sauvegarde
restore:
	@$(CP) $(RESTORESRC) $(RESTOREHEAD) $(SRC)
	@echo Sauvegarde restaure.

# cree une archive avec les fichiers necessaire a la generation d un projet
give:
	@mkdir $(nameArchive) $(nameArchive)/$(SRC) $(nameArchive)/$(SAVE) $(nameArchive)/$(BIN) $(nameArchive)/$(OBJ) $(nameArchive)/$(DATA) || echo Fichier deja existant.
	@$(CP) $(RESTORESRC) $(RESTOREHEAD) $(nameArchive)/$(SRC) || echo Rien a copier ou repertoire src/ inexistant.
	@$(CP) Makefile $(nameArchive)/ || echo Makefile inexistant.
	tar -cvf $(nameArchive).tar $(nameArchive)
	$(RM) $(nameArchive)

# supprime les fichiers generes
clean:
	@$(RM) $(BIN)/* $(OBJ)/* ./*.bak ./*.old ./*.\*\~ ./\#*\# || echo Rien a supprimer dans $(BIN)/ et dans $(OBJ)/