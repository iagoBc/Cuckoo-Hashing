

parametrosCompilacao=-Wall 
nomePrograma=myht

all: 
	gcc hash.c main.c -o $(nomePrograma) $(parametrosCompilacao)

clean:
	rm -f $(nomePrograma)
	rm -f *.o *.gch
