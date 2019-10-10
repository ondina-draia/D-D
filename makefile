#########################################
# Directory where to put the object files
OBJDIR = .

#########################################
# Directory where to locate source files
SRCDIR = .

#########################################
# Compiler
CC=g++

######################
# All the object files      
OBJFILES = $(OBJDIR)/main_Projet_DD_Draia-Nicolau_Ondina.o $(OBJDIR)/Race.o $(OBJDIR)/Personnage.o $(OBJDIR)/Classe.o $(OBJDIR)/IntGraph.o 

###############
# All the flagss
DEBUGFLAGS = -O5 -g -DDEBUG -m64 -L /lib64 `pkg-config gtkmm-3.0 --cflags`	
STFLAGS    = -DLCB -DLENGTHTYPE=Uint -pthread `pkg-config gtkmm-3.0 --libs`

DDFeuillePerso : $(OBJFILES)
	$(CC) $^ $(STFLAGS) -o $(OBJDIR)/$@

# How to make the object files:
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(DEBUGFLAGS) -c $? -o $@

# Cleaning target (only works with fileutils):
clean:
	/bin/rm -f $(OBJFILES) DDFeuillePerso
