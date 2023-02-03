
#include "get_next_line.h"
#include <unistd.h>

char	*ft_jfree(char *pez_a, char *pez_b) //eseguo la funzione che unisce jar(pez_o) a buffer(pez_a) pulisce jar e ritorna il join
{
	char	*pez_temp;

	peztemp = ft_strjoin(pez_a, pez_b);
	free(pez_a);
	return (pez_temp);
}

char	*ft_next(char *buffernxt)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffernxt[i] && buffernxt[i] != '\n') //trovare la lunghezza della prima line
		i++;
	if (!buffernxt[i]) // se la fine della line e' \0 la svuotiamo e ritorniamo NULL
	{
		free(buffernxt);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffernxt) - i + 1), sizeof(char)); //perche'impostare la lunghezza di linfd - lunghezza della prima linea + 1?
	i++;
	j = 0;
	while (buffernxt[i]) //copio il buffernxt nella linea e poi libero il buffer
	{
		line[j] = buffernxt[i];
		j++;
		i++;
	}
	free(buffernxt);
	return (line);
}

char *ft_line(char *bufferlin) //eseguo la funzione che mi dara' la linea effettiva come ritorno
{
	char	*line;
	int		i;

	i = 0;
	if (!bufferlin[i]) //ovviamente se la linea da tornare non esiste ritorniamo NULL
		return (NULL);
	while (bufferlin[i] && bufferlin[i] != '\n') //dobbiamo arrivare alla fine della linea per capire quanta memoria allocare
		i++;
	line = ft_calloc(i + 2, sizeof(char)); //definiamo la dimensione della line (i +2 per includere \n e \0)
	i = 0; //reset di i per utilizzarlo nuovamente come contatore
	while (bufferlin[i] && bufferlin[i] != '\n') //qui'definiamo effettivamente la line copiadoci il buffer dentro
	{
		line[i] = bufferlin[i];
		i++;
	}
	if (bufferlin[i] && bufferlin[i] == '\n') // se la fine della line nel buffer e' \n o \0 sostituiamo la fine della line effettiva con \n
		line[i++] = '\n';
	return (line);
}

char	*readfd(int fd, char *jar) //esecuzione della F. che legge il file e ritorna jar (vasetto con dentro pezzi del file)
{
	char	*buffer;
	int		byt_lett;

	if (!jar)
		jar = (char*) malloc(sizeof(char) * (BUFFER_SIZE + 1)); //non equivalente a jar = calloc(1,1);?
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char)); //dovrebbe essere il terzo buffer, quello che mette in jar che poi mette in tank.
	byt_lett = 1;
	while (byt_lett > 0)
	{
		byt_lett = read(fd, buffer , BUFFER_SIZE); //lettura effettiva del pezzetto di file
		if (byt_lett == -1) //gestione di errore in caso non legga byt
		{
			free(buffer);
			return (NULL);
		}
		buffer[byt_lett] = 0; //evitare il leak
		jar = ft_jfree(jar, buffer); //richiamo la funzione che unisce buffer e jar, pulisce e ritorna la loro unione
		if (ft_strchr(buffer, '\n')) //interrompere il ciclo se si trova il caratter accapo (\n)
			break ;
	}
	free(buffer);
	return(jar);
}

char *get_next_line(int fd) //funzione principale
{
	static char	*tank; //e' il buffer statico in cui dovremo mettere i frammenti di file
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0) //la condizione read(fd, 0, 0) < 0 e'solo un rinforzo e non effettivamente necessaria
		return (NULL);
	
	tank = readfd(fd, tank); //qui' eseguo la funzione che leggera' il file e ne mettera' i pezzetti dentro
	if (!tank)
		return (NULL);
	line = ft_line(tank); //eseguo la funzione che prende la linea come return
	tank = ft_next(tank); //eseguo la funzione che va a capo
	return (line);

}
